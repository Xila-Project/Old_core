#include "calculator.hpp"

Calculator_Class::Calculator_Class()
{
    if(Number_Instance > 0) {
        delete this;
    }

    ++Number_Instance;


}

Calculator_Class::~Calculator_Class()
{
    --Number_Instance;
}

void Calculator_Class::Execute(uint16_t const &Socket_Method_To_Set)
{
    Socket_Method = Socket_Method_To_Set;
    vTaskResume(Socket_Handle);
}

void Calculator_Class::Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2)
{
    Socket_Method = ((uint16_t)Socket_Method_Char1 << 8) | (uint16_t)Socket_Method_Char2;
    vTaskResume(Socket_Handle);
}

void Calculator_Socket(void *pvParameters)
{
    Calculator_Class *Calculator_Pointer = GalaxOS.Get_Software_Pointer();
    for(;;)
    {
        switch (Calculator_Pointer->Socket_Method)
        {
        case :
            
            break;
        
        default:
            break;
        }
    }
}