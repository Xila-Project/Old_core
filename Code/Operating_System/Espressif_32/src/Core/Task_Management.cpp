#include "Core/Core.hpp"

void Xila_Class::Task_Resume(Xila_Task_Handle Task_To_Resume)
{
  Feed_Watchdog();
  vTaskResume(Task_To_Resume);
}

void Xila_Class::Task_Suspend(Xila_Task_Handle Task_To_Suspend)
{
  Feed_Watchdog();
  vTaskSuspend(Task_To_Suspend);
}

Xila_Event Xila_Class::Task_Create(Xila_Task_Function Task_Function, const char* Task_Name, size_t Stack_Size, void* pvParameters, Xila_Task_Handle Task_Handle)
{
  Feed_Watchdog();
  if (xTaskCreatePinnedToCore(Task_Function, Task_Name, Stack_Size, pvParameters, SOFTWARE_TASK_PRIOITY, &Task_Handle, tskNO_AFFINITY) != pdPASS)
  {
    return Error;
  }
  return Success;
}

void Xila_Class::Task_Delete(Xila_Task_Handle Task_To_Delete)
{
  Feed_Watchdog();
  vTaskDelete(Task_To_Delete);
}

