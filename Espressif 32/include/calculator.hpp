#ifndef CALCULATOR_HPP_INCLUDED
#define CALCULATOR_HPP_INCLUDED

#include "GalaxOS.hpp"
#include "Arduino.h"

class Calculator_Class : public Software_Class
{
private:

    static Calculator_Class* Instance_Pointer;
    
    float Result;

    float Number[5];


    uint8_t Operator[4];

    

    uint8_t Current_Number;

    void Add_Number(uint8_t const& Number_To_Add);
    void Set_Operator(char const& Operator_To_Set);

    void Clear();
    void Clear_Last_Number();

    void Compute();

    void Display();

public:
    Calculator_Class(Software_Handle_Class*);
    ~Calculator_Class();

    friend void Calculator_Task(void *pvParameters);
};

void Calculator_Task(void *pvParamters);

#endif