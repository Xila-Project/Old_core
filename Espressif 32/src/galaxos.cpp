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
//Blue -> P16    //
//Yellow -> P17  //
//Black -> GND  //

//   SD Card    //
//MISO -> P19    //
//MOSI -> P23    //0
//SCK -> P18     //
//CS -> P5      //
//3.3 v -> 3.3 v//
//GND -> GND    //

//Communication Settings Path : /USERS/%USERNAME%/STTNGS/.GSF//
//Password Settings Path : /USERS/%USERNAME%/STTNGS/PASSWORD.GSF//
//Keyboard Settings Path : /USERS/%USERNAME%/STTNGS/KEYBOARD.GSF//

#include "Arduino.h"
#include "mbedtls/sha256.h"

#include "galaxos.hpp"
#include "WiFi.h"
#include "object.hpp"


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

  GalaxOS.Current_Page = 0;
  GalaxOS.Last_Page = 0;

  GalaxOS.Low_RAM_Threshold = 2000;

  GalaxOS.C_MIDI = 60;

  GalaxOS.C_Frequency = 262;

  GalaxOS.Username = "\0";
  GalaxOS.Password = "\0";

  GalaxOS.Speaker_Pin = 25;

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

iGOS_Class *GalaxOS_Class::Get_Software_Pointer()
{
  return iGOS_Pointer;
}

void GalaxOS_Class::Nextion_Upload_Firmware(String const &Path)
{
  if (!SD.exists(Path))
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
  Temporary_File = SD.open(Path, FILE_READ);
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
    Nextion_Serial.print(F("page iGOS\xFF\xFF\xFF"));
    break;
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
  if (!SD.begin())
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
  Nextion_Serial.print(F("page Desk\xFF\xFF\xFF"));
  Username = "ALIX";
  Password = "ALIX";

  strcpy(WiFi_SSID, "Avrupa");
  strcpy(WiFi_Password, "0749230994");

  
  WiFi_Connect();
  Synchronise_Time();
}

void GalaxOS_Class::Set_Variable(char const &Tag, long const &Long_To_Set)
{ //float
  Temporary_File = SD.open("/GALAXOS/MEMORY/LONG/" + String(Tag), FILE_WRITE);
  GalaxOS.Temporary_Split_Long.Long = Long_To_Set;
  if (Temporary_File)
  {
    Temporary_File.write(GalaxOS.Temporary_Split_Long.Byte, 4);
    Temporary_File.close();
    return;
  }
  else
  {
    //error
    return;
  }
}

void GalaxOS_Class::Get_Variable(char const &Tag, long &Long_To_Get)
{ //float
  Temporary_File = SD.open("/GALAXOS/MEMORY/LONG/" + String(Tag), FILE_WRITE);
  if (Temporary_File)
  {
    GalaxOS.Temporary_Split_Long.Byte[0] = Temporary_File.read();
    GalaxOS.Temporary_Split_Long.Byte[1] = Temporary_File.read();
    GalaxOS.Temporary_Split_Long.Byte[2] = Temporary_File.read();
    GalaxOS.Temporary_Split_Long.Byte[3] = Temporary_File.read();
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
  SD.remove("/GALAXOS/MEMORY/STRING/" + String(Tag));
  Temporary_File = SD.open("/GALAXOS/MEMORY/STRING/" + String(Tag), FILE_WRITE);
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
  Temporary_File = SD.open("/GALAXOS/MEMORY/STRING/" + String(Tag), FILE_READ);
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
  Temporary_File = SD.open("/GALAXOS/MEMORY/CHAR/" + String(Tag), FILE_WRITE);
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
  Temporary_File = SD.open("/GALAXOS/MEMORY/CHAR/" + String(Tag), FILE_READ);
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
  Temporary_File = SD.open("/GALAXOS/MEMORY/BYTE/" + String(Tag), FILE_WRITE);
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
  Temporary_File = SD.open("/GALAXOS/MEMORY/BYTE/" + String(Tag), FILE_READ);
  if (Temporary_File)
  {
    Byte_To_Get = Temporary_File.read();
    Temporary_File.close();
    return;
  }
  else
  {
    //error
    return;
  }
}

void GalaxOS_Class::Set_Variable(char const &Tag, int const &Integer_To_Set)
{ //integer
  Temporary_File = SD.open("/GALAXOS/MEMORY/INTEGER/" + String(Tag), FILE_WRITE);
  if (Temporary_File)
  {
    byte Split_Integer[2] = {0, 0};
    Split_Integer[0] = (Integer_To_Set >> 8) & 0xFF;
    Temporary_File.write(Split_Integer[0]);
    Split_Integer[1] = Integer_To_Set & 0xFF;
    Temporary_File.write(Split_Integer[1]);
    Temporary_File.close();
    return;
  }
  else
  {
    //error
    return;
  }
}

void GalaxOS_Class::Get_Variable(char const &Tag, int &Integer_To_Get)
{ //integer
  Temporary_File = SD.open("/GALAXOS/MEMORY/INTEGER/" + String(Tag), FILE_WRITE);
  if (Temporary_File)
  {
    Integer_To_Get |= Temporary_File.read() << 8;
    Integer_To_Get |= Temporary_File.read();
    Temporary_File.close();
    return;
  }
  else
  {
    //error
    return;
  }
}

void GalaxOS_Class::Set_Variable(char const &Tag, float const &Float_To_Set)
{ //float
  Temporary_File = SD.open("/GALAXOS/MEMORY/FLOAT/" + String(Tag), FILE_WRITE);
  GalaxOS.Temporary_Split_Float.Float = Float_To_Set;
  if (Temporary_File)
  {
    Temporary_File.write(GalaxOS.Temporary_Split_Float.Byte, 4);
    Temporary_File.close();
    return;
  }
  else
  {
    //error
    return;
  }
}

void GalaxOS_Class::Get_Variable(char const &Tag, float &Float_To_Get)
{ //float
  Temporary_File = SD.open("/GALAXOS/MEMORY/FLOAT/" + String(Tag), FILE_WRITE);
  if (Temporary_File)
  {
    GalaxOS.Temporary_Split_Float.Byte[0] = Temporary_File.read();
    GalaxOS.Temporary_Split_Float.Byte[1] = Temporary_File.read();
    GalaxOS.Temporary_Split_Float.Byte[2] = Temporary_File.read();
    GalaxOS.Temporary_Split_Float.Byte[3] = Temporary_File.read();
    Temporary_File.close();
    return;
  }
  else
  {
    //error
    return;
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
  return;
}

void Print_Free_Heap()
{
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
  Temporary_File = SD.open("/USERS/" + String(Username_To_Check) + "/STTNGS/PASSWORD.GSF", FILE_READ);
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
  Temporary_File = SD.open("/GALAXOS.GSF");
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
  GalaxOS.Get_Variable('U', Temporary_Username);
  GalaxOS.Get_Variable('P', Temporary_Password);
  if (GalaxOS.Check_Credentials(Temporary_Username, Temporary_Password) == INFORMATION_GOOD_CREDENTIALS)
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

void GalaxOS_Class::Event_Handler_Request(const uint16_t &Type)
{
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
}

void GalaxOS_Class::Event_Handler_Reply(const byte &Reply)
{
  switch (Reply)
  {
  case 0:
    break;
  default:
    break;
  }
}

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
  Temporary_File = SD.open(Temporary_File_Path);
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
          else if (Temporary_String == "Close_iGOS")
          {
            GalaxOS.Close_Software(SOFTWARE_IGOS_ID);
          }
          else
          {
            switch (GalaxOS.Current_Page)
            {
            case 27: //iGOS
              GalaxOS.iGOS_Pointer->Execute(Temporary_String.charAt(0), Temporary_String.charAt(1));
              break;
            case 38: //Piano
              if (Temporary_String == "CLow")
              {
                Piano(0, 0);
              }
              else if (Temporary_String == "C#Low")
                Piano(16, 1);
              else if (Temporary_String == "DLow")
                Piano(32, 2);
              else if (Temporary_String == "D#Low")
                Piano(50, 3);
              else if (Temporary_String == "ELow")
                Piano(68, 4);
              else if (Temporary_String == "FLow")
                Piano(88, 5);
              else if (Temporary_String == "F#Low")
                Piano(108, 6);
              else if (Temporary_String == "GLow")
                Piano(130, 7);
              else if (Temporary_String == "G#Low")
                Piano(154, 8);
              else if (Temporary_String == "ALow")
                Piano(178, 9);
              else if (Temporary_String == "A#Low")
                Piano(205, 10);
              else if (Temporary_String == "BLow")
                Piano(232, 11);
              else if (Temporary_String == "CHigh")
                Piano(262, 12);
              else if (Temporary_String == "C#High")
                Piano(293, 13);
              else if (Temporary_String == "DHigh")
                Piano(326, 14);
              else if (Temporary_String == "D#High")
                Piano(361, 15);
              else if (Temporary_String == "EHigh")
                Piano(398, 16);
              else if (Temporary_String == "FHigh")
                Piano(437, 17);
              else if (Temporary_String == "F#High")
                Piano(478, 18);
              else if (Temporary_String == "GHigh")
                Piano(522, 19);
              else if (Temporary_String == "G#High")
                Piano(569, 20);
              else if (Temporary_String == "AHigh")
                Piano(618, 21);
              else if (Temporary_String == "A#High")
                Piano(670, 22);
              else if (Temporary_String == "BHigh")
              {
                Piano(726, 23);
              }
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
        GalaxOS.Event_Handler_Request((int)Temporary_Byte_Array[0]);
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
  if(!getLocalTime(&Time))
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

Ultrasonic_Class::Ultrasonic_Class()
{
}

Ultrasonic_Class::~Ultrasonic_Class()
{
}

void Ultrasonic_Class::Get_Trig_Pin()
{
  GalaxOS.Get_Variable('A', Trig_Pin);
  pinMode(Trig_Pin, OUTPUT);
}

void Ultrasonic_Class::Get_Echo_Pin()
{
  GalaxOS.Get_Variable('B', Echo_Pin);
  pinMode(Echo_Pin, INPUT);
}

void Ultrasonic_Class::Read()
{
  digitalWrite(Trig_Pin, LOW);
  while (Nextion_Serial.available() == 0)
  {
    digitalWrite(Trig_Pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig_Pin, LOW);
    unsigned long Duration = pulseIn(Echo_Pin, HIGH);
    if (Duration > 30000)
    {
      Serial.println(F("|| > Onde perdue                                         ||"));
    }
    else
    {
      Duration /= 2;
      float Time = Duration / 1000000;
      int Distance = Time * SOUND_SPEED_AIR;
      Serial.print(F("|| > Distance :"));
      Serial.println(Distance);
      Nextion_Serial.print(F("DISTVAL_NUM.val="));
      Nextion_Serial.print(Distance);
      Nextion_Serial.print(F("\xFF\xFF\xFF"));
      vTaskDelay(100);
    }
  }
}

void Piano(int Frequency, int Note)
{
  ledcAttachPin(GalaxOS.Get_Speaker_Pin(), 0);
  String Temporary = "";
  unsigned long Duration = 200;
  Frequency += GalaxOS.Get_C_Frequency();
  Note += GalaxOS.Get_C_MIDI();
  Temporary = "Frequency : " + String(Frequency, DEC);
  Nextion_Serial.print(F("FREQUENCY_TXT.txt=\""));
  Nextion_Serial.print(Temporary);
  Nextion_Serial.print(F("\xFF\xFF\xFF"));
  Temporary = "MIDI Code : " + String(Note, DEC);
  Nextion_Serial.print(F("MIDICODE_TXT.txt=\""));
  Nextion_Serial.print(Temporary);
  Nextion_Serial.print(F("\xFF\xFF\xFF"));
  if (GalaxOS.MIDIOutEnable == true)
  {
    Serial.write(144);
    Serial.write(Note);
    Serial.write(128);
    delay(Duration);
    Serial.write(128);
    Serial.write(Note);
    Serial.write(128);
  }
  ledcWriteTone(0, Frequency);
  vTaskDelay(pdMS_TO_TICKS(Duration));
  ledcWriteTone(0, 0);
  return;
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
  Temporary_File = SD.open(Temporary_File_Path);
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

void Files_And_Folders()
{
  /*GalaxOS.Get_Variable('A', Temporary_File_Path);
  Temporary_File = SD.open(Temporary_File_Path);
  String Item_Name = "";
  if (Temporary_File)
  {
    if (Temporary_File.isDirectory())
    {
      for (int i = 1; i < 19; i++)
      { //Clear Items
        Item_Name = "ITEM" + String(i);
        Item_Name += "_TXT";
        Nextion_Serial.print(Item_Name);
        Nextion_Serial.print(F(".txt=\"\"\xFF\xFF\xFF"));
        Item_Name = "ITEM" + String(i);
        Item_Name += "_BUT";
        Nextion_Serial.print(Item_Name);
        Nextion_Serial.print(F(".pic=15\xFF\xFF\xFF"));
      }
      Temporary_File.rewindDirectory();
      for (byte i = 1; i < 19; i++)
      {
        File Item = Temporary_File.openNextFile();
        if (!Item)
          break;
        Item_Name = "ITEM" + String(i);
        Item_Name += "_TXT";
        Nextion_Serial.print(Item_Name);
        Nextion_Serial.print(F(".txt=\""));
        Nextion_Serial.print(Item.name());
        Nextion_Serial.print(F("\"\xFF\xFF\xFF"));
        Item_Name = "ITEM" + String(i);
        Item_Name += "_BUT";
        if (Item.isDirectory())
        {
          Nextion_Serial.print(Item_Name);
          Nextion_Serial.print(F(".pic=17\xFF\xFF\xFF"));
        }
        else
        {
          Nextion_Serial.print(Item_Name);
          Nextion_Serial.print(F(".pic=16\xFF\xFF\xFF"));
        }
        Item.close();
      }
    }
    else
    {
      Item_Name = Temporary_File.name();
      char Item_Name_Char[14];

      Item_Name.toCharArray(Item_Name_Char, 14);

      for (byte i = 1; i < 15; i++)
      {
        if (Item_Name_Char[i] == '.')
        {
          Item_Name = String(Item_Name_Char[i + 1]) + String(Item_Name_Char[i + 2]) + String(Item_Name_Char[i + 3]);
        }
      }
      Temporary_File.close();
      if (Item_Name == "WAV")
      {
      }
      else if (Item_Name == "BMP")
      {
        Pictviewer();
      }
      else if (Item_Name == "GPF")
      {
      }
      else if (Item_Name == "FPF")
      {
      }
      else if (Item_Name == "GMF")
      {
        //vTaskResume(GalaxOS.Musical_Digital_Player_Handle);
      }
      else
      {
        //Fileditor();
      }
    }
  }
  else
  {
  }*/
}

/*
void Function_Generator(int Frequency, int Pin, double Offset, double Width)
{
  unsigned long cycle_time;
  unsigned long raising_edge;
  unsigned long falling_edge;
  unsigned long prev_micros;

  pinMode(Pin, OUTPUT);

// calculate arguments
freq = 1;
width = 0.5;
offset = 0.0;

cycle_time = 1000000 / freq;
raising_edge = (unsigned long)(offset * cycle_time) % cycle_time;
falling_edge = (unsigned long)((offset + width) * cycle_time) % cycle_time;

prev_micros = micros();

// do pinout shifting
while(1) {
  if (width + offset < 1) {
    // raising edge should appear earlier
    while (TIME_CMP(micros(), prev_micros + raising_edge, cycle_time)); setHigh();
    while (TIME_CMP(micros(), prev_micros + falling_edge, cycle_time)); setLow();
  } else {
    // falling edge should appear earlier
    while (TIME_CMP(micros(), prev_micros + falling_edge, cycle_time)); setLow();
    while (TIME_CMP(micros(), prev_micros + raising_edge, cycle_time)); setHigh();
  }
  prev_micros += cycle_time;
}
}*/

