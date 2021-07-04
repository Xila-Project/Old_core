///
/// @file Shell.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief Xila's user interface header file.
/// @version 0.1.0
/// @date 21-05-2020
/// @details Xila user interface software.
///
/// @section License
///
/// Copyright (c) 2020 Alix ANNERAUD
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
/// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
///
/// @copyright Copyright (c) 2021
///

#ifndef SHELL_HPP_INCLUDED
#define SHELL_HPP_INCLUDED

#include "Xila.hpp"


#define Default_Background -1

///
/// @brief Shell class
///
/// @details Main inter
///
class Shell_Class : public Software_Class
{
protected:
    // -- Attributes

    ///
    /// @brief Instance pointer, help to keep track of current instance.
    ///
    static Shell_Class *Instance_Pointer;

    ///
    /// @brief Desk class
    ///
    class Desk_Class
    {
    protected:
        
        // -- Attributes

        char Username[Maximum_Username_Lenght + 1];
        char Password[Maximum_Password_Lenght + 1];

        ///
        /// @brief Desk background
        ///
        /// @details Desk image when < 0 and Custom color when > 0 (color code itself).
        ///
        int32_t Background;

        uint8_t Offset;

        // -- Constructors / destructor

        Desk_Class();

        // -- Methods

        void Open(char);

        void Refresh_Desk();
        void Refresh_Drawer();

        void Execute_Desk_Instruction(Xila_Instruction);
        void Execute_Drawer_Instruction(Xila_Instruction);
        void Execute_Login_Instruction(Xila_Instruction);

        void Dock(uint8_t, uint8_t);

        void Open_From_Drawer(uint8_t);

        void Refresh_Login();
        void Logout();

        // -- friendship
        friend class Shell_Class;

    } Desk;

    ///
    /// @brief Dialog class
    ///
    class Dialog_Class
    {
    protected:
        // -- Attributes

        char Temporary_Float_String[25];

        // -- Constructors / Destructor

        Dialog_Class();
        ~Dialog_Class();

        // -- Methods

        static void Open(uint8_t Mode); // -- Open
        static bool State();
        static void Close(); // -- Close

        void Execute_Shutdown_Instruction(Xila_Instruction);
        void Execute_Color_Picker_Instruction(Xila_Instruction);
        void Execute_Event_Instruction(Xila_Instruction);
        void Execute_Keyboard_Instruction(Xila_Instruction);
        void Execute_Keypad_Instruction(Xila_Instruction);

        static void Load(const __FlashStringHelper *Header, const __FlashStringHelper *Message, uint16_t Duration = 0);
        static void Load(const char *Header, const char *Message, uint16_t Duration = 0);
        static Xila_Class::Event Keyboard(char *, size_t, bool = false);
        static Xila_Class::Event Keypad(float &Number_To_Get);
        static Xila_Class::Event Event(const __FlashStringHelper *, uint8_t, const __FlashStringHelper * = NULL, const __FlashStringHelper * = NULL, const __FlashStringHelper * = NULL);
        static Xila_Class::Event Event(const char *, uint8_t, const char * = NULL, const char * = NULL, const char * = NULL);
        static Xila_Class::Event Color_Picker(uint16_t &);
        static Xila_Class::Event Open_File(File &);
        static Xila_Class::Event Save_File(File &);
        static Xila_Class::Event Open_Folder(File &);

        // -- Friend
        friend class Shell_Class;

    } * Dialog_Pointer;

    ///
    /// @brief File manager class
    ///
    class File_Manager_Class
    {
    protected:
        // -- Attributes

        File Selected_Item;

        File Operation_Item;

        uint8_t Operation;

        enum File_Manager_Operation
        {
            Browse,
            New_File,
            New_Folder,
            Delete,
            Rename,
            Copy,
            Cut,
            Paste_Copy,
            Paste_Cut,
            Detail
        };

        uint8_t Mode;

        uint8_t Offset;

        // -- Methods

        File_Manager_Class();

        static void Open(uint8_t i);
        static bool State();
        static void Close();

        void Execute_Instruction(Xila_Instruction);

        static void Select_Item();

        void Refresh_Footerbar();
        void Refresh();
        void Make_File();
        void Go_Parent();

        void Refresh_Detail();
        void Open_Detail();

        // -- Attributes
        char Current_Item_Name[13];
        char Current_Path[192];

        friend class Shell_Class;

    } * File_Manager_Pointer;

    ///
    /// @brief Preferences class
    ///
    class Preferences_Class
    {
    public:
        // -- Constructor

        Preferences_Class();

    protected:
        // -- Attributes

        bool Autologin; // -- Accounts

        char Username[Maximum_Username_Lenght + 1];
        char Target_Username[Maximum_Username_Lenght + 1];
        char Password_1[Maximum_Password_Lenght + 1];
        char Password_2[Maximum_Password_Lenght + 1];

        int32_t GMT_Offset; // -- Time
        int16_t Daylight_Offset;
        char NTP_Server[sizeof(Xila.Time.NTP_Server)];

        char Name[25]; // -- System

        char WiFi_Name[33]; // -- Network
        char WiFi_Password[sizeof(Xila.WiFi.Password)];

        char Temporary_String[16];

        IPAddress Local_IP;
        IPAddress Gateway_IP;
        IPAddress Subnet_Mask;
        IPAddress DNS[2];

        uint16_t Write_Speed, Read_Speed; // -- Hardware

        // -- Methods
        static void Open(uint8_t Mode);
        static bool State();
        static void Close();

        void Refresh_Hardware();
        void Refresh_Personal();
        void Refresh_Network();
        void Refresh_System();
        void Refresh_Install();

        void Execute_Hardware_Instruction(Xila_Instruction);
        void Execute_Network_Instruction(Xila_Instruction);
        void Execute_Personal_Instruction(Xila_Instruction);
        void Execute_System_Instruction(Xila_Instruction);
        void Execute_Install_Instruction(Xila_Instruction);

        inline void System_Update();

        friend class Shell_Class;

    } * Preferences_Pointer;

    ///
    /// @brief Pages
    ///
    class Pages_Class
    {
    protected:
        enum
        {
            About = Xila.Display.Shell_Pages,
            Dialog_Color_Picker, // color picker
            Desk,
            Drawer,
            Dialog_Event,
            File_Manager_Main,
            File_Manager_Detail,
            Preferences_Hardware,
            Preferences_Install,
            Dialog_Keyboard,
            Dialog_Keypad,
            Login,
            Dialog_Load,
            Preferences_Network,
            Preferences_Personal,
            Shutdown,
            Preferences_System,
            Welcome,
        };

        friend class Shell_Class;
    } static Pages;

    // -- Attributes

    // -- Methods

    void Execute_Instruction(Xila_Instruction);

    Xila_Class::Event Save_Registry();
    Xila_Class::Event Load_Registry();

    void Set_Variable(const void *, uint8_t, uint8_t, uint8_t = 0);

    static void Main_Task(void *);

public:
    // -- Methods
    static Software_Class *Load_Shell();

    static void Startup();

    class Images_Class
    {
    public:
        enum
        {
            Empty_16 = Xila.Display.Shell_Images,
            File_16,
            Folder_16,
            Copy_24,
            Cut_24,
            Home_24,
            New_File_24,
            New_Folder_24,
            Refresh_24,
            Paste_24,
            Rename_24,
            Root_24,
            Trash_24,
            Empty_32,
            File_Manager_32,
            Preferences_32,
            Shutdown_32,
            Alix_Fait_Grr_Icon_64,
            Background_Picture_480,
        };
    } static Images;

    Shell_Class();
    ~Shell_Class();
};

// -- Shell handle -- //

extern Software_Handle_Class Shell_Handle;

// -- Shortcuts -- //
#define SHELL Shell_Class::Instance_Pointer
#define PREFERENCES SHELL->Preferences_Pointer
#define FILE_MANAGER SHELL->File_Manager_Pointer
#define DIALOG SHELL->Dialog_Pointer
#define DESK SHELL->Desk

#endif