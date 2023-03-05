///
/// @file ESP32.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 05-03-2023
///
/// @copyright Copyright (c) 2023
///

#ifdef Xila_Pin_Hardware_ESP32

#include "Core/Pin/Pin.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Pin_Types;

///
/// @brief Set voltage reference pin for for ADC measurements.
///
/// @param Pin Involved GPIO.
void Xila_Namespace::Pin_Class::Set_Voltage_Reference_Pin(uint8_t Pin)
{
    analogSetVRefPin(Pin);
}

#endif