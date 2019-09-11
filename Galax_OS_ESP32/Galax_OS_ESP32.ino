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
//|| Version : - Alix ANNERAUD (c) 2019                                         ||
//||Versions :
//||0.001 : Make The Loading, Logon, Desk and Menu (Main + Shutdown)
//||0.002 : Make Setup + About//
//||0.003 : Make The Link Between Arduino And Nextion//
//||0.004 : Make Ultrasonic Range Finder//
//||0.005 : Create Analog Read + Analog Write//
//||0.006 : Setup Panel Improve + Clock Improve + Communication Improve//
//||0.007 : Integrate SD Card + Make F&F//
//||0.008 : Piano + Panel_SetPassword//
//||0.009 : Make Fileditor//
//||0.010 : Digital Write + Digital Read//
//||0.011 : Login + Redesign some windows + Change Edition Name From  "Portable Edition" to "Embeded Edition" + Add Music Player//
//||0.012 : Add Function Generator and Save Form + Midi Feature on piano + NextionSerial Function + concat ReadInstructionFunction and Serialread to serialEvent1 + Personalisation of Taskbar + Add tiles to piano + Modified How Galax OS Load + Personalisation of Taskbar//
//||0.013 : Add Pictureader//

//Nextion Wiring//
//Blue -> 19    //
//Yellow -> 18  //
//Black -> GND  //
//Red -> 5v     //

//   SD Card    //
//MISO -> 50    //
//MOSI -> 51    //
//SCK -> 52     //
//CS -> 53      //
//3.3 v -> 3.3 v//
//GND -> GND    //

//    Clock     //
//SCL -> 20     //
//SDA -> 21     //
//VCC -> 5V     //
//GND -> GND    //


//Password Settings Path : /USERS/%USERNAME%/STTNGS/PASSWORD.GSF//
//Keyboard Settings Path : /USERS/%USERNAME%/STTNGS/KEYBOARD.GSF//

#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "WiFi.h"

#define ATTRIBUTE_TXT 0
#define ATTRIBUTE_VAL 1
#define ATTRIBUTE_TIM 2
#define ATTRIBUTE_PIC 4
#define ATTRIBUTE_EN 5

#define COMMAND_PAGE_NAME 3
#define COMMAND_PAGE_ID 6
#define COMMAND_CLICK_ID 7

HardwareSerial Nextion_Serial(2);

byte Taskbar_Items_PID[7] = {255, 255, 255, 255, 255, 255, 255};
byte Taskbar_Items_Icon[7] = {10, 10, 10, 10, 10, 10, 10};

int Public_Integer_Variable[12];

unsigned int CFrequency = 262;

int Speaker_Pin = 12;

char* Wifi_SSID     = "Avrupa";
char* WiFi_Password = "0235745484";

String Username = "NULL";
String Password = "NULL";

String Public_String_Variable[3] = {"", "", ""};

String Temporary_Path = "NULL";

File Temporary_File;

//--------------------------------------------------------------------------------//
//                                        Define Tasks                            //
//--------------------------------------------------------------------------------//
void Nextion_Serial_Receive ( void *pvParameters );

void setup() {
  //Serial Initialisation//
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

  xTaskCreatePinnedToCore(Nextion_Serial_Receive, "Nextion_Serial_Receive", 4096, 2, NULL, 1);
  xTaskCreatePinnedToCore(Musical_Digital_Player, "Musical_Digital_Player", 1024, 2, NULL, 1);


  Serial.println(F("|| > Loading Task ...                                                         ||"));

  Serial.println(F("|| > Waiting for Display ...                                                  ||"));



}

void loop() {
  vTaskDelete(NULL);
}


void Nextion_Serial_Receive(void *pvParameters) {
  (void) pvParameters;
  for (;;)
  {
    if (Nextion_Serial.available()) {

      Serial.println(F("|| > Incoming Data On UART 1                                                  ||"));

      String RX_Data_String = "";

      char RX_Data_Char[50];

      byte Selected_Variable = 0;
      byte Type = 0;
      byte i = 1;

      while (Nextion_Serial.available()) {
        RX_Data_Char[i] = char(Nextion_Serial.read());
        i++;
      }

      switch (RX_Data_Char[2]) {
        case 0x2A : Type = 1; break;
        case 0x2F : Type = 6; break;
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
      Serial.print("RX_Data_Char[1] :");
      Serial.println(RX_Data_Char[1], DEC);
      Serial.print("RX_Data_Char[2] :");
      Serial.println(RX_Data_Char[2], DEC);
      while (RX_Data_Char[i] != 255 && i < 47) {
        RX_Data_String += RX_Data_Char[i];
        i++;
      }
      RX_Data_String.toCharArray(RX_Data_Char, RX_Data_String.length() + 1);

      Serial.print("RX Data Char :");
      Serial.println(RX_Data_Char);
      Serial.print("RX Data String :");
      Serial.println(RX_Data_String);

      Serial.println(F("|| > Execute Incoming Data On UART 1 - Step 4                                 ||"));
      switch (Type) {
        case 0:
          break;
        case 1:
          //1 -> Command
          Serial.println(F("Command"));
          //System Feature
          if (RX_Data_String == "LoadSystem") Load_System_Files();
          else if (RX_Data_String == "LoadUser") Load_User_Files();
          else if (RX_Data_String == "Logon") Logon();
          else if (RX_Data_String == "Menu") Open_Menu();
          else if (RX_Data_String == "Desk") Open_Desk();

          else if (NextStrnInst == "TBItem1") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[0]);
          else if (NextStrnInst == "TBItem2") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[1]);
          else if (NextStrnInst == "TBItem3") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[2]);
          else if (NextStrnInst == "TBItem4") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[3]);
          else if (NextStrnInst == "TBItem5") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[4]);
          else if (NextStrnInst == "TBItem6") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[5]);
          else if (NextStrnInst == "TBItem7") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[6]);
          else {
            Serial.println(F("Unknow Command"));
          }
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
          Serial.println("String");
          Public_String_Variable[Selected_Variable] = RX_Data_String;
          break;
        case 6:
          Serial.println("Files&dFolders");
          Temporary_Path = "/" + RX_Data_String;
          Files_And_Folders();
          break;
        default:
          Serial.println(F("|| > Unrecognized Type Of Command                                            ||"));
          break;

      }
    }
    vTaskDelay(100);
  }
}

void Musical_Digital_Player() {
  ledcAttachPin(Speaker_Pin, 0);
  int Frequency;
  int Duration;
  Temporary_File = SD.open(Temporary_File);
  if (!Temporary_File) {
    return;
  }
  while (Temporary_File.available()) {
    Frequency = Temporary_File.read();
    Frequency *= 256;
    Frequency += Temporary_File.read();
    Frequency += CFrequency;
    Duration = Temporary_File.read();
    Duration *= 256;
    Duration += Temporary_File.read();
    ledcWriteTone(0, Frequency);
    vTaskDelay(pdMS_TO_TICKS(Duration));
  }
  ledcWriteTone(0, 0);
}

void Files_And_Folders() {
  Temporary_File = SD.open(Temporary_Path);
  String Item_Name = "";
  if (Temporary_File.isDirectory()) {
    for (int i = 1; i < 19; i++) { //Clear Items
      Item_Name = "ITEM" + i + "_TXT";
      Nextion_Serial_Transmit(Item_Name, ATTRIBUTE_TXT, "", 0);
      Item_Name = "ITEM" + i + "_BUT";
      Nextion_Serial_Transmit(Item_Name, ATTRIBUTE_PIC, "", 15);
    }
    Temporary_File.rewindDirectory();
    for (int i = 1; i < 19; i++) {
      File Item = Temporary_File.openNextFile();
      if (! Item) break;
      Item_Name = "ITEM" + i + "_TXT";
      Nextion_Serial_Transmit(Item_Name; ATTRIBUTE_TXT, Item.name(), 0);
      Item_Name = "ITEM" + i + "_BUT";
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
    String Item_Name_Char[14];
    Item_Name.toCharArray(Item_Name_Char, 14);
    for (int i = 1; i < 15; i++) {
      if (CharFileName[i] == '.') {
        Item_Name = String(Item_Name_Char[i + 1]) + String(Item_Name_Char[i + 2]) + String(Item_Name_Char[i + 3]);
      }
    }
    if (Extension == "WAV") {}
    else if (Extension == "BMP") {}
    else if (Extension == "GPF") {}
    else if (Extension == "FPF") {}
    else {
      //Fileditor();
    }
  }
  Temporary_File.close();
}

void Error_Reporting() {

}

void Open_Menu() {
  Nextion_Serial_Transmit(F("Menu_P1"), COMMAND_PAGE_NAME, F(""), 0);
  Nextion_Serial_Transmit(F("USERNAME_TXT"), ATTRIBUTE_TXT, Username, 0);
}

void Open_Desk() {
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

void Logon() {
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
  }
  else {
    Nextion_Serial_Transmit(F("WRONG_TXT"), ATTRIBUTE_TXT, F("Wrong Username !"), 0);
    Serial.println(F("Wrong Username !"));
    return;
  }
  Serial.println(Password);
  if (Password == Public_String_Variable[2]) {
    Serial.print(F("Good Password"));
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

void Load_System_Files() {
  Serial.println(F("Load System Files ..."));
  Temporary_File = SD.open("/GALAXOS.GSF");
  String Temporary_String = "";
  if (Temporary_File) {
    while (Temporary_File.available() && Temporary_File.peek() != 10 && Temporary_File.peek() != 13) {
      Temporary_String += Temporary_File.read();
    }
    Serial.print(Temporary_String);
    if (Temporary_String != "Galax OS Embeded Edition For Arduino Mega 2560 Version Alpha 0.12") {
      Serial.println("Error : ERROR_SOME_SYSTEM_FILES_ARE_CORRUPTED");
      return;
    }
  }
  else {
    Serial.println("Error : ERROR_SOME_SYSTEM_FILES_ARE_MISSING");
    return;
  }
  Temporary_String = "";
  return;

  Nextion_Serial_Transmit(F("LOAD_TXT"), ATTRIBUTE_TXT, F("Loading System Files ..."), 0);
  Nextion_Serial_Transmit(F("LOAD_TIM"), ATTRIBUTE_TIM, F(""), 50);
}

void Load_User_Files() {
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
  //Path = "/GALAXOS/SOUNDS/STARTUP.GMF";
  //MDI();
  Nextion_Serial_Transmit(F("LOAD_TIM"), ATTRIBUTE_TIM, "", 50);
}

void Nextion_Serial_Transmit(String Component, byte Type, String Nextion_Serial_Transmit_String, int Nextion_Serial_Transmit_Integer) {
  switch (Type) {
    case 0: //.txt for Text & Scrolling Text, QRCode, Button, DualStateButton //
      Nextion_Serial.print(Component);
      Nextion_Serial.print(F(".txt="));
      Nextion_Serial.write(0x22);
      Nextion_Serial.print(Nextion_Serial_Transmit_String);
      Nextion_Serial.write(0x22);
      break;
    case 1: //.val for Number,Progress Bar & Slider, Variable//
      Nextion_Serial.print(Component);
      Nextion_Serial.print(F(".val="));
      Nextion_Serial.print(Nextion_Serial_Transmit_Integer);
      break;
    case 2: //.tim for Timer//
      Nextion_Serial.print(Component);
      Nextion_Serial.print(F(".tim="));
      Nextion_Serial.print(Nextion_Serial_Transmit_Integer);
      break;
    case 3: //Change page to page specified name.//
      Nextion_Serial.print(F("page "));
      Nextion_Serial.print(Component);
      break;
    case 4: //.PIC
      Nextion_Serial.print(Component);
      Nextion_Serial.print(F(".pic="));
      Nextion_Serial.print(Nextion_Serial_Transmit_Integer);
      break;
    case 5: //Timer enable
      Nextion_Serial.print(Component);
      Nextion_Serial.print(F(".en="));
      Nextion_Serial.print(Nextion_Serial_Transmit_Integer);
      break;
    case 6: //page PID//
      byte PID;
      PID = Nextion_Serial_Transmit_Integer;
      Nextion_Serial.print(F("page "));
      Nextion_Serial.print(PID);
      break;
    case 7: //click
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
