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

#include "Core/Core.hpp"

using namespace Xila_Namespace;

std::vector<Software_Class*> Software_Class::List(10);

Software_Class* Software_Class::Active_Software = NULL;



///
/// @brief Start a software main task.
///
/// @param Instance_Pointer
void Software_Class::Start_Main_Task(void *Instance_Pointer)
{
  (Software_Class*)Instance_Pointer->Main_Task_Function();
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
/// @brief Function that close software.
///
/// @param Software_Handle Software's handle to close (equal NULL by default, which close currrent maximized software).
void Software_Class::Close()
{

  // - Don't forget to remove the software pointer from the software list.
  for (auto Software_Pointer = List.begin(); Software_Pointer != List.end(); Software_Pointer++)
  {
    if (*Software_Pointer == this)
    {
      List.erase(Software_Pointer);
      break;
    }
  }

  this->Send_Instruction(Close);
}

///
/// @brief Function that minimize software (and maximize Shell).
///
/// @param Software_Handle Software's handle to minimize.
void Software_Class::Minimize()
{
 
  Task_Type::Delay(20);
  Maximized_Software = NULL;
  List[0]->Maximize();
}

///
/// @brief Function that maximize software (and minimize current maximized software).
///
/// @param Software_Handle Software handle to maximize.
void Software_Class::Maximize()
{
  this->Send_Instruction(Maximize);
  Task_Type::Delay(20);
}

///
/// @brief Construct a new Xila_Class::Software object
///
/// @param Software_Handle Current software handle
/// @param Queue_Size Instructions queue size (default : )
Software_Class::Software_Class(uint8_t Queue_Size) : Module_Class(Queue_Size)
{
  List.push_back(this);
  
}

///
/// @brief Destroy the Xila_Class::Software object
///
Software_Class::~Software_Class() // Destructor : close
{
}



