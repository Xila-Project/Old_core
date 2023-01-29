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

/// @brief Shell class
///
/// @details Main inter
class Shell_Class : public Software_Type
{
    // - Attributes

    /// @brief Instance pointer, help to keep track of current instance.
    static std::vector<Shell_Class *> Instances;

    // - Types

    /// @brief Desk class
    class Desk_Class
    {
    public:
        // - Methods

        static void Open(Shell_Class *Shell_Pointer);
        static void Close(Shell_Class *Shell_Pointer);
        static bool Is_Open(Shell_Class *Shell_Pointer);

        void Execute_Instruction(const Instruction_Type &Instruction);

    protected:
        // - Methods

        // - - Constructors / destructor
        Desk_Class(Shell_Class *Shell_Pointer);
        ~Desk_Class();

        void Refresh();

        // - Attributes
        Window_Type Window;
        Object_Type Desk_Grid;
        Object_Type Dock;
        Object_Type Menu_Button;
        Object_Type Dock_List;

        Shell_Class *Shell_Pointer;
    } *Desk_Pointer;

    class Drawer_Class
    {
    public:
        static void Open(Shell_Class *Shell_Pointer);
        static void Close(Shell_Class *Shell_Pointer);
        static bool Is_Open(Shell_Class *Shell_Pointer);

        void Execute_Instruction(Instruction_Type Instruction);
    private:
        // - Attributes
        Window_Type Window;

        Drawer_Class(Shell_Class *Shell_Pointer);
        ~Drawer_Class();

        static const Instruction_Type Click_On_Item;

        Shell_Class *Shell_Pointer;

        friend class Shell_Class;

    } *Drawer_Pointer;

    class Login_Class
    {
    public:
        static void Open(Shell_Class *Shell_Pointer);
        static bool Is_Openned(Shell_Class *Shell_Pointer);
        static void Close(Shell_Class *Shell_Pointer);

    private:
        
        Login_Class(Shell_Class *Shell_Pointer);
        ~Login_Class();

        void Execute_Instruction(Instruction_Type Instruction);

        Dialog_Type Dialog;

        Text_Area_Type Name_Input;
        Text_Area_Type Password_Input;
        Button_Type Login_Button;
        Label_Type Login_Label;
        Keyboard_Type Keyboard;

        Shell_Class *Shell_Pointer;
    } *Login_Pointer;

    ///
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

        File_Manager_Class(Shell_Class *Shell_Pointer);
        ~File_Manager_Class();

        Shell_Class *Shell_Pointer;

        static void Open(uint8_t = Idle);

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
        }

        inline uint8_t Get_Operation()
        {
            return Operation;
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

    } *File_Manager_Pointer;

    ///
    /// @brief Preferences class
    ///
    class Preferences_Class
    {
    public:
        // -- Constructor

        Preferences_Class(Shell_Class *Shell_Pointer);

        Window_Type Window;
        Tabs_Type Tabs;
        Object_Type Personnal_Tab, Softwares_Tab, Hardware_Tab, Network_Tab, Users_Tab, System_Tab;

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

        Shell_Class *Shell_Pointer;

        IPAddress Local_IP;
        IPAddress Gateway_IP;
        IPAddress Subnet_Mask;
        IPAddress DNS[2];

        uint16_t Write_Speed, Read_Speed; // -- Hardware

        // -- Methods
        static void Open(uint8_t Mode);
        static void Close();

        void Refresh_Hardware();
        void Refresh_Personal();
        void Refresh_Network();
        void Refresh_System();
        void Refresh_Install();

        void Execute_Instruction(Instruction_Type Instruction);

        inline void System_Update();

        friend class Shell_Class;

    } *Preferences_Pointer;

    // -- Attributes

    // -- Methods

    void Execute_Instruction(Instruction_Type Instruction);
    void Refresh_Header();
    uint32_t Next_Refresh;
    char Temporary_Char_Array[6];

    Result_Type Save_Registry();
    Result_Type Load_Registry();

    void Main_Task_Function();

    Software_Type *Open_Shell();

public:
    // -- Methods

    static Software_Handle_Type Handle;

    static void Startup();

    Shell_Class();
    ~Shell_Class();

    static void Create_Instance()
    {
        new Shell_Class();
    }
};

// -- Shortcuts -- //

#define KEYBOARD DIALOG.Keyboard_Pointer
#define KEYPAD DIALOG.Keypad_Pointer
#define COLOR_PICKER DIALOG.Color_Picker_Pointer
#define EVENT DIALOG.Event_Pointer
#define POWER DIALOG.Power_Pointer
#define LOAD DIALOG.Load_Pointer
#define LOGIN DIALOG.Login_Pointer

#endif