 /// @file Pin.cpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 23-05-2023
 /// 
 /// @copyright Copyright (c) 2021

#include "Pin/Pin.hpp"
#include "Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Pin_Types;

Pin_Type Xila_Namespace::Pin;

void Pin_Class::Set_Mode(uint8_t Pin, Mode_Type Mode)
{
    pinMode(Pin, (uint8_t)Mode);
}

Result_Type Pin_Class::Valid_Output_Pin(uint8_t Pin)
{
    return (Result_Type)digitalPinCanOutput(Pin);
}

void Pin_Class::Digital_Write(uint8_t Pin, Digital_State_Type State)
{
    switch (State)
    {
    case Digital_State_Type::Low:
        digitalWrite(Pin, LOW);
        break;
    case Digital_State_Type::High:
        digitalWrite(Pin, HIGH);
        break;
    }
}

Digital_State_Type Pin_Class::Digital_Read(uint8_t Pin)
{
    if (digitalRead(Pin) == LOW)
    {
        return Digital_State_Type::Low;
    }
    return Digital_State_Type::High;
}

Result_Type Pin_Class::Valid_Digital_Pin(uint8_t Pin)
{
    return (Result_Type)digitalPinIsValid(Pin);
}

uint32_t Pin_Class::Get_Pulse_In(uint8_t Pin, Digital_State_Type State, uint32_t Timeout)
{
    auto Pulse = pulseIn(Pin, (uint8_t)State, Timeout);
    return Pulse;
}

uint16_t Pin_Class::Analog_Read(uint8_t Pin)
{
    return analogRead(Pin);
}

uint32_t Pin_Class::Analog_Read_Milli_Volts(uint8_t Pin)
{
    return analogReadMilliVolts(Pin);
}

void Pin_Class::Set_Attenuation(uint8_t Pin, uint8_t Attenuation)
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

void Pin_Class::Set_Attenuation(uint8_t Attenuation)
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

void Pin_Class::Set_Clock_Divider(uint8_t Clock_Divider)
{
    analogSetClockDiv(Clock_Divider);
}

void Pin_Class::Set_Width(uint8_t Bits_Width)
{
    // analogSetWidth(Bits_Width);
}

void Pin_Class::Set_Read_Resolutions(uint8_t Bits_Resolution)
{
    analogReadResolution(Bits_Resolution);
}

uint8_t Convert_Mode_Type(Interrupt_Mode_Type Mode)
{
    switch (Mode)
    {
    case Interrupt_Mode_Type::Rising:
        return RISING;
        break;
    case Interrupt_Mode_Type::Falling:
        return FALLING;
        break;
    case Interrupt_Mode_Type::Change:
        return CHANGE;
        break;
    case Interrupt_Mode_Type::On_Low:
        return ONLOW;
        break;
    case Interrupt_Mode_Type::On_High:
        return ONHIGH;
        break;
    case Interrupt_Mode_Type::On_Low_WE:
        return ONLOW_WE;
        break;
    case Interrupt_Mode_Type::On_High_WE:
        return ONHIGH_WE;
        break;
    default:
        return DISABLED;
        break;
    }
}

void Pin_Class::Attach_Interrupt(uint8_t Pin, void (*Function_Pointer)(void), Interrupt_Mode_Type Mode)
{
    attachInterrupt(Pin, Function_Pointer, Convert_Mode_Type(Mode));
}

void Pin_Class::Attach_Interrupt(uint8_t Pin, void (*Function_Pointer)(void *), void *Argument, Interrupt_Mode_Type Mode)
{
    attachInterruptArg(Pin, Function_Pointer, Argument, Convert_Mode_Type(Mode));
}

void Pin_Class::Detach_Interrupt(uint8_t Pin)
{
    detachInterrupt(Pin);
}
