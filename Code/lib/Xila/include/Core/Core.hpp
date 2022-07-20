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
/// Copyright (c) 2021 Alix ANNERAUD
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
/// The above notice and this permission notice shall be included in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
///
#ifndef CORE_HPP_INCLUDED
#define CORE_HPP_INCLUDED

#ifdef __cplusplus

#else

#error Xila requires a C++ complier, please change file extension to .cpp

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

// -- SPI library
#include "SPI.h"



// -- Registry management library
#include "ArduinoJson.h" //used to store registries
#include "StreamUtils.h"

// -- Debug library
#include <ArduinoTrace.h>

//----------------------------------------------------------------------------//
//                          Include all project file                          //
//----------------------------------------------------------------------------//

// -- Configuration file (at compile time)
#include "Configuration.hpp" // default values
#include "Modules/Log.hpp"
#include "Modules/Path.hpp" // Path list

// -- Components
#include "Graphical_Interface\Graphical_Interface.hpp"
#include "Software\Software.hpp"
#include "Mathematics\Mathematics.hpp"
#include "Commmunication\WiFi.hpp"

//----------------------------------------------------------------------------//
//                                Define Const                                //
//----------------------------------------------------------------------------//

///
/// @brief Xila time class
///

//----------------------------------------------------------------------------//
//

///
/// @brief String to 16 bits encoded address conversion macro.
///
#define Address(x, y) (x * 256 + y)

///
/// @brief String to 16 bits encoded instruction conversion macro.
///
#define Instruction(Sender, Argument_1, Argument_2, Argument_3) (Sender * 16777216 + Argument_1 * 65536 + Argument_2 * 256 + Argument_3)

///
/// @brief Memory chunk macro.
///
#define Memory_Chunk(x) (x * 1024)

//----------------------------------------------------------------------------//
//                         Define Xila Core API                               //
//----------------------------------------------------------------------------//

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
public:
    //==============================================================================//
    //                                 Constructors                                 //
    //==============================================================================//

    Xila_Class();
    ~Xila_Class();

    //==============================================================================//
    //                              Enumerations & Type definition                  //
    //==============================================================================//

    typedef Software_Class Software_Type;

    Account_Class Account;

    Display_Class Display;

    //==============================================================================//
    ///
    /// @brief Drive class
    ///
    class Drive_Class
    {
    public:
        ///
        /// @brief Drive type.
        ///
        typedef enum
        {
            None,  ///< None (nothing connected).
            MMC,   ///< MMC type.
            SD_SC, ///< SD type.
            SD_HC, ///< SD HC type.
            Unknow ///< Unknow type.
        } Sd_Card_Type;

        uint64_t Size();
        Sd_Card_Type Type();

        bool Exists(const char *Path);
        bool Exists(const String &Path);

        bool Make_Directory(const char *Path);
        bool Make_Directory(const String &Path);

        bool Remove_Directory(const char *Path);
        bool Remove_Directory(const String &Path);

        File Open(const char *Path, const char *Mode = "r");
        File Open(const String &Path, const char *Mode = "r");

        bool Remove(const char *Path);
        bool Remove(const String &Path);

        bool Rename(const char *Path_From, const char *Path_To);
        bool Rename(const String &Path_From, const String &Path_To);

        uint64_t Total_Bytes();
        uint64_t Used_Bytes();

        // Custom

        Result_Type Copy(File &Origin_File, File &Destination_File);
        Result_Type Get_Name(File const &File, char *File_Name_Buffer, size_t Size);
        uint16_t Count_Items(File &Folder);

        // -- Constructor
        Drive_Class();

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;

    protected:
        void End();

        bool Begin(uint8_t Slave_Select_Pin = SS, SPIClass &spi = SPI, uint32_t Frequency = 4000000, const char *Mount_Point = "/sd", uint8_t Maximum_Files = 5);

    } Drive;

    ///=============================================================================//
    ///
    /// @brief Flash wrapper class.
    ///
    class Flash_Class
    {
    public:
        // -- Methods
        uint32_t Get_Size();
        uint32_t Get_Speed();
        FlashMode_t Get_Mode();

        Result_Type Read(uint32_t Offset, uint32_t *Data, size_t Size);

        Result_Type Partition_Read(const esp_partition_t *Partition, uint32_t Offset, uint32_t *Data, size_t Size);

        uint32_t Get_Sketch_Size();
        String Get_Sketch_MD5();
        uint32_t Get_Sketch_Free_Space();

    private:
        // -- Methods
        Result_Type Set_Boot_Partition(const uint8_t Partition_Number);

        Result_Type Erase_Sector(uint32_t Sector);
        Result_Type Write(uint32_t Offset, uint32_t *Data, size_t Size);

        Result_Type Partition_Write(const esp_partition_t *Partition, uint32_t Offset_, uint32_t *Data, size_t Size);
        Result_Type Partition_Erase_Range(const esp_partition_t *Partition, uint32_t Offset, size_t Size);

        static uint32_t Sketch_Size(sketchSize_t Response);
        uint32_t Magic_Size(uint8_t Byte);
        uint32_t Magic_Speed(uint8_t Byte);
        FlashMode_t Magic_Mode(uint8_t Byte);

        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;
    } Flash;

    //==============================================================================//
    // @brief Graphic interface wrapper
    //==============================================================================//
    typedef Graphic_Interface_Class Graphic_Interface;

    //==============================================================================//
    ///
    /// @brief GPIO management class
    ///
    class GPIO_Class
    {
    public:
        GPIO_Class();

        // -- Pin mode
        void Set_Mode(uint8_t Pin, uint8_t Mode);

        Result_Type Valid_Output_Pin(uint8_t Pin);

        // -- Digital
        void Digital_Write(uint8_t Pin, uint8_t State);
        int16_t Digital_Read(uint8_t Pin);

        Result_Type Valid_Digital_Pin(uint8_t Pin);

        // -- Analog
        uint16_t Analog_Read(uint8_t Pin);
        uint32_t Analog_Read_Milli_Volts(uint8_t Pin);

        void Set_Voltage_Reference_Pin(uint8_t Pin);
        void Set_Read_Resolutions(uint8_t Bits_Resolution);
        void Set_Width(uint8_t Bits_Width);
        void Set_Clock_Divider(uint8_t Clock_Divider);

        void Set_Attenuation(uint8_t Attenuation);
        void Set_Attenuation(uint8_t Pin, uint8_t Attenuation);

        // -- Interrupts
        void Attach_Interrupt(uint8_t Pin, void (*Function_Pointer)(void), int16_t Mode);
        void Attach_Interrupt_Argument(uint8_t Pin, void (*Function_Pointer)(void *), void *Argument, int16_t Mode);
        void Detach_Interrupt(uint8_t Pin);

        ///
        /// @brief Digital IOs states.
        ///
        enum Digital_States : uint8_t
        {
            Low = LOW,   ///< Low state.
            High = HIGH, ///< High state.

        };

        ///
        /// @brief IOs modes.
        ///
        enum Modes : uint8_t
        {
            Input = 0x01,             ///< Input
            Output = 0x02,            ///< Output
            Pull_Up = 0x04,           ///< Pull up resistor.
            Input_Pull_Up = 0x05,     ///< Input with a pull up resistor.
            Pull_Down = 0x08,         ///< Pull down resistor.
            Input_Pull_Down = 0x09,   ///< Input with a pull down resistor.
            Open_Drain = 0x10,        ///< Open drain (nothing connected).
            Output_Open_Drain = 0x12, ///< Output with open drain by default.
            Special = 0xF0,           ///< Special
            Function_1 = 0x00,        ///< Function 1
            Function_2 = 0x20,        ///< Function 2
            Function_3 = 0x40,        ///< Function 3
            Function_4 = 0x60,        ///< Function 4
            Function_5 = 0x80,        ///< Function 5
            Function_6 = 0xA0,        ///< Function 6
            Analog = 0xC0             ///< Analog
        };

        ///
        /// @brief Interrupt modes.
        ///
        enum Interrupt_Modes : uint8_t
        {
            Disabled = 0x00,  ///< No interrupt.
            Rising = 0x01,    ///< Triggered when signal rise.
            Falling = 0x02,   ///< Triggered when signal fall.
            Change = 0x03,    ///< Triggered when signal fall or rise.
            On_Low = 0x04,    ///< Triggered on low state.
            On_High = 0x05,   ///< Triggered on high state.
            On_Low_WE = 0x0C, ///< Triggered on low state.
            On_High_WE = 0x0D ///< Triggered on high state.
        };

        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;
    } GPIO;

    //==============================================================================//
    ///
    /// @brief Keyboard class
    ///
    class Keyboard_Class
    {
    public:
        // -- Keyboard constructor / destructor

        Keyboard_Class();

        ///
        /// @brief Keyboard available layout.
        ///
        enum Layouts
        {
            American, ///< American QWERTY layout.
            German,   ///< German QWERTY layout.
            French,   ///< French AZERTY layout.
            Spanish,  ///< Spanish QWERTY layout.
            Italian,  ///< Italian QWERTY layout.
            English   ///< English QWERTY layout.
        };

        ///
        /// @brief Special keys enumeration.
        ///
        enum Special_Keys
        {
            Tab = 9,
            Enter = 13,
            Backspace = 127,
            Escape = 27,
            Insert = 0,
            Delete = 127,
            Home = 0,
            End = 0,
            Page_Up = 25,
            Page_Down = 26,
            Arrow_Up = 11,
            Arrow_Down = 10,
            Arrow_Left = 8,
            Arrow_Right = 21,
            F1 = 0,
            F2 = 0,
            F3 = 0,
            F4 = 0,
            F5 = 0,
            F6 = 0,
            F7 = 0,
            F8 = 0,
            F9 = 0,
            F10 = 0,
            F11 = 0,
            F12 = 0,
            Scroll = 0,
            Euro_Sign = 0,
            // Custom regional keys
            Inverted_Exclamation = 161,
            Cent_Sign,
            Pound_Sign,
            Currency_Sign,
            Yen_Sign,
            Broken_Bar,
            Secontion_Sign,
            Diaeresis,
            Copyright_Sign,
            Feminine_Ordinal,
            Left_Double_Angle_Quote,
            Not_Sign,
            Hyphen,
            Registered_Sign,
            Macron,
            Degree_Sign,
            Plus_Minus_Sign,
            Superscript_Two,
            Superscript_Three,
            Acute_Accent,
            Micro_Sign,
            Pilcrow_Sign,
            Middle_Dot,
            Cedilla,
            Superscript_One,
            Masculine_Ordinal,
            Right_Double_Angle_Quote,
            Fraction_One_Quarter,
            Fraction_One_Half,
            Fraction_Three_Quarters,
            Inverted_Question_Mark,
            A_Grave,
            A_Acute,
            A_Circumflex,
            A_Tilde,
            A_Diaeresis,
            A_Ring_Above,
            AE,
            C_Cedilla,
            E_Grave,
            E_Acute,
            E_Circumflex,
            E_Diaeresis,
            I_Grave,
            I_Acute,
            I_Circumflex,
            I_Diaeresis,
            Eth,
            N_Tilde,
            O_Grave,
            O_Acute,
            O_Circumflex,
            O_Tilde,
            O_Diaeresis,
            Multiplication,
            O_Stroke,
            U_Grave,
            U_Acute,
            U_Circumflex,
            U_Diaeresis,
            Y_Acute,
            Thorn,
            Sharp_S,
            a_Grave,
            a_Acute,
            a_Circumflex,
            a_Tilde,
            a_Diaeresis,
            a_Ring_Above,
            ae,
            c_Cedilla,
            e_Grave,
            e_Acute,
            e_Circumflex,
            e_Diaeresis,
            i_Grave,
            i_Acute,
            i_Circumflex,
            i_Diaeresis,
            eth,
            n_Tilde,
            o_Grave,
            o_Acute,
            o_Circumflex,
            o_Tilde,
            o_Diaeresis,
            Division,
            o_Stroke,
            u_Grave,
            u_Acute,
            u_Circumflex,
            u_Diaeresis,
            y_Acute,
            thorn,
            y_Diaeresis
        };

        // -- Methods
        uint8_t Read();
        uint8_t Read_Raw();

        uint8_t Available();

        void Clear();

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;

    protected:
        // -- Methods
        Result_Type Load_Registry();
        Result_Type Save_Registry();

        uint8_t Layout;

        uint8_t Data_Pin;
        uint8_t Clock_Pin;

        void Begin();

    } Keyboard;

    Mathematics_Class Mathematics;

    Memory_Class Memory;

    //==============================================================================//
    ///
    /// @brief Power management module.
    ///
    class Power_Class : public Battery_Class
    {

    protected:
        // -- Constructors / Destructors
        Power_Class();

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;

        // -- Methods

        Result_Type Save_Registry();
        Result_Type Load_Registry();

        // -- Attributes
        ///
        /// @brief Button press counter.
        ///
        volatile uint8_t Button_Counter;

        ///
        /// @brief Button press timer, used to differentiate a short press from a long press.
        ///
        volatile uint32_t Button_Timer;

        ///
        /// @brief Button interrupt mutex.
        ///
        portMUX_TYPE Button_Mutex;

        // -- Methods -- //
        void static IRAM_ATTR Button_Interrupt_Handler();

        void Check_Button();
        void Deep_Sleep();

    } Power;

    //==============================================================================//
    ///
    /// @brief Software management module.
    ///
    class Software_Management_Class
    {
    public:
        Software_Management_Class();

        Xila_Class::State Get_State(Xila_Class::Software_Handle const &Software_Handle);

        Result_Type Open(Xila_Class::Software_Handle const &Software_Handle);
        void Minimize(Xila_Class::Software_Handle const &Software_Handle);
        Result_Type Maximize(Xila_Class::Software_Handle const &);
        void Close(Xila_Class::Software_Handle const &Software_Handle);

        void Feed_Watchdog(Xila_Class::Software_Handle const &Software_Handle);

        // -- Friendship -- //
        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;

    protected:
        // -- Attributes -- //

        uint32_t Watchdog_Timer;
        uint8_t Watchdog_State;

        ///
        /// @brief Openned software pointer array
        ///
        /// Openned[0] : Maximized software
        /// Openned[1 - 7] : All openned software (Slot 1 is for Shell)
        ///
        Xila_Class::Software *Openned[8] = {NULL};

        ///
        /// @brief All software handle pointers.
        ///
        Xila_Class::Software_Handle *Handle[Maximum_Software] = {NULL};

        // -- Methods -- //

        void Defrag();

        void Check_Watchdog();

        void Shell_Maximize();
        void Shell_Send_Instruction(Xila_Class::Instruction);
        void Shell_Set_Variable(Xila_Class::Address, uint8_t, const void *);

        uint8_t Seek_Open_Software_Handle(Xila_Class::Software_Handle const &Software_Handle);

        uint8_t Get_Software_Handle(Xila_Class::Software_Handle const &);
        void Add_Handle(Xila_Class::Software_Handle &);

        Result_Type Force_Close(Xila_Class::Software_Handle const &Software_Handle);

    } Software_Management;

    //==============================================================================//

    ///
    /// @brief Sound class API
    ///
    class Sound_Class
    {
    public:
        Sound_Class();
        ~Sound_Class();

        void Set_Channels(uint8_t Channels);

        void Set_Volume(uint8_t Volume);
        uint8_t Get_Volume();

        uint8_t Play(File &File_To_Play);
        uint8_t Play(const char *File_Path_Or_Host, const char *User = "", const char *Password = "");

        void Set_Loop(bool Loop);

        uint32_t Get_File_Size();
        uint32_t Get_File_Position();
        bool Set_File_Position(uint32_t Position);
        bool Set_File_Seek(const float Speed);

        uint32_t Get_Sample_Rate();
        uint8_t Get_Bit_Resolution();
        uint8_t Get_Channels();
        uint32_t Get_Bit_Rate();

        void Set_Tone(int8_t Gain_Low_Pass, int8_t Gain_Band_Pass, int8_t Gain_High_Pass);

        void Set_Output(uint8_t Output);

        ///
        /// @brief Output DAC.
        ///
        enum : uint8_t
        {
            Internal_DAC = 0, ///< Internal DAC.
            External_DAC      ///< External DAC.
        };

        void Resume();
        void Pause();
        void Mute();
        void Stop();

        void Set_Current_Time(uint16_t Time);
        uint32_t Get_Current_Time();
        uint32_t Get_Duration();

        bool Set_Pinout(uint8_t Bit_Clock_Pin, uint8_t Frame_Clock_Pin, uint8_t Data_Out_Pin, uint8_t Data_In_Pin = (-1));
        void Set_Balance(int8_t Balance = 0);

        uint32_t Get_Total_Time();

        void Set_Time_Offset(int16_t Time);
        uint8_t Get_State();

        void Tone(uint16_t Frequency, uint32_t Duration = 0, uint8_t Pin = 0xFF);
        void No_Tone(uint8_t Pin = 0xFF); // no tone (0xFF default pins)

        static void Task(void *);

        ///
        /// @brief Sound class event type.
        ///
        enum Event
        {
            Failed_To_Get_RTC_Period,   ///< Failed to get ULP processor frequency.
            Failed_To_Open_File,        ///< Failed to open file.
            Failed_To_Get_Metadata,     ///< Failed to read file metadata (corrupted).
            Failed_To_Load_ULP_Program, ///< Failed to load program into ULP.
            Failed_To_Create_Task,      ///< Failed to create sound task.
            Not_RIFF_Compliant,         ///< Invalid metadata (RIFF).
            Not_WAVE_Compliant,         ///< Invalid metadata (WAVE).
            Incompatible_Block_ID,      ///< Incompatible bloc ID.
            Not_A_PCM_File,             ///< Failed to read a non PCM file.
            Unsupported_Bit_Depth,      ///< Unsupported bit depth.
            Unsupported_Sampling_Rate,  ///< Unsupported sampling rate.
            Unsupported_Channel_Number, ///< Unsupported channel number.
        };

        ///
        /// @brief Playing state.
        ///
        enum State
        {
            Stopped, ///< Stopped (no file loaded, no task running)
            Playing, ///< Currently playing.
            Paused   ///< Paused play.
        };

        friend void audio_eof_mp3(const char *);

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;

        ///
        /// @brief Channel enumeration.
        ///
        enum Channels
        {
            Left_Channel = 0,  ///< Left channel only.
            Right_Channel = 1, ///< Right channel only.
            Custom_Channel = 2 ///< Custom channel.
        };

    protected:
        // -- Attributes -- //

        ///
        /// @brief Sound task handle.
        ///
        Xila_Class::Task_Handle Task_Handle;

        ///
        /// @brief Custom pin to tone.
        ///
        uint8_t Custom_Pin;

        ///
        /// @brief Music file.
        ///
        File Music_File;

        ///
        /// @brief Custom data pin.
        ///
        uint8_t Data_Pin;

        ///
        /// @brief Custom word select pin.
        ///
        uint8_t Word_Select_Pin;

        ///
        /// @brief Custom clock pin.
        ///
        uint8_t Clock_Pin;

        uint8_t Output;

        // -- Methods -- //
        Result_Type Save_Registry();
        Result_Type Load_Registry();

        void Begin();

    } Sound;

    //==============================================================================//

    ///
    /// @brief System module API
    ///
    class System_Class
    {
    public:
        // -- Constructors
        System_Class();
        ~System_Class();

        // -- Methods
        const char *Get_Device_Name();
        uint64_t Get_eFuse_MAC();
        uint8_t Get_Chip_Revision();
        const char *Get_Chip_Model();
        uint32_t Get_Chip_Cores();
        uint32_t Get_CPU_Frequency();
        const char *Get_SDK_Version();

        void Start();
        void Start(Xila_Class::Software_Handle **Software_Package, uint8_t Size);

        void Shutdown();
        void Restart();
        void Hibernate();

        void Refresh_Header();

        static void Task(void *);

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;

    protected:
        // System's task :
        Xila_Class::Task_Handle Task_Handle;

        ///
        /// @brief Device name used as Network hostname ...
        ///
        char Device_Name[25];

        // -- Methods

        Result_Type Load_Registry();
        Result_Type Save_Registry();

        Result_Type Save_Dump();
        Result_Type Load_Dump();

        Result_Type Load_Executable(File Executable_File);

        void Second_Sleep_Routine();

        ///
        /// @brief Panic codes used by the panic handler ("Grey screen").
        ///
        enum Panic_Code
        {
            Missing_System_Files,     ///< Missing system files (registries).
            Damaged_System_Registry,  ///< Damaged system registry.
            Installation_Conflict,    ///< Installation conflict (between MCU and Display or Drive).
            System_Drive_Failure,     ///< System drive failure (disconnected).
            Failed_To_Update_Display, ///< Failed to update display.
            Low_Memory,               ///< Low memory (fragmentation, too much software openned).
            Memory_Corruption,        ///< Memory corruption.
        };

        void Panic_Handler(Panic_Code Panic_Code);

        void First_Start_Routine();
        void Second_Start_Routine();

        void Execute_Startup_Function();
    } System;

    //==============================================================================//

    ///
    /// @brief Task management module
    ///
    class Task_Class
    {

    public:
        typedef TickType_t Tick_Type;

        // -- Communication between tasks

        typedef SemaphoreHandle_t Semaphore_Handle_Type;
        typedef StaticSemaphore_t Static_Semaphore_Type;
        ///
        /// @brief
        ///
        class Semaphore_Class
        {
        public:
            typedef TickType_t Tick_Type;

            enum
            {
                Binary,
                Counting,
                Mutex,
                Recursive_Mutex
            };

            static Semaphore_Handle_Type Create(uint8_t Type, UBaseType_t Initial_Count, UBaseType_t Maximum_Count);
            static Semaphore_Handle_Type Create_Static(uint8_t Type, Static_Semaphore_Type *Semaphore_Buffer, UBaseType_t Initial_Count = 0, UBaseType_t Maximum_Count = 0);
            static void Delete(Semaphore_Handle_Type Semaphore_Handle);
            static void Take(Semaphore_Handle_Type Semaphore_Handle);
            static void Give(Semaphore_Handle_Type Semaphore_Handle);
            static void Take_From_ISR(Semaphore_Type Semaphore_Handle, signed UBaseType_t *Higher_Priority_Task_Woken);
            static void Give_From_ISR(Semaphore_Type Semaphore_Handle, signed UBaseType_t *Higher_Priority_Task_Woken);
            static void Take_Recursive(Semaphore_Handle_Type Semaphore_Handle, Tick_Type Ticks_To_Wait);
            static void Give_Recursive(Semaphore_Handle_Type Semaphore_Handle);
            static Xila_Class::Task_Handle Get_Mutex_Holder(Semaphore_Handle_Type Semaphore_Handle);
            static UBaseType_t Get_Count(Semaphore_Handle_Type Semaphore);
        };

        // -- Friendship
        friend Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;

    protected:
        ///
        /// @brief Tasks priorities.
        ///
        enum Priorities
        {
            Idle_Task = 0, ///< Idle task (only for statistics purpose).
            Software_Task, ///< Software task (lowest priority).
            System_Task,   ///< System task.
            Driver_Task    ///< Driver task (highest priority).
        };

    } Task;


    WiFi_Class WiFi;

private:
    //==============================================================================//
    //                                    Attributes                                //
    //==============================================================================//

    ///
    /// @brief Current instance pointer. Help to prevent from corruption.
    ///
    static Xila_Class *Instance_Pointer;
};

bool operator==(Xila_Class::Software_Handle const &a, Xila_Class::Software_Handle const &b);

extern Xila_Class Xila;

#endif