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

Task_Class::Task_Class() : Task_Handle(NULL)
{
}

Task_Class::~Task_Class()
{
    Delete();
}

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Task_Class::Resume()
{
    if (Get_State() != Deleted || Get_State() != Invalid)
    {
        vTaskResume(Task_Handle);
    }
}

void Task_Class::Suspend()
{
    if (Get_State() != Deleted || Get_State() != Invalid)
    {
        vTaskSuspend(Task_Handle);
    }
}

Module_Class::Result_Type Task_Class::Create(Task_Function *Task_Function, const char *Task_Name, Size_Type Stack_Size, Priority_Type Priority)
{
    if (Task_Handle != NULL)
    {
        return Error;
    }

    if (Priority > High || Priority < Background)
    {
        return Invalid_Argument;
    }

    if (xTaskCreatePinnedToCore(Task_Function, Task_Name, Stack_Size, NULL, (UBaseType_t)Priority, &Task_Handle, tskNO_AFFINITY) != pdPASS)
    {
        return Error;
    }
    return Success;
}

///
/// @brief A delay function.
/// @param Delay_In_Millisecond
/// @details A delay function that behave exactly like delay()
///
void Task_Class::Delay(uint32_t Delay_In_Millisecond)
{
    vTaskDelay(pdMS_TO_TICKS(Delay_In_Millisecond));
}

void Task_Class::Delay_Until(TickType_t *Previous_Wake_Time, const TickType_t Time_Increment)
{
    vTaskDelayUntil(Previous_Wake_Time, Time_Increment);
}

void Task_Class::Delete()
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

Module_Class::Result_Type Task_Class::Set_Priority(Priority_Type Priority)
{
    if (Priority > Idle && Priority < System)
    {
        return Invalid_Argument;
    }
    if (Get_State() == Deleted)
    {
        return Error;
    }
    vTaskPrioritySet(Task_Handle, (UBaseType_t)Priority);
    return Success;
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

Task_Class::State_Type Task_Class::Get_State()
{
    if (Task_Handle == NULL)
    {
        return Invalid;
    }
    return (State_Type)eTaskGetState(Task_Handle);
}

Task_Class::Priority_Type Task_Class::Get_Priority()
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