///
/// @file Task.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 19-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Module.hpp"

#include "Core/Core.hpp"

using namespace Xila_Namespace;

// ------------------------------------------------------------------------- //
//
//                               Variables
//
// ------------------------------------------------------------------------- //

std::vector<Module_Class*> Module_Class::List(40);

// ------------------------------------------------------------------------- //
//
//                                  Constructor
//
// ------------------------------------------------------------------------- //

Module_Class::Module_Class(Size_Type Queue_Size)
{
    if (Queue_Size != 0)
    {
        if (xQueueCreate(Queue_Size, sizeof(Instruction_Type)) == NULL)
        {
            delete this;
        }
    }
    vTaskDelay(pdMS_TO_TICKS(5));
}

Module_Class::~Module_Class()
{
    vQueueDelete(Instruction_Queue_Handle);
}

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

///
/// @brief Used to send instructions to software.
///
/// @param Instruction Instruction to send.
///
/// @details It's used by Xila and the software itself to fill the instructions queue.
void Module_Class::Send_Instruction(const Instruction_Type &Instruction)
{
    xQueueSendToBack(Instruction_Queue_Handle, (void *)&Instruction, portMAX_DELAY);
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //



// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //


Module_Class::Size_Type Module_Class::Instruction_Available()
{
    return uxQueueMessagesWaiting(Instruction_Queue_Handle);
}

/// @brief Return last instruction from the instructions queue.
///
/// @return Xila_Class::Instruction Software instruction.
Module_Class::Instruction_Type Module_Class::Get_Instruction()
{
    static Instruction_Type Current_Instruction;
    if (xQueueReceive(Instruction_Queue_Handle, &Current_Instruction, 0) != pdTRUE)
    {
        Current_Instruction.Set_Sender(NULL);
        Current_Instruction.Set_Receiver(NULL);

    }
    return Current_Instruction;
}

