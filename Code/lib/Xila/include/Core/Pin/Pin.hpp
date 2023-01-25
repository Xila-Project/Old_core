///
/// @file Pin.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 05-04-2021
///
/// @copyright Copyright (c) 2021
///

#ifndef Pin_Hpp_Included
#define Pin_Hpp_Included

#include "Arduino.h"
#include "../Module/Module.hpp"

//==============================================================================//
///
/// @brief Pin management class
///

namespace Xila_Namespace
{
    class Pin_Class : public Module_Class
    {
    public:
        // TODO : Transform into a full Object Oriented Object.

        Pin_Class();

        // -- Pin mode
        void Set_Mode(uint8_t Pin, uint8_t Mode);

        Result_Type Valid_Output_Pin(uint8_t Pin);

        // -- Digital
        void Digital_Write(uint8_t Pin, uint8_t State);
        int16_t Digital_Read(uint8_t Pin);

        Result_Type Valid_Digital_Pin(uint8_t Pin);

        // -- Analog
        uint16_t Analog_Read(uint8_t Pin);
        uint32_t Analog_Read_Milli_Volts(uint8_t Pin);

        void Set_Voltage_Reference_Pin(uint8_t Pin);
        void Set_Read_Resolutions(uint8_t Bits_Resolution);
        void Set_Width(uint8_t Bits_Width);
        void Set_Clock_Divider(uint8_t Clock_Divider);

        void Set_Attenuation(uint8_t Attenuation);
        void Set_Attenuation(uint8_t Pin, uint8_t Attenuation);

        // -- Interrupts
        void Attach_Interrupt(uint8_t Pin, void (*Function_Pointer)(void), int16_t Mode);
        void Attach_Interrupt_Argument(uint8_t Pin, void (*Function_Pointer)(void *), void *Argument, int16_t Mode);
        void Detach_Interrupt(uint8_t Pin);

        ///
        /// @brief Digital IOs states.
        ///
        enum Digital_States : uint8_t
        {
            Low = LOW,   ///< Low state.
            High = HIGH, ///< High state.

        };

        ///
        /// @brief IOs modes.
        ///
        enum Modes : uint8_t
        {
            Input = 0x01,             ///< Input
            Output = 0x02,            ///< Output
            Pull_Up = 0x04,           ///< Pull up resistor.
            Input_Pull_Up = 0x05,     ///< Input with a pull up resistor.
            Pull_Down = 0x08,         ///< Pull down resistor.
            Input_Pull_Down = 0x09,   ///< Input with a pull down resistor.
            Open_Drain = 0x10,        ///< Open drain (nothing connected).
            Output_Open_Drain = 0x12, ///< Output with open drain by default.
            Special = 0xF0,           ///< Special
            Function_1 = 0x00,        ///< Function 1
            Function_2 = 0x20,        ///< Function 2
            Function_3 = 0x40,        ///< Function 3
            Function_4 = 0x60,        ///< Function 4
            Function_5 = 0x80,        ///< Function 5
            Function_6 = 0xA0,        ///< Function 6
            Analog = 0xC0             ///< Analog
        };

        ///
        /// @brief Interrupt modes.
        ///
        enum Interrupt_Modes : uint8_t
        {
            Disabled = 0x00,  ///< No interrupt.
            Rising = 0x01,    ///< Triggered when signal rise.
            Falling = 0x02,   ///< Triggered when signal fall.
            Change = 0x03,    ///< Triggered when signal fall or rise.
            On_Low = 0x04,    ///< Triggered on low state.
            On_High = 0x05,   ///< Triggered on high state.
            On_Low_WE = 0x0C, ///< Triggered on low state.
            On_High_WE = 0x0D ///< Triggered on high state.
        };

    } Pin;

}

#endif