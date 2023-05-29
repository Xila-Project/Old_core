/// @file  Rational_Number.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 02-04-2023
///
/// @copyright Copyright (c) 2023

#include "Mathematics/Rational.hpp"

#include <cmath>

using namespace Xila_Namespace;
using namespace Xila_Namespace::Mathematics_Types;

// - Methods

// - - Constructor

Rational_Class::Rational_Class() : Numerator(0), Denominator(1)
{

}

Rational_Class::Rational_Class(Long_Real_Type Value)
{
    {
        Long_Real_Type Integer_Part;
        Long_Real_Type Fractional_Part = std::modf(Value, &Integer_Part);
        if (Fractional_Part == 0.0)
        {
            Numerator = Integer_Part;
            Denominator = 1;
            return;
        }
    }

    // - Convert d to scientific nonation : d = m * 10^e
    Long_Integer_Type e = std::floor(std::log10(std::fabs(Value))) + 1;
    Long_Real_Type m = Value * std::pow(10, -e);

    // - Approximate m with a rational number
    Rational_Type Temporary(std::round(m * 100000), 100000);    // ? : Arbitrary precision ?

    // - Reduce the fraction
    Temporary = Temporary.Simplify();

    // - Multiply by 10^e to get the final result
    Numerator = Temporary.Numerator * std::pow(10, e);
    Denominator = Temporary.Denominator;
}

Rational_Class::Rational_Class(Long_Integer_Type Numerator, Long_Integer_Type Denominator)
    : Numerator(Numerator), Denominator(Denominator)
{}

Rational_Class::Rational_Class(Rational_Class Numerator, Rational_Class Denominator)
{
    this->Numerator = Numerator.Get_Numerator() * Denominator.Get_Denominator();
    this->Denominator = Numerator.Get_Denominator() * Denominator.Get_Numerator();
}

// - - Getters

Long_Integer_Type Rational_Class::Get_Numerator() const
{
    return Numerator;
}

Long_Integer_Type Rational_Class::Get_Denominator() const
{
    return Denominator;
}

// - - Manipulation

Rational_Class Rational_Class::Absolute_Value() const
{
    return Rational_Class(std::abs(Numerator), std::abs(Denominator));
}

Rational_Class Rational_Class::Simplify() const
{
    Long_Integer_Type Temporary = Greatest_Common_Divisor();
    return Rational_Class(Numerator / Temporary, Denominator / Temporary);
}

Long_Integer_Type Rational_Class::Greatest_Common_Divisor() const
{
    Long_Integer_Type Temporary_Numerator = Get_Numerator();
    Long_Integer_Type Temporary_Denominator = Get_Denominator();

    while (Temporary_Denominator != 0)
    {
        Long_Integer_Type Temporary = Temporary_Denominator;
        Temporary_Denominator = Temporary_Numerator % Temporary_Denominator;
        Temporary_Numerator = Temporary;
    }
    return Temporary_Numerator;
}

Long_Integer_Type Rational_Class::Least_Common_Multiple() const
{
    return (Numerator * Denominator) / Greatest_Common_Divisor();
}

// - - - Factors

Rational_Class Rational_Class::Factorial() const
{
    Rational_Class Temporary(1, 1);
    for (Long_Integer_Type i = 1; i <= Numerator; i++)
    {
        Temporary *= i;
    }
    return Temporary;
}

Rational_Class Rational_Class::Inverse() const
{
    return Rational_Class(Denominator, Numerator);
}

Rational_Class Rational_Class::Power(Long_Integer_Type Exponent) const
{
    return Rational_Class(std::pow(Numerator, Exponent), std::pow(Denominator, Exponent));
}

Rational_Class Rational_Class::Square() const
{
    return Rational_Class(std::pow(Numerator, 2), std::pow(Denominator, 2));
}

Rational_Class Rational_Class::Cube() const
{
    return Rational_Class(std::pow(Numerator, 3), std::pow(Denominator, 3));
}

Rational_Class Rational_Class::Root(Long_Integer_Type Exponent) const
{
    return Rational_Class(std::pow(Numerator, 1 / Exponent), std::pow(Denominator, 1 / Exponent));
}

Rational_Class Rational_Class::Square_Root() const
{
    return Rational_Class(std::sqrt(Numerator), std::sqrt(Denominator));
}

Rational_Class Rational_Class::Cube_Root() const
{
    return Rational_Class(std::cbrt(Numerator), std::cbrt(Denominator));
}

// - - - Logarithms / Exponential

Rational_Class Rational_Class::Logarithm(Long_Integer_Type Base) const
{
    return Rational_Class(std::log(Numerator) / std::log(Base), std::log(Denominator) / std::log(Base));    // ! : Precision
}

Rational_Class Rational_Class::Natural_Logarithm() const
{
    return Rational_Class(std::log(Numerator), std::log(Denominator));
}

Rational_Class Rational_Class::Decimal_Logarithm() const
{
    return Rational_Class(std::log10(Numerator), std::log10(Denominator));
}

Rational_Class Rational_Class::Binary_Logarithm() const
{
    return Rational_Class(std::log2(Numerator), std::log2(Denominator));
}

Rational_Class Rational_Class::Exponential() const
{
    return Rational_Class(std::exp(Numerator), std::exp(Denominator));
}

// - - - Trigonometry

// - - - - Sine

Rational_Class Rational_Class::Sine() const
{
    return Rational_Class(std::sin(Numerator), std::sin(Denominator));
}

Rational_Class Rational_Class::Arc_Sine() const
{
    return Rational_Class(std::asin(Numerator), std::asin(Denominator));
}

Rational_Class Rational_Class::Hyperbolic_Sine() const
{
    return Rational_Class(std::sinh(Numerator), std::sinh(Denominator));
}

Rational_Class Rational_Class::Hyperbolic_Arc_Sine() const
{
    return Rational_Class(std::asinh(Numerator), std::asinh(Denominator));
}

// - - - - Cosine

Rational_Class Rational_Class::Cosine() const
{
    return Rational_Class(std::cos(Numerator), std::cos(Denominator));
}

Rational_Class Rational_Class::Arc_Cosine() const
{
    return Rational_Class(std::acos(Numerator), std::acos(Denominator));
}

Rational_Class Rational_Class::Hyperbolic_Cosine() const
{
    return Rational_Class(std::cosh(Numerator), std::cosh(Denominator));
}

Rational_Class Rational_Class::Hyperbolic_Arc_Cosine() const
{
    return Rational_Class(std::acosh(Numerator), std::acosh(Denominator));
}

// - - - - Tangent

Rational_Class Rational_Class::Tangent() const
{
    return Rational_Class(std::tan(Numerator), std::tan(Denominator));
}

Rational_Class Rational_Class::Arc_Tangent() const
{
    return Rational_Class(std::atan(Numerator), std::atan(Denominator));
}

Rational_Class Rational_Class::Hyperbolic_Tangent() const
{
    return Rational_Class(std::tanh(Numerator), std::tanh(Denominator));
}

Rational_Class Rational_Class::Hyperbolic_Arc_Tangent() const
{
    return Rational_Class(std::atanh(Numerator), std::atanh(Denominator));
}

// - - Operators

// - - - Arithmetic

Rational_Class &Rational_Class::operator+=(const Long_Real_Type &Other)
{
    return operator+=(Rational_Class(Other));
}

Rational_Class &Rational_Class::operator+=(const Rational_Class &Other)
{
    Numerator = Numerator * Other.Denominator + Other.Numerator * Denominator;
    Denominator *= Other.Denominator;
    return *this;
}

Rational_Class &Rational_Class::operator-=(const Long_Real_Type &Other)
{
    return operator-=(Rational_Class(Other));
}

Rational_Class &Rational_Class::operator-=(const Rational_Class &Other)
{
    Numerator = Numerator * Other.Denominator - Other.Numerator * Denominator;
    Denominator *= Other.Denominator;
    return *this;
}

Rational_Class &Rational_Class::operator*=(const Long_Real_Type &Other)
{
    return operator*=(Rational_Class(Other));
}

Rational_Class &Rational_Class::operator*=(const Rational_Class &Other)
{
    Numerator *= Other.Numerator;
    Denominator *= Other.Denominator;
    return *this;
}

Rational_Class &Rational_Class::operator/=(const Long_Real_Type &Other)
{
    return operator/=(Rational_Class(Other));
}

Rational_Class &Rational_Class::operator/=(const Rational_Class &Other)
{
    Numerator *= Other.Denominator;
    Denominator *= Other.Numerator;
    return *this;
}


Rational_Class Rational_Class::operator+(const Long_Real_Type &Other) const
{
    return operator+(Rational_Class(Other));
}

Rational_Class Rational_Class::operator+(const Rational_Class &Other) const
{
    Long_Integer_Type Result_Numerator = Numerator * Other.Denominator + Other.Numerator * Denominator;
    Long_Integer_Type Result_Denominator = Denominator * Other.Denominator;
    return Rational_Class(Result_Numerator, Result_Denominator);
}


Rational_Class Rational_Class::operator-(const Long_Real_Type &Other) const
{
    return operator-(Rational_Class(Other));
}

Rational_Class Rational_Class::operator-(const Rational_Class &Other) const
{
    Long_Integer_Type Result_Numerator = Numerator * Other.Denominator - Other.Numerator * Denominator;
    Long_Integer_Type Result_Denominator = Denominator * Other.Denominator;
    return Rational_Class(Result_Numerator, Result_Denominator);
}

Rational_Class Rational_Class::operator*(const Long_Real_Type &Other) const
{
    return operator*(Rational_Class(Other));
}

Rational_Class Rational_Class::operator*(const Rational_Class &Other) const
{
    Long_Integer_Type Result_Numerator = Numerator * Other.Numerator;
    Long_Integer_Type Result_Denominator = Denominator * Other.Denominator;
    return Rational_Class(Result_Numerator, Result_Denominator);
}

Rational_Class Rational_Class::operator/(const Long_Real_Type &Other) const
{
    return operator/(Rational_Class(Other));
}

Rational_Class Rational_Class::operator/(const Rational_Class &Other) const
{
    Long_Integer_Type Result_Numerator = Numerator * Other.Denominator;
    Long_Integer_Type Result_Denominator = Denominator * Other.Numerator;
    return Rational_Class(Result_Numerator, Result_Denominator);
}

// - - - Comparison

bool Rational_Class::operator==(const Long_Integer_Type &Other) const
{
    return (Numerator == Other) && (Denominator == 1);
}

bool Rational_Class::operator==(const Rational_Class &Other) const
{
    return (Numerator == Other.Numerator) && (Denominator == Other.Denominator);
}

bool Rational_Class::operator!=(const Long_Integer_Type &Other) const
{
    return (Numerator != Other) || (Denominator != 1);
}

bool Rational_Class::operator!=(const Rational_Class &Other) const
{
    return (Numerator != Other.Numerator) || (Denominator != Other.Denominator);
}

bool Rational_Class::operator<(const Long_Integer_Type &Other) const
{
    return (Numerator < Other * Denominator);
}

bool Rational_Class::operator<(const Rational_Class &Other) const
{
    return (Numerator * Other.Denominator) < (Other.Numerator * Denominator);
}

bool Rational_Class::operator<=(const Long_Integer_Type &Other) const
{
    return (Numerator <= Other * Denominator);
}

bool Rational_Class::operator<=(const Rational_Class &Other) const
{
    return (Numerator * Other.Denominator) <= (Other.Numerator * Denominator);
}

bool Rational_Class::operator>(const Long_Integer_Type &Other) const
{
    return (Numerator > Other * Denominator);
}

bool Rational_Class::operator>(const Rational_Class &Other) const
{
    return (Numerator * Other.Denominator) > (Other.Numerator * Denominator);
}

bool Rational_Class::operator>=(const Long_Integer_Type &Other) const
{
    return (Numerator >= Other * Denominator);
}

bool Rational_Class::operator>=(const Rational_Class &Other) const
{
    return (Numerator * Other.Denominator) >= (Other.Numerator * Denominator);
}

// - - - Casting

Rational_Class::operator Long_Real_Type() const
{
    return static_cast<Real_Type>(Numerator) / Denominator;
}
