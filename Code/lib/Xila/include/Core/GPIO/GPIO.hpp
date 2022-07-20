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

///
 /// @brief Set GPIO mode.
 /// 
 /// @param Pin Involved GPIO.
 /// @param Mode Mode.
inline void Xila_Class::GPIO_Class::Set_Mode(uint8_t Pin, uint8_t Mode)
{
    pinMode(Pin, Mode);
}

///
 /// @brief Check if a GPIO is valid for output purpose.
 /// 
 /// @param Pin Involved GPIO.
 /// @return Result_Type 
inline Result_Type Xila_Class::GPIO_Class::Valid_Output_Pin(uint8_t Pin)
{
    if (digitalPinCanOutput(Pin) == true)
    {
        return Success;
    }

    return Error;
}

///
 /// @brief Set GPIO digital state.
 /// 
 /// @param Pin Involved GPIO.
 /// @param State GPIO state to set.
inline void Xila_Class::GPIO_Class::Digital_Write(uint8_t Pin, uint8_t State)
{
    digitalWrite(Pin, State);
}

///
 /// @brief Read GPIO digital state.
 /// 
 /// @param Pin Involved GPIO.
 /// @return int16_t GPIO state.
inline int16_t Xila_Class::GPIO_Class::Digital_Read(uint8_t Pin)
{
    return digitalRead(Pin);
}

///
 /// @brief Check if a GPIO pin is suitable for digital signals.
 /// 
 /// @param Pin Involved GPIO.
 /// @return Result_Type 
inline Result_Type Xila_Class::GPIO_Class::Valid_Digital_Pin(uint8_t Pin)
{
    if (digitalPinIsValid(Pin))
    {
        return Success;
    }
    return Error;
}

///
 /// @brief Read GPIO voltage value.
 /// 
 /// @param Pin Involved GPIO.
 /// @return uint16_t GPIO voltage value (between 0 and 4095).
inline uint16_t Xila_Class::GPIO_Class::Analog_Read(uint8_t Pin)
{
    return analogRead(Pin);
}

///
 /// @brief Read GPIO voltage.
 /// 
 /// @param Pin Involved GPIO.
 /// @return uint32_t GPIO voltage value in millivolts.
inline uint32_t Xila_Class::GPIO_Class::Analog_Read_Milli_Volts(uint8_t Pin)
{
    return analogReadMilliVolts(Pin);
}

///
 /// @brief Set voltage reference pin for for ADC measurements.
 /// 
 /// @param Pin Involved GPIO.
inline void Xila_Class::GPIO_Class::Set_Voltage_Reference_Pin(uint8_t Pin)
{
    analogSetVRefPin(Pin);
}

///
 /// @brief Set GPIO attenuation for ADC measurements.
 /// 
 /// @param Pin Involved GPIO.
 /// @param Attenuation Attenuation.
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

///
 /// @brief Set GPIOs attenuation for ADC measurements.
 /// 
 /// @param Attenuation Attenuation.
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

///
 /// @brief Set clock divider.
 /// 
 /// @param Clock_Divider Clock divider.
inline void Xila_Class::GPIO_Class::Set_Clock_Divider(uint8_t Clock_Divider)
{
    analogSetClockDiv(Clock_Divider);
}

///
 /// @brief Set bit width of ADC measurements.
 /// 
 /// @param Bits_Width Bit width.
inline void Xila_Class::GPIO_Class::Set_Width(uint8_t Bits_Width)
{
    analogSetWidth(Bits_Width);
}

///
 /// @brief Set read resolution of ADC measurements.
 /// 
 /// @param Bits_Resolution Bit resolution.
inline void Xila_Class::GPIO_Class::Set_Read_Resolutions(uint8_t Bits_Resolution)
{
    analogReadResolution(Bits_Resolution);
}

///
 /// @brief Set an interrupt.
 /// 
 /// @param Pin Involved GPIO.
 /// @param[in] Function_Pointer Function pointer.
 /// @param Mode Interrupt mode.
inline void Xila_Class::GPIO_Class::Attach_Interrupt(uint8_t Pin, void (*Function_Pointer)(void), int16_t Mode)
{
    attachInterrupt(Pin, Function_Pointer, Mode);
}

///
 /// @brief Set an interrupt with an argument passed to the hadling function.
 /// 
 /// @param Pin Involved GPIO.
 /// @param Function_Pointer Function pointer.
 /// @param Argument Argument passed to the function.
 /// @param Mode Interrupt mode.
inline void Xila_Class::GPIO_Class::Attach_Interrupt_Argument(uint8_t Pin, void (*Function_Pointer)(void*), void *Argument, int16_t Mode)
{
    attachInterruptArg(Pin, Function_Pointer, Argument, Mode);
}

///
 /// @brief Detach interrupt from a GPIO.
 /// 
 /// @param Pin Involved GPIO.
inline void Xila_Class::GPIO_Class::Detach_Interrupt(uint8_t Pin)
{
    detachInterrupt(Pin);
}

#endif