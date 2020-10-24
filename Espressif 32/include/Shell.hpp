#ifndef SHELL_HPP_INCLUDED
#define SHELL_HPP_INCLUDED

#include "GalaxOS.hpp"

#define INSTANCE_POINTER Shell_Class::Instance_Pointer

class Shell_Class : public Software_Class
{
protected:

    File Temporary_File;

    uint8_t Mode;
    String Current_Path;

    static Shell_Class* Instance_Pointer;

    static Software_Handle_Class* Handle_Pointer;

    uint8_t Selected_Software;

    char Username[9];
    char Password[25];

    void Login();

    void Open_Desk();
    void Open_Menu();
    void Open_Item();
    void Open_Login();

    void Display_Path();

    void Make_Directory(char *);
    void Make_File(char *);
    void Rename(char *);
    void Delete(char *);
    void Go_Parent();

    void Open_From_Dock(uint8_t);
    void Open_From_Menu();

    void Set_Variable(const void*, uint8_t, uint8_t, uint8_t = 0);

    friend void Shell_Task(void *);

public:
    static Software_Class* Load();

    Shell_Class();
    ~Shell_Class();
};

void Shell_Task(void *);

Software_Handle_Class Shell_Handle("Shell", 5, Shell_Class::Load);

#endif