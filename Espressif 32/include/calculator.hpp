#ifndef CALCULATOR_HPP_INCLUDED
#define CALCULATOR_HPP_INCLUDED

#include "Arduino.h"

class Calculator_Class
{
private:

    float Number

    static uint8_t Number_Instance;

    uint16_t Socket_Method;

    xTaskHandle Socket_Handle;

public:
    Calculator_Class();
    ~Calculator_Class();

    void Execute(uint16_t const &Socket_Method_To_Set);
    void Execute(char const &Socket_Method_Char1, char const &Socket_Method_Char2);

    friend void Calculator_Socket(void *pvParameters);
};

void Calculator_Socket(void *pvParamters);

#endif