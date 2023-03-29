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
#include "Core/Log/Log.hpp"
#include "Core/System/System.hpp"

using namespace Xila_Namespace;

// - Attributes

std::vector<Task_Class *> Task_Class::List;

// - Methods

// - Constructors / Destructors

Task_Class::Task_Class(Module_Class *Owner_Module) : Owner_Module(Owner_Module), Task_Handle(NULL)
{
    
}

Task_Class::Task_Class(Module_Class *Owner_Module, Function_Type Task_Function, const char *Name, Size_Type Stack_Size, void *Data, Priority_Type Priority) : Owner_Module(Owner_Module), Task_Handle(NULL)
{
    Create(Task_Function, Name, Stack_Size, Data, Priority);
}

Task_Class::Task_Class(xTaskHandle Task_Handle) : Task_Handle(Task_Handle)
{
}

Task_Class::~Task_Class()
{
    Delete();
}

// - - Manipulaton

Result_Type Task_Class::Create(Function_Type Task_Function, const char *Name, Size_Type Stack_Size, void *Data, Priority_Type Priority)
{
    // Not ideal but it's the only way to allocate static vector.
    List.reserve(40);

    if ((Priority > Priority_Type::Idle) || (Priority <= Priority_Type::Driver))
    {
        Priority = Priority_Type::Normal;
    }

    if (this->Get_State() != State_Type::Invalid)
    {
        return Result_Type::Error;
    }

    if (xTaskCreatePinnedToCore(Task_Function, Name, Stack_Size, Data, (UBaseType_t)Priority, &Task_Handle, tskNO_AFFINITY) != pdPASS)
    {
        return Result_Type::Error;
    }

    Feed_Watchdog();
    List.push_back(this);
    return Result_Type::Success;
}

void Task_Class::Delete()
{
    if ((Get_State() == State_Type::Deleted) || (Get_State() == State_Type::Invalid))
    {
        return;
    }

    vTaskDelete(Task_Handle);

    for (auto Task_Pointer = List.begin(); Task_Pointer != List.end(); Task_Pointer++)
    {
        if (*Task_Pointer == this)
        {
            List.erase(Task_Pointer);
            break;
        }
    }
}

void Task_Class::Feed_Watchdog()
{
    Watchdog_Timeout = System.Get_Up_Time_Milliseconds() + Default_Watchdog_Timeout;
}

uint32_t Task_Class::Get_Watchdog_Timeout()
{
    return Watchdog_Timeout;
}

char* Task_Class::Get_Name()
{
    return pcTaskGetName(Task_Handle);
}

void Task_Class::Check_Watchdogs()
{
    // Iterate through all tasks.
    for (auto &Task_Pointer : List)
    {
        // Check if a running or active task hasn't refresh its watchdog.
        if (Task_Pointer->Get_State() == State_Type::Running)
        {
            if (Task_Pointer->Get_Watchdog_Timeout() < System.Get_Up_Time_Milliseconds())
            {
                Log_Warning("System", "A task (%s) seems to be frozen, suspend it !", Task_Pointer->Get_Name());
                Task_Pointer->Suspend(); // Suspend task.
            }
            // ? : Would it be safer to rather delete the task ?
        }
    }
}

void Task_Class::Resume()
{
    if ((Get_State() != State_Type::Deleted) || (Get_State() != State_Type::Invalid))
    {
        Feed_Watchdog();
        vTaskResume(Task_Handle);
    }
}

void Task_Class::Suspend()
{
    if ((Get_State() != State_Type::Deleted) || (Get_State() != State_Type::Invalid))
    {
        vTaskSuspend(Task_Handle);
    }
}

void Task_Type::Delay(uint32_t Delay_In_Millisecond)
{
    Feed_Watchdog();
    vTaskDelay(pdMS_TO_TICKS(Delay_In_Millisecond));
}

void Task_Class::Delay_Static(uint32_t Delay_In_Millisecond)
{
    vTaskDelay(pdMS_TO_TICKS(Delay_In_Millisecond));

    for (auto Task_Pointer : List)
    {
        if (Task_Pointer->Task_Handle == xTaskGetCurrentTaskHandle())
        {
            Task_Pointer->Feed_Watchdog();
            break;
        }
    }
}

void Task_Class::Delay_Until(TickType_t Time_Increment)
{
    Feed_Watchdog();
    vTaskDelayUntil(&Previous_Wake_Time, Time_Increment);
}

void Task_Class::Suspend_All()
{
    vTaskSuspendAll();
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
    Feed_Watchdog();
    vTaskPrioritySet(Task_Handle, (UBaseType_t)Priority);
    return Result_Type::Success;
}

void Task_Class::Set_Watchdog_Timeout(uint16_t Watchdog_Timeout)
{
    if ((Watchdog_Timeout <= Maximum_Watchdog_Timeout) && (this->Watchdog_Timeout - System.Get_Up_Time_Milliseconds() > Default_Watchdog_Timeout))
    {
        this->Watchdog_Timeout = System.Get_Up_Time_Milliseconds() + Watchdog_Timeout;
    }
}

const Module_Type* Task_Class::Get_Owner_Module()
{
    return Owner_Module;
}

void Task_Class::Delete_Module_Tasks(Module_Type* Module)
{
    for (auto & Task_Pointer : List)
    {
        if (Task_Pointer->Get_Owner_Module() == Module)
        {
            Task_Pointer->Delete();
        }
    }
}

Size_Type Task_Class::Get_Lowest_Free_Stack()
{
    Log_Verbose("Task", "Task handle %X", Task_Handle);
    return uxTaskGetStackHighWaterMark(Task_Handle);
}