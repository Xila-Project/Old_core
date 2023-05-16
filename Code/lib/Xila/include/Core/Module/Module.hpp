///
/// @file Modules.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Modules_Hpp_Included
#define Modules_Hpp_Included

// - - Standard libraries

#include <vector>

// - - Base types

#include "Base_Types.hpp"

// - - Other types

#include "Task.hpp"
#include "Instruction.hpp"
#include "Semaphore.hpp"
#include "Queue.hpp"
#include "String.hpp"
#include "Date.hpp"
#include "Time.hpp"
#include "Registry.hpp"
#include "Stream.hpp"

#include "../Configuration/Path.hpp"

#define Stringizing(x) #x

namespace Xila_Namespace
{
    /// @brief Module type enumeration.
    typedef class Module_Class
    {
    public:  
        // - Methods

        // - - Constructor / destructor

        /// @brief Module constructor.
        /// @param Queue_Size Set a custom size the instruction queue (default : `Default_Instruction_Queue_Size`).
        Module_Class(Size_Type Queue_Size = Default_Instruction_Queue_Size);
        ~Module_Class();

        // - - Management

        /// @brief Send instruction to the module.
        /// @param Instruction Instruction to send.
        /// @return `Result_Type::Success` if the instruction has been sent, `Result_Type::Error` otherwise.
        Result_Type Send_Instruction(const Instruction_Type &Instruction);
        
        /// @brief Return the number of instructions available in the instruction queue.
        /// @return Number of instructions available.
        Size_Type Instruction_Available();

        // - - Getters

        /// @brief Return last instruction from the instructions queue.
        /// @return Instruction Software instruction.
        Instruction_Type Get_Instruction();

    private:
        // - Attributes

        /// @brief Instruction queue handle.
        QueueHandle_t Instruction_Queue_Handle;
    } Module_Type;
}

#endif
