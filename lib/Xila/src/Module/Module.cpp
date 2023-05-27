/// @file Task.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 19-07-2022
///
/// @copyright Copyright (c) 2022

// - Includes

#include "Module/Module.hpp"
#include "Log/Log.hpp"

// - Namespaces
using namespace Xila_Namespace;

// - Methods

Module_Class::Module_Class(Size_Type Queue_Size) : Instruction_Queue_Handle(NULL)
{
    if (Queue_Size != 0)
    {
        Instruction_Queue_Handle = xQueueCreate(Queue_Size, sizeof(Instruction_Type));
        if (Instruction_Queue_Handle == NULL)
        {
            Log_Error("Module", "Failed to create instruction queue ! Deleting module...");
            delete this;
        }
    }

}

Module_Class::~Module_Class()
{
    vQueueDelete(Instruction_Queue_Handle);
}

Result_Type Module_Class::Send_Instruction(const Instruction_Type &Instruction)
{
    if (xQueueSendToBack(Instruction_Queue_Handle, (void *)&Instruction, 0) != pdTRUE)
    {
        return Result_Type::Error;
    }
    return Result_Type::Success;
}


Size_Type Module_Class::Instruction_Available()
{
    return uxQueueMessagesWaiting(Instruction_Queue_Handle);
}

Instruction_Type Module_Class::Get_Instruction()
{
    static Instruction_Type Current_Instruction;
    if (xQueueReceive(Instruction_Queue_Handle, &Current_Instruction, 0) != pdTRUE)
    {
        Current_Instruction.Set_Sender(NULL);
        Current_Instruction.Set_Receiver(NULL);

    }
    return Current_Instruction;
}

