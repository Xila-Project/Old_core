#ifndef CALCULATOR_HPP_INCLUDED
#define CALCULATOR_HPP_INCLUDED

#include "Xila.hpp"
#include "Arduino.h"

#define POINT_PRECISION 9

class Calculator_Class : public Software_Class
{
private:
    static Calculator_Class* Instance_Pointer;

    char Temporary_Char_Array[59];
    char Ending_Character[4];
    uint8_t Temporary_Current_Position;

    char Numbers[3][59];
    
    uint8_t Exponent[3];
    uint8_t Decimal_Point[3];
    uint8_t Current_Position[3];

    uint8_t Secondary_Operator[2];

    double Memory;

    uint8_t Primary_Operator;

    uint8_t State;
    // 0 : taping Number[0]
    // set operator + (secondary operator)
    // 1 : taping Number[1]
    // (set secondary operator)
    // 2 : have computed the result

    uint8_t Keys_Mode;

    enum Keys_Mode_Definition
    {
        Second = 0,
        Hyperbolic,
        Angle,
    };

    // 00000000 : Normal mode
    // 00000001 : 2nd mode
    // 00000010 : Hyperbolic mode
    // 00000100 : Degree mode
    // 00001000 : AC mode

    double Temporary_Numbers[3]; //Used in computation

    void Add_Number(char const &Number_To_Add);
    void Delete_Number();

    void Switch_Symbol();
    void Switch_Angle_Unity();
    void Refresh_Keys();

    void Set_Primary_Operator(char const &Operator_To_Set);
    void Set_Secondary_Operator(char const& Operator_To_Set);

    void Degree_To_Radian(uint8_t);

    void Memory_Operation(uint8_t const);

    void Switch_Keys_Second();
    void Switch_Keys_Hyperbolic();

    uint16_t Numbers_After_Point(double Number);


    void Clear();
    void Clear_All();

    void Compute();

    void Compute_Secondary(uint8_t Selected_Number);

    double fact(double Number);

    double asec(double Number);
    double acsc(double Number);
    double acot(double Number);

    double asech(double Number);
    double acsch(double Number);
    double acoth(double Number);

    void Refresh_Interface();

    void Error();

    enum Angle_Unity
    {
        Radian = 0,
        Degree
    };

    enum Special_Number
    {
        Pi = 'P',
        Neper_Constant = 'N',
        Random = 'R',
        Point = '.',
        Power_10 = 'E',
        Symbol = 'S'
    };

    enum Operation
    {
        None = '\0',
        Addition = '+',       //main
        Substraction = '-',   //main
        Multiplication = '*', //main
        Division = ':',       //main
        Modulo = '%',         //main

        Factorial = '!',         //secondary
        Decimal_Logarithm = 'l', //secondary
        Natural_Logarithm = 'L', //secondary
        Binary_Logarithm,        //secondary

        //Logarithm, //primary

        Squared, //secondary
        Cube,    //secondary

        Exponential, //secondary
        Power_2, // secondary

        Power = '^', //primary

        Square_Root, //secondary
        Cubic_Root,  //secondary

        Root = 'r', // primary

        Inverse, // secondary
        Absolute,   // secondary

        Sine = 180, //secondary
        Cosine,
        Tangent,
        Secant,
        Cosecant,
        Cotangent,
        Arc_Sine,
        Arc_Cosine,
        Arc_Tangent,
        Arc_Secant,
        Arc_Cosecant,
        Arc_Cotangent,
        Hyperbolic_Sine,
        Hyperbolic_Cosine,
        Hyperbolic_Tangent,
        Hyperbolic_Secant,
        Hyperbolic_Cosecant,
        Hyperbolic_Cotangent,
        Arc_Hyperbolic_Sine,
        Arc_Hyperbolic_Cosine,
        Arc_Hyperbolic_Tangent,
        Arc_Hyperbolic_Secant,
        Arc_Hyperbolic_Cosecant,
        Arc_Hyperbolic_Cotangent,

        Memory_Add,
        Memory_Substract,
        Memory_Clear,
        Memory_Read
    };

public:
    Calculator_Class();
    ~Calculator_Class();

    static void Main_Task(void*);

    enum Image
    {
        Icon_32 = Xila.Display.Calculator_Images
    };

    static Software_Class *Load();
};

Software_Handle_Class Calculator_Handle("Calculator", Calculator_Class::Icon_32, Calculator_Class::Load);

#endif