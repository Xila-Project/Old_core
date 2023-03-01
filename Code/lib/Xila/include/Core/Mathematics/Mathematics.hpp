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
#include "../Module/Module.hpp"
#include "Hash.hpp"

namespace Xila_Namespace
{
    namespace Mathematics_Types
    {

    };

    typedef class Mathematics_Class : Module_Class
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
        /// @brief Degrees to radian coefficient.
        ///
        const double Degrees_To_Radians = 0.017453292519943295769236907684886;

        ///
        /// @brief Radian to degrees coefficient.
        ///
        const double Radians_To_Degrees = 57.295779513082320876798154814105;

        // -- Methods -- //
        double String_To_Float(const char *String); // --
        char *Float_To_String(double Number, int8_t Width, uint8_t Precision, char *String);

        bool Is_NAN(double Number);
        bool Is_Infinite(double Number);

        double Copy_Sign(double Number_1, double Number_2);
        double Floor(double Number);
        double Modulo(double Number_1, double Number_2);
        double Greatest_Common_Divisor(double Number_1, double Number_2);
        double Least_Common_Multiple(double Number_1, double Number_2);

        double Radians(double Degrees);
        double Degrees(double Radians);

        double Factorial(double Number);
        double Absolute(double Number);
        double Inverse(double Number);

        double Combination(double n, double k);
        double Permutation(double n, double k);

        double Sine(double Number);
        double Cosine(double Number);
        double Tangent(double Number);
        double Secant(double Number);
        double Cosecant(double Number);
        double Cotangent(double Number);

        double Arc_Sine(double Number);
        double Arc_Cosine(double Number);
        double Arc_Tangent(double Number);
        double Arc_Secant(double Number);
        double Arc_Cosecant(double Number);
        double Arc_Cotangent(double Number);

        double Hyperbolic_Sine(double Number);
        double Hyperbolic_Cosine(double Number);
        double Hyperbolic_Tangent(double Number);
        double Hyperbolic_Secant(double Number);
        double Hyperbolic_Cosecant(double Number);
        double Hyperbolic_Cotangent(double Number);

        double Arc_Hyperbolic_Sine(double Number);
        double Arc_Hyperbolic_Cosine(double Number);
        double Arc_Hyperbolic_Tangent(double Number);
        double Arc_Hyperbolic_Secant(double Number);
        double Arc_Hyperbolic_Cosecant(double Number);
        double Arc_Hyperbolic_Cotangent(double Number);

        double Power(double Base, double Exponent);
        double Square(double Number);
        double Cube(double Number);

        double Root(double Base, double Exponent);
        double Square_Root(double Number);
        double Cubic_Root(double Number);

        double Exponential(double Number);

        double Logarithm(double Base, double Number);
        double Binary_Logarithm(double Number);
        double Natural_Logarithm(double Number);
        double Decimal_Logarithm(double Number);

        uint32_t Random();
        uint32_t Random(uint32_t Upper_Bound);
        uint32_t Random(uint32_t Low_Bound, uint32_t Upper_Bound);

    } Mathematics_Type;

    extern Mathematics_Type Mathematics;
}

#endif