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

#include "../Module/Module.hpp"
#include "Hash.hpp"
#include "Rational.hpp"

namespace Xila_Namespace
{
    namespace Mathematics_Types
    {


    };

    typedef class Mathematics_Class : Module_Class
    {
    public:

        /// @brief Pi constant.
        static const Mathematics_Types::Rational_Type Pi;

        /// @brief Euler constant.
        static const Mathematics_Types::Rational_Type Euler;

        // -- Methods -- //
        double String_To_Float(const char *String); // --
        char *Float_To_String(double Number, int8_t Width, uint8_t Precision, char *String);

        bool Is_NAN(double Number);
        bool Is_Infinite(double Number);

        double Copy_Sign(double Number_1, double Number_2);
        double Floor(double Number);
        double Modulo(double Number_1, double Number_2);

        Mathematics_Types::Rational_Type Radians(Mathematics_Types::Rational_Type Degrees);
        Mathematics_Types::Rational_Type Degrees(Mathematics_Types::Rational_Type Radians);

        Mathematics_Types::Rational_Type Combination(double n, double k);
        Mathematics_Types::Rational_Type Permutation(double n, double k);

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


        uint32_t Random();
        uint32_t Random(uint32_t Upper_Bound);
        uint32_t Random(uint32_t Low_Bound, uint32_t Upper_Bound);

    } Mathematics_Type;

    extern Mathematics_Type Mathematics;
}

#endif