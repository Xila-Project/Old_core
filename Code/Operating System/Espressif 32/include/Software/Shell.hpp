#ifndef SHELL_HPP_INCLUDED
#define SHELL_HPP_INCLUDED

#include "Xila.hpp"

class Shell_Class : public Software_Class
{
protected:
    static Shell_Class *Instance_Pointer;

    uint32_t Temporary_Variable[4];

    char *Temporary_Char_Array[3];

    uint8_t Automatic_Login;

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

    // Command
    uint16_t Current_Command;

    void Main_Commands();
    void Desk_Commands();

    void Keyboard_Commands();
    void Numpad_Commands();

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

    enum Load_Mode
    {
        Login,
        Shutdown,
    };

    enum File_Manager_Mode
    {
        Browse,
        New_File,
        Delete_File,
        Rename_File,
        Copy_File,
        Cut_File,
        Open_File,
        Open_Folder,
        Save_File
    };

    File Temporary_File;

    uint8_t Mode;
    // 0 : default (browse)
    // 1 : new file
    // 2 : delete file
    // 3 : rename file
    // 4 : copy file
    // 5 : open file
    // 6 : open folder
    // 7 : save file

    char Current_Item_Name[13];
    char Current_Path[128];

    void Select_Item();
    void Open_File_Manager();
    void Open_Preferences(char const &Section);

    void Make_Directory();
    void Make_File();
    void Rename();
    void Delete();
    void Go_Parent();

    void Dock(uint8_t, uint8_t);
    void Open_From_Drawer(uint8_t);

    void Set_Variable(const void *, uint8_t, uint8_t, uint8_t = 0);

    static void Main_Task(void *);

public:
    static Software_Class *Load();

    static void Startup();

    enum Image
    {
        File_Manager_32 = 4,
        Preferences_32 = 3,
        Empty_16 = 14,
        File_16 = 15,
        Folder_16 = 16,
        Empty_32 = 38
    };

    Shell_Class();
    ~Shell_Class();
};

Software_Handle_Class Shell_Handle("Shell", Shell_Class::Empty_32, Shell_Class::Load, Shell_Class::Startup);

#endif