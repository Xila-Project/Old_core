/**
 * @file
 * @author Alix ANNERAUD
 * @version 0.1.0
 * 
 * @section License
 * 
 * Copyright <YEAR> <COPYRIGHT HOLDER>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 * @section Description
 * 
 * Xila core class.
*/

#ifndef GALAXOS_CORE_H_INCLUDED
#define GALAXOS_CORE_H_INCLUDED

//----------------------------------------------------------------------------//
//                          Include Necessary Libraries                       //
//----------------------------------------------------------------------------//

#include "Arduino.h"

#if SD_MODE == 0
#include "SD_MMC.h"
#include "FS.h"
#else
#include "SD.h"
#endif

#include "time.h"
#include "Update.h"
#include <ArduinoJson.h> //used to store
#include "WiFi.h"

//----------------------------------------------------------------------------//
//                          Include All Project File                          //
//----------------------------------------------------------------------------//

// Main compile-time configuration file
#include "Configuration.hpp"
// Path list
#include "Path.hpp"

// Other part of the core
#include "Instruction.hpp"
#include "Software.hpp"
#include "Software_Handle.hpp"

// Driver files
#include "Driver/Display.hpp"  // Nextion display driver (maybe create a library for each driver)
#include "Driver/Keyboard.hpp" // PS2 keyboard driver
#include "Driver/Sound.hpp"
#include "Driver/Battery.hpp"

//----------------------------------------------------------------------------//
//                                Define Const                                //
//----------------------------------------------------------------------------//

// Event  (used to interract with the event handler)

typedef uint16_t Xila_Event;
typedef uint16_t Xila_Command;
typedef tm Xila_Time;

// System state
#define SYSTEM_STATE_STANDALONE 1
#define SYSTEM_STATE_NORMAL 0

// Software type
#define SOFTWARE_EMBEDDED 0
#define SOFTWARE_STANDALONE 1

// Alignement

//----------------------------------------------------------------------------//
//                         Define Xila Core API                               //
//----------------------------------------------------------------------------//

extern Software_Handle_Class Shell_Handle;

class Xila_Class
{
protected:
    // Instance pointer

    static Xila_Class *Instance_Pointer;

    /**
     * Device name used as Network hostname ...
    */
    char Device_Name[24];

    enum Image
    {
        AFG_Icon_64,
        Question_32,
        Information_32,
        Warning_32,
        Error_32
    };

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

    // Display
    char Tag;
    static void Incomming_String_Data_From_Display(const char *, uint8_t);
    static void Incomming_Numeric_Data_From_Display(uint32_t &);
    static void Incomming_Event_From_Display(uint8_t &);

    // Serial print

    uint8_t Remaining_Spaces;

    //Software management

    uint8_t Get_Software_Handle_Pointer(const char *Software_Name);

    // Power button

public:

    /**
     * Font identifier
    */
    enum Font
    {
        Main_16 = 0,
        Main_24 = 2,
        Main_32 = 3
    };

    static void IRAM_ATTR Power_Button_Handler();

    portMUX_TYPE Power_Button_Mutex = portMUX_INITIALIZER_UNLOCKED;

    volatile uint8_t Power_Button_Counter;

    void Check_Power_Button();

    // Software management

    inline void Rollback(); // go back to xila

    inline uint8_t Seek_Open_Software_Handle(Software_Handle_Class const &);

    void Open_Software(Software_Handle_Class const &);
    void Close_Software(Software_Handle_Class * = NULL);
    void Minimize_Software();
    void Maximize_Software(Software_Handle_Class const &);

    Xila_Event Load_Software_Handle(Software_Handle_Class *Software_Handle_To_Load, const __FlashStringHelper *Header_Path);

    Xila_Event Add_Software_Handle(Software_Handle_Class const &); //private shortcut

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

    enum Font_32
    {
        Exclamation_Mark = 127,
        Question_Mark,
        Cross
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

    Xila_Event WiFi_Connect();
    Xila_Event WiFi_Connect(char *Name, char *Password);

    // System state
    void Start();                                                //start system in standard mode
    void Start(Software_Handle_Class *Software_Handle_To_Start); // reload system from the dump file

    void Shutdown(); // private
    void Restart();  // private

    Xila_Event Load_Regionnal_Registry();
    Xila_Event Load_Display_Registry();
    Xila_Event Load_Network_Registry();
    Xila_Event Load_Account_Registry();
    Xila_Event Load_System_Registry();
    Xila_Event Load_Sound_Registry();

    Xila_Event Set_Regionnal_Registry(const char *NTP_Server = NULL, int32_t GMT_Offset = 0xFFFFFFFF, int16_t Daylight_Offset = 0xFFFF);
    Xila_Event Set_Display_Registry(uint8_t Brighness = 0xFF, uint16_t Standby_Time = 0xFFFF, uint8_t Receive_Pin = 0xFF, uint8_t Send_Pin = 0xFF);
    Xila_Event Set_Network_Registry(bool WiFi_Enabled, const char *WiFi_Name, const char *Password);
    Xila_Event Set_Account_Registry(const char *Autologin_Account = NULL);
    Xila_Event Set_System_Registry(const char *Device_Name, );
    Xila_Event Set_Sound_Registry(uint8_t Volume = 0xFF);

    int32_t GMT_Offset;
    int16_t Daylight_Offset;

    const char *Get_Device_Name();

    /**
     * 
     *@param Executable_File : Executable file
     *@param Type : Type ('M' for MCU or 'D' for Display)
     *
     * @return 
    */
    Xila_Event Load_Executable(File Executable_File, uint8_t Type = 'M');
    Xila_Event Update();

    Xila_Event Create_Dump();
    Xila_Event Load_Dump();

    uint8_t System_State;

    Software_Handle_Class *Software_Handle_To_Start;

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
        Hiberrnate = 'H',          // create dump
        Installation_Wizard = 'I', // Open installation form
        Open_File_Dialog = 'f',
        Open_Folder_Dialog = 'F',
        Save_File_Dialog = 'e',
        Keyboard_Dialog = 'K',
        Numpad_Dialog = 'N',
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
        Variable_Long_Global = 'L'
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
    Xila_Event Add_User(const char *Username, const char *Password);
    Xila_Event Delete_User(const char *);
    Xila_Event Change_Password(const char *, const char *);
    Xila_Event Change_Username(const char *, const char *);
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
    SemaphoreHandle_t Dialog_Semaphore;
    File *File_Dialog_Reply;
    uint32_t Long_Dialog_Reply;
)
    //Xila_Event Color_Picker_Dialog(uint16_t& Color);
    Xila_Event File_Dialog(File &File_To_Open);
Xila_Event Folder_Dialog(File &Folder_To_Open);
Xila_Event File_Dialog(File const &);

Xila_Event Set_Autologin();

uint16_t Display_Standby_Time;
uint32_t System_Standby_Time;

Xila_Event Copy_File(File &Origin_File, File &Destination_File);

// Copy paste

private:
File Clipboard_File;
uint8_t Split_Number[8];

public:
Xila_Event Copy(uint64_t const &Value_To_Copy);
Xila_Event Copy(const char *Char_Array_To_Copy, size_t Char_Array_Lenght = 0);
Xila_Event Copy(String const &String_To_Copy); // deprecated : only for compatibility purpose

Xila_Event Paste(uint64_t &Value_To_Paste);
Xila_Event Paste(char *Char_Array_To_Paste, size_t Char_Array_Lenght);
Xila_Event Paste(String &String_To_Paste);

// Background jobs

uint32_t Last_Execution;
uint8_t Background_Function_Counter;

inline void Execute_Startup_Function();
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