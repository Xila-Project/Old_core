#include "Core/Core.hpp"

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

    if ((millis() - Last_Header_Refresh) > 4000) // Refresh header every ~4000 ms
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