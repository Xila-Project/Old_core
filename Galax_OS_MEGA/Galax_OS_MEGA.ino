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

#include <SD.h>
#include <pcmConfig.h>
#include <pcmRF.h>
#include <TMRpcm.h>
#include <Wire.h>
#include <SPI.h>
#include "RTClib.h"
#include <PS2Keyboard.h>
#include <Arduino_FreeRTOS.h>

#define SOUND_SPEED 343000
#define LIGHT_SPEED 299792458000

/*
  #define ERROR_FILE_NOT_FOUND 62
*/
#define ERROR_FAILLED_TO_INTIALIZE_SD_CARD 94
#define ERROR_SOME_SYSTEM_FILES_ARE_MISSING 12
#define ERROR_SOME_SYSTEM_FILES_ARE_CORRUPTED 13
#define ERROR_SOME_USER_SETTINGS_FILES_ARE_MISSING 63
#define ERROR_SOME_USER_SETTINGS_FILES_ARE_CORRUPTED 64
#define ERROR_WRONG_PASSWORD 50

#define WRONG_PASSWORD 92
#define WRONG_USERNAME 42

RTC_DS1307 RTC;

TMRpcm Audio;


const int SDPin = 53;
File Temp;
String Path;

int IntegerCommonVariable[12];
String StringCommonVariable[3] = {"", ""};

unsigned int CFrequency = 262;
byte CMIDI = 60;

unsigned int SpeakerPin = 11;

String Value;
String UARTPort;

byte KBCPin = 3;
byte KBDPin = 8;
byte KBLayout = 33; //44 -> UK, 1 -> USA, 49 -> Germnay, 34 -> Spain, 39 -> Italy, 33 -> France

PS2Keyboard Keyboard;

String User = "";
String Password = "";


bool MIDIOutEnable = false;
bool MIDIInEnable = false;

bool KBEnable = false;

byte TBApp[7] = {255, 255, 255, 255, 255, 255, 255};
byte TBIcon[7] = {10, 10, 10, 10, 10, 10, 10};

byte LastPage = 0;
byte CurrentPage = 0;

byte MAC[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAdress IP(192,168,0,254);
EthernetClient Client;
char server[30] = "*";
char path[60] = "";
char url[90] = "";

struct cacheStruct {
  uint8_t    pagePtr, lastPage;                 // Pointers to current and last page indexed
  uint16_t  index[PAGEINDEXSIZE];               // File page index pointers
  uint8_t   pageState[PAGEINDEXSIZE];           // Initial tag state for page e.g. in a <strong>
};

cacheStruct textContent = {
  0, 0, false };

struct linkStruct {
  uint8_t    linkPtr, lastLink;                  // Pointers to current and last link indexed
  uint16_t   index[LINKINDEXSIZE];               // Link
};
linkStruct pageLinks = {
  0, 0 };

LCD tftLCD = LCD (320, 240);                      // LCD object instance

uint16_t lowestRAM = 2000;                        // Keeps tabs for low memoery alerts

uint8_t command = 6;                              // Initial browser command to display the homepage                         // Input joystick positions
uint8_t generalBuffer[55];

//================================================
// CPU hard reset
//================================================
void (* resetFunc) (void) = 0;                    //declare reset function at address 0


void setup() {

  for (int i = 0; i < 27; i++) {
    IntegerCommonVariable[i] = 0;
  }
  //Serial Initialisation//
  Serial.begin(57600);
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
  Serial.println(F("|| > Starting Galax OS ...                                                    ||"));
  Serial.println(F("|| > Mount The SD Card ...                                                    ||"));

  Audio.speakerPin = SpeakerPin;

  if (!SD.begin(SDPin)) {
    Serial.println(F("|| > Warning : The SD Card isn't mounted.                                     ||"));
  }
  else {
    Serial.println(F("|| > The SD Card is mounted.                                                  ||"));
  }
  Serial.println(F("|| > Loading Task ...                                                         ||"));

  Serial.println(F("|| > Waiting for Display ...                                                  ||"));



}

void loop() {
}

void serialEvent1() {
  Serial.println(F("|| > Incoming Data On UART 1                                                  ||"));
  byte i = 1;
  char RX1Data[47];

  while (Serial1.available() && i < 47) {
    RX1Data[i] = char(Serial1.read());
    Serial.println(RX1Data[i]);
    i++;
  }

  byte NextTypeInst = 0;
  byte SelectedVariable = 0;
  char NextCharInst[14] = "";
  String NextStrnInst = "";

  Serial.println("|| > Reading Incoming Data On UART 1 - Step 2                                 ||");

  switch (RX1Data[1]) {
    case 0x66 :
      NextTypeInst = 10;
      Clock_Refresh();
      return;
      break;
    case 0x71 : NextTypeInst = 2;
      LastPage = CurrentPage;
      CurrentPage = RX1Data[2];
      return;
      break;
    default : break;
  }
  switch (RX1Data[2]) {
    case 0x2A : NextTypeInst = 1; break; //*
    case 0x2F : NextTypeInst = 6; break; ///
    default :
      if (isUpperCase(RX1Data[2])) {
        SelectedVariable = RX1Data[2];
        SelectedVariable -= 65;
        return;
      }
      else if (isLowerCase(RX1Data[2])) {
        SelectedVariable = RX1Data[2];
        SelectedVariable -= 96;
        NextTypeInst = 3;
      }
      else {
        break;
      }
  }
  for (int i = 3; i < 47; i++) {
    if (RX1Data[i] != -1) {
      NextStrnInst += RX1Data[i];
    }
    else {
      break;
    }

  }
  Serial.println(NextStrnInst);

  Serial.println(F("|| > Execute Incoming Data On UART 1 - Step 4                                 ||"));

  NextStrnInst.toCharArray(NextCharInst, 15);

  Serial.println(NextStrnInst);
  Serial.println(NextTypeInst);

  switch (NextTypeInst) {
    case 1:
      Serial.println(F("Command"));
      //*->Command//
      if (NextStrnInst == "Ready") Ready();

      else if (NextStrnInst == "TBItem1") NextionSerial("", 6, "", TBApp[0]);
      else if (NextStrnInst == "TBItem2") NextionSerial("", 6, "", TBApp[1]);
      else if (NextStrnInst == "TBItem3") NextionSerial("", 6, "", TBApp[2]);
      else if (NextStrnInst == "TBItem4") NextionSerial("", 6, "", TBApp[3]);
      else if (NextStrnInst == "TBItem5") NextionSerial("", 6, "", TBApp[4]);
      else if (NextStrnInst == "TBItem6") NextionSerial("", 6, "", TBApp[5]);
      else if (NextStrnInst == "TBItem7") NextionSerial("", 6, "", TBApp[6]);

      else if (NextStrnInst == "LoadSystem") LoadSystemFile();
      else if (NextStrnInst == "LoadUser") LoadUserFile();

      else if (NextStrnInst == "ChckPsswd") CheckPassword(StringCommonVariable[1], StringCommonVariable[2]);
      else if (NextStrnInst == "GoodPswd") Logon();

      else if (NextStrnInst == "Menu") NextionSerial(F("USERNAME_TXT"), 0, User, 0);
      else if (NextStrnInst == "Desk") Desk();

      else if (NextStrnInst == "USRF") UltraSonic(IntegerCommonVariable[0], IntegerCommonVariable[1]);

      else if (NextStrnInst == "Periodic_Main") Periodic_Main(IntegerCommonVariable[0], IntegerCommonVariable[1], 1);
      else if (NextStrnInst == "Periodic_Data") Periodic_Main(IntegerCommonVariable[0], IntegerCommonVariable[1], 2);

      else if (NextStrnInst == "ClckRfrs") Clock_Refresh();
      else if (NextStrnInst == "Clock") Clock();
      else if (NextStrnInst == "SetHour") SetHour(IntegerCommonVariable[0], IntegerCommonVariable[1]);
      else if (NextStrnInst == "SetDate") SetDate(IntegerCommonVariable[0], IntegerCommonVariable[1], IntegerCommonVariable[2]);

      else if (NextStrnInst == "AnlgRead") Analog_Read();
      else if (NextStrnInst == "AnlgWrit") Analog_Write(IntegerCommonVariable[0], IntegerCommonVariable[1]);
      else if (NextStrnInst == "DgtlWrit") Digital_Write(IntegerCommonVariable[0], IntegerCommonVariable[1]);

      else if (NextStrnInst == "SetPsswrd") SetPassword(StringCommonVariable[1], StringCommonVariable[2]);
      else if (NextStrnInst == "SetUsrnm") SetUsername(StringCommonVariable[1], StringCommonVariable[2]);

      else if (NextStrnInst == "SetKBDP") {
        KBDPin = IntegerCommonVariable[0];
        SetKeyboard();
      }
      else if (NextStrnInst == "SetKBCP2") {
        KBCPin = 2;
        SetKeyboard();
      }
      else if (NextStrnInst == "SetKBCP3") {
        KBCPin = 3;
        SetKeyboard();
      }
      else if (NextStrnInst == "SetKBCP18") {
        KBCPin = 18;
        SetKeyboard();
      }
      else if (NextStrnInst == "SetKBCP19") {
        KBCPin = 19;
        SetKeyboard();
      }
      else if (NextStrnInst == "SetKBCP20") {
        KBCPin = 20;
        SetKeyboard();
      }
      else if (NextStrnInst == "SetKBCP21") {
        KBCPin = 21;
        SetKeyboard();
      }
      else if (NextStrnInst == "SetKBL1") {
        KBLayout = 1;
        SetKeyboard();
      }
      else if (NextStrnInst == "SetKBL33") {
        KBLayout = 33;
        SetKeyboard();
      }
      else if (NextStrnInst == "SetKBL34") {
        KBLayout = 34;
        SetKeyboard();
      }
      else if (NextStrnInst == "SetKBL39") {
        KBLayout = 39;
        SetKeyboard();
      }
      else if (NextStrnInst == "SetKBL44") {
        KBLayout = 44;
        SetKeyboard();
      }
      else if (NextStrnInst == "SetKBL49") {
        KBLayout = 49;
        SetKeyboard();
      }

      else if (NextStrnInst == "EnMIDIOut") MIDIOutEnable = true;
      else if (NextStrnInst == "DiMIDIOut") MIDIOutEnable = false;
      else if (NextStrnInst == "EnMIDIIn") MIDIInEnable = true;
      else if (NextStrnInst == "DiMIDIIn") MIDIInEnable = false;
      else if (NextStrnInst == "EnKBIn") KBEnable = true;
      else if (NextStrnInst == "DisKBIn") KBEnable = false;

      else if (NextStrnInst == "CLow") Piano(0, 0);
      else if (NextStrnInst == "C#Low") Piano(16, 1);
      else if (NextStrnInst == "DLow") Piano(32, 2);
      else if (NextStrnInst == "D#Low") Piano(50, 3);
      else if (NextStrnInst == "ELow") Piano(68, 4);
      else if (NextStrnInst == "FLow") Piano(88, 5);
      else if (NextStrnInst == "F#Low") Piano(108, 6);
      else if (NextStrnInst == "GLow") Piano(130, 7);
      else if (NextStrnInst == "G#Low") Piano(154, 8);
      else if (NextStrnInst == "ALow") Piano(178, 9);
      else if (NextStrnInst == "A#Low") Piano(205, 10);
      else if (NextStrnInst == "BLow") Piano(232, 11);
      else if (NextStrnInst == "CHigh") Piano(262, 12);
      else if (NextStrnInst == "C#High") Piano(293, 13);
      else if (NextStrnInst == "DHigh") Piano(326, 14);
      else if (NextStrnInst == "D#High") Piano(361, 15);
      else if (NextStrnInst == "EHigh") Piano(398, 16);
      else if (NextStrnInst == "FHigh") Piano(437, 17);
      else if (NextStrnInst == "F#High") Piano(478, 18);
      else if (NextStrnInst == "GHigh") Piano(522, 19);
      else if (NextStrnInst == "G#High") Piano(569, 20);
      else if (NextStrnInst == "AHigh") Piano(618, 21);
      else if (NextStrnInst == "A#High") Piano(670, 22);
      else if (NextStrnInst == "BHigh") Piano(726, 23);

      else if (NextStrnInst == "Pause") Audio.pause();
      else if (NextStrnInst == "Mute") Audio.setVolume(0);
      else if (NextStrnInst == "Unmute") Audio.setVolume(1);
      else if (NextStrnInst == "StopMusic") Audio.disable();
      else if (NextStrnInst == "Resume") Music_Player(IntegerCommonVariable[0], "");
      else if (NextStrnInst == "Tone") tone(IntegerCommonVariable[1], IntegerCommonVariable[0]);
      else if (NextStrnInst == "NoTone") tone(IntegerCommonVariable[1], IntegerCommonVariable[0]);
      else if (NextStrnInst == "FGSave") Save(StringCommonVariable[1], F("FG"));

      else if (NextStrnInst == "TinyBasic") TinyBasic();

      else if (NextStrnInst == "KB47") KBA(47);

      else if (NextStrnInst == "CardInfo") CardInformation();

      /*else if (NextStrnInst == "iGOSConnect") iGOS_Connect();
      else if (NextStrnInst == "iGOSUp") iGOS(1);
      else if (NextStrnInst == "iGOSDown") iGOS(2);
      else if (NextStrnInst == "iGOSRight") iGOS(3);
      else if (NextStrnInst == "iGOSLeft") iGOS(4);*/


      else Serial.print(F("Unknow Command"));
      break;

    case 2:
      Serial.print(F("Selected Variable :"));
      Serial.println(SelectedVariable);
      Serial.println(F("Integer (Byte)"));
      //#->Integer Variable//
      IntegerCommonVariable[SelectedVariable] = RX1Data[3];

      break;

    case 3:
      Serial.print(F("Selected Variable :"));
      Serial.println(SelectedVariable);
      Serial.println("String");
      //$->String Variable//
      StringCommonVariable[SelectedVariable] = NextStrnInst;

      break;

    case 6:
      Serial.println("Files&dFolders Search");
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
  return;
}

void NextionSerial(String Item, byte Type, String StringData, int IntegerData) {
  switch (Type) {
    case 0: //.txt for Text & Scrolling Text, QRCode, Button, DualStateButton //

      Serial1.print(Item);
      Serial1.print(F(".txt="));
      Serial1.write(0x22);
      Serial1.print(StringData);
      Serial1.write(0x22);
      break;

    case 1://.val for Number,Progress Bar & Slider, Variable//

      Serial1.print(Item);
      Serial1.print(F(".val="));
      Serial1.print(IntegerData);
      break;

    case 2://.tim for Timer//

      Serial1.print(Item);
      Serial1.print(F(".tim="));
      Serial1.print(IntegerData);
      break;

    case 3://Page text//

      Serial1.print(F("page "));
      Serial1.print(Item);
      break;

    case 4://Picture

      Serial1.print(Item);
      Serial1.print(F(".pic="));
      Serial1.print(IntegerData);
      break;

    case 5://Timer enable

      Serial1.print(Item);
      Serial1.print(F(".en="));
      Serial1.print(IntegerData);
      break;

    case 6: //page PID//
      byte PID;
      PID = IntegerData;
      Serial1.print(F("page "));
      Serial1.print(PID);
      break;

    case 7://click

      Serial1.print(F("click "));
      Serial1.print(Item);
      Serial1.write(0x2C);
      Serial1.print(IntegerData);
      break;

  }

  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);
  return;
}

void Nexiton_Update() {
  Serial1.print(F("  DRAKJHSUYDGBNCJHGJKSHBDNÿÿÿ"));
  Serial1.print(F("  connectÿÿÿ"));
  Serial1.print(F("  ÿÿconnectÿÿÿ"));
  Serial1.print(F("whmi-wri filesize,115200,res0ÿÿÿ"));
}

void Periodic_Main (int Tch0, int Tch1, byte Type) {
  int Round;
  String Temporary;
  float Column;
  float Line;
  String Item = "";
  String Data = "";

  Column = Tch0;
  Column -= 5;
  Column *= 18;
  Column /= 468;
  Column += 0.5;

  Column = round(Column);

  Line = Tch0;
  Line -= 28;
  Line *= 9;
  Line /= 234;
  Line += 0.5;

  Line = round(Line);

  Path = "/SOFTWARE/" + String(Column, DEC) + "/" + String(Line, DEC) + ".CSV";
  Temp.open(Path);

  if (Temp) {
    while (Temp.available()) {
      while (Temp.peek() != 59) {
        Item += Temp.read();
      }
      while (!isAlphaNumeric(Temp.peek())) {
        Temp.read();
      }
      while (Temp.peek() != 13 || Temp.peek() != 10) {
        Data += Temp.read();
      }
      while (!isAlphaNumeric(Temp.peek())) {
        Temp.read();
      }
      if (Type == 1) {
        if (Item == "Name") {
          Temporary = "Name : " + Data;
          NextionSerial(F("NAME_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Number") {
          Temporary = "Number : " + Data;
          NextionSerial(F("NUMBER_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Mass") {
          Temporary = "Mass : " + Data + " u";
          NextionSerial(F("MASS_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Category") {
          Temporary = "Category : " + Data;
          NextionSerial(F("CATEGORY_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Symbol") {
          Temporary = "Symbol : " + Data;
          NextionSerial(F("SYMBOL_TXT"), 0, Temporary, 0);
        }
        else {
          return;
        }
      }
      if (Type == 2) {
        if (Item == "Name") {
          Temporary = "Name : " + Data;
          NextionSerial(F("NAME_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Number") {
          Temporary = "Number : " + Data;
          NextionSerial(F("NUMBER_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Mass") {
          Temporary = "Mass : " + Data + " u";
          NextionSerial(F("MASS_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Category") {
          Temporary = "Category : " + Data;
          NextionSerial(F("CATEGORY_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Symbol") {
          Temporary = "Symbol : " + Data;
          NextionSerial(F("SYMBOL_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Category") {
          Temporary = "Symbol : " + Data;
          NextionSerial(F("SYMBOL_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Protons") {
          Temporary = "Protons : " + Data;
          NextionSerial(F("PROTONS_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Neutrons") {
          Temporary = "Neutrons : " + Data;
          NextionSerial(F("NEUTRONS_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Electrons") {
          Temporary = "Electron Configuration : " + Data;
          NextionSerial(F("ELECTRONS_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Electronegativity") {
          Temporary = "Electronegativity : " + Data;
          NextionSerial(F("ELECTRO_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Phase At STP") {
          Temporary = "Phase At STP : " + Data;
          NextionSerial(F("PHASE_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Fusion Point") {
          Temporary = "Fusion Point : " + Data;
          NextionSerial(F("FUSION_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Boiling Point") {
          Temporary = "Boiling Point : " + Data;
          NextionSerial(F("BOILING_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Discover") {
          Temporary = "Discover : " + Data;
          NextionSerial(F("DISCOVER_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Density") {
          Temporary = "Density : " + Data;
          NextionSerial(F("DENSITY_TXT"), 0, Temporary, 0);
        }
        else if (Item == "Ionization") {
          Temporary = "Iozination : " + Data;
          NextionSerial(F("IONIZATION_TXT"), 0, Temporary, 0);
        }
        else {
          return;
        }
      }
    }
    return;
  }
}

void MDI () {
  Serial.println("MDI");
  int Frequency;
  int Duration;
  Temp = SD.open(Path);
  if (!Temp) {
    Serial.println("Can't open file");
    return;
  }
  while (Temp.available()) {
    Frequency = Temp.read();
    Frequency *= 256;
    Frequency += Temp.read();
    Frequency += CFrequency;

    Duration = Temp.read();
    Duration *= 256;
    Duration += Temp.read();

    tone(SpeakerPin, Frequency);
    delay(Duration);
    noTone(SpeakerPin);
  }
  Temp.close();
  return;
}

int LoadSystemFile() {
  Temp = SD.open("/GALAXOS.GSF");
  StringCommonVariable[1] = "";
  if (Temp) {
    while (Temp.available() && Temp.peek() != 10 && Temp.peek() != 13) {
      StringCommonVariable[1] += Temp.read();
    }
    Serial.print(StringCommonVariable[1]);
    if (StringCommonVariable[1] != "Galax OS Embeded Edition For Arduino Mega 2560 Version Alpha 0.12") {
      Serial.print("Error :");
      Serial.println(ERROR_SOME_SYSTEM_FILES_ARE_CORRUPTED);
      return ERROR_SOME_SYSTEM_FILES_ARE_CORRUPTED;
    }
  }
  else {
    Serial.print("Error :");
    Serial.println(ERROR_SOME_SYSTEM_FILES_ARE_MISSING);
    return ERROR_SOME_SYSTEM_FILES_ARE_MISSING;
  }
  StringCommonVariable[1] = "";
  return;

  NextionSerial("LOAD_TXT", 0, "Loading System Files ...", 0);
  NextionSerial("LOAD_TIM", 2, "", 50);

}

int LoadUserFile() {

  NextionSerial("Load_User", 3, "", 0);
  //Taskbar
  Path = "/USERS/" + User + "/STTNGS/TASKBAR.GSF";
  Temp = SD.open(Path);
  byte i = 0;
  while (Temp.available()) {
    TBApp[i] = Temp.read();
    Temp.read();
    //if(Temp.read() != 124) Serial.print(ERROR_SOME_USER_SETTINGS_FILES_ARE_CORRUPTED);
    TBIcon[i] = Temp.read();
    Temp.read();
    Temp.read();
    i++;
  }
  Temp.close();

  Path = "/GALAXOS/SOUNDS/STARTUP.GMF";
  MDI();

  NextionSerial("LOAD_TIM", 2, "", 50);



}

void SetKeyboard() {
  Path = "/USER/" + User + "/STTNGS/KEYBOARD.GSF";
  Temp = SD.open(Path, FILE_WRITE);
  if (Temp) {
    Temp.write(KBCPin);
    Temp.write(0x7C);
    Temp.write(KBDPin);
    Temp.write(0x7C);
    Temp.write(KBLayout);
    Temp.write(0x0D);
    Temp.write(0x0A);
    Temp.close();
  }
  else { //if didn't open
    return;
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

  Serial1.print(F("LINE1_TXT.txt="));
  Serial1.write(0x22);
  Serial1.print(Line[1]);
  Serial1.write(0x22);
  Serial1.write(0xff);
  Serial1.write(0xff);
  Serial1.write(0xff);

  Serial1.print(F("LINE2_TXT.txt="));
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
          Desk();
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
        Desk();
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

void KBA(byte Application) {

  if (KBEnable == false) {
    return;
  }
  switch (KBLayout) { //Keyboard Layout
    case 1:
      Keyboard.begin(KBDPin, KBCPin, PS2Keymap_US);
    case 33:
      Keyboard.begin(KBDPin, KBCPin, PS2Keymap_French);
    case 34:
      Keyboard.begin(KBDPin, KBCPin, PS2Keymap_Spanish);
    case 39:
      Keyboard.begin(KBDPin, KBCPin, PS2Keymap_Italian);
    case 44:
      Keyboard.begin(KBDPin, KBCPin, PS2Keymap_UK);
    case 49:
      Keyboard.begin(KBDPin, KBCPin, PS2Keymap_German);
  }
  switch (Application) {
    case 48:
      while (!Serial1.available()) {
        if (Keyboard.available()) {
          char Entry = Keyboard.read();
          if (Entry == PS2_ENTER) NextionSerial(F("b210"), 7, "", 1);
          else if (Entry == PS2_HOME) Desk();
          else if (Entry == PS2_ESC) NextionSerial("loadpageid.val", 3, "", 0);
          else if (Entry == PS2_DELETE) NextionSerial("b200", 7, "", 1);
          else if (Entry == PS2_TAB) NextionSerial("b201", 7, "", 1);
          else if (isPrintable(Entry)) {
            Serial1.print("input.txt+=");
            Serial1.write(0x22);
            Serial1.print(Entry);
            Serial1.write(0x22);
            Serial1.write(0xff);
            Serial1.write(0xff);
            Serial1.write(0xff);
          }
          NextionSerial(F("show"), 0, F("input.txt"), 0);
        }
      }
    default:
      return;
  }
}

void Pictureader(String Filename) {

  NextionSerial("Pictviewer", 3, "", 0);
  NextionSerial("FILENAME_TXT", 0, Filename, 0);

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

void Hibernate () {
  NextionSerial("wup", 1, "", 0);
  NextionSerial("ussp", 1, "", 1);
  NextionSerial("sleep", 1, "", 1);
  /*power_spi_disable();
    power_timer0_disable();
    poser_timer1_disable();
    power_timer2_disable();
    power_twi_disable();
    set_sleep_mode(SLEEP_MODE_IDLE);*/
}

void Shutdown () {
  NextionSerial("sleep", 1, "", 1);
  //set_sleep_mode(SLEEP_MODE_PWR_DOWN);
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

    NextionSerial(F("PATH_TXT"), 0, Path, 0);

    for (int i = 1; i < 19; i++) {
      File ItemFile = Directory.openNextFile();
      if (! ItemFile) {
        Serial.println(F("|| No more item                                                               ||"));
        break;
      }

      Serial1.print("ITEM");
      Serial1.print(i);
      Serial1.print("_TXT.txt=");
      Serial1.write(0x22);
      Serial1.print(ItemFile.name());
      Serial1.write(0x22);
      Serial1.write(0xff);
      Serial1.write(0xff);
      Serial1.write(0xff);

      Serial.println(ItemFile.name());
      if (ItemFile.isDirectory()) {
        Serial1.print("ITEM");
        Serial1.print(i);
        Serial1.print("_BUT.pic=11");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
      }
      else {
        Serial1.print("ITEM");
        Serial1.print(i);
        Serial1.print("_BUT.pic=10");
        Serial1.write(0xff);
        Serial1.write(0xff);
        Serial1.write(0xff);
      }
      ItemFile.close();
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
    Serial.println(F("Extension :"));
    Serial.print(Extension);

    if (Extension == "WAV") Music_Player(0, StringFileName);
    if (Extension == "BMP") Pictureader(StringFileName);
    if (Extension == "GPF") {}
    if (Extension == "FPF") {
      NextionSerial(F("Func Generator"), 3, "", 0);
      NextionSerial(F("FGFN_TXT"), 0, StringFileName, 0);

      Temp = SD.open(Path);

      String Line = "";

      while (Temp.available()) {
        while (Temp.peek() != 10 && Temp.peek() != 13) {
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
  NextionSerial(F("Fileditor"), 3, "", 0);
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
    NextionSerial(F("Music Player"), 3, "", 0);
    NextionSerial(F("FILENAME_TXT"), 0, Filename, 0);
  }

  NextionSerial(F("TIMER_TIM"), 5, "", 1);
  char Temporary[Path.length() + 1];
  Path.toCharArray(Temporary, sizeof(Temporary));
  Audio.play(Temporary, Time);
}

void Ready() {
  Serial.println(F("|| > Ready.                                                                   ||"));
  NextionSerial(F("Logon"), 3, "", 0);
}

int CheckPassword(String Username, String PTC) {
  User = Username;
  Path = "/USERS/" + User + "/STTNGS/PASSWORD.GSF";
  Serial.println(Path);
  Temp = SD.open(Path);
  Password = "";
  if (Temp) {
    while (Temp.available()) {
      if (isAlphaNumeric(Temp.peek())) {
        Serial.println(Temp.peek());
        Password += char(Temp.read());
      }
      else {
        Temp.read();
      }
    }
    Serial.print(F("Password :"));
    Serial.println(Password);
    Temp.close();
  }
  else {
    Serial.println(F("Wrong Username"));
    NextionSerial(F("WRONG_TXT"), 0, F("Wrong Username !"), 0);
    return WRONG_USERNAME;
  }

  if (PTC == Password) {
    Serial.print(F("Good Password"));
    LoadUserFile();
  }
  else {
    NextionSerial(F("WRONG_TXT"), 0, F("Wrong Password !"), 0);
  }
  return;
}

void Desk() {
  NextionSerial(F("Desk"), 3, "", 0);
  delay(100);
  NextionSerial(F("ITEM1_PIC"), 4, "", TBIcon[0]);
  NextionSerial(F("ITEM2_PIC"), 4, "", TBIcon[1]);
  NextionSerial(F("ITEM3_PIC"), 4, "", TBIcon[2]);
  NextionSerial(F("ITEM4_PIC"), 4, "", TBIcon[3]);
  NextionSerial(F("ITEM5_PIC"), 4, "", TBIcon[4]);
  NextionSerial(F("ITEM6_PIC"), 4, "", TBIcon[5]);
  NextionSerial(F("ITEM7_PIC"), 4, "", TBIcon[6]);
  return;
}

void Logon() {
  Serial.println(F("|| > Good Pin Code                                                            ||"));
  Serial.println(F("|| > Loading Session ...                                                      ||"));

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
  return;
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
  return;
}

void Digital_Read() {
  Serial.println(F("|| > Open Arduino Digital Read App                                            ||"));
  while (Serial1.available() == 0)  {
    for (int i = 0; i < 16; i++) {

    }
  }
  Serial.println(F("|| > Close Arduino Analog Read App                                           ||"));
  return;
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
  return;
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
      int Distance = Time * SOUND_SPEED;
      Serial.println("|| > Distance :");
      Serial.print(Distance);
      NextionSerial(F("DISTVAL_NUM"), 1, "", Distance);
      delay(100);
    }
  }
  Serial.println(F("|| > Close UltraSonic Rangefinder App                                        ||"));
  return;
}

int freeRam() {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

void CardInformation() {
  string Temporary = "";
  SdVolume CardVolume;
  Sd2Card Card;
  uint32_t VolumeSize;

  switch (Card.type()) {
    case SD_CARD_TYPE_SD1:
      Temporary = "Card Type : SD1";
      NextionSerial(F("CT_TXT"), 0, Temporary, 0);
      break;
    case SD_CARD_TYPE_SD2:
      Temporary = "Card Type : SD2";
      NextionSerial(F("CT_TXT"), 0, Temporary, 0);
      break;
    case SD_CARD_TYPE_SDHC:
      Temporary = "Card Type : SDHC";
      NextionSerial(F("CT_TXT"), 0, Temporary, 0);
      break;
    default:
      Temporary = "Card Type : Unknow";
      NextionSerial(F("CT_TXT"), 0, Temporary, 0);
      break;
  }

  Temporary = "Main Partition : FAT" + CardVolume.fatType();
  NextionSerial(F("MP_TXT"), 0, Temporary, 0);

  VolumeSize = CardVolume.blocksPerCluster();
  VolumeSize *= CardVolume.clusterCount();
  VolumeSize *= 512;
  VolumeSize /= 1024;
  VolumeSize /= 1024;

  Temporary = "Size :" + String(VolumeSize, DEC) + " MB";
  NextionSerial(F("SIZE_TXT"), 0, Temporary, 0);

  return;
}

void Piano(int Frequency, int Note) {
  string Temporary = "";
  unsigned long Duration = 200;
  Frequency += CFrequency;
  Note += CMIDI;
  Temporary = "Frequency : " + String(Frequency, DEC);
  NextionSerial(F("FREQUENCY_TXT"), 1, "", Temporary);
  Temporary = "MIDI Code : " + String(Note, DEC);
  NextionSerial(F("MIDICODE_TXT"), 1, "", Temporary);
  tone(SpeakerPin, Frequency, Duration);
  if (MIDIOutEnable == true) {
    Serial.write(144);
    Serial.write(Note);
    Serial.write(128);
    delay(Duration);
    Serial.write(128);
    Serial.write(Note);
    Serial.write(128);
  }
  return;
}

void SetPassword(String PTC, String NewPassword) {
  if (PTC == Password) {
    Serial.println(F("|| > Set The New Password In The SD Card ...                                 ||"));
    Serial.println(Password);
    SD.remove("/GALAXOS/USER/PASSWORD.GSF");
    Temp = SD.open("/GALAXOS/USER/PASSWORD.GSF", FILE_WRITE);
    Temp.println(Password);
    Temp.close();
    Serial.println(F("|| > Done.                                                                   ||"));
  }
  else {
    return;
  }
  return;
}

void SetUsername(String PTC, String Username) {
  if (PTC == Password) {
    Serial.println(F("|| > Set The New Username In The SD Card ...                                 ||"));
    Serial.println(Username);
  }
  return;
}

void Arduino_UART(int Serial, int Baudrate, String TXData) {
  switch (Serial) {
    case 2:
      Serial2.begin(Baudrate);
      Serial2.print(TXData);
      break;
    case 3:
      Serial3.begin(Baudrate);
      Serial3.print(TXData);
      break;
    default :
      break;
  }
  return;
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

String TinyBasic_RE(String CopyLine) {
  char Command[sizeof(CopyLine) + 1];
  String Keyword = "";
  String Argument[3] = {"", "", ""};
  int IntegerArgument[3] = {0, 0, 0};
  char TypeArgument[4] = {'\0', '\0', '\0'};
  byte i = 0;
  byte AmountArguments = 0;

  //Read
  for (int ii = 0; ii < 4; i++) {
    if (Command[i] == '\0') break;
    if (ii == 0) {
      while (Command[i] != 47) {
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
        while (Command[i] != 39) {
          Argument[ii] += Command[i];
          i++;
        }
      }
      else if (isDigit(Command[i])) {
        TypeArgument[ii] == '#';
        while (isDigit(Command[i])) {
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
  if (Keyword == "PRINT") {

    if (AmountArguments == 1) {
      if (TypeArgument[1] == '$' | TypeArgument[i] == '#') {
        ToPrint = Argument[1];
      }
      else if (isUpperCase(TypeArgument[1])) {
        ToPrint = IntegerCommonVariable[TypeArgument[1] - 64];
      }
      else {
        ToPrint = F("Invalid Argument");
      }
    }
    else if (AmountArguments > 2) {
      if (TypeArgument[1] == '$' & TypeArgument[3] == '$') {
        ToPrint = Argument[1] + Argument[3];
      }
      else {
        if (isUpperCase(TypeArgument[1])) {
          IntegerArgument[1] = IntegerCommonVariable[TypeArgument[1] - 64];
        }
        if (isUpperCase(TypeArgument[3])) {
          IntegerArgument[3] = IntegerCommonVariable[TypeArgument[3] - 64];
        }
        if (Argument[2] == "+") {
          IntegerArgument[2] = IntegerArgument[1] + IntegerArgument[3];
        }
        else if (Argument[2] == "-") {
          IntegerArgument[2] = IntegerArgument[1] - IntegerArgument[3];
        }
        else if (Argument[2] == "*") {
          IntegerArgument[2] = IntegerArgument[1] * IntegerArgument[3];
        }
        else if (Argument[2] == "/") {
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
