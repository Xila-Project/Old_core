///
/// @file Task.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 19-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Software/Task.hpp"

Task_Class::Task_Class() : Task_Handle(NULL)
{
}

void Task_Class::Resume()
{
    vTaskResume(Task_Handle);
}

void Task_Class::Suspend()
{
    vTaskSuspend(Task_Handle);
}

Event_Type Task_Class::Create(Task_Function (*Task_Function)(void *), const char *Task_Name, size_t Stack_Size, Priority_Type Priority)
{
    if (Task_Handle != NULL)
    {
        return Event_Type::Error;
    }

    if (xTaskCreatePinnedToCore(Task_Function, Task_Name, Stack_Size, NULL, Software_Task, &Task_Handle, tskNO_AFFINITY) != pdPASS)
    {
        return Error;
    }
    return Success;
}

void Task_Class::Delete()
{
    vTaskDelete(Task_Handle);
}

Event_Type Task_Class::Set_Priority(Priority_Type Priority)
{
    if (Priority < Low)
    {
        return Invalid_Argument;
    }
    vTaskPrioritySet(Task_Handle, Priority);
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

void Task_Class::Delay_Until(TickType_t* Previous_Wake_Time, const TickType_t Time_Increment)
{
    vTaskDelayUntil(Previous_Wake_Time, Time_Increment);
}
