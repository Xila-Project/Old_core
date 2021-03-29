///
/// @file Task.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 28-03-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Core.hpp"

inline void Xila_Class::Task_Class::Resume(Xila_Task_Handle Task_To_Resume)
{
  vTaskResume(Task_To_Resume);
}

inline void Xila_Class::Task_Class::Suspend(Xila_Task_Handle Task_To_Suspend)
{
  vTaskSuspend(Task_To_Suspend);
}

inline Xila_Event Xila_Class::Task_Class::Create(Xila_Task_Function Task_Function, const char *Task_Name, size_t Stack_Size, void *pvParameters, Xila_Task_Handle *Task_Handle)
{
  if (xTaskCreatePinnedToCore(Task_Function, Task_Name, Stack_Size, pvParameters, Software_Task, Task_Handle, tskNO_AFFINITY) != pdPASS)
  {
    return Error;
  }
  return Success;
}

inline Xila_Event Xila_Class::Task_Class::Create(Xila_Task_Function Task_Function, const char *Task_Name, size_t Stack_Size, void *pvParameters, uint16_t Priority, Xila_Task_Handle *Task_Handle)
{
  if (xTaskCreatePinnedToCore(Task_Function, Task_Name, Stack_Size, pvParameters, Priority, Task_Handle, tskNO_AFFINITY) != pdPASS)
  {
    return Error;
  }
  return Success;
}

void Xila_Class::Task_Class::Delete(Xila_Task_Handle Task_To_Delete)
{
  vTaskDelete(Task_To_Delete);
}

/**
    * @brief A delay function.
    * @param Delay_In_Millisecond
    * @details A delay function that behave exactly like delay()
    */
void Xila_Class::Task_Class::Delay(uint32_t Delay_In_Millisecond)
{
  Xila.Task.Delay(Delay_In_Millisecond);
}
