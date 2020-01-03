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
#define ERROR_THE_FILE_DO_NOT_EXIST 7018

#define INFORMATION 17723

#define WARNING_WRONG_PASSWORD 28362
#define WARNING_WRONG_USERNAME 54114
#define WARNING_DO_YO_REALLY_WANT_TO_DELETE_THIS_ITEM 43345

#define STYLE_LEFT_ALIGNMENT 0
#define STYLE_CENTER_ALIGNMENT 1
#define STYLE_RIGHT_ALIGNMENT 2
#define STYLE_JUSTIFIED_ALIGNMENT 3

#define MAXIMUM_POINTERS 26
//----------------------------------------------------------------------------//
//                                        Define  Communication               //
//----------------------------------------------------------------------------//

HardwareSerial Nextion_Serial(2);

int *Pointers_Global_Dynamic_Variable[MAXIMUM_POINTERS];

char server[30] = "*";                         // THERE HAS TO BE A BETTER WAY OF SPLITTING A URL
char path[60] = "";                            // INTO PARTS USING VARIABLES - JUST TO PASS THE HTTP REQUEST
char url[90] = "";                           // What IS a reasonable maximum URL length?

File Temporary_File;

String Temporary_File_Path = "NULL";

String Temporary_File_Name = "NULL";

bool MIDIOutEnable = false;



//----------------------------------------------------------------------------//
//                                        Define Tasks                        //
//----------------------------------------------------------------------------//
xTaskHandle Nextion_Serial_Transmit_Handle;
xTaskHandle Musical_Digital_Player_Handle;
xTaskHandle Ressource_Monitor_Handle;
//----------------------------------------------------------------------------//
//                            Define Function                                 //
//----------------------------------------------------------------------------//

void Files_And_Folders();

void Periodic_Main (byte Type);
void Piano(int Frequency, int Note);
void Pictureader();

void UltraSonic(int USTrig, int USEcho);


#endif