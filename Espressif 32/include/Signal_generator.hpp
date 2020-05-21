#ifndef SIGNAL_GENERATOR_INCLUDED
#define SIGNAL_GENERATOR_INCLUDED

#include "Arduino.h"
#include "galaxos.hpp"

class Signal_Generator_Class
{
private:
    static uint8_t Number_Instance;

    uint16_t Socket_Method;

    xTaskHandle Socket_Handle;

public:

    Signal_Generator_Class();
    ~Signal_Generator_Class();

    void Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2);

    friend void Signal_Generator_Socket(void *pvParameters);

};

void Signal_Generator_Socket(void *pvParameters);

#endif