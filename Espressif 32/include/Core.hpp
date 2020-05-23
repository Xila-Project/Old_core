#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#include "Arduino.h"
#include "SD_MMC.h"
#include "FS.h"
#include "time.h"

#include "GalaxOS.hpp"
#include "Igos.hpp"
#include "Software.hpp"
#include "Periodic.hpp"
#include "File_Manager.hpp"
#include "Calculator.hpp"
#include "Piano.hpp"
#include "Ultrasonic.hpp"
#include "Signal_Generator.hpp"
#include "Paint.hpp"
#include "Display.hpp"

//----------------------------------------------------------------------------//
//                                        Define Const                        //
//----------------------------------------------------------------------------//

#define PAGE_SPLASH_A 0
#define PAGE_SPLASH_B 1
#define PAGE_ARDUINO_HOME 2

#define SOUND_SPEED_AIR 343

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

#define ERROR_CANNOT_WRITE_DATA_TO_DISK_RAM 8942

#define INFORMATION_GOOD_CREDENTIALS 39548

#define WARNING_WRONG_PASSWORD 28364
#define WARNING_WRONG_USERNAME 54112
#define WARNING_DO_YO_REALLY_WANT_TO_DELETE_THIS_ITEM 43345

#define STYLE_LEFT_ALIGNMENT 0
#define STYLE_CENTER_ALIGNMENT 1
#define STYLE_RIGHT_ALIGNMENT 2
#define STYLE_JUSTIFIED_ALIGNMENT 3

#define CODE_COMMAND 42
#define CODE_SOFTWARE_OPEN 111 //o
#define CODE_SOFTWARE_CLOSE 99 //c
#define CODE_COMMAND_NEW 35
#define CODE_VARIABLE_BYTE 66              //1 byte
#define CODE_VARIABLE_CHAR 67              //unsigned 1 byte
#define CODE_VARIABLE_INTEGER 73           //2 byte
#define CODE_VARIABLE_UNSIGNED_INTEGER 105 //unsigned 2 byte
#define CODE_VARIABLE_FLOAT 70             //4 byte float
#define CODE_VARIABLE_LONG 76              //4 byte
#define CODE_VARIABLE_UNSIGNED_LONG 108    //unsigned 4 byte
#define CODE_VARIABLE_STRING 83

#define SOFTWARE_IGOS_ID 73 //random number for ID
#define SOFTWARE_FILE_MANAGER_ID 45 

#define IGOS_ICON 10

//----------------------------------------------------------------------------//
//                                        Define  Communication               //
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
//                                        Define Tasks                        //
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
//                            Define Class                                    //
//----------------------------------------------------------------------------//


class GalaxOS_Class
{
private:
    File Temporary_File;

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

    Nextion_Display_Class Display;
    
    iGOS_Class *iGOS_Pointer;
    Periodic_Class *Periodic_Pointer;
    File_Manager_Class *File_Manager_Pointer;
    Ultrasonic_Class *Ultrasonic_Pointer;
    Calculator_Class *Calculator_Pointer;
    Paint_Class *Paint_Pointer;
    Piano_Class *Piano_Pointer;
    Signal_Generator_Class *Signal_Generator_Pointer;
    //Music_Player_Class *Music_Player_Pointer;
    //Pong_Class *Pong_Class;

    uint8_t Event_Reply;

    GalaxOS_Software_Class *Software_Pointer[4];

    char Tag;

    struct tm Time;

    char WiFi_SSID[20];
    char WiFi_Password[20];

    xTaskHandle Nextion_Serial_Receive_Handle;

    xTaskHandle Ressource_Monitor_Handle;
    xTaskHandle GalaxOS_Core_Handle;

public:

    GalaxOS_Class();

    ~GalaxOS_Class();

    void Update_From_SD();

    void Open_Software(uint8_t const &Software_ID);
    void Close_Software(uint8_t const &Software_ID);

    void Incomming_String_Data_From_Display(String const& Received_Data);
    void Incomming_Numeric_Data_From_Display(uint32_t const& Received_Data);
    void Incomming_Event_From_Display(uint16_t);

    void Horizontal_Seperator();
    //void Print(const __FlashStringHelper* String_To_Print);

    byte Get_Speaker_Pin();
    int Get_C_Frequency();
    byte Get_C_MIDI();

    void Set_Software_Pointer(byte const &Software_Pointer_ID, GalaxOS_Software_Class &Software_Pointer_To_Set);

    void Get_Software_Pointer(iGOS_Class*& Software_Pointer_To_Set);
    void Get_Software_Pointer(Periodic_Class*& Software_Pointer_To_Set);
    void Get_Software_Pointer(File_Manager_Class*& Software_Pointer_To_Set);
    void Get_Software_Pointer(Calculator_Class*& Software_Pointer_To_Set);
    void Get_Software_Pointer(Signal_Generator_Class*& Software_Pointer_To_Set);

    void Synchronise_Time();

    void Start();

    void Set_Variable(char const &Tag, String const &String_To_Set);
    void Get_Variable(char const &Tag, String &String_To_Get);

    void Set_Variable(char const &Tag, char const &Char_To_Set);
    void Get_Variable(char const &Tag, char &Char_To_Get);

    void Set_Variable(char const &Tag, byte const &Byte_To_Set);
    void Get_Variable(char const &Tag, byte &Byte_To_Get);

    void Set_Variable(char const &Tag, int const &Integer_To_Set);
    void Get_Variable(char const &Tag, int &Integer_To_Get);

    void Set_Variable(char const &Tag, long const &Long_To_Set);
    void Get_Variable(char const &Tag, long &Long_To_Get);

    void Set_Variable(char const &Tag, float const &Float_To_Set);
    void Get_Variable(char const &Tag, float &Float_To_Get);

    void Data_File_Get_Key(String const &Path, char (&Key_Name)[], String &Key_Value_To_Get);
    void Data_File_Get_Key(const __FlashStringHelper* Path, const __FlashStringHelper* Key_Name, String &Key_Value_To_Get);

    void Open_File(String const& File_Path_To_Open);

    void WiFi_Connect();

    void USB_Serial_Transmit(char const *USB_Serial_Transmit_String, byte Alignment);

    void Open_Desk();
    void Open_Menu();

    void Nextion_Serial_Transmit(String Component, byte Type, String Nextion_Serial_Transmit_String = "", int Nextion_Serial_Transmit_Integer = 0);

    void Load_System_Files();
    void Load_User_Files();

    uint16_t Check_Credentials(String const &Username_To_Check, String const &Password_To_Check);

    uint8_t Event_Handler(const uint16_t &Type);

    void Nextion_Upload_Firmware(String const &Path);

    //friend void Core ( void *pvParameters );
    friend void Nextion_Serial_Receive(void *pvParameters);
    friend void Ressource_Monitor(void *pvParameters);

    xTaskHandle Musical_Digital_Player_Handle;

    bool MIDIOutEnable = false;
};

//GalaxOS class's method (FreeRTOS seems to not support class/struct)
void Nextion_Serial_Receive(void *pvParameters);
void Ressource_Monitor(void *pvParameters);

void Musical_Digital_Player(void *pvParameters);

void Files_And_Folders();

void Periodic_Main(byte Type);
void Piano(int Frequency, int Note);
void Pictureader();

void UltraSonic(int USTrig, int USEcho);

#endif