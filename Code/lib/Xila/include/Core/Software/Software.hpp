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

#include "../Module.hpp"

#include "Software_Handle.hpp"

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
            Active,
            Inactive
        } State_Type;

        // - Methods

        // - - Constructor / Destructor
        Software_Class(uint8_t Queue_Size = Default_Instruction_Queue_Size);
        virtual ~Software_Class();

        State_Type Get_State(const Software_Handle_Class &Software_Handle);


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

        static void Start_Main_Task(void *Instance_Pointer);


        private:

        ///
        /// @brief Openned software pointer array
        ///
        static std::vector<Software_Class *> List;

        static Software_Class* Active_Software;


    } Software_Type;
}

#endif