#include "calculator.hpp"
#include "object.hpp"

uint8_t Calculator_Class::Number_Instance = 0;

Calculator_Class::Calculator_Class()
{
    if(Number_Instance > 0) {
        delete this;
        return;
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
    Calculator_Class *Calculator_Pointer;
    GalaxOS.Get_Software_Pointer(Calculator_Pointer);
    for(;;)
    {
        switch (Calculator_Pointer->Socket_Method)
        {
        case 0:
            
            break;
        
        default:
            break;
        }
        Calculator_Pointer->Socket_Method = 0;
        vTaskSuspend(NULL);
    }
}