///
/// @file Software.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Software/Software.hpp"

std::vector<Software_Class *> Software_Class::Software_List;

Software_Class *Software_Class::Maximized_Software = NULL;

uint8_t Software_Class::Watchdog_State = 0;

///
/// @brief Start a software instance main task.
///
/// @param Instance_Pointer
void Software_Class::Start_Main_Task(void *Instance_Pointer)
{
  (Software_Class *)Instance_Pointer->Main_Task_Function();
}

///
/// @brief Return openned software's state.
///
/// @param Software_Handle Software handle to check.
/// @return Software::State
Software_Class::State_Type Software_Class::Get_State()
{
  if (Maximized_Software != NULL && Maximized_Software == this)
  {
    return Maximized;
  }
  else
  {
    return Minimized;
  }
}

///
/// @brief Check watchdog timer of every openned software.
///
void Software_Class::Check_Watchdogs()
{
  // Iterate through all opened software.
  for (auto Software_Pointer = Software_List.begin(); Software_Pointer != Software_List.end(); Software_Pointer++)
  {
    // Check if watchdogs are expired.
    if ((*Software_Pointer)->Check_Watchdog())
    {
      // Watchdog expired, kill software.
      (*Software_Pointer)->Kill();
    }
  }
}

///
/// @brief Return if software watchdog is expired or not.
///
/// @return true watchdog is expired.
/// @return false watchdog is not expired.
bool Software_Class::Check_Watchdog()
{
  if (Xila.Time.Milliseconds() - Last_Watchdog_Feed > Watchdog_Timeout || Watchdog_Timeout > Maximum_Watchdog_Timeout)
  {
    return true;
  }
  else
  {
    return false;
  }
}

///
/// @brief Feed watchdog timer (reset).
///
/// @param Software_Handle Software's handle to feed watchdog.
void Software_Class::Feed_Watchdog()
{
  if (Watchdog_State != 0 && &Software_Handle == Xila.Software_Management.Openned[Watchdog_ State]->Handle)
  {
    Xila.Software_Management.Watchdog_Timer = Xila.Time.Milliseconds();
  }
}

///
/// @brief Function that close software.
///
/// @param Software_Handle Software's handle to close (equal NULL by default, which close currrent maximized software).
void Software_Class::Close()
{

  // - Don't forget to remove the software pointer from the software list.
  for (auto Software_Pointer = Software_List.begin(); Software_Pointer != Software_List.end(); Software_Pointer++)
  {
    if (*Software_Pointer == this)
    {
      Software_List.erase(Software_Pointer);
      break;
    }
  }

  // -- Don't forget to remove maximized pointer.
  if (Maximized_Software == this)
  {
    Maximized_Software = NULL;
    Software_List[0]->Maximize();
  }

  this->Send_Instruction(Xila.Close);
}

///
/// @brief Function that minimize software (and maximize Shell).
///
/// @param Software_Handle Software's handle to minimize.
void Software_Class::Minimize()
{
  if (Maximized_Software == this || Maximized_Software == NULL)
  {
    return;
  }
  Maximized_Software->Send_Instruction(Xila.Minimize);
  Task_Type::Delay(20);
  Maximized_Software = NULL;
  Software_List[0]->Maximize();
}

///
/// @brief Function that maximize software (and minimize current maximized software).
///
/// @param Software_Handle Software handle to maximize.
void Software_Class::Maximize()
{
  if (Maximized_Software == this)
  {
    return;
  }
  if (Maximized_Software != NULL)
  {
    Maximized_Software->Minimize();
  }
  Maximized_Software = this;
  this->Send_Instruction(Xila.Maximize);
  Task_Type::Delay(20);
}

///
/// @brief Function that close roughly the current maximized software.
///  @details Delete manualy the main software's task, and then delete software instance. That could leave undeleted memory fragment (external tasks, external variables, dynamic allocated variables etc.).
///
void Software_Class::Kill()
{

  this->Close();

  Xila.Task.Delete(this->Main_Task);
  delete this;
  Task_Class::Delay(10);
}

///
/// @brief Construct a new Xila_Class::Software object
///
/// @param Software_Handle Current software handle
/// @param Queue_Size Instructions queue size (default : )
Software_Class::Software_Class(uint8_t Queue_Size) :  Current_Instruction(Xila.Idle),
                                                      Last_Watchdog_Feed(millis()),
                                                      Watchdog_Timeout(Default_Watchdog_Timeout)
{
  if (Queue_Size != 0)
  {
    if (Instruction_Queue.Create(Queue_Size) == Error)
    {
      delete this;
    }
    else
    {
      Send_Instruction(Open);
    }
  }
  vTaskDelay(pdMS_TO_TICKS(5)); // -- Wait fews ms (crash if not)
}

///
/// @brief Destroy the Xila_Class::Software object
///
Software_Class::~Software_Class() // Destructor : close
{
  vQueueDelete(Instruction_Queue_Handle);
}

///
/// @brief Set watchdog timeout, by default it's set to 5000 ms.
///
/// @param Watchdog_Timeout Watchdog timeout in milliseconds.
void Software_Class::Set_Watchdog_Timeout(uint16_t Watchdog_Timeout)
{
  if (Watchdog_Timeout <= Maximum_Watchdog_Timeout)
  {
    this->Watchdog_Timeout = Watchdog_Timeout;
  }
}

///
/// @brief Return last instruction from the instructions queue.
///
/// @return Xila_Class::Instruction Software instruction.
Software_Class::Instruction_Type Software_Class::Get_Instruction()
{
  static Instruction_Type Current_Instruction;

  if (xQueueReceive(Instruction_Queue_Handle, &Current_Instruction, 0) != pdTRUE)
  {
    Current_Instruction.Sender = 0;
    Current_Instruction.Current_Instruction = 0;
  }

  this->Feed_Watchdog();
  return Current_Instruction;
}

///
/// @brief Used to send instructions to software.
///
/// @param Instruction Instruction to send.
///
/// @details It's used by Xila and the software itself to fill the instructions queue.
void Software_Class::Send_Instruction(Instruction_Type Instruction)
{
  xQueueSendToBack(Instruction_Queue_Handle, (void *)&Instruction, portMAX_DELAY);
}

///
/// @brief Convert 2 byte char instruction into Xila Instruction and send it.
///
/// @param Instruction_Char_1 Instruction first byte
/// @param Instruction_Char_2 Instruction second byte
void Software_Class::Send_Instruction(Module::Type Sender, const char Arguments[4])
{
  static Instruction_Type Current_Instruction;
  Current_Instruction.Sender = Sender;
  memcpy(Current_Instruction.Arguments, Arguments, sizeof(Arguments));
  Send_Instruction(Current_Instruction);
}
