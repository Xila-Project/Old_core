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
#define ERROR_CANNOT_CREATE_SYSTEM_QUEUE 17496
#define ERROR_NEXTION_INVALID_INTRUCTION 0
#define ERROR_NEXTION_INVALID_COMPONENT_ID 2
#define ERROR_NEXTION_INVALID_PAGE_ID 3
#define ERROR_NEXTION_INVALID_PICTURE_ID 4
#define ERROR_NEXTION_INVALID_FONT_ID 5
#define ERROR_NEXTION_INVALID_FILE_OPERATION 6
#define ERROR_NEXTION_INVALID_BAUD_RATE_SETTING 17
#define ERROR_NEXTION_INVALID_WAVEFORM_ID_OR_CHANNEL 18
#define ERROR_NEXTION_INVALID_VARIABLE_NAME_OR_ATTRIBUTE 26
#define ERROR_NEXTION_INVALID_VARIABLE_OPERATION 27
#define ERROR_NEXTION_FAIL_TO_ASSIGN 28
#define ERROR_NEXTION_FAIL_EEPROM_OPERATION 29
#define ERROR_NEXTION_INVALID_QUANTITY_OF_PARAMETERS 30
#define ERROR_NEXTION_IO_OPERATION_FAILED 31
#define ERROR_NEXTION_INVALID_ESCAPE_CHARACTER 32
#define ERROR_NEXTION_TOO_LONG_VARIABLE_NAME 35
#define ERROR_NEXTION_SERIAL_BUFFER_OVERFLOW 36

#define INFORMATION_NEXTION_STARTUP 0 //same as invalid instruction, only at startup
#define INFORMATION_NEXTION_INTRUCTION_SUCCESSFUL 1
#define INFORMATION_NEXTION_TOUCH_EVENT 101
#define INFORMATION_NEXTION_CURRENT_PAGE_NUMBER 102
#define INFORMATION_NEXTION_TOYCH_COORDINATE_AWAKE 103
#define INFORMATION_NEXTION_TOUCH_COOORDINATE_SLEEP 104
#define INFORMATION_NEXTION_STRING_DATA_ENCLOSED 112
#define INFORMATION_NEXTION_NUMERIC_DATA_ENCLOSED 113
#define INFORMATION_NEXTION_AUTO_ENTERED_SLEEP_MODE 134
#define INFORMATION_NEXTION_AUTO_WAKE_FROM_SLEEP_MODE 135
#define INFORMATION_NEXTION_READY 136
#define INFORMATION_NEXTION_START_UPGRADE_FROM_SD 137
#define INFORMATION_NEXTION_TRANSPARENT_DATA_FINISHED 253
#define INFORMATION_NEXTION_TRANSPARENT_DATA_READY 254

#define WARNING_WRONG_PASSWORD 28362
#define WARNING_WRONG_USERNAME 54114
#define WARNING_DO_YO_REALLY_WANT_TO_DELETE_THIS_ITEM 43345

#define STYLE_LEFT_ALIGNMENT 0
#define STYLE_CENTER_ALIGNMENT 1
#define STYLE_RIGHT_ALIGNMENT 2
#define STYLE_JUSTIFIED_ALIGNMENT 3

#define CODE_COMMAND 42
#define CODE_COMMAND_NEW 35
#define CODE_VARIABLE_BYTE 66 //1 byte
#define CODE_VARIABLE_CHAR 67 //1 byte
#define CODE_VARIABLE_INTEGER 73 //2 byte
#define CODE_VARIABLE_FLOAT 70 //4 byte
#define CODE_VARIABLE_LONG 76 //4 byte
#define CODE_VARIABLE_STRING 83
#define CODE_VARIABLE_UNSIGNED_INTEGER 105 //2 byte
#define CODE_VARIABLE_UNSIGNED_LONG 108 //4 byte
//----------------------------------------------------------------------------//
//                                        Define  Communication               //
//----------------------------------------------------------------------------//

HardwareSerial Nextion_Serial(2);

char server[30] = "*";                         // THERE HAS TO BE A BETTER WAY OF SPLITTING A URL
char path[60] = "";                            // INTO PARTS USING VARIABLES - JUST TO PASS THE HTTP REQUEST
char url[90] = "";                           // What IS a reasonable maximum URL length?

const char* WiFi_SSID     = "Avrupa";
const char* WiFi_Password = "0235745484";

File Temporary_File;

String Temporary_File_Path = "\0";

String Temporary_File_Name = "\0";

bool MIDIOutEnable = false;

//----------------------------------------------------------------------------//
//                                        Define Tasks                        //
//----------------------------------------------------------------------------//
xTaskHandle Nextion_Serial_Transmit_Handle;
xTaskHandle Musical_Digital_Player_Handle;
xTaskHandle Ressource_Monitor_Handle;
xTaskHandle GalaxOS_Core_Handle;

QueueHandle_t Nextion_Serial_Queue;
//----------------------------------------------------------------------------//
//                            Define Function                                 //
//----------------------------------------------------------------------------//

void Files_And_Folders();

void Periodic_Main (byte Type);
void Piano(int Frequency, int Note);
void Pictureader();

void UltraSonic(int USTrig, int USEcho);



class GalaxOS{
    
    public:

        static byte Taskbar_Items_PID[7];
        static byte Taskbar_Items_Icon[7];

        static byte Current_Page;
        static byte Last_Page;

        static byte C_MIDI;

        static int C_Frequency;

        static byte Speaker_Pin;

        static String Username;
        static String Password;

        static int Low_RAM_Threshold;

        static String Temporary_String;

        GalaxOS();

        static void Start();

        static void Set(char const& Tag, String const& String_To_Set);
        static void Get(char const& Tag, String& String_To_Get);

        static void Set(char const& Tag, char const& Char_To_Set);
        static void Get(char const& Tag, char& Char_To_Get);

        static void Set(char const& Tag, byte const& Byte_To_Set);
        static void Get(char const& Tag, byte& Byte_To_Get);

        static void Set(char const& Tag, int const& Integer_To_Set);
        static void Get(char const& Tag, int& Integer_To_Get);

        static void Set(char const& Tag, float const& Float_To_Set);
        static void Get(char const& Tag, float& Float_To_Get);

        static void WiFi_Connect();

        static void USB_Serial_Transmit(char const* USB_Serial_Transmit_String, byte Alignment);

        static void Open_Desk();
        static void Open_Menu();


        static void Musical_Digital_Player( void *pvParameters );
        static void Nextion_Serial_Receive( void *pvParameters );
        static void Nextion_Serial_Transmit(String Component, byte Type, String Nextion_Serial_Transmit_String = "", int Nextion_Serial_Transmit_Integer = 0);

        static void Load_System_Files();
        static void Load_User_Files();

        static byte Check_Credentials(String const& Username_To_Check, String const& Password_To_Check);

        static void Core( void *pvParameters );
        
        static void Ressource_Monitor( void *pvParameters );

        static void Event_Handler_Request(int Type, String Infromations);
        static void Event_Handler_Reply(byte Reply);

};



#endif