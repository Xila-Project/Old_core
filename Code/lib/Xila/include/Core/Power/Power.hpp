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
        enum class Event_Code_Type : Byte_Type
        {
            Power_Button_Pressed
        };
    }

    typedef class Power_Class : public Module_Class, public Battery_Class
    {

    public:
        // - Methods

        // - - Constructors / Destructors
        Power_Class();
        ~Power_Class();

        Result_Type Start();
        Result_Type Stop();

        uint8_t Get_Battery_Charge_Level();
        uint16_t Get_Battery_Voltage();

        static void IRAM_ATTR Button_Interrupt_Handler();

        void Check_Button();
        void Deep_Sleep();
        void Restart();


    private:
        // - Methods

        // - - Registry
        Result_Type Create_Registry();
        Result_Type Save_Registry();
        Result_Type Load_Registry();

        // - - Task
        static void Task_Start_Function(void* Instance_Pointer);
        void Task_Function();

       // - Attributes

        Task_Type Task;

        /// @brief Button press counter.
        volatile uint8_t Button_Counter;


        /// @brief Button press timer, used to differentiate a short press from a long press.
        volatile uint32_t Button_Timer;
    } Power_Type;

    extern Power_Type Power;
}

#endif
