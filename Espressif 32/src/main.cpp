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
