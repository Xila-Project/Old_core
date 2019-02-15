//Versions : //
//0.001 : Make The Loading, Logon, Desk and Menu (Main + Shutdown)//
//0.002 : Make Setup + About//
//0.003 : Make The Link Between Arduino And Nextion//
//0.004 : Make Ultrasonic Range Finder//
//0.005 : Create Analog Read + Analog Write//
//0.006 : Setup Panel Improve + Clock Improve + Communication Improve//
//0.007 : Integrate SD Card + Make F&F//
//0.008 : Piano + Panel_SetPassword//
//0.009 : Make Fileditor//
//0.010 : Digital Write + Digital Read//
//0.011 : Login + Redesign some windows + Change Edition Name From  "Portable Edition" to "Embeded Edition" + Add Music Player//
//!0.012 : Add Pictureader//
//!0.013 : Add Function Generator and Save Form//

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


//Password Path : /USERS/%USERNAME%/PASSWORD.GSF//
//Keyboard Set : /USERS/%USERNAME%/SETTINGS/KEYBOARD.GSF//

#include <SD.h>

#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>

#include <Wire.h>

#include <SPI.h>

#include "RTClib.h"

#include <PS2Keyboard.h>

#define SoundSpeed 340000


RTC_DS1307 RTC;

TMRpcm Audio;

int SDPin = 53;
File Temp;
String Path;

byte RX1Data[15];
byte VariableSelection = 0;
int IntegerCommonVariable[26];
String StringCommonVariable = "";

unsigned int  C = 262;
unsigned int SpeakerPin = 11;

String Value;
String UARTPort;

byte NextTypeInst = 0;
char NextCharInst[14] = "";
String NextStrnInst;

const int KBDPin = 8;
const int KBCPin = 3;
PS2Keyboard Keyboard;

String User;

void setup() {

  for(int i = 0; i < 27; i++) {
    IntegerCommonVariable[i] = 0;
  }
  //Serial Initialisation//
  Serial.begin(38400);
  Serial1.begin(115200); //Nextion UART

  RTC.begin();

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
  Serial.println(F("|| > Serial Initialization ...                                                ||"));
  Serial.println(F("|| > Bootup The System ...                                                    ||"));
  Serial.println(F("|| > Waiting for Display ...                                                  ||"));

  Audio.speakerPin = SpeakerPin;

  if (!SD.begin(SDPin)) {
    Serial.println(F("|| > Initialization failed !                                                  ||"));
    return;
  }
  Serial.println(F("|| > Initialization done !                                                    ||"));

}

void loop() {
  if (Serial.available() > 0) {

  }
  //--------Read Nextion Display Data--------//
  if (Serial1.available() > 0) {
    Serial.println(F("|| > Incoming Data On UART 1                                                  ||"));
    for (int i = 1; i < 15; i++) {
      RX1Data[i] = Serial1.read();
      Serial.println(RX1Data[i]);
    }
    Read_Instruction();
  }
  if (Serial2.available() > 0) {
  }
  if (Serial3.available() > 0) {
  }
}

void Clock_Refresh()  {
  DateTime now = RTC.now();
  Serial1.print("CLOCK_TXT.txt=");
  Serial1.write(0x22);
  Serial1.print(now.hour(), DEC);
  Serial1.write(0x3a);
  if (now.minute() < 10)  Serial1.write("0");
  Serial1.print(now.minute(), DEC);
  Serial1.write(0x22);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
}

void Read_Instruction() {
  NextStrnInst = "";
  Serial.println("|| > Reading Incoming Data On UART 1 - Step 2                                 ||");
  switch (RX1Data[1]) {
    case 0x66 : NextTypeInst = 10; Clock_Refresh(); break;
    default : break;
  }
  switch (RX1Data[2]) {
    case 0x23 : NextTypeInst = 2; break; //#//
    case 0x24 : NextTypeInst = 3; break; //$//
    case 0x2A : NextTypeInst = 1; break; //*
    case 0x2F : NextTypeInst = 6; break; ///
    case 0x20 : break;
    default : break;
  }
  for (int i = 3; i < 15; i++) {
    switch (RX1Data[i]) {
      case 0xFF : break;
      case 0x86 : break; //Byte 0x86 : ASCII : (134) : Device automatically enters into sleep mode//
      case 0x87 : break; //Byte 0x87 : ASCII : (135) : Device automatically wake up//
      case 0x88 : break; //Byte 0x88 : ASCII : (136) : System successful start up//
      case 0x89 : break; //Byte 0x89 : ASCII : (137) : Start SD card upgrade//
      case 0xFD : break; //Byte 0xFD : ASCII : (253) : Data transparent transmit finished//
      case 0xFE : break; //Byte 0xFE : ASCII : (254) : Data transparent transmit ready//
      case 0x00 : break; //Byte 0x00 : ASCII : (NUL) : Error//

      case 0x20 : NextStrnInst = NextStrnInst + ' '; break;
      case 0x21 : NextStrnInst = NextStrnInst + '!'; break;
      case 0x23 : NextStrnInst = NextStrnInst + '#'; break;
      case 0x2A : NextStrnInst = NextStrnInst + '*'; break;
      case 0x2E : NextStrnInst = NextStrnInst + '.'; break;
      case 0x2F : NextStrnInst = NextStrnInst + '/'; break;
      case 0x30 : NextStrnInst = NextStrnInst + '0'; break;
      case 0x31 : NextStrnInst = NextStrnInst + '1'; break;
      case 0x32 : NextStrnInst = NextStrnInst + '2'; break;
      case 0x33 : NextStrnInst = NextStrnInst + '3'; break;
      case 0x34 : NextStrnInst = NextStrnInst + '4'; break;
      case 0x35 : NextStrnInst = NextStrnInst + '5'; break;
      case 0x36 : NextStrnInst = NextStrnInst + '6'; break;
      case 0x37 : NextStrnInst = NextStrnInst + '7'; break;
      case 0x38 : NextStrnInst = NextStrnInst + '8'; break;
      case 0x39 : NextStrnInst = NextStrnInst + '9'; break;
      case 0x41 : NextStrnInst = NextStrnInst + 'A'; break;
      case 0x42 : NextStrnInst = NextStrnInst + 'B'; break;
      case 0x43 : NextStrnInst = NextStrnInst + 'C'; break;
      case 0x44 : NextStrnInst = NextStrnInst + 'D'; break;
      case 0x45 : NextStrnInst = NextStrnInst + 'E'; break;
      case 0x46 : NextStrnInst = NextStrnInst + 'F'; break;
      case 0x47 : NextStrnInst = NextStrnInst + 'G'; break;
      case 0x48 : NextStrnInst = NextStrnInst + 'H'; break;
      case 0x49 : NextStrnInst = NextStrnInst + 'I'; break;
      case 0x4A : NextStrnInst = NextStrnInst + 'J'; break;
      case 0x4B : NextStrnInst = NextStrnInst + 'K'; break;
      case 0x4C : NextStrnInst = NextStrnInst + 'L'; break;
      case 0x4D : NextStrnInst = NextStrnInst + 'M'; break;
      case 0x4E : NextStrnInst = NextStrnInst + 'N'; break;
      case 0x4F : NextStrnInst = NextStrnInst + 'O'; break;
      case 0x50 : NextStrnInst = NextStrnInst + 'P'; break;
      case 0x51 : NextStrnInst = NextStrnInst + 'Q'; break;
      case 0x52 : NextStrnInst = NextStrnInst + 'R'; break;
      case 0x53 : NextStrnInst = NextStrnInst + 'S'; break;
      case 0x54 : NextStrnInst = NextStrnInst + 'T'; break;
      case 0x55 : NextStrnInst = NextStrnInst + 'U'; break;
      case 0x56 : NextStrnInst = NextStrnInst + 'V'; break;
      case 0x57 : NextStrnInst = NextStrnInst + 'W'; break;
      case 0x58 : NextStrnInst = NextStrnInst + 'X'; break;
      case 0x59 : NextStrnInst = NextStrnInst + 'Y'; break;
      case 0x5A : NextStrnInst = NextStrnInst + 'Z'; break;
      case 0x61 : NextStrnInst = NextStrnInst + 'a'; break;
      case 0x62 : NextStrnInst = NextStrnInst + 'b'; break;
      case 0x63 : NextStrnInst = NextStrnInst + 'c'; break;
      case 0x64 : NextStrnInst = NextStrnInst + 'd'; break;
      case 0x65 : NextStrnInst = NextStrnInst + 'e'; break;
      case 0x66 : NextStrnInst = NextStrnInst + 'f'; break;
      case 0x67 : NextStrnInst = NextStrnInst + 'g'; break;
      case 0x68 : NextStrnInst = NextStrnInst + 'h'; break;
      case 0x69 : NextStrnInst = NextStrnInst + 'i'; break;
      case 0x6A : NextStrnInst = NextStrnInst + 'j'; break;
      case 0x6B : NextStrnInst = NextStrnInst + 'k'; break;
      case 0x6C : NextStrnInst = NextStrnInst + 'l'; break;
      case 0x6D : NextStrnInst = NextStrnInst + 'm'; break;
      case 0x6E : NextStrnInst = NextStrnInst + 'n'; break;
      case 0x6F : NextStrnInst = NextStrnInst + 'o'; break;
      case 0x70 : NextStrnInst = NextStrnInst + 'p'; break;
      case 0x71 : NextStrnInst = NextStrnInst + 'q'; break;
      case 0x72 : NextStrnInst = NextStrnInst + 'r'; break;
      case 0x73 : NextStrnInst = NextStrnInst + 's'; break;
      case 0x74 : NextStrnInst = NextStrnInst + 't'; break;
      case 0x75 : NextStrnInst = NextStrnInst + 'u'; break;
      case 0x76 : NextStrnInst = NextStrnInst + 'v'; break;
      case 0x77 : NextStrnInst = NextStrnInst + 'w'; break;
      case 0x78 : NextStrnInst = NextStrnInst + 'x'; break;
      case 0x79 : NextStrnInst = NextStrnInst + 'y'; break;
      case 0x7A : NextStrnInst = NextStrnInst + 'z'; break;
      default : Serial.println(F("|| > Unrecognized Charactere                                                  ||")); break;
    }
  }

  Serial.println(F("|| > Execute Incoming Data On UART 1 - Step 4                                 ||"));
  NextStrnInst.toCharArray(NextCharInst, 15);
  Serial.println(NextStrnInst);
  Serial.println(NextTypeInst);

  switch (NextTypeInst) {
    case 1:
      Serial.println(F("Command"));
      //*->Command//
      if (NextStrnInst == "Ready") Ready();
      else if (NextStrnInst == "GetPswd") GetPassword(StringCommonVariable);
      else if (NextStrnInst == "GoodPswd") Logon();
      else if (NextStrnInst == "Menu") {
        Serial1.print("USERPAN_TXT.txt=");
        Serial1.write(0x22);
        Serial1.print(User);
        Serial1.write(0x22);
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
      }
      else if (NextStrnInst == "USRF") UltraSonic(IntegerCommonVariable[1], IntegerCommonVariable[2]);
      else if (NextStrnInst == "ClckRfrs") Clock_Refresh();
      else if (NextStrnInst == "Clock") Clock();
      else if (NextStrnInst == "SetHour") SetHour(IntegerCommonVariable[1], IntegerCommonVariable[2]);
      else if (NextStrnInst == "SetDate") SetDate(IntegerCommonVariable[1], IntegerCommonVariable[2], IntegerCommonVariable[3]);
      else if (NextStrnInst == "AnlgRead") Analog_Read();
      else if (NextStrnInst == "AnlgWrit") Analog_Write(IntegerCommonVariable[1], IntegerCommonVariable[2]);
      else if (NextStrnInst == "DgtlWrit") Digital_Write(IntegerCommonVariable[1], IntegerCommonVariable[2]);
      else if (NextStrnInst == "SetPsswr") SetPassword(StringCommonVariable);
      else if (NextStrnInst == "SetUsrnm") SetUsername(StringCommonVariable);
      else if (NextStrnInst == "CLow") Piano(0);
      else if (NextStrnInst == "C#Low") Piano(16);
      else if (NextStrnInst == "DLow") Piano(32);
      else if (NextStrnInst == "D#Low") Piano(50);
      else if (NextStrnInst == "ELow") Piano(68);
      else if (NextStrnInst == "FLow") Piano(88);
      else if (NextStrnInst == "F#Low") Piano(108);
      else if (NextStrnInst == "GLow") Piano(130);
      else if (NextStrnInst == "G#Low") Piano(154);
      else if (NextStrnInst == "AHigh") Piano(178);
      else if (NextStrnInst == "A#High") Piano(205);
      else if (NextStrnInst == "BHigh") Piano(232);
      else if (NextStrnInst == "CHigh") Piano(262);
      else if (NextStrnInst == "C#High") Piano(293);
      else if (NextStrnInst == "DHigh") Piano(326);
      else if (NextStrnInst == "D#High") Piano(361);
      else if (NextStrnInst == "EHigh") Piano(398);
      else if (NextStrnInst == "FHigh") Piano(437);
      else if (NextStrnInst == "F#High") Piano(478);
      else if (NextStrnInst == "GHigh") Piano(522);
      else if (NextStrnInst == "Pause") Audio.pause();
      else if (NextStrnInst == "Mute") Audio.setVolume(0);
      else if (NextStrnInst == "Unmute") Audio.setVolume(1);
      else if (NextStrnInst == "StopMusic") Audio.disable();
      else if (NextStrnInst == "Resume") Music_Player(IntegerCommonVariable[1], "");
      else if (NextStrnInst == "Tone") tone(IntegerCommonVariable[2], IntegerCommonVariable[1]);
      else if (NextStrnInst == "NoTone") tone(IntegerCommonVariable[2], IntegerCommonVariable[1]);
      else if (NextStrnInst == "FGSave") Save(StringCommonVariable, "FG");
      else if (NextStrnInst == "TinyBasic") TinyBasic();
      else Serial.print(F("Unknow Command"));
      break;

    case 2:

      Serial.println("Integer");
      //#->Integer Variable//
      if (NextStrnInst == "Hour") VariableSelection = 1;
      else if (NextStrnInst == "Minute") VariableSelection = 2;

      if (NextStrnInst == "Day") VariableSelection = 1;
      else if (NextStrnInst == "Month") VariableSelection = 2;
      else if (NextStrnInst == "Year") VariableSelection = 3;

      else if (NextStrnInst == "USTrig") VariableSelection = 1;
      else if (NextStrnInst == "USEcho") VariableSelection = 2;

      else if (NextStrnInst == "PWMP") VariableSelection = 1;
      else if (NextStrnInst == "PWMDC") VariableSelection = 2;

      else if (NextStrnInst == "OPPIN") VariableSelection = 1;
      else if (NextStrnInst == "OPSTATE") VariableSelection = 2;

      else if (NextStrnInst == "MPTime") VariableSelection = 1;

      else if (NextStrnInst == "Frequency") VariableSelection = 1;
      else if (NextStrnInst == "FGPin") VariableSelection = 2;

      NextTypeInst = 4;
      break;

    case 3:
      Serial.println("String");
      //$->String Variable//
      if (NextStrnInst == "Username") VariableSelection = 1;
      else if (NextStrnInst == "Password") VariableSelection = 1;
      NextTypeInst = 5;
      break;

    case 4:
      Serial.println("Edit Integer");
      //Edit Integer Common Variable//
      IntegerCommonVariable[VariableSelection] = RX1Data[2];
      break;

    case 5:
      Serial.println("Edit String");
      //Edit String Common Variable//
      StringCommonVariable = NextStrnInst;
      break;

    case 6:
      Serial.println("File&dFolder Search");
      //Files&Folder Search//
      if (NextStrnInst == "/") {
        Path = "/";
        Fandf(SD.open(Path));
      }
      else {
        Path = Path + NextStrnInst;
        Temp = SD.open(Path);

        if (Temp && !Temp.isDirectory()) {
          Fandf(SD.open(Path));
        }
        else {
          Path = Path + "/";
          Fandf(SD.open(Path));
        }

      }
      break;

    default:

      //Unrecognized Type Of Command//
      Serial.println(F("|| > Unrecognized Type Of Command                                            ||"));
      break;
  }
}

void NextionSerial(String Item, int Type, String StringData, int IntegerData) {
  switch (Type) {
    case 0: //.txt for Text & Scrolling Text, QRCode, Button, DualStateButton //

    Serial1.print(Item);
    Serial1.print(".txt=");
    Serial1.write(0x22);
    Serial1.print(StringData);
    Serial1.write(0x22);

    case 1://.val for Number,Progress Bar & Slider, Variable//

    Serial1.print(Item);
    Serial1.print(".val=");
    Serial1.print(IntegerData);

    case 2://.tim for Timer//

    Serial1.print(Item);
    Serial1.print(".tim=");
    Serial1.print(IntegerData);

    case 3://Page//

    Serial1.print("page ");
    Serial1.print(Item);
  }

  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

}

void TinyBasic () {
  Serial.println(F("|| > Tiny Basic"));
  Keyboard.begin(KBDPin, KBCPin, PS2Keymap_French);
  String Line[16];
  int SelectLine = 1;
  char Entry;

  for (int i = 0; i < 17; i++) {
    Line[i] = "";
  }

  IntegerCommonVariable[1] = freeRam;
  Line[1] = "          ==== Galax OS EE Tiny Basic 0.1 ====";
  Line[2] = "Arduino Mega 2560 - ATmega2560-16AU - 8K RAM";

  Serial1.print("LINE1_TXT.txt=");
  Serial1.write(0x22);
  Serial1.print(Line[1]);
  Serial1.write(0x22);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  Serial1.print("LINE2_TXT.txt=");
  Serial1.write(0x22);
  Serial1.print(Line[2]);
  Serial1.write(0x22);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  SelectLine = 3;

  Serial1.print("SELECTLINE_VAR.val=");
  Serial1.print(SelectLine);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial.println(F("|| > Listen to Keyboard"));
  while (!Serial1.available()) {
    if (Keyboard.available()) {
      Entry = Keyboard.read();
      Serial.print(Entry);
      if (Entry == PS2_ENTER) {
        if (SelectLine > 15) {
          for (int i = 1; i < 16; i++) {
            Serial1.print("LINE");
            Serial1.print(i);
            Serial1.print("_TXT.txt=");
            Serial1.write(0x22);
            Serial1.print(Line[i]);
            Serial1.write(0x22);
            Serial1.write(0xff);
            Serial1.write(0xff);
            Serial1.write(0xff);
            Line[i] = Line[i + 1];
          }
          SelectLine--;
          Line[16] = "";
        }
        if (Line[SelectLine] == "CLEAR") {
          for (int i = 1; i < 17; i++) {
            Line[i] = "";
            Serial1.print("LINE");
            Serial1.print(i);
            Serial1.print("_TXT.txt=");
            Serial1.write(0x22);
            Serial1.print(Line[i]);
            Serial1.write(0x22);
            Serial1.write(0xff);
            Serial1.write(0xff);
            Serial1.write(0xff);

          }
          SelectLine = 0;
        }
        else if (Line[SelectLine] == "ESCAPE") {
          Serial1.print("page Desk");
          Serial1.write(0xff);
          Serial1.write(0xff);
          Serial1.write(0xff);
        }
        else {
          Line[SelectLine + 1] = TinyBasic_RE(Line[SelectLine]);
        }

        SelectLine += 1;
        Serial1.print("LINE");
        Serial1.print(SelectLine);
        Serial1.print("_TXT.txt=");
        Serial1.write(0x22);
        Serial1.print(Line[SelectLine]);
        Serial1.write(0x22);
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);

      }
      else if (Entry == PS2_ESC) {
        Serial1.print("page Desk");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
      }
      else if (Entry == PS2_DELETE) {
        Line[SelectLine] = Line[SelectLine].substring(0, Line[SelectLine].length() - 1);
        Serial1.print("LINE");
        Serial1.print(SelectLine);
        Serial1.print("_TXT.txt=");
        Serial1.write(0x22);
        Serial1.print(Line[SelectLine]);
        Serial1.write(0x22);
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
      }
      else {
        Line[SelectLine] += Entry;
        Serial1.print("LINE");
        Serial1.print(SelectLine);
        Serial1.print("_TXT.txt=");
        Serial1.write(0x22);
        Serial1.print(Line[SelectLine]);
        Serial1.write(0x22);
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
      }

    }
  }
}

String TinyBasic_RE(String CopyLine) {
   char Command[sizeof(CopyLine)+1];
   String Keyword = "";
   String Argument[3] = {"", "", ""};
   int IntegerArgument[3] = {0, 0, 0};
   char TypeArgument[4] = {'\0', '\0', '\0'};
   byte i = 0;
   byte AmountArguments = 0;

   //Read
   for(int ii = 0; ii < 4; i++) {
     if(Command[i] == '\0') break;
     if(ii == 0) {
       while(Command[i] != 47) {
         Keyword += Command[i];
         i++;
       }
       i++;
     }
     else {
       AmountArguments++;
       if (Command[i] == 39) {
         TypeArgument[ii] == '$';
         i++;
         while(Command[i] != 39) {
           Argument[ii] += Command[i];
           i++;
         }
       }
       else if(isDigit(Command[i])) {
         TypeArgument[ii] == '#';
         while(isDigit(Command[i])) {
           Argument[ii] += Command[i];
           i++;
         }
         IntegerArgument[ii] = int(Argument[ii].toInt());
       }
       else if (isUpperCase(Command[i])) {
         TypeArgument[ii] = Command[i];
         i++;
       }
       else {
         TypeArgument[ii] == '|';
         Argument[ii] = Command[i];
         i++;
       }
     }
   }

   String ToPrint;

   Serial.println(Keyword);
   Serial.println(Argument[1]);
   Serial.println(Argument[2]);
   Serial.println(Argument[3]);
   Serial.println(AmountArguments);
   //Execute
   if(Keyword == "PRINT") {

     if(AmountArguments == 1) {
       if(TypeArgument[1] == '$' | TypeArgument[i] == '#') {
         ToPrint = Argument[1];
       }
       else if(isUpperCase(TypeArgument[1])) {
         ToPrint = IntegerCommonVariable[TypeArgument[1] - 64];
       }
       else {
         ToPrint = F("Invalid Argument");
       }
     }
     else if(AmountArguments > 2) {
       if(TypeArgument[1] == '$' & TypeArgument[3] == '$') {
        ToPrint = Argument[1] + Argument[3];
       }
       else {
         if(isUpperCase(TypeArgument[1])) {
           IntegerArgument[1] = IntegerCommonVariable[TypeArgument[1]-64];
         }
         if(isUpperCase(TypeArgument[3])) {
           IntegerArgument[3] = IntegerCommonVariable[TypeArgument[3]-64];
         }
         if(Argument[2] == "+") {
           IntegerArgument[2] = IntegerArgument[1] + IntegerArgument[3];
         }
         else if(Argument[2] == "-") {
          IntegerArgument[2] = IntegerArgument[1] - IntegerArgument[3];
         }
         else if(Argument[2] == "*") {
          IntegerArgument[2] = IntegerArgument[1] * IntegerArgument[3];
         }
         else if(Argument[2] == "/") {
          IntegerArgument[2] = IntegerArgument[1] / IntegerArgument[3];
         }
         ToPrint = String(IntegerArgument[2], DEC);
       }
     }
     else {
       ToPrint = F("Error : No Arguments");
     }
   }
   return ToPrint;
}

void Pictureader(String Filename) {

  Serial1.print("page Pictviewer");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  Serial1.print("FILENAME_TXT.txt=");
  Serial1.write(0x22);
  Serial1.print(Filename);
  Serial1.write(0x22);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  int Width; //largeur
  int Heigh; //hauteur
  int Size;
  unsigned long Data_offset;
  int Encoding;
  int Array_size;
  int Red;
  int Green;
  int Blue;
  int Color;


  Serial.println(Path);
  Temp = SD.open(Path);
  if (Temp) {
    Temp.seek(0);
    if (Temp.read() == 66 && Temp.read() == 77) {
      Serial.println(F("It's a Bitmap File"));

      Temp.seek(2);
      Size = int(Temp.read()); //in bytes
      Serial.println(Size);

      Serial1.print("SIZE_NUM.val=");
      Serial1.print(Size);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);

      Temp.seek(10);
      Data_offset = long(Temp.read());
      Serial.println(Data_offset);

      Temp.seek(18);
      Width = int(Temp.read());
      Serial.println(Width);

      Serial1.print("WIDTH_NUM.val=");
      Serial1.print(Width);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);

      Temp.seek(22);
      Heigh = long(Temp.read());
      Serial.println(Heigh);

      Serial1.print("HEIGH_NUM.val=");
      Serial1.print(Heigh);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);

      Temp.seek(28);
      Encoding = int(Temp.read());
      Serial.println(Encoding);
      Heigh += 24;
      Width += 10;

      Temp.seek(Data_offset);
      Serial.println(Temp.position());

      if (Encoding == 16) {
        Serial.println(F("16 bit encoding"));
        for (int y = Heigh; y > 24; y--) {
          for (int x = 10; x < Width; x++) {

            Serial.println(Temp.peek());
            Blue = int(Temp.read());
            Serial.println(Temp.peek());
            Green = int(Temp.read());
            Serial.println(Temp.peek());
            Red = int(Temp.read());

            Red = Red << 11;
            Green = Green << 6;

            Color = Red | Green;
            Color = Color | Blue;


            Serial1.print("fill ");
            Serial1.print(x);
            Serial1.write(0x2c);
            Serial1.print(y);
            Serial1.write(0x2c);
            Serial1.print(1);
            Serial1.write(0x2c);
            Serial1.print(1);
            Serial1.write(0x2c);
            Serial1.print(Color);
            Serial1.write(0xff);
            Serial1.write(0xff);
            Serial1.write(0xff);
          }
        }
      }

      else if (Encoding == 24) {
        Serial.println(F("24 bit encoding"));
        for (int y = Heigh; y > 24; y--) {
          for (int x = 10; x < Width; x++) {

            Serial.println(Temp.peek());
            Blue = int(Temp.read());
            Serial.println(Temp.peek());
            Green = int(Temp.read());
            Serial.println(Temp.peek());
            Red = int(Temp.read());

            Red = Red << 11;
            Green = Green << 6;

            Color = Red | Green;
            Color = Color | Blue;

            Serial.println(Color);

            Serial1.print("fill ");
            Serial1.print(x);
            Serial1.write(0x2c);
            Serial1.print(y);
            Serial1.write(0x2c);
            Serial1.print(1);
            Serial1.write(0x2c);
            Serial1.print(1);
            Serial1.write(0x2c);
            Serial1.print(map(Color, 0, 16777215, 0, 65535));
            Serial1.write(0xff);
            Serial1.write(0xff);
            Serial1.write(0xff);
          }
          Temp.read();
          Temp.read();
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

void SetHour(int Hour, int Minute) {
  DateTime now = RTC.now();

  //RTC.adjust(now.year(), now.month(), now.day(), Hour, Minute, 0);
}

void SetDate(int Day, int Month, int Year) {
  DateTime now = RTC.now();
  //RTC.adjust(Year, Month, Day, now.hour(), now.minute(), now.second());
}

void Save(String Filename, String Application) {
  if (Application == "FG") {
    Path = "/USERS/" + User;
    Path += "/FUNCGENE/";
    Path += Filename;
    Path += ".FPF";
    Temp = SD.open(Path, FILE_WRITE);
    Temp.println("Function Generator Preset File");
    Temp.println(IntegerCommonVariable[2]);
    Temp.println(IntegerCommonVariable[1]);
  }
}

void Fandf(File Directory) {
  Serial.println(F("|| > Open F&F App                                                            ||"));
  if (Directory.isDirectory()) {
    Directory.rewindDirectory();

    Serial1.print("PATH_TXT.txt=");
    Serial1.write(0x22);
    Serial1.print(Path);
    Serial1.write(0x22);
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);

    for (int i = 1; i < 19; i++) {
      File Item = Directory.openNextFile();
      if (! Item) {
        Serial.println(F("|| No more item                                                               ||"));
        break;
      }
      Serial1.print("ITEM");
      Serial1.print(i);
      Serial1.print("_TXT.txt=");
      Serial1.write(0x22);
      Serial1.print(Item.name());
      Serial1.write(0x22);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial.println(Item.name());
      if (Item.isDirectory()) {
        Serial1.print("ITEM");
        Serial1.print(i);
        Serial1.print("_BUT.pic=12");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
      }
      else {
        Serial1.print("ITEM");
        Serial1.print(i);
        Serial1.print("_BUT.pic=11");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
      }
      Item.close();
    }
    Directory.close();
  }
  else {
    String StringFileName = Directory.name();
    char CharFileName[14];
    String Extension;

    StringFileName.toCharArray(CharFileName, 14);
    for (int i = 1; i < 15; i++) {
      Serial.write(CharFileName[i]);
      if (CharFileName[i] == '.') {
        Extension = String(CharFileName[i + 1]) + String(CharFileName[i + 2]) + String(CharFileName[i + 3]);
      }

    }
    Directory.close();
    Serial.println("Extension :");
    Serial.print(Extension);

    if (Extension == "WAV") Music_Player(0, StringFileName);
    if (Extension == "BMP") Pictureader(StringFileName);
    if (Extension == "GPF") {}
    if (Extension == "FPF") {
      Serial1.print("page Func Generator");
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);

      Serial1.print("page Func Generator");
      Serial1.write(0x22);
      Serial1.print(StringFileName);
      Serial1.write(0x22);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);

      Temp = SD.open(Path);

      String Line = "";

      while (Temp.available()) {
        while (Temp.peek() != 10 or Temp.peek() != 13) {
          Line = Temp.read();
        }
        Temp.seek(Temp.position() + 2);
        if (Line == "Function Generator Preset File") {
          Serial1.print("PIN_NUM.val=");
          while (Temp.peek() != 10 or Temp.peek() != 13) {
            Serial1.print(Temp.read());
          }
          Temp.seek(Temp.position() + 2);
          Serial1.write(0xff);
          Serial1.write(0xff);
          Serial1.write(0xff);

          Serial1.print("FREQUENCY_NUM.val=");
          while (Temp.peek() != 10 or Temp.peek() != 13) {
            Serial1.print(Temp.read());
          }
          Temp.seek(Temp.position() + 2);
          Serial1.write(0xff);
          Serial1.write(0xff);
          Serial1.write(0xff);
        }
        else {

        }
      }
    }
    else {
      Directory.close();
      Fileditor();
    }
  }
}

void Fileditor() {
  Serial.println(F("|| Open Fileditor                                                             ||"));
  Serial1.print("page Fileditor");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Temp = SD.open(Path);
  for (int i = 1; i < 14; i++) {
    Serial.println(F("|| Ligne :                                                                    ||"));
    Serial.print(i);
    Serial1.print("LINE");
    Serial1.print(i);
    Serial1.print("_TXT.txt=");
    Serial1.write(0x22);
    for (int ii = 1; ii < 57; ii++) {
      if (Temp.available()) {
        Serial.println(Temp.peek());
        if (Temp.peek() == 10 or Temp.peek() == 13) {
          Temp.seek(Temp.position() + 2);
          ii = 57;
          Serial.println(F("|| Retour Ligne                                                               ||"));
        }
        else {
          Serial1.write(Temp.read());
        }
      }
      else {
        loop();
        break;
      }
    }
    Serial1.write(0x22);
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
  }
}

void Music_Player(int Time, String Filename) {
  if (Filename != "") {
    Serial1.print("page Music Player");
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);

    Serial1.print("FILENAME_TXT.txt=");
    Serial1.write(0x22);
    Serial1.print(Filename);
    Serial1.write(0x22);
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
  }
  Serial1.print("TIMER_TIM.en=");
  Serial1.print(1);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
  char Temporary[Path.length() + 1];
  Path.toCharArray(Temporary, sizeof(Temporary));
  Audio.play(Temporary, Time);
}

void Ready() {
  Serial.println(F("|| > Ready.                                                                   ||"));
  Serial1.print("page Logon");
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
}

void GetPassword(String Username) {
  Path = "/USERS/" + Username + "/PASSWORD.GSF";
  Serial.println(Path);
  Temp = SD.open(Path);
  if (Temp) {
    User = Username;
    while (Temp.available()) {
      if (Temp.peek() >= 31) {
        Serial.print(Temp.peek());
        StringCommonVariable = Temp.read();
      }
      else {
        Temp.read();
      }
    }
    NextionSerial("TEMP_VAR", 0, StringCommonVariable, 0);
    Temp.close();
    loop();
  }
  else {
    Serial.println(F("Wrong Username"));
    Serial1.print("WRONG_TXT.txt=");
    Serial1.write(0x22);
    Serial1.print("Wrong Username !");
    Serial1.write(0x22);
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
  }
}

void Logon() {
  Serial.println(F("|| > Good Pin Code                                                            ||"));
  Serial.println(F("|| > Loading Session ...                                                      ||"));
  NextionSerial("Desk", 3, "", 0);
  Serial.println(F("|| > Page Desk                                                                ||"));
  Serial.println(F("|| > Initialization SD Card ...                                               ||"));
  loop();
}

void Analog_Write(int Pin, int DutyCycle)  {
  Serial.println(F("|| > Open Arduino Analog Write App                                            ||"));
  pinMode(Pin, OUTPUT);
  analogWrite(Pin, DutyCycle);
}

void Analog_Read() {
  for (int i = 0; i < 16; i++) {
    Serial1.print("A");
    Serial1.print(i);
    Serial1.print("VAL_TXT.val=");
    Serial1.print(map(analogRead(i), 0, 1023, 0, 5000));
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
  }
  loop();
}

void Digital_Write(int Pin, int State) {
  Serial.println(F("|| > Open Arduino DigitalWrite App                                            ||"));
  pinMode(Pin, OUTPUT);
  if (State == 0) {
    digitalWrite(Pin, LOW);
  }
  else {
    digitalWrite(Pin, HIGH);
  }
}

void Digital_Read() {
  Serial.println(F("|| > Open Arduino Digital Read App                                            ||"));
  while (Serial1.available() == 0)  {
    for (int i = 0; i < 16; i++) {

    }
  }
  Serial.println(F("|| > Close Arduino Analog Read App                                           ||"));
  loop();
}

void Clock()  {
  Serial.println(F("|| > Open Clock App                                                           ||"));
  while (Serial1.available() == 0)  {
    DateTime now = RTC.now();
    Serial1.print("CLOCK_TXT.txt=");
    Serial1.write(0x22);
    if (now.hour() < 10)  Serial1.print("0");
    Serial1.print(now.hour(), DEC);
    Serial1.write(0x3a);
    if (now.minute() < 10)  Serial1.print("0");
    Serial1.print(now.minute(), DEC);
    Serial1.write(0x22);
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);

    Serial1.print("TIME_TXT.txt=");
    Serial1.write(0x22);
    if (now.hour() < 10)  Serial1.print("0");
    Serial1.print(now.hour(), DEC);
    Serial1.write(0x20);
    Serial1.write(0x3a);
    if (now.minute() < 10)  Serial1.print("0");
    Serial1.print(now.minute(), DEC);
    Serial1.write(0x20);
    Serial1.write(0x3a);
    if (now.second() < 10)  Serial1.print("0");
    Serial1.print(now.second(), DEC);
    Serial1.write(0x22);
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);

    Serial1.print("DAYOFWEEK_TXT.txt=");
    Serial1.write(0x22);
    switch (now.dayOfTheWeek()) {
      case 1 : Serial1.print("Monday"); break;
      case 2 : Serial1.print("Tuesday"); break;
      case 3 : Serial1.print("Wednesday"); break;
      case 4 : Serial1.print("Thursday"); break;
      case 5 : Serial1.print("Friday"); break;
      case 6 : Serial1.print("Saturday"); break;
      case 7 : Serial1.print("Sunday"); break;
    }
    Serial1.write(0x22);
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);

    Serial1.print("DAY_TXT.txt=");
    Serial1.write(0x22);
    if (now.day() < 10)  Serial1.print("0");
    Serial1.print(now.day(), DEC);
    Serial1.write(0x22);
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);

    Serial1.print("MONTH_TXT.txt=");
    Serial1.write(0x22);
    switch (now.month()) {
      case 1 : Serial1.print("January"); break;
      case 2 : Serial1.print("February"); break;
      case 3 : Serial1.print("March"); break;
      case 4 : Serial1.print("April"); break;
      case 5 : Serial1.print("May"); break;
      case 6 : Serial1.print("June"); break;
      case 7 : Serial1.print("July"); break;
      case 8 : Serial1.print("August"); break;
      case 9 : Serial1.print("September"); break;
      case 10 : Serial1.print("October"); break;
      case 11: Serial1.print("November"); break;
      case 12 : Serial1.print("December"); break;
    }
    Serial1.write(0x22);
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);

    Serial1.print("YEAR_TXT.txt=");
    Serial1.write(0x22);
    Serial1.print(now.year(), DEC);
    Serial1.write(0x22);
    Serial1.write(0xff);
    Serial1.write(0xff);
    Serial1.write(0xff);
  }
  Serial.println(F("|| > Close Clock App                                                        ||"));
  loop();
}

void UltraSonic(int USTrig, int USEcho) {
  Serial.println(F("|| > Open UltraSonic Rangefinder App                                         ||"));
  Serial.println(USTrig);
  Serial.println(USEcho);
  pinMode(USTrig, OUTPUT);
  pinMode(USEcho, INPUT);
  digitalWrite(USTrig, LOW);
  while (Serial1.available() == 0)  {
    digitalWrite(USTrig, HIGH);
    delayMicroseconds(10); //on attend 10 µs
    digitalWrite(USTrig, LOW);
    unsigned long Duration = pulseIn(USEcho, HIGH);
    if (Duration > 30000) ("|| > Onde perdue                                         ||");
    else {
      Duration = Duration / 2;
      float Time = Duration / 1000000.0;
      int Distance = Time * SoundSpeed;
      Serial.println("|| > Distance :");
      Serial.print(Distance);
      Serial1.print("DISTVAL_NUM.val=");
      Serial1.print(Distance);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      delay(100);
    }
  }
  Serial.println(F("|| > Close UltraSonic Rangefinder App                                        ||"));
  loop();
}

int freeRam() {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

void CardInformation() {
  SdVolume CardVolume;
  Sd2Card Card;
  uint32_t VolumeSize;
  switch (Card.type()) {
    case SD_CARD_TYPE_SD1:
      Serial1.print("CTVAL_TXT.txt=");
      Serial1.write(0x22);
      Serial1.print("SD1");
      Serial1.write(0x22);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      break;
    case SD_CARD_TYPE_SD2:
      Serial1.print("CTVAL_TXT.txt=");
      Serial1.write(0x22);
      Serial1.print("SD2");
      Serial1.write(0x22);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      break;
    case SD_CARD_TYPE_SDHC:
      Serial1.print("CTVAL_TXT.txt=");
      Serial1.write(0x22);
      Serial1.print("SDHC");
      Serial1.write(0x22);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
      break;
    default:
      Serial1.print("CTVAL_TXT.txt=");
      Serial1.write(0x22);
      Serial1.print("Unknow");
      Serial1.write(0x22);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);
  }

  Serial1.print("MPVAL_TXT.txt=");
  Serial1.write(0x22);
  Serial1.print("FAT");
  Serial1.print(CardVolume.fatType(), DEC);
  Serial1.write(0x22);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  VolumeSize = CardVolume.blocksPerCluster();
  VolumeSize *= CardVolume.clusterCount();
  VolumeSize *= 512;
  VolumeSize /= 1024;
  VolumeSize /= 1024;

  Serial1.print("SIZEVAL_TXT.txt=");
  Serial1.write(0x22);
  Serial1.print(VolumeSize);
  Serial1.print("MB");
  Serial1.write(0x22);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
}

void Piano(int Note) {
  unsigned long Duration = 200;
  Note = Note + C;
  tone(SpeakerPin, Note, Duration);
}

void SetPassword(String Password) {
  Serial.println(F("|| > Set The New Password In The SD Card ...                                 ||"));
  Serial.println(Password);
  SD.remove("/GALAXOS/USER/PASSWORD.GSF");
  Temp = SD.open("/GALAXOS/USER/PASSWORD.GSF", FILE_WRITE);
  Temp.println(Password);
  Temp.close();
  Serial.println(F("|| > Done.                                                                   ||"));
  loop();
}

void SetUsername(String Username) {
  Serial.println(F("|| > Set The New Username In The SD Card ...                                 ||"));
  Serial.println(Username);
  loop();
}

int Char_to_Int(char InChar1, char InChar2)  {
  int Temporary = 0;
  switch (InChar2)  {
    case '0' :
      Temporary = 0;
      break;
    case  '1' :
      Temporary = 1;
      break;
    case  '2' :
      Temporary = 2;
      break;
    case  '3' :
      Temporary = 3;
      break;
    case  '4' :
      Temporary = 4;
      break;
    case  '5' :
      Temporary = 5;
      break;
    case  '6' :
      Temporary = 6;
      break;
    case  '7' :
      Temporary = 7;
      break;
    case  '8' :
      Temporary = 8;
      break;
    case  '9' :
      Temporary = 9;
      break;
    default :
      break;
  }
  switch (InChar1)  {
    case '0' :
      break;
    case  '1' :
      Temporary = Temporary + 10;
      break;
    case  '2' :
      Temporary = Temporary + 20;
      break;
    case  '3' :
      Temporary = Temporary + 30;
      break;
    case  '4' :
      Temporary = Temporary + 40;
      break;
    case  '5' :
      Temporary = Temporary + 50;
      break;
    case  '6' :
      Temporary = Temporary + 60;
      break;
    case  '7' :
      Temporary = Temporary + 70;
      break;
    case  '8' :
      Temporary = Temporary + 80;
      break;
    case  '9' :
      Temporary = Temporary + 90;
      break;
    default :
      break;
  }
  return Temporary;
}
