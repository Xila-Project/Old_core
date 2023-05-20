/// @file Rational_Number.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 02-04-2023
///
/// @copyright Copyright (c) 2023

#ifndef Rational_Number_Hpp
#define Rational_Number_Hpp

#include "Module/Base_Types.hpp"

namespace Xila_Namespace
{
    namespace Mathematics_Types
    {
        typedef class Rational_Class
        {
        public:
            // - Methods

            // - - Constructor

            /// @brief Construct a new Rational_Class object.
            /// @param Numerator
            /// @param Denominator
            Rational_Class(Long_Integer_Type, Long_Integer_Type);
            
            /// @brief Construct a new Rational_Class object from rational numerator and denominator.
            /// @param Numerator
            /// @param Denominator
            Rational_Class(Rational_Class, Rational_Class);
            
            /// @brief Construct a new Rational_Class object from a real number.
            /// @param Real
            Rational_Class(Long_Real_Type);

            // - - Getters
            /// @brief Get the Numerator object.
            Long_Integer_Type Get_Numerator() const;
            /// @brief Get the Denominator object.
            Long_Integer_Type Get_Denominator() const;

            // - - Manipulation

            /// @brief Get the absolute value of the rational number.
            /// @return Rational_Class result.
            Rational_Class Absolute_Value() const;

            /// @brief Get the reciprocal of the rational number.
            /// @return Rational_Class result.
            Rational_Class Simplify() const;

            // - - - Congruence

            /// @brief Check if the rational number is congruent to another.
            /// @param Rational_Number
            Long_Integer_Type Greatest_Common_Divisor() const;

            /// @brief Check if the rational number is congruent to another.
            /// @param Rational_Number
            Long_Integer_Type Least_Common_Multiple() const;

            // - - - Factors

            /// @brief Get the factorial of the rational number.
            /// @return Rational_Class result.
            Rational_Class Factorial() const;

            /// @brief Get the inverse of the rational number.
            /// @return Rational_Class result.
            Rational_Class Inverse() const;

            // - - -  Power / root

            Rational_Class Power(Long_Integer_Type Exponent) const;
            Rational_Class Square() const;
            Rational_Class Cube() const;

            Rational_Class Root(Long_Integer_Type Exponent) const;
            Rational_Class Cube_Root() const;
            Rational_Class Square_Root() const;

            // - - - Logarithms / exponents
            Rational_Class Logarithm(Long_Integer_Type Base) const;
            Rational_Class Decimal_Logarithm() const;
            Rational_Class Binary_Logarithm() const;
            Rational_Class Natural_Logarithm() const;

            Rational_Class Exponential() const;
            // - - - Trigonometry

            // - - - - Sine
            Rational_Class Sine() const;
            Rational_Class Arc_Sine() const;
            Rational_Class Hyperbolic_Sine() const;
            Rational_Class Hyperbolic_Arc_Sine() const;

            // - - - - Cosine
            Rational_Class Cosine() const;
            Rational_Class Arc_Cosine() const;
            Rational_Class Hyperbolic_Cosine() const;
            Rational_Class Hyperbolic_Arc_Cosine() const;

            // - - - - Tangent
            Rational_Class Tangent() const;
            Rational_Class Arc_Tangent() const;
            Rational_Class Hyperbolic_Tangent() const;
            Rational_Class Hyperbolic_Arc_Tangent() const;


            // - - Operators

            // - - - Arithmetic
            Rational_Class &operator+=(const Long_Real_Type &other);
            Rational_Class &operator+=(const Rational_Class &other);

            Rational_Class &operator-=(const Long_Real_Type &other);
            Rational_Class &operator-=(const Rational_Class &other);

            Rational_Class &operator*=(const Long_Real_Type &other);
            Rational_Class &operator*=(const Rational_Class &other);
            
            Rational_Class &operator/=(const Long_Real_Type &other);
            Rational_Class &operator/=(const Rational_Class &other);
    

            Rational_Class operator+(const Long_Real_Type &other) const;
            Rational_Class operator+(const Rational_Class &other) const;

            Rational_Class operator-(const Long_Real_Type &other) const;
            Rational_Class operator-(const Rational_Class &other) const;

            Rational_Class operator*(const Long_Real_Type &other) const;
            Rational_Class operator*(const Rational_Class &other) const;

            Rational_Class operator/(const Long_Real_Type &other) const;
            Rational_Class operator/(const Rational_Class &other) const;

            // - - - Comparison
            bool operator==(const Long_Integer_Type &other) const;
            bool operator==(const Rational_Class &other) const;
            bool operator!=(const Long_Integer_Type &other) const;
            bool operator!=(const Rational_Class &other) const;
            bool operator<(const Long_Integer_Type &other) const;
            bool operator<(const Rational_Class &other) const;
            bool operator<=(const Long_Integer_Type &other) const;
            bool operator<=(const Rational_Class &other) const;
            bool operator>(const Long_Integer_Type &other) const;
            bool operator>(const Rational_Class &other) const;
            bool operator>=(const Long_Integer_Type &other) const;
            bool operator>=(const Rational_Class &other) const;

            // - - - Casting
            explicit operator Long_Real_Type() const;

        private:
            // - Attributes
            Long_Integer_Type Numerator;
            Long_Integer_Type Denominator;
        } Rational_Type;

    };
};

#endif // Rational_Number_Hpp