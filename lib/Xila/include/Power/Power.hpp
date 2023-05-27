///
/// @file Power.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 21-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Power_Hpp_Included
#define Power_Hpp_Included

#include "../Module/Module.hpp"

#include "Battery_Library.hpp"

//==============================================================================//
///
/// @brief Power management module.
///

namespace Xila_Namespace
{
    namespace Power_Types
    {
        /// @brief Power module event codes.
        enum class Event_Code_Type : Byte_Type
        {
            Power_Button_Pressed    ///< Power button pressed.
        };
    }

    typedef class Power_Class : public Module_Class
    {

    public:
        // - Methods

        // - - Constructors / Destructors
        Power_Class();
        ~Power_Class();

        /// @brief Start the module.
        /// @return `Result_Type::Success` if the module has been started successfully, `Result_Type::Error` otherwise.
        Result_Type Start();

        /// @brief Stop the module.
        /// @return `Result_Type::Success` if the module has been stopped successfully, `Result_Type::Error` otherwise.
        Result_Type Stop();

        /// @brief Get the battery charge level.
        /// @return Battery charge level in percent.
        uint8_t Get_Battery_Charge_Level();

        /// @brief Get the battery voltage.
        /// @return Battery voltage in millivolts.
        uint16_t Get_Battery_Voltage();

        /// @brief Power button interrupt callback function.
        /// @return `Result_Type::Success` if the callback function has been called successfully, `Result_Type::Error` otherwise.
        static void IRAM_ATTR Button_Interrupt_Handler();

        /// @brief Check if the power button has been pressed and send instruction if needed.
        void Check_Button();

        /// @brief Go to deep sleep mode.
        void Deep_Sleep();

        /// @brief Restart the system.
        void Restart();


    private:
        // - Methods

        // - - Registry
        Result_Type Create_Registry();
        Result_Type Save_Registry();
        Result_Type Load_Registry();

       // - Attributes

        Task_Type Task;

        /// @brief Button press counter.
        volatile uint8_t Button_Clicked;


        /// @brief Button press timer, used to differentiate a short press from a long press.
        volatile uint32_t Button_Timer;
    } Power_Type;

    extern Power_Type Power;
}

#endif
