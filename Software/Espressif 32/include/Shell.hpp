#ifndef SHELL_HPP_INCLUDED
#define SHELL_HPP_INCLUDED

#include "Xila.hpp"

class Shell_Class : public Software_Class
{
protected:
    File Temporary_File;

    uint8_t Mode;
    String Current_Path;

    static Shell_Class *Instance_Pointer;

    char* Temporary_Variable;
    char Username[9];
    char Password[25];
    char Password_To_Set[25];

    uint8_t Automatic_Login;

    enum Pages
    {
        About = 28,
        Desk,
        Drawer,
        File_Manager,
        Preferences_Hardware,
        Installation,
        Login,
        Preferences_Network,
        Preferences_Personal,
        Shutdown,
        Preferences_System,
        Task_Manager,
        Welcome,
    };

    void Login();
    void Logout();

    // Command
    uint16_t Current_Command;
    
    void Main_Commands();
    void Desk();
    void Shutdown();
    void Drawer();

    void Install();

    void Open_Install();

    uint16_t Desk_Background;
    void Open_Desk();
    void Open_Drawer();
    void Open_Item();
    void Open_Login();
    void Open_File_Manager();
    void Open_Preferences(char const &Section);

    void Modify_User(uint8_t const &Mode);

    void Display_Path();

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
    static Software_Class *Load();

    static void Startup();

    enum Picture
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