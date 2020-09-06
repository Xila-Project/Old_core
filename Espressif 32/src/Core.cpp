#include "Arduino.h"

#include "Core.hpp"

GalaxOS_Class GalaxOS;

/*char WiFi_SSID[] = "Avrupa";
char WiFi_Password[] = "0749230994";*/

GalaxOS_Class::GalaxOS_Class() : Keyboard(2, 6) //builder
{
  //strcpy(WiFi_SSID, "Avrupa");
  //strcpy(WiFi_Password, "0749230994");

  for (int i = 0; i < 4; i++)
  {
    Software_Pointer[i] = NULL;
  }

  Low_RAM_Threshold = 2000;

  C_MIDI = 60;

  C_Frequency = 262;

  memset(Current_Username, 0, sizeof(Current_Username));

  Tag = 0x00;

  memset(Software_Pointer, NULL, 6);
}

GalaxOS_Class::~GalaxOS_Class() //detroyer
{
}

// Used to initialise the core

void GalaxOS_Class::Start()
{
  Serial.begin(921600); //PC Debug UART
  Horizontal_Separator();
  Print_Line();
  Serial.println(F("||      _____       ___   _           ___  __    __       _____   _____       ||"));
  Serial.println(F("||     |  ___|     /   | | |         /   | | |  | |      |  _  | |  ___|      ||"));
  Serial.println(F("||     | |        / /| | | |        / /| |  | || |       | | | | | |___       ||"));
  Serial.println(F("||     | |  _    / /_| | | |       / /_| |   |  |        | | | | |___  |      ||"));
  Serial.println(F("||     | |_| |  / ___  | | |___   / ___  |  | || |       | |_| |  ___| |      ||"));
  Serial.println(F("||     |_____| /_/   |_| |_____| /_/   |_| |_|  |_|      |_____| |_____|      ||"));
  Print_Line();
  Print_Line();
  Horizontal_Separator();
  Print_Line(F("Flash : 1,310,720 Bytes - EEPROM : 512 Bytes - RAM : " + String(ESP.getFreeHeap()) + "/327680 Bytes"));
  Print_Line(F("Galax OS Embedded Edition - Alix ANNERAUD - Alpha"));
  Horizontal_Separator();
  Print_Line(F("Starting Galax OS ..."), 0);
  // Initialize SD Card
  Print_Line("Mount The SD Card ...", 0);

#if SD_MODE == 0
  pinMode(14, INPUT_PULLUP);
  //pinMode(15, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  //delete &SD_MMC;
#else
  //delete &SD;
#endif

  if (!Drive.begin() || Drive.cardType() == CARD_NONE)
  {

    Serial.println(F("|| > Warning : The SD Card isn't mounted.                                     ||"));
  }
  else
  {
    Serial.println(F("|| > The SD Card is mounted.                                                  ||"));

    File Temporary_File;

    // Initialize Virtual Memory
    Virtual_Memory_Semaphore = xSemaphoreCreateMutex();

    if (Virtual_Memory_Semaphore == NULL)
    {
      //error handle
    }
    else
    {
      xSemaphoreGive(Virtual_Memory_Semaphore);
    }

    //Testing Virtual Memory
    uint32_t Test_Float = 123456789;
    Set_Variable('T', Test_Float);
    Serial.println(Test_Float);
    Get_Variable('T', Test_Float);
    Serial.println(Test_Float);

    // Load Task
    Verbose_Print("Loading Task ...");

    //xTaskCreatePinnedToCore() //core class : used to execute api call in "root" mode

    // Check if the system state was saved
    Print_Line("Check existing of file last state ...");
    if (Drive.exists("/GALAXOS/GOSCUSA.GSF"))
    {
      Restore_System_State();
    }

    // Load display configuration
    Display.Set_Backlight(100, false);

    Verbose_Println("Initialize display ...");

    // Load network configuration
    Print_Line("Load Network Configuration ...");
    Temporary_File = Drive.open("/GALAXOS/REGISTRY/NETWORK.GRF");
    if (!Temporary_File)
    {
      //error handle
    }
    DynamicJsonDocument Network_Registry(256);
    deserializeJson(Network_Registry, Temporary_File);
    WiFi.setHostname(Network_Registry["Host Name"]);                   // Set hostname
    const uint8_t Number_WiFi_AP = Network_Registry["Number WiFi AP"]; // Check number of registred AP
    char SSID[32], Password[32];
    for (uint8_t i = 1; i < Number_WiFi_AP; i++)
    {
      strcpy(SSID, Network_Registry["SSID" + String(i)]);
      strcpy(Password, Network_Registry["Password" + String(i)]);
      WiFi.setAutoConnect(false);
      WiFi.begin(SSID, Password);
      while (WiFi.status() != WL_CONNECTED && i < 50)
      {
        vTaskDelay(pdMS_TO_TICKS(100));
        i++;
      }
      if (WiFi.status() == WL_CONNECTED)
      {
        break;
      }
    }
    delete Network_Registry;
    Temporary_File.close();

    // Set Regional Parameters

    Temporary_File = Drive.open(F("/GALAXOS/REGISTRY/REGIONAL.GRF"));
    if (!Temporary_File)
    {
      //error
    }
    Synchronise_Time();
    Temporary_File.close();

    // Load software (including Shell UI)
    Temporary_File = Drive.open("/GALAXOS/REGISTRY/SOFTWARE.GRF");
    if (!Temporary_File)
    {
      return;
    }
    DynamicJsonDocument Software_Registry(256);
    deserializeJson(Software_Registry, Temporary_File);

    delete Software_Registry;
    Open_Software("Shell");
  }

  void GalaxOS_Class::Save_System_State()
  {
    if (Drive.exists("/GALAXOS/GOSCUSA.GSF"))
    {
      if (Drive.remove("/GALAXOS/GOSCUSA.GSF"))
      {
        //event handler
      }
    }
    DynamicJsonDocument System_Save_Registry(256);

    System_Save_Registry["Current Username"] = Current_Username;

    File Temporary_File = Drive.open("/GALAXOS/GOSCUSA.GSF");
    serializeJson(System_Save_Registry, Temporary_File);
    Temporary_File.close();
  }

  // Callback function for screen

  void GalaxOS_Class::Incomming_String_Data_From_Display(String & Received_Data)
  {
    uint8_t Temporary_Return_Code = Received_Data.charAt(0);
    Received_Data.remove(0, 1);
    switch (Temporary_Return_Code)
    {
    case CODE_COMMAND:
    case CODE_COMMAND_NEW:
      if (Received_Data == "Close")
      {
        Close_Software();
      }
      else if (Received_Data == "Minimize")
      {
        Software_Pointer[0]->Minimize();
      }
      else
      {
        Software_Pointer[0]->Execute(Received_Data.charAt(0), Received_Data.charAt(1));
      }
      break;
    case CODE_VARIABLE_CHAR:
      Set_Variable(Received_Data.charAt(0), uint8_t(Received_Data.charAt(1)));
      Tag = '\0';
      break;
    case CODE_VARIABLE_STRING:
      Tag = (char)Received_Data.charAt(0);
      Received_Data.remove(0, 1);
      Set_Variable(Tag, Received_Data);
      Tag = '\0';
      break;
    case CODE_VARIABLE_LONG:
      Tag = Received_Data.charAt(0);
      break;
    case CODE_VARIABLE_UNSIGNED_LONG:
      Tag = Received_Data.charAt(0);
      break;
    default:
      //error handle
      break;
    }
  }

  void GalaxOS_Class::Incomming_Numeric_Data_From_Display(uint32_t const &Received_Data)
  {
    if (Tag != 0x00)
    {
      Set_Variable(Tag, Received_Data);
    }
    else
    {
      Serial.println(F("Error : Cannot Set Variable Because Tag is NULL."));
      //error handle
    }
  }

  // File openning handling

  void GalaxOS_Class::Open_File(File & File_To_Open)
  {
    if (!File_To_Open)
    {
      //error handle
      File_To_Open.close();
      return;
    }
    else if (File_To_Open.isDirectory())
    {
      //error : directory not a file
      File_To_Open.close();
      return;
    }

    char File_Name[14];
    strcpy(File_Name, File_To_Open.name());
    uint8_t i = 1;
    for (; i < 14; i++) //extract extension
    {
      if (File_Name[i] == '.')
      {
        break;
      }
    }
    char Extension[] = {File_Name[i + 1], File_Name[i + 2], File_Name[i + 3]};
    //pre-defined
    if (strcmp(Extension, "GEF"))
    {
      if (File_To_Open.size() == 0)
      {
        //error : empty file
        File_To_Open.close();
        return;
      }
      if (Update.begin(File_To_Open.size()))
      {
        if (Update.writeStream(File_To_Open) != File_To_Open.size())
        {
          //error : update perform partialy
          File_To_Open.close();
          return;
        }
        if (Update.end() && Update.isFinished())
        {
          //info : update completed
        }
        else
        {
          //error : update went wrong
        }
      }
      else
      {
        //error : not enought space to perform OTA
      }
    }
    else if (strcmp(Extension, "BMP"))
    {
    }

    else if (strcmp(Extension, "GPF"))
    {
    }
    else if (strcmp(Extension, "FPF"))
    {
    }
    else
    {
      if (Registry_Read(Drive.open(F("/GALAXOS/SOFTWARE/EXTEMANA.O"))))
      {
      }
      //error handle : unknow extension
    }
    File_To_Open.close();
  }

  // Software management

  void GalaxOS_Class::Open_Software(const char *Software_Name)
  {
    for (uint8_t i = 0; i < 6; i++)
    {
      if (Software_Pointer[i] == NULL)
      {
        Software_Pointer[i] = Get_Software_Handle_Pointer(Software_Name)->Load_Function_Pointer();
        Software_Pointer[i]->Handle_Pointer = Get_Software_Handle_Pointer(Software_Name);
        Software_Pointer[i]->Maximize();
      }
    }

    Get_Software_Handle_Pointer(Software_Name)->Load_Function_Pointer();
  }

  void GalaxOS_Class::Close_Software(const char *Software_Name = NULL)
  {
    if (Software_Name == NULL) //by default delete current running software
    {
      Software_Pointer[0]->Minimize();
      vTaskDelete(Software_Pointer[0]->Task_Handle);
      delete Software_Pointer[0];
      Software_Pointer[0] = NULL;
    }
    else
    {
      Get_Software_Pointer(Software_Name)->Minimize();
      vTaskDelete(Get_Software_Pointer(Software_Name)->Task_Handle);
      delete Get_Software_Pointer(Software_Name);

      Set_Software_Pointer(Software_Name, NULL);
    }
  }

  Software_Class *GalaxOS_Class::Get_Software_Pointer(const char *Software_Name)
  {
    for (byte i = 0; 1 < 6; i++)
    {
      if (i > 6)
      {
        return NULL; //nothing find
      }
      if (Software_Pointer[i]->Handle_Pointer == NULL)
      {
        continue;
      }
      else if (strcmp(Software_Pointer[i]->Handle_Pointer->Name, Software_Name))
      {
        return Software_Pointer[i];
      }
    }
  }

  Software_Handle_Class *GalaxOS_Class::Get_Software_Handle_Pointer(const char *Software_Name)
  {
    for (byte i = 0; i <= MAXIMUM_SOFTWARE; i++)
    {
      if (i >= MAXIMUM_SOFTWARE)
      {
        return NULL;
      }
      if (Software_Handle[i] == NULL)
      {
        continue;
      }
      if (strcmp(Software_Handle[i]->Name, Software_Name))
      {
        return Software_Handle[i];
      }
    }
  }

  void GalaxOS_Class::Set_Load_Function(const char *Software_Name, void (*Load_Function_To_Set)())
  {
    Get_Software_Handle_Pointer(Software_Name)->Load_Function_Pointer = Load_Function_To_Set;
  }

  // Serial communication with commputerà

  void GalaxOS_Class::Horizontal_Separator()
  {
    Serial.println(F("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"));
  }

  void GalaxOS_Class::Print_Line(const char *Text_To_Print = NULL, uint8_t Alignement = 1)
  {
    Serial.print(F("||"));

    if (Text_To_Print == NULL) //print blank line
    {
      for (uint8_t i = 0; i < 64; i++)
      {
        Serial.print(F(" "));
      }
      Serial.println("||");
    }
    else if (sizeof(Text_To_Print) > 64)
    {
      return;
    }
    uint8_t Remaining_Spaces = sizeof(Text_To_Print);
    switch (Alignement)
    {
    case 0: //left
      Serial.print(F(" "));
      Serial.print(Text_To_Print);
      Remaining_Spaces = 64 - Remaining_Spaces;
      break;
    case 1: //centered

    default:
      break;
    }
    for (uint8_t i = 0; i < Remaining_Spaces; i++)
    {
      Serial.println(F(" "));
    }
    Serial.println("||");
  }

  // --------------------------

  void GalaxOS_Class::Restore_System_State()
  {
    Display.Set_Current_Page(PAGE_DESK);

    if (!Drive.exists("/GALAXOS/GOSCUSA.GSF"))
    {
      return;
    }
    File Temporary_File = Drive.open("/GALAXOS/GOSCUSA.GSF");
    DynamicJsonDocument Temporary_Json_Document(256);
    //ReadBufferingStream Buffering_Stream(Drive.open("/"), 64); dont work, i don't know why

    if (deserializeJson(Temporary_Json_Document, Temporary_File) == true)
    {
      return;
    }

    Current_Username = Temporary_Json_Document["Current Username"];

    Temporary_File.close();
    ESP.restart();
  }

  //---------------------------------------------------------------------------//
  //                                Virtual Memory Management                  //
  //---------------------------------------------------------------------------//

  // Char array
  void GalaxOS_Class::Set_Variable(char const &Tag, const char *String_To_Set)
  {
    xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
    Virtual_Memory_File = Drive.open("/GALAXOS/MEMORY/CHAR/" + Tag, FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.write((uint8_t *)String_To_Set, sizeof(String_To_Set)) != sizeof(String_To_Set);
    }
    Virtual_Memory_File.close();
    xSemaphoreGive(Virtual_Memory_Semaphore);
  }

  void GalaxOS_Class::Get_Variable(char const &Tag, char *String_To_Set)
  {
    xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
    Virtual_Memory_File = Drive.open("/GALAXOS/MEMORY/CHAR/" + Tag, FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.readBytes(String_To_Set, sizeof(String_To_Set));
    }
    Virtual_Memory_File.close();
    xSemaphoreGive(Virtual_Memory_Semaphore);
  }

  // String
  void GalaxOS_Class::Set_Variable(char const& Tag, String const &String_To_Set)
  {
    xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
    Virtual_Memory_File = Drive.open("/GALAXOS/MEMORY/STRING/" + Tag, FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.print(String_To_Set);
    }
    Virtual_Memory_File.close();
    xSemaphoreGive(Virtual_Memory_Semaphore);
  }

  void GalaxOS_Class::Get_Variable(char const& Tag, String &String_To_Get)
  {
    xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
    Virtual_Memory_File = Drive.open("/GALAXOS/MEMORY/STRING/" + Tag, FILE_READ);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      String_To_Get = Virtual_Memory_File.readString();
    }
    Virtual_Memory_File.close();
    xSemaphoreGive(Virtual_Memory_Semaphore);
  }

  // 64-bit var
  void GalaxOS_Class::Set_Variable(uint8_t const &Tag, uint64_t const &Number_To_Set)
  {
    xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
    Virtual_Memory_File = Drive.open(GLOBAL_VIRTUAL_MEMORY_FILE, FILE_WRITE);
    Virtual_Memory_File.seek(Tag << 1);
    Split_Number = {(uint8_t)Number_To_Set, (uint8_t)Number_To_Set >> 8, (uint8_t)Number_To_Set >> 16, (uint8_t)Number_To_Set >> 24, (uint8_t)Number_To_Set >> 32, (uint8_t)Number_To_Set >> 48, (uint8_t)Number_To_Set >> 56, (uint8_t)Number_To_Set >> 64};
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.write(Split_Number, 8);
    }
    Virtual_Memory_File.close();
    xSemaphoreGive(Virtual_Memory_Semaphore);
  }

  void GalaxOS_Class::Get_Variable(char const &Tag, uint64_t &Number_To_Get)
  {
    xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
    Virtual_Memory_File = Drive.open(GLOBAL_VIRTUAL_MEMORY_FILE + Tag, FILE_READ);
    Virtual_Memory_File.seek(Tag << 1);
    if (Virtual_Memory_File)
    {
      Number_To_Set = Virtual_Memory_File.readBytes(Split_Number, 8);
    }
    Number_To_Get = (uint64_t)Number_To_Get << 64 | (uint64_t)Number_To_Get << 56 | (uint64_t)Number_To_Get << 48 | (uint64_t)Number_To_Get << 32 | (uint64_t)Number_To_Get << 24 | (uint64_t)Number_To_Get << 16 | (uint64_t)Number_To_Get << 8 | (uint64_t)Number_To_Get;
    Virtual_Memory_File.close();
    xSemaphoreGive(Virtual_Memory_Semaphore);
  }

  // 32-bit variable
  void GalaxOS_Class::Set_Variable(uint8_t const &Tag, uint32_t const &Number_To_Set)
  {
    xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
    Virtual_Memory_File = Drive.open(GLOBAL_VIRTUAL_MEMORY_FILE, FILE_WRITE);
    Virtual_Memory_File.seek(Tag << 1);
    Split_Number = {(uint8_t)Number_To_Set, (uint8_t)Number_To_Set >> 8, (uint8_t)Number_To_Set >> 16, (uint8_t)Number_To_Set >> 24};
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.write(Split_Number, 4);
    }
    Virtual_Memory_File.close();
    xSemaphoreGive(Virtual_Memory_Semaphore);
  }

  void GalaxOS_Class::Get_Variable(char const &Tag, uint32_t const &Number_To_Get)
  {
    xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
    Virtual_Memory_File = Drive.open(GLOBAL_VIRTUAL_MEMORY_FILE + Tag, FILE_READ);
    Virtual_Memory_File.seek(Tag << 1);
    if (Virtual_Memory_File)
    {
      Number_To_Set = Virtual_Memory_File.parseFloat();
    }
    Virtual_Memory_File.close();
    xSemaphoreGive(Virtual_Memory_Semaphore);
  }

  // 16 bit variable
  void GalaxOS_Class::Set_Variable(char const &Tag, uint16_t const& Number_To_Set)
  {
    xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
    Virtual_Memory_File = Drive.open(GLOBAL_VIRTUAL_MEMORY_FILE + Tag, FILE_WRITE);
    if (Virtual_Memory_File)
    {
      uint8_t Split_Integer[] = {uint8_t(Number_To_Set << 8), uint8_t(Number_To_Set)};
      Virtual_Memory_File.write(Split_Integer, 2);
    }
    Virtual_Memory_File.close();
    xSemaphoreGive(Virtual_Memory_Semaphore);
  }

  void GalaxOS_Class::Get_Variable(char const &Tag, uint16_t& Number_To_Set)
  {
    xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
    Virtual_Memory_File = Drive.open(GLOBAL_VIRTUAL_MEMORY_FILE + Tag, FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Number_To_Set = Virtual_Memory_File.parseInt();
    }
    Virtual_Memory_File.close();
    xSemaphoreGive(Virtual_Memory_Semaphore);
  }

  // 8 bit variable
  void GalaxOS_Class::Set_Variable(char const &Tag, uint8_t const& Number_To_Set)
  {
    xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
    Virtual_Memory_File = Drive.open(GLOBAL_VIRTUAL_MEMORY_FILE + Tag, FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.write(Number_To_Set);
    }
    Virtual_Memory_File.close();
    xSemaphoreGive(Virtual_Memory_Semaphore);
  }

  void GalaxOS_Class::Get_Variable(char const &Tag, uint8_t &Number_To_Set)
  {
    xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
    Virtual_Memory_File = Drive.open(GLOBAL_VIRTUAL_MEMORY_FILE + Tag, FILE_READ);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Number_To_Set = Virtual_Memory_File.read();
    }
    Virtual_Memory_File.close();
    xSemaphoreGive(Virtual_Memory_Semaphore);
  }

  void Ressource_Monitor(void *pvParameters)
  {
    (void)pvParameters;
    for (;;)
    {
      if (ESP.getFreeHeap() < 2000)
      {
        Serial.println("Low Memory !");
      }
      vTaskDelay(1000);
    }
  }

// Security 
  uint16_t GalaxOS_Class::Check_Credentials(const char *Username_To_Check, const char *Password_To_Check)
  {
    File Temporary_File = Drive.open("/USERS/" + String(Username_To_Check) + "/STTNGS/PASSWORD.GSF", FILE_READ);
    char Temporary_Password[Temporary_File.size()];
    if (Temporary_File)
    {
      Temporary_File.readString().toCharArray(Temporary_Password, Temporary_File.size());
    }
    else
    {
      Serial.println(F("Wrong Username !"));
      return WARNING_WRONG_USERNAME;
    }
    Temporary_File.close();
    if (strcmp(Temporary_Password, Password_To_Check))
    {
      Serial.println(F("Good Password"));
      strcpy(Current_Username, Username_To_Check);

      return INFORMATION_GOOD_CREDENTIALS;
    }
    else
    {
      Serial.println(F("Wrong Password !"));
      return WARNING_WRONG_PASSWORD;
    }
  }

  void GalaxOS_Class::Load_System_Files()
  {
    Serial.println(F("Load System Files ..."));
    File Temporary_File = Drive.open("/GALAXOS.GSF");
    String Temporary_String = "";
    if (Temporary_File)
    {
      while (Temporary_File.available() && Temporary_File.peek() != 10 && Temporary_File.peek() != 13)
      {
        Temporary_String += String(Temporary_File.read());
      }
      if (Temporary_String != "Galax OS Embeded Edition For Arduino Mega 2560 Version Alpha 0.12")
      {
        //error handle
        Serial.println(F("Error : ERROR_SOME_SYSTEM_FILES_ARE_CORRUPTED"));
        return;
      }
    }
    else
    {
      Serial.println(F("Error : ERROR_SOME_SYSTEM_FILES_ARE_MISSING"));
      return;
    }
    Temporary_String = "";

    //Load software from registry
    String Software_Name;
    for (uint8_t i = 0; i < MAXIMUM_SOFTWARE; i++)
    {

      Registry_Read(Drive.open("/GALAXOS/REGISTRY/SOFTWARE/LIST.GCF"), (const char)i, Software_Name)
    }

    Display.Set_Text(F("LOAD_TIM"), F("Loading System Files ..."));
    Display.Set_Time(F("LOAD_TIM"), 50);
  }

  void GalaxOS_Class::Load_User_Files()
  {
    Serial.print(F("Load User Files ..."));
    String Temporary_Username;
    String Temporary_Password;
    Get_Variable('U', Temporary_Username);
    Get_Variable('P', Temporary_Password);
    if (Check_Credentials(Temporary_Username, Temporary_Password) == INFORMATION_GOOD_CREDENTIALS)
    {
      Display.Set_Current_Page(F("Load_User"));
    }
    else
    {
      //error : wrong username or password
    }
  }

  uint8_t GalaxOS_Class::Event_Handler(uint16_t const &Type, String const &Extra_Informations = "")
  {
#define EVENT_CANCEL 0
#define EVENT_YES 1
    Display.Set_Current_Page(F("Event"));
    uint8_t Event_Type;
    Registry_Read(Drive.open(), String(Type), Event_Type);
    byte i = 0;
    while (Event_Reply == 0 && i < 100)
    {
      vTaskDelay(pdMS_TO_TICKS(50));
      i++;
    }
    if (i > 100)
    {
      Display.Set_Current_Page(Last_Page);
      return 0;
    }
    return Event_Reply;
  }

  /*
  switch (Type)
  {
    Nextion_Serial_Transmit(F("Event"), COMMAND_PAGE_NAME, "", 0);
  case ERROR_FAILLED_TO_INTIALIZE_SD_CARD:
    Nextion_Serial.print(F("TITLE_TXT.txt="));
    Nextion_Serial.print(F("A"));
    Nextion_Serial_Transmit(F("TITLE_TXT"), ATTRIBUTE_TXT, F("Error !"), 0);
    Nextion_Serial_Transmit(F("MESSAGE_TXT"), ATTRIBUTE_TXT, F("Failled to initialize the SD Card !"), 0);
    break;
  case ERROR_SOME_SYSTEM_FILES_ARE_MISSING:
    Nextion_Serial_Transmit(F("TITLE_TXT"), ATTRIBUTE_TXT, F("Error !"), 0);
    Nextion_Serial_Transmit(F("MESSAGE_TXT"), ATTRIBUTE_TXT, F("Some system files are missing !"), 0);
    break;
  case ERROR_SOME_USER_SETTINGS_FILES_ARE_MISSING:
    Nextion_Serial_Transmit(F("TITLE_TXT"), ATTRIBUTE_TXT, F("Error !"), 0);
    Nextion_Serial_Transmit(F("MESSAGE_TXT"), ATTRIBUTE_TXT, F("Some settings files are missing !"), 0);
    break;
  case ERROR_SOME_USER_SETTINGS_FILES_ARE_CORRUPTED:
    Nextion_Serial_Transmit(F("TITLE_TXT"), ATTRIBUTE_TXT, F("Error !"), 0);
    Nextion_Serial_Transmit(F("MESSAGE_TXT"), ATTRIBUTE_TXT, F("Some user settings files are corrupted !"), 0);
    break;
  case ERROR_THE_FILE_DO_NOT_EXIST:
    Nextion_Serial_Transmit(F("TITLE_TXT"), ATTRIBUTE_TXT, F("Error !"), 0);
    Nextion_Serial_Transmit(F("MESSAGE_TXT"), ATTRIBUTE_TXT, F("The file doesn't exist !"), 0);
    break;
  case WARNING_WRONG_PASSWORD:
    break;
  case WARNING_WRONG_USERNAME:
    Nextion_Serial_Transmit(F("WRONG_TXT"), ATTRIBUTE_TXT, F("Wrong Username !"), 0);
    Serial.println(F("Wrong Username !"));
    break;
  case WARNING_DO_YO_REALLY_WANT_TO_DELETE_THIS_ITEM:
    break;
  default:
    break;
  }
}*/

  void GalaxOS_Class::USB_Serial_Transmit(char const *USB_Serial_Transmit_String, byte Alignment)
  {
    unsigned int USB_Serial_Transmit_String_Lenght = strlen(USB_Serial_Transmit_String);
    byte Lines = USB_Serial_Transmit_String_Lenght;
    Lines = Lines / 72;
    if (USB_Serial_Transmit_String_Lenght % 72 != 0)
      Lines++;
    if (Lines == 1)
    {
      switch (Alignment)
      {
      case STYLE_LEFT_ALIGNMENT:
        Serial.print(F("|| > "));
        for (byte i = 1; i <= USB_Serial_Transmit_String_Lenght; i++)
        {
          Serial.print(USB_Serial_Transmit_String[i]);
        }
        for (byte i = 1; i <= 72 - USB_Serial_Transmit_String_Lenght; i++)
        {
          Serial.print(" ");
        }
        Serial.print(F(" ||"));
        Serial.print(F("\r"));
        Serial.print(F("\n"));
        break;
      case STYLE_CENTER_ALIGNMENT:
        //not coded now
        break;
      case STYLE_RIGHT_ALIGNMENT:
        //not coded now
        break;
      case STYLE_JUSTIFIED_ALIGNMENT:
        //not coded now
        break;
      default:
        break;
      }
    }
    else
    {
      //not coded now
    }
  }

  void Musical_Digital_Player(void *pvParameters)
  {
    /*Serial.print(F("Musical Digital Player ..."));
  ledcAttachPin(GalaxOS.Get_Speaker_Pin(), 0);
  int Frequency;
  int Duration;
  Temporary_File = Drive.open(Temporary_File_Path);
  if (Temporary_File)
  {
    while (Temporary_File.available())
    {
      Frequency = Temporary_File.read();
      Frequency *= 256;
      Frequency += Temporary_File.read();
      Frequency += GalaxOS.Get_C_Frequency();
      Duration = Temporary_File.read();
      Duration *= 256;
      Duration += Temporary_File.read();
      ledcWriteTone(0, Frequency);
      vTaskDelay(pdMS_TO_TICKS(Duration));
    }
  }
  else
  {
    //error handle
  }
  ledcWriteTone(0, 0);
  vTaskSuspend(GalaxOS.Musical_Digital_Player_Handle);*/
  }

  void GalaxOS_Class::Synchronise_Time()
  {
    char NTP_Server[20] = "pool.ntp.org";
    const long GMT_Offset = 3600;
    const long Daylight_Offset = 3600;
    if (WiFi.status() != WL_CONNECTED)
    {
      //error handle
      return;
    }
    configTime(GMT_Offset, Daylight_Offset, NTP_Server);
    if (!getLocalTime(&Time))
    {
      //error handle
      Serial.println(F("Failed to get time"));
      return;
    }
    Serial.println(&Time, "%A, %B %d %Y %H:%M:%S");
    vTaskDelay(pdMS_TO_TICKS(1000));
    Serial.println(&Time, "%A, %B %d %Y %H:%M:%S");
  }

  void Pictviewer()
  {
    /*Nextion_Serial.print(F("page Pictviewer\xFF\xFF\xFF"));
  Nextion_Serial.print(F("FILENAME_TXT.txt=\""));
  Nextion_Serial.print(Temporary_File_Name);
  Nextion_Serial.print(F("\"\xFF\xFF\xFF"));
  unsigned int Width;
  unsigned int Height;
  unsigned int Size;
  unsigned long Data_offset;
  unsigned int Encoding;
  unsigned int Array_Size;
  byte Red;
  byte Green;
  byte Blue;
  unsigned int Color;
  Serial.print(F("Open path :"));
  Serial.println(Temporary_File_Path);
  Temporary_File = Drive.open(Temporary_File_Path);
  if (Temporary_File)
  {
    //Read the header
    Temporary_File.seek(0);
    if (Temporary_File.read() == 66 && Temporary_File.read() == 77)
    {
      Serial.println(F("It's a Bitmap File"));
      Temporary_File.seek(2);
      Size = int(Temporary_File.read()); //in bytes
      Serial.print(F("Size :"));
      Serial.println(Size);
      Nextion_Serial.print(F("SIEZ_NUM.val="));
      Nextion_Serial.print(Size);
      Nextion_Serial.print(F("\xFF\xFF\xFF"));
      Temporary_File.seek(10);
      Data_offset = long(Temporary_File.read());
      Serial.print(F("Data Offset :"));
      Serial.println(Data_offset);
      Temporary_File.seek(18);
      Width = int(Temporary_File.read());
      Serial.print(F("Width :"));
      Serial.println(Width);
      Nextion_Serial.print(F("WIDTH_NUM.val="));
      Nextion_Serial.print(Width);
      Nextion_Serial.print(F("\xFF\xFF\xFF"));
      Temporary_File.seek(22);
      Height = long(Temporary_File.read());
      Nextion_Serial.print(F("HEIGH_NUM.val="));
      Nextion_Serial.print(Height);
      Nextion_Serial.print(F("\xFF\xFF\xFF"));
      Serial.print(F("Height :"));
      Serial.println(Height);
      Temporary_File.seek(28);
      Encoding = int(Temporary_File.read());
      Serial.print(F("Encoding :"));
      Serial.println(Encoding);
      Height += 24;
      Width += 10;
      Temporary_File.seek(Data_offset);
      Serial.println(Temporary_File.position());
      if (Encoding == 16)
      {
        //Draw picture
        Serial.println(F("16 bit encoding"));
        for (int y = Height; y > 24; y--)
        {
          for (int x = 10; x < Width; x++)
          {
            Serial.println(Temporary_File.peek());
            Blue = Temporary_File.read();
            Serial.println(Temporary_File.peek());
            Green = Temporary_File.read();
            Color = Blue;
            Color = Color << 8;
            Color = Color | Green;
            Serial.println(Color);
            Nextion_Serial.print(F("fill "));
            Nextion_Serial.print(x);
            Nextion_Serial.write(0x2c);
            Nextion_Serial.print(y);
            Nextion_Serial.write(0x2c);
            Nextion_Serial.print(1);
            Nextion_Serial.write(0x2c);
            Nextion_Serial.print(1);
            Nextion_Serial.write(0x2c);
            Nextion_Serial.print(Color);
            Nextion_Serial.write(0xff);
            Nextion_Serial.write(0xff);
            Nextion_Serial.write(0xff);
          }
        }
      }
      else if (Encoding == 24)
      {
        Serial.println(F("24 bit encoding"));
        for (int y = Height; y > 24; y--)
        {
          for (int x = 10; x < Width; x++)
          {
            Serial.println(Temporary_File.peek());
            Blue = Temporary_File.read();
            Serial.println(Temporary_File.peek());
            Green = Temporary_File.read();
            Serial.println(Temporary_File.peek());
            Red = Temporary_File.read();
            Color = Red << 6;
            Color = Color | Green;
            Color = Color << 5;
            Color = Color | Blue;
            Serial.println(Color);
            Nextion_Serial.print(F("fill "));
            Nextion_Serial.print(x);
            Nextion_Serial.write(0x2c);
            Nextion_Serial.print(y);
            Nextion_Serial.write(0x2c);
            Nextion_Serial.print(1);
            Nextion_Serial.write(0x2c);
            Nextion_Serial.print(1);
            Nextion_Serial.write(0x2c);
            Nextion_Serial.print(map(Color, 0, 16777215, 0, 65535));
            Nextion_Serial.write(0xff);
            Nextion_Serial.write(0xff);
            Nextion_Serial.write(0xff);
          }
          Temporary_File.read();
          Temporary_File.read();
        }
      }

      else
      {
        Serial.println(F("The 32 bit encoding isn't be supported now"));
      }
    }
    else
    {
      Serial.println(F("It isn't a bitmap file"));
    }
  }
  else
  {
    Serial.println(F("The File Doesn't Exist or isn't readable"));
  }*/
  }