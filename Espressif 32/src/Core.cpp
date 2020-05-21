//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//||                                                                            ||
//||      _____       ___   _           ___  __    __       _____   _____       ||
//||     |  ___|     /   | | |         /   | | |  | |      |  _  | |  ___|      ||
//||     | |        / /| | | |        / /| |  | || |       | | | | | |___       ||
//||     | |  _    / /_| | | |       / /_| |   |  |        | | | | |___  |      ||
//||     | |_| |  / ___  | | |___   / ___  |  | || |       | |_| |  ___| |      ||
//||     |_____| /_/   |_| |_____| /_/   |_| |_|  |_|      |_____| |_____|      ||
//||                                                                            ||
//||                                                                            ||
//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//|| For ESP-32 based MPUs                                                      ||
//|| Version : - Alix ANNERAUD (c) 2020                                         ||

//Nextion Wiring//
//Red -> 5v     //
//Blue -> P16   //
//Yellow -> P17 //
//Black -> GND  // 

//   SD Card    //
//MISO -> P19   //
//MOSI -> P23   //
//SCK -> P18    //
//CS -> P5      //
//3.3 v -> 3.3  //
//GND -> GND    //

//Communication Settings Path : /USERS/%USERNAME%/STTNGS/.GSF//
//Password Settings Path : /USERS/%USERNAME%/STTNGS/PASSWORD.GSF//
//Keyboard Settings Path : /USERS/%USERNAME%/STTNGS/KEYBOARD.GSF//

#include "Arduino.h"

#include "core.hpp"
#include "WiFi.h"
#include "galaxos.hpp"

/*char WiFi_SSID[] = "Avrupa";
char WiFi_Password[] = "0749230994";*/

GalaxOS_Class::GalaxOS_Class() //builder
{
  //strcpy(WiFi_SSID, "Avrupa");
  //strcpy(WiFi_Password, "0749230994");
  for (int i = 0; i < 4; i++)
  {
    Software_Pointer[i] = NULL;
  }

  for (int i = 0; i < 6; i++)
  {
    Taskbar_Items_PID[i] = 255;
    Taskbar_Items_Icon[i] = 10;
  }

  Current_Page = 0;
  Last_Page = 0;

  Low_RAM_Threshold = 2000;

  C_MIDI = 60;

  C_Frequency = 262;

  Username = "\0";
  Password = "\0";

  Speaker_Pin = 25;

  iGOS_Pointer = NULL;
  Ultrasonic_Pointer = NULL;
  Software_Pointer[0] = NULL;
  Software_Pointer[1] = NULL;
  Software_Pointer[2] = NULL;
  Software_Pointer[3] = NULL;
}

GalaxOS_Class::~GalaxOS_Class() //detroyer
{
}

void GalaxOS_Class::Open_File(String const &File_Path_To_Open)
{
  File Temporary_Local_File = SD_MMC.open(File_Path_To_Open);
  if (!Temporary_Local_File)
  {
    //error handle
    return;
  }
  String File_Name = Temporary_Local_File.name();
  uint8_t i;
  for (i = 1; i < 14; i++) //extract extension
  {
    if (File_Name.charAt(i) == '.')
    {
      break;
    }
  }
  char Extension[3] = {File_Name.charAt(i + 1), File_Name.charAt(i + 2), File_Name.charAt(i + 3)};
  if (strcmp(Extension, "WAV"))
  {
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
    //error handle : unknow extension
  }
}

void GalaxOS_Class::Get_Software_Pointer(iGOS_Class *&Software_Pointer_To_Set)
{
  Software_Pointer_To_Set = iGOS_Pointer;
}

void GalaxOS_Class::Get_Software_Pointer(Periodic_Class *&Software_Pointer_To_Set)
{
  Software_Pointer_To_Set = Periodic_Pointer;
}

void GalaxOS_Class::Get_Software_Pointer(File_Manager_Class *&Software_Pointer_To_Set)
{
  Software_Pointer_To_Set = File_Manager_Pointer;
}

void GalaxOS_Class::Get_Software_Pointer(Calculator_Class *&Software_Pointer_To_Set)
{
  Software_Pointer_To_Set = Calculator_Pointer;
}

void GalaxOS_Class::Get_Software_Pointer(Signal_Generator_Class *&Software_Pointer_To_Set)
{
  Software_Pointer_To_Set = Signal_Generator_Pointer;
}

void GalaxOS_Class::Nextion_Upload_Firmware(String const &Path)
{
  if (!SD_MMC.exists(Path))
  {
    //error handle
    return;
  }
  while (Nextion_Serial.available()) //clear serial buffer
  {
    Nextion_Serial.read();
  }
  Nextion_Serial.print(F("\xFF\xFF\xFF")); //empty : clear
  Nextion_Serial.print(F("DRAKJHSUYDGBNCJHGJKSHBDN\xFF\xFF\xFF"));
  Nextion_Serial.print(F("\xFF\xFF\xFF")); //empty : clear
  Nextion_Serial.print(F("connectÿÿÿ"));
  Nextion_Serial.print(F("ÿÿconnectÿÿÿ"));
  byte i = 0;
  while (Nextion_Serial.available() == 0)
  {
    vTaskDelay(pdMS_TO_TICKS(100));
    i++;
    if (i > 50)
    {
      //error handle : no reply from screen
      return;
    }
  }
  String Temporary_String = "";
  for (byte i = 0; i < 5; i++)
  {
    Temporary_String += char(Nextion_Serial.read());
  }
  while (Nextion_Serial.available())
  {
    Nextion_Serial.read();
  }
  if (Temporary_String != "comok")
  {
    return;
  }
  Temporary_File = SD_MMC.open(Path, FILE_READ);
  uint32_t Size = Temporary_File.size();
  Nextion_Serial.print(F("whmi-wri "));
  Nextion_Serial.print(Size);
  Nextion_Serial.print(F(",921600"));
  Nextion_Serial.print(F(",res0\xFF\xFF\xFF"));
  while (Temporary_File.available() >= 4096)
  {
    while (Nextion_Serial.available() == 0)
    {
      vTaskDelay(50);
    }
    if (Nextion_Serial.read() != 0x05)
    {
      //error handle
      return;
    }
    for (uint16_t i = 0; i < 4096; i++)
    {
      Nextion_Serial.print(Temporary_File.read());
    }
  }
  while (Temporary_File.available()) //final packet
  {
    Nextion_Serial.print(Temporary_File.read());
  }
  while (Nextion_Serial.available() == 0)
  {
    vTaskDelay(50);
  }
  if (Nextion_Serial.read() != 0x05)
  {
    //error handle
    return;
  }
  Serial.println(F("Succefully transmited file"));
}

void GalaxOS_Class::Open_Software(uint8_t const &Software_ID)
{
  switch (Software_ID)
  {
  case SOFTWARE_IGOS_ID:
    if (iGOS_Pointer == NULL)
    {
      iGOS_Pointer = new iGOS_Class;
    }
    else
    {
      iGOS_Pointer->Execute('R', 'E');
    }
    break;
  case SOFTWARE_FILE_MANAGER_ID:
    if (File_Manager_Pointer == NULL)
    {
      File_Manager_Pointer = new File_Manager_Class;
    }
    else
    {
      File_Manager_Pointer->Execute('R', 'E');
    }
  default:
    break;
  }
}

void GalaxOS_Class::Close_Software(uint8_t const &Software_ID)
{
  switch (Software_ID)
  {
  case SOFTWARE_IGOS_ID:
    if (iGOS_Pointer != NULL)
    {
      delete iGOS_Pointer;
      iGOS_Pointer = NULL;
    }
    break;
  default:
    break;
  }
}

void GalaxOS_Class::Set_Software_Pointer(byte const &Software_Pointer_ID, GalaxOS_Software_Class &Software_Pointer_To_Set)
{
  Software_Pointer[Software_Pointer_ID] = &Software_Pointer_To_Set;
}

byte GalaxOS_Class::Get_Speaker_Pin()
{
  return Speaker_Pin;
}

int GalaxOS_Class::Get_C_Frequency()
{
  return C_Frequency;
}

byte GalaxOS_Class::Get_C_MIDI()
{
  return C_MIDI;
}

void GalaxOS_Class::Start()
{
  Serial.begin(921600);                             //PC Debug UART
  Nextion_Serial.begin(921600, SERIAL_8N1, 16, 17); //Nextion UART
  Serial.println(F("\r||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"));
  Serial.println(F("||                                                                            ||"));
  Serial.println(F("||      _____       ___   _           ___  __    __       _____   _____       ||"));
  Serial.println(F("||     |  ___|     /   | | |         /   | | |  | |      |  _  | |  ___|      ||"));
  Serial.println(F("||     | |        / /| | | |        / /| |  | || |       | | | | | |___       ||"));
  Serial.println(F("||     | |  _    / /_| | | |       / /_| |   |  |        | | | | |___  |      ||"));
  Serial.println(F("||     | |_| |  / ___  | | |___   / ___  |  | || |       | |_| |  ___| |      ||"));
  Serial.println(F("||     |_____| /_/   |_| |_____| /_/   |_| |_|  |_|      |_____| |_____|      ||"));
  Serial.println(F("||                                                                            ||"));
  Serial.println(F("||                                                                            ||"));
  Serial.println(F("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"));
  Serial.println(F("||     Flash : 1,310,720 Bytes - EEPROM : 512 Bytes - RAM : 327,680 Bytes     ||"));
  Serial.println(F("||               Galax OS Embedded Edition - Alix ANNERAUD - Dev              ||"));
  Serial.println(F("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"));
  Serial.println(F("|| > Starting Galax OS ...                                                    ||"));
  Serial.println(F("|| > Mount The SD Card ...                                                    ||"));
  //Audio.speakerPin = SpeakerPin;
  if (!SD_MMC.begin())
  {
    Serial.println(F("|| > Warning : The SD Card isn't mounted.                                     ||"));
  }
  else
  {
    Serial.println(F("|| > The SD Card is mounted.                                                  ||"));
  }
  xTaskCreatePinnedToCore(Nextion_Serial_Receive, "GOS NSR", 4096, NULL, 2, &Nextion_Serial_Receive_Handle, 0);
  //xTaskCreatePinnedToCore(Musical_Digital_Player, "Musical_Digital", 4096, NULL, 2, &Musical_Digital_Player_Handle, 1);
  //vTaskSuspend(GalaxOS.Musical_Digital_Player_Handle);
  xTaskCreatePinnedToCore(Ressource_Monitor, "Ressource_Monitor", 2048, NULL, 2, &Ressource_Monitor_Handle, 1);

  Serial.println(F("|| > Loading Task ...                                                         ||"));
  Serial.println(F("|| > Waiting for Display ...                                                  ||"));

  //bypass for dev purpose
  Username = "ALIX";
  Password = "ALIX";
  Open_Desk();

  strcpy(WiFi_SSID, "Avrupa");
  strcpy(WiFi_Password, "0749230994");

  float Test_Float = 123456789;
  Set_Variable('T', Test_Float);
  Serial.println(Test_Float);
  Get_Variable('T', Test_Float);
  Serial.println(Test_Float);

  WiFi_Connect();
  Synchronise_Time();
}


void GalaxOS_Class::Data_File_Get_Key(const __FlashStringHelper* Path, const __FlashStringHelper* Key_Name, String &Key_Value_To_Get)
{
  File Temporary_Local_File = SD_MMC.open(Path);
  uint32_t Temporary_Local_File_Position = 0;
  if (!Temporary_Local_File)
  {
    //error handle : cannot open file
    return;
  }
  Temporary_File.seek(0);
  long Timeout = millis() + 5000;
  char Temporary_Char = 0;
  if (!Temporary_Local_File.find(Key_Name))
  {
    //error handle : cannot keyname
    return;
  }
  if (!Temporary_Local_File.seek(Temporary_Local_File.position() - strlen_P(Key_Name) - 1))
  {
    //error handle
    return;
  }
  if (Temporary_Local_File.read() == 0x0A)
  {
    //error handle
    return;
  }
  if (!Temporary_Local_File.seek(Temporary_Local_File.position() + strlen_P(Key_Name)))
  {
    //error handle
    return;
  }
  if (Temporary_Local_File.read() != ';')
  {
    //error
    return;
  }
  while (Temporary_Local_File.available())
  {
    Temporary_Char = Temporary_Local_File.read();

    if (Temporary_Char == 0x0D)
    {

      break;
    }
    else
    {
      Key_Value_To_Get += (char)Temporary_Char;
    }
  }
}

void GalaxOS_Class::Data_File_Get_Key(String const &Path, char (&Key_Name)[], String &Key_Value_To_Get)
{
  File Temporary_Local_File = SD_MMC.open(Path);
  uint32_t Temporary_Local_File_Position = 0;
  if (!Temporary_Local_File)
  {
    //error handle : cannot open file
    return;
  }
  Temporary_File.seek(0);
  long Timeout = millis() + 5000;
  char Temporary_Char = 0;
  if (!Temporary_Local_File.find(Key_Name))
  {
    //error handle : cannot keyname
    return;
  }
  if (!Temporary_Local_File.seek(Temporary_Local_File.position() - strlen(Key_Name) - 1))
  {
    //error handle
    return;
  }
  if (Temporary_Local_File.read() == 0x0A)
  {
    //error handle
    return;
  }
  if (!Temporary_Local_File.seek(Temporary_Local_File.position() + strlen(Key_Name)))
  {
    //error handle
    return;
  }
  if (Temporary_Local_File.read() != ';')
  {
    //error
    return;
  }
  while (Temporary_Local_File.available())
  {
    Temporary_Char = Temporary_Local_File.read();

    if (Temporary_Char == 0x0D)
    {

      break;
    }
    else
    {
      Key_Value_To_Get += (char)Temporary_Char;
    }
  }
}

void GalaxOS_Class::Set_Variable(char const &Tag, long const &Long_To_Set)
{ //float
  Temporary_File = SD_MMC.open("/GALAXOS/MEMORY/LONG/" + String(Tag), FILE_WRITE);
  uint8_t Split_Long[] = {(uint8_t)Long_To_Set, (uint8_t)Long_To_Set >> 8, (uint8_t)Long_To_Set >> 16, (uint8_t)Long_To_Set >> 24};
  if (Temporary_File)
  {
    if (Temporary_File.write(Split_Long, 4) != 4)
    {
      //error handle
    }
    Temporary_File.close();
  }
  else
  {
    //error
  }
}

void GalaxOS_Class::Get_Variable(char const &Tag, long &Long_To_Get)
{ //float
  Temporary_File = SD_MMC.open("/GALAXOS/MEMORY/LONG/" + String(Tag), FILE_WRITE);
  if (Temporary_File)
  {
    Long_To_Get = ((long)Temporary_File.read() << 24) | ((long)Temporary_File.read() << 16) | ((long)Temporary_File.read() << 8) | (long)Temporary_File.read();
    Temporary_File.close();
    return;
  }
  else
  {
    //error
    return;
  }
}

void GalaxOS_Class::Set_Variable(char const &Tag, String const &String_To_Set)
{ //string
  SD_MMC.remove("/GALAXOS/MEMORY/STRING/" + String(Tag));
  Temporary_File = SD_MMC.open("/GALAXOS/MEMORY/STRING/" + String(Tag), FILE_WRITE);
  if (Temporary_File)
  {
    Temporary_File.print(String_To_Set);
    Temporary_File.close();
    return;
  }
  else
  {
    //error
    return;
  }
}

void GalaxOS_Class::Get_Variable(char const &Tag, String &String_To_Get)
{ //string
  Temporary_File = SD_MMC.open("/GALAXOS/MEMORY/STRING/" + String(Tag), FILE_READ);
  if (Temporary_File)
  {
    while (Temporary_File.available())
    {
      String_To_Get += String((char)Temporary_File.read());
    }
    Temporary_File.close();
    return;
  }
  else
  {
    //error
    return;
  }
}

void GalaxOS_Class::Set_Variable(char const &Tag, char const &Char_To_Set)
{ //char
  Temporary_File = SD_MMC.open("/GALAXOS/MEMORY/CHAR/" + String(Tag), FILE_WRITE);
  if (Temporary_File)
  {
    Temporary_File.write(Char_To_Set);
    Temporary_File.close();
    return;
  }
  else
  {
    //error
    return;
  }
}

void GalaxOS_Class::Get_Variable(char const &Tag, char &Char_To_Get)
{ //char
  Temporary_File = SD_MMC.open("/GALAXOS/MEMORY/CHAR/" + String(Tag), FILE_READ);
  if (Temporary_File)
  {
    Char_To_Get = Temporary_File.read();
    Temporary_File.close();
    return;
  }
  else
  {
    //error
    return;
  }
}

void GalaxOS_Class::Set_Variable(char const &Tag, byte const &Byte_To_Set)
{ //byte
  Temporary_File = SD_MMC.open("/GALAXOS/MEMORY/BYTE/" + String(Tag), FILE_WRITE);
  if (Temporary_File)
  {
    Temporary_File.write(Byte_To_Set);
    Temporary_File.close();
    return;
  }
  else
  {
    //error
    return;
  }
}

void GalaxOS_Class::Get_Variable(char const &Tag, byte &Byte_To_Get)
{ //byte
  Temporary_File = SD_MMC.open("/GALAXOS/MEMORY/BYTE/" + String(Tag), FILE_READ);
  if (Temporary_File)
  {
    Byte_To_Get = Temporary_File.read();
    Temporary_File.close();
  }
  else
  {
    //error
  }
}

void GalaxOS_Class::Set_Variable(char const &Tag, int const &Integer_To_Set)
{ //integer
  Temporary_File = SD_MMC.open("/GALAXOS/MEMORY/INTEGER/" + String(Tag), FILE_WRITE);
  if (Temporary_File)
  {
    uint8_t Split_Integer[] = {(uint8_t)Integer_To_Set << 8, (uint8_t)Integer_To_Set};
    if (Temporary_File.write(Split_Integer, 2) != 2)
    {
      //error handle
    }
    Temporary_File.close();
  }
  else
  {
    //error
  }
}

void GalaxOS_Class::Get_Variable(char const &Tag, int &Integer_To_Get)
{ //integer
  Temporary_File = SD_MMC.open("/GALAXOS/MEMORY/INTEGER/" + String(Tag), FILE_WRITE);
  if (Temporary_File)
  {
    Integer_To_Get = ((int)Temporary_File.read() << 8) | (int)Temporary_File.read();
    Temporary_File.close();
  }
  else
  {
    //error
  }
}

void GalaxOS_Class::Set_Variable(char const &Tag, float const &Float_To_Set)
{ //float
  Temporary_File = SD_MMC.open("/GALAXOS/MEMORY/FLOAT/" + String(Tag), FILE_WRITE);
  uint8_t Split_Float[] = {(uint8_t)Float_To_Set, (uint8_t)Float_To_Set >> 8, (uint8_t)Float_To_Set >> 16, (uint8_t)Float_To_Set >> 24};
  if (Temporary_File)
  {
    if (Temporary_File.write(Split_Float, 4) != 4)
    {
      //error handle
    }
    Temporary_File.close();
  }
  else
  {
    //error
  }
}

void GalaxOS_Class::Get_Variable(char const &Tag, float &Float_To_Get)
{ //float
  Temporary_File = SD_MMC.open("/GALAXOS/MEMORY/FLOAT/" + String(Tag), FILE_WRITE);
  if (Temporary_File)
  {
    Float_To_Get = ((float)Temporary_File.read() << 24) | ((float)Temporary_File.read() << 16) | ((float)Temporary_File.read() << 8) | (float)Temporary_File.read();
    Temporary_File.close();
  }
  else
  {
    //error
  }
}

void GalaxOS_Class::Open_Menu()
{
  Nextion_Serial.print(F("page Menu_P1\xFF\xFF\xFF"));
  Nextion_Serial.print(F("USERNAME_TXT.txt=\""));
  Nextion_Serial.print(Username);
  Nextion_Serial.print(F("\"\xFF\xFF\xFF"));
}

void GalaxOS_Class::Open_Desk()
{
  Nextion_Serial.print(F("page Desk\xFF\xFF\xFF"));
  uint8_t Minimized_Application_Icon;
  for (uint8_t Slot = 1; Slot < 6; Slot++)
  {
    if (iGOS_Pointer != NULL)
    {
      Slot++;
    }

    Nextion_Serial.print(F("SLOT"));
    Nextion_Serial.print(Slot);
    Nextion_Serial.print(F("_PIC.pic="));
    Nextion_Serial.print(Minimized_Application_Icon);
    Nextion_Serial.print(F("\xFF\xFF\xFF"));
  }
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

uint16_t GalaxOS_Class::Check_Credentials(String const &Username_To_Check, String const &Password_To_Check)
{
  Temporary_File = SD_MMC.open("/USERS/" + String(Username_To_Check) + "/STTNGS/PASSWORD.GSF", FILE_READ);
  String Temporary_Password = "";
  if (Temporary_File)
  {
    while (Temporary_File.available())
    {
      if (isAlphaNumeric(Temporary_File.peek()))
      {
        Password += String(Temporary_File.read());
      }
      else
      {
        Temporary_File.read();
      }
    }
    Temporary_File.close();
  }
  else
  {
    Serial.println(F("Wrong Username !"));
    Temporary_File.close();
    return WARNING_WRONG_USERNAME;
  }
  if (Temporary_Password == Temporary_Password)
  {
    Serial.println(F("Good Password"));
    GalaxOS.Username = Username_To_Check;
    GalaxOS.Password = Password_To_Check;
    return INFORMATION_GOOD_CREDENTIALS;
  }
  else
  {
    Nextion_Serial.print(F("WRONG_TXT.txt=\"Wrong Password !\"\xFF\xFF\xFF"));
    Serial.println(F("Wrong Password !"));
    return WARNING_WRONG_PASSWORD;
  }
}

void GalaxOS_Class::Load_System_Files()
{
  Serial.println(F("Load System Files ..."));
  Temporary_File = SD_MMC.open("/GALAXOS.GSF");
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
  return;

  Nextion_Serial.print(F("LOAD_TXT.txt=\"Loading System Files ...\"\xFF\xFF\xFF"));
  Nextion_Serial.print(F("LOAD_TIM.tim=50\xFF\xFF\xFF"));
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
    Nextion_Serial.print(F("page Load_User\xFF\xFF\xFF"));
  }
  else
  {
    //error : wrong username or password
    Nextion_Serial.print(F("WRONG_TXT.txt=\"Wrong Credentials !\"\xFF\xFF\xFF"));
  }
}

void GalaxOS_Class::Nextion_Serial_Transmit(String Component, byte Type, String Nextion_Serial_Transmit_String, int Nextion_Serial_Transmit_Integer) //not used anymore in order to save ram
{
  switch (Type)
  {
  case ATTRIBUTE_TXT: //.txt for Text & Scrolling Text, QRCode, Button, DualStateButton //
    Nextion_Serial.print(Component);
    Nextion_Serial.print(F(".txt="));
    Nextion_Serial.write(0x22);
    Nextion_Serial.print(Nextion_Serial_Transmit_String);
    Nextion_Serial.write(0x22);
    break;
  case ATTRIBUTE_VAL: //.val for Number,Progress Bar & Slider, Variable//
    Nextion_Serial.print(Component);
    Nextion_Serial.print(F(".val="));
    Nextion_Serial.print(Nextion_Serial_Transmit_Integer);
    break;
  case ATTRIBUTE_TIM: //.tim for Timer//
    Nextion_Serial.print(Component);
    Nextion_Serial.print(F(".tim="));
    Nextion_Serial.print(Nextion_Serial_Transmit_Integer);
    break;
  case COMMAND_PAGE_NAME: //Change page to page specified name.//
    Nextion_Serial.print(F("page "));
    Nextion_Serial.print(Component);
    break;
  case ATTRIBUTE_PIC: //.PIC
    Nextion_Serial.print(Component);
    Nextion_Serial.print(F(".pic="));
    Nextion_Serial.print(Nextion_Serial_Transmit_Integer);
    break;
  case ATTRIBUTE_EN: //Timer enable
    Nextion_Serial.print(Component);
    Nextion_Serial.print(F(".en="));
    Nextion_Serial.print(Nextion_Serial_Transmit_Integer);
    break;
  case COMMAND_PAGE_ID: //page PID//
    byte PID;
    PID = Nextion_Serial_Transmit_Integer;
    Nextion_Serial.print(F("page "));
    Nextion_Serial.print(PID);
    break;
  case COMMAND_CLICK_ID: //click
    Nextion_Serial.print(F("click "));
    Nextion_Serial.print(Component);
    Nextion_Serial.write(0x2C);
    Nextion_Serial.print(Nextion_Serial_Transmit_Integer);
    break;
  }
  Nextion_Serial.write(0xFF);
  Nextion_Serial.write(0xFF);
  Nextion_Serial.write(0xFF);
  return;
}

uint8_t GalaxOS_Class::Event_Handler(const uint16_t &Event_ID)
{
  Nextion_Serial.print(F("page Event/xFF/xFF/xFF"));

  byte i = 0;
  while (Event_Reply == 0 && i < 100)
  {
    vTaskDelay(pdMS_TO_TICKS(50));
    i++;
  }
  if (i > 100)
  {
    Nextion_Serial.print(F("page "));
    Nextion_Serial.print(Last_Page);
    Nextion_Serial.print(F("/xFF/xFF/xFF"));
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
  Temporary_File = SD_MMC.open(Temporary_File_Path);
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

void Nextion_Serial_Receive(void *pvParameters)
{
  static char Tag;
  uint8_t Return_Code = 0;
  uint8_t Temporary_Byte_Array[7] = {0};
  String Temporary_String = String("");

  (void)pvParameters;
  for (;;)
  {
    if (Nextion_Serial.available())
    {
      Return_Code = Nextion_Serial.read();
      Serial.print(F("|| R_C : "));
      Serial.print(Return_Code);
      switch (Return_Code)
      {
      case INFORMATION_NEXTION_NUMERIC_DATA_ENCLOSED:
        Serial.print(F(" | Tag : "));
        Serial.print(Tag);
        Serial.print(F(" | Raw :"));
        Serial.write(Temporary_Byte_Array[4]);
        Serial.write(Temporary_Byte_Array[3]);
        Serial.write(Temporary_Byte_Array[2]);
        Serial.write(Temporary_Byte_Array[1]);

        if (7 == Nextion_Serial.readBytes((char *)Temporary_Byte_Array, 7))
        {
          if (Temporary_Byte_Array[4] == 0xFF && Temporary_Byte_Array[5] == 0xFF && Temporary_Byte_Array[6] == 0xFF)
          {
            long Temporary_Long = ((long)Temporary_Byte_Array[4] << 24) | ((long)Temporary_Byte_Array[3] << 16) | (Temporary_Byte_Array[2] << 8) | (Temporary_Byte_Array[1]);
            if (Tag != 0x00)
            {
              Serial.print(F(" | Long : "));
              Serial.println(Temporary_Long);
              GalaxOS.Set_Variable(Tag, Temporary_Long);
              Tag = '\0';
            }
            else
            {
              Serial.println(F("Error : Cannot Set Variable Because Tag is NULL."));
              //error handle
            }
          }
        }
        break;
      case INFORMATION_NEXTION_STRING_DATA_ENCLOSED:
        Temporary_String = String("");
        Temporary_Byte_Array[0] = Nextion_Serial.read();
        Serial.print(F(" | Type : "));
        Serial.print(Temporary_Byte_Array[0]);
        if (Temporary_Byte_Array[0] != CODE_COMMAND && Temporary_Byte_Array[0] != CODE_COMMAND_NEW) //not a command, therefore a variable
        {
          Temporary_Byte_Array[1] = Nextion_Serial.read(); //tag or ID
          Serial.print(F(" | Tag : "));
          Serial.print(Temporary_Byte_Array[1]);
          switch (Temporary_Byte_Array[0])
          {
          case CODE_VARIABLE_CHAR:
            Tag = (char)Temporary_Byte_Array[1];
            GalaxOS.Set_Variable(Tag, (char)Nextion_Serial.read());
            Tag = '\0';
            break;
          case CODE_VARIABLE_STRING:
            Tag = (char)Temporary_Byte_Array[1];
            break;
          case CODE_VARIABLE_LONG:
            Tag = (char)Temporary_Byte_Array[1];
            break;
          case CODE_VARIABLE_UNSIGNED_LONG:
            Tag = (char)Temporary_Byte_Array[1];
            break;
          case CODE_SOFTWARE_OPEN:
            GalaxOS.Open_Software(Temporary_Byte_Array[1]);
            break;
          case CODE_SOFTWARE_CLOSE:
            GalaxOS.Close_Software(Temporary_Byte_Array[1]);
            break;
          default:
            //error handle
            break;
          }
        }
        Temporary_Byte_Array[3] = 0; //counter for 0xFF ending code
        while (Nextion_Serial.available())
        {
          Temporary_Byte_Array[2] = Nextion_Serial.read();
          if (Temporary_Byte_Array[2] == 255)
          {
            ++Temporary_Byte_Array[3];
            if (Temporary_Byte_Array[3] >= 3)
            {
              Serial.println(F(" ||"));
              break;
            }
          }
          else
          {
            Temporary_String += (char)Temporary_Byte_Array[2];
            Serial.print((char)Temporary_Byte_Array[2]);
          }
        }
        if (Temporary_Byte_Array[0] == CODE_VARIABLE_STRING)
        {
          GalaxOS.Set_Variable(Tag, Temporary_String);
          Temporary_String = String("");
          Tag = '\0';
        }
        else if (Temporary_Byte_Array[0] == CODE_COMMAND || Temporary_Byte_Array[0] == CODE_COMMAND_NEW)
        {
          if (Temporary_String == "LoadSystem")
          {
            GalaxOS.Load_System_Files();
          }
          else if (Temporary_String == "Login")
            GalaxOS.Load_User_Files();
          else if (Temporary_String == "OpenMenu")
            GalaxOS.Open_Menu();
          else if (Temporary_String == "OpenDesk")
            GalaxOS.Open_Desk();
          else if (Temporary_String == "F&F")
            Files_And_Folders();
          //else if (Temporary_String == "F&F_RDelete") Event_Handler_Request();
          //taskbar item
          else if (Temporary_String == "TBItem1")
          {
            Nextion_Serial.print(F("page "));
            Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[0]);
            Nextion_Serial.print(F("\xFF\xFF\xFF"));
          }
          else if (Temporary_String == "TBItem2")
          {
            Nextion_Serial.print(F("page "));
            Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[1]);
            Nextion_Serial.print(F("\xFF\xFF\xFF"));
          }
          else if (Temporary_String == "TBItem3")
          {
            Nextion_Serial.print(F("page "));
            Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[2]);
            Nextion_Serial.print(F("\xFF\xFF\xFF"));
          }
          else if (Temporary_String == "TBItem4")
          {
            Nextion_Serial.print(F("page "));
            Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[3]);
            Nextion_Serial.print(F("\xFF\xFF\xFF"));
          }
          else if (Temporary_String == "TBItem5")
          {
            Nextion_Serial.print(F("page "));
            Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[4]);
            Nextion_Serial.print(F("\xFF\xFF\xFF"));
          }
          else if (Temporary_String == "TBItem6")
          {
            Nextion_Serial.print(F("page "));
            Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[5]);
            Nextion_Serial.print(F("\xFF\xFF\xFF"));
          }
          else if (Temporary_String == "TBItem7")
          {
            Nextion_Serial.print(F("page "));
            Nextion_Serial.print(GalaxOS.Taskbar_Items_PID[6]);
            Nextion_Serial.print(F("\xFF\xFF\xFF"));
          }
          else
          {
            switch (GalaxOS.Current_Page)
            {
            case 20: //Event
              GalaxOS.Event_Reply = uint8_t(Temporary_String.charAt(1));
              break;
            case 27: //iGOS
              GalaxOS.iGOS_Pointer->Execute(Temporary_String.charAt(0), Temporary_String.charAt(1));
              break;
            case 38: //Piano
              GalaxOS.Piano_Pointer->Execute(Temporary_String.charAt(0), Temporary_String.charAt(1));
              break;
            default:
              Serial.println(F("Unknow Page ID"));
              break;
            }
          }
        }
        break;
      case INFORMATION_NEXTION_CURRENT_PAGE_NUMBER:
        if (4 == Nextion_Serial.readBytes((char *)Temporary_Byte_Array, 4))
        {
          if (Temporary_Byte_Array[1] == 0xFF && Temporary_Byte_Array[2] == 0xFF && Temporary_Byte_Array[3] == 0xFF)
          {
            Serial.print(F(" | Current Page : "));
            Serial.print(Temporary_Byte_Array[0]);

            GalaxOS.Last_Page = GalaxOS.Current_Page;
            GalaxOS.Current_Page = Temporary_Byte_Array[0];
          }
        }
        break;
      default:
        Temporary_Byte_Array[3] = 0;       //counter for 0xFF ending code
        while (Nextion_Serial.available()) //Purge until the end of the intruction
        {
          Temporary_Byte_Array[2] = Nextion_Serial.read();
          if (Temporary_Byte_Array[2] == 0xFF)
          {
            Temporary_Byte_Array[3]++;
            if (Temporary_Byte_Array[3] >= 3)
            {

              break;
            }
          }
        }
        GalaxOS.Event_Handler((int)Temporary_Byte_Array[0]);
        break;
      }
    }
    vTaskDelay(50);
  }
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

void GalaxOS_Class::WiFi_Connect()
{
  if (!WiFi.setHostname("GOS ESP32"))
  {
    Serial.println("Cannot set a custom hostname !");
    //error handle
  }
  WiFi.begin(WiFi_SSID, WiFi_Password);
  byte i = 0;
  while (WiFi.status() != WL_CONNECTED && i < 10)
  {
    vTaskDelay(pdMS_TO_TICKS(500));
    i++;
  }
  if (WiFi.status() == WL_CONNECTED)
  {
    Serial.print(F("Connected to WiFi :"));
  }
  else if (WiFi.status() == WL_IDLE_STATUS)
  {
    //error handle
  }
  else
  {
    Serial.println(F("Can't Connect to WiFi"));
  }
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
  Temporary_File = SD_MMC.open(Temporary_File_Path);
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