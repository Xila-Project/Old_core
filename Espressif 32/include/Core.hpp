#ifndef GALAXOS_CORE_H_INCLUDED
#define GALAXOS_CORE_H_INCLUDED

#include "Configuration.hpp"

//----------------------------------------------------------------------------//
//                          Include Necessary Libraries                       //
//----------------------------------------------------------------------------//

#include "Arduino.h"

#if SD_MODE == 0
#include "SD_MMC.h"
#include "FS.h"
#else
#include <SD.h>
#endif

#include "time.h"
#include "Update.h"
#include <ArduinoJson.h> //used to store
#include "WiFi.h"

//----------------------------------------------------------------------------//
//                          Include All Project File                          //
//----------------------------------------------------------------------------//

// Other part of the core
#include "Instruction.hpp"
#include "Software.hpp"

// Driver files
#include "Display.hpp"  // Nextion display driver (maybe create a library for each driver)
#include "Keyboard.hpp" // PS2 keyboard driver
#include "Sound.hpp"

//----------------------------------------------------------------------------//
//                                Define Const                                //
//----------------------------------------------------------------------------//

//
#define MAXIMUM_SOFTWARE 15

// Page ID Index
#define PAGE_SPLASH_A 0
#define PAGE_SPLASH_B 1
#define PAGE_ARDUINO_HOME 2
#define PAGE_DESK 19
#define PAGE_EVENT 20
#define PAGE_IGOS 27
#define PAGE_PIANO 38
#define PAGE_MENU_1

// Color

#define COLOR_DARK_GREY 16904
#define COLOR_LIGHT_GREY 33808
#define COLOR_WHITE 65535

// Event constant (used to interract with the event handler)

typedef uint16_t GalaxOS_Event;

// Errors
#define ERROR_FAILLED_TO_INTIALIZE_SD_CARD 10896
#define ERROR_SOME_SYSTEM_FILES_ARE_MISSING 49361
#define ERROR_SOME_SYSTEM_FILES_ARE_CORRUPTED 60041
#define ERROR_SOME_USER_SETTINGS_FILES_ARE_MISSING 25814
#define ERROR_SOME_USER_SETTINGS_FILES_ARE_CORRUPTED 12733
#define ERROR_THE_FILE_DO_NOT_EXIST 7018
#define ERROR_CANNOT_CREATE_SYSTEM_QUEUE 17496
#define ERROR_UNEXPECTED_RETURN_COMMAND 46201
#define ERROR_CANNOT_WRITE_DATA_TO_DISK_RAM 8942
#define ERROR_INVALID_SOFTWARE_ID 4562
#define ERROR_CANNOT_OPEN_REGISTRY_FILE 684
#define ERROR_REGISTRY_FILE_DOES_NOT_EXIST 8404
#define ERROR_TO_MUCH_OPENNED_SOFTWARE 7519

// Alignement
#define STYLE_LEFT_ALIGNMENT 0
#define STYLE_CENTER_ALIGNMENT 1
#define STYLE_RIGHT_ALIGNMENT 2
#define STYLE_JUSTIFIED_ALIGNMENT 3

// Nextion command
#define CODE_COMMAND 0x2A                   // * : Command
#define CODE_COMMAND_NEW 0x43               // # : Command
#define CODE_VARIABLE_BYTE_LOCAL 0x62       // b : 1 byte
#define CODE_VARIABLE_BYTE_GLOBAL 0x42      // B : 1 byte
#define CODE_VARIABLE_INTEGER_LOCAL 0x69    // i : 2 bytes
#define CODE_VARIABLE_INTEGER_GLOBAL 0x49   // I : 2 bytes
#define CODE_VARIABLE_LONG_GLOBAL 0x4C      // L : 4 bytes
#define CODE_VARIABLE_LONG_LOCAL 0x6C       // l : 4 bytes
#define CODE_VARIABLE_LONG_LONG_GLOBAL 0x48 // H : 8 bytes
#define CODE_VARIABLE_LONG_LONG_LOCAL 0x68  // h : 8 bytes
#define CODE_VARIABLE_STRING_GLOBAL 0x53    // S : String (undefined size)
#define CODE_VARIABLE_STRING_LOCAL 0x73     // s : String

//----------------------------------------------------------------------------//
//                         Define GalaxOS Core Class                          //
//----------------------------------------------------------------------------//


class GalaxOS_Class
{
protected:
    static GalaxOS_Class *Instance_Pointer;

    // System extension :
    // GRF : Galax'OS Registry File
    // GEF : Galax'OS Executable File
    // GSF : Galax'OS Sound File
    const char Users_Path[8] = "/USERS/";
    const char System_Path[10] = "/GALAXOS/";
    const char Extension_Registry_Path[31] = "/GALAXOS/REGISTRY/EXTENSIO.GRF";
    const char Display_Registry_Path[30] = "/GALAXOS/REGISTRY/DISPLAY.GRF";
    const char Network_Registry_Path[30] = "/GALAXOS/REGISTRY/NETWORK.GRF";
    const char Regional_Registry_Path[31] = "/GALAXOS/REGISTRY/REGIONAL.GRF";
    const char Software_Registry_Path[31] = "/GALAXOS/REGISTRY/SOFTWARE.GRF";
    const char Event_Registry_Path[31] = "/GALAXOS/REGISTRY/SOFTWARE.GRF";
    const char Virtual_Global_Memory_File[36] = "/GALAXOS/MEMORY/GLOBAL/VARIABLE.GSF";

    // Virtual Memory File

    File Virtual_Memory_File;
    uint8_t Split_Number[8];
    SemaphoreHandle_t Virtual_Memory_Semaphore;

    byte C_MIDI;

    int C_Frequency;

    const int Low_RAM_Threshold = 2000;

    //User attribute
    char Current_Username[8];

    String Temporary_String;

    Software_Class *Open_Software_Pointer[6];
    Software_Handle_Class *Software_Handle_Pointer[MAXIMUM_SOFTWARE];

    uint8_t Event_Reply;

    char Tag;

    struct tm Time;

    char WiFi_SSID[20];
    char WiFi_Password[20];

    xTaskHandle Ressource_Monitor_Handle;
    xTaskHandle Core_Task_Handle;

    QueueHandle_t Core_Instruction_Queue_Handle;

    // Serial print

    uint8_t Remaining_Spaces;

    //Software management

    GalaxOS_Event Event_Handler(GalaxOS_Event const &);

    uint8_t Get_Software_Pointer(const char *);
    uint8_t Get_Software_Handle_Pointer(const char *Software_Name);

    void Open_Software(const char *);
    void Close_Software(Software_Handle_Class * = NULL);
    void Minimize_Software();
    void Maximize_Software(uint8_t);

    void Create_System_Files();



public:

    // Core APIs (system calls)
    void Open_File(File&);

    enum Information
    {
        Good_Credentials,
        Wrong_Credentials,
    };

    enum Question
    {
        Close_All_Running_Software,
        Delete_File,
    };

    enum Answer
    {
        Yes,
        Cancel,
        Apply,
        No,
        Default,
    };

    enum Warning
    {

        Low_RAM,
    };

    enum Error
    {
        Not_Logged,
        Corrupted_User_File,
        Failed_To_Initialize_SD_Card,
        Corrupted_System_File,
        Invalid_Software_ID,
    };

    enum Color
    {
        Black,
        White,
        Grey,
        Light_Grey,
        Dark_Grey,
        Red = 57344,
        Blue = 1300,
        Green = 34308,
        Yellow = 64896
    };

    GalaxOS_Class();
    ~GalaxOS_Class();

    // Drivers
    // Display
    Nextion_Display_Class Display;
    // Sound
    Sound_Class Sound;
    // Input
    Keyboard_Class Keyboard;
// Disk
#if SD_MODE == 0
    fs::SDMMCFS *Drive;
#else
    fs::SDFS *Drive;
#endif
    // WiFi

    // System state
    void Start();
    void Save_System_State(); //Save system state in a file, in case of binary loading or hiberte, in order to restore the last system state. Start routine check always if a "GOSH.GSF"
    void Restore_System_State();

    void Synchronise_Time();

    // Software Management

    void Set_Load_Function(const char*, Software_Class* (*)()); // Used by softwa

    // Display callback functions

    enum Code {
        Close = 0x43,
        Maximize = 0x4D,
        Minimize = 0x6D,
        Command = 0x2A,
        Command_New = 0x23,
        Variable_String_Local = 0x0073,
        Variable_String_Global = 0x0053,
        Variable_Long_Local = 0x6C,
        Variable_Long_Global = 0x4C,
    };

    void Incomming_String_Data_From_Display(String &);
    void Incomming_Numeric_Data_From_Display(uint32_t &);
    void Incomming_Event_From_Display(uint8_t &);

    // Serial communication macro

    void Horizontal_Separator();
    void Print_Line(const char *, uint8_t const & = 0);
    void Print_Line(const __FlashStringHelper*, uint8_t const & = 0);
    void Print_Line();

    //
    byte Get_Speaker_Pin();
    int Get_C_Frequency();
    byte Get_C_MIDI();

    // Virtual Memory
    void Set_Variable(char const &, String const &, uint16_t = 0, Software_Handle_Class * = NULL);
    void Get_Variable(char const &, String &, uint16_t = 0, Software_Handle_Class * = NULL);

    void Set_Variable(uint8_t const &, const char *, uint16_t, Software_Handle_Class * = NULL);
    void Get_Variable(uint8_t const &, char *, uint16_t, Software_Handle_Class * = NULL);

    /*void Set_Variable(uint8_t const &, uint8_t*, uint16_t const&, Software_Handle_Class* = NULL);
    void Get_Variable(uint8_t const &, uint8_t*, uint16_t const&, Software_Handle_Class* = NULL);

    void Set_Variable(uint8_t const &, uint16_t*, uint16_t const&, Software_Handle_Class* = NULL);
    void Get_Variable(uint8_t const &, uint16_t*, uint16_t const&, Software_Handle_Class* = NULL);

    void Set_Variable(uint8_t const &, uint32_t*, uint16_t const&, Software_Handle_Class* = NULL);
    void Get_Variable(uint8_t const &, uint32_t*, uint16_t const&, Software_Handle_Class* = NULL);*/

    void Set_Variable(char const &, uint32_t *, uint16_t = 0, Software_Handle_Class * = NULL);
    void Get_Variable(char const &, uint32_t *, uint16_t = 0, Software_Handle_Class * = NULL);

    char* Get_Current_Username()
    {
        return Current_Username;
    }

    /*void Registry_Find(File &Registry_File, const char *Key_Name, char *Key_Value_To_Get, uint16_t const &Column = 0);
    char *Registry_Read(File &Registry_File, uint16_t const &Line_Number, uint16_t const &Column_Number);
    void Registry_Write(const __FlashStringHelper *Path, const __FlashStringHelper *Key_Name, String &Key_Value_To_Get);
    void Registry_Add(const __FlashStringHelper *Path, const __FlashStringHelper *Key_Name, String &Key_Value_To_Set);
    void Registry_Modify(const __FlashStringHelper *Path, const __FlashStringHelper *Key_Name, String &Key_Value_To_Set);
    void Registry_Delete(const __FlashStringHelper *Path, const __FlashStringHelper *Key_Name);*/

    void Load_System_Files();
    void Load_User_Files();

    GalaxOS_Event Check_Credentials(String const &, String const &);
    GalaxOS_Event Login(String const &, String const &);
    GalaxOS_Event Logout();

    //services
    void Desk_Execute(uint16_t const &Command);

    enum Events
    {
        Error,
        Warning,
        Information,
        Question,
    };

    GalaxOS_Event Event_Handler(const __FlashStringHelper*, uint8_t, const __FlashStringHelper* = NULL, const __FlashStringHelper* = NULL, const __FlashStringHelper* = NULL);
    
    void Nextion_Upload_Firmware(String const &Path);

    friend class Shell_Class;
    friend void Core_Task(void *);
    friend void Ressource_Monitor(void *pvParameters);
};

//GalaxOS tasks as separate function (FreeRTOS seems to not support class/struct method)
void Ressource_Monitor(void *);
void Core_Task(void *);

#endif