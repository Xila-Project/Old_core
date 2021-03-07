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
    // -- Variable

    static Shell_Class *Instance_Pointer;

    float Temporary_Float;

    // Login page variable

    // -- File Manager variable

    char Current_Item_Name[13];
    char Current_Path[192];

    // -- Hardware

    uint8_t Brightness;

    uint16_t Standby_Display_Time;
    uint16_t Standby_System_Time;

    // -- Preferences system attributes

    bool Autologin;

    int32_t GMT_Offset;      // -- Shared with install wizard
    int16_t Daylight_Offset; // -- Shared with install wizard

    char NTP_Server[sizeof(Xila.NTP_Server)];
    char Device_Name[25]; // -- Shared with install wizard

    char Target_Username[9];
    char Username[9];    // -- Shared with install wizard and login
    char Password_1[25]; // -- Shared with install wizard and login
    char Password_2[25]; // -- Shared with install wizard

    // -- Preferences network attributes

    char WiFi_Name[25];     // -- Shared with install wizard
    char WiFi_Password[65]; // -- Shared with install wizard

    // -

    uint32_t Temporary_Variable[4];

    uint8_t Automatic_Login;

    char Temporary_Char[14];

    // -- Desk variables
    int32_t Desk_Background;
    /**
     * -1 = Default desk background
     * 0 - 65535 : Custom color
    */

    /**
     * @enum Pages
     */
    enum Pages
    {
        About = 20,
        Color_Picker, // color picker
        Desk,
        Drawer,
        Event,
        File_Manager,
        Preferences_Hardware,
        Install,
        Keyboard,
        Keypad,
        Login,
        Load,
        Preferences_Network,
        Preferences_Personal,
        Shutdown,
        Preferences_System,
        Welcome,
    };

    uint8_t Offset;

    // -- Methods

    //

    void Logout();

    //

    inline void System_Update();

    // -- Preferences methods

    inline void Open_Preferences_Hardware();
    inline void Open_Preferences_Network();
    inline void Open_Preferences_System();
    inline void Open_Preferences_Personal();

    void Refresh_Preferences_Hardware();
    void Refresh_Preferences_Personal();
    void Refresh_Preferences_Network();
    void Refresh_Preferences_System();

    void Preferences_Hardware_Commands();
    void Preferences_Network_Commands();
    void Preferences_Personal_Commands();
    void Preferences_System_Commands();

    // -- Desk methods

    void Refresh_Desk();
    void Desk_Commands();

    void Dock(uint8_t, uint8_t);

    // -- Global scope

    uint16_t Current_Command;
    void Main_Commands();

    // -- Dialog boxes method

    inline void Open_Color_Picker();
    inline void Open_Keypad();
    inline void Open_Keyboard();

    inline void Color_Picker_Commands();
    inline void Event_Commands();
    inline void Keyboard_Commands();
    inline void Keypad_Commands();

    // -- Custom dialog boxes

    Xila_Event Keyboard_Dialog(char *, size_t, bool = false);
    Xila_Event Event_Dialog(const __FlashStringHelper *, uint8_t, const __FlashStringHelper * = NULL, const __FlashStringHelper * = NULL, const __FlashStringHelper * = NULL);

    // -- Shutdown

    inline void Open_Shutdown();
    void Shutdown_Commands();

    // -- Desk

    void Open_Desk();

    void Login_Commands();
    void Install_Commands();
    void Load_Commands();
    void File_Manager_Commands();

    // -- Drawer
    
    void Open_Drawer();
    void Refresh_Drawer();
    void Open_From_Drawer(uint8_t);
    void Drawer_Commands();

    // -- Registry management

    Xila_Event Set_Registry(uint32_t Desk_Background = 0xFFFFFFFF);
    Xila_Event Load_Registry();

    // -- Installation wizard methods

    void Refresh_Install();

    inline void Open_Install();

    inline void Idle();

    //

    void Open_Item();

    void Open_Login();

    void Open_Load(uint8_t Mode);

    void Refresh_Login();

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

    // -- File manager methods

    inline void Fill_Footer_Bar();
    inline void Empty_Footer_Bar();

    void Select_Item();
    void Open_File_Manager();

    void Refresh_File_Manager();
    void Make_File();
    void Go_Parent();

    char Temporary_File_Name[192];
    const char *Get_File_Name(File const &File); // Temporary fix to file name issues

    //

    void Set_Variable(const void *, uint8_t, uint8_t, uint8_t = 0);

    static void Main_Task(void *);

public:
    static Software_Class *Load_Shell();

    static void Startup();

    enum Images
    {
        Empty_16 = Xila.Shell,
        File_16,
        Folder_16,
        Copy_24,
        Cut_24,
        Home_24,
        New_File_24,
        New_Folder_24,
        Paste_24,
        Refresh_24,
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

    Shell_Class();
    ~Shell_Class();
};

Software_Handle_Class Shell_Handle("Shell", Shell_Class::Empty_32, Shell_Class::Load_Shell, Shell_Class::Startup);

#endif