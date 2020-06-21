#include "GalaxOS.hpp"
#include "Software.hpp"

class Shell_Class : public Software_Class
{
private:
    const byte Page_Desk = 19;
    const byte Page_Menu = 31;


public:
    
    Shell_Class();
    ~Shell_Class();

    void Load();
    
    static Shell_Class *Instance_Pointer;

    void Maximize();
    void Minimize();

    void Execute(uint16_t const &Socket_Method_To_Set);
    void Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2);

    void Login();

    void Open_Desk();
    void Open_Menu();
    void Open_Item();
};

void Shell_Task(void *pvParameters);