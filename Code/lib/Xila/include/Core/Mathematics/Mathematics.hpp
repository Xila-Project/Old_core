///
/// @file Mathematics.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

#ifndef MATHEMATICS_HPP_INCLUDED
#define MATHEMATICS_HPP_INCLUDED

#include "Arduino.h"
#include "../Module.hpp"

class Mathematics_Class : Module_Class
{
public:
    ///
    /// @brief Archimedes constant.
    ///
    const double Pi = 3.1415926535897932384626433832795;

    ///
    /// @brief Euler constant.
    ///
    const double Euler = 2.718281828459045235360287471352;

    ///
    static /// @brief Degrees to radian coefficient.
    static ///
    static const double Degrees_To_Radians = 0.017453292519943295769236907684886;
 
    static ///
    static /// @brief Radian to degrees coefficient.
    static ///
    static const double Radians_To_Degrees = 57.295779513082320876798154814105;
 
    static // -- Methods -- //
    static double String_To_Float(const char *String); // --
    static char *Float_To_String(double Number, int8_t Width, uint8_t Precision, char *String);
 
    static bool Is_NAN(double Number);
    static bool Is_Infinite(double Number);
 
    static double Copy_Sign(double Number_1, double Number_2);
    static double Floor(double Number);
    static double Modulo(double Number_1, double Number_2);
    static double Greatest_Common_Divisor(double Number_1, double Number_2);
    static double Least_Common_Multiple(double Number_1, double Number_2);
 
    static double Radians(double Degrees);
    static double Degrees(double Radians);
 
    static double Factorial(double Number);
    static double Absolute(double Number);
    static double Inverse(double Number);
 
    static double Combination(double n, double k);
    static double Permutation(double n, double k);
 
    static double Sine(double Number);
    static double Cosine(double Number);
    static double Tangent(double Number);
    static double Secant(double Number);
    static double Cosecant(double Number);
    static double Cotangent(double Number);
 
    static double Arc_Sine(double Number);
    static double Arc_Cosine(double Number);
    static double Arc_Tangent(double Number);
    static double Arc_Secant(double Number);
    static double Arc_Cosecant(double Number);
    static double Arc_Cotangent(double Number);
 
    static double Hyperbolic_Sine(double Number);
    static double Hyperbolic_Cosine(double Number);
    static double Hyperbolic_Tangent(double Number);
    static double Hyperbolic_Secant(double Number);
    static double Hyperbolic_Cosecant(double Number);
    static double Hyperbolic_Cotangent(double Number);
 
    static double Arc_Hyperbolic_Sine(double Number);
    static double Arc_Hyperbolic_Cosine(double Number);
    static double Arc_Hyperbolic_Tangent(double Number);
    static double Arc_Hyperbolic_Secant(double Number);
    static double Arc_Hyperbolic_Cosecant(double Number);
    static double Arc_Hyperbolic_Cotangent(double Number);
 
    static double Power(double Base, double Exponent);
    static double Square(double Number);
    static double Cube(double Number);
 
    static double Root(double Base, double Exponent);
    static double Square_Root(double Number);
    static double Cubic_Root(double Number);
 
    static double Exponential(double Number);
 
    static double Logarithm(double Base, double Number);
    static double Binary_Logarithm(double Number);
    static double Natural_Logarithm(double Number);
    static double Decimal_Logarithm(double Number);
 
    static uint32_t Random() const;
    static uint32_t Random(uint32_t Upper_Bound) const;
    static uint32_t Random(uint32_t Low_Bound, uint32_t Upper_Bound) const;

} Mathematics;

#endif