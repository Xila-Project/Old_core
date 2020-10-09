#ifndef SHELL_HPP_INCLUDED
#define SHELL_HPP_INCLUDED

#include "GalaxOS.hpp"

#define INSTANCE_POINTER Shell_Class::Instance_Pointer

class Shell_Class : public Software_Class
{
protected:
    
    File Temporary_File;

    uint8_t Mode;
    char* Current_Path;


    Shell_Class(Software_Handle_Class*);
    ~Shell_Class();
    
    static Shell_Class *Instance_Pointer;

    Software_Class* Load(Software_Handle_Class*);

    void Login();

    void Open_Desk();
    void Open_Menu();
    void Open_Item();
    void Open_Login();

    void Display_Path();

    void Make_Directory(char*);
    void Make_File(char*);
    void Rename(char*);
    void Delete(char*);
    void Go_Parent();

    void Open_From_Dock(uint8_t);
    void Open_From_Menu();

    friend void Shell_Task(void*);
};

void Shell_Task(void*);

#endif