#include "Core/Core.hpp"

double Xila_Class::Mathematics_Class::String_To_Float(const char *String)
{
    return atof(String);
}

char *Xila_Class::Mathematics_Class::Float_To_String(double Number, int8_t Width, uint8_t Precision, char *String)
{
    dtostrf(Number, Width, Precision, String);
    // -- Delete unwanted zeros
    for (uint8_t i = sizeof(String) - 1; i > 0; i--)
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

double Xila_Class::Mathematics_Class::Greatest_Common_Divisor(double Number_1, double Number_2)
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

double Xila_Class::Mathematics_Class::Least_Common_Multiple(double Number_1, double Number_2)
{
    return ((Number_1 * Number_2) / Greatest_Common_Divisor(Number_1, Number_2));
}

double Xila_Class::Mathematics_Class::Factorial(double Number)
{
    for (uint8_t i = Number - 1; i > 0; i--)
    {
        Number *= i;
    }
    return Number;
}

double Xila_Class::Mathematics_Class::Combination(double n, double k)
{
    return Factorial(n) / (Factorial(n - k) * Factorial(k));
}

double Xila_Class::Mathematics_Class::Permutation(double n, double k)
{
    return Factorial(n) / Factorial(n - k);
}

