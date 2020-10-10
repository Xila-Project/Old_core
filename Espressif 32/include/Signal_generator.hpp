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

    Signal_Generator_Class(Software_Handle_Class*);
    ~Signal_Generator_Class();

    void Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2);


    friend void Signal_Generator_Socket(void*);

public:
    static Software_Class* Load();
};

void Signal_Generator_Socket(void*);

Software_Handle_Class Signal_Generator_Handle("Signal Generator", 12, Signal_Generator_Class::Load)

#endif