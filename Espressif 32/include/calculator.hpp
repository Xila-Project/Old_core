#ifndef CALCULATOR_HPP_INCLUDED
#define CALCULATOR_HPP_INCLUDED

#include "Xila.hpp"
#include "Arduino.h"

#define NEPER_CONSTANT 2.71828182845904523536028747135266249

class Calculator_Class : public Software_Class
{
private:

    static Calculator_Class* Instance_Pointer;
    
    float Result;

    float Number[2];

    float Memory;

    uint8_t Operator;

    uint8_t State;


    
    // 0 : taping Number[0]
    // 1 : taping Number[1]
    // 2 : have computed the result

    uint8_t Keys_Mode;

    // 00000000 : Normal mode 
    // 00000001 : 2nd mode
    // 00000010 : Hyperbolic mode
    // 00000100 : Degree mode
    // 00001000 : AC mode

    void Add_Number(uint8_t const& Number_To_Add);
    void Switch_Symbol();
    void Switch_Angle_Unity();
    void Set_Operator(char const& Operator_To_Set);

    float Degree_To_Radian(float);

    void Memory_Operation(uint8_t& const);

    void Switch_Keys_Second();
    void Switch_Keys_Hyperbolic();

    void Switch_Angle_Unity();

    void Clear();
    void Clear_All();

    void Compute();

    void Display();

    enum Angle_Unity
    {
        Degree,
        Radian
    };

    enum Special_Number
    {
        Pi,
        Exponential,
        Random
    };

    enum Operation
    {
        Addition = '+',
        Substraction = '-',
        Multiplication = '*',
        Division = ':',
        Modulo = '%',
        Factorial,
        Logarithm,
        Natural_Logarithm,
        Square_Root,
        Cubic_Root,
        Root,
        Sine = 180,
        Cosine,
        Tangent,
        Arc_Sine,
        Arc_Cosine,
        Arc_Tangent,
        Hyperbolic_Sine,
        Hyperbolic_Cosine,
        Hyperbolic_Tangent,
        Arc_Hyperbolic_Sine,
        Arc_Hyperbolic_Cosine,
        Arc_Hyperbolic_Tangent,
        Memory_Add,
        Memory_Substract,
        Memory_Clear,
        Memory_Read
    };

public:
    Calculator_Class();
    ~Calculator_Class();

    static void Main_Task(void *pvParameters);

    enum Picture
    {
        Calculator_32 = 6
    };

    static Software_Class* Load();
};

Software_Handle_Class Calculator_Handle("Calculator", Calculator_Class::Calculator_32, Calculator_Class::Load);

#endif