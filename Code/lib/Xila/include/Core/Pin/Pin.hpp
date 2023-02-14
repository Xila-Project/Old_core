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
    namespace Pin_Types
    {
        /// @brief Digital IOs states.
        enum class Digital_State_Type
        {
            Low,   ///< Low state.
            High, ///< High state.

        };

        /// @brief IOs modes.
        enum class Mode_Type
        {
            Input,              ///< Input
            Output,             ///< Output
            Pull_Up,            ///< Pull up resistor.
            Input_Pull_Up,      ///< Input with a pull up resistor.
            Pull_Down,          ///< Pull down resistor.
            Input_Pull_Down,    ///< Input with a pull down resistor.
            Open_Drain,         ///< Open drain (nothing connected).
            Output_Open_Drain,  ///< Output with open drain by default.
            Analog              ///< Analog
        };

        /// @brief Interrupt modes.
        enum class Interrupt_Mode_Type
        {
            Disabled,  ///< No interrupt.
            Rising,    ///< Triggered when signal rise.
            Falling,   ///< Triggered when signal fall.
            Change,    ///< Triggered when signal fall or rise.
            On_Low,    ///< Triggered on low state.
            On_High,   ///< Triggered on high state.
            On_Low_WE, ///< Triggered on low state.
            On_High_WE ///< Triggered on high state.
        };

    };

    class Pin_Class : public Module_Class
    {
    public:
        // TODO : Transform into a full Object Oriented Object.

        Pin_Class();

        // -- Pin mode
        void Set_Mode(uint8_t Pin, Pin_Types::Mode_Type Mode);

        Result_Type Valid_Output_Pin(uint8_t Pin);

        // -- Digital
        void Digital_Write(uint8_t Pin, Pin_Types::Digital_State_Type State);
        Pin_Types::Digital_State_Type Digital_Read(uint8_t Pin);

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
        void Attach_Interrupt(uint8_t Pin, void (*Function_Pointer)(void), Pin_Types::Interrupt_Mode_Type Mode);
        void Attach_Interrupt(uint8_t Pin, void (*Function_Pointer)(void *), void *Argument, Pin_Types::Interrupt_Mode_Type Mode);
        void Detach_Interrupt(uint8_t Pin);
    
    private:
    } Pin;

}

#endif