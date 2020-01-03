#include "galaxos.h"

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
    xTaskCreatePinnedToCore(Nextion_Serial_Receive, "Nextion_Serial_Receive", 1028, NULL, 2, &Nextion_Serial_Transmit_Handle, 0);
    xTaksCreatePinnedToCore(GalaxOS.core, "GalaxOS Core", 4096, NULL, 2, &GalaxOS_Core_Handle, 1);
    xTaskCreatePinnedToCore(Musical_Digital_Player, "Musical_Digital_Player", 4096, NULL, 2, &Musical_Digital_Player_Handle, 1);
    vTaskSuspend(Musical_Digital_Player_Handle);
    xTaskCreatePinnedToCore(Ressource_Monitor, "Ressource_Monitor", 2048, NULL, 2, &Ressource_Monitor_Handle, 1);
    Serial.println(F("|| > Loading Task ...                                                         ||"));
    Serial.println(F("|| > Waiting for Display ...                                                  ||"));
    
}

void GalaxOS::Core() {
    //to do : check notify
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

void GalaxOS::Event_Handler_Request(int Type, String Infromations) {
  switch (Type) {
    Nextion_Serial_Transmit(F("Event"), COMMAND_PAGE_NAME, "", 0);
    case ERROR_FAILLED_TO_INTIALIZE_SD_CARD :
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
      
  }
  
}

void GalaxOS::USB_Serial_Transmit(const char* USB_Serial_Transmit_String, byte Alignment) {
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

      Serial.println(F("|| > Incoming Data On UART 1                                                  ||"));

      String RX_Data_String = "";

      char RX_Data_Char[80];

      byte Selected_Variable = 0;
      byte Type = 0;
      byte i = 1;

      while (Nextion_Serial.available()) {
        RX_Data_Char[i] = char(Nextion_Serial.read());
        i++;
      }

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
          if (RX_Data_String == "LoadSystem") Load_System_Files();
          else if (RX_Data_String == "LoadUser") Load_User_Files();
          else if (RX_Data_String == "Logon") Logon();
          else if (RX_Data_String == "Menu") Open_Menu();
          else if (RX_Data_String == "Desk") Open_Desk();

          else if (RX_Data_String == "OK") Event_Handler_Replay

          else if (RX_Data_String == "F&F") Files_And_Folders();
          else if (RX_Data_String == "F&F_RDelete") Event_Handler_Request();
          

          
          else if (RX_Data_String == "TBItem1") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[0]);
          else if (RX_Data_String == "TBItem2") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[1]);
          else if (RX_Data_String == "TBItem3") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[2]);
          else if (RX_Data_String == "TBItem4") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[3]);
          else if (RX_Data_String == "TBItem5") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[4]);
          else if (RX_Data_String == "TBItem6") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[5]);
          else if (RX_Data_String == "TBItem7") Nextion_Serial_Transmit("", 6, "", Taskbar_Items_PID[6]);

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