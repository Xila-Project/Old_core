#include "signal_generator.hpp"

uint8_t Signal_Generator_Class::Number_Instance = 0;

Signal_Generator_Class::Signal_Generator_Class()
{
    if (Number_Instance > 0)
    {
        delete this;
        //error handle
    }

    ++Number_Instance;

    xTaskCreatePinnedToCore(Signal_Generator_Socket, "Signal Generator", 1024*4, NULL, 2, &Socket_Handle, 1);
}

Signal_Generator_Class::~Signal_Generator_Class()
{
    vTaskDelete(Socket_Handle);
    --Number_Instance;
}

void Signal_Generator_Class::Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2)
{
    Socket_Method = ((uint16_t)Socket_Method_Char1 << 8) | (uint16_t)Socket_Method_Char2;
    vTaskResume(Socket_Handle);
}

void Signal_Generaot_Socket(void *pvParameters)
{
    Signal_Generator_Class *Signal_Generator_Pointer;
    GalaxOS.Get_Software_Pointer(Signal_Generator_Pointer);
}