#ifndef SHELL_HPP_INCLUDED
#define SHELL_HPP_INCLUDED

#include "GalaxOS.hpp"

#define INSTANCE_POINTER Shell_Class::Instance_Pointer

class Shell_Class : public Software_Class
{
protected:
    const byte Page_Desk = 19;
    const byte Page_Menu = 31;
    
    File Temporary_File;

    uint8_t Mode;
    char* Current_Path;


    Shell_Class(Software_Handle_Class*);
    ~Shell_Class();
    
    static Shell_Class *Instance_Pointer;

    Software_Class* Load(Software_Handle_Class*);

    void Maximize();
    void Minimize();

    void Execute(uint16_t const&);
    void Execute(char const&, char const&);

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

    friend void Shell_Task(void*);
};

void Shell_Task(void*);

#endif