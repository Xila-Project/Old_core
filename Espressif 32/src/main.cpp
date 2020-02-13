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
//|| Version : - Alix ANNERAUD (c) 2019                                         ||

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

#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "WiFi.h"
#include "main.h"
#include "galaxos.h"

GalaxOS GalaxOS;

void setup() {
  GalaxOS.begin();
}

void loop() {
  vTaskDelete(NULL);
}

GalaxOS::GalaxOS() {
    Taskbar_Items_PID[7] = {255, 255, 255, 255, 255, 255, 255};
    Taskbar_Items_Icon[7] = {10, 10, 10, 10, 10, 10, 10};

    Current_Page = NULL;
    Last_Page = NULL;

    C_MIDI = 60;

    C_Frequency = 262;

    String Username = "\0";
    String Password = "\0";
}

void GalaxOS::Start() {
    Serial.begin(115200); //PC Debug UART
    Nextion_Serial.begin(921600, SERIAL_8N1, 16, 17); //Nextion UART   
    Serial.println(F("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"));
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
    USB_Serial_Transmit("Flash : 253.952 Bytes - EEPROM : 4.000 Bytes - RAM : 8.192 Bytes", STYLE_LEFT_ALIGNMENT);
    Serial.println(F("||      Flash : 253.952 Bytes - EEPROM : 4.000 Bytes - RAM : 8.192 Bytes      ||"));
    Serial.println(F("||               Galax OS Portable Edition - Alix ANNERAUD - 0.03             ||"));
    Serial.println(F("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"));
    Serial.println(F("|| > Starting Galax OS ...                                                    ||"));
    Serial.println(F("|| > Mount The SD Card ...                                                    ||"));
    //Audio.speakerPin = SpeakerPin;
    if (!SD.begin()) {
        Serial.println(F("|| > Warning : The SD Card isn't mounted.                                     ||"));
    }
    else {
        Serial.println(F("|| > The SD Card is mounted.                                                  ||"));
    }
    xTaskCreatePinnedToCore(GalaxOS::Nextion_Serial_Receive, "Nextion_Serial_Receive", 1028, NULL, 2, &Nextion_Serial_Transmit_Handle, 1);
    xTaksCreatePinnedToCore(GalaxOS.core, "GalaxOS Core", 4096, NULL, 2, &GalaxOS_Core_Handle, 1);
    xTaskCreatePinnedToCore(Musical_Digital_Player, "Musical_Digital_Player", 4096, NULL, 2, &Musical_Digital_Player_Handle, 1);
    vTaskSuspend(Musical_Digital_Player_Handle);
    xTaskCreatePinnedToCore(Ressource_Monitor, "Ressource_Monitor", 2048, NULL, 2, &Ressource_Monitor_Handle, 1);
    
    Serial.println(F("|| > Loading Task ...                                                         ||"));
    Serial.println(F("|| > Waiting for Display ...                                                  ||"));

    Nextion_Serial_Queue xQueueCreate(100, sizeof(char));
    if (Nextion_Serial_Queue == NULL) {
      //FATAL ERROR
    }
}

void GalaxOS::Set(char const& Tag, String const& String_To_Set) { //string
  Temporary_File = SD.open("/GALAXOS/MEMORY/STRING/" + Tag, FILE_WRITE);
  if (Temporary_File) {
    Temporary_File.print(String_To_Set);
    Temporary_File.close();
    return;
  }
  else {
    //error
    return;
  }
}

void GalaxOS::Get(char const& Tag, String& String_To_Get) { //string
  Temporary_File = SD.open("/GALAXOS/MEMORY/STRING/" + Tag, FILE_READ);
  if (Temporary_File)  {
    while (Temporary_File.available()) {
      String_To_Get += Temporary_File.read();
    }
    Temporary_File.close();
    return;
  }
  else {
    //error
    return;
  }
}


void GalaxOS::Set(char const& Tag, char const& Char_To_Set) { //char
  Temporary_File = SD.open("/GALAXOS/MEMORY/CHAR/" + Tag, FILE_WRITE);
  if (Temporary_File) {
    Temporary_File.write(Char_To_Set)
    Temporary_File.close();
    return;
  }
  else {
    //error
    return;
  }
}

void GalaxOS::Get(char const& Tag, char& Char_To_Get) { //char
  Temporary_File = SD.open("/GALAXOS/MEMORY/CHAR/" + Tag, FILE_READ);
  if (Temporary_File) {
    Char_To_Get = Temporary_File.read();
    Temporary_File.close();
    return;
  }
  else {
    //error
    return;
  }
} 

void GalaxOS::Set(char const& Tag, byte const& Byte_To_Set) { //byte
  Temporary_File = SD.open("/GALAXOS/MEMORY/BYTE/" + Tag, FILE_WRITE);
  if (Temporary_File) {
    Temporary_File.write(Data);
    Temporary_File.close();
    return;
  }
  else {
    //error
    return;
  }
}

void GalaxOS::Get(char const& Tag, byte const& Byte_To_Get) { //byte
  Temporary_File = SD.open("/GALAXOS/MEMORY/BYTE/" + Tag, FILE_READ);
  if (Temporary_File) {
    Byte_To_Get = Temporary_File.read();
    Temporary_File.close();
    return;
  }
  else {
    //error
    return;
  }
}

void GalaxOS::Set(char const& Tag, int const& Integer_To_Set) { //integer
  Temporary_File = SD.open("/GALAXOS/MEMORY/INTEGER/" + Tag, FILE_WRITE);
  if (Temporary_File) {
    byte Split_Integer[2] = {0, 0};
    Split_Integer[0] = (Integer_To_Set >> 8) & 0xFF;
    Temporary_File.write(Split_Integer[0]);
    Split_Integer[1] = Integer_To_Set & 0xFF;
    Temporary_File.write(Split_Integer[1]);
    Temporary_File.close();
    return;
  }
  else {
    //error
    return;
  }
}

void GalaxOS::Get(char const& Tag, int& Integer_To_Get) { //integer
  Temporary_File = SD.open("/GALAXOS/MEMORY/INTEGER/" + Tag, FILE_WRITE);
  if(Temporary_File) {
    Integer_To_Get |= Temporary_File.read() << 8;
    Integer_To_Get |= Temporary_File.read();
    Temporary_File.close();
    return;
  }
  else {
    //error
    return;
  }
}

void GalaxOS::Set(char const& Tag, float const& Float_To_Set) { //float
  Temporary_File = SD.open("/GALAXOS/MEMORY/FLOAT/" + Tag, FILE_WRITE);
  if (Temporary_File) {
    byte Split_Float[4] = {0, 0, 0, 0};
    Float_To_Set[0] = (Integer_To_Set >> 24) & 0xFF;
    Float_To_Set[1] = (Integer_To_Set >> 16) & 0xFF;
    Float_To_Set[2] = (Integer_To_Set >> 8) & 0xFF;
    Float_To_Set[3] = Integer_To_Set & 0xFF;
    Temporary_File.close();
    return;
  }
  else {
    //error
    return;
  }
}

void GalaxOS::Get(char const& Tag, int& Float_To_Get) { //float
  Temporary_File = SD.open("/GALAXOS/MEMORY/FLOAT/" + Tag, FILE_WRITE);
  if(Temporary_File) {
    Float_To_Get |= Temporary_File.read() << 24;
    Float_To_Get |= Temporary_File.read() << 16;
    Float_To_Get |= Temporary_File.read() << 8;
    Float_To_Get |= Temporary_File.read();
    Temporary_File.close();
    return;
  }
  else {
    //error
    return;
  }
}



void GalaxOS::Core( void *pvParameters ) {
    //to do : check notify
  (void) pvParameters;
  for(;;) {
    if (notification) {
      char First_Return_Code = 0;
      xQueueReceive(Nextion_Serial_Queue, &First_Byte, portMAX_DELAY);
      char Second_Return_Code = 0;
      xQueueReceive(Nextion_Serial_Queue, &Second_Return_Code, portMAX_DELAY);
      switch(First_Return_Code) {
        case ERROR_NEXTION_INVALID_INTRUCTION :
          Serial.println(F("Invalid Intruction !"));
          break;
        case ERROR_NEXTION_INVALID_COMPONENT_ID :
          Serial.println("Invalid Component ID !");
          break;
        case ERROR_NEXTION_INVALID_PAGE_ID :
          Serial.println("Invalid Page ID !");
          break;
        case ERROR_NEXTION_INVALID_PICTURE_ID :
          Serial.println("Invalid Picture ID !");
          break;
        case ERROR_NEXTION_INVALID_FONT_ID :
          Serial.println("Invalid Font ID !");
          break;
        case INFORMATION_NEXTION_CURRENT_PAGE_NUMBER :
          Last_Page = Current_Page;
          Current_Page = Second_Return_Code;
          break;
        case INFORMATION_NEXTION_STRING_DATA_ENCLOSED :
          switch (Second_Return_Code) {
            case CODE_COMMAND : //* - command
              String Command = "";
              char Temporary_Current_Char;
              char Temporary_Forward_Char;
              while(uxQueueMessagesWaiting(Nextion_Serial_Queue) != 0) {
                xQueueReceive(Nextion_Serial_Queue, &Temporary_Current_Char, portMAX_DELAY);
                xQueuePeek(Nexiton_Serial_Queue, &Temporary_Forward_Char, portMAX_DELAY);
                if(Temporary_Forward_Char == 255 && Temporary_Current_Char == 255) {
                  xQueueReceive(Nextion_Serial_Queue, NULL, portMAX_DELAY);
                  xQueueReceive(Nextion_Serial_Queue, NULL, portMAX_DELAY);
                  break;
                }
                Command += Temporary_Current_Char;
              }
              if (RX_Data_String == "LoadSystem") Load_System_Files();
              else if (RX_Data_String == "LoadUser") Load_User_Files();
              else if (RX_Data_String == "Logon") Logon();
              else if (RX_Data_String == "Menu") Open_Menu();
              else if (RX_Data_String == "Desk") Open_Desk();
              //event handler
              else if (RX_Data_String == "OK") Event_Handler_Replay
              //file&folder
              else if (RX_Data_String == "F&F") Files_And_Folders();
              else if (RX_Data_String == "F&F_RDelete") Event_Handler_Request();   
              //taskbar item
              else if (RX_Data_String == "TBItem1") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[0]);
              else if (RX_Data_String == "TBItem2") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[1]);
              else if (RX_Data_String == "TBItem3") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[2]);
              else if (RX_Data_String == "TBItem4") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[3]);
              else if (RX_Data_String == "TBItem5") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[4]);
              else if (RX_Data_String == "TBItem6") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[5]);
              else if (RX_Data_String == "TBItem7") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[6]);
              //piano
              else if (RX_Data_String == "CLow") Piano(0, 0);
              else if (RX_Data_String == "C#Low") Piano(16, 1);
              else if (RX_Data_String == "DLow") Piano(32, 2);
              else if (RX_Data_String == "D#Low") Piano(50, 3);
              else if (RX_Data_String == "ELow") Piano(68, 4);
              else if (RX_Data_String == "FLow") Piano(88, 5);
              else if (RX_Data_String == "F#Low") Piano(108, 6);
              else if (RX_Data_String == "GLow") Piano(130, 7);
              else if (RX_Data_String == "G#Low") Piano(154, 8);
              else if (RX_Data_String == "ALow") Piano(178, 9);
              else if (RX_Data_String == "A#Low") Piano(205, 10);
              else if (RX_Data_String == "BLow") Piano(232, 11);
              else if (RX_Data_String == "CHigh") Piano(262, 12);
              else if (RX_Data_String == "C#High") Piano(293, 13);
              else if (RX_Data_String == "DHigh") Piano(326, 14);
              else if (RX_Data_String == "D#High") Piano(361, 15);
              else if (RX_Data_String == "EHigh") Piano(398, 16);
              else if (RX_Data_String == "FHigh") Piano(437, 17);
              else if (RX_Data_String == "F#High") Piano(478, 18);
              else if (RX_Data_String == "GHigh") Piano(522, 19);
              else if (RX_Data_String == "G#High") Piano(569, 20);
              else if (RX_Data_String == "AHigh") Piano(618, 21);
              else if (RX_Data_String == "A#High") Piano(670, 22);
              else if (RX_Data_String == "BHigh") Piano(726, 23);
              else {
                Serial.println(F("Unknow Command"));
              }
              break;
            case CODE_COMMAND_NEW : //#
              String Command = "";
              char Temporary_Current_Char;
              char Temporary_Forward_Char;
              while(uxQueueMessagesWaiting(Nextion_Serial_Queue) != 0) {
                xQueueReceive(Nextion_Serial_Queue, &Temporary_Current_Char, portMAX_DELAY);
                xQueuePeek(Nexiton_Serial_Queue, &Temporary_Forward_Char, portMAX_DELAY);
                if(Temporary_Forward_Char == 255 && Temporary_Current_Char == 255) {
                  xQueueReceive(Nextion_Serial_Queue, NULL, portMAX_DELAY);
                  xQueueReceive(Nextion_Serial_Queue, NULL, portMAX_DELAY);
                  break;
                }
                Command += Temporary_Current_Char;
              }
              if (RX_Data_String == "LoadSystem") Load_System_Files();
              else if (RX_Data_String == "LoadUser") Load_User_Files();
              else if (RX_Data_String == "Logon") Logon();
              else if (RX_Data_String == "Menu") Open_Menu();
              else if (RX_Data_String == "Desk") Open_Desk();
              //event handler
              else if (RX_Data_String == "OK") Event_Handler_Replay
              //file&folder
              else if (RX_Data_String == "F&F") Files_And_Folders();
              else if (RX_Data_String == "F&F_RDelete") Event_Handler_Request();   
              //taskbar item
              else if (RX_Data_String == "TBItem1") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[0]);
              else if (RX_Data_String == "TBItem2") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[1]);
              else if (RX_Data_String == "TBItem3") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[2]);
              else if (RX_Data_String == "TBItem4") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[3]);
              else if (RX_Data_String == "TBItem5") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[4]);
              else if (RX_Data_String == "TBItem6") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[5]);
              else if (RX_Data_String == "TBItem7") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[6]);
              //piano
              else if (RX_Data_String == "CLow") Piano(0, 0);
              else if (RX_Data_String == "C#Low") Piano(16, 1);
              else if (RX_Data_String == "DLow") Piano(32, 2);
              else if (RX_Data_String == "D#Low") Piano(50, 3);
              else if (RX_Data_String == "ELow") Piano(68, 4);
              else if (RX_Data_String == "FLow") Piano(88, 5);
              else if (RX_Data_String == "F#Low") Piano(108, 6);
              else if (RX_Data_String == "GLow") Piano(130, 7);
              else if (RX_Data_String == "G#Low") Piano(154, 8);
              else if (RX_Data_String == "ALow") Piano(178, 9);
              else if (RX_Data_String == "A#Low") Piano(205, 10);
              else if (RX_Data_String == "BLow") Piano(232, 11);
              else if (RX_Data_String == "CHigh") Piano(262, 12);
              else if (RX_Data_String == "C#High") Piano(293, 13);
              else if (RX_Data_String == "DHigh") Piano(326, 14);
              else if (RX_Data_String == "D#High") Piano(361, 15);
              else if (RX_Data_String == "EHigh") Piano(398, 16);
              else if (RX_Data_String == "FHigh") Piano(437, 17);
              else if (RX_Data_String == "F#High") Piano(478, 18);
              else if (RX_Data_String == "GHigh") Piano(522, 19);
              else if (RX_Data_String == "G#High") Piano(569, 20);
              else if (RX_Data_String == "AHigh") Piano(618, 21);
              else if (RX_Data_String == "A#High") Piano(670, 22);
              else if (RX_Data_String == "BHigh") Piano(726, 23);
              else {
                Serial.println(F("Unknow Command"));
              }
              break;
            case CODE_VARIABLE_STRING : //S - string
              String Received_String = "";
              char Tag;
              char Temporary_Current_Char;
              char Temporary_Forward_Char;
              xQueueReceive(Nextion_Serial_Queue, & )
              while(uxQueueMessagesWaiting(Nextion_Serial_Queue) != 0) {
                xQueueReceive(Nextion_Serial_Queue, &Temporary_Current_Char, portMAX_DELAY);
                xQueuePeek(Nexiton_Serial_Queue, &Temporary_Forward_Char, portMAX_DELAY);
                if(Temporary_Forward_Char == 255 && Temporary_Current_Char == 255) {
                  xQueueReceive(Nextion_Serial_Queue, NULL, portMAX_DELAY);
                  xQueueReceive(Nextion_Serial_Queue, NULL, portMAX_DELAY);
                  break;
                }
                Received_String += Temporary_Current_Char;
              }
              break;
            case CODE_VARIABLE_CHAR : //C - string
              break;
            
          }
          break;
        case INFORMATION_NEXTION_NUMERIC_DATA_ENCLOSED :

          break;
        case 0xFF :
          xQueueReceive(Nextion_Serial_Queue, NULL, portMAX_DELAY);
          break;
        default:
          Serial.print("Unknow error code :");
          Serial.println(First_Return_Code);
          break;
      }
      

    }
  }
}

void GalaxOS::Open_Menu() {
  Nextion_Serial_Transmit(F("Menu_P1"), COMMAND_PAGE_NAME, F(""), 0);
  Nextion_Serial_Transmit(F("USERNAME_TXT"), ATTRIBUTE_TXT, String(Username), 0);
}

void GalaxOS::Open_Desk() {
  Nextion_Serial_Transmit(F("Desk"), COMMAND_PAGE_NAME, "", 0);
  vTaskDelay(100);
  Nextion_Serial_Transmit(F("ITEM1_PIC"), ATTRIBUTE_PIC, "", Taskbar_Items_Icon[0]);
  Nextion_Serial_Transmit(F("ITEM2_PIC"), ATTRIBUTE_PIC, "", Taskbar_Items_Icon[1]);
  Nextion_Serial_Transmit(F("ITEM3_PIC"), ATTRIBUTE_PIC, "", Taskbar_Items_Icon[2]);
  Nextion_Serial_Transmit(F("ITEM4_PIC"), ATTRIBUTE_PIC, "", Taskbar_Items_Icon[3]);
  Nextion_Serial_Transmit(F("ITEM5_PIC"), ATTRIBUTE_PIC, "", Taskbar_Items_Icon[4]);
  Nextion_Serial_Transmit(F("ITEM6_PIC"), ATTRIBUTE_PIC, "", Taskbar_Items_Icon[5]);
  Nextion_Serial_Transmit(F("ITEM7_PIC"), ATTRIBUTE_PIC, "", Taskbar_Items_Icon[6]);
  return;
}



void GalaxOS::Ressource_Monitor ( void *pvParameters ) {
  (void) pvParameters;
  for (;;) {
    vTaskDelay(100);
  }
}

void GalaxOS::Logon() {
  Temporary_File = SD.open("/USERS/" + Public_String_Variable[1] + "/STTNGS/PASSWORD.GSF");
  Password = "";
  if (Temporary_File) {
    while (Temporary_File.available()) {
      if (isAlphaNumeric(Temporary_File.peek())) {
        Password += char(Temporary_File.read());
      }
      else {
        Temporary_File.read();
      }
    }
    Temporary_File.close();
    Temporary_File_Path = "NULL";
  }
  else {
    Nextion_Serial_Transmit(F("WRONG_TXT"), ATTRIBUTE_TXT, F("Wrong Username !"), 0);
    Serial.println(F("Wrong Username !"));
    return;
  }
  Serial.println(Password);
  if (Password == Public_String_Variable[2]) {
    Serial.println(F("Good Password"));
    Username = Public_String_Variable[1];
    Password = Public_String_Variable[2];
    Load_User_Files();
    return;
  }
  else {
    Nextion_Serial_Transmit(F("WRONG_TXT"), ATTRIBUTE_TXT, F("Wrong Password !"), 0);
    Serial.println(F("Wrong Password !"));
    Password = "";
    return;
  }
  return;
}

void GalaxOS::Load_System_Files() {
  Serial.println(F("Load System Files ..."));
  Temporary_File = SD.open("/GALAXOS.GSF");
  String Temporary_String = "";
  if (Temporary_File) {
    while (Temporary_File.available() && Temporary_File.peek() != 10 && Temporary_File.peek() != 13) {
      Temporary_String += Temporary_File.read();
    }
    Serial.print(Temporary_String);
    if (Temporary_String != "Galax OS Embeded Edition For Arduino Mega 2560 Version Alpha 0.12") {
      Serial.println(F("Error : ERROR_SOME_SYSTEM_FILES_ARE_CORRUPTED"));
      return;
    }
  }
  else {
    Serial.println(F("Error : ERROR_SOME_SYSTEM_FILES_ARE_MISSING"));
    return;
  }
  Temporary_String = "";
  return;

  Nextion_Serial_Transmit(F("LOAD_TXT"), ATTRIBUTE_TXT, F("Loading System Files ..."), 0);
  Nextion_Serial_Transmit(F("LOAD_TIM"), ATTRIBUTE_TIM, F(""), 50);
}

void GalaxOS::Load_User_Files() {
  Serial.print(F("Load User Files ..."));
  Nextion_Serial_Transmit("Load_User", COMMAND_PAGE_NAME, "", 0);
  Temporary_File = SD.open("/USERS/" + Username + "/STTNGS/TASKBAR.GSF", FILE_READ);
  byte i = 0;
  while (Temporary_File.available()) {
    Taskbar_Items_PID[i] = Temporary_File.read();
    Temporary_File.read();
    //if(Temporary_File.read() != 124) Serial.print(ERROR_SOME_USER_SETTINGS_FILES_ARE_CORRUPTED);
    Taskbar_Items_Icon[i] = Temporary_File.read();
    Temporary_File.read();
    Temporary_File.read();
    i++;
  }
  Temporary_File.close();
  Temporary_File_Path = "/GALAXOS/SOUNDS/STARTUP.GMF";
  vTaskResume(Musical_Digital_Player_Handle);
  Nextion_Serial_Transmit(F("LOAD_TIM"), ATTRIBUTE_TIM, "", 50);
}

void GalaxOS::Nextion_Serial_Transmit(String Component, byte Type, String Nextion_Serial_Transmit_String, int Nextion_Serial_Transmit_Integer) {
  switch (Type) {
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
    case ATTRIBUTE_EN : //Timer enable
      Nextion_Serial.print(Component);
      Nextion_Serial.print(F(".en="));
      Nextion_Serial.print(Nextion_Serial_Transmit_Integer);
      break;
    case COMMAND_PAGE_ID : //page PID//
      byte PID;
      PID = Nextion_Serial_Transmit_Integer;
      Nextion_Serial.print(F("page "));
      Nextion_Serial.print(PID);
      break;
    case COMMAND_CLICK_ID : //click
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

void GalaxOS::Event_Handler_Request(int Type, String Infromations) {
  switch (Type) {
    Nextion_Serial_Transmit(F("Event"), COMMAND_PAGE_NAME, "", 0);
    case ERROR_FAILLED_TO_INTIALIZE_SD_CARD :
      Nextion_Serial.print(F("TITLE_TXT.txt=")); Nextion_Serial.print(F("A"))
      Nextion_Serial_Transmit(F("TITLE_TXT"), ATTRIBUTE_TXT, F("Error !"), 0);
      Nextion_Serial_Transmit(F("MESSAGE_TXT"), ATTRIBUTE_TXT, F("Failled to initialize the SD Card !"), 0);
      break;
    case ERROR_SOME_SYSTEM_FILES_ARE_MISSING :
      Nextion_Serial_Transmit(F("TITLE_TXT"), ATTRIBUTE_TXT, F("Error !"), 0);
      Nextion_Serial_Transmit(F("MESSAGE_TXT"), ATTRIBUTE_TXT, F("Some system files are missing !"), 0);
      break;
    case ERROR_SOME_USER_SETTINGS_FILES_ARE_MISSING :
      Nextion_Serial_Transmit(F("TITLE_TXT"), ATTRIBUTE_TXT, F("Error !"), 0);
      Nextion_Serial_Transmit(F("MESSAGE_TXT"), ATTRIBUTE_TXT, F("Some settings files are missing !"), 0);
      break;
    case ERROR_SOME_USER_SETTINGS_FILES_ARE_CORRUPTED :
      Nextion_Serial_Transmit(F("TITLE_TXT"), ATTRIBUTE_TXT, F("Error !"), 0);
      Nextion_Serial_Transmit(F("MESSAGE_TXT"), ATTRIBUTE_TXT, F("Some user settings files are corrupted !"), 0);
      break;
    case ERROR_THE_FILE_DO_NOT_EXIST :
      Nextion_Serial_Transmit(F("TITLE_TXT"), ATTRIBUTE_TXT, F("Error !"), 0);
      Nextion_Serial_Transmit(F("MESSAGE_TXT"), ATTRIBUTE_TXT, F("The file doesn't exist !"), 0);
      break;
    case WARNING_WRONG_PASSWORD :
      break;
    case WARNING_WRONG_USERNAME :
      Nextion_Serial_Transmit(F("WRONG_TXT"), ATTRIBUTE_TXT, F("Wrong Username !"), 0);
      Serial.println(F("Wrong Username !"));
      break;
    case WARNING_DO_YO_REALLY_WANT_TO_DELETE_THIS_ITEM :
      Nextion_Serial_Transmit(F(""))
      break;
    default:
      break;
  }
}


void GalaxOS::Event_Handler_Reply(byte Reply) {
  switch (Reply) {
    case 0 :
      break;
    default:
      break;
  }
  
}

void GalaxOS::USB_Serial_Transmit(char const* USB_Serial_Transmit_String, byte const* Alignment) {
  unsigned int USB_Serial_Transmit_String_Lenght = strlen(USB_Serial_Transmit_String);
  byte Lines = USB_Serial_Transmit_String_Lenght;
  Lines = Lines / 72;
  if(USB_Serial_Transmit_String_Lenght % 72 != 0) Lines++;
  if(Lines == 1) {
    switch (Alignment) {
      case STYLE_LEFT_ALIGNMENT :
        Serial.print(F("|| > "));
        for(byte i = 1; i <= USB_Serial_Transmit_String_Lenght; i++) {   
          Serial.print(USB_Serial_Transmit_String[i]);
        }
        for(byte i = 1; i <= 72 - USB_Serial_Transmit_String_Lenght; i++) {   
          Serial.print(" ");
        }
        Serial.print(F(" ||"));
        Serial.print(F("\r"));
        Serial.print(F("\n"));
        break;     
      case STYLE_CENTER_ALIGNMENT :
        //not coded now
        break;
      case STYLE_RIGHT_ALIGNMENT :
        //not coded now
        break;
      case STYLE_JUSTIFIED_ALIGNMENT :
        //not coded now
        break;
      default:
        break;
      
    }
  }
  else {
    //not coded now
  }
}

void GalaxOS::Musical_Digital_Player( void *pvParameters ) {
  Serial.print(F("Musical Digital Player ..."));
  ledcAttachPin(Speaker_Pin, 0);
  int Frequency;
  int Duration;
  Temporary_File = SD.open(Temporary_File_Path);
  if (!Temporary_File) {
    return;
  }
  while (Temporary_File.available()) {
    Frequency = Temporary_File.read();
    Frequency *= 256;
    Frequency += Temporary_File.read();
    Frequency += C_Frequency;
    Duration = Temporary_File.read();
    Duration *= 256;
    Duration += Temporary_File.read();
    ledcWriteTone(0, Frequency);
    vTaskDelay(pdMS_TO_TICKS(Duration));
  }
  ledcWriteTone(0, 0);
  vTaskSuspend(Musical_Digital_Player_Handle);
}

void GalaxOS::Nextion_Serial_Receive( void *pvParameters ) { //to do : rewrite the whole function and dispatch between gos core and this (using xTaskNotify)
  (void) pvParameters;
  for (;;)
  {
    if (Nextion_Serial.available()) {
      
      while (Nextion_Serial.available()) {
        if(uxQueueSpacesAvailable(Nextion_Serial_Queue) != 0) {
          Nextion_Serial_Receive_Char = char(Nextion_Serial.read());
          xQueueSend(Nextion_Serial_Queue, &Nextion_Serial_Receive_Char, portMAX_DELAY);
        }
        else {
          //error : full queue
          Serial.println(f("The queue is full !"));
          vTaskDekay(1000);
        }
      }
      
      Serial.println(F("|| > Incoming Data On UART 1                                                  ||"));

      String RX_Data_String = "";

      char RX_Data_Char[80];

      byte Selected_Variable = 0;
      byte Type = 0;
      byte i = 1;

  

      if (RX_Data_Char[1] == 0x66) {
        Last_Page = Current_Page;
        Current_Page = RX_Data_Char[2];
        return;
      }

      switch (RX_Data_Char[2]) {
        case 0x2A : Type = 1; break;
        default :
          if (isUpperCase(RX_Data_Char[2])) {
            Selected_Variable = RX_Data_Char[2];
            Selected_Variable -= 65;
            Type = 0;
            return;
          }
          else if (isLowerCase(RX_Data_Char[2])) {
            Selected_Variable = RX_Data_Char[2];
            Selected_Variable -= 96;
            Type = 3;
            break;
          }
          else {
            Type = 0;
            break;
          }
      }
      i = 3;
      Serial.print(F("RX_Data_Char[1] :"));
      Serial.println(RX_Data_Char[1], DEC);
      Serial.print(F("RX_Data_Char[2] :"));
      Serial.println(RX_Data_Char[2], DEC);
      while (RX_Data_Char[i] != 255 && i < 80) {
        RX_Data_String += RX_Data_Char[i];
        i++;
      }
      RX_Data_String.toCharArray(RX_Data_Char, RX_Data_String.length() + 1);

      Serial.print(F("RX Data Char :"));
      Serial.println(RX_Data_Char);
      Serial.print(F("RX Data String :"));
      Serial.println(RX_Data_String);

      Serial.println(F("|| > Execute Incoming Data On UART 1 - Step 4                                 ||"));
      switch (Type) {
        case 0:
          break;
        case 1:
          //1 -> Command
          Serial.println(F("Command"));
          //System Feature
          
          break;
        case 2:
          //2 -> Integer Variable
          Serial.print(F("Selected Variable :"));
          Serial.println(Selected_Variable);
          Serial.println(F("Integer (Byte)"));
          Public_Integer_Variable[Selected_Variable] = RX_Data_Char[3];
          break;
        case 3:
          //3 -> String Variable
          Serial.print(F("Selected Variable :"));
          Serial.println(Selected_Variable);
          Serial.println(F("String"));
          Public_String_Variable[Selected_Variable] = RX_Data_String;
          break;
        default:
          Serial.println(F("|| > Unrecognized Type Of Command                                            ||"));
          break;
      }
    }
    vTaskDelay(100);
  }
}

void GalaxOS::WiFi_Connect() {
  WiFi.begin(WiFi_SSID, WiFi_Password);
  byte i = 0;
  while (WiFi.status() != WL_CONNECTED && i < 10) {
    vTaskDelay(pdMS_TO_TICKS(500));
    i++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(F("Connected to WiFi"));
  }
  else {
    Serial.println(F("Can't Connect to WiFi"));
  }
}

void UltraSonic(int USTrig, int USEcho) {
  Serial.println(F("|| > Open UltraSonic Rangefinder App                                         ||"));
  Serial.println(USTrig);
  Serial.println(USEcho);
  pinMode(USTrig, OUTPUT);
  pinMode(USEcho, INPUT);
  digitalWrite(USTrig, LOW);
  while (Nextion_Serial.available() == 0)  {
    digitalWrite(USTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(USTrig, LOW);
    unsigned long Duration = pulseIn(USEcho, HIGH);
    if (Duration > 30000) {
      Serial.println(F("|| > Onde perdue                                         ||"));
    }
    else {
      Duration /= 2;
      float Time = Duration / 1000000;
      int Distance = Time*SOUND_SPEED_AIR;
      Serial.print(F("|| > Distance :"));
      Serial.println(Distance);
      Nextion_Serial_Transmit(F("DISTVAL_NUM"), ATTRIBUTE_VAL, "", Distance);
      vTaskDelay(100);
    }
  }
  Serial.println(F("|| > Close UltraSonic Rangefinder App                                        ||"));
  return;
}

void Piano(int Frequency, int Note) {
  ledcAttachPin(Speaker_Pin, 0);
  String Temporary = "";
  unsigned long Duration = 200;
  Frequency += C_Frequency;
  Note += C_MIDI;
  Temporary = "Frequency : " + String(Frequency, DEC);
  Nextion_Serial_Transmit(F("FREQUENCY_TXT"), 1, Temporary, 0);
  Temporary = "MIDI Code : " + String(Note, DEC);
  Nextion_Serial_Transmit(F("MIDICODE_TXT"), 1, Temporary, 0);
  if (MIDIOutEnable == true) {
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

void Pictviewer() {
  Nextion_Serial_Transmit("Pictviewer", COMMAND_PAGE_NAME, "", 0);
  Nextion_Serial_Transmit("FILENAME_TXT", ATTRIBUTE_TXT, Temporary_File_Name, 0);
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
  if (Temporary_File) {
    //Read the header
    Temporary_File.seek(0);
    if (Temporary_File.read() == 66 && Temporary_File.read() == 77) {
      Serial.println(F("It's a Bitmap File"));
      Temporary_File.seek(2);
      Size = int(Temporary_File.read()); //in bytes
      Serial.print(F("Size :"));
      Serial.println(Size);
      Nextion_Serial_Transmit("SIZE_NUM.val", ATTRIBUTE_VAL, "", Size);
      Temporary_File.seek(10);
      Data_offset = long(Temporary_File.read());
      Serial.print(F("Data Offset :"));
      Serial.println(Data_offset);
      Temporary_File.seek(18);
      Width = int(Temporary_File.read());
      Serial.print(F("Width :"));
      Serial.println(Width);
      Nextion_Serial_Transmit("WIDTH_NUM", ATTRIBUTE_VAL, "", Width);
      Temporary_File.seek(22);
      Height = long(Temporary_File.read());
      Nextion_Serial_Transmit("HEIGHT_NUM", ATTRIBUTE_VAL, "", Height);
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
      if (Encoding == 16) {
        //Draw picture
        Serial.println(F("16 bit encoding"));
        for (int y = Height; y > 24; y--) {
          for (int x = 10; x < Width; x++) {
            Serial.println(Temporary_File.peek());
            Blue = Temporary_File.read();
            Serial.println(Temporary_File.peek());
            Green = Temporary_File.read();
            Color = Red;
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
      else if (Encoding == 24) {
        Serial.println(F("24 bit encoding"));
        for (int y = Height; y > 24; y--) {
          for (int x = 10; x < Width; x++) {
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

      else {
        Serial.println(F("The 32 bit encoding isn't be supported now"));
      }

    }
    else {
      Serial.println(F("It isn't a bitmap file"));
    }
  }
  else {
    Serial.println(F("The File Doesn't Exist or isn't readable"));
  }
}

void Files_And_Folders() {
  Temporary_File_Path = Public_String_Variable[1];
  Temporary_File = SD.open(Temporary_File_Path);
  String Item_Name = "";
  if (SD.exists(Temporary_File_Path)) {
    if (Temporary_File.isDirectory()) {
      for (int i = 1; i < 19; i++) { //Clear Items
        Item_Name = "ITEM" + String(i);
        Item_Name += "_TXT";
        Nextion_Serial_Transmit(Item_Name, ATTRIBUTE_TXT, "", 0);
        Item_Name = "ITEM" + String(i);
        Item_Name += "_BUT";
        Nextion_Serial_Transmit(Item_Name, ATTRIBUTE_PIC, "", 15);
      }
      Temporary_File.rewindDirectory();
      for (byte i = 1; i < 19; i++) {
        File Item = Temporary_File.openNextFile();
        if (!Item) break;
        Item_Name = "ITEM" + String(i);
        Item_Name += "_TXT";
        Nextion_Serial_Transmit(Item_Name, ATTRIBUTE_TXT, Item.name(), 0);
        Item_Name = "ITEM" + String(i);
        Item_Name += "_BUT";
        if (Item.isDirectory()) {
          Nextion_Serial_Transmit(Item_Name, ATTRIBUTE_PIC, F(""), 17);
        }
        else {
          Nextion_Serial_Transmit(Item_Name, ATTRIBUTE_PIC, F(""), 16);
        }
        Item.close();
      }
    }
    else {
    Item_Name = Temporary_File.name();
    char Item_Name_Char[14];

    Item_Name.toCharArray(Item_Name_Char, 14);

    for (byte i = 1; i < 15; i++) {
      if (Item_Name_Char[i] == '.') {
        Item_Name = String(Item_Name_Char[i + 1]) + String(Item_Name_Char[i + 2]) + String(Item_Name_Char[i + 3]);
      }
    }
    Temporary_File.close();
    if (Item_Name == "WAV") {}
    else if (Item_Name == "BMP") {
      Pictviewer();
    }
    else if (Item_Name == "GPF") {}
    else if (Item_Name == "FPF") {}
    else if (Item_Name == "GMF") vTaskResume(Musical_Digital_Player_Handle);
    else {
      //Fileditor();
    }
  }
  }
  else {
    
  }
}

/*
void Function_Generator(int Frequency, int Pin, double Offset, double Width) {
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

void Periodic_Main (byte Type) {

  float Column;
  float Line;

  Column = Public_Integer_Variable[0];
  Column -= 6;
  Column /= 26;
  Column = round(Column);
  Serial.print(F("Column : "));
  Serial.println(Column);
  Line = Public_Integer_Variable[1];
  Line -= 29;
  Line /= 26;
  Line = round(Line);
  Serial.print(F("Line : "));
  Serial.println(Line);
}






/*
void iGOS (byte Type) {
  switch (Type) {
    case 0:

 case 1:
 //================================================
 // Page up - then re-display
 //================================================
   Serial.print (F("\n>> Command 1: "));
   if (textContent.pagePtr > 0) {
     textContent.pagePtr--;
     Type = 6;
     pageLinks.lastLink = 0;
     Serial.print (F("Page up to page "));
     Serial.println (textContent.pagePtr);
     pageLinks.linkPtr = 0;
   }
   else { // Can't got up any further
     Type = 10;
     Serial.println(F("Cancelled"));
   }
   break;
 case 2:
    //================================================
    // Page down - then re-display
    //================================================
   Serial.print (F("\n>> Command 2: "));
   if (textContent.pagePtr < textContent.lastPage) {
     textContent.pagePtr++;
   }
   else {
          textContent.pagePtr = 0;  // Reset to top
   }
   Type = 6;
   pageLinks.linkPtr = 0;
   pageLinks.lastLink = 0;
   Serial.print (F("Page down to page "));
   Serial.println (textContent.pagePtr);
   break;


 case 3:
    //================================================
    // Next link - then re-display to update link highlight
    //================================================
   Serial.print (F("\n>> Command 3: Next link: "));
   if (pageLinks.linkPtr < pageLinks.lastLink) {
     pageLinks.linkPtr++;
     Type = 6;
     Serial.print (F("Increased link to "));
     Serial.println (pageLinks.linkPtr);
   }
   else
   {
     pageLinks.linkPtr = 0;
     Type = 6;
     Serial.print (F("Reset link to "));
     Serial.println (pageLinks.linkPtr);
   }
   break;
   //================================================
   // Prev link - then re-display to update link highlight
   //================================================
 case 4:
   Serial.print (F("\n>> Command 4: Previous link: "));
   if (pageLinks.linkPtr > 0) {
     pageLinks.linkPtr--;
     Type = 6;
     Serial.print (F("Decreased link to "));
     Serial.println (pageLinks.linkPtr);
   }
   else  {
     pageLinks.linkPtr = pageLinks.lastLink;
     Type = 6;
     Serial.print (F("Reset link to "));
     Serial.println (pageLinks.linkPtr);
   }
   break;
 case 5:
   //================================================
   // Download, parse and cache url
   //================================================
   Serial.println (F("\n>> Command 5: Load & cache URL"));
   Temporary_File.sync();
   Temporary_File.close ();                  // Close read only cache file
   splitURL (url);
   if (cacheURL (server, path)) {  // Download and cache URL
     pageLinks.lastLink = 0;
     pageLinks.linkPtr = 0;
     Type = 6;
   }
   else {
     Temporary_File.close ();
     client.stop();
     tftLCD.println(F("\nDownload & caching failed"));
     memcpy (server, "*\0", 2);
     memcpy (path, '\0', 1);
     memcpy (url, '\0', 1);
     pageLinks.lastLink = 0;
     openCacheFile (true);
     Type = 6;
     Serial.println("Download & caching failed");
     break;
   }
   if (!openCacheFile(true)) {             // Re-open read only cache file
     tftLCD.println (F("Cache open failed"));
     memcpy (server, "*\0", 2);
   }
   else {
     pageLinks.lastLink = 0;
     Type = 6;
   }
   break;

   //================================================
   // Display current page from cached file
   //================================================
 case 6:

   Serial.print (F("\n>> Command 6: Display cached page: "));
   Serial.println (textContent.pagePtr);
   if (!displayPage()) {
     tftLCD.println(F("\nDisplay cache failed"));
     Serial.println(F("\nDisplay cache failed"));
   }
   Type = 10;
   Temporary_File.sync();
   break;

   //================================================
   // Print cache file to serial - debug only
   //================================================
 case 7:
   Serial.print (F("\n>> Command 7: Print raw cached page: "));
   Type = 10;
   break;
 case 11:
   tftLCD.println (F("Press button to reset"));
   resetFunc();
 default:
   break;
 }
}
*/
