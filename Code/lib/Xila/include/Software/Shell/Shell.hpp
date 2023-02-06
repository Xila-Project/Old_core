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
public:
    // - Types

    static Software_Handle_Type Handle;

private:

    static void Create_Instance()
    {
        new Shell_Class();
    }

    // -- Methods

    Shell_Class();
    ~Shell_Class();

    // - Attributes

    /// @brief Instance pointer, help to keep track of current instance.
    static std::vector<Shell_Class *> Instances;

    // - Types

    /// @brief Desk class
    class Desk_Class
    {
    public:
        // - Methods
        void Execute_Instruction(const Instruction_Type &Instruction);

    private:
        // - Methods

        // - - Constructors / destructor
        Desk_Class(Shell_Class* Shell_Pointer);
        ~Desk_Class();

        void Refresh();

        // - Attributes
        Window_Type Window;
        Object_Type Desk_Grid;
        Object_Type Dock;
        Object_Type Menu_Button;
        Object_Type Dock_List;

        Shell_Class* Shell_Pointer;
    } Desk;

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
    public:
        static void Open(Shell_Class *Shell_Pointer);
        static bool Is_Openned(Shell_Class *Shell_Pointer);
        static void Close(Shell_Class *Shell_Pointer);

    private:
        // -- Attributes
        char Buffer[256];

        bool Cut;

        // -- Methods

        File_Manager_Class(Shell_Class *Shell_Pointer);
        ~File_Manager_Class();

        void Refresh();

        void Enable_Selection_Mode(bool Multiple);
        void Disable_Selection_Mode();
        uint8_t Count_Selected_Items();

        void Execute_Instruction(Instruction_Type Instruction);

        void Paste();
        void Details();
        void Go_Parent_Folder();
        void Click();
        void Rename();
        void Delete();
        void Create_File();
        void Create_Folder();

        Window_Type Window;

        Object_Type Grid;
        Object_Type Flexbox;
        Text_Area_Type Path_Text_Area;
        List_Type List;
        Button_Type Parent_Folder_Button;
        Button_Type Home_Folder_Button;
        Button_Type Root_Folder_Button;
        Button_Type Refresh_Button;
        Button_Type New_Folder_Button;
        Button_Type New_File_Button;
        Button_Type Select_Button;
        Button_Type Deselect_Button;
        Button_Type Delete_Button;
        Button_Type Rename_Button;
        Button_Type Copy_Button;
        Button_Type Cut_Button;
        Button_Type Paste_Button;
        Button_Type Details_Button;
        
        Dialog_Type Details_Dialog;
        Table_Type Details_Table;
                
        
        Shell_Class *Shell_Pointer;

        friend class Shell_Class;

    } *File_Manager_Pointer;

    /// @brief Preferences class
    class Preferences_Class
    {
    public:
    
        static void Open(Shell_Class *Shell_Pointer);
        static bool Is_Openned(Shell_Class *Shell_Pointer);
        static void Close(Shell_Class *Shell_Pointer);

    private:
        // -- Constructor

        Preferences_Class(Shell_Class *Shell_Pointer);

        Window_Type Window;
        Tabs_Type Tabs;
        Object_Type Personnal_Tab, Softwares_Tab, Hardware_Tab, Network_Tab, Users_Tab, System_Tab;
        Keyboard_Type Keyboard;

        static Coordinate_Type Column_Descriptor[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
        static Coordinate_Type Row_Descriptor[] = {40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 40, LV_GRID_TEMPLATE_LAST};

        void Draw_Personal();
        void Draw_Softwares();
        void Draw_Hardware();
        void Draw_Network();
        void Draw_Users();
        void Draw_System();


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
        static void Close();

        void Refresh_Hardware();
        void Refresh_Personal();
        void Refresh_Network();
        void Refresh_System();
        void Refresh_Install();

        void Execute_Instruction(Instruction_Type Instruction);

        inline void System_Update();

        Shell_Class* Shell_Pointer;

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
};

#endif