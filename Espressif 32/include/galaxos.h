#ifndef GALAXOS_H_INCLUDED
#define GALAXOS_H_INCLUDED

#include "Arduino.h"
#include "software.h"
#include "igos.h"

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

#define INFORMATION_GOOD_CREDENTIALS 39548

#define WARNING_WRONG_PASSWORD 28364
#define WARNING_WRONG_USERNAME 54112
#define WARNING_DO_YO_REALLY_WANT_TO_DELETE_THIS_ITEM 43345

#define STYLE_LEFT_ALIGNMENT 0
#define STYLE_CENTER_ALIGNMENT 1
#define STYLE_RIGHT_ALIGNMENT 2
#define STYLE_JUSTIFIED_ALIGNMENT 3

#define CODE_COMMAND 42
#define CODE_CONSTRUCT 99
#define CODE_DESTRUCT 100
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

WiFiClient client;



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
//                            Define Class                                    //
//----------------------------------------------------------------------------//

class Ultrasonic_Class //Application It self;
{
    private:
        byte Trig_Pin;
        byte Echo_Pin;

    public:
        Ultrasonic_Class();
        ~Ultrasonic_Class();
        void Set_Trig_Pin(byte const& Trig_Pin);
        void Set_Echo_Pin(byte const& Echo_Pin);
        void Read();
};


class GalaxOS_Class
{
    private:
    
        byte Taskbar_Items_PID[7];
        byte Taskbar_Items_Icon[7];

        byte Current_Page;
        byte Last_Page;

        byte C_MIDI;

        int C_Frequency;

        byte Speaker_Pin;

        String Username;
        String Password;

        int Low_RAM_Threshold;

        String Temporary_String;

        GalaxOS_Software_Class *Software_Pointer[4];
        Ultrasonic_Class *Ultrasonic_Pointer;
        iGOS_Class *iGOS_Pointer;


        union Temporary_Split_Integer_Union
        {
            int Integer;
            byte Byte[2];
        } Temporary_Split_Integer;

        union Temporary_Split_Float_Union
        {
            float Float;
            byte Byte[4];
        } Temporary_Split_Float;

        const char* WiFi_SSID     = "Avrupa";
        const char* WiFi_Password = "0235745484";

        uint16_t Cursor_X, Cursor_Y;

    public:

        GalaxOS_Class();

        ~GalaxOS_Class();

        byte Get_Speaker_Pin();
        int Get_C_Frequency();
        byte Get_C_MIDI();

        void Set_Software_Pointer(byte const& Software_Pointer_ID, GalaxOS_Software_Class const& Software_Pointer_To_Set);

        void Start();

        void Set(char const& Tag, String const& String_To_Set);
        void Get(char const& Tag, String& String_To_Get);

        void Set(char const& Tag, char const& Char_To_Set);
        void Get(char const& Tag, char& Char_To_Get);

        void Set(char const& Tag, byte const& Byte_To_Set);
        void Get(char const& Tag, byte& Byte_To_Get);

        void Set(char const& Tag, int const& Integer_To_Set);
        void Get(char const& Tag, int& Integer_To_Get);

        void Set(char const& Tag, float const& Float_To_Set);
        void Get(char const& Tag, float& Float_To_Get);

        //Nextion Screen Cursor for dynamic rendering
        uint16_t Get_Cursor_X();
        uint16_t Get_Cursor_Y();
        uint16_t Set_Cursor(uint16_t const& X_Coordinate, uint16_t const& Y_Coordinate);

        void WiFi_Connect();

        void USB_Serial_Transmit(char const* USB_Serial_Transmit_String, byte Alignment);

        void Open_Desk();
        void Open_Menu();
         
        void Nextion_Serial_Transmit(String Component, byte Type, String Nextion_Serial_Transmit_String = "", int Nextion_Serial_Transmit_Integer = 0);

        void Load_System_Files();
        void Load_User_Files();

        byte Check_Credentials(String const& Username_To_Check, String const& Password_To_Check);   

        void Event_Handler_Request(int Type, String Infromations);
        void Event_Handler_Reply(byte Reply);

        
        friend void Core ( void *pvParameters );
        friend void Nextion_Serial_Receive( void *pvParameters );
        friend void Ressource_Monitor ( void *pvParameters );
};







//GalaxOS class's method (FreeRTOS seems to not support class/struct)
void Nextion_Serial_Receive( void *pvParameters );
void Core( void *pvParameters );
void Ressource_Monitor( void *pvParameters );

void Musical_Digital_Player( void *pvParameters );

void Files_And_Folders();

void Periodic_Main (byte Type);
void Piano(int Frequency, int Note);
void Pictureader();

void UltraSonic(int USTrig, int USEcho);

GalaxOS_Class GalaxOS;

#endif