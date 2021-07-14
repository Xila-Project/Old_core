///
/// @file GPIO.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 05-04-2021
///
/// @copyright Copyright (c) 2021
///

#include "Arduino.h"

#ifndef GPIO_HPP_INCLUDED
#define GPIO_HPP_INCLUDED

inline void Xila_Class::GPIO_Class::Set_Mode(uint8_t Pin, uint8_t Mode)
{
    pinMode(Pin, Mode);
}

inline Xila_Class::Event Xila_Class::GPIO_Class::Valid_Output_Pin(uint8_t Pin)
{
    if (digitalPinCanOutput(Pin) == true)
    {
        return Success;
    }

    return Error;
}

inline void Xila_Class::GPIO_Class::Digital_Write(uint8_t Pin, uint8_t State)
{
    digitalWrite(Pin, State);
}

inline int16_t Xila_Class::GPIO_Class::Digital_Read(uint8_t Pin)
{
    return digitalRead(Pin);
}

inline Xila_Class::Event Xila_Class::GPIO_Class::Valid_Digital_Pin(uint8_t Pin)
{
    if (digitalPinIsValid(Pin))
    {
        return Success;
    }
    return Error;
}

inline uint16_t Xila_Class::GPIO_Class::Analog_Read(uint8_t Pin)
{
    return analogRead(Pin);
}

inline uint32_t Xila_Class::GPIO_Class::Analog_Read_Milli_Volts(uint8_t Pin)
{
    return analogReadMilliVolts(Pin);
}

inline void Xila_Class::GPIO_Class::Set_Voltage_Reference_Pin(uint8_t Pin)
{
    analogSetVRefPin(Pin);
}

inline void Xila_Class::GPIO_Class::Set_Attenuation(uint8_t Pin, uint8_t Attenuation)
{
    switch (Attenuation)
    {
    case ADC_0db:
        analogSetPinAttenuation(Pin, ADC_0db);
        break;
    case ADC_2_5db:
        analogSetPinAttenuation(Pin, ADC_2_5db);
        break;
    case ADC_6db:
        analogSetPinAttenuation(Pin, ADC_6db);
        break;
    case ADC_11db:
        analogSetPinAttenuation(Pin, ADC_11db);
        break;
    default:
        break;
    }
}

inline void Xila_Class::GPIO_Class::Set_Attenuation(uint8_t Attenuation)
{
    switch (Attenuation)
    {
    case ADC_0db:
        analogSetAttenuation(ADC_0db);
        break;
    case ADC_2_5db:
        analogSetAttenuation(ADC_2_5db);
        break;
    case ADC_6db:
        analogSetAttenuation(ADC_6db);
        break;
    case ADC_11db:
        analogSetAttenuation(ADC_11db);
        break;
    default:
        break;
    }
}

inline void Xila_Class::GPIO_Class::Set_Clock_Divider(uint8_t Clock_Divider)
{
    analogSetClockDiv(Clock_Divider);
}

inline void Xila_Class::GPIO_Class::Set_Width(uint8_t Bits_Width)
{
    analogSetWidth(Bits_Width);
}

inline void Xila_Class::GPIO_Class::Set_Read_Resolutions(uint8_t Bits_Resolution)
{
    analogReadResolution(Bits_Resolution);
}

inline void Xila_Class::GPIO_Class::Attach_Interrupt(uint8_t Pin, void (*Function_Pointer)(void), int16_t Mode)
{
    attachInterrupt(Pin, Function_Pointer, Mode);
}

inline void Xila_Class::GPIO_Class::Attach_Interrupt_Argument(uint8_t Pin, void (*Function_Pointer)(void*), void *Argument, int16_t Mode)
{
    attachInterruptArg(Pin, Function_Pointer, Argument, Mode);
}

inline void Xila_Class::GPIO_Class::Detech_Interrupt(uint8_t Pin)
{
    detachInterrupt(Pin);
}

#endif