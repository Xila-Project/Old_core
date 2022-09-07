///
/// @file Mathematics.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief File to declare mathmetics methods.
/// @version 0.2
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"

///
/// @brief Check if a float is a number.
///
/// @param Number
/// @return true
/// @return false
bool Mathematics_Class::Is_NAN(double Number)
{
    return isnan(Number);
}

///
/// @brief Check if a number is infinite.
///
/// @param Number
/// @return true
/// @return false
bool Mathematics_Class::Is_Infinite(double Number)
{
    return isinf(Number);
}

///
/// @brief Copy sign from a number to another.
///
/// @param Number_1 Origin number.
/// @param Number_2 Destination number.
/// @return double New number sign
double Mathematics_Class::Copy_Sign(double Number_1, double Number_2)
{
    return copysign(Number_1, Number_2);
}

double Mathematics_Class::Floor(double Number)
{
    return floor(Number);
}

double Mathematics_Class::Modulo(double Number_1, double Number_2)
{
    return fmod(Number_1, Number_2);
}

///
/// @brief Convert angle from degrees to radians.
///
/// @param Degrees Angle to convert in degrees.
/// @return double Converted angle in radians.
double Mathematics_Class::Radians(double Degrees)
{
    return Degrees * Degrees_To_Radians;
}

///
/// @brief Convert angle from radians to degrees.
///
/// @param Radians Angle to convert in radians.
/// @return double Converted angle in degrees.
double Mathematics_Class::Degrees(double Radians)
{
    return Radians * Radians_To_Degrees;
}

///
/// @brief Calculate the sine of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Sine of the number.
double Mathematics_Class::Sine(double Number)
{
    return sin(Number);
}

///
/// @brief Calculate the consine of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Cosine of the number.
double Mathematics_Class::Cosine(double Number)
{
    return cos(Number);
}

///
/// @brief Calculate the tangent of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Tangent of the number.
double Mathematics_Class::Tangent(double Number)
{
    return tan(Number);
}

///
/// @brief Calculate the secant of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Secant of the number.
double Mathematics_Class::Secant(double Number)
{
    return 1 / Cosine(Number);
}

///
/// @brief Calculate the cosecant of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Cosecant of the number.
double Mathematics_Class::Cosecant(double Number)
{
    return 1 / Sine(Number);
}

///
/// @brief Calculate the cotangent of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Cotangent of the number.
double Mathematics_Class::Cotangent(double Number)
{
    return 1 / Tangent(Number);
}

///
/// @brief Calculate the arc sine of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Arc sine of the number.
double Mathematics_Class::Arc_Sine(double Number)
{
    return asin(Number);
}

///
/// @brief Calculate the arc cosine of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Arc cosine of the number.
double Mathematics_Class::Arc_Cosine(double Number)
{
    return acos(Number);
}

///
/// @brief Calculate the arc tangent of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Arc tangent of the number.
double Mathematics_Class::Arc_Tangent(double Number)
{
    return atan(Number);
}

///
/// @brief Calculate the arc secant of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Arc secant of the number.
double Mathematics_Class::Arc_Secant(double Number)
{
    return Arc_Cosine(1 / Number);
}

///
/// @brief Calculate the arc cosecant of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Arc cosecant of the number.
double Mathematics_Class::Arc_Cosecant(double Number)
{
    return Arc_Sine(1 / Number);
}

///
/// @brief Calculate the arc cotangent of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Arc cotangent of the number.
double Mathematics_Class::Arc_Cotangent(double Number)
{
    return (Pi / 2) - Arc_Tangent(Number);
}

///
/// @brief Calculate the hyperbolic sine of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Hyperbolic sine of the number.
double Mathematics_Class::Hyperbolic_Sine(double Number)
{
    return sinh(Number);
}

///
/// @brief Calculate the tangent of a number in radians.
///
/// @param Number Number to calculate in radians.
/// @return double Tangent of the number.
double Mathematics_Class::Hyperbolic_Cosine(double Number)
{
    return cosh(Number);
}

double Mathematics_Class::Hyperbolic_Tangent(double Number)
{
    return tanh(Number);
}

double Mathematics_Class::Hyperbolic_Secant(double Number)
{
    return 1 / Hyperbolic_Cosine(Number);
}

double Mathematics_Class::Hyperbolic_Cosecant(double Number)
{
    if (Number == 0)
    {
        return nan("");
    }
    return 1 / Hyperbolic_Sine(Number);
}

double Mathematics_Class::Hyperbolic_Cotangent(double Number)
{
    if (Number == 0)
    {
        return nan("");
    }
    return Hyperbolic_Cosine(Number) / Hyperbolic_Sine(Number);
}

double Mathematics_Class::Arc_Hyperbolic_Sine(double Number)
{
    return asinh(Number);
}

double Mathematics_Class::Arc_Hyperbolic_Cosine(double Number)
{
    return acosh(Number);
}

double Mathematics_Class::Arc_Hyperbolic_Tangent(double Number)
{
    return atanh(Number);
}

double Mathematics_Class::Arc_Hyperbolic_Secant(double Number)
{
    return 1 / Hyperbolic_Secant(Number);
}

double Mathematics_Class::Arc_Hyperbolic_Cosecant(double Number)
{
    return 1 / Hyperbolic_Cosecant(Number);
}

double Mathematics_Class::Arc_Hyperbolic_Cotangent(double Number)
{
    return 1 / Hyperbolic_Cotangent(Number);
}

double Mathematics_Class::Absolute(double Number)
{
    return abs(Number);
}

///
/// @brief Calculates the power of a number.
///
/// @param Base Base number.
/// @param Exponent Exponent to apply.
/// @return double Power of the number.
double Mathematics_Class::Power(double Base, double Exponent)
{
    return pow(Base, Exponent);
}

///
/// @brief Calculate the square of a number.
///
/// @param Number Number to calculate.
/// @return double Square of the number.
double Mathematics_Class::Square(double Number)
{
    return Number * Number;
}

double Mathematics_Class::Cube(double Number)
{
    return Number * Number * Number;
}

double Mathematics_Class::Root(double Base, double Exponent)
{
    return Power(Base, 1 / Exponent);
}

double Mathematics_Class::Square_Root(double Number)
{
    return sqrt(Number);
}

double Mathematics_Class::Cubic_Root(double Number)
{
    return cbrt(Number);
}

double Mathematics_Class::Exponential(double Number)
{
    return exp(Number);
}

double Mathematics_Class::Logarithm(double Base, double Number)
{
    return Natural_Logarithm(Number) / Natural_Logarithm(Base);
}

double Mathematics_Class::Binary_Logarithm(double Number)
{
    return log2(Number);
}

double Mathematics_Class::Natural_Logarithm(double Number)
{
    return log(Number);
}

double Mathematics_Class::Decimal_Logarithm(double Number)
{
    return log10(Number);
}

double Mathematics_Class::Inverse(double Number)
{
    return 1 / Number;
}

uint32_t Mathematics_Class::Random()
{
    return esp_random();
}

uint32_t Mathematics_Class::Random(uint32_t Upper_Bound)
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

uint32_t Mathematics_Class::Random(uint32_t Lower_Bound, uint32_t Upper_Bound)
{
    if (Lower_Bound >= Upper_Bound)
    {
        return Lower_Bound;
    }
    long diff = Upper_Bound - Lower_Bound;
    return Random(diff) + Lower_Bound;
}

///
/// @brief Convert string to a float number.
///
/// @param String String to convert.
/// @return double Converted number.
double Mathematics_Class::String_To_Float(const char *String)
{
    return atof(String);
}

///
/// @brief Convert a float number into string.
///
/// @param Number Number to convert.
/// @param Width String buffer size.
/// @param Precision Float point precision.
/// @param String String buffer.
/// @return char* String buffer pointer.
char *Mathematics_Class::Float_To_String(double Number, int8_t Width, uint8_t Precision, char *String)
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

///
/// @brief Calculate the greated common divisor of two number.
///
/// @param Number_1
/// @param Number_2
/// @return double Greatest common divisor.
double Mathematics_Class::Greatest_Common_Divisor(double Number_1, double Number_2)
{
    if (Number_1 == 0 || Number_2 == 0)
    {
        return 0;
    }
    else if (Number_1 == Number_2)
    {
        return Number_1;
    }
    else if (Number_1 > Number_2)
    {
        return Greatest_Common_Divisor(Number_1 - Number_2, Number_2);
    }
    else
    {
        return Greatest_Common_Divisor(Number_1, Number_2 - Number_1);
    }
}

///
/// @brief Calculate the least common multiple of two number.
///
/// @param Number_1
/// @param Number_2
/// @return double Least common divisor.
double Mathematics_Class::Least_Common_Multiple(double Number_1, double Number_2)
{
    return ((Number_1 * Number_2) / Greatest_Common_Divisor(Number_1, Number_2));
}

///
/// @brief Calculate the factorial of a number.
///
/// @param Number Number to calculte the factorial from.
/// @return double Factorial.
double Mathematics_Class::Factorial(double Number)
{
    for (uint8_t i = Number - 1; i > 0; i--)
    {
        Number *= i;
    }
    return Number;
}

double Mathematics_Class::Combination(double n, double k)
{
    return Factorial(n) / (Factorial(n - k) * Factorial(k));
}

double Mathematics_Class::Permutation(double n, double k)
{
    return Factorial(n) / Factorial(n - k);
}
