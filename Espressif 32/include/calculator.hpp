#ifndef CALCULATOR_HPP_INCLUDED
#define CALCULATOR_HPP_INCLUDED

#include "GalaxOS.hpp"
#include "Arduino.h"

#define NEPER_CONSTANT 2.71828182845904523536028747135266249

class Calculator_Class : public Software_Class
{
private:

    static Calculator_Class* Instance_Pointer;
    
    float Result;

    float Number[2];


    uint8_t Operator;

    uint8_t Current_Number;

    void Add_Number(uint8_t const& Number_To_Add);
    void Switch_Symbol();
    void Set_Operator(char const& Operator_To_Set);

    float Degree_To_Radian(float);

    uint8_t Angle_Unity;

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
        Arc_Hyperbolic_Tangent
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