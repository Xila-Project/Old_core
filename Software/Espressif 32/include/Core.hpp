#ifndef GALAXOS_CORE_H_INCLUDED
#define GALAXOS_CORE_H_INCLUDED

#include "Configuration.hpp"

//----------------------------------------------------------------------------//
//                          Include Necessary Libraries                       //
//----------------------------------------------------------------------------//

#include <vector>

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

// Event  (used to interract with the event handler)

typedef uint16_t Xila_Event;
typedef uint16_t Xila_Command;
typedef tm Xila_Time;

// Alignement
#define STYLE_LEFT_ALIGNMENT 0
#define STYLE_CENTER_ALIGNMENT 1
#define STYLE_RIGHT_ALIGNMENT 2
#define STYLE_JUSTIFIED_ALIGNMENT 3

//----------------------------------------------------------------------------//
//                         Define GalaxOS Core Class                          //
//----------------------------------------------------------------------------//

extern Software_Handle_Class Shell_Handle;

class Xila_Class
{
protected:
    // Instance pointer

    static Xila_Class *Instance_Pointer;

    // System path

    const char Users_Directory_Path[8] = "/USERS/";
    const char System_Directory_Path[10] = "/XILA/";
    const char System_Registry_Path[26] = "/XILA/REGISTRY/SYSTEM.XRF";
    const char Extension_Registry_Path[31] = "/XILA/REGISTRY/EXTENSIO.XRF";
    const char Display_Registry_Path[30] = "/XILA/REGISTRY/DISPLAY.XRF";
    const char Network_Registry_Path[30] = "/XILA/REGISTRY/NETWORK.XRF";
    const char Account_Registry_Path[27] = "/XILA/REGISTRY/ACCOUNT.XRF";
    const char Regional_Registry_Path[31] = "/XILA/REGISTRY/REGIONAL.XRF";
    const char Software_Registry_Path[31] = "/XILA/REGISTRY/SOFTWARE.XRF";
    const char Event_Registry_Path[31] = "/XILA/REGISTRY/SOFTWARE.XRF";
    const char Sound_Registry_Path[28] = "/XILA/REGISTRY/SOUND.XRF";
    const char Virtual_Global_Memory_File[36] = "/XILA/MEMORY/GLOBAL/VARIABLE.XSF";
    const char Dump_Registry_Path[24] = "/XILA/REGISTRY/DUMP.XRF";
    const char System_Executable_Path[15]= "/XILA/XILA.XEF";
    // System extension :
    // GRF : Galax'OS Registry File
    // GEF : Galax'OS Executable File
    // GSF : Galax'OS Sound File

    char Device_Name[24];

    // Picure ID

    enum Image
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

    Software_Class *Open_Software_Pointer[8];
    // Open_Software_Pointer[0] : Current running software
    // Open_Software_Pointer[1] : Shell slot
    // Open_Softwaer_Pointer[2 - 7] : Other openned software

    Software_Handle_Class *Software_Handle_Pointer[MAXIMUM_SOFTWARE];
    // Software_Handle_Pointer[0 - MAXIMUM_SOFTWARE] : other software handle

    // Shell short cut

    void *Shell_Return_Item;
    Xila_Event Shell_Return;
    void Maximize_Shell();
    void Execute_Shell(uint16_t const &);

    // Display callback
    char Tag;
    static void Incomming_String_Data_From_Display(const char *, uint8_t);
    static void Incomming_Numeric_Data_From_Display(uint32_t &);
    static void Incomming_Event_From_Display(uint8_t &);

    // Serial print

    uint8_t Remaining_Spaces;

    //Software management

    uint8_t Get_Software_Handle_Pointer(const char *Software_Name);

public:
    // Power button

    static void IRAM_ATTR Power_Button_Handler();
    portMUX_TYPE Power_Button_Mutex = portMUX_INITIALIZER_UNLOCKED;
    volatile uint8_t Power_Button_Counter;
    void Check_Power_Button();

    // Software management

    void Open_Software(Software_Handle_Class *);
    void Close_Software(Software_Handle_Class * = NULL);
    void Minimize_Software();
    void Maximize_Software(uint8_t);

    void Load_Software_Handle(Software_Handle_Class *Software_Handle_Pointer_To_Add, const __FlashStringHelper *Header_Path);

    // Core APIs (system calls)

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

    enum Color
    {
        Black,
        White = 65535,
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
    void Start();                                                //start system in standard mode
    void Start(Software_Handle_Class *Software_Handle_To_Start); // reload system from the dump file

    void Shutdown();       // private
    void Restart();        // private
    void Load();           // private
    void Load_From_Dump(); // restore curre

    Xila_Event Load_Executable(File);

    Xila_Event Create_Dump();
    Xila_Event Load_Dump();

    uint8_t System_State;

    Software_Handle_Class* Software_Handle_To_Start;

    void Save_System_State();    // Private : method Save system state in a file, in case of binary loading or hiberte, in order to restore the last system state. Start routine check always if a "GOSH.GSF"
    void Restore_System_State(); // private :

    // Time management
    Xila_Time Time;
    time_t Now;
    char NTP_Server[32];

    void Synchronise_Time();
    void Refresh_Header();
    Xila_Time Get_Time();

    // Display callback functions

    enum Instruction
    {
        Open = 'O',
        Close = 'C',
        Maximize = 'M',
        Minimize = 'm',
        Command = '*',
        Command_New = '#',
        Event = 'E',
        Variable_Byte_Local = 'b',
        Variable_Byte_Global = 'B',
        Variable_String_Local = 's',
        Variable_String_Global = 'S',
        Variable_Char_Local = 'c',
        Variable_Char_Global = 'C',
        Variable_Long_Local = 'l',
        Variable_Long_Global = 'L',

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
    Xila_Event Add_User(const char *, const char *);
    Xila_Event Delete_User(const char *, const char *);
    Xila_Event Change_Password(const char *, const char *, const char *);
    Xila_Event Login(const char *Username_To_Check = NULL, const char *Password_To_Check = NULL);
    Xila_Event Logout();

    // System dialogs

    enum Events
    {
        Error,
        Warning,
        Information,
        Question,
        Success,
    };

    enum Reply
    {
        None = 0,
        Button_1 = 0x31, // Yes
        Button_2 = 0x32, // No
        Button_3 = 0x33  // Cancel
    };

    Xila_Event Event_Dialog(const __FlashStringHelper *, uint8_t, const __FlashStringHelper * = NULL, const __FlashStringHelper * = NULL, const __FlashStringHelper * = NULL);
    Xila_Event Event_Dialog(Xila_Event const &);
    SemaphoreHandle_t Dialog_Semaphore;
    Xila_Event Event_Reply;

    Xila_Event Open_File_Dialog(File &File_To_Open);
    Xila_Event Open_Folder_Dialog(File &Folder_To_Open);
    Xila_Event Save_File_Dialog(File const &);

    // Copy paste

    std::vector<char> Copied_Data;

    size_t Size_Of_Coped_Data;

    Xila_Event Copy(uint32_t& Value_To_Copy);
    Xila_Event Copy(uint64_t& Value_To_Copy);
    Xila_Event Copy(const char *Char_Array_To_Copy);
    Xila_Event Copy(String &String_To_Copy); // deprecated : only for compatibility purpose

    Xila_Event Paste(uint32_t &Value_To_Paste);
    Xila_Event Paste(char *Char_Array_To_Paste);
    Xila_Event Paste(String String_To_Paste);

    // Background jobs

    uint32_t Last_Execution;
    uint8_t Background_Function_Counter;
    void Execute_Background_Jobs();

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