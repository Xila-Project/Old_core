///
/// @file Task.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 29-03-2021
///
/// @copyright Copyright (c) 2021
///

#ifndef Task_Hpp_Included
#define Task_Hpp_Included

#include <vector>
#include "../Module.hpp"
#include "Arduino.h"
#include "Configuration.hpp"

class Task_Class : public Module_Class
{
public:
  typedef void Task_Function(void *);

  typedef enum Priority_Enumeration
  {
    Idle = 0,
    Background,
    Low,
    Normal,
    High,
    System,
    Driver
  } Priority_Type;

  typedef enum State_Enumeration
  {
    Running = eRunning,
    Ready = eReady,
    Blocked = eBlocked,
    Suspended = eSuspended,
    Deleted = eDeleted,
    Invalid = eInvalid,
  } State::Type;

  Task_Class();
  ~Task_Class();

  Result_Type Create(Task_Function *Task_Function, const char *Task_Name, size_t Stack_Size = 4000, Priority_Type Priority = Normal);

  Result_Type Set_Priority(Priority_Type Priority);
  void Suspend();
  void Resume();
  void Delete();

  State::Type Get_State();
  Priority_Type Get_Priority();

  /*
  static void Give_Notification(Task_Class& Task, unsigned int Index = 0);
  static void Give_Notification_From_ISR(Task_Class& Task, void* Data, unsigned int Index = 0);
  static void Take_Notification(Task_Class& Task);
  */

  static void Delay(uint32_t Delay_In_Millisecond);
  static void Delay_Until(TickType_t *Previous_Wake_Time, const TickType_t Time_Increment);

private:
  xTaskHandle Task_Handle;
};

#endif