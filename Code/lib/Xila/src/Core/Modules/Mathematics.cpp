#include "Core/Core.hpp"

char *Xila_Class::Mathematics_Class::Float_To_String(double Number, int8_t Width, uint8_t Precision, char *String)
{
    dtostrf(Number, Width, Precision, String);
    uint8_t i;
    // -- Delete unwanted zeros
    for (i = sizeof(String) - 1; i > 0; i--)
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