///
 /// @file Mathematics.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1
 /// @date 11-07-2021
 /// 
 /// @copyright Copyright (c) 2021
 /// 

#include "Arduino.h"

#ifndef MATHEMATICS_HPP_INCLUDED
#define MATHEMATICS_HPP_INCLUDED

///
 /// @brief Check if a float is a number.
 /// 
 /// @param Number 
 /// @return true 
 /// @return false 
inline bool Xila_Class::Mathematics_Class::Is_NAN(double Number)
{
    return isnan(Number);
}

///
 /// @brief Check if a number is infinite.
 /// 
 /// @param Number 
 /// @return true 
 /// @return false 
inline bool Xila_Class::Mathematics_Class::Is_Infinite(double Number)
{
    return isinf(Number);
}

///
 /// @brief Copy sign from a number to another.
 /// 
 /// @param Number_1 Origin number.
 /// @param Number_2 Destination number.
 /// @return double New number sign 
inline double Xila_Class::Mathematics_Class::Copy_Sign(double Number_1, double Number_2)
{
    return copysign(Number_1, Number_2);
}

inline double Xila_Class::Mathematics_Class::Floor(double Number)
{
    return floor(Number);
}

inline double Xila_Class::Mathematics_Class::Modulo(double Number_1, double Number_2)
{
    return fmod(Number_1, Number_2);
}

inline double Xila_Class::Mathematics_Class::Radians(double Degrees)
{
    return Degrees * Degrees_To_Radians;
}

inline double Xila_Class::Mathematics_Class::Degrees(double Radians)
{
    return Radians * Radians_To_Degrees;
}

inline double Xila_Class::Mathematics_Class::Sine(double Number)
{
    return sin(Number);
}

inline double Xila_Class::Mathematics_Class::Cosine(double Number)
{
    return cos(Number);
}

inline double Xila_Class::Mathematics_Class::Tangent(double Number)
{
    return tan(Number);
}

inline double Xila_Class::Mathematics_Class::Secant(double Number)
{
    return 1 / Cosine(Number);
}

inline double Xila_Class::Mathematics_Class::Cosecant(double Number)
{
    return 1 / Sine(Number);
}

inline double Xila_Class::Mathematics_Class::Cotangeant(double Number)
{
    return 1 / Tangent(Number);
}

inline double Xila_Class::Mathematics_Class::Arc_Sine(double Number)
{
    return asin(Number);
}

inline double Xila_Class::Mathematics_Class::Arc_Cosine(double Number)
{
    return acos(Number);
}

inline double Xila_Class::Mathematics_Class::Arc_Tangent(double Number)
{
    return atan(Number);
}

inline double Xila_Class::Mathematics_Class::Arc_Secant(double Number)
{
    return Arc_Cosine(1 / Number);
}

inline double Xila_Class::Mathematics_Class::Arc_Cosecant(double Number)
{
    return Arc_Sine(1 / Number);
}

inline double Xila_Class::Mathematics_Class::Arc_Cotangent(double Number)
{
    return (Pi / 2) - Arc_Tangent(Number);
}

inline double Xila_Class::Mathematics_Class::Hyperbolic_Sine(double Number)
{
    return sinh(Number);
}

inline double Xila_Class::Mathematics_Class::Hyperbolic_Cosine(double Number)
{
    return cosh(Number);
}

inline double Xila_Class::Mathematics_Class::Hyperbolic_Tangent(double Number)
{
    return tanh(Number);
}

inline double Xila_Class::Mathematics_Class::Hyperbolic_Secant(double Number)
{
    return 1 / Hyperbolic_Cosine(Number);
}

inline double Xila_Class::Mathematics_Class::Hyperbolic_Cosecant(double Number)
{
    if (Number == 0)
    {
        return nan("");
    }
    return 1 / Hyperbolic_Sine(Number);
}

inline double Xila_Class::Mathematics_Class::Hyperbolic_Cotangent(double Number)
{
    if (Number == 0)
    {
        return nan("");
    }
    return Hyperbolic_Cosine(Number) / Hyperbolic_Sine(Number);
}

inline double Xila_Class::Mathematics_Class::Arc_Hyperbolic_Sine(double Number)
{
    return asinh(Number);
}

inline double Xila_Class::Mathematics_Class::Arc_Hyperbolic_Cosine(double Number)
{
    return acosh(Number);
}

inline double Xila_Class::Mathematics_Class::Arc_Hyperbolic_Tangent(double Number)
{
    return atanh(Number);
}

inline double Xila_Class::Mathematics_Class::Arc_Hyperbolic_Secant(double Number)
{
    return 1 / Hyperbolic_Secant(Number);
}

inline double Xila_Class::Mathematics_Class::Arc_Hyperbolic_Cosecant(double Number)
{
    return 1 / Hyperbolic_Cosecant(Number);
}

inline double Xila_Class::Mathematics_Class::Arc_Hyperbolic_Cotangent(double Number)
{
    return 1 / Hyperbolic_Cotangent(Number);
}

inline double Xila_Class::Mathematics_Class::Absolute(double Number)
{
    return abs(Number);
}

inline double Xila_Class::Mathematics_Class::Power(double Base, double Exponent)
{
    return pow(Base, Exponent);
}

inline double Xila_Class::Mathematics_Class::Square(double Number)
{
    return Number * Number;
}

inline double Xila_Class::Mathematics_Class::Cube(double Number)
{
    return Number * Number * Number;
}

inline double Xila_Class::Mathematics_Class::Root(double Base, double Exponent)
{
    return Power(Base, 1 / Exponent);
}

inline double Xila_Class::Mathematics_Class::Square_Root(double Number)
{
    return sqrt(Number);
}

inline double Xila_Class::Mathematics_Class::Cubic_Root(double Number)
{
    return cbrt(Number);
}

inline double Xila_Class::Mathematics_Class::Exponential(double Number)
{
    return exp(Number);
}

inline double Xila_Class::Mathematics_Class::Logarithm(double Base, double Number)
{
    return Natural_Logarithm(Number) / Natural_Logarithm(Base);
}

inline double Xila_Class::Mathematics_Class::Binary_Logarithm(double Number)
{
    return log2(Number);
}

inline double Xila_Class::Mathematics_Class::Natural_Logarithm(double Number)
{
    return log(Number);
}

inline double Xila_Class::Mathematics_Class::Decimal_Logarithm(double Number)
{
    return log10(Number);
}

inline double Xila_Class::Mathematics_Class::Inverse(double Number)
{
    return 1 / Number;
}


#endif