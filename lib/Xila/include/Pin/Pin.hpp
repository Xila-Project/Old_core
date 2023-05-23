/// @file Pin.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 05-04-2021
///
/// @copyright Copyright (c) 2021


#ifndef Pin_Hpp_Included
#define Pin_Hpp_Included

#include "../Module/Module.hpp"
#include "Serial.hpp"
#include "Two_Wire_Interface.hpp"


namespace Xila_Namespace
{
    namespace Pin_Types
    {
        /// @brief Digital IOs states.
        enum class Digital_State_Type : Byte_Type
        {
            Low = LOW,   ///< Low state.
            High = HIGH ///< High state.

        };

        /// @brief IOs modes.
        enum class Mode_Type : Byte_Type
        {
            Input = INPUT,              ///< Input
            Output = OUTPUT,      ///< Output
            Pull_Up = PULLUP,            ///< Pull up resistor.
            Input_Pull_Up = INPUT_PULLUP,    ///< Input with a pull up resistor.
            Pull_Down = PULLDOWN,          ///< Pull down resistor.
            Input_Pull_Down = INPUT_PULLDOWN,    ///< Input with a pull down resistor.
            Open_Drain = OPEN_DRAIN,         ///< Open drain (nothing connected).
            Output_Open_Drain = OUTPUT_OPEN_DRAIN,  ///< Output with open drain by default.
            Analog = ANALOG,             ///< Analog
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

    /// @brief Pin module class
    typedef class Pin_Class : public Module_Class
    {
    public:
        // - Methods

        // TODO : Transform into a full Object Oriented Object.

        // - - Pin mode

        /// @brief Set pin mode.
        /// @param Pin Pin to set.
        /// @param Mode Mode to set.
        void Set_Mode(uint8_t Pin, Pin_Types::Mode_Type Mode);

        /// @brief Check if a pin is valid for output purpose.
        /// @param Pin Pin to check.
        /// @return `Result_Type::Success` if the pin is valid, `Result_Type::Error` otherwise.
        Result_Type Valid_Output_Pin(uint8_t Pin);

        // -- Digital

        /// @brief Set a digital state to a pin.
        /// @param Pin Pin to set.
        /// @param State State to set.
        void Digital_Write(uint8_t Pin, Pin_Types::Digital_State_Type State);

        /// @brief Read the digital state from a pin.
        /// @param Pin Pin to read.
        /// @return Pin state.
        Pin_Types::Digital_State_Type Digital_Read(uint8_t Pin);

        /// @brief Check if a pin is valid for digital purpose.
        /// @param Pin Pin to check.
        /// @return `Result_Type::Success` if the pin is valid, `Result_Type::Error` otherwise.
        Result_Type Valid_Digital_Pin(uint8_t Pin);

        /// @brief Get the pulse in time.
        /// @param Pin Pin to read.
        /// @param State State to wait for.
        /// @param Timeout Time to wait for the pulse in milliseconds.
        /// @return Pulse in time in microseconds.
        uint32_t Get_Pulse_In(uint8_t Pin, Pin_Types::Digital_State_Type State, uint32_t Timeout = 1000000);

        // - - Analog

        /// @brief Set a analog value to a pin.
        /// @param Pin Pin to set.
        /// @param Value Value to set.
        uint16_t Analog_Read(uint8_t Pin);

        /// @brief Read the analog value from a pin.
        /// @param Pin Pin to read.
        /// @return Pin value.
        uint32_t Analog_Read_Milli_Volts(uint8_t Pin);
        

        /// @brief Set the voltage reference pin.
        /// @param Pin Pin to set.
        void Set_Voltage_Reference_Pin(uint8_t Pin);

        /// @brief Set the read resolution.
        /// @param Bits_Resolution Bits resolution to set.
        void Set_Read_Resolutions(uint8_t Bits_Resolution);

        /// @brief
        /// @param Bits_Width
        void Set_Width(uint8_t Bits_Width);

        /// @brief Set the clock divider.
        /// @param Clock_Divider Clock divider to set. 
        void Set_Clock_Divider(uint8_t Clock_Divider);

        /// @brief Set the attenuation of all pins.
        /// @param Attenuation Attenuation to set.
        void Set_Attenuation(uint8_t Attenuation);

        /// @brief Set the attenuation of a pin.
        /// @param Pin Pin to set.
        void Set_Attenuation(uint8_t Pin, uint8_t Attenuation);

        // - - Interrupts

        /// @brief Attach an interrupt to a pin.
        /// @param Pin Pin to attach.
        /// @param Function_Pointer Function to call when the interrupt is triggered.
        /// @param Mode Interrupt mode.
        void Attach_Interrupt(uint8_t Pin, void (*Function_Pointer)(void), Pin_Types::Interrupt_Mode_Type Mode);

        /// @brief Attach an interrupt to a pin.
        /// @param Pin Pin to attach.
        /// @param Function_Pointer Function to call when the interrupt is triggered.
        /// @param Argument Argument to pass to the function.  
        /// @param Mode Interrupt mode.
        void Attach_Interrupt(uint8_t Pin, void (*Function_Pointer)(void *), void *Argument, Pin_Types::Interrupt_Mode_Type Mode);

        /// @brief Detach an interrupt from a pin.
        /// @param Pin Pin to detach.
        void Detach_Interrupt(uint8_t Pin);
    
    private:
    } Pin_Type;

    /// @brief Pin module instance.
    extern Pin_Type Pin;

}

#endif