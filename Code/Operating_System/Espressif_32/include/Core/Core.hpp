///
/// @file Core.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Xila's core header file.
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///
/// @details Gather all the parts used by Xila core.
///
/// @section MIT License
///
///  Copyright (c) 2020 Alix ANNERAUD
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
/// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
///
#ifndef CORE_H_INCLUDED
#define CORE_H_INCLUDED

#ifdef __cplusplus

#else

#error Xila requires a C++ complier, pleas echange file extension to .cc or .cpp

#endif

//============================================================================//
//                          Include required libraries                        //
//============================================================================//

// -- C++ standard library
#include <stdint.h>

// -- Arduino framework
#include "Arduino.h"

// -- File system library
#include "FS.h"
#include "ff.h"
// -- SD SPI
#include "vfs_api.h"
#include "sd_diskio.h"
#include "ff.h"
// -- SD MMC
#include "vfs_api.h"
extern "C"
{
#include <sys/unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include "esp_vfs_fat.h"
#include "driver/sdmmc_host.h"
#include "driver/sdmmc_defs.h"
#include "sdmmc_cmd.h"
}

// -- SPI library
#include "SPI.h"

// -- Time library
#include "time.h"

// -- ESP 32 update
#include "Update.h"

// -- Registry management library
#include <ArduinoJson.h> //used to store registries
#include <StreamUtils.h>

// WiFi libraries
#include "Print.h"
#include "IPAddress.h"
#include "IPv6Address.h"
#include "WiFiType.h"
#include "WiFiSTA.h"
#include "WiFiAP.h"
#include "WiFiScan.h"
#include "WiFiGeneric.h"
#include "WiFiClient.h"
#include "WiFiServer.h"
#include "WiFiUdp.h"

// Driver files
#include "Driver/Display.hpp"
#include "Driver/Battery.hpp"

//----------------------------------------------------------------------------//
//                          Include All Project File                          //
//----------------------------------------------------------------------------//

// Configuration file (at compile time)
#include "Configuration.hpp" // default values
#include "Path.hpp"          // Path list

// Other part of the core

#include "Software.hpp"
#include "Software_Handle.hpp"


//----------------------------------------------------------------------------//
//                                Define Const                                //
//----------------------------------------------------------------------------//

///
/// @brief Xila time class
///
typedef tm Xila_Time;

//----------------------------------------------------------------------------//
//                         Define Xila Core API                               //
//----------------------------------------------------------------------------//

extern Software_Handle_Class Shell_Handle;

class Shell_Class;

///
/// @class Xila_Class
///
/// @brief Core class.
///
/// @details Contain all core A.P.I. and modules to make the kernel working.
///
class Xila_Class
{
protected:
    //==============================================================================//
    //                                    Attributes                                //
    //==============================================================================//

    ///
    /// @brief Current instance pointer. Help to prevent from corruption.
    ///
    static Xila_Class *Instance_Pointer;

public:
    //==============================================================================//
    //                              Enumerations                                    //
    //==============================================================================//

    ///
    /// @brief Xila event type
    ///
    typedef enum
    {
        None,
        Success = 1,
        Error,
        Warning,
        Information,
        Question,
        Button_1 = 0x31, //< Button 1 reply, by default : Yes
        Button_2 = 0x32, //< Button 2 reply by default : No
        Button_3 = 0x33, //< Button 3 reply by default : Cancel (returned also by close button)
        Default_Yes = Button_1,
        Default_No = Button_2,
        Default_Cancel = Button_3,
    } Event;

    //==============================================================================//
    //                                  Modules                                     //
    //==============================================================================//

    ///
    /// @brief Account management class
    ///
    class Account_Class
    {
    protected:
        char Current_Username[9];
        uint8_t State;

        Xila_Class::Event Load_Registry();
        Xila_Class::Event Save_Registry();

    public:
        ///
        /// @brief Session state type
        ///
        enum Session_State
        {
            Disconnected,
            Logged,
            Locked
        };

        Xila_Class::Event Add(const char *Username, const char *Password);
        Xila_Class::Event Delete(const char *);
        Xila_Class::Event Change_Password(const char *, const char *);
        Xila_Class::Event Change_Username(const char *, const char *);
        Xila_Class::Event Set_Autologin(bool Enable);

        Xila_Class::Event Check_Credentials(const char *, const char *);
        Xila_Class::Event Login(const char *Username_To_Check = NULL, const char *Password_To_Check = NULL);
        Xila_Class::Event Logout();
        Xila_Class::Event Lock();

        const char *Get_Current_Username();

        uint8_t Get_State();

        Account_Class();

        friend class Xila_Class;
        friend class Shell_Class;
    } Account;

    //==============================================================================//

    ///
    /// @brief Clipboard module
    ///
    class Clipboard_Class
    {
    protected:
        File Clipboard_File;
        uint8_t Split_Number[8];

    public:
        Xila_Class::Event Copy(uint64_t const &Value_To_Copy);
        Xila_Class::Event Copy(const char *Char_Array_To_Copy, size_t Char_Array_Lenght = 0);
        Xila_Class::Event Copy(String const &String_To_Copy); // deprecated : only for compatibility purpose

        Xila_Class::Event Paste(uint64_t &Value_To_Paste);
        Xila_Class::Event Paste(char *Char_Array_To_Paste, size_t Char_Array_Lenght);
        Xila_Class::Event Paste(String &String_To_Paste);

        friend class Xila_Class;
        friend class Shell_Class;
    } Clipboard;

    //==============================================================================//

    ///
    /// @brief Dialog class
    ///
    class Dialog_Class
    {
    protected:
        // -- Attributes

        ///
        /// @brief Caller software pointer
        ///
        Software_Class *Caller_Software;

        ///
        /// @brief Dialog state
        ///
        Xila_Class::Event State;

        ///
        /// @brief Dialog semaphore (avoid to have multiple dialog boxes at the same time);
        ///
        SemaphoreHandle_t Semaphore;

        ///
        /// @brief Multi purpose long variable (for exemple : text size in keyboard dialog)
        ///
        uint32_t Long[2];

        ///
        /// @brief Dialog data pointer.
        ///
        void *Pointer;

    public:
        Xila_Class::Event Event(const __FlashStringHelper *, uint8_t, const __FlashStringHelper * = NULL, const __FlashStringHelper * = NULL, const __FlashStringHelper * = NULL);
        Xila_Class::Event Color_Picker(uint16_t &Color);
        Xila_Class::Event Open_File(File &File_To_Open);
        Xila_Class::Event Dialog_Open_Folder(File &Folder_To_Open);
        Xila_Class::Event Save_File(File &File_To_Save);
        Xila_Class::Event Keyboard(char *Char_Array_To_Get, size_t Char_Array_Size = 189, bool Masked_Input = false);
        // to do : Xila_Class::Event Keyboard_Difalog(float& Number_To_Get) (and more overload);
        Xila_Class::Event Keypad(float &Number_To_Get);

        Dialog_Class();

        friend class Xila_Class;
        friend class Shell_Class;
    } Dialog;

    //==============================================================================//

    ///
    /// @brief Display class
    ///
    class Display_Class : public Nextion_Display_Class
    {
    protected:
        uint8_t Brightness;
        uint16_t Standby_Time;
        uint8_t Receive_Pin;
        uint8_t Send_Pin;

        char Tag = 0;

        Xila_Class::Event Load_Registry();
        Xila_Class::Event Save_Registry();

    public:
        ///
        /// @brief Prefixs used to differienciate exchanged data between display, core and software
        ///
        enum Prefixs
        {
            Instruction = '#',
            Variable_String = 's',
            Variable_Long = 'l',
        };

        ///
        /// @brief Default system colors.
        ///
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

        ///
        /// @brief Xila_16 special characters list.
        ///
        enum Xila_16
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

        ///
        /// @brief Xila_32 special characters list.
        ///
        enum Font_32
        {
            Exclamation_Mark = 127,
            Question_Mark,
            Cross
        };

        ///
        /// @brief Image offsets list.
        ///
        /// @details All image offset, used by included software to keep track of picture offset
        ///
        enum Image_Offset
        {
            Shell = 0,
            Calculator = 20,
            Clock = 21,
            Image_Viewer = 22,
            Internet_Browser = 23,
            Music_Player = 24,
            Oscilloscope = 33,
            Paint = 34,
            Periodic = 35,
            Piano = 37,
            Pong = 41,
            Simon = 42,
            Text_Editor = 43,
            Tiny_Basic = 44
        };

        ///
        /// @brief Pages list
        ///
        enum Pages_Offset
        {

        };

        ///
        /// @brief Font list
        ///
        enum Font
        {
            Regular_16 = 0, /*!< Roboto Regular 16 px (+ special character), main font used almost everywhere. */
            Mono_16,
            Regular_24, /*!< Robot Regular 24 px (+ special character), secondary font used sometimes. */
            Regular_32, /*!< Roboto Regular 32 px (+ special character), secondary font used sometimes. */
            Regular_48
        };

        static void Incomming_String_Data_From_Display(const char *, uint8_t);
        static void Incomming_Numeric_Data_From_Display(uint32_t);
        static void Incomming_Event_From_Display(uint8_t);

        friend class Xila_Class;
        friend class Shell_Class;
    } Display;

    //==============================================================================//

#if SD_MODE == 0

    ///
    /// @brief Drive class (SD MMC)
    ///
    class Drive_Class : public FS
    {
    protected:
        sdmmc_card_t *_card;

    public:
        Drive_Class(FSImpltPtr impl);
        bool begin(const char *mountpoint = "/sdcard", bool mode1bit = false);
        void end();
        sdcard_type_t cardType();
        uint64_t cardSize();
        uint64_t totalBytes();
        uint64_t usedBytes();

        //Custom

        Xila_Class::Event Copy(File &Origin_File, File &Destination_File);
        Xila_Class::Event Get_Name(File const &File, char *File_Name_Buffer, size_t Size);
        uint16_t Count_Files(File &Folder);

        friend class Xila_Class;
        friend class Shell_Class;
    };

#elif SD_MODE == 1

    ///
    /// @brief Drive class (SD SPI)
    ///
    class Drive_Class : public FS
    {
    protected:
        uint8_t _pdrv;

    public:
        Drive_Class(FSImplPtr impl);
        bool begin(uint8_t ssPin = SS, SPIClass &spi = SPI, uint32_t frequency = 4000000, const char *mountpoint = "/sd", uint8_t max_files = 5);
        void end();
        sdcard_type_t cardType();
        uint64_t cardSize();
        uint64_t totalBytes();
        uint64_t usedBytes();

        //Custom

        Xila_Class::Event Copy(File &Origin_File, File &Destination_File);
        Xila_Class::Event Get_Name(File const &File, char *File_Name_Buffer, size_t Size);
        uint16_t Count_Files(File &Folder);

        friend class Xila_Class;
        friend class Shell_Class;
    } Drive;

#endif

    ///
    /// @brief Keyboard class
    ///
    class Keyboard_Class
    {
    protected:
        // -- Methods
        Xila_Class::Event Load_Registry();
        Xila_Class::Event Save_Registry();

        enum Key_Maps
        {
            American,
            German,
            French,
            Spanish,
            Italian,
            English
        };

        uint8_t Key_Map;

        uint8_t Data_Pin;
        uint8_t Clock_Pin;

        inline void Begin();

    public:
        // -- Methods
        uint8_t Read();
        uint8_t Read_Raw();

        uint8_t Available();

        void Clear();

        // -- Keyboard constructor / destructor

        Keyboard_Class();

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;

    } Keyboard;

    //==============================================================================//

    ///
    /// @brief Power management module
    ///
    class Power_Class : public Battery_Class
    {
    protected:
        // -- Attributes
        volatile uint8_t Button_Counter;
        portMUX_TYPE Button_Mutex;

        // -- Methods
        void static IRAM_ATTR Button_Handler();

        void Check_Button();

    public:
        // -- Constructors / Destructors
        Power_Class();

        // -- Friendship
        friend Xila_Class;
        friend class Shell_Class;
    } Power;

    //==============================================================================//

    ///
    /// @brief Software management module
    ///
    class Software_Management_Class
    {
    protected:
        uint32_t Watchdog_Timer;
        uint8_t Watchdog_State;

        void Check_Watchdog();

        ///
        /// @brief Openned software pointer array
        ///
        /// Openned[0] : Maximized software
        /// Openned[1 - 7] : All openned software (Slot 1 is for Shell)
        ///
        Software_Class *Openned[8] = {NULL};

        ///
        /// @brief All software handle pointers.
        ///
        Software_Handle_Class *Handle[MAXIMUM_SOFTWARE] = {NULL};

        void Maximize_Shell();
        void Execute_Shell(Xila_Instruction const &Command);

        inline uint8_t Seek_Open_Software_Handle(Software_Handle_Class const &);
        void Add_Handle(Software_Handle_Class &);

        Xila_Class::Event Force_Close(Software_Handle_Class const &Software_Handle);

    public:
        Xila_Class::Event Open(Software_Handle_Class const &Software_Handle);
        void Minimize(Software_Handle_Class const &Software_Handle);
        Xila_Class::Event Maximize(Software_Handle_Class const &);
        void Close(Software_Handle_Class const &Software_Handle);

        void Feed_Watchdog(Software_Handle_Class const &Software_Handle);

        Software_Management_Class();

        friend class Xila_Class;
        friend class Shell_Class;

    } Software;

    //==============================================================================//

    ///
    /// @brief Sound class API
    ///
    class Sound_Class
    {
    protected:
        const static uint8_t Left_Channel = 0;
        const static uint8_t Right_Channel = 1;
        const static uint8_t Custom_Channel = 2;

        Xila_Task_Handle Task_Handle;

        uint8_t Custom_Pin;

        File Music_File;

        enum State
        {
            Stopped,
            Playing,
            Paused
        };

        // 0 : stopped
        // 1 : playing
        // 2 : paused
        // 3 : tone

        Xila_Class::Event Save_Registry();
        Xila_Class::Event Load_Registry();

    public:
        enum Event
        {
            Failed_To_Get_RTC_Period,
            Failed_To_Open_File,
            Failed_To_Get_Metadata,
            Failed_To_Load_ULP_Program,
            Failed_To_Create_Task,
            Not_RIFF_Compliant,
            Not_WAVE_Compliant,
            Incompatible_Block_ID,
            Not_A_PCM_File,
            Unsupported_Bit_Depth,
            Unsupported_Sampling_Rate,
            Unsupported_Channel_Number,
        };

        void Set_Output_Channel(uint8_t Number_Output_Channel);

        void Set_Volume(uint16_t); // volume between 0 and 255
        uint8_t Get_Volume();

        void Set_Balance(uint8_t);

        uint8_t Play(File &File_To_Play);
        uint8_t Play(const char *File_Path_Or_Host, const char *User = "", const char *Password = "");

        uint8_t Resume();
        void Pause();
        void Mute();
        void Stop();

        void Set_Current_Time(uint32_t Time);
        uint32_t Get_Current_Time();
        uint32_t Get_Total_Time();
        void Set_Offset_Time(int16_t Time);
        uint8_t Get_State();

        void Tone(uint16_t const &Frequency, uint32_t const &Duration = 0, uint8_t const &Pin = 0xFF);
        void No_Tone(uint8_t const &Pin = 0xFF); // no tone (0xFF default pins)

        static void Task(void *);

        Sound_Class();
        ~Sound_Class();

        friend void audio_eof_mp3(const char *);

        friend Xila_Class;
        friend class Shell_Class;
    } Sound;

    //==============================================================================//

    ///
    /// @brief System module API
    ///
    class System_Class
    {
    protected:
        // System's task :
        Xila_Task_Handle Task_Handle;

        ///
        /// @brief Device name used as Network hostname ...
        ///
        char Name[24];

        Xila_Class::Event Load_Registry();
        Xila_Class::Event Save_Registry();

        Xila_Class::Event Create_Dump();
        Xila_Class::Event Load_Dump();

        Xila_Class::Event Load_Executable(File Executable_File, uint8_t Type = 'M');

        enum System_States
        {
            Default,
            New_Installation,
        } State;

        ///
        /// @brief Panic codes used by the panic handler ("Grey screen").
        ///
        enum Panic_Code
        {
            Missing_System_Files,
            Damaged_System_Registry,
            Installation_Conflict,
            System_Drive_Failure,
            Low_Memory,
            Memory_Corruption,
        };

        void Panic_Handler(Panic_Code Panic_Code);

    public:
        const char *Get_Name();

        uint32_t Get_Free_Heap();

        void First_Start_Routine();
        void Second_Start_Routine();

        void Execute_Startup_Function();

        void Shutdown();
        void Restart();
        void Hibernate();
        void Deep_Sleep();

        void Start();
        void Start(Software_Handle_Class *Software_Package, uint8_t Size);

        uint32_t Random() const;
        uint32_t Random(uint32_t Upper_Bound) const;
        uint32_t Random(uint32_t Low_Bound, uint32_t Upper_Bound) const;

        void Refresh_Header();

        static void Task(void *);

        System_Class();

        friend class Xila_Class;
        friend class Shell_Class;
    } System;

    //==============================================================================//

    ///
    /// @brief Task management module
    ///
    class Task_Class
    {
    protected:
        ///
        /// @brief Tasks priorities.
        ///
        enum Priorities
        {
            Idle_Task = 0,
            Software_Task,
            System_Task,
            Driver_Task
        };

        Xila_Class::Event Create(Xila_Task_Function Task_Function, const char *Task_Name, size_t Stack_Size, void *pvParameters, uint16_t Priority, Xila_Task_Handle *Task_Handle);

    public:
        // -- Task management -- //
        Xila_Class::Event Create(Xila_Task_Function Task_Function, const char *Task_Name, size_t Stack_Size, void *pvParameters = NULL, Xila_Task_Handle *Task_Handle = NULL) const;
        void Suspend(Xila_Task_Handle Task_To_Suspend = NULL) const;
        void Resume(Xila_Task_Handle Task_To_Resume) const;
        void Delete(Xila_Task_Handle Task_To_Delete = NULL) const;

        void Delay(uint32_t Delay_In_Millisecond) const;

        friend Xila_Class;
        friend class Shell_Class;
    } Task;

    //==============================================================================//

    ///
    /// @brief
    ///
    class Time_Class
    {
    protected:
        // -- Attributes
        int32_t GMT_Offset;
        int16_t Daylight_Offset;

        Xila_Time Current_Time;
        time_t Now;
        char NTP_Server[32];

        // -- Methods
        Xila_Class::Event Load_Registry();
        Xila_Class::Event Save_Registry();

    public:
        // -- Methods
        Xila_Time Get_Time();
        void Synchronise();

        uint32_t Milliseconds() const;

        // -- Time constructor / destructor

        Time_Class();

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;

    } Time;

    //==============================================================================//

    ///
    /// @brief WiFi class
    ///
    class WiFi_Class : public WiFiGenericClass, public WiFiSTAClass, public WiFiScanClass, public WiFiAPClass
    {
    protected:
        bool prov_enable;
        char Password[82];

    public:
        void printDiag(Print &dest);

        void enableProv(bool status);
        bool isProvEnabled();

        WiFi_Class();

        using WiFiGenericClass::channel;

        using WiFiSTAClass::BSSID;
        using WiFiSTAClass::BSSIDstr;
        using WiFiSTAClass::RSSI;
        using WiFiSTAClass::SSID;

        using WiFiScanClass::BSSID;
        using WiFiScanClass::BSSIDstr;
        using WiFiScanClass::channel;
        using WiFiScanClass::encryptionType;
        using WiFiScanClass::RSSI;
        using WiFiScanClass::SSID;

        void Set_Credentials(const char *Name, const char *Password);

        Xila_Class::Event Load_Registry();
        Xila_Class::Event Save_Registry();

        friend class WiFiClient;
        friend class WiFiServer;
        friend class WiFiUDP;

        friend Xila_Class;
        friend class Shell_Class;

    } WiFi;

    //==============================================================================//

    Xila_Class();
    ~Xila_Class();
};


#include "Task.hpp"
#include "Time.hpp"
#include "System.hpp"

#endif