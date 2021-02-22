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
  if (xTaskCreatePinnedToCore(Task_Function, Task_Name, Stack_Size, pvParameters, SOFTWARE_TASK_PRIOITY, &Task_Handle, SOFTWARE_CORE) != pdPASS)
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

// Main task for the core
void Xila_Class::Core_Task(void *pvParameters)
{
  uint32_t Last_Header_Refresh = 0;
  (void)pvParameters;
  while (1)
  {

    if (ESP.getFreeHeap() < 2000)
    {
      Serial.println("Low Memory !");
    }

    Xila.Check_Watchdog(); // check if current running software is not frozen

    Xila.Synchronise_Time(); // Time synchro

    if ((millis() - Last_Header_Refresh) > 3000)
    {
      Xila.Refresh_Header(); // Header refreshing
      Last_Header_Refresh = millis();
    }

    Xila.Check_Power_Button();

#if STACK_OVERFLOW_DETECTION == 1
    Verbose_Print("> Current task high watermark :");
    Serial.println(uxTaskGetStackHighWaterMark(Xila_Class::Instance_Pointer->Open_Software_Pointer[0]->Task_Handle));
#endif
    vTaskDelay(pdMS_TO_TICKS(200));
  }
  /*xQueueReceive(Xila.Core_Instruction_Queue_Handle, Core_Instruction_Pointer, portMAX_DELAY);
    Core_Instruction_Pointer->Return_Pointer = Core_Instruction_Pointer->Function_Pointer(Core_Instruction_Pointer);
    xSemaphoreGive(Core_Instruction_Pointer->Executed);
    vTaskDelay(pdMS_TO_TICKS(5));*/
}
