#include "Arduino.h"

#include "Core.hpp"

#define INSTANCE_POINTER GalaxOS_Class::Instance_Pointer
GalaxOS_Class *GalaxOS_Class::Instance_Pointer = NULL;

GalaxOS_Class GalaxOS;

extern Software_Handle_Class Shell_Handle;
extern Software_Handle_Class Oscilloscope_Handle;
extern Software_Handle_Class Paint_Handle;
extern Software_Handle_Class Calculator_Handle;
extern Software_Handle_Class TinyBasic_Handle;
extern Software_Handle_Class Internet_Browser_Handle;
extern Software_Handle_Class Music_Player_Handle;
extern Software_Handle_Class Piano_Handle;
extern Software_Handle_Class Ultrasonic_Handle;

/*char WiFi_SSID[] = "Avrupa";
char WiFi_Password [] = "0749230994";*/

GalaxOS_Class::GalaxOS_Class() : Display(),
                                 Sound(),
                                 Keyboard(2, 6)
{
  if (Instance_Pointer != NULL)
  {
    // something went wrong
    ESP.restart();
  }
  Instance_Pointer = this;

  //strcpy(WiFi_SSID, "Avrupa");
  //strcpy(WiFi_Password, "0749230994");

#if SD_MODE == 0
  Drive = &SD_MMC;
#else
  Drive = &SD;
#endif

  memset(Current_Username, '\0', sizeof(Current_Username));

  Tag = 0x00;

  memset(Open_Software_Pointer, '\0', sizeof(Open_Software_Pointer));

  //Core_Instruction_Queue_Handle = xQueueCreate(10, sizeof(Core_Instruction));
}

GalaxOS_Class::~GalaxOS_Class() // Detroyer
{
  Instance_Pointer = NULL;
}

// Idle task, lowest priority, nothing is running

void Idle_Task_Software_Core(void *pvParameters)
{
  (void)pvParameters;
  while (1)
  {
    Serial.print(F("Idle software core"));
    vTaskDelay(1);
  }
}

void Idle_Task_System_Core(void *pvParameters)
{
  (void)pvParameters;
  while (1)
  {
    Serial.print(F("Idle system core"));
    vTaskDelay(1);
  }
}

// Used to initialise the core

void GalaxOS_Class::Start()
{
  xTaskCreatePinnedToCore(GalaxOS_Class::Core_Task, "Core Task", 4 * 1024, NULL, SYSTEM_TASK_PRIORITY, &Core_Task_Handle, SYSTEM_CORE);
}

void GalaxOS_Class::Load()
{
  Serial.begin(SERIAL_SPEED); //PC Debug UART
  Remaining_Spaces = 0;
  Horizontal_Separator();
  Print_Line();
  Print_Line(" _____       ___   _           ___  __    __       _____   _____ ", STYLE_CENTER_ALIGNMENT);
  Print_Line("|  ___|     /   | | |         /   | | |  | |      |  _  | |  ___|", STYLE_CENTER_ALIGNMENT);
  Print_Line("| |        / /| | | |        / /| |  | || |       | | | | | |___ ", STYLE_CENTER_ALIGNMENT);
  Print_Line("| |  _    / /_| | | |       / /_| |   |  |        | | | | |___  |", STYLE_CENTER_ALIGNMENT);
  Print_Line("| |_| |  / ___  | | |___   / ___  |  | || |       | |_| |  ___| |", STYLE_CENTER_ALIGNMENT);
  Print_Line("|_____| /_/   |_| |_____| /_/   |_| |_|  |_|      |_____| |_____|", STYLE_CENTER_ALIGNMENT);
  Print_Line();
  Print_Line();
  Horizontal_Separator();
  //Print_Line("Flash : 1,310,720 Bytes - EEPROM : 512 Bytes - RAM : " + char(ESP.getFreeHeap()) + "/ 327680 Bytes");
  Print_Line(F("Galax OS Embedded Edition - Alix ANNERAUD - Alpha"));
  Horizontal_Separator();
  Print_Line(F("Starting Galax OS ..."), 0);
  // Initialize SD Card
  Print_Line(F("Mount The SD Card ..."), 0);

#if SD_MODE == 0
  pinMode(14, INPUT_PULLUP);
  //pinMode(15, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  Drive = &SD_MMC;
#else

  Drive = &SD;
#endif

  while (!Drive->begin() || Drive->cardType() == CARD_NONE)
  {
    Display.Draw_Text(140, 228, 200, 20, Main_16, Display.White, Display.Black, Display.Center, Display.Center, Display.None, "Please Insert System Drive");
    vTaskDelay(pdMS_TO_TICKS(50));
  }

  Display.Draw_Fill(140, 228, 200, 20, Display.Black);

  File Temporary_File;

  // Initialize Virtual Memory
  /*Virtual_Memory_Semaphore = xSemaphoreCreateMutex();

  if (Virtual_Memory_Semaphore == NULL)
  {
    //error handle
  }
  else
  {
    xSemaphoreGive(Virtual_Memory_Semaphore);
  }*/

  //Testing Virtual Memory

  /*Verbose_Print_Line("> Testing Virtual Memory ...");

  uint32_t Test_Float = 123456789;
  Set_Variable('T', &Test_Float);
  Serial.println(Test_Float);
  Get_Variable('T', &Test_Float);
  Serial.println(Test_Float);

  uint16_t Test_Integer = 1543;
  Set_Variable('T', (uint32_t *)&Test_Integer);
  Serial.println(Test_Integer);
  Get_Variable('T', (uint32_t *)&Test_Integer);
  Serial.println(Test_Integer);

  uint8_t Test_Byte = 128;
  Set_Variable('T', (uint32_t *)&Test_Byte);
  Serial.println(Test_Byte);
  Get_Variable('T', (uint32_t *)&Test_Byte);
  Serial.println(Test_Byte);

  String Test_String = "test";
  Set_Variable('T', Test_String);
  Serial.println(Test_String);
  Get_Variable('T', Test_String);
  Serial.println(Test_String);/

  if (Test_Float != 123456789 || Test_Integer != 1543 || Test_Byte != 128 || Test_String == "test")
  {
    Verbose_Print("> Waring : Test failed for uint64_t");
  }*/

  // Load Task
  Verbose_Print_Line("> Loading Task ...");
  //xTaskCreatePinnedToCore(Idle_Task_Software_Core, "Idle Software", 2 * 1024, NULL, IDLE_TASK_PRIORITY, NULL, SOFTWARE_CORE);
  //xTaskCreatePinnedToCore(Idle_Task_System_Core, "Idle System", 2 * 1024, NULL, IDLE_TASK_PRIORITY, NULL, SYSTEM_CORE);

  // Check if the system state was saved
  Verbose_Print_Line("> Check existing of file last state ...");
  if (Drive->exists("/GALAXOS/GOSCUSA.GSF"))
  {
    Restore_System_State();
  }

  // Initialize display & Load display configuration
  Display.Set_Callback_Function_Numeric_Data(&Incomming_Numeric_Data_From_Display);
  Display.Set_Callback_Function_String_Data(&Incomming_String_Data_From_Display);
  Display.Set_Callback_Function_Event(&Incomming_Event_From_Display);
  Display.Begin();
  {
    Verbose_Print_Line("> Load display registry ...");
    Temporary_File = Drive->open(Display_Registry_Path);
    DynamicJsonDocument Display_Registry(256);
    deserializeJson(Display_Registry, Temporary_File);
    Display.Set_Backlight(Display_Registry["Brightness"] | 100);
    //Display.Set_Baud_Rate(Display_Registry["Baud Rate"] | 921600, false);
  }
  Display.Set_Current_Page(F("Core_Load"));
  Display.Click(7, 1); // Shadow in annimation
  vTaskDelay(pdMS_TO_TICKS(4000));


  // Sound load
  {
    Temporary_File = Drive->open(Sound_Registry_Path);
    DynamicJsonDocument Sound_Registry(256);
    deserializeJson(Sound_Registry, Temporary_File);
    Sound.Set_Volume(Sound_Registry["Volume"] | 0);
    Temporary_File.close();
  }
  Temporary_File = Drive->open("/GALAXOS/SOUNDS/STARTUP.WAV");
  Sound.Play(Temporary_File);
  vTaskDelay(pdMS_TO_TICKS(10000));

  // Load network configuration
  {
    Verbose_Print_Line("> Load network registry ...");
    Temporary_File = Drive->open(Network_Registry_Path);
    if (!Temporary_File)
    {
      //error handle
    }
    DynamicJsonDocument Network_Registry(256);
    deserializeJson(Network_Registry, Temporary_File);
    // WiFi :
    WiFi.setHostname(Network_Registry["WiFi"]["Host Name"]); // Set hostname
    JsonArray Name_Array = Network_Registry["WiFi"]["Names"];
    JsonArray Password_Array = Network_Registry["WiFi"]["Passwords"];
    char Name[32], Password[32];
    for (uint8_t i = 0; i < Name_Array.size(); i++)
    {
      strcpy(Name, Name_Array[i]);
      strcpy(Password, Password_Array[i]);
      WiFi.setAutoConnect(false);
      WiFi.begin(Name, Password);
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
    Temporary_File.close();
  }
  Display.Set_Value(F("LOAD_BAR"), 20);
  vTaskDelay(pdMS_TO_TICKS(800));

  // Set Regional Parameters
  {
    Verbose_Print_Line("> Load regional registry ...");
    Temporary_File = Drive->open(Regional_Registry_Path);
    if (!Temporary_File)
    {
      //error
    }
    DynamicJsonDocument Regional_Registry(256);
    deserializeJson(Regional_Registry, Temporary_File);
    char NTP_Server[Regional_Registry["Time"]["NTP Server"].size()];
    strcpy(NTP_Server, Regional_Registry["Time"]["NTP Server"]);
    Serial.println(NTP_Server);
    char Time_Zone[Regional_Registry["Time"]["Time Zone"].size()];
    strcpy(Time_Zone, Regional_Registry["Time"]["Time Zone"]);
    Serial.println(Time_Zone);
    configTime(0, 0, NTP_Server);

    setenv("TZ", Time_Zone, 1);
    Temporary_File.close();
  }

  Display.Set_Value(F("LOAD_BAR"), 40);
  vTaskDelay(pdMS_TO_TICKS(1200));

  Display.Set_Value(F("LOAD_BAR"), 60);
  vTaskDelay(pdMS_TO_TICKS(800));

  // Load software (including Shell UI)
  Verbose_Print_Line("> Load software registry");
  //Verbose_Print_Line("> Load software ...");
  Software_Handle_Pointer[0] = &Shell_Handle;
  Software_Handle_Pointer[1] = &Oscilloscope_Handle;
  Software_Handle_Pointer[2] = &Paint_Handle;
  Software_Handle_Pointer[3] = &Calculator_Handle;
  Software_Handle_Pointer[4] = &TinyBasic_Handle;
  Software_Handle_Pointer[5] = &Internet_Browser_Handle;

  {
    Temporary_File = Drive->open(Software_Registry_Path);
    if (!Temporary_File)
    {
      return;
    }
    DynamicJsonDocument Software_Registry(256);
    deserializeJson(Software_Registry, Temporary_File);
  }

  Display.Set_Value(F("LOAD_BAR"), 80);
  vTaskDelay(pdMS_TO_TICKS(1200));
  // to do

  Display.Set_Value(F("LOAD_BAR"), 100);
  vTaskDelay(pdMS_TO_TICKS(800));
  Display.Click(7, 0); // Shadow out animation;
  vTaskDelay(pdMS_TO_TICKS(2000));

  //Finish startup
  Verbose_Print_Line(F("> Open Shell"));
  Open_Software_Pointer[1] = (*Shell_Handle.Load_Function_Pointer)();
  Open_Software_Pointer[0] = Open_Software_Pointer[1];
}

// Main task for the core
void GalaxOS_Class::Core_Task(void *pvParameters)
{
  (void)pvParameters;
  //Core_Instruction *Core_Instruction_Pointer;
  GalaxOS.Load();
  while (1)
  {
    if (ESP.getFreeHeap() < 2000)
    {
      Serial.println("Low Memory !");
    }
    INSTANCE_POINTER->Synchronise_Time();
#if STACK_OVERFLOW_DETECTION == 1
    Verbose_Print("> Current task high watermark :");
    Serial.println(uxTaskGetStackHighWaterMark(GalaxOS_Class::Instance_Pointer->Open_Software_Pointer[0]->Task_Handle));
#endif
    vTaskDelay(pdMS_TO_TICKS(200));
  }
  /*xQueueReceive(GalaxOS.Core_Instruction_Queue_Handle, Core_Instruction_Pointer, portMAX_DELAY);
    Core_Instruction_Pointer->Return_Pointer = Core_Instruction_Pointer->Function_Pointer(Core_Instruction_Pointer);
    xSemaphoreGive(Core_Instruction_Pointer->Executed);
    vTaskDelay(pdMS_TO_TICKS(5));*/
}

void GalaxOS_Class::Save_System_State()
{
  if (Drive->exists("/GALAXOS/GOSeCUSA.GSF"))
  {
    if (Drive->remove("/GALAXOS/GOSCUSA.GSF"))
    {
      //event handler
    }
  }
  DynamicJsonDocument System_Save_Registry(256);

  System_Save_Registry["Current Username"] = Current_Username;

  File Temporary_File = Drive->open("/GALAXOS/GOSCUSA.GSF");
  serializeJson(System_Save_Registry, Temporary_File);
  Temporary_File.close();
}

// Callback function for screen

void GalaxOS_Class::Incomming_String_Data_From_Display(const char *Received_Data, uint8_t Size)
{
  Serial.println(Received_Data);
  String Temporary_String;
  switch (Received_Data[0])
  {
  case Code::Close:
    GalaxOS.Close_Software();
    break;
  case Code::Minimize:
    GalaxOS.Minimize_Software();
    break;
  case Code::Command:
  case Code::Command_New:
    GalaxOS.Open_Software_Pointer[0]->Execute(Received_Data[1], Received_Data[2]);
    break;
  case Code::Variable_String_Local:
    Temporary_String = String(Received_Data + 2);
    GalaxOS.Open_Software_Pointer[0]->Set_Variable(&Temporary_String, Variable_String_Local, Received_Data[0]);
    break;
  case Code::Variable_Char_Local:
    GalaxOS.Open_Software_Pointer[0]->Set_Variable(Received_Data + 2, Variable_Char_Local, Received_Data[1], Size);
    GalaxOS.Tag = '\0';
    break;
  case Code::Variable_String_Global:
    break;
  case Code::Variable_Long_Local:
    GalaxOS.Tag = Received_Data[1];
    break;
  case Code::Variable_Long_Global:
    GalaxOS.Tag = Received_Data[1];
    break;
  default:
    //error handle
    break;
  }
}

void GalaxOS_Class::Incomming_Numeric_Data_From_Display(uint32_t &Received_Data)
{
  if (GalaxOS.Tag != '\0')
  {
    GalaxOS.Open_Software_Pointer[0]->Set_Variable(&Received_Data, GalaxOS.Variable_Long_Local, GalaxOS.Tag);
    GalaxOS.Tag = '\0';
  }
  else
  {
    GalaxOS.Event_Handler(GalaxOS.Screen_Data_Exception);
  }
}

void GalaxOS_Class::Incomming_Event_From_Display(uint8_t &Event_Code)
{
}

void GalaxOS_Class::Open_File(File &File_To_Open)
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
  if (strcmp(Extension, "GEF")) // executable file : load it into FFS
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
    if (Drive->open(F("/GALAXOS/REGISTRY/EXTENSIO.GCF")))
    {
      DynamicJsonDocument Extension_Registry(256);
      File Temporary_File = Drive->open(Extension_Registry_Path);
      deserializeJson(Extension_Registry, Temporary_File);
      for (uint8_t i = 0; i < MAXIMUM_SOFTWARE; i++)
      {
        if (strcmp(Software_Handle_Pointer[i]->Name, Extension_Registry[Extension]))
        {
          Open_Software(Software_Handle_Pointer[i]);
          for (uint8_t j = 0; i < 8; i++)
          {
            if (Open_Software_Pointer[j]->Handle_Pointer == Software_Handle_Pointer[i])
            {
              Open_Software_Pointer[j]->Open_File(File_To_Open);
              File_To_Open.close();
              return;
            }
          }
        }
      }
    }
    //error handle : unknow extension
  }
  File_To_Open.close();
}

// Software management

void GalaxOS_Class::Open_Software(Software_Handle_Class *Software_Handle_Pointer)
{
  for (uint8_t i = 0; i < 8; i++) //check if software is openned already
  {
    if (Open_Software_Pointer[i] != NULL)
    {
      if (Software_Handle_Pointer == Open_Software_Pointer[i]->Handle_Pointer)
      {
        Maximize_Software(i);
        return;
      }
    }
  }
  for (uint8_t i = 0; i < 8; i++)
  {
    if (Open_Software_Pointer[i] == NULL)
    {
      Open_Software_Pointer[i] = (*Software_Handle_Pointer->Load_Function_Pointer)();
      break;
    }
  }
}

void GalaxOS_Class::Close_Software(Software_Handle_Class *Software_Handle_To_Close)
{
  if (Software_Handle_To_Close == NULL) //by default delete current running software
  {
    Open_Software_Pointer[0]->Close();
    Open_Software_Pointer[0] = NULL;
  }
  else
  {
    for (uint8_t i = 2; i <= 7; i++)
    {
      if (Open_Software_Pointer[i]->Handle_Pointer == Software_Handle_To_Close)
      {
        Open_Software_Pointer[i]->Close();
        Open_Software_Pointer[i] = NULL;
      }
    }
  }
  Maximize_Software(1);
}

void GalaxOS_Class::Minimize_Software()
{
  Open_Software_Pointer[0]->Minimize();
  for (uint8_t i = 2; i <= 7; i++)
  {
    if (Open_Software_Pointer[i] == NULL)
    {
      Open_Software_Pointer[i] = Open_Software_Pointer[0];
      Open_Software_Pointer[0] = NULL;
      break;
    }
  }
  Maximize_Software(1);
}

void GalaxOS_Class::Maximize_Software(uint8_t Slot)
{
  if (Open_Software_Pointer[Slot] == NULL) // Error : no software to maximize
  {
    return;
  }
  if (strcmp(Open_Software_Pointer[0]->Handle_Pointer->Name, "Shell")) // Shell
  {
    Open_Software_Pointer[1] = Open_Software_Pointer[0];
  }
  else if (Open_Software_Pointer != NULL)
  {
    Minimize_Software();
  }
  Open_Software_Pointer[0] = Open_Software_Pointer[Slot];
  Open_Software_Pointer[0]->Maximize();
}

uint8_t GalaxOS_Class::Get_Software_Handle_Pointer(const char *Software_Name)
{
  for (byte i = 0; i <= MAXIMUM_SOFTWARE; i++)
  {
    if (i >= MAXIMUM_SOFTWARE)
    {
      return 255; // nothing found
    }
    if (Software_Handle_Pointer[i] == NULL)
    {
      continue;
    }
    if (strcmp(Software_Handle_Pointer[i]->Name, Software_Name))
    {
      return i;
    }
  }
  return 255;
}

void GalaxOS_Class::Set_Load_Function(const char *Software_Name, Software_Class *(*Load_Function_To_Set)())
{
  Software_Handle_Pointer[Get_Software_Handle_Pointer(Software_Name)]->Load_Function_Pointer = Load_Function_To_Set;
}

// Serial communication with commputer

void GalaxOS_Class::Horizontal_Separator()
{
  Serial.println(F("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"));
}

void GalaxOS_Class::Print_Line(const __FlashStringHelper *Text_To_Print, uint8_t const &Alignement)
{
  Serial.print(F("||"));
  Serial.print(F(" "));
  Serial.print(Text_To_Print);
  Serial.println(F("||"));
}

void GalaxOS_Class::Print_Line(const char *Text_To_Print, uint8_t const &Alignement)
{
  Serial.print(F("||"));

  if (sizeof(Text_To_Print) > 64)
  {
    //unsupported now
    return;
  }
  Remaining_Spaces = 64 - sizeof(Text_To_Print);
  switch (Alignement)
  {
  case 0: //left
    Serial.print(F(" "));
    Serial.print(Text_To_Print);
    break;
  case 1: //centered
    Serial.print(F(" "));
    for (uint8_t i = 0; i < Remaining_Spaces / 2; i++)
    {
      Serial.println(F(" "));
    }
    Serial.print(Text_To_Print);
    Remaining_Spaces /= 2;
  default:

    break;
  }
  for (uint8_t i = 0; i < Remaining_Spaces; i++)
  {
    Serial.println(F(" "));
  }
  Serial.println(F("||"));
}

void GalaxOS_Class::Print_Line()
{
  Serial.print(F("||                                                                            ||"));
}

// --------------------------

void GalaxOS_Class::Restore_System_State()
{
  Display.Set_Current_Page(PAGE_DESK);

  if (!Drive->exists("/GALAXOS/GOSCUSA.GSF"))
  {
    return;
  }
  File Temporary_File = Drive->open("/GALAXOS/GOSCUSA.GSF");
  DynamicJsonDocument Temporary_Json_Document(256);
  //ReadBufferingStream Buffering_Stream(Drive->open("/"), 64); dont work, i don't know why

  if (deserializeJson(Temporary_Json_Document, Temporary_File) == true)
  {
    return;
  }

  strcpy(Current_Username, Temporary_Json_Document["Current Username"]);

  Temporary_File.close();
  ESP.restart();
}

//---------------------------------------------------------------------------//
//                                Virtual Memory Management                  //
//---------------------------------------------------------------------------//

// Char array
/*void GalaxOS_Class::Set_Variable(char const &Tag, const char *String_To_Set, Software_Handle_Class *Software_Handle_Targeted = NULL)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  if (Software_Handle_Targeted == NULL) // global scope
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/GLOBAL/STRING/" + Tag, FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.print(String_To_Set);
    }
  }
  else // local scope
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/" + char(Software_Handle_Targeted->Name) + "/STRING/" + Tag, FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.print(String_To_Set);
    }
  }
  Virtual_Memory_File.close();
  xSemaphoreGive(Virtual_Memory_Semaphore);
}

void GalaxOS_Class::Get_Variable(char const &Tag, char *String_To_Set, Software_Handle_Class *Software_Handle_Targeted = NULL)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  if (Software_Handle_Targeted == NULL) // global scope
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/GLOBAL/STRING/" + Tag, FILE_READ);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.readBytes(String_To_Set, sizeof(String_To_Set));
    }
  }
  else // local scope
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/" + char(Software_Handle_Targeted->Name) + "/STRING/" + Tag, FILE_READ);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.readBytes(String_To_Set, sizeof(String_To_Set));
    }
  }
  Virtual_Memory_File.close();
  xSemaphoreGive(Virtual_Memory_Semaphore);
}/

// String
void GalaxOS_Class::Set_Variable(char const &Tag, String const &String_To_Set, uint16_t Size, Software_Handle_Class *Software_Handle_Targeted)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  if (Software_Handle_Targeted == NULL) // global scope
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/GLOBAL/STRING/" + Tag, FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.print(String_To_Set);
    }
  }
  else // local scope
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/" + String(*Software_Handle_Targeted->Name) + "/STRING/" + Tag, FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.print(String_To_Set);
    }
  }
  Virtual_Memory_File.close();
  xSemaphoreGive(Virtual_Memory_Semaphore);
}

void GalaxOS_Class::Get_Variable(char const &Tag, String &String_To_Get, uint16_t Size, Software_Handle_Class *Software_Handle_Targeted)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  if (Software_Handle_Targeted == NULL) // global scope
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/GLOBAL/STRING/" + Tag, FILE_READ);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      String_To_Get = Virtual_Memory_File.readString();
    }
  }
  else // local scope
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/" + String(*Software_Handle_Targeted->Name) + "/STRING/" + Tag, FILE_READ);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      String_To_Get = Virtual_Memory_File.readString();
    }
  }
  Virtual_Memory_File.close();
  xSemaphoreGive(Virtual_Memory_Semaphore);
}

// char array
void GalaxOS_Class::Set_Variable(char const &Tag, const char *String_To_Set, uint16_t Size, Software_Handle_Class *Software_Handle_Targeted)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  if (Software_Handle_Targeted == NULL) // global scope
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/GLOBAL/STRING/" + Tag, FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.print(String(String_To_Set));
    }
  }
  else // local scope
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/" + String(*Software_Handle_Targeted->Name) + "/STRING/" + Tag, FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.print(String(String_To_Set));
    }
  }
  Virtual_Memory_File.close();
  xSemaphoreGive(Virtual_Memory_Semaphore);
}

void GalaxOS_Class::Get_Variable(char const &Tag, char *String_To_Get, uint16_t Size, Software_Handle_Class *Software_Handle_Targeted)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  if (Software_Handle_Targeted == NULL) // global scope
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/GLOBAL/STRING/" + Tag, FILE_READ);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.readString().toCharArray(String_To_Get, Size);
    }
  }
  else // local scope
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/" + String(*Software_Handle_Targeted->Name) + "/STRING/" + Tag, FILE_READ);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.readString().toCharArray(String_To_Get, Size);
    }
  }
  Virtual_Memory_File.close();
  xSemaphoreGive(Virtual_Memory_Semaphore);
}

// 32-bit var
void GalaxOS_Class::Set_Variable(char const &Tag, uint32_t *Number_To_Set, uint16_t Size, Software_Handle_Class *Software_Handle_Targeted)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  Split_Number[0] = (uint8_t)Number_To_Set[0];
  Split_Number[1] = (uint8_t)Number_To_Set[0] << 8;
  Split_Number[2] = (uint8_t)Number_To_Set[0] << 16;
  Split_Number[3] = (uint8_t)Number_To_Set[0] << 24;
  if (Software_Handle_Targeted == NULL)
  {
    Virtual_Memory_File = Drive->open(Virtual_Global_Memory_File, FILE_WRITE);
    Virtual_Memory_File.seek(Tag << 1);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.write(Split_Number, 4);
    }
  }
  else
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/" + String(*Software_Handle_Targeted->Name) + "/VARIABLE.GSF", FILE_WRITE);
    Virtual_Memory_File.seek(Tag << 1);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.write(Split_Number, 4);
    }
  }
  Virtual_Memory_File.close();
  xSemaphoreGive(Virtual_Memory_Semaphore);
}

void GalaxOS_Class::Get_Variable(char const &Tag, uint32_t *Number_To_Get, uint16_t Size, Software_Handle_Class *Software_Handle_Targeted)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  if (Software_Handle_Targeted == NULL)
  {
    Virtual_Memory_File = Drive->open(Virtual_Global_Memory_File, FILE_READ);
    Virtual_Memory_File.seek(Tag << 1);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.readBytes((char *)Split_Number, 4);
    }
  }
  else
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/" + String(*Software_Handle_Targeted->Name) + "/VARIABLE.GSF", FILE_READ);
    Virtual_Memory_File.seek(Tag << 1);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.readBytes((char *)Split_Number, 4);
    }
  }
  Number_To_Get[0] = (uint32_t)Split_Number << 24 | (uint32_t)Split_Number << 16 | (uint32_t)Split_Number << 8 | (uint32_t)Split_Number;
  Virtual_Memory_File.close();
  xSemaphoreGive(Virtual_Memory_Semaphore);
}
/*
// 32-bit variable
void GalaxOS_Class::Set_Variable(uint8_t const &Tag, uint32_t const &Number_To_Set, Software_Handle_Class *Software_Handle_Targeted = NULL)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  Split_Number[0] = (uint8_t)Number_To_Set;
  Split_Number[1] = (uint8_t)Number_To_Set << 8;
  Split_Number[2] = (uint8_t)Number_To_Set << 16;
  Split_Number[3] = (uint8_t)Number_To_Set << 24;
  if (Software_Handle_Targeted == NULL)
  {
    Virtual_Memory_File = Drive->open(Virtual_Global_Memory_File, FILE_WRITE);
    Virtual_Memory_File.seek(Tag << 1);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.write(Split_Number, 4);
    }
  }
  else
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/" + char(Software_Handle_Targeted->Name) + "/VARIABLE.GSF", FILE_WRITE);
    Virtual_Memory_File.seek(Tag << 1);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.write(Split_Number, 4);
    }
  }
  Virtual_Memory_File.close();
  xSemaphoreGive(Virtual_Memory_Semaphore);
}

void GalaxOS_Class::Get_Variable(uint8_t const &Tag, uint32_t &Number_To_Get, Software_Handle_Class *Software_Handle_Targeted = NULL)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  if (Software_Handle_Targeted == NULL)
  {
    Virtual_Memory_File = Drive->open(Virtual_Global_Memory_File, FILE_READ);
    Virtual_Memory_File.seek(Tag << 1);
    if (Virtual_Memory_File)
    {
      Number_To_Get = Virtual_Memory_File.parseFloat();
    }
  }
  else
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/" + char(Software_Handle_Targeted) + "/VARIABLE.GSF", FILE_READ);
    Virtual_Memory_File.seek(Tag << 1);
    if (Virtual_Memory_File)
    {
      Number_To_Get = Virtual_Memory_File.parseFloat();
    }
  }
  Virtual_Memory_File.close();
  xSemaphoreGive(Virtual_Memory_Semaphore);
}

// 16 bit variable
void GalaxOS_Class::Set_Variable(uint8_t const &Tag, uint16_t* Number_To_Set, uint16_t const& Size = 1, Software_Handle_Class *Software_Handle_Targeted = NULL)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  if (Software_Handle_Targeted == NULL)
  {
    Virtual_Memory_File = Drive->open(Virtual_Global_Memory_File, FILE_WRITE);
    if (Virtual_Memory_File)
    {
      Split_Number[0] = (char)Number_To_Set;
      Split_Number[1] = (char)Number_To_Set << 8;
      Virtual_Memory_File.write(Split_Number, 2);
    }
  }
  else
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/" + char(Software_Handle_Targeted->Name) + "/VARIABLE.GSF", FILE_WRITE);
    if (Virtual_Memory_File)
    {
      Split_Number[0] = (char)Number_To_Set;
      Split_Number[1] = (char)Number_To_Set << 8;
      Virtual_Memory_File.write(Split_Number, 2);
    }
  }
  Virtual_Memory_File.close();
  xSemaphoreGive(Virtual_Memory_Semaphore);
}

void GalaxOS_Class::Get_Variable(uint8_t const &Tag, uint16_t* Number_To_Set, uint16_t const& Size = 1, Software_Handle_Class *Software_Handle_Targeted = NULL)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  if (Software_Handle_Targeted == NULL)
  {
    Virtual_Memory_File = Drive->open(Virtual_Global_Memory_File, FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Number_To_Set = Virtual_Memory_File.parseInt();
    }
  }
  else
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/" + char(Software_Handle_Targeted->Name) + "/VARIABLE.GSF", FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Number_To_Set = Virtual_Memory_File.parseInt();
    }
  }
  Virtual_Memory_File.close();
  xSemaphoreGive(Virtual_Memory_Semaphore);
}

// 8 bit variable
void GalaxOS_Class::Set_Variable(uint8_t const &Tag, uint8_t* Number_To_Set, uint16_t const& Size = 1, Software_Handle_Class *Software_Handle_Targeted = NULL)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  if (Software_Handle_Targeted == NULL)
  {
    Virtual_Memory_File = Drive->open(Virtual_Global_Memory_File, FILE_WRITE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.write(Number_To_Set, Size);
    }
  }
  else
  {
    Virtual_Memory_File = Drive->open("/GALAXOS/MEMORY/" + char(Software_Handle_Targeted->Name) + "/VARIABLE.GSF", FILE_WRTIE);
    Virtual_Memory_File.seek(0);
    if (Virtual_Memory_File)
    {
      Virtual_Memory_File.write(Number_To_Set, Size);
    }
  }
  Virtual_Memory_File.close();
  xSemaphoreGive(Virtual_Memory_Semaphore);
}

void GalaxOS_Class::Get_Variable(uint8_t const &Tag, uint8_t &Number_To_Set, Software_Handle_Class *Software_Handle_Targeted = NULL)
{
  xSemaphoreTake(Virtual_Memory_Semaphore, portMAX_DELAY);
  Virtual_Memory_File = Drive->open(Virtual_Global_Memory_File, FILE_READ);
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
}*/

// Account management
GalaxOS_Event GalaxOS_Class::Check_Credentials(const char *Username_To_Check, const char *Password_To_Check)
{
  if (Drive->exists("/USERS/" + String(Username_To_Check) + "/REGISTRY/USER.GRF"))
  {
    File Temporary_File = Drive->open("/USERS/" + String(Username_To_Check) + "/REGISTRY/USER.GRF");
    DynamicJsonDocument User_Registry(256);
    if (deserializeJson(User_Registry, Temporary_File))
    {
      return Wrong_Credentials;
    }
    char Password[24];
    strcpy(Password, User_Registry["Password"]);
    Serial.println(Password);
    if (strcmp(Password_To_Check, Password) == 0)
    {
      Verbose_Print_Line("> Good Credentials ...");
      Temporary_File.close();
      return Good_Credentials;
    }
    else
    {
      Verbose_Print_Line("> Wrong Credentials ...");
      Temporary_File.close();
      return Wrong_Credentials;
    }
  }
  return Wrong_Credentials;
}

GalaxOS_Event GalaxOS_Class::Login(const char *Username_To_Check, const char *Password_To_Check)
{
  if (Check_Credentials(Username_To_Check, Password_To_Check) == Good_Credentials)
  {

    return Good_Credentials;
  }
  else
  {
    return Check_Credentials(Username_To_Check, Password_To_Check);
  }
}

void GalaxOS_Class::Load_User_Files()
{
  Verbose_Print("> Load user files ...");
  if (Current_Username[0] == 255) // if not logged
  {
    Event_Handler(Not_Logged);
    return;
  }
  if (!Drive->exists(Users_Path + String(Current_Username)))
  {
    Event_Handler(Corrupted_User_File);
  }
}

/*  switch (Type)
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
  }*/

GalaxOS_Event GalaxOS_Class::Event_Handler(uint16_t const &Event_ID)
{

  Display.Set_Current_Page(F("Event"));

  DynamicJsonDocument Event_Registry(256);
  File Temporary_File = Drive->open(Event_Registry_Path);
  deserializeJson(Event_Registry, Temporary_File);

  Display.Set_Text("MESSAGE_TXT", Event_Registry[Event_ID]);
  byte i = 0;

  while (Event_Reply == 0 && i < 100)
  {
    vTaskDelay(pdMS_TO_TICKS(50));
    i++;
  }
  if (i > 100)
  {
    Display.Set_Current_Page(Display.Page_History[1]); //go to last page
    return Default;
  }
  return Event_Reply;
}

GalaxOS_Event GalaxOS_Class::Event_Handler(const __FlashStringHelper *Message, uint8_t Event_Type, const __FlashStringHelper *Button_Text_1, const __FlashStringHelper *Button_Text_2, const __FlashStringHelper *Button_Text_3)
{
  Display.Set_Current_Page(F("Event"));
  if (Button_Text_1 != NULL)
  {
    Display.Set_Text(F("BUTTON1"), Button_Text_1);
    if (Button_Text_2 != NULL)
    {
      Display.Set_Text(F("BUTTON2"), Button_Text_2);
    }
    else
    {
      Display.Set_Text(F("BUTTON2"), F(""));
    }
    if (Button_Text_3 != NULL)
    {
      Display.Set_Text(F("BUTTON3"), Button_Text_3);
    }
    else
    {
      Display.Set_Text(F("BUTTON3"), F(""));
    }
  }
  else
  {
    Display.Set_Text(F("BUTTON1"), F("Okay"));
    Display.Set_Text(F("BUTTON2"), F("Yes"));
    Display.Set_Text(F("BUTTON3"), F("No"));
  }

  switch (Event_Type)
  {
  case Error:
    Display.Set_Picture(F("EVENT_PIC"), 12);
    Display.Set_Text(F("TITLE_TXT"), F("Error"));
    break;
  case Warning:
    Display.Set_Picture(F("EVENT_PIC"), 12);
    Display.Set_Text(F("TITLE_TXT"), F("Warning"));
    break;
  case Information:
    Display.Set_Picture(F("EVENT_PIC"), 12);
    Display.Set_Text(F("TITLE_TXT"), F("Information"));
    break;
  case Question:
    Display.Set_Picture(F("EVENT_PIC"), 12);
    Display.Set_Text(F("TITLE_TXT"), F("Question"));
  default:
    break;
  }
  while (Event_Reply == 0)
  {
    vTaskDelay(pdMS_TO_TICKS(10));
  }
  GalaxOS_Event Event_Reply_Copy = Event_Reply;
  Event_Reply = 0;
  return Event_Reply_Copy;
}

void GalaxOS_Class::Synchronise_Time()
{
  static char Clock[5];
  time(&Now);
  localtime_r(&Now, &Time);
  itoa(Time.tm_hour, Clock, 10);
  itoa(Time.tm_min, Clock + 3, 10);
  Clock[2] = ':';
  Display.Set_Text(F("CLOCK_TXT"), Clock);
}

// Create System file at 1st boot

void GalaxOS_Class::Create_System_Files()
{
  // Display Registry
  DynamicJsonDocument Display_Registry(256);
  Display_Registry["Backlight"] = 75;
  Display_Registry["Baud Rate"] = 921600;
  File Temporary_File = Drive->open(Display_Registry_Path, FILE_WRITE);
  serializeJson(Display_Registry, Temporary_File);
  Display_Registry.clear();
  Temporary_File.close();

  // Network registry
  DynamicJsonDocument Network_Registry(256);
  Network_Registry["Host name"] = "ESP32";
  Network_Registry["Number WiFi AP"] = 0;
  Temporary_File = Drive->open(Network_Registry_Path, FILE_WRITE);
  serializeJson(Display_Registry, Temporary_File);
  Network_Registry.clear();
  Temporary_File.close();

  // Regional registry
  DynamicJsonDocument Regional_Registry(256);
  Temporary_File = Drive->open(Regional_Registry_Path, FILE_WRITE);
  serializeJson(Regional_Registry, Temporary_File);
  Regional_Registry.clear();
  Temporary_File.close();

  // Software registry
  DynamicJsonDocument Software_Registry(256);
  Temporary_File = Drive->open(Software_Registry_Path, FILE_WRITE);
  Software_Registry.clear();
  Temporary_File.close();
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
  Temporary_File = Drive->open(Temporary_File_Path);
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