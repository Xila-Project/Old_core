#ifndef SHELL_HPP_INCLUDED
#define SHELL_HPP_INCLUDED

#include "Xila.hpp"

class Shell_Class : public Software_Class
{
protected:
    File Temporary_File;

    uint8_t Mode;
    char Current_Path[64];

    static Shell_Class *Instance_Pointer;

    uint32_t Temporary_Variable[4];

    char* Temporary_Char_Array[3];

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

    // 0 : default (browse)
    // 1 : open file
    // 2 : open folder
    // 3 : save file
    // 4 : new file
    // 5 : delete file
    // 6 : rename file
    // 7 : copy file
    uint8_t File_Manager_Mode;
    
    void Open_File_Manager();
    void Open_Preferences(char const &Section);

    uint8_t Drawer_Offset;



    void Make_Directory(char *);
    void Make_File(char *);
    void Rename(char *);
    void Delete(char *);
    void Go_Parent();

    void Dock(uint8_t, uint8_t);
    void Open_From_Drawer(uint8_t);

    void Set_Variable(const void *, uint8_t, uint8_t, uint8_t = 0);

    static void Main_Task(void *);

public:
    static Software_Class* Load();

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