/**
 * @file Core.hpp
 * @brief Xila's core header file.
 * @author Alix ANNERAUD
 * @copyright MIT License
 * @version 0.1.0
 * @date 21/05/2020
 * @details Gather all the parts used by Xila core.
 * @section License
 * 
 * Copyright (c) 2020 Alix ANNERAUD
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
*/

#ifndef GALAXOS_CORE_H_INCLUDED
#define GALAXOS_CORE_H_INCLUDED

//----------------------------------------------------------------------------//
//                          Include Necessary Libraries                       //
//----------------------------------------------------------------------------//

#include "Arduino.h"

#if SD_MODE == 1
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
typedef void* Xila_Task_Handle;

typedef void (*Xila_Task_Function)(void *);

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

/**
 * @class Xila_Class
 * @brief Core class.
 * 
 * Contain all core parts and include also its API which is used by external software.
 */
class Xila_Class
{

protected:
    // Instance pointer

    static Xila_Class *Instance_Pointer;

    /**
     * Device name used as Network hostname ...
    */
    char Device_Name[24];

    const int Low_RAM_Threshold = 2000;

    //User attribute
    char Current_Username[9];

    Software_Class *Open_Software_Pointer[8] = {NULL};
    // Open_Software_Pointer[0] : Current running software
    // Open_Software_Pointer[1] : Shell slot
    // Open_Softwaer_Pointer[2 - 7] : Other openned software

    Software_Handle_Class *Software_Handle_Pointer[MAXIMUM_SOFTWARE] = {NULL};
    // Software_Handle_Pointer[0 - MAXIMUM_SOFTWARE] : other software handle

    // Shell short cut

    void *Shell_Return_Item;
    Xila_Event Shell_Return;

    void Maximize_Shell();
    void Execute_Shell(Xila_Command const &Command);

    // Display
    char Tag;
    static void Incomming_String_Data_From_Display(const char *, uint8_t);
    static void Incomming_Numeric_Data_From_Display(uint32_t);
    static void Incomming_Event_From_Display(uint8_t);

    // Serial print

    uint8_t Remaining_Spaces;

    //Software management

    uint8_t Get_Software_Handle_Pointer(const char *Software_Name);

    // Power button

public:
    enum Image_Offset
    {
        Shell = 0,
        Calculator = 19,
        Clock = 20,
        Internet_Browser = 21,
        Music_Player = 22,
        Oscilloscope = 29,
        Paint = 30,
        Periodic = 31,
        Piano = 33,
        Picture_Viewer = 37,
        Pong = 38,
        Simon = 39,
        Text_Editor = 40,
        Tiny_Basic = 41
    };

    enum Pages_Offset
    {

    };

    uint32_t Last_Watchdog_Feed;
    uint8_t Watchdog_Reminder;

    /**
     * @brief A function that feed watchdog
     */
    void Feed_Watchdog();

    /**
    * @brief A delay function.
    * @param Delay_In_Millisecond
    * @details A delay function that behave exactly like delay() but reset also Xila watchdog (check if an app is frozen)
    */
    void Delay(uint32_t Delay_In_Millisecond);

    void Check_Watchdog();

    /**
     * @enum Font identifier
    */
    enum Font
    {
        Main_16 = 0, /*!< Roboto Regular 16 px (+ special character), main font used almost everywhere. */
        Main_24 = 2, /*!< Robot Regular 24 px (+ special character), secondary font used sometimes. */
        Main_32 = 3  /*!< Roboto Regular 32 px (+ special character), secondary font used sometimes. */
    };

    static void IRAM_ATTR Power_Button_Handler();

    portMUX_TYPE Power_Button_Mutex = portMUX_INITIALIZER_UNLOCKED;

    volatile uint8_t Power_Button_Counter;

    void Check_Power_Button();

    // -- Task management -- //

    void Task_Resume(Xila_Task_Handle Task_To_Resume);

    void Task_Suspend(Xila_Task_Handle Task_To_Suspend = NULL);
    void Task_Delete(Xila_Task_Handle Task_To_Delete = NULL);
    Xila_Event Task_Create(Xila_Task_Function Task_Function, const char *Task_Name, size_t Stack_Size, void *pvParameters = NULL, Xila_Task_Handle* Task_Handle = NULL);

    // -- Software management -- //

    inline uint8_t Seek_Open_Software_Handle(Software_Handle_Class const &);

    /**
     * @brief Function used to open a Software.
     * 
     * @param Software_Handle The software's handle to open 
     */
    Xila_Event Software_Open(Software_Handle_Class const &Software_Handle);

    /**
     * @brief Function used to close a Software.
     * 
     * @param Software_Handle The software's handle to close, equal NULL by default which close the currently running software.
     */
    void Software_Close(Software_Handle_Class const &Software_Handle);

    /**
     * @brief Function that close roughly the current running software.
     * @details Delete manualy the main software task, and then delete software instance. That could leave undeleted memory fragment (external tasks, external variables ...).
     */
    void Force_Software_Close();

    /**
     * @brief Function used to minimize the currently running software, and then maximize Shell.
     */
    void Software_Minimize(Software_Handle_Class const& Software_Handle);

    /**
     * @brief Function used to maxmize the software.
     * 
     * @param Software_Handle The software's handle to maxmize.
     */
    Xila_Event Software_Maximize(Software_Handle_Class const &);

    void Add_Software_Handle(Software_Handle_Class &); //private shortcut

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

    /**
     * @enum Color
     * @brief Default system colors.
     */
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

    // WiFi

    //WiFiClass* WiFi = &WiFi;

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
    fs::SDMMCFS *Drive = &SD_MMC;
#else

    fs::SDFS *Drive = &SD;

#endif
    // WiFi

    /**
     * @brief Function that allow to connect WiFi.
     * @return Xila.Success if it succed to connect, and Xila.Error if not.
     * @details Function that connect to already registered access point.
     */
    Xila_Event WiFi_Connect();

    /**
     * @brief Function that allow to connect WiFi.
     * @param Name SSID of the access point.
     * @param Password Password of the access point.
     * @return Xila.Success if it succed to connect, and Xila.Error if not.
     * @details Function that that try to connect to the given access point, and if succed, save credential into network registry.
     */
    Xila_Event WiFi_Connect(char *Name, char *Password);

    // -- System state -- //

    /**
    * @brief Function handle deep-sleep wakeup, initialize the core, start software etc.
    * @param Software_Package Software that Xila need to load. 
    * @details Function steps :
    * 1) Check if the wakeup reasing is linked to a power button press, or undefined (power reset) and if not, go to sleep.
    * 2) Create an interrupt for the power button.
    * 3) Initalize display.
    * 4) Initalize system drive.
    * 5) Load registries (display, sound, keyboard, network, time).
    * 6) Play sound and animation.
    * 7) Load software handles.
    * 8) Execute software startup function (Shell and other software).
    */
    void Start(Software_Handle_Class *Software_Package, uint8_t Size); // reload system from the dump file

    /**
     * @brief Function that handle deep-sleep wakeup, initialize the, start software etc.
     * @details Function steps :
     * 1) Cheeck if the wa
     */
    void Start();

    enum Panic_Code
    {
        Damaged_System_Registry,
        Installation_Conflict,
        System_Drive_Failure,
        Low_Memory
    };

    /**
     * @brief Function shutdown the system.
     * @details Function that execute, before making 
     * 
     */
    void Shutdown(); // private

    void Check_System_Drive();

    inline void First_Start_Routine();
    inline void Second_Start_Routine();

    void Restart(); // private

    void Hibernate(); // private

    void Deep_Sleep();

    // -- Registry modification methods -- //

    Xila_Event Load_Time_Registry();
    Xila_Event Load_Keyboard_Registry();
    Xila_Event Load_Display_Registry();
    Xila_Event Load_Network_Registry();
    Xila_Event Load_Account_Registry();
    Xila_Event Load_System_Registry();
    Xila_Event Load_Sound_Registry();

    Xila_Event Set_Time_Registry(const char *NTP_Server = NULL, int32_t GMT_Offset = 0xFFFFFFFF, int16_t Daylight_Offset = 0xFFFF);
    Xila_Event Set_Keyboard_Registry(uint8_t Data_Pin = 0xFF, uint8_t Interrupt_Pin = 0xFF, uint8_t Keymap = 0xFF);
    Xila_Event Set_Display_Registry(uint8_t Brighness = 0xFF, uint16_t Standby_Time = 0xFFFF, uint8_t Receive_Pin = 0xFF, uint8_t Send_Pin = 0xFF);
    Xila_Event Set_Network_Registry(uint8_t WiFi_Enabled = 0xFF, const char *WiFi_Name = NULL, const char *Password = NULL);
    Xila_Event Set_Account_Registry(const char *Autologin_Account = NULL);
    Xila_Event Set_System_Registry(const char *Device_Name);
    Xila_Event Set_Sound_Registry(uint8_t Volume = 0xFF);

    int32_t GMT_Offset;
    int16_t Daylight_Offset;

    uint8_t Keyboard_Data_Pin;
    uint8_t Keyboard_Interrupt_Pin;
    uint8_t Keyboard_Keymap;

    const char *Get_Device_Name();

    /**
     * 
     *@param Executable_File : Executable file
     *@param Type : Type ('M' for MCU or 'D' for Display)
     *
     * @return 
    */
    Xila_Event Load_Executable(File Executable_File, uint8_t Type = 'M');

    //Xila_Event Update();

    Xila_Event Create_Dump();
    Xila_Event Load_Dump();

    uint8_t System_State;

    enum System_States
    {
        Default,
        New_Installation,
    };

    void Save_System_State();    // Private : method Save system state in a file, in case of binary loading or hiberte, in order to restore the last system state. Start routine check always if a "GOSH.GSF"
    void Restore_System_State(); // private :

    // -- Time management
    Xila_Time Time;
    time_t Now;
    char NTP_Server[32];

    void Synchronise_Time();
    void Refresh_Header();
    Xila_Time Get_Time();

    // Display callback functions


    // -- Prefixs used to differienciate exchanged data between display, core and software
    enum Prefixs
    {
        Instruction = '#',

        Variable_String_Local = 's', // 
        Variable_String_Global = 'S', // Unused : redirected to Variable_String_Local
        Variable_Long_Local = 'l',
        Variable_Long_Global = 'L' // Unused : redirected to Variable_Long_Local
    };

    // -- Instructions used by the core (with the prefix "#")

    enum Instructions
    {
        // -- General instructions
        Idle = 0,

        // -- Software state instructions
        Open = 'O',
        Close = 'C',
        Maximize = 'M',
        Minimize = 'm',
        // -- System state instructions
        Shutting_down = 200,
        Restarting,
        Hibernating = 'H',

        Watchdog = 'W',

        // -- Shell specials instructions
        Install_Dialog = 'I',   // Open installation form
        Desk = 'D',             // Open desk
        Open_File = 'f',        // Open open file dialog
        Open_Folder = 'F',      // Open open folder dialog
        Save_File = 'e',        // Open save file dialog
        Virtual_Keyboard = 'K', // Open keyboard dialog
        Virtual_Keypad = 'k',   // Open keyapd dialog
        Color_Picker = 'c',     // Open color picker dialog
        Power = 'P',            // Open power dialog
        Event = 'E',            // Open event dialog

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

    /**
     * @enum Events
     * @brief All kinds of events returned by Core API.
     */
    enum Events
    {
        None,
        Error,
        Warning,
        Information,
        Question,
        Success,
        Button_1 = 0x31, //< Button 1 reply, by default : Yes
        Button_2 = 0x32, //< Button 2 reply by default : No
        Button_3 = 0x33  //< Button 3 reply by default : Cancel (returned also by close button)
    };

    void Panic_Handler(uint32_t Panic_Code);

    Xila_Event Event_Dialog(const __FlashStringHelper *, uint8_t, const __FlashStringHelper * = NULL, const __FlashStringHelper * = NULL, const __FlashStringHelper * = NULL);
    Xila_Event Color_Picker_Dialog(uint16_t &Color);
    Xila_Event Open_File_Dialog(File &File_To_Open);
    Xila_Event Open_Folder_Dialog(File &Folder_To_Open);
    Xila_Event Save_File_Dialog(File &File_To_Save);
    Xila_Event Keyboard_Dialog(char *Char_Array_To_Get, size_t Char_Array_Size = 189, bool Masked_Input = false);
    // to do : Xila_Event Keyboard_Difalog(float& Number_To_Get) (and more overload);
    Xila_Event Keypad_Dialog(float &Number_To_Get);

    uint32_t Dialog_Long[2];
    void *Dialog_Pointer;

    Software_Class *Caller_Software_Handle_Pointer;

    Xila_Event Dialog_State;

    SemaphoreHandle_t Dialog_Semaphore;

    File *File_Dialog_Reply;

    Xila_Event Set_Autologin();

    uint16_t Standby_Display_Time;
    uint32_t Standby_System_Time;

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

    void Execute_Startup_Function();

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