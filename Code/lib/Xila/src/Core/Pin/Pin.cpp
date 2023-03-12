///
/// @file GPIO.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief GPIO maangement source file
/// @version 0.1
/// @date 05-04-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Pin/Pin.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Pin_Types;

Pin_Type Xila_Namespace::Pin;

///
/// @brief Set GPIO mode.
///
/// @param Pin Involved GPIO.
/// @param Mode Mode.
void Xila_Namespace::Pin_Class::Set_Mode(uint8_t Pin, Mode_Type Mode)
{
    switch (Mode)
    {
    case Mode_Type::Input:
        pinMode(Pin, INPUT);
        break;
    case Mode_Type::Output:
        pinMode(Pin, OUTPUT);
        break;  
    case Mode_Type::Pull_Up:
        pinMode(Pin, PULLUP);
        break;
    case Mode_Type::Input_Pull_Up:
        pinMode(Pin, INPUT_PULLUP);
        break;
    case Mode_Type::Pull_Down:
        pinMode(Pin, PULLDOWN);
        break;
    case Mode_Type::Input_Pull_Down:
        pinMode(Pin, INPUT_PULLDOWN);
        break;
    case Mode_Type::Open_Drain:
        pinMode(Pin, OPEN_DRAIN);
        break;
    case Mode_Type::Output_Open_Drain:
        pinMode(Pin, OUTPUT_OPEN_DRAIN);
        break;
    case Mode_Type::Analog:
        pinMode(Pin, ANALOG);
        break;
    }
}

///
/// @brief Check if a GPIO is valid for output purpose.
///
/// @param Pin Involved GPIO.
/// @return Result_Type
Result_Type Xila_Namespace::Pin_Class::Valid_Output_Pin(uint8_t Pin)
{
    if (digitalPinCanOutput(Pin) == true)
    {
        return Result_Type::Success;
    }

    return Result_Type::Error;
}

///
/// @brief Set GPIO digital state.
///
/// @param Pin Involved GPIO.
/// @param State GPIO state to set.
void Xila_Namespace::Pin_Class::Digital_Write(uint8_t Pin, Digital_State_Type State)
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

/// @brief Read GPIO digital state.
///
/// @param Pin Involved GPIO.
/// @return Digital_State_Type GPIO state.
Digital_State_Type Xila_Namespace::Pin_Class::Digital_Read(uint8_t Pin)
{
    if (digitalRead(Pin) == LOW)
    {
        return Digital_State_Type::Low;
    }
    return Digital_State_Type::High;
}

///
/// @brief Check if a GPIO pin is suitable for digital signals.
///
/// @param Pin Involved GPIO.
/// @return Result_Type
Result_Type Xila_Namespace::Pin_Class::Valid_Digital_Pin(uint8_t Pin)
{
    if (digitalPinIsValid(Pin))
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

///
/// @brief Read GPIO voltage value.
///
/// @param Pin Involved GPIO.
/// @return uint16_t GPIO voltage value (between 0 and 4095).
uint16_t Xila_Namespace::Pin_Class::Analog_Read(uint8_t Pin)
{
    return analogRead(Pin);
}

///
/// @brief Read GPIO voltage.
///
/// @param Pin Involved GPIO.
/// @return uint32_t GPIO voltage value in millivolts.
uint32_t Xila_Namespace::Pin_Class::Analog_Read_Milli_Volts(uint8_t Pin)
{
    return analogReadMilliVolts(Pin);
}

///
/// @brief Set GPIO attenuation for ADC measurements.
///
/// @param Pin Involved GPIO.
/// @param Attenuation Attenuation.
void Xila_Namespace::Pin_Class::Set_Attenuation(uint8_t Pin, uint8_t Attenuation)
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

///
/// @brief Set GPIOs attenuation for ADC measurements.
///
/// @param Attenuation Attenuation.
void Xila_Namespace::Pin_Class::Set_Attenuation(uint8_t Attenuation)
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

///
/// @brief Set clock divider.
///
/// @param Clock_Divider Clock divider.
void Xila_Namespace::Pin_Class::Set_Clock_Divider(uint8_t Clock_Divider)
{
    analogSetClockDiv(Clock_Divider);
}

///
/// @brief Set bit width of ADC measurements.
///
/// @param Bits_Width Bit width.
void Xila_Namespace::Pin_Class::Set_Width(uint8_t Bits_Width)
{
    //analogSetWidth(Bits_Width);
}

///
/// @brief Set read resolution of ADC measurements.
///
/// @param Bits_Resolution Bit resolution.
void Xila_Namespace::Pin_Class::Set_Read_Resolutions(uint8_t Bits_Resolution)
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

///
/// @brief Set an interrupt.
///
/// @param Pin Involved GPIO.
/// @param[in] Function_Pointer Function pointer.
/// @param Mode Interrupt mode.
void Xila_Namespace::Pin_Class::Attach_Interrupt(uint8_t Pin, void (*Function_Pointer)(void), Interrupt_Mode_Type Mode)
{
    attachInterrupt(Pin, Function_Pointer, Convert_Mode_Type(Mode));
}

///
/// @brief Set an interrupt with an argument passed to the hadling function.
///
/// @param Pin Involved GPIO.
/// @param Function_Pointer Function pointer.
/// @param Argument Argument passed to the function.
/// @param Mode Interrupt mode.
void Xila_Namespace::Pin_Class::Attach_Interrupt(uint8_t Pin, void (*Function_Pointer)(void *), void *Argument, Interrupt_Mode_Type Mode)
{
    attachInterruptArg(Pin, Function_Pointer, Argument, Convert_Mode_Type(Mode));
}

///
/// @brief Detach interrupt from a GPIO.
///
/// @param Pin Involved GPIO.
void Xila_Namespace::Pin_Class::Detach_Interrupt(uint8_t Pin)
{
    detachInterrupt(Pin);
}
