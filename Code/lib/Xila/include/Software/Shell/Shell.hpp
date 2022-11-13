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

#ifndef Shell_Hpp_Included
#define Shell_Hpp_Included

#include "Xila.hpp"

using namespace Xila;

#define Default_Background -1

///
/// @brief Shell class
///
/// @details Main inter
///

using namespace Xila;

class Shell_Class : public Software_Type
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

        ///
        /// @brief Desk background
        ///
        /// @details Desk image when < 0 and Custom color when > 0 (color code itself).
        ///
        Object_Type::Color_Type Background_Color;

        Window_Type Window;
        Object_Type Grid;
        Object_Type Dock;
        Object_Type Menu_Button;

        // -- Constructors / destructor
        Desk_Class();
        ~Desk_Class();

        // -- Methods
        void Open(uint8_t);
        void Refresh_Desk();
        void Execute_Desk_Instruction(Instruction_Type);
        void Execute_Drawer_Instruction(Instruction_Type);

        void Maximize_Dock_Software(uint8_t);
        void Close_Dock_Software(uint8_t);

        void Open_From_Drawer(uint8_t);

        void Logout();

        // -- friendship
        friend class Shell_Class;

    } * Desk_Pointer;

    class Drawer_Class
    {
    protected:

        // - Constructor / destructor
        Drawer_Class();
        ~Drawer_Class();

        // - Methods
        void Refresh_Drawer();
        
        // - Attributes
        Window_Type Window;
        List_Type List;

    } * Drawer_Pointer;

    ///
    /// @brief File manager class
    ///
    class File_Manager_Class
    {
    protected:
        // -- Attributes

        File *Item_Pointer;
        File Selected_Item;
        File Operation_Item;

        enum Operations
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
        uint8_t Operation;
        uint8_t Offset;

        // -- Methods

        File_Manager_Class();
        ~File_Manager_Class();

        static void Open(uint8_t = Idle);
        static bool State();
        static void Close();

        void Execute_Instruction(Instruction_Type Instruction);

        void Select_Item();
        void Validate();
        void Open_Home_Directory();
        void Open_Root_Directory();
        void Copy_Item();
        void Cut_Item();
        void Create_File();
        void Create_Folder();

        /*inline Instruction_Type Get_Mode()
        {
            return Mode;
            DUMP("get mode");
            DUMP(this->Mode);
        }*/
        
        inline void Set_Operation(uint8_t Operation)
        {
            this->Operation = Operation;
            DUMP("set operation");
            DUMP(this->Operation);
        }
        inline uint8_t Get_Operation()
        {
            return Operation;
            DUMP("get operation");
            DUMP(this->Operation);
        }

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

        char Username[Maximum_Username_Length + 1];
        char Target_Username[Maximum_Username_Length + 1];
        char Password_1[Maximum_Password_Length + 1];
        char Password_2[Maximum_Password_Length + 1];

        int32_t GMT_Offset; // -- Time
        int16_t Daylight_Offset;
        char NTP_Server[sizeof(Time.NTP_Server)];

        char Name[25]; // -- System

        char WiFi_Name[33]; // -- Network
        char WiFi_Password[sizeof(WiFi.Password)];

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

        void Execute_Hardware_Instruction(Instruction_Type Instruction);
        void Execute_Network_Instruction(Instruction_Type Instruction);
        void Execute_Personal_Instruction(Instruction_Type Instruction);
        void Execute_System_Instruction(Instruction_Type Instruction);
        void Execute_Install_Instruction(Instruction_Type Instruction);

        inline void System_Update();

        friend class Shell_Class;

    } * Preferences_Pointer;

    // -- Attributes

    // -- Methods

    void Execute_Instruction(Instruction_Type Instruction);
    void Refresh_Header();
    uint32_t Next_Refresh;
    char Temporary_Char_Array[6];

    Result::Type Save_Registry();
    Result::Type Load_Registry();

    static void Main_Task(void *);

public:
    // -- Methods

    static void Create_Instance();

    static void Startup();

    Shell_Class();
    ~Shell_Class();
};

// -- Shell handle -- //

extern Xila_Class::Software_Handle Shell_Handle;

// -- Shortcuts -- //
#define SHELL Shell_Class::Instance_Pointer
#define PREFERENCES SHELL->Preferences_Pointer
#define FILE_MANAGER SHELL->File_Manager_Pointer
#define DESK SHELL->Desk
#define DIALOG SHELL->Dialog

#define KEYBOARD DIALOG.Keyboard_Pointer
#define KEYPAD DIALOG.Keypad_Pointer
#define COLOR_PICKER DIALOG.Color_Picker_Pointer
#define EVENT DIALOG.Event_Pointer
#define POWER DIALOG.Power_Pointer
#define LOAD DIALOG.Load_Pointer
#define LOGIN DIALOG.Login_Pointer

#endif