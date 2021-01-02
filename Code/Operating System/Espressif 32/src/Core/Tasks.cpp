#include "Core/Core.hpp"

// Idle task, lowest priority, nothing is running

void Xila_Class::Idle_Task_Software_Core(void *pvParameters)
{
  (void)pvParameters;
  while (1)
  {
    //Serial.print(F("Idle software core"));
    vTaskDelay(1);
  }
}

void Xila_Class::Idle_Task_System_Core(void *pvParameters)
{
  (void)pvParameters;
  while (1)
  {
    //Serial.print(F("Idle system core"));
    vTaskDelay(1);
  }
}

// Main task for the core
void Xila_Class::Core_Task(void *pvParameters)
{
  (void)pvParameters;
  uint8_t Counter = 0;
  while (1)
  {

    if (ESP.getFreeHeap() < 2000)
    {
      Serial.println("Low Memory !");
    }

    Xila.Synchronise_Time(); // Time synchro

    Xila.Refresh_Header(); // Header refreshing

    Xila.Check_Power_Button();

    Xila.Execute_Background_Jobs(); // Software background function execution

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
