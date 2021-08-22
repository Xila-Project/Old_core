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

///
 /// @brief Convert angle from degrees to radians.
 /// 
 /// @param Degrees Angle to convert in degrees.
 /// @return double Converted angle in radians.
inline double Xila_Class::Mathematics_Class::Radians(double Degrees)
{
    return Degrees * Degrees_To_Radians;
}

///
 /// @brief Convert angle from radians to degrees.
 /// 
 /// @param Radians Angle to convert in radians.
 /// @return double Converted angle in degrees.
inline double Xila_Class::Mathematics_Class::Degrees(double Radians)
{
    return Radians * Radians_To_Degrees;
}

///
 /// @brief Calculate the sine of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Sine of the number.
inline double Xila_Class::Mathematics_Class::Sine(double Number)
{
    return sin(Number);
}

///
 /// @brief Calculate the consine of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Cosine of the number.
inline double Xila_Class::Mathematics_Class::Cosine(double Number)
{
    return cos(Number);
}

///
 /// @brief Calculate the tangent of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Tangent of the number.
inline double Xila_Class::Mathematics_Class::Tangent(double Number)
{
    return tan(Number);
}

///
 /// @brief Calculate the secant of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Secant of the number.
inline double Xila_Class::Mathematics_Class::Secant(double Number)
{
    return 1 / Cosine(Number);
}

///
 /// @brief Calculate the cosecant of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Cosecant of the number.
inline double Xila_Class::Mathematics_Class::Cosecant(double Number)
{
    return 1 / Sine(Number);
}

///
 /// @brief Calculate the cotangeant of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Cotangent of the number.
inline double Xila_Class::Mathematics_Class::Cotangeant(double Number)
{
    return 1 / Tangent(Number);
}

///
 /// @brief Calculate the arc sine of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Arc sine of the number.
inline double Xila_Class::Mathematics_Class::Arc_Sine(double Number)
{
    return asin(Number);
}

///
 /// @brief Calculate the arc cosine of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Arc cosine of the number.
inline double Xila_Class::Mathematics_Class::Arc_Cosine(double Number)
{
    return acos(Number);
}

///
 /// @brief Calculate the arc tangent of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Arc tangent of the number.
inline double Xila_Class::Mathematics_Class::Arc_Tangent(double Number)
{
    return atan(Number);
}

///
 /// @brief Calculate the arc secant of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Arc secant of the number.
inline double Xila_Class::Mathematics_Class::Arc_Secant(double Number)
{
    return Arc_Cosine(1 / Number);
}

///
 /// @brief Calculate the arc cosecant of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Arc cosecant of the number.
inline double Xila_Class::Mathematics_Class::Arc_Cosecant(double Number)
{
    return Arc_Sine(1 / Number);
}

///
 /// @brief Calculate the arc cotangent of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Arc cotangent of the number.
inline double Xila_Class::Mathematics_Class::Arc_Cotangent(double Number)
{
    return (Pi / 2) - Arc_Tangent(Number);
}

///
 /// @brief Calculate the hyperbolic sine of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Hyperbolic sine of the number.
inline double Xila_Class::Mathematics_Class::Hyperbolic_Sine(double Number)
{
    return sinh(Number);
}

///
 /// @brief Calculate the tangent of a number in radians.
 /// 
 /// @param Number Number to calculate in radians.
 /// @return double Tangent of the number.
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

///
 /// @brief Calculates the power of a number.
 /// 
 /// @param Base Base number.
 /// @param Exponent Exponent to apply.
 /// @return double Power of the number.
inline double Xila_Class::Mathematics_Class::Power(double Base, double Exponent)
{
    return pow(Base, Exponent);
}

///
 /// @brief Calculate the square of a number.
 /// 
 /// @param Number Number to calculate.
 /// @return double Square of the number.
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