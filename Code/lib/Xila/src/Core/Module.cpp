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

using namespace Xila_Namespace;

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
        else
        {
            Send_Instruction(Open);
        }
    }
    vTaskDelay(pdMS_TO_TICKS(5));
}

Module_Class::~Module_Class()
{
    vQueueDelete(Instruction_Queue_Handle);
}

Module_Class::Task_Class::Task_Class() : Task_Handle(NULL)
{
}

Module_Class::Task_Class::~Task_Class()
{
    Delete();
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
void Module_Class::Send_Instruction(Instruction_Type &Instruction)
{
    xQueueSendToBack(Instruction_Queue_Handle, (void *)&Instruction, portMAX_DELAY);
}

///
/// @brief Convert 2 byte char instruction into Xila Instruction and send it.
///
/// @param Instruction_Char_1 Instruction first byte
/// @param Instruction_Char_2 Instruction second byte
void Module_Class::Send_Instruction(Module_Class *Sender, const char Arguments[4])
{
    static Instruction_Type Current_Instruction;
    Current_Instruction.Set_Sender(Sender);
    Current_Instruction.Set_Arguments(Arguments);
    Send_Instruction(Current_Instruction);
}

void Module_Class::Task_Class::Resume()
{
    if (Get_State() != Deleted || Get_State() != Invalid)
    {
        vTaskResume(Task_Handle);
    }
}

void Module_Class::Task_Class::Suspend()
{
    if (Get_State() != Deleted || Get_State() != Invalid)
    {
        vTaskSuspend(Task_Handle);
    }
}

Module_Class::Result::Type Module_Class::Task_Class::Create(Task_Function *Task_Function, const char *Task_Name, Size_Type Stack_Size, Priority_Type Priority)
{
    if (Task_Handle != NULL)
    {
        return Result::Error;
    }

    if (Priority > High || Priority < Background)
    {
        return Result::Invalid_Argument;
    }

    if (xTaskCreatePinnedToCore(Task_Function, Task_Name, Stack_Size, NULL, (UBaseType_t)Priority, &Task_Handle, tskNO_AFFINITY) != pdPASS)
    {
        return Result::Error;
    }
    return Result::Success;
}

///
/// @brief A delay function.
/// @param Delay_In_Millisecond
/// @details A delay function that behave exactly like delay()
///
void Module_Class::Task_Class::Delay(uint32_t Delay_In_Millisecond)
{
    vTaskDelay(pdMS_TO_TICKS(Delay_In_Millisecond));
}

void Module_Class::Task_Class::Delay_Until(TickType_t *Previous_Wake_Time, const TickType_t Time_Increment)
{
    vTaskDelayUntil(Previous_Wake_Time, Time_Increment);
}

void Module_Class::Task_Class::Delete()
{
    if (Get_State() != Deleted || Get_State() != Invalid)
    {
        vTaskDelete(Task_Handle);
    }
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

Module_Class::Result::Type Module_Class::Task_Class::Set_Priority(Priority_Type Priority)
{
    if (Priority > Idle && Priority < System)
    {
        return Result::Invalid_Argument;
    }
    if (Get_State() == Deleted)
    {
        return Result::Error;
    }
    vTaskPrioritySet(Task_Handle, (UBaseType_t)Priority);
    return Result::Success;
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

///
/// @brief Return last instruction from the instructions queue.
///
/// @return Xila_Class::Instruction Software instruction.
Module_Class::Instruction_Type Module_Class::Get_Instruction()
{
    static Instruction_Type Current_Instruction;

    if (xQueueReceive(Instruction_Queue_Handle, &Current_Instruction, 0) != pdTRUE)
    {
        Current_Instruction.Set_Sender(NULL);
        Current_Instruction.Set_Sender(NULL);
        Current_Instruction.Set_Arguments(0);
    }

    this->Feed_Watchdog();
    return Current_Instruction;
}

Module_Class::Task_Class::State_Type Module_Class::Task_Class::Get_State()
{
    if (Task_Handle == NULL)
    {
        return Invalid;
    }
    return (State_Type)eTaskGetState(Task_Handle);
}

Module_Class::Task_Class::Priority_Type Module_Class::Task_Class::Get_Priority()
{
    switch (uxTaskPriorityGet(Task_Handle))
    {
    case Idle:
        return Idle;
    case Background:
        return Background;
    case Low:
        return Low;
    case Normal:
        return Normal;
    case High:
        return High;
    case System:
        return System;
    case Driver:
        return Driver;
    }
}