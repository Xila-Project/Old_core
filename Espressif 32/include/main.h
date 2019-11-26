#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "Arduino.h"
#include <string>

//----------------------------------------------------------------------------//
//                                        Define Const                        //
//----------------------------------------------------------------------------//

#define SOUND_SPEED_AIR 343
#define LIGHT_SPEED_AIR 299792458

#define ATTRIBUTE_TXT 0
#define ATTRIBUTE_VAL 1
#define ATTRIBUTE_TIM 2
#define ATTRIBUTE_PIC 4
#define ATTRIBUTE_EN 5

#define COMMAND_PAGE_NAME 3
#define COMMAND_PAGE_ID 6
#define COMMAND_CLICK_ID 7

#define ERROR_FAILLED_TO_INTIALIZE_SD_CARD 10896
#define ERROR_SOME_SYSTEM_FILES_ARE_MISSING 49361
#define ERROR_SOME_SYSTEM_FILES_ARE_CORRUPTED 60041
#define ERROR_SOME_USER_SETTINGS_FILES_ARE_MISSING 25814
#define ERROR_SOME_USER_SETTINGS_FILES_ARE_CORRUPTED 12733
#define ERROR_THE_FILE_DOESNT_EXIST 7018

#define INFORMATION 17723

#define WARNING_WRONG_PASSWORD 28362
#define WARNING_WRONG_USERNAME 54114

#define STYLE_LEFT_ALIGNMENT 0
#define STYLE_CENTER_ALIGNMENT 1
#define STYLE_RIGHT_ALIGNMENT 2
#define STYLE_JUSTIFIED_ALIGNMENT 3


//----------------------------------------------------------------------------//
//                                        Define  Communication               //
//----------------------------------------------------------------------------//

HardwareSerial Nextion_Serial(2);

WiFiClient client;

byte Taskbar_Items_PID[7] = {255, 255, 255, 255, 255, 255, 255};
byte Taskbar_Items_Icon[7] = {10, 10, 10, 10, 10, 10, 10};

byte C_MIDI = 60;

int Public_Integer_Variable[12];

unsigned int C_Frequency = 262;

int Speaker_Pin = 25;

const char* WiFi_SSID     = "Avrupa";
const char* WiFi_Password = "0235745484";

char server[30] = "*";                         // THERE HAS TO BE A BETTER WAY OF SPLITTING A URL
char path[60] = "";                            // INTO PARTS USING VARIABLES - JUST TO PASS THE HTTP REQUEST
char url[90] = "";                           // What IS a reasonable maximum URL length?



String Public_String_Variable[3] = {"", "", ""};

String Temporary_File_Path = "NULL";

File Temporary_File;

String Temporary_File_Name = "NULL";

uint16_t Low_RAM_Threshold = 2000;

bool MIDIOutEnable = false;

String Username = "NULL";
String Password = "NULL";

//----------------------------------------------------------------------------//
//                                        Define Tasks                        //
//----------------------------------------------------------------------------//
xTaskHandle Nextion_Serial_Transmit_Handle;
xTaskHandle Musical_Digital_Player_Handle;
xTaskHandle Ressource_Monitor_Handle;
//----------------------------------------------------------------------------//
//                            Define Function                                 //
//----------------------------------------------------------------------------//
void Event_Handler(byte Type, String Informations);
void Files_And_Folders();
void Load_System_Files();
void Load_User_Files();
void Logon();
void Musical_Digital_Player( void *pvParameters );
void Nextion_Serial_Receive( void *pvParameters );
void Nextion_Serial_Transmit(String Component, byte Type, String Nextion_Serial_Transmit_String = "", int Nextion_Serial_Transmit_Integer = 0);
void Open_Desk();
void Open_Menu();
void Periodic_Main (byte Type);
void Piano(int Frequency, int Note);
void Pictureader();
void Ressource_Monitor( void *pvParameters );
void UltraSonic(int USTrig, int USEcho);
void USB_Serial_Transmit(const char* USB_Serial_Transmit_String);
void WiFi_Connect();

#endif