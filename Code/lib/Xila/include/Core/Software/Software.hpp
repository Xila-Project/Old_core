///
/// @file Software.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Software_Hpp_Included
#define Software_Hpp_Included

class Software_Handle;

#include "../Module.hpp"

#include "Software_Handle.hpp"

#include "Semaphore.hpp"
#include <vector>

/*
///
/// @brief String to 16 bits encoded instruction conversion macro.
///
#define Instruction(Sender, Argument_1, Argument_2, Argument_3) (Sender * 16777216 + Argument_1 * 65536 + Argument_2 * 256 + Argument_3)*/

namespace Xila_Namespace
{
    typedef class Software_Class : public Module_Class
    {
    public:
        // - Types
        typedef enum State_Enumeration
        {
            Minimized, ///< Maximized state.
            Maximized, ///< Minimized state.
        } State_Type;

        typedef Task_Class Task_Type;

        // - Methods

        // - - Constructor / Destructor
        Software_Class(uint8_t Queue_Size = Default_Instruction_Queue_Size);
        virtual ~Software_Class();

        void Send_Instruction(Instruction_Type Instruction);
        void Send_Instruction(Module::Type Sender, const char Arguments[4]);

        bool Check_Watchdog();

        static void Check_Watchdogs();

        static void Send_Instruction_To_Maximized(Instruction_Type Instruction);

        State_Type Get_State(const Software_Handle_Class &Software_Handle);

        Instruction_Type Get_Instruction();

        void Set_Watchdog_Timeout(uint16_t Watchdog_Timeout = Default_Watchdog_Timeout);

        /// @brief Software task handle.
        ///
        Task_Type Main_Task;

        virtual void Main_Task_Function();

        // private:

        void Minimize();
        void Maximize();
        void Kill();
        void Close();

        void Feed_Watchdog();

        static void Start_Main_Task(void *Instance_Pointer);

        ///
        /// @brief Openned software pointer array
        ///
        static std::vector<Software_Class *> Software_List;

        static volatile Software_Class *Maximized_Software;

        // -- Attributes -- //

        uint32_t Watchdog_Timer = 0;
        static uint8_t Watchdog_State;

        ///
        /// @brief Queue handle.
        ///
        QueueHandle_t Instruction_Queue;

        ///
        /// @brief Last software watchdog feed.
        ///
        uint32_t Last_Watchdog_Feed;

        ///
        /// @brief Watchdog defined timeout.
        ///
        uint16_t Watchdog_Timeout;
    } Software_Type;
}

#endif