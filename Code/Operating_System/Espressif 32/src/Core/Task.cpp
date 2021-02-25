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
      Xila.Panic_Handler(Low_Memory);
    }

    Xila.Check_Watchdog(); // check if current running software is not frozen

    Xila.Synchronise_Time(); // Time synchro

    if ((millis() - Last_Header_Refresh) > 4000) // Refresh header every ~4000 ms
    {
      Xila.Refresh_Header(); // Header refreshing
      Last_Header_Refresh = millis();
    }

    Xila.Check_Power_Button();

    Xila.Check_System_Drive();

    vTaskDelay(pdMS_TO_TICKS(200));
  }
}