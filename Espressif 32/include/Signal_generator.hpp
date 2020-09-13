#ifndef SIGNAL_GENERATOR_INCLUDED
#define SIGNAL_GENERATOR_INCLUDED

#include "GalaxOS.hpp"

#define INSTANCE_POINTER Signal_Generator_Class::Instance_Pointer

class Signal_Generator_Class : protected Software_Class
{
protected:
    static uint8_t Number_Instance;

    uint16_t Socket_Method;

    xTaskHandle Socket_Handle;

    Signal_Generator_Class();
    ~Signal_Generator_Class();

    void Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2);

    friend void Signal_Generator_Socket(void*);

};

void Signal_Generator_Socket(void*);

#endif