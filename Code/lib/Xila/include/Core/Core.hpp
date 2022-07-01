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

#error Xila requires a C++ complier, pleasr change file extension to .cpp

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
#include "lvgl.h"
#include "Nextion_Library.hpp"

//----------------------------------------------------------------------------//
//                          Include all project file                          //
//----------------------------------------------------------------------------//

// -- Configuration file (at compile time)
#include "Configuration.hpp" // default values
#include "Modules/Log.hpp"
#include "Modules/Path.hpp" // Path list

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
#define Instruction(x, y) (x * 256 + y)

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

    class Date_Type {
    private:
        uint8_t Day;
        uint8_t Month;
        uint16_t Year;
    public:
        Date_Type();
        Date_Type(uint8_t Day, uint8_t Month, uint16_t Year);

        void Set(uint8_t Day, uint8_t Month, uint16_t Year);
        void Set_Day(uint8_t Day);
        void Set_Month(uint8_t Month);
        void Set_Year(uint16_t Year);
    
        uint8_t Get_Day();
        uint8_t Get_Month();
        uint16_t Get_Year();
    };

    /// @brief Xila Address type.
    typedef uint16_t Address;

    /// @brief Image type.
    typedef uint8_t Image;

    /// @brief Xila instruction type.
    typedef uint32_t Instruction;

    /// @brief Page type.
    typedef uint8_t Page;

    /// @brief Task type
    typedef void Task_Function;

    /// @brief Task handle type
    typedef void *Task_Handle;

    /// @brief Size Type;
    typedef size_t Size_Type;

    /// @brief Instructions used by the core (with the prefix "#").
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
        Dialog_Keypad = 'k',       // Open keypad dialog
        Dialog_Color_Picker = 'c', // Open color picker dialog
        Dialog_Power = 'P',        // Open power dialog
        Dialog_Event = 'E',        // Open event dialog
        Dialog_Login = 'L',        // Open login dialog
        Dialog_Load = 'l'          // Open load dialog
    };

    ///
    /// @brief Variable type enumeration
    ///
    enum Types : uint8_t
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
        char Name[Default_Software_Name_Length]; // used to identify the software,

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
        /// @details That is usefull to start a background task, or launch your application at the startup.
        ///
        void (*Startup_Function_Pointer)();

        // -- Friendship
        friend class Xila_Class;
        friend class Xila_Class::Software;
        friend class Shell_Class;
        friend class Unit_Test_Class;
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

        Xila_Class::Event Check_Credentials(const char *, const char *);

        // -- Getter
        const char *Get_Current_Username();
        uint8_t Get_State();

        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;

    protected:
        ///
        /// @brief Loaded username.
        ///
        char Current_Username[9];

        ///
        /// @brief Session state.
        ///
        Session_State State;

        // -- Methods

        Xila_Class::Event Add(const char *Username, const char *Password);
        Xila_Class::Event Delete(const char *);
        Xila_Class::Event Change_Password(const char *, const char *);
        Xila_Class::Event Change_Username(const char *, const char *);
        Xila_Class::Event Set_Autologin(bool Enable);
        Xila_Class::Event Login(const char *Username_To_Check = NULL, const char *Password_To_Check = NULL);
        Xila_Class::Event Logout();
        Xila_Class::Event Lock();

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
        friend class Unit_Test_Class;

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
        friend class Unit_Test_Class;

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

        // -- Enumerations

        ///
        /// @brief Prefix used to distinguish exchanged data between display, core and software
        ///
        enum Prefix
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
        /// @brief Xila_32 special characters list.
        ///
        enum Font_32
        {
            Exclamation_Mark = 127,
            Question_Mark,
            Cross
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

        static void Incoming_String_Data_From_Display(const char *, uint8_t);
        static void Incoming_Numeric_Data_From_Display(uint32_t);
        static void Incoming_Event_From_Display(uint8_t);

        uint8_t Get_State();

        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;

        enum
        {
            Keep = -32768,
        };

        enum Alignment
        {
            Left = LV_ALIGN_LEFT,
            Center = LV_ALIGN_CENTER,
            Right = LV_ALIGN_RIGHT,
            In_Between = LV_ALIGN_IN_BETWEEN,
            In_Between_Hor = LV_ALIGN_IN_BETWEEN_HOR,
            In_Between_Ver = LV_ALIGN_IN_BETWEEN_VER
        };

        /// @brief Animations enumeration
        enum Animation
        {
            Enable = LV_ANIM_ON,
            Disable = LV_ANIM_OFF
        };

        /// @brief Event class.
        class Event_Class
        {
        public:
            Event_Code_Type Get_Code();
            Object_Class Get_Current_Target();
            Object_Class Get_Target();
            void *Get_User_Data();

            typedef enum
            {
                All = LV_EVENT_ALL,
                // -- Interaction related events
                Pressed = LV_EVENT_PRESSED,
                Pressing = LV_EVENT_PRESSING,
                Press_Lost = LV_EVENT_PRESS_LOST,

                Short_Clicked = LV_EVENT_SHORT_CLICKED,
                Long_Pressed = LV_EVENT_LONG_PRESSED,
                Long_Pressed_Repeat = LV_EVENT_LONG_PRESSED_REPEAT,

                Clicked = LV_EVENT_CLICKED,
                Released = LV_EVENT_RELEASED,
                Scroll_Begin = LV_EVENT_SCROLL_BEGIN,
                Scroll_End = LV_EVENT_SCROLL_END,
                Scroll = LV_EVENT_SCROLL,
                Gesture = LV_EVENT_GESTURE,
                Key = LV_EVENT_KEY,
                Focused = LV_EVENT_FOCUSED,
                Defocused = LV_EVENT_DEFOCUSED,
                Leave = LV_EVENT_LEAVE,
                Hit_Test = LV_EVENT_HIT_TEST,
                // -- Drawing context
                Cover_Check = LV_EVENT_COVER_CHECK,

                Extra_Draw_Size = LV_EVENT_REFR_EXT_DRAW_SIZE,
                Draw_Main_Begin = LV_EVENT_DRAW_MAIN_BEGIN,
                Draw_Main = LV_EVENT_DRAW_MAIN,
                Draw_Main_End = LV_EVENT_DRAW_MAIN_END,

                Draw_Post_Begin = LV_EVENT_DRAW_POST_BEGIN,
                Draw_Post = LV_EVENT_DRAW_POST,
                Draw_Post_End = LV_EVENT_DRAW_POST_END,
                Draw_Part_Begin = LV_EVENT_DRAW_PART_BEGIN,
                Draw_Part_End = LV_EVENT_DRAW_PART_END,

                // -- Special events
                Value_Changed = LV_EVENT_VALUE_CHANGED,
                Insert = LV_EVENT_INSERT,
                Refresh = LV_EVENT_REFRESH,
                Ready = LV_EVENT_READY,
                Cancel = LV_EVENT_CANCEL,

                // -- State events
                Delete = LV_EVENT_DELETE,
                Child_Changed = LV_EVENT_CHILD_CHANGED,
                Child_Created = LV_EVENT_CHILD_CREATED,
                Child_Deleted = LV_EVENT_CHILD_DELETED,

                // -- Screen events
                Screen_Unload_Start = LV_EVENT_SCREEN_UNLOAD_START,
                Screen_Load_Start = LV_EVENT_SCREEN_LOAD_START,
                Screen_Loaded = LV_EVENT_SCREEN_LOADED,
                Screen_Unloaded = LV_EVENT_SCREEN_UNLOADED,

                // -- Appearance events
                Size_Changed = LV_EVENT_SIZE_CHANGED,
                Style_Changed = LV_EVENT_STYLE_CHANGED,
                Layout_Changed = LV_EVENT_LAYOUT_CHANGED,
                Get_Self_Size = LV_EVENT_GET_SELF_SIZE,

                Last_Event = _LV_EVENT_LAST
            } Event_Code_Type;

        private:
            lv_event_t LVGL_Event;
        };

        void Initialise();
        bool Initialisation_State();

        /// @brief Object class.
        class Object_Class
        {
        public:
            // -- Types
            typedef lv_coord_t Coordinate_Type;
            typedef lv_opa_t Opacity_Type;

            typedef lv_state_t State_Type;
            typedef lv_part_t Part_Type;
            typedef lv_obj_flag_t Flag_Type;

            typedef lv_event_t Event_Type;

            typedef lv_obj_t LVGL_Object_Class;

            typedef lv_obj_class_t Class_Type;
            typedef lv_style_selector_t Style_Selector_Type;

            typedef lv_dir_t Direction_Type;

            /// @brief Direction enumeration.
            enum
            {
                None = LV_DIR_NONE,
                Left = LV_DIR_LEFT,
                Right = LV_DIR_RIGHT,
                Top = LV_DIR_TOP,
                Bottom = LV_DIR_BOTTOM,
                Horizontal = LV_DIR_HOR,
                Vertical = LV_DIR_VER,
                All = LV_DIR_ALL,
            };

            /// @brief State enumeration.
            enum
            {
                Default = LV_STATE_DEFAULT,
                Checked = LV_STATE_CHECKED,
                Focused = LV_STATE_FOCUSED,
                Focus_Key = LV_STATE_FOCUS_KEY,
                Edited = LV_STATE_EDITED,
                Hovered = LV_STATE_HOVERED,
                Pressed = LV_STATE_PRESSED,
                Scrolled = LV_STATE_SCROLLED,
                Disabled = LV_STATE_DISABLED,
                Custom_1 = LV_STATE_USER_1,
                Custom_2 = LV_STATE_USER_2,
                Custom_3 = LV_STATE_USER_3,
                Custom_4 = LV_STATE_USER_4,
                Any = LV_STATE_ANY
            };

            /// @brief Part enumeration.
            enum
            {
                Main = LV_PART_MAIN,
                Scrollbar = LV_PART_SCROLLBAR,
                Indicator = LV_PART_INDICATOR,
                Knob = LV_PART_KNOB,
                Selected = LV_PART_SELECTED,
                Items = LV_PART_ITEMS,
                Ticks = LV_PART_TICKS,
                Cursor = LV_PART_CURSOR,
                Custom_First = LV_PART_CUSTOM_FIRST,
                Any = LV_PART_ANY
            };

            /// @brief Flag enumeration.
            enum
            {
                Hidden = LV_OBJ_FLAG_HIDDEN,
                Clickable = LV_OBJ_FLAG_CLICKABLE,
                Click_Focusable = LV_OBJ_FLAG_CLICK_FOCUSABLE,
                Checkable = LV_OBJ_FLAG_CHECKABLE,
                Scrollable = LV_OBJ_FLAG_SCROLLABLE,
                Scroll_Elastic = LV_OBJ_FLAG_SCROLL_ELASTIC,
                Scroll_Momentum = LV_OBJ_FLAG_SCROLL_MOMENTUM,
                Scroll_One = LV_OBJ_FLAG_SCROLL_ONE,
                Scroll_Chain_Horizontal = LV_OBJ_FLAG_SCROLL_CHAIN_HOR,
                Scroll_Chain_Vertical = LV_OBJ_FLAG_SCROLL_CHAIN_VER,
                Scroll_Chain = LV_OBJ_FLAG_SCROLL_CHAIN,
                Scroll_On_Focus = LV_OBJ_FLAG_SCROLL_ON_FOCUS,
                Scroll_With_Arrow = LV_OBJ_FLAG_SCROLL_WITH_ARROW,
                Snappable = LV_OBJ_FLAG_SNAPPABLE,
                Press_Lock = LV_OBJ_FLAG_PRESS_LOCK,
                Event_Bubble = LV_OBJ_FLAG_EVENT_BUBBLE,
                Gesture_Bubble = LV_OBJ_FLAG_GESTURE_BUBBLE,
                Adv_Hittest = LV_OBJ_FLAG_ADV_HITTEST,
                Ignore_Layout = LV_OBJ_FLAG_IGNORE_LAYOUT,
                Floating = LV_OBJ_FLAG_FLOATING,
                Overflow_Visible = LV_OBJ_FLAG_OVERFLOW_VISIBLE,
                Layout_1 = LV_OBJ_FLAG_LAYOUT_1,
                Layout_2 = LV_OBJ_FLAG_LAYOUT_2,
                Widget_1 = LV_OBJ_FLAG_WIDGET_1,
                Widget_2 = LV_OBJ_FLAG_WIDGET_2,
                Custom_1 = LV_OBJ_FLAG_USER_1,
                Custom_2 = LV_OBJ_FLAG_USER_2,
                Custom_3 = LV_OBJ_FLAG_USER_3,
                Custom_4 = LV_OBJ_FLAG_USER_4,
            };

            /// @brief Event enumeration.
            enum Draw_Part_Type
            {
                Rectangle = LV_OBJ_DRAW_PART_RECTANGLE,
                Border_Post = LV_OBJ_DRAW_PART_BORDER_POST,
                Scrollbar = LV_OBJ_DRAW_PART_SCROLLBAR
            };

            // -- Methods

            // -- Constructors

            Object_Class(Object_Class &Parent_Object);
            ~Object_Class();

            //  -- Management
            void Delete();
            void Clean();
            // -- -- Flags
            void Add_Flag(Flag_Type Flag);
            void Clear_Flag();
            bool Has_Flag(Flag_Type Flag);
            bool Has_Any_Flag(Flag_Type Flag);
            // -- -- States
            void Add_State(State_Type State);
            void Clear_State(State_Type State);
            bool Has_State(State_Type State);
            // -- -- Swap
            void Swap(Object_Class Object_To_Swap_With);
            // -- -- Events
            void Add_Event(Event_Type Event);
            void Remove_Event(Event_Type Event);
            void Send_Event(Event_Type Event);
            // -- -- Layer management
            void Move_Foreground();
            void Move_Background();

            void Allocate_Special_Data();

            bool Check_Type(const Class_Type *Class);
            bool Has_Class(const Class_Type *Class);
            const Class_Type *Get_Class();

            bool Is_Valid();
            bool Is_Focused();

            static Coordinate_Type DPX(Coordinate_Type Coordinate);

            // -- Set attributes values.
            void Set_Index(uint32_t Index);
            void Set_Parent(Object_Class Parent_Object);

            void Set_User_Data(void *User_Data);
            void Set_Position(Xila_Class::Object_Class, Coordinates X = Keep, Coordinates Y = Keep);
            void Set_Size(Xila_Class::Object_Class, Coordinates Width = Keep, Coordinates Height = Keep, char Fit = 'N');
            void Set_Alignment(Xila_Class::Object_Class, Xila_Class::Alignment, Xila_Class::Alignment = Xila_Class::Keep);

            void Add_Style(Style_Type Style, Style_Selector_Type *Style_Selector);

            // -- Get attributes values.
            State_Type Get_State();
            void *Get_Group();
            void *Get_User_Data();
            State Get_Object_Visibility(Xila_Class::Object_Class);
            void Get_Identifier(Object_Class Object);

            uint16_t Get_Child_Count(Object_Class Parent_Object);
            Object_Class Get_Child(Object_Class Object, uint16_t Index);

            // -- Operator
            LVGL_Object_Class &operator=(const Object_Class &Object_Class);

        protected:
            LVGL_Object_Class Get_Parent();

            void Set_Pointer(LVGL_Object_Class *Object);
            LVGL_Object_Class *Get_Pointer();

            static void Event_Handler(Event_Type Event);

        private:
            LVGL_Object_Class *LVGL_Object_Pointer;
        };

        /// @brief Screnn class.
        class Screen_Class : public Object_Class
        {
            // TODO : Implement screen API.
        };

        class Arc_Class : public Object_Class
        {
            typedef enum
            {
                Normal = LV_ARC_MODE_NORMAL,
                Symmetrical = LV_ARC_MODE_SYMMETRICAL,
                Reversed = LV_ARC_MODE_REVERSED
            } Mode_Type;

            typedef enum
            {
                Background = LV_ARC_DRAW_PART_BACKGROUND,
                Foreground = LV_ARC_DRAW_PART_FOREGROUND,
                Knob = LV_ARC_DRAW_PART_KNOB
            } Part_Type;

            // -- Set attributes values.
            void Set_Start_Angle(uint16_t Start_Angle);
            void Set_End_Angle(uint16_t End_Angle);
            void Set_Angles(uint16_t Start_Angle, uint16_t End_Angle);

            void Set_Background_Start_Angle(uint16_t Start_Angle);
            void Set_Background_End_Angle(uint16_t End_Angle);
            void Set_Background_Angles(uint16_t lv_arc_set_start_angle, unt16_t End_Angle);

            void Set_Range(int16_t Minimum, int16_t Maximum);
            void Set_Change_Rate(uint16_t Rate);

            void Set_Rotation(uint16_t Rotation);

            void Set_Mode(Mode_Type Mode);
            void Set_Value(int16_t Value);

            // -- Get attributes values.
            uint16_t Get_Angle_Start();
            uint16_t Get_Angle_End();

            uint16_t Get_Background_Angle_Start();
            uint16_t Get_Background_Angle_End();

            int16_t Get_Value();
            int16_t Get_Minimum_Value();
            int16_t Get_Maximum_Value();

            Mode_Type Get_Mode();
        };

        /// @brief Bar class.
        class Bar_Class : public Object_Class
        {
        public:
            // -- Types

            /// @brief Bar mode type.
            typedef lv_bar_mode_t Mode_Type;
            /// @brief Bar mode enumeration.

            typedef enum
            {
                Normal = LV_BAR_MODE_NORMAL,
                Symmetrical = LV_BAR_MODE_SYMMETRICAL,
                Range = LV_BAR_MODE_RANGE
            };

            typedef enum
            {
                Indicator = LV_BAR_DRAW_PART_INDICATOR
            } Part_Type;

            // -- Methods
            Bar_Class(Object_Class &Parent_Object);

            // -- Set attributes values.
            void Set_Value(int32_t Value, bool Enable_Animation = true);

            void Set_Start_Value(Object Bar, int32_t Value, bool Enable_Animation = true);

            void Set_Range(int32_t Minimum_Value, int32_t Maximum_Value);
            void Set_Mode(Object Bar, Mode_Type Mode);

            // -- Get attributes values.
            int32_t Get_Value();
            int32_t Get_Start_Value();
            int32_t Get_Minimum_Value();
            int32_t Get_Maximum_Value();
            Mode_Type Get_Mode();
        };

        /// @brief Button class.
        class Button_Class : public Object_Class
        {
        public:
            Create(Object_Class &Parent_Object);

            
            
        };

        /// @brief Button matrix class.
        class Button_Matrix_Class : public Object_Class
        {
        public:
            // -- Types

            typedef lv_btnmatrix_ctrl_t Control_Type;
            typedef lv_btnmatrix_btn_draw_cb_t Button_Draw_Callback_Type;

            // -- Enumerations

            enum
            {
                Button_Matrix_Width = _LV_BTNMATRIX_WIDTH,
                Hidden = LV_BTNMATRIX_CTRL_HIDDEN,
                No_Repeat = LV_BTNMATRIX_CTRL_NO_REPEAT,
                Disabled = LV_BTNMATRIX_CTRL_DISABLED,
                Checkable = LV_BTNMATRIX_CTRL_CHECKABLE,
                Checked = LV_BTNMATRIX_CTRL_CHECKED,
                Click_Trigger = LV_BTNMATRIX_CTRL_CLICK,
                Popover = LV_BTNMATRIX_CTRL_POPOVER,
                Custom_1 = LV_BTNMATRIX_CTRL_CUSTOM_1,
                Custom_2 = LV_BTNMATRIX_CTRL_CUSTOM_2
            };

            typedef enum
            {
                Button = LV_BTNMATRIX_DRAW_PART_BTN
            } Draw_Part_Type;

            // -- Methods

            // -- -- Constructor

            Button_Matrix_Class(Object_Class &Parent_Object);

            // -- -- Action methods
            void Clear_Button_Control(uint16_t Button_Identifier, Control_Type Control);
            void Clear_All_Buttons_Control(Control_Type Control);
            bool Has_Button_Control(uint16_t Button_Identifier, Control_Type Control);

            // -- -- Set attributes values.
            void Set_Width(uint16_t Button_Identifier, uint8_t Width);

            void Set_Map(const char *Map[]);
            void Set_Control_Map(Control_Type Map[]);

            void Set_Selected_Button(uint16_t Button_Identifier);
            void Set_Button_Control(uint16_t Button_Identifier, Control_Type Control);
            void Set_Button_Control_All(Control_Type Control);

            void Set_One_Checked(bool Enabled);

            // -- -- Get attributes values.
            const char **Get_Map();
            uint16_t Get_Selected_Button();
            const char *Get_Button_Text(uint16_t Button_Identifier);
            bool Get_One_Checked();
        };

        /// @brief Canvas class.
        class Canvas_Class : public Object_Class
        {
        public:
            // -- Methods

            Canvas_Class(Object_Class &Parent_Object);

            // -- --
            void Copy_Buffer(const void *Buffer_To_Copy, Coordinate_Type X, Coordinate_Type Y, uint16_t Width, uint16_t Height);

            void Transform(Image_Descriptor_Type *Image, int16_t Angle, uint16_t Zoom, Coordinate_Type Offset_X, Coordinate_Type Offset_Y, int32_t Pivot_X, int32_t Pivot_Y, bool Anti_Aliasing);
            void Horizontal_Blur(const Area_Type *Area, uint16_t Radius);
            void Vertical_Blur(const Area_Type *Area, uint16_t Radius);
            void Fill_Background(Color_Type Color, Opacity_Type Opacity);

            void Draw_Rectangle(Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Width, Coordinate_Type Height, Draw_Rectangle_Descriptor_Type *Draw_Rectangle_Descriptor);
            void Draw_Text(Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Maximum_Width, Draw_Label_Descriptor_Type *Draw_Label_Descriptor, const char *Text);
            void Draw_Image(Coordinate_Type X, Coordinate_Type Y, Draw_Image_Descriptor_Type *Draw_Image_Descriptor);
            void Draw_Line(const Point_Type Points[], uint32_t Number_Of_Point, const Draw_Line_Descriptor_Type *Draw_Line_Descriptor);
            void Draw_Polygon(const Point_Type Points[], uint32_t Number_Of_Point, const Draw_Rectangle_Descriptor_Type *Draw_Polygon_Descriptor);
            void Draw_Arc(Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Radius, int32_t Start_Angle, int32_t End_Angle, const Draw_Arc_Descriptor *Draw_Arc_Descriptor);

            // -- -- Set attributes values.

            void Set_Pixel_Color(Coordinate_Type X, Coordinate_Type Y, Color_Type Color);
            void Set_Pixel_Opacity(Coordinate_Type X, Coordinate_Type Y, Opacity_Type Opacity);
            void Set_Palette(uint8_t Identifier, Color_Type Color);

            void Set_Buffer(void *Buffer, Coordinate_Type Width, Coordinate_Type Height, Image_Color_Format_Type Color_Format);

            // -- -- Get attributes values.

            Color_Type Get_Pixel(Coordinate_Type X, Coordinate_Type Y);
            Image_Descriptor_Type Get_Image();
        };

        class Checkbox_Class : public Object_Class
        {
        public:
            enum Draw_Part_Type
            {
                Box = LV_CHECKBOX_DRAW_PART_BOX,
            };

            // -- Methods

            Checkbox_Class(Object_Class &Parent_Object);

            // -- -- Set attributes values.
            void Set_Text(const char *Text);
            void Set_Text_Static(const char *Text);

            // -- -- Get attributes values.
            const char *Get_Text();
        };

        class Drop_Down_List_Class : public Object_Class
        {
        public:
            // -- Methods

            Drop_Down_List_Class(Object_Class &Parent_Object);

            // Management

            void Add_Option(const char *Option, uint32_t Position);
            void Clear_Options();

            void Open();
            void Close();

            //  Setters
            void Set_Text(const char *Text);
            void Set_Options(const char *Options);
            void Set_Options_Static(const char *Options);
            void Set_Selected(uint16_t Selected_Option);
            void Set_Direction(Direction_Type Direction);
            void Set_Symbol(const void *Symbol);
            void Set_Selected_Highlight(bool Enabled);

            //  Getters
            Object_Class *Get_List();
            const char *Get_Text();
            const char *Get_Options();
            uint16_t Get_Selected();
            uint16_t Get_Option_Count();
            void Get_Selected_String(char *Buffer, Size_Type Buffer_Size);
            int32_t Get_Option_Index(const char *Option);
            const char *Get_Symbol();
            bool Get_Selected_Highlight();
            Direction_Type Get_Direction();
            bool Is_Open();
        };

        /// @brief image class
        class Image_Class : public Object_Class
        {
        public:
            typedef lv_img_size_mode_t Image_Size_Mode_Type;

            enum {
                Virtual = LV_IMG_SIZE_MODE_VIRTUAL,
                Real = LV_IMG_SIZE_MODE_REAL
            };

            // -- Methods
            Image_Class(Object_Class &Parent_Object);

            // -- Setters
            void Set_Source(const void* Source);
            void Set_Offset_X(Coordinate_Type X);
            void Set_Offset_Y(Coordinate_Type Y);
            void Set_Angle(int16_t Angle);
            void Set_Pivot(Coordinate_Type X, Coordinate_Type Y);
            void Set_Zoom(uint16_t Zoom);
            void Set_Antialias(bool Enabled);
            void Set_Size_Mode(Image_Size_Mode_Type Size_Mode);
            
            // -- Getters
            const void* Get_Size_Mode();
            Coordinate_Type Get_Offset_X();
            Coordinate_Type Get_Offset_Y();
            uint16_t Get_Angle();
            void Get_Pivot(Coordinate_Type *X, Coordinate_Type *Y);
            uint16_t Get_Zoom();
            bool Get_Antialias();
            Image_Size_Mode_Type Get_Size_Mode();
        };

        /// @brief Label class.
        class Label_Class : public Label_Class
        {
        public:
            // -- Types
            typedef lv_label_long_mode_t Long_Mode_Type;

            enum
            {
                Long_Wrap = LV_LABEL_LONG_WRAP,
                Long_Dot = LV_LABEL_LONG_DOT,
                Long_Scroll = LV_LABEL_LONG_SCROLL,
                Long_Scroll_Circular = LV_LABEL_LONG_SCROLL_CIRCULAR,
                Long_Clip = LV_LABEL_LONG_CLIP
            };

            // -- Methods
            Label_Class(const Object_Class &Parent_Object);
            void Insert_Text(uint32_t Position, const char *Text);
            void Cut_Text(uint32_t Position, uint32_t Length);
            bool Is_Char_Under_Position(Point_Type *Position);

            // -- Setters
            void Set_Text(const char *Text);
            void Set_Text_Format(const char *Format, ...);
            void Set_Text_Static(const char *Text);
            void Set_Long_Mode(Long_Mode_Type Long_Mode);
            void Set_Recolor(bool Recolor);
            void Set_Selection_Start(uint32_t Index);
            void Set_Selection_End(uint32_t Index);

            // -- Getters
            char *Get_Text();
            Long_Mode_Type Get_Long_Mode();
            bool Get_Recolor();
            void Get_Letter_Position(uint32_t Index, Point_Type *Position);
            uint32_t Get_Letter_On(Point_Type *Position_In);
            uint32_t Get_Selection_Start();
            uint32_t Get_Selection_End();
        };

        /// @brief Line class.
        class Line_Class : public Object_Class
        {
        public:
            // -- Methods
            Line_Class(const Object_Class &Parent_Object);

            void Set_Points(const Point_Type Points[], uint16_t Point_Number);
            void Set_Y_Inversion(bool Inversion);

            bool Get_Y_Inversion();
        }

        /// @brief Roller class.
        class Roller_Class : public Object_Class
        {
        public:
            // -- Types
            typedef lv_roller_mode_t Mode_Type;
            enum
            {
                Normal = LV_ROLLER_MODE_NORMAL,
                Infinite = LV_ROLLER_MODE_INFINITE
            };

            // -- Methods
            Roller_Class(Parent_Object &Parent_Object);

            // -- Setters
            void Set_Options(const char *Options, Mode_Type Mode);
            void Set_Selected(uint16_t Index, Animation_Enable_Type Animation);
            void Set_Visible_Row_Count(uint8_t Row_Count);

            // -- Getters
            uint16_t Get_Selected();
            void Get_Selected_String(char *Buffer, uint32_t Buffer_Size);
            const char *Get_Options();
            uint16_t Get_Option_Count();
        };

        class Slider_Class : public Object_Class
        {
        public:
            // -- Types
            typedef lv_slider_mode_t Slider_Mode;

            // -- Enumerations
            enum
            {
                Normal = LV_SLIDER_MODE_NORMAL,
                Symmetrical = LV_SLIDER_MODE_SYMMETRICAL,
                Range = LV_SLIDER_MODE_RANGE,
            };

            typedef enum
            {
                Knob = LV_SLIDER_TYPE_KNOB,
                Knob_Left = LV_SLIDER_TYPE_KNOB_LEFT,
            } Part_Type;

            // -- Methods
            Slider_Class(Object_Class &Parent_Object);

            bool Is_Dragged();

            // -- -- Setters.
            void Set_Value(int32_t Value, bool Animation);
            void Set_Left_Value(int32_t Value, bool Animation);
            void Set_Range(int32_t Minimum_Value, int32_t Maximum_Value);
            void Set_Mode(Mode_Type Mode);

            // -- -- Getters.
            int32_t Get_Value();
            int32_t Get_Left_Value();
            int32_t Get_Minimum_Value();
            int32_t Get_Maximum_Value();
            Mode_Type Get_Mode();
        };

        class Switch_Class : public Object_Class
        {
        public:
            // -- Methods
            Switch_Class(Object_Class &Parent_Object);
        };

        class Table_Class : public Object_Class
        {
        public:
            // -- Typedef

            typedef lv_table_cell_format_t Cell_Format;

            enum
            {
                Background,
                Cell_1,
                Cell_2,
                Cell_3,
                Cell_4
            };

            // -- Methods

            Table_Class(Object_Class &Parent_Object);

            // -- -- Setters.

            void Set_Cell_Value(uint16_t Row, uint16_t Column, const char *Value);
            void Set_Cell_Value_Format(uint16_t Row, uint16_t Column, const char *Formated_Value, ...);
            void Set_Row_Count(uint16_t Row_Count);
            void Set_Column_Count(uint16_t Column_Count);
            void Set_Column_Width(uint16_t Column, Coordinates_Type Width);
            void Set_Cell_Alignment(uint16_t Row, uint16_t Column, Label_Align_Type Align);
            void Set_Cell_Type(uint16_t Row, uint16_t Column, uint8_t Type);
            void Set_Cell_Crop(uint16_t Row, uint16_t Column, bool Crop);
            void Set_Cell_Merge_Right(uint16_t Row, uint16_t Column, bool Merge);

            // -- -- Getters.
            const char *Get_Cell_Value(uint16_t Row, uint16_t Column);
            uint16_t Get_Row_Count();
            uint16_t Get_Column_Count();
            Coordinates_Type Get_Column_Width(uint16_t Column);
            Label_Align_Type Get_Cell_Alignment(uint16_t Row, uint16_t Column);
            Label_Align_Type Get_Cell_Type(uint16_t Row, uint16_t Column);
            Label_Align_Type Get_Cell_Crop(uint16_t Row, uint16_t Column);
            bool Get_Cell_Merge_Right(uint16_t Row, uint16_t Column);
            Ressource_Type Get_Pressed_Cell(uint16_t *Row, uint16_t *Column);
        };

        class Text_Area_Class : public Object_Class
        {
            /// @brief Text area custom part enumeration.
            enum
            {
                Placeholder = LV_TEXTAREA_PLACEHOLDER
            };

            // -- Methods

            Text_Area_Class(Object_Class &Parent_Object);

            void Add_Char(uint32_t Character);
            void Add_Text(const char* Text);
            void Delete_Character();
            void Delete_Character_Forward();
            
            // -- Setters
            void Set_Text(const char* Text);
            void Set_Placeholder_Text(const char* Text);
            void Set_Cursor_Click_Position(bool Enabled);
            void Set_Password_Bullet(const char* Bullet);
            void Set_One_Line(bool Enabled);
            void Set_Accepted_Characters(const char* List);
            void Set_Maximum_Length(uint32_t Length);
            void Set_Insert_Replace(const char* Text);
            void Set_Text_Selection(bool Enabled);
            void Set_Password_Show_Time(uint16_t Time);
            void Set_Text_Alignment(Text_Align_Type Alignment);
            
            // -- Getters
            const char* Get_Text();
            const char* Get_Placeholder_Text();
            Label_Class* Get_Label();
            uint32_t Get_Cursor_Position();
            bool Get_Cursor_Click_Position();
            bool Get_Password_Mode();
            const char* Get_Password_Bullet();
            bool Get_One_Line();
            const char* Get_Accepted_Characters();
            uint32_t Get_Maximum_Length();
            bool Get_Text_Selection();
            uint16_t Get_Password_Show_Time();
            
            void Clear_Selection();
            void Cursor_Right();
            void Cursor_Left();
            void Cursor_Up();
            void Cursor_Down();

            bool Is_Selected();


        };

        // -- Widgets

        class Calendar_Class : public Object_Class
        {
        public:
            // -- Methods
            
            Calendar_Class(Object_Class &Parent_Object);

            // -- -- Setters.

            void Set_Today_Date(uint32_t Year, uint32_t Month, uint32_t Day);
            void Set_Showed_Date(uint32_t Year, uint32_t Month);
            void Set_Highlighted_Dates(Date_Type Date[], uint16_t Number);
            void Set_Days_Names(const char** Day_Names);
            Button_Matrix* Get_Button_Matrix();

            // -- -- Getters.
            const Date_Type* Get_Today_Date();
            const Date_Type* Get_Showed_Dates();
            Date_Type* Get_Highlighted_Dates();
            uint16_t Get_Highlighted_Dates_Number();
            Event_Type Get_Pressed_Date(Date_Type* Date);
        };

        class Chart_Class : public Object_Class
        {
        public:
            
            typedef lv_chart_series_t Series_Type;
            typedef lv_chart_cursor_t Cursor_Type;
            typedef lv_chart_tick_dsc_t Tick_Descriptor_Type;

            typedef uint8_t Type_Type;
            
            enum {
                None = LV_CHART_TYPE_NONE,
                Line = LV_CHART_TYPE_LINE,
                Bar = LV_CHART_TYPE_BAR,
                Scatter = LV_CHART_TYPE_SCATTER
            };
            
            typedef uint8_t Update_Mode_Type;
            
            enum {
                Shift = LV_CHART_UPDATE_MODE_SHIFT,
                Circular = LV_CHART_UPDATE_MODE_CIRCULAR
            };

            typedef uint8_t Axis_Type;

            enum {
                Primary_Y = LV_CHART_AXIS_PRIMARY_Y,
                Secondary_Y = LV_CHART_AXIS_SECONDARY_Y,
                Primary_X = LV_CHART_AXIS_PRIMARY_X,
                Secondary_X = LV_CHART_AXIS_SECONDARY_X,
                Last = LV_CHART_AXIS_LAST
            };

            enum Draw_Part_Type
            {
                Div_Line_Init = LV_CHART_DRAW_PART_DIV_LINE_INIT,
                Div_Line_Horizontal = LV_CHART_DRAW_PART_DIV_LINE_HORIZONTAL,
                Div_Line_Vertical = LV_CHART_DRAW_PART_DIV_LINE_VERTICAL,
                Line_And_Point = LV_CHART_DRAW_PART_LINE_AND_POINT,
                Bar = LV_CHART_DRAW_PART_BAR,
                Cursor = LV_CHART_DRAW_PART_CURSOR,
                Tick_Label = LV_CHART_DRAW_PART_TICK_LABEL
            };


            // -- Methods

            Chart_Class(Object_Class &Parent_Object);

            void Chart_Refresh();
            Series_Type* Add_Series(Color_Type Color, Axis_Type Axis);
            void Remove_Series(Series_Type* Series);
            void Hide_Series(Series_Type* Series, bool Hide);
            Cursor_Type* Add_Cursor(Color_Type Color, Direction_Type Direction);

            // -- -- Setters.

            void Set_Type(Type_Type Type);
            void Set_Point_Count(uint16_t Count);
            void Set_Range(Axis_Type Axis, Coordinates_Type Minimum, Coordinates_Type Maximum);
            void Set_Update_Mode(Update_Mode_Type Update_Mode);
            void Set_Div_Line_Count(uint8_t Horizontal_Div, uint8_t Vertical_Div);
            void Set_Zoom_X(uint16_t Zoom_X);
            void Set_Zoom_Y(uint16_t Zoom_Y);
            void Set_Axis_Tick(Axis_Type Axis, Coordinate_Type Major_Length, Coordinate_Type Minor_Length, Coordinate_Type Major_Count, Coordinate_Type Minor_Count, bool Label_Enabled, Coordinate_Type Draw_Size);
            void Set_Series_Color(Series_Type* Series, Color_Type Color);
            void Set_X_Start_Point(Series_Type* Series, uint16_t Identifier);
            void Set_Cursor_Position(Cursor_Type* Cursor, Point_Type* Position);
            void Set_Cursor_Point(Cursor_Type* Cursor, Series_Type* Series, uint16_t Identifier);
            void Set_All_Value(Series_Type* Series, Coordinate_Type Value);
            void Set_Next_Value(Series_Type* Series, Coordinate_Type Value);
            void Set_Next_Value(Series_Type* Series, Coordinate_Type X_Value, Coordinate_Type Y_Value);
            void Set_Value_By_Identifier(Series_Type* Series, uint16_t Identifier, Coordinate_Type Value);
            void Set_Value_By_Identifier(Series_Type* Series, uint16_t Identifier, Coordinate_Type X_Value, Coordinate_Type Y_Value);
            void Set_External_Y_Array(Series_Type* Series, Coordinate_Type Array[]);
            void Set_External_X_Array(Series_Type* Series, Coordinate_Type Array[]);

            // -- -- Getters.
            uint16_t Get_Zoom_X();
            uint16_t Get_Zoom_Y();
            Type_Type Get_Type();
            uint16_t Get_Point_Count();
            uint16_t Get_X_Start_Point(Series_Type* Series);
            void Get_Point_Position_By_Identifier(Series_Type* Series, uint16_t Identifier, Point_Type* Point_Out);
            Series_Type* Get_Series_Next(const Series_Type* Series);
            Point_Type Get_Cursor_Point(Cursor_Type* Cursor);
            Coordinate_Type* Get_Y_Array(Series_Type* Series);
            Coordinate_Type* Get_X_Array(Series_Type* Series);
            uint32_t Get_Pressed_Point();         
        };

        // @brief Color wheel class.
        class Color_Wheel_Class : public Object_Class
        {
        public:
            // -- Types
            typedef lv_colorwheel_mode_t Mode_Type;

            enum
            {
                Hue = LV_COLORWHEEL_MODE_HUE,
                Saturation = LV_COLORWHEEL_MODE_SATURATION,
                Value = LV_COLORWHEEL_MODE_VALUE
            };

            // -- Methods
            Color_Wheel_Class(const Object_Class &Parent_Object);

            // -- -- Setters
            bool Set_HSV(Color_HSV_Type HSV_Color);
            bool Set_RGB(Color_Type Color);
            void Set_Mode(Mode_Type Mode);
            void Set_Mode_Fixed(bool Fixed);

            // -- Getters
            Color_HSV_Type Get_HSV();
            Color_Type Get_RGB();
            Mode_Type Get_Mode();
            bool Get_Mode_Fixed();
        };

        /// @brief Keyboard object class.
        class Keyboard_Class : public Object_Class
        {
            typedef lv_keyboard_mode_t Mode_Type;

            enum {
                Text_Lower = LV_KEYBOARD_MODE_TEXT_LOWER,
                Text_Upper = LV_KEYBOARD_MODE_TEXT_UPPER,
                Special = LV_KEYBOARD_MODE_SPECIAL,
                Number = LV_KEYBOARD_MODE_NUMBER,
                User_1 = LV_KEYBOARD_MODE_USER_1,
                User_2 = LV_KEYBOARD_MODE_USER_2,
                User_3 = LV_KEYBOARD_MODE_USER_3,
                User_4 = LV_KEYBOARD_MODE_USER_4
            };

            // -- Methods
            Keyboard_Class(const Object_Class &Parent_Object);

            void Define_Event_Callback(Event_Type* Event);

            // -- -- Setters
            void Set_Text_Area(Text_Area_Class& Text_Area);
            void Set_Mode(Mode_Type Mode);
            void Set_Pop_Overs(bool Enabled);
            void Set_Map(Mode_Type Mode, const char* Map[], const Xila_Class::Display_Class::Button_Matrix_Class::Control_Type Control_Map[]);

            // -- Getters
            Text_Area_Class& Get_Text_Area();
            Mode_Type Get_Mode();
            bool Get_Pop_Overs();
            static const char** Get_Map_Array();
            static const uint16_t Get_Selected_Button();
            static const char* Get_Button_Text();
        };

        /// @brief List class.
        class List_Class : public Object_Class
        {
        public:
            // -- Methods
            List_Class(const Object_Class &Parent_Object);
            
            const Text_Area_Class& Add_Text(const char* Text);
            const Button_Class& Add_Button(const void* Icon, const char* Text);
            
            // -- Getters
            const char* Get_Button_Text(Button_Class& Button);
        };


        /// @brief Menu class
        class Menu_Class : public Object_Class
        {
        public:
            // -- Methods
            typedef lv_menu_mode_header_t Mode_Header_Type;

            enum {
                Top_Fixed = LV_MENU_HEADER_TOP_FIXED,
                Top_Unfixed = LV_MENU_HEADER_TOP_UNFIXED,
                Bottom_Fixed = LV_MENU_HEADER_BOTTOM_FIXED,
            };
            
            typedef lv_menu_mode_root_back_btn_t Mode_Root_Back_Button_Type;

            enum {
                Back_Button_Disabled = LV_MENU_ROOT_BACK_BTN_DISABLED,
                Back_Button_Enabled = LV_MENU_ROOT_BACK_BTN_ENABLED,
            };

            Object_Class* Create_Content(Object_Class Parent_Object);
            Object_Class* Create_Section(Object_Class Parent_Object);
            Object_Class* Create_Separator(Object_Class Parent_Object);
            
            void Set_Page(Object_Class Page);
            void Set_Sidebar_Page(Object_Class Page);

        };


        //


        class Tabs_Class : public Object_Class
        {
        public:
            // -- Types
            typedef lv_tabview_btns_pos_t Buttons_Position_Type;
            typedef lv_tabview_part_t Part_Type;
            enum
            {
                None = LV_TABVIEW_TAB_POS_NONE,
                Top = LV_ALIGN_TAB_POS_TOP,
                Bottom = LV_ALIGN_TAB_POS_BOTTOM,
                Left = LV_ALIGN_TAB_POS_LEFT,
                Right = LV_ALIGN_TAB_POS_RIGHT,
            };

            enum
            {
                Background = LV_TABVIEW_PART_BG,
                Virtual_Last = LV_TABVIEW_PART_VIRTUAL_LAST,
                Background_Scrollable = LV_TABVIEW_PART_BG_SCROLLABLE,
                Tab_Background = LV_TABVIEW_PART_TAB_BG,
                Tab_Button = LV_TABVIEW_PART_TAB_BTN,
                Part_Indicator = LV_TABVIEW_PART_INDICATOR,
                Real_Last = LV_TABVIEW_PART_REAL_LAST
            };

            // -- Methods
            Tabs_Class(Object_Class &Parent_Object);

            void Clean_Tab();

            // -- -- Setters.
            void Set_Active_Tab(uint16_t Identifier, Animation_Type Animation);
            void Set_Tab_Name(uint16_t Identifier, char *Name);
            void Set_Animation_Time(uint16_t Animation_Time);
            void Set_Buttons_Position(Buttons_Position_Type Buttons_Position);

            // -- -- Getters.
            uint16_t Get_Active_Tab();
            uint16_t Get_Tab_Count();
            Object_Class Get_Tab(uint16_t Identifier);
            uint16_t Get_Animation_Time();
            Buttons_Position_Type Get_Buttons_Position();
        };

        class Windows_Class : public Object_Class
        {
        public:
            typedef Xila_Class::Object_Class Object_Class;

            Object_Class Load(File);

            Object_Class Create();

            void Set_Title(Object_Class Window, const char *Title);

        protected:
            Object_Class Add_Button(Object_Class Parent_Window);

        private:
            Object_Class Title_Label;
            Object_Class Clock_Label;

            Object_Class Network_Button;
            Object_Class Battery_Button;
            Object_Class Sound_Button;

            Object_Class Close_Button;
            Object_Class Minimize_Button;
        };

        static void
        Task(void *);

        Xila_Class::Task_Handle Task_Handle;

        Xila_Class::Semaphore_Handle_Type Mutex_Semaphore_Handle;

        // -- Display state
        uint16_t Get_Horizontal_Definition();
        uint16_t Get_Vertical_Definition();

        Xila_Class::Event Compile_Page(File);
        Xila_Class::Event Load_Page(File, Object *, uint16_t);

    protected:
        static lv_fs_drv_t File_System_Driver;

        static void *File_System_Open(lv_fs_drv_t *, const char *, lv_fs_mode_t);
        static lv_fs_res_t File_System_Close(lv_fs_drv_t *, void *);
        static lv_fs_res_t File_System_Read(lv_fs_drv_t *, void *, void *, uint32_t, uint32_t *);
        static lv_fs_res_t File_System_Write(lv_fs_drv_t *, void *, const void *, uint32_t, uint32_t *);
        static lv_fs_res_t File_System_Set_Position(lv_fs_drv_t *, void *, uint32_t, lv_fs_whence_t);
        static lv_fs_res_t File_System_Get_Position(lv_fs_drv_t *, void *, uint32_t *);
        static void *File_System_Open_Directory(lv_fs_drv_t *, const char *);
        static lv_fs_res_t File_System_Directory_Read(lv_fs_drv_t *, void *, char *);
        static lv_fs_res_t File_System_Close_Directory(lv_fs_drv_t *, void *);

        void Initialize_File_System();

        void Set_State(uint8_t State);

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

        Xila_Class::Event Copy(File &Origin_File, File &Destination_File);
        Xila_Class::Event Get_Name(File const &File, char *File_Name_Buffer, size_t Size);
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
        Xila_Class::Event Set_Boot_Partition(const uint8_t Partition_Number);

        Xila_Class::Event Erase_Sector(uint32_t Sector);
        Xila_Class::Event Write(uint32_t Offset, uint32_t *Data, size_t Size);

        Xila_Class::Event Partition_Write(const esp_partition_t *Partition, uint32_t Offset_, uint32_t *Data, size_t Size);
        Xila_Class::Event Partition_Erase_Range(const esp_partition_t *Partition, uint32_t Offset, size_t Size);

        static uint32_t Sketch_Size(sketchSize_t Response);
        uint32_t Magic_Size(uint8_t Byte);
        uint32_t Magic_Speed(uint8_t Byte);
        FlashMode_t Magic_Mode(uint8_t Byte);

        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;
    } Flash;

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
        Xila_Class::Event Load_Registry();
        Xila_Class::Event Save_Registry();

        uint8_t Layout;

        uint8_t Data_Pin;
        uint8_t Clock_Pin;

        void Begin();

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
        double Cotangent(double Number);

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

        uint32_t Random() const;
        uint32_t Random(uint32_t Upper_Bound) const;
        uint32_t Random(uint32_t Low_Bound, uint32_t Upper_Bound) const;

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

    protected:
        // -- Constructors / Destructors
        Power_Class();

        // -- Friendship
        friend class Xila_Class;
        friend class Shell_Class;
        friend class Unit_Test_Class;

        // -- Methods

        Xila_Class::Event Save_Registry();
        Xila_Class::Event Load_Registry();

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

        Xila_Class::Event Open(Xila_Class::Software_Handle const &Software_Handle);
        void Minimize(Xila_Class::Software_Handle const &Software_Handle);
        Xila_Class::Event Maximize(Xila_Class::Software_Handle const &);
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

        Xila_Class::Event Load_Registry();
        Xila_Class::Event Save_Registry();

        Xila_Class::Event Save_Dump();
        Xila_Class::Event Load_Dump();

        Xila_Class::Event Load_Executable(File Executable_File);

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

        // -- Task management -- //
        static Xila_Class::Event Create(Xila_Class::Task_Function (*Task_Function)(void *), const char *Task_Name, size_t Stack_Size, void *pvParameters = NULL, Xila_Class::Task_Handle *Task_Handle = NULL) const;
        static void Suspend(Xila_Class::Task_Handle Task_To_Suspend = NULL) const;
        static void Resume(Xila_Class::Task_Handle Task_To_Resume) const;
        static void Delete(Xila_Class::Task_Handle Task_To_Delete = NULL) const;

        static void Delay(uint32_t Delay_In_Millisecond) const;

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

        Xila_Class::Event Create(Xila_Class::Task_Function (*Task_Function)(void *), const char *Task_Name, size_t Stack_Size, void *pvParameters, uint16_t Priority, Xila_Class::Task_Handle *Task_Handle);

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
        friend class Unit_Test_Class;

    protected:
        // -- Attributes

        ///
        /// @brief GMT offset in seconds.
        ///
        int32_t GMT_Offset;

        ///
        /// @brief Daylight offset in seconds.
        ///
        int16_t Daylight_Offset;

        ///
        /// @brief Current time structure.
        ///
        tm Current_Time;

        ///
        /// @brief Current unix time in seconds.
        ///
        time_t Now;

        ///
        /// @brief NTP server name.
        ///
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
        friend class Unit_Test_Class;

    protected:
        bool prov_enable;

        ///
        /// @brief Access point password.
        ///
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

#include "Core/Abstraction/Display.hpp"

extern Xila_Class Xila;

#endif