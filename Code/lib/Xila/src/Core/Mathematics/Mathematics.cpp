/// @file Mathematics.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief File to declare mathematics methods.
/// @version 0.2
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021

#include "Core/Mathematics/Mathematics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Mathematics_Types;

Mathematics_Type Xila_Namespace::Mathematics;

// - Attributes

const Mathematics_Types::Rational_Type Mathematics_Class::Pi(355, 113);
const Mathematics_Types::Rational_Type Mathematics_Class::Euler(2718281828459045, 1000000000000000);

bool Xila_Namespace::Mathematics_Class::Is_NAN(double Number)
{
    return isnan(Number);
}

bool Xila_Namespace::Mathematics_Class::Is_Infinite(double Number)
{
    return isinf(Number);
}

double Xila_Namespace::Mathematics_Class::Copy_Sign(double Number_1, double Number_2)
{
    return copysign(Number_1, Number_2);
}

double Xila_Namespace::Mathematics_Class::Floor(double Number)
{
    return floor(Number);
}

double Xila_Namespace::Mathematics_Class::Modulo(double Number_1, double Number_2)
{
    return fmod(Number_1, Number_2);
}

Rational_Type Xila_Namespace::Mathematics_Class::Radians(Rational_Type Degrees)
{
    using namespace Xila_Namespace::Mathematics_Types;
    return Rational_Type(Pi, Rational_Type(360)) * Degrees;
}

Rational_Type Xila_Namespace::Mathematics_Class::Degrees(Rational_Type Radians)
{
    using namespace Xila_Namespace::Mathematics_Types;
    return Radians * Rational_Type(Rational_Type(360), Pi);
}

double Xila_Namespace::Mathematics_Class::Sine(double Number)
{
    return sin(Number);
}

double Xila_Namespace::Mathematics_Class::Cosine(double Number)
{
    return cos(Number);
}

double Xila_Namespace::Mathematics_Class::Tangent(double Number)
{
    return tan(Number);
}

double Xila_Namespace::Mathematics_Class::Secant(double Number)
{
    return 1 / Cosine(Number);
}

double Xila_Namespace::Mathematics_Class::Cosecant(double Number)
{
    return 1 / Sine(Number);
}

double Xila_Namespace::Mathematics_Class::Cotangent(double Number)
{
    return 1 / Tangent(Number);
}

double Xila_Namespace::Mathematics_Class::Arc_Sine(double Number)
{
    return asin(Number);
}

double Xila_Namespace::Mathematics_Class::Arc_Cosine(double Number)
{
    return acos(Number);
}

double Xila_Namespace::Mathematics_Class::Arc_Tangent(double Number)
{
    return atan(Number);
}

double Xila_Namespace::Mathematics_Class::Arc_Secant(double Number)
{
    return Arc_Cosine(1 / Number);
}

double Xila_Namespace::Mathematics_Class::Arc_Cosecant(double Number)
{
    return Arc_Sine(1 / Number);
}

double Xila_Namespace::Mathematics_Class::Arc_Cotangent(double Number)
{
    return static_cast<Long_Real_Type>((Pi / 2) - Arc_Tangent(Number));
}

double Xila_Namespace::Mathematics_Class::Hyperbolic_Sine(double Number)
{
    return sinh(Number);
}

double Xila_Namespace::Mathematics_Class::Hyperbolic_Cosine(double Number)
{
    return cosh(Number);
}

double Xila_Namespace::Mathematics_Class::Hyperbolic_Tangent(double Number)
{
    return tanh(Number);
}

double Xila_Namespace::Mathematics_Class::Hyperbolic_Secant(double Number)
{
    return 1 / Hyperbolic_Cosine(Number);
}

double Xila_Namespace::Mathematics_Class::Hyperbolic_Cosecant(double Number)
{
    if (Number == 0)
    {
        return nan("");
    }
    return 1 / Hyperbolic_Sine(Number);
}

double Xila_Namespace::Mathematics_Class::Hyperbolic_Cotangent(double Number)
{
    if (Number == 0)
    {
        return nan("");
    }
    return Hyperbolic_Cosine(Number) / Hyperbolic_Sine(Number);
}

double Xila_Namespace::Mathematics_Class::Arc_Hyperbolic_Sine(double Number)
{
    return asinh(Number);
}

double Xila_Namespace::Mathematics_Class::Arc_Hyperbolic_Cosine(double Number)
{
    return acosh(Number);
}

double Xila_Namespace::Mathematics_Class::Arc_Hyperbolic_Tangent(double Number)
{
    return atanh(Number);
}

double Xila_Namespace::Mathematics_Class::Arc_Hyperbolic_Secant(double Number)
{
    return 1 / Hyperbolic_Secant(Number);
}

double Xila_Namespace::Mathematics_Class::Arc_Hyperbolic_Cosecant(double Number)
{
    return 1 / Hyperbolic_Cosecant(Number);
}

double Xila_Namespace::Mathematics_Class::Arc_Hyperbolic_Cotangent(double Number)
{
    return 1 / Hyperbolic_Cotangent(Number);
}

uint32_t Xila_Namespace::Mathematics_Class::Random()
{
    return esp_random();
}

uint32_t Xila_Namespace::Mathematics_Class::Random(uint32_t Upper_Bound)
{
    uint32_t x = esp_random();
    uint64_t m = uint64_t(x) * uint64_t(Upper_Bound);
    uint32_t l = uint32_t(m);
    if (l < Upper_Bound)
    {
        uint32_t t = -Upper_Bound;
        if (t >= Upper_Bound)
        {
            t -= Upper_Bound;
            if (t >= Upper_Bound)
                t %= Upper_Bound;
        }
        while (l < t)
        {
            x = esp_random();
            m = uint64_t(x) * uint64_t(Upper_Bound);
            l = uint32_t(m);
        }
    }
    return m >> 32;
}

uint32_t Xila_Namespace::Mathematics_Class::Random(uint32_t Lower_Bound, uint32_t Upper_Bound)
{
    if (Lower_Bound >= Upper_Bound)
    {
        return Lower_Bound;
    }
    long diff = Upper_Bound - Lower_Bound;
    return Random(diff) + Lower_Bound;
}

double Xila_Namespace::Mathematics_Class::String_To_Float(const char *String)
{
    return atof(String);
}

char *Xila_Namespace::Mathematics_Class::Real_To_String(double Number, int8_t Width, uint8_t Precision, char *String)
{
    dtostrf(Number, Width, Precision, String);
    // -- Delete unwanted zeros
    for (uint8_t i = strlen(String) - 1; i > 0; i--)
    {
        if (String[i] == '0' || String[i] == '\0')
        {
            String[i] = '\0';
        }
        else
        {
            if (String[i] == '.')
            {
                String[i] = '\0';
            }
            break;
        }
    }
    return String;
}

Rational_Type Xila_Namespace::Mathematics_Class::Combination(double n, double k)
{
    return Rational_Type(n).Factorial() / Rational_Type(n - k).Factorial() * Rational_Type(k).Factorial();
}

Rational_Type Xila_Namespace::Mathematics_Class::Permutation(double n, double k)
{
    return Rational_Type(n).Factorial() / Rational_Type(n - k).Factorial();
}
