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

// ------------------------------------------------------------------------- //
//
//                                  Constructor
//
// ------------------------------------------------------------------------- //

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