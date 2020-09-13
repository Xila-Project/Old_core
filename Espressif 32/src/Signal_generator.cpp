#include "signal_generator.hpp"

uint8_t Signal_Generator_Class::Number_Instance = 0;

Signal_Generator_Class::Signal_Generator_Class(Software_Handle_Class* Software_Handle_To_Set) : Software_Class(Software_Handle_To_Set, 6)
{
    xTaskCreatePinnedToCore(Signal_Generator_Socket, "Signal Generator", 1024*4, NULL, 2, &Socket_Handle, 1);
}

Signal_Generator_Class::~Signal_Generator_Class() : ~Software_Class()
{
}

void Signal_Generator_Class::Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2)
{
    Socket_Method = ((uint16_t)Socket_Method_Char1 << 8) | (uint16_t)Socket_Method_Char2;
    vTaskResume(Socket_Handle);
}

void Signal_Generator_Socket(void *pvParameters)
{
    while(1)
    {
        switch(Get_Command())
        {
            case 0:
                break;
            default :
                break;
        }
    }
}