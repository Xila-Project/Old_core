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

std::vector<Software_Class *> Software_Class::List(10);


///
/// @brief Construct a new Xila_Class::Software object
///
/// @param Software_Handle Current software handle
/// @param Queue_Size Instructions queue size (default : )
Software_Class::Software_Class(Software_Handle_Type *Handle_Pointer, Size_Type Main_Task_Stack_Size, Size_Type Queue_Size)
    : Module_Class(Queue_Size),
      Main_Task(this, Start_Main_Task_Function, "Software", Main_Task_Stack_Size, this),
      Handle_Pointer(Handle_Pointer)
{
  List.push_back(this); // Add software to the list.
}

/// @brief Destroy the Xila_Class::Software object
Software_Class::~Software_Class() // Destructor : close
{
  // Don't forget to remove the software pointer from the software list.
  for (auto Software_Pointer = List.begin(); Software_Pointer != List.end(); Software_Pointer++)
  {
    if (*Software_Pointer == this)
    {
      List.erase(Software_Pointer);
      break;
    }
  }
}

/// @brief Start a software main task.
///
/// @param Instance_Pointer
void Software_Class::Start_Main_Task_Function(void *Instance_Pointer)
{
  Software_Class* Local_Instance_Pointer = (Software_Class*)Instance_Pointer;
  Local_Instance_Pointer->Main_Task_Function();
}

///
/// @brief Function that close software.
///
void Software_Class::Close()
{
  Instruction_Type Instruction(this, this);
  Instruction.Software.Set_Code((uint8_t)Event_Code_Type::Close);
}

void Software_Class::Main_Task_Function()
{
  // If no function is defined, the software will be closed.
  Close();
}
