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

// -- SPI library
#include "SPI.h"

// -- Time library
#include "time.h"

// -- Registry management library
#include "ArduinoJson.h" //used to store registries
#include "StreamUtils.h"

// -- WiFi libraries
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

// -- Debug library
#include <ArduinoTrace.h>

// -- Driver headers
#include "Nextion_Library.hpp"
#include "Battery_Library.hpp"

//----------------------------------------------------------------------------//
//                          Include all project file                          //
//----------------------------------------------------------------------------//

// -- Configuration file (at compile time)
#include "Configuration.hpp" // default values
#include "Modules/Path.hpp"  // Path list

//----------------------------------------------------------------------------//
//                                Define Const                                //
//----------------------------------------------------------------------------//

///
/// @brief Xila time class
///

//----------------------------------------------------------------------------//
//

///
/// @brief Instruction conversion macro.
///
#define Instruction(x, y) (x * 256 + y)

///
/// @brief Address conversion macro.
///
#define Address(x, y) (x * 256 + y)

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

    ///
    /// @brief Xila Address type.
    ///
    typedef uint16_t Address;

    ///
    /// @brief Image type.
    ///
    typedef uint8_t Image;

    ///
    /// @brief Xila instruction type.
    ///
    typedef uint16_t Instruction;

    ///
    /// @brief Page type.
    ///
    typedef uint8_t Page;

    ///
    /// @brief Task type
    ///
    typedef void (*Task_Function)(void *);

    ///
    /// @brief Task handle type
    ///
    typedef void *Task_Handle;

    ///
    /// @brief Instructions used by the core (with the prefix "#").
    ///
    enum : Xila_Class::Instruction
    {
        // -- General instructions
        Idle = 0,
        // -- Software state instructions
        Open = 'O',
        Close = 'C',
        Maximize = 'M',
        Minimize = 'm',
        // -- System state instructions
        Shutdown = 200,
        Restart,
        Hibernate = 'H',
        Watchdog = 'W',
        // -- Shell specials instructions
        Desk = 'D',                // Open desk
        Dialog_Open_File = 'f',    // Open open file dialog
        Dialog_Open_Folder = 'F',  // Open open folder dialog
        Dialog_Save_File = 'e',    // Open save file dialog
        Dialog_Keyboard = 'K',     // Open keyboard dialog
        Dialog_Keypad = 'k',       // Open keyapd dialog
        Dialog_Color_Picker = 'c', // Open color picker dialog
        Dialog_Power = 'P',        // Open power dialog
        Dialog_Event = 'E',        // Open event dialog
        Dialog_Login = 'L',        // Open login dialog
        Dialog_Load = 'l'          // Open load dialog
    };

    ///
    /// @brief Variable type enumeration
    ///
    enum Variable_Types : uint8_t
    {
        Variable_Long = 'l',   ///< Long variable (64 bits)
        Variable_String = 's', ///< String variable (char array)
        Pointer = 'p',         ///< Point variable (pointer)
        Other = 'o'            ///< Other data types
    };

    ///
    /// @brief Software states
    ///
    typedef enum
    {
        Minimized, ///< Maximized state.
        Maximized  ///< Minimized state.
    } State;

    ///
    /// @brief Xila event type.
    ///
    typedef enum : uint8_t
    {
        Success = true,            ///< Success event.
        Error = false,             ///< Error event.
        Warning,                   ///< Warning event.
        Information,               ///< Information event.
        Question,                  ///< Question event.
        Button_1 = 0x31,           ///< Button 1 reply (equivalent to Yes reply).
        Button_2 = 0x32,           ///< Button 2 reply (equivalent to No reply).
        Button_3 = 0x33,           ///< Button 3 reply (equivalent to Cancel reply).
        Default_Yes = Button_1,    ///< Yes reply (equivalent to Button 1).
        Default_No = Button_2,     ///< No reply (equivalent to Button 2).
        Default_Cancel = Button_3, ///< Cancel reply (equivalent to Button 3).
        None
    } Event;

    ///
    /// @brief Color union.
    ///
    union Color
    {
        uint32_t Color;
        uint8_t Component;
    };

    class Software_Handle;

    //==============================================================================//
    ///
    /// @brief Software class.
    ///
    /// @details This API is used by core in order to communicate with the software.
    ///
    class Software
    {
    protected:
        // -- Constructor / Destructor
        Software(Xila_Class::Software_Handle &Software_Handle, uint8_t Queue_Size = Default_Instruction_Queue_Size);
        virtual ~Software();

        // -- Methods
        void Send_Instruction(Xila_Class::Instruction Intruction);

        ///
        /// @brief Convert 2 byte char instruction into Xila Instruction and send it.
        ///
        /// @param Instruction_Char_1 Instruction first byte
        /// @param Instruction_Char_2 Instruction second byte
        inline void Send_Instruction(char Instruction_Char_1, char Instruction_Char_2)
        {
            Send_Instruction(((uint16_t)Instruction_Char_1 << 8) | (uint16_t)Instruction_Char_2);
        }

        virtual void Set_Variable(Xila_Class::Address Address, uint8_t Type, const void *Variable);

        Xila_Class::Instruction Get_Instruction();

        void Set_Watchdog_Timeout(uint16_t Watchdog_Timeout = Default_Watchdog_Timeout);

        // -- Attributes

        ////
        /// @brief Software task handle.
        ///
        Xila_Class::Task_Handle Task_Handle;

        ///
        /// @brief Software handle pointer.
        ///
        Xila_Class::Software_Handle *Handle;

        friend class Xila_Class;
        friend class Shell_Class;

    private:
        ///
        /// @brief Temporary variable to receive current instruction from queue.
        ///
        Xila_Class::Instruction Current_Instruction;

        ///
        /// @brief Queue handle.
        ///
        QueueHandle_t Instruction_Queue_Handle;

        ///
        /// @brief Last software watchdog feed.
        ///
        uint32_t Last_Watchdog_Feed;

        ///
        /// @brief Watchdog defined timeout.
        ///
        uint16_t Watchdog_Timeout;
    };

    //==============================================================================//
    ///
    /// @class Software_Handle
    ///
    /// @brief Software handle used by Xila to manage each software.
    ///
    class Software_Handle
    {
    public:
        // -- Constructors / Destructor
        Software_Handle();
        Software_Handle(const char *Software_Name, uint8_t Icon_ID, Xila_Class::Software *(*Load_Function_Pointer)(), void (*Startup_Function_Pointer)() = NULL);
        ~Software_Handle();

        /// -- Methods -- //
        bool Is_Equal(Xila_Class::Software_Handle const &Software_Handle_To_Compare) const;

    protected:
        ///
        /// @brief Software string name.
        ///
        char Name[Default_Software_Name_Length]; //used to identify the software,

        ///
        /// @brief Software icon.
        ///
        uint8_t Icon;

        ///
        /// @brief Function pointer called by Xila to load software.
        /// @details Function allocate memory and return allocated software memory pointer and then send an "Open" instruction in the queue.
        ///
        Xila_Class::Software *(*Load_Function_Pointer)();

        ///
        /// @brief Function pointer that is called by Xila at startup.
        /// @details That is usefull when you whan to start a background task, or launch your application at the startup.
        ///
        void (*Startup_Function_Pointer)();

        // -- Friendship
        friend class Xila_Class;
        friend class Xila_Class::Software;
        friend class Shell_Class;
    };

    //==============================================================================//
    //                                  Modules                                     //
    //==============================================================================//

    ///
    /// @brief Account management class
    ///
    class Account_Class
    {
    public:
        // -- Constructor
        Account_Class();

        ///
        /// @brief Session state type
        ///
        typedef enum : uint8_t
        {
            Disconnected,
            Logged,
            Locked
        } Session_State;

        Xila_Class::Event Add(const char *Username, const char *Password);
        Xila_Class::Event Delete(const char *);
        Xila_Class::Event Change_Password(const char *, const char *);
        Xila_Class::Event Change_Username(const char *, const char *);
        Xila_Class::Event Set_Autologin(bool Enable);

        Xila_Class::Event Check_Credentials(const char *, const char *);
        Xila_Class::Event Login(const char *Username_To_Check = NULL, const char *Password_To_Check = NULL);
        Xila_Class::Event Logout();
        Xila_Class::Event Lock();

        // -- Getter
        const char *Get_Current_Username();
        uint8_t Get_State();

        friend class Xila_Class;
        friend class Shell_Class;

    protected:
        ///
        /// @brief Loaded username.
        ///
        char Current_Username[9];

        ///
        /// @brief Session state.
        ///
        Session_State State;

        // -- Setter
        void Set_Current_Username(const char *Username);
        void Set_State(Session_State State);

        Xila_Class::Event Load_Registry();

    } Account;

    //==============================================================================//
    ///
    /// @brief Clipboard module
    ///
    class Clipboard_Class
    {
    public:
        Xila_Class::Event Clear();

        Xila_Class::Event Copy(uint64_t const &Value_To_Copy);
        Xila_Class::Event Copy(const char *Char_Array_To_Copy, size_t Char_Array_Length = 0);
        Xila_Class::Event Copy(String const &String_To_Copy); // deprecated : only for compatibility purpose

        Xila_Class::Event Paste(uint64_t &Value_To_Paste);
        Xila_Class::Event Paste(char *Char_Array_To_Paste, size_t Char_Array_Length);
        Xila_Class::Event Paste(String &String_To_Paste);

        friend class Xila_Class;
        friend class Shell_Class;

    protected:
        ///
        /// @brief Clipboard file.
        ///
        File Clipboard_File;

        ///
        /// @brief Split number array.
        ///
        uint8_t Split_Number[8];
    } Clipboard;

    //==============================================================================//
    ///
    /// @brief Dialog class
    ///
    class Dialog_Class
    {
    public:
        Xila_Class::Event Login();
        Xila_Class::Event Event(const __FlashStringHelper *Message, uint8_t Type, const __FlashStringHelper *Button_Text_1 = NULL, const __FlashStringHelper *Button_Text_2 = NULL, const __FlashStringHelper *Button_Text_3 = NULL);
        Xila_Class::Event Event(const char *Message, uint8_t Type, const char *Button_Text_1, const char *Button_Text_2, const char *Button_Text_3);
        Xila_Class::Event Color_Picker(uint16_t &Color);
        Xila_Class::Event Open_File(File &File_To_Open);
        Xila_Class::Event Open_Folder(File &Folder_To_Open);
        Xila_Class::Event Save_File(File &File_To_Save);
        Xila_Class::Event Keyboard(char *String, size_t Size = 189, bool Masked_Input = false);
        Xila_Class::Event Keypad(float &Number);
        void Power();
        void Load(const __FlashStringHelper *Header, const __FlashStringHelper *Message, uint32_t Duration = 0);
        void Load(const char *Header, const char *Message, uint32_t Duration = 0);
        void Close_Load();

        Dialog_Class();

        friend class Xila_Class;
        friend class Shell_Class;

    protected:
        // -- Attributes

        ///
        /// @brief Dialogs state
        ///
        Xila_Class::Event Power_State;
        Xila_Class::Event Keyboard_State;
        Xila_Class::Event Keypad_State;
        Xila_Class::Event Color_Picker_State;
        Xila_Class::Event Event_State;
        Xila_Class::Event File_Manager_State;
        Xila_Class::Event Credentials_State;
        Xila_Class::Event Login_State;

    } Dialog;

    //==============================================================================//

    ///
    /// @brief Display class
    ///
    class Display_Class : public Nextion_Class
    {
    public:
        Display_Class();
        ~Display_Class();

        uint8_t Get_State();

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
        enum Xila_16 : uint8_t
        {
            State_Button = 127,
            Left_Arrow,
            Right_Arrow,
            Up_Arrow,
            Down_Arrow,
            Battery_Empty,
            Battery_Quarter,
            Battery_Half,
            Battery_Three_Quarters,
            Battery_Full,
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
            Shell_Images = 0,
            Calculator_Images = 20,
            Clock_Images,
            Internet_Browser_Images,
            Music_Player_Images,
            Oscilloscope_Images = 32,
            Paint_Images,
            Periodic_Images,
            Piano_Images = 36,
            Pong_Images = 40,
            Simon_Images,
            Text_Editor_Images,
            Tiny_Basic_Images
        };

        ///
        /// @brief Software pages offset enurmeration.
        ///
        enum Pages_Offset
        {
            Core_Pages = 0,
            Shell_Pages = 5,
            Calculator_Pages = 23,
            Clock_Pages,
            Text_Editor_Pages = 28,
            Paint_Pages,
            Internet_Browser_Pages,
            Music_Player_Pages,
            Oscilloscope_Pages,
            Periodic_Pages,
            Piano_Pages = 35,
            Pong_Pages,
            Simon_Pages,
            Tiny_Basic_Pages
        };

        ///
        /// @brief Font list
        ///
        enum Font
        {
            Regular_16 = 0, ///< Roboto Regular 16 px (+ special character), main font used almost everywhere.
            Mono_16,        ///< Robot Mono 16 px, used for terminals etc.
            Regular_24,     ///< Robot Regular 24 px.
            Regular_32,     ///< Roboto Regular 32 px .
            Regular_48      ///< Roboto Regular 48 px.
        };

        static void Incomming_String_Data_From_Display(const char *, uint8_t);
        static void Incomming_Numeric_Data_From_Display(uint32_t);
        static void Incomming_Event_From_Display(uint8_t);

        friend class Xila_Class;
        friend class Shell_Class;

    protected:
        void Set_State(uint8_t State);

        uint8_t State;

        uint8_t Brightness, Receive_Pin, Standby_Time, Transmit_Pin;

        Xila_Class::Address Current_Address;

        Xila_Class::Event Load_Registry();
        Xila_Class::Event Save_Registry();

    } Display;

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
            None,   ///< None (nothing connected).
            MMC,    ///< MMC type.
            SD_SC,  ///< SD type.
            SD_HC,  ///< SD HC type.
            Unknow  ///< Unknow type.
        } Sd_Card_Type;

        bool Begin(uint8_t Slave_Select_Pin = SS, SPIClass &spi = SPI, uint32_t Frequency = 4000000, const char *Mount_Point = "/sd", uint8_t Maximum_Files = 5);

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

        //Custom

        Xila_Class::Event Copy(File &Origin_File, File &Destination_File);
        Xila_Class::Event Get_Name(File const &File, char *File_Name_Buffer, size_t Size);
        uint16_t Count_Items(File &Folder);

        // -- Constructor
        Drive_Class();

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;

    protected:
        void End();

    } Drive;

    ///=============================================================================//
    ///
    /// @brief Flash class
    ///
    class Flash_Class
    {
    public:
        // -- Methods
        uint32_t Get_Size();
        uint32_t Get_Speed();
        FlashMode_t Get_Mode();

        Xila_Class::Event Read(uint32_t Offset, uint32_t *Data, size_t Size);

        Xila_Class::Event Partition_Read(const esp_partition_t *Partition, uint32_t Offset, uint32_t *Data, size_t Size);

        uint32_t Get_Sketch_Size();
        String Get_Sketch_MD5();
        uint32_t Get_Sketch_Free_Space();

    private:
        // -- Methods
        Xila_Class::Event Erase_Sector(uint32_t Sector);
        Xila_Class::Event Write(uint32_t Offset, uint32_t *Data, size_t Size);

        Xila_Class::Event Partition_Write(const esp_partition_t *Partition, uint32_t Offset_, uint32_t *Data, size_t Size);
        Xila_Class::Event Partition_Erase_Range(const esp_partition_t *Partition, uint32_t Offset, size_t Size);

        static uint32_t Sketch_Size(sketchSize_t Response);
        uint32_t Magic_Size(uint8_t Byte);
        uint32_t Magic_Speed(uint8_t Byte);
        FlashMode_t Magic_Mode(uint8_t Byte);
    };

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

        Xila_Class::Event Valid_Output_Pin(uint8_t Pin);

        // -- Digital
        void Digital_Write(uint8_t Pin, uint8_t State);
        int16_t Digital_Read(uint8_t Pin);

        Xila_Class::Event Valid_Digital_Pin(uint8_t Pin);

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
        void Detech_Interrupt(uint8_t Pin);

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
            Pull_Up = 0x04,           ///< Pull up resitor.
            Input_Pull_Up = 0x05,     ///< Input with a pull up resitor.
            Pull_Down = 0x08,         ///< Pull down resitor.
            Input_Pull_Down = 0x09,   ///< Input with a pull down reistor.
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

    protected:
        // -- Methods
        Xila_Class::Event Load_Registry();
        Xila_Class::Event Save_Registry();

        uint8_t Layout;

        uint8_t Data_Pin;
        uint8_t Clock_Pin;

        inline void Begin();

    } Keyboard;

    //==============================================================================//
    ///
    /// @brief Mathematics class
    ///

    class Mathematics_Class
    {
    public:
        ///
        /// @brief Archimedes constant.
        ///
        const double Pi = 3.1415926535897932384626433832795;

        ///
        /// @brief Euler constant.
        ///
        const double Euler = 2.718281828459045235360287471352;

        ///
        /// @brief Degrees to radian coefficient.
        ///
        const double Degrees_To_Radians = 0.017453292519943295769236907684886;

        ///
        /// @brief Radian to degrees coefficient.
        ///
        const double Radians_To_Degrees = 57.295779513082320876798154814105;

        // -- Methods -- //
        double String_To_Float(const char *String); // --
        char *Float_To_String(double Number, int8_t Width, uint8_t Precision, char *String);

        bool Is_NAN(double Number);
        bool Is_Infinite(double Number);

        double Copy_Sign(double Number_1, double Number_2);
        double Floor(double Number);
        double Modulo(double Number_1, double Number_2);
        double Greatest_Common_Divisor(double Number_1, double Number_2);
        double Least_Common_Multiple(double Number_1, double Number_2);

        double Radians(double Degrees);
        double Degrees(double Radians);

        double Factorial(double Number);
        double Absolute(double Number);
        double Inverse(double Number);

        double Combination(double n, double k);
        double Permutation(double n, double k);

        double Sine(double Number);
        double Cosine(double Number);
        double Tangent(double Number);
        double Secant(double Number);
        double Cosecant(double Number);
        double Cotangeant(double Number);

        double Arc_Sine(double Number);
        double Arc_Cosine(double Number);
        double Arc_Tangent(double Number);
        double Arc_Secant(double Number);
        double Arc_Cosecant(double Number);
        double Arc_Cotangent(double Number);

        double Hyperbolic_Sine(double Number);
        double Hyperbolic_Cosine(double Number);
        double Hyperbolic_Tangent(double Number);
        double Hyperbolic_Secant(double Number);
        double Hyperbolic_Cosecant(double Number);
        double Hyperbolic_Cotangent(double Number);

        double Arc_Hyperbolic_Sine(double Number);
        double Arc_Hyperbolic_Cosine(double Number);
        double Arc_Hyperbolic_Tangent(double Number);
        double Arc_Hyperbolic_Secant(double Number);
        double Arc_Hyperbolic_Cosecant(double Number);
        double Arc_Hyperbolic_Cotangent(double Number);

        double Power(double Base, double Exponent);
        double Square(double Number);
        double Cube(double Number);

        double Root(double Base, double Exponent);
        double Square_Root(double Number);
        double Cubic_Root(double Number);

        double Exponential(double Number);

        double Logarithm(double Base, double Number);
        double Binary_Logarithm(double Number);
        double Natural_Logarithm(double Number);
        double Decimal_Logarithm(double Number);

    } Mathematics;

    //==============================================================================//
    ///
    /// @brief Memory management class.
    ///
    class Memory_Class
    {
    public:
        // -- Methods

        uint32_t Get_Heap_Size();
        uint32_t Get_Free_Heap();
        uint32_t Get_Minimum_Free_Heap();
        uint32_t Get_Maximum_Allocated_Heap();

        uint32_t Get_PSRAM_Size();
        uint32_t Get_Free_PSRAM();
        uint32_t Get_Minimum_Free_PSRAM();
        uint32_t Get_Maximum_Allocated_PSRAM();
    } Memory;

    //==============================================================================//
    ///
    /// @brief Power management module.
    ///
    class Power_Class : public Battery_Class
    {

    public:
        // -- Constructors / Destructors
        Power_Class();

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;

        // -- Methods

        Xila_Class::Event Save_Registry();
        Xila_Class::Event Load_Registry();

    protected:
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

        // -- Methods
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

        Xila_Class::Event Open(Xila_Class::Software_Handle const &Software_Handle);
        void Minimize(Xila_Class::Software_Handle const &Software_Handle);
        Xila_Class::Event Maximize(Xila_Class::Software_Handle const &);
        void Close(Xila_Class::Software_Handle const &Software_Handle);

        void Feed_Watchdog(Xila_Class::Software_Handle const &Software_Handle);

        friend class Xila_Class;
        friend class Shell_Class;

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

        uint8_t ftware_Handle(Xila_Class::Software_Handle const &);
        void Add_Handle(Xila_Class::Software_Handle &);

        Xila_Class::Event Force_Close(Xila_Class::Software_Handle const &Software_Handle);

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

        void Set_Volume(uint8_t Volume); // volume between 0 and 255
        uint8_t Get_Volume();

        void Set_Balance(uint8_t);

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

        enum : uint8_t
        {
            Internal_DAC = 0,
            External_DAC
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

        friend class Xila_Class;
        friend class Shell_Class;

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
        Xila_Class::Event Save_Registry();
        Xila_Class::Event Load_Registry();

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

        uint32_t Random() const;
        uint32_t Random(uint32_t Upper_Bound) const;
        uint32_t Random(uint32_t Low_Bound, uint32_t Upper_Bound) const;

        void Refresh_Header();

        static void Task(void *);

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;

    protected:
        // System's task :
        Xila_Class::Task_Handle Task_Handle;

        ///
        /// @brief Device name used as Network hostname ...
        ///
        char Device_Name[24];

        // -- Methods

        Xila_Class::Event Load_Registry();
        Xila_Class::Event Save_Registry();

        Xila_Class::Event Save_Dump();
        Xila_Class::Event Load_Dump();

        Xila_Class::Event Load_Executable(File Executable_File);

        void Second_Sleep_Routine();

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
            Failed_To_Update_Display,
            Low_Memory,
            Memory_Corruption,
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
        // -- Task management -- //
        Xila_Class::Event Create(Xila_Class::Task_Function Task_Function, const char *Task_Name, size_t Stack_Size, void *pvParameters = NULL, Xila_Class::Task_Handle *Task_Handle = NULL) const;
        void Suspend(Xila_Class::Task_Handle Task_To_Suspend = NULL) const;
        void Resume(Xila_Class::Task_Handle Task_To_Resume) const;
        void Delete(Xila_Class::Task_Handle Task_To_Delete = NULL) const;

        void Delay(uint32_t Delay_In_Millisecond) const;

        friend Xila_Class;
        friend class Shell_Class;

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

        Xila_Class::Event Create(Xila_Class::Task_Function Task_Function, const char *Task_Name, size_t Stack_Size, void *pvParameters, uint16_t Priority, Xila_Class::Task_Handle *Task_Handle);

    } Task;

    //==============================================================================//

    ///
    /// @brief
    ///
    class Time_Class
    {

    public:
        // -- Methods
        tm Get_Time();
        void Synchronize();

        uint32_t Get_Cycle_Count();
        uint32_t Milliseconds() const;
        int64_t Microseconds() const;

        // -- Time constructor / destructor

        Time_Class();

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;

    protected:
        // -- Attributes
        int32_t GMT_Offset;
        int16_t Daylight_Offset;

        tm Current_Time;
        time_t Now;
        char NTP_Server[32];

        // -- Methods
        Xila_Class::Event Load_Registry();
        Xila_Class::Event Save_Registry();
    } Time;

    //==============================================================================//
    ///
    /// @brief WiFi class
    ///
    class WiFi_Class : public WiFiGenericClass, public WiFiSTAClass, public WiFiScanClass, public WiFiAPClass
    {

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

    protected:
        bool prov_enable;
        char Password[82];

    } WiFi;

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

#include "Core/Modules/Task.hpp"
#include "Core/Modules/Time.hpp"
#include "Core/Modules/System.hpp"
#include "Core/Modules/Mathematics.hpp"
#include "Core/Modules/Software_Management.hpp"

#include "Core/Abstraction/Display.hpp"
#include "Core/Abstraction/GPIO.hpp"
#include "Core/Abstraction/Memory.hpp"
#include "Core/Abstraction/Flash.hpp"

extern Xila_Class Xila;

#endif