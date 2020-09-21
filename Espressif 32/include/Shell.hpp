#include "GalaxOS.hpp"

#define INSTANCE_POINTER Shell_Class::Instance_Pointer

class Shell_Class : public Software_Class
{
protected:
    const byte Page_Desk = 19;
    const byte Page_Menu = 31;
    
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

    friend void Shell_Task(void*);
};

void Shell_Task(void*);