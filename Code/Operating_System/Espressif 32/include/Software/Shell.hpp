/**
 * @file Shell.hpp
 * @brief Xila's user interface header file.
 * @author Alix ANNERAUD
 * @copyright MIT License
 * @version 0.1.0
 * @date 21/05/2020
 * @details Xila user interface software.
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
#ifndef SHELL_HPP_INCLUDED
#define SHELL_HPP_INCLUDED

#include "Xila.hpp"

/**
 * @class Shell_Class Shell.hpp
 * 
 * @
*/
class Shell_Class : public Software_Class
{
protected:
    static Shell_Class *Instance_Pointer;

    

    // Login page variable
    char Username[9];
    char Password[25];

    // File Manager variable 
    char Current_Item_Name[13];
    
    char Current_Path[192];

    // 


    char Password_1[25];
    char Password_2[25];

    char Device_Name[25];

    char WiFi_Name[25];
    char WiFi_Password[25];

    uint32_t Temporary_Variable[4];

    uint8_t Automatic_Login;

    char Temporary_Char[14];

    /**
     * @enum Pages
     */
    enum Pages
    {
        About = 27,
        Desk,
        Drawer,
        Event,
        File_Manager,
        Preferences_Hardware,
        Install,
        Keyboard,
        Keypad,
        Login,
        Preferences_Network,
        Preferences_Personal,
        Shutdown,
        Preferences_System,
        Welcome,
    };

    uint8_t Offset;

    void Login();
    void Logout();

    void System_Update();

    // Command
    uint16_t Current_Command;

    inline void Open_Keypad();
    inline void Open_Keyboard();

    void Main_Commands();
    void Desk_Commands();

    void Keyboard_Commands();
    void Keypad_Commands();

    void Preferences_Hardware_Commands();
    void Preferences_Network_Commands();
    void Preferences_Personal_Commands();
    void Preferences_System_Commands();

    void Shutdown_Commands();

    void Drawer_Commands();
    void Login_Commands();
    void Install_Commands();
    void Load_Commands();
    void File_Manager_Commands();

    Xila_Event Set_Registry(uint32_t Desk_Background = 0xFFFFFFFF);
    Xila_Event Load_Registry();

    void Open_Install();

    inline void Idle();

    uint32_t Desk_Background;

    void Open_Desk();
    void Open_Drawer();
    void Refresh_Drawer();
    void Open_Item();

    void Open_Login();
    
    void Open_Load(uint8_t Mode);

    void Refresh_Login();

    enum Load_Mode
    {
        Login,
        Shutdown,
    };

    File Selected_Item;

    File Temporary_Item;

    uint8_t Operation;

    enum File_Manager_Operation
    {
        Browse,
        New_File,
        New_Folder,
        Delete,
        Rename,
        Copy,
        Cut
    };


    // -- Related to Xila.Instruction
    uint8_t Mode;


    inline void Fill_Footer_Bar();
    inline void Empty_Footer_Bar();

    inline void Open_File();

    void Select_Item();
    void Open_File_Manager();
    void Open_Preferences(char const &Section);

    void Refresh_File_Manager();
    void Make_Directory();
    void Make_File();
    void Go_Parent();

    void Dock(uint8_t, uint8_t);
    void Open_From_Drawer(uint8_t);

    void Set_Variable(const void *, uint8_t, uint8_t, uint8_t = 0);

    static void Main_Task(void *);

public:
    static Software_Class *Load();

    static void Startup();

    enum Images
    {
        File_Manager_32 = 4,
        Preferences_32 = 3,
        Empty_16 = 14,
        File_16 = 15,
        Folder_16 = 16,
        Home_24 = 35,
        Copy_24,
        Cut_24,
        Paste_24,
        Trash_24,
        New_File_24,
        New_Folder_24,
        Rename_24,
        Root_24,
        Empty_32 = 38
    };

    Shell_Class();
    ~Shell_Class();
};

Software_Handle_Class Shell_Handle("Shell", Shell_Class::Empty_32, Shell_Class::Load, Shell_Class::Startup);

#endif