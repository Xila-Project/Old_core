///
/// @file Task.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 13-11-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Module/Module.hpp"

#include "Core/Module/Task.hpp"

#include "Core/Core.hpp"

using namespace Xila_Namespace;

Task_Class::Task_Class(Module_Class* Owner_Module) : Owner_Module(Owner_Module)
{
    Task_Handle = NULL;
}

Task_Class::Task_Class(Module_Class *Owner_Module, Function_Type Task_Function, const char *Name, Size_Type Stack_Size, void *Data, Priority_Type Priority) : Owner_Module(Owner_Module)
{
   Create(Task_Function, Name, Stack_Size, Data, Priority);
}

Task_Class::~Task_Class()
{
   Delete();
}

Result_Type Task_Class::Create(Function_Type Task_Function, const char *Name, Size_Type Stack_Size, void *Data, Priority_Type Priority)
{
     if ((Priority > Priority_Type::Idle) || (Priority <= Priority_Type::Driver))
    {
        Priority = Priority_Type::Normal;
    }
    if (xTaskCreatePinnedToCore(Task_Function, Name, Stack_Size, Data, (UBaseType_t)Priority, &Task_Handle, tskNO_AFFINITY) == pdPASS)
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

void Task_Class::Delete()
{
     if ((Get_State() != State_Type::Deleted) || (Get_State() != State_Type::Invalid))
    {
        vTaskDelete(Task_Handle);
    }
}

/// @brief Feed watchdog timer.
void Task_Class::Feed_Watchdog()
{
    Watchdog_Timeout = Default_Watchdog_Timeout;
    Watchdog_Timer = Time.Milliseconds();
}

uint32_t Task_Class::Get_Watchdog_Timer()
{
    return Watchdog_Timer;
}

uint32_t Task_Class::Get_Watchdog_Timeout()
{
    return Watchdog_Timeout;
}

/// @brief  Check if one task is frozen (watchdog timeout).
void Task_Class::Check_Watchdogs()
{
    // Iterate through all tasks.
    for (auto Task_Pointer : List)
    {
        // Check if a running or active task hasn't refresh its watchdog.
        if (Task_Pointer->Get_State() == State_Type::Running && (Time.Milliseconds() - Task_Pointer->Get_Watchdog_Timer() > Task_Pointer->Get_Watchdog_Timeout()))
        {
            Task_Pointer->Suspend(); // Suspend task.
            // ? : Would it be safer to rather delete the task ?
        }
    }
}

/// @brief Resume a task.
void Task_Class::Resume()
{
    if ((Get_State() != State_Type::Deleted) || (Get_State() != State_Type::Invalid))
    {
        vTaskResume(Task_Handle);
    }
}

/// @brief Suspend a task.
void Task_Class::Suspend()
{
    if ((Get_State() != State_Type::Deleted) || (Get_State() != State_Type::Invalid))
    {
        vTaskSuspend(Task_Handle);
    }
}

/// @brief Function that delay the execution of the following instruction.
/// @param Delay_In_Millisecond
/// @details A delay function that behave exactly like delay() but additionaly feed the task watchdog.
///
void Task_Type::Delay(uint32_t Delay_In_Millisecond)
{
    Feed_Watchdog();
    vTaskDelay(pdMS_TO_TICKS(Delay_In_Millisecond));
}

/// @brief Function that delay the execution of the following
/// @param Delay_In_Millisecond
void Task_Class::Delay_Static(uint32_t Delay_In_Millisecond)
{
    vTaskDelay(pdMS_TO_TICKS(Delay_In_Millisecond));
}

/// @brief Function that delay the execution of the following instruction.
/// @param Previous_Wake_Time
/// @param Time_Increment
void Task_Class::Delay_Until(TickType_t Time_Increment)
{
    vTaskDelayUntil(&Previous_Wake_Time, Time_Increment);
}

Task_Class::State_Type Task_Class::Get_State()
{
    if (Task_Handle == NULL)
    {
        return State_Type::Invalid;
    }
    return (State_Type)eTaskGetState(Task_Handle);
}

Task_Class::Priority_Type Task_Class::Get_Priority()
{
    return (Priority_Type)uxTaskPriorityGet(Task_Handle);
}

Result_Type Task_Class::Set_Priority(Priority_Type Priority)
{
    if ((Priority > Priority_Type::Idle) && (Priority < Priority_Type::System))
    {
        return Result_Type::Invalid_Argument;
    }
    if (Get_State() == State_Type::Deleted)
    {
        return Result_Type::Error;
    }
    vTaskPrioritySet(Task_Handle, (UBaseType_t)Priority);
    return Result_Type::Success;
}

///
/// @brief Set a temporary watchdog timeout in milliseconds, by default it's set to 5000 ms. It will be reset at the next feed of the watchdog (Feed_Watchdog()).
///
/// @param Watchdog_Timeout Watchdog timeout in milliseconds.
void Task_Class::Set_Watchdog_Timeout(uint16_t Watchdog_Timeout)
{
    if (Watchdog_Timeout <= Maximum_Watchdog_Timeout)
    {
        this->Watchdog_Timeout = Watchdog_Timeout;
    }
}
