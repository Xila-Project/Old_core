///
 /// @file Task.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1
 /// @date 29-03-2021
 /// 
 /// @copyright Copyright (c) 2021
 /// 

 #ifndef TASK_HPP_INCLUDED
 #define TASK_HPP_INCLUDED

inline void Xila_Class::Task_Class::Resume(Xila_Task_Handle Task_To_Resume) const
{
  vTaskResume(Task_To_Resume);
}

inline void Xila_Class::Task_Class::Suspend(Xila_Task_Handle Task_To_Suspend) const
{
  vTaskSuspend(Task_To_Suspend);
}

inline Xila_Class::Event Xila_Class::Task_Class::Create(Xila_Task_Function Task_Function, const char *Task_Name, size_t Stack_Size, void *pvParameters, Xila_Task_Handle *Task_Handle) const
{
  if (xTaskCreatePinnedToCore(Task_Function, Task_Name, Stack_Size, pvParameters, Software_Task, Task_Handle, tskNO_AFFINITY) != pdPASS)
  {
    return Error;
  }
  return Success;
}

inline Xila_Class::Event Xila_Class::Task_Class::Create(Xila_Task_Function Task_Function, const char *Task_Name, size_t Stack_Size, void *pvParameters, uint16_t Priority, Xila_Task_Handle *Task_Handle)
{
  if (xTaskCreatePinnedToCore(Task_Function, Task_Name, Stack_Size, pvParameters, Priority, Task_Handle, tskNO_AFFINITY) != pdPASS)
  {
    return Error;
  }
  return Success;
}

inline void Xila_Class::Task_Class::Delete(Xila_Task_Handle Task_To_Delete) const
{
  vTaskDelete(Task_To_Delete);
}

/**
    * @brief A delay function.
    * @param Delay_In_Millisecond
    * @details A delay function that behave exactly like delay()
    */
inline void Xila_Class::Task_Class::Delay(uint32_t Delay_In_Millisecond) const
{
  vTaskDelay(pdMS_TO_TICKS(Delay_In_Millisecond));
}

 #endif