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
#include "Battery.hpp"

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

typedef uint16_t Xila_Event;
typedef uint16_t Xila_Command;
typedef tm Xila_Time;

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
#define ERROR_TOO_MUCH_OPENNED_SOFTWARE 7519

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

class Xila_Class
{
protected:
    // Instance pointer

    static Xila_Class *Instance_Pointer;

    // System path

    const char Users_Directory_Path[8] = "/USERS/";
    const char System_Directory_Path[10] = "/GALAXOS/";
    const char Extension_Registry_Path[31] = "/GALAXOS/REGISTRY/EXTENSIO.GRF";
    const char Display_Registry_Path[30] = "/GALAXOS/REGISTRY/DISPLAY.GRF";
    const char Network_Registry_Path[30] = "/GALAXOS/REGISTRY/NETWORK.GRF";
    const char Regional_Registry_Path[31] = "/GALAXOS/REGISTRY/REGIONAL.GRF";
    const char Software_Registry_Path[31] = "/GALAXOS/REGISTRY/SOFTWARE.GRF";
    const char Event_Registry_Path[31] = "/GALAXOS/REGISTRY/SOFTWARE.GRF";
    const char Sound_Registry_Path[28] = "/GALAXOS/REGISTRY/SOUND.GRF";
    const char Virtual_Global_Memory_File[36] = "/GALAXOS/MEMORY/GLOBAL/VARIABLE.GSF";
    // System extension :
    // GRF : Galax'OS Registry File
    // GEF : Galax'OS Executable File
    // GSF : Galax'OS Sound File

    // Picure ID

    enum Picture
    {
        AFG_Icon_64,
        Question_32,
        Information_32,
        Warning_32,
        Error_32
    };

    // Font ID

    enum Font
    {
        Main_16 = 0,
        Main_24 = 2,
        Main_32 = 3
    };

    /* Virtual Memory File
    File Virtual_Memory_File;
    uint8_t Split_Number[8];
    SemaphoreHandle_t Virtual_Memory_Semaphore;*/

    const int Low_RAM_Threshold = 2000;

    //User attribute
    char Current_Username[9];

    String Temporary_String;

    Software_Class *Open_Software_Pointer[8];
    // Open_Software_Pointer[0] : Current running software
    // Open_Software_Pointer[1] : Shell slot
    // Open_Softwaer_Pointer[2 - 7] : Other openned software (still in ram)
    Software_Handle_Class *Software_Handle_Pointer[MAXIMUM_SOFTWARE];

    // Display callback
    char Tag;
    static void Incomming_String_Data_From_Display(const char *, uint8_t);
    static void Incomming_Numeric_Data_From_Display(uint32_t &);
    static void Incomming_Event_From_Display(uint8_t &);

    // Serial print

    uint8_t Remaining_Spaces;

    //Software management

    uint8_t Get_Software_Handle_Pointer(const char *Software_Name);

    void Open_Software(Software_Handle_Class *);
    void Close_Software(Software_Handle_Class * = NULL);
    void Minimize_Software();
    void Maximize_Software(uint8_t);
    void Add_Software_Handle(Software_Handle_Class *);

    void Create_System_Files();

public:
    // Core APIs (system calls)


    //Background job

    Xila_Event Add_Background_Job(Software_Handle_Class*, void(*));
    Xila_Event Delete_Background_Job(Background_Job_Class*);



    void Open_File(File &);

    enum Font_16
    {
        State_Button = 127,
        Left_Arrow,
        Right_Arrow,
        Up_Arrow,
        Down_Arrow,
        Battery_Empty,
        Battery_Low,
        Battery_Medium,
        Battery_High,
        WiFi_Low,
        WiFi_Medium,
        WiFi_High,
        Bluetooth,
        Sound_Mute,
        Sound_Low,
        Sound_Medium,
        Sound_High,
    };

    enum Information
    {
        Good_Credentials,
        Wrong_Credentials,
        Success,
    };

    enum Question
    {
        Close_All_Running_Software,
        Delete_File,
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
        Too_Much_Openned_Software,
        Screen_Data_Exception,
        User_Already_Exist
    };

    enum Color
    {
        Black,
        White,
        Grey,
        Light_Grey = 33808,
        Dark_Grey = 16904,
        Red = 57344,
        Blue = 1300,
        Green = 34308,
        Yellow = 64896
    };

    Xila_Class();
    ~Xila_Class();

    // Drivers
    // Display
    Nextion_Display_Class Display;
    // Sound
    Sound_Class Sound;
    // Battery
    Battery_Class Battery;
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
    void Start(); // public

    void Shutdown(); // private
    void Load();     // private

    void Save_System_State();    // Private : method Save system state in a file, in case of binary loading or hiberte, in order to restore the last system state. Start routine check always if a "GOSH.GSF"
    void Restore_System_State(); // private :

    // Time management
    Xila_Time Time;
    time_t Now;
    char NTP_Server[32];
    char Time_Zone[48];

    void Synchronise_Time();
    void Refresh_Clock();
    Xila_Time Get_Time();

    // Display callback functions

    enum Code
    {
        Close = 0x43,       // 'C'
        Maximize = 0x4D,    // 'M'
        Minimize = 0x6D,    // 'm'
        Switch = 0x53,      // 'S' : switch
        Command = 0x2A,     // '*'
        Command_New = 0x23, // '#'
        Event = 0x45,
        Variable_String_Local = 0x73,  // 's'
        Variable_String_Global = 0x53, // 'S'
        Variable_Char_Local = 0x63,    // 'c'
        Variable_Char_Global = 0x42,   // 'C'
        Variable_Long_Local = 0x6C,    // 'l'
        Variable_Long_Global = 0x4C,   // 'L'
    };

    // Serial communication macro

    void Horizontal_Separator();
    void Print_Line(const char *, uint8_t const & = 0);
    void Print_Line(const __FlashStringHelper *, uint8_t const & = 0);
    void Print_Line();

    //

    /* Virtual Memory
    void Set_Variable(char const &, String const &, uint16_t = 0, Software_Handle_Class * = NULL);
    void Get_Variable(char const &, String &, uint16_t = 0, Software_Handle_Class * = NULL);

    void Set_Variable(uint8_t const &, const char *, uint16_t, Software_Handle_Class * = NULL);
    void Get_Variable(uint8_t const &, char *, uint16_t, Software_Handle_Class * = NULL);

    void Set_Variable(uint8_t const &, uint8_t*, uint16_t const&, Software_Handle_Class* = NULL);
    void Get_Variable(uint8_t const &, uint8_t*, uint16_t const&, Software_Handle_Class* = NULL);

    void Set_Variable(uint8_t const &, uint16_t*, uint16_t const&, Software_Handle_Class* = NULL);
    void Get_Variable(uint8_t const &, uint16_t*, uint16_t const&, Software_Handle_Class* = NULL);

    void Set_Variable(uint8_t const &, uint32_t*, uint16_t const&, Software_Handle_Class* = NULL);
    void Get_Variable(uint8_t const &, uint32_t*, uint16_t const&, Software_Handle_Class* = NULL);

    void Set_Variable(char const &, uint32_t *, uint16_t = 0, Software_Handle_Class * = NULL);
    void Get_Variable(char const &, uint32_t *, uint16_t = 0, Software_Handle_Class * = NULL);*/

    char *Get_Current_Username()
    {
        return Current_Username;
    }

    /*void Registry_Find(File &Registry_File, const char *Key_Name, char *Key_Value_To_Get, uint16_t const &Column = 0);
    char *Registry_Read(File &Registry_File, uint16_t const &Line_Number, uint16_t const &Column_Number);
    void Registry_Write(const __FlashStringHelper *Path, const __FlashStringHelper *Key_Name, String &Key_Value_To_Get);
    void Registry_Add(const __FlashStringHelper *Path, const __FlashStringHelper *Key_Name, String &Key_Value_To_Set);
    void Registry_Modify(const __FlashStringHelper *Path, const __FlashStringHelper *Key_Name, String &Key_Value_To_Set);
    void Registry_Delete(const __FlashStringHelper *Path, const __FlashStringHelper *Key_Name);*/

    Xila_Event Check_Credentials(const char *, const char *);
    Xila_Event Add_User(const char*, const char*);
    Xila_Event Delete_User(const char*, const char*);
    Xila_Event Change_Password(const char*, const char*, const char*);
    Xila_Event Login(const char *Username_To_Check, const char *Password_To_Check);
    Xila_Event Logout();

    // System dialogs

    enum Events
    {
        Error,
        Warning,
        Information,
        Question,
    };

    enum Reply
    {
        None = 0,
        Button_1 = 0x31,
        Button_2 = 0x32,
        Button_3 = 0x33
    };

    Xila_Event Event_Dialog(const __FlashStringHelper *, uint8_t, const __FlashStringHelper * = NULL, const __FlashStringHelper * = NULL, const __FlashStringHelper * = NULL);
    Xila_Event Event_Dialog(Xila_Event const &);
    SemaphoreHandle_t Dialog_Semaphore;
    Xila_Event Event_Reply;
    File File_Dialog(Xila_Event const&); //s

    //

    void Nextion_Upload_Firmware(String const &Path);

    // System's task :
    xTaskHandle Core_Task_Handle;
    //QueueHandle_t Core_Instruction_Queue_Handle;
    static void Core_Task(void *);
    static void Idle_Task_Software_Core(void *);
    static void Idle_Task_System_Core(void *);

    friend class Shell_Class;
    friend class Software_Handle_Class;
};

//GalaxOS tasks as separate function (FreeRTOS seems to not support class/struct method)
#endif