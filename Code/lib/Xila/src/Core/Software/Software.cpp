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

#include "Core/Account/Accounts.hpp"

using namespace Xila_Namespace;

std::list<Software_Class *> Software_Class::List;

/// @brief Construct a new Xila_Class::Software object
///
/// @param Software_Handle Current software handle
/// @param Queue_Size Instructions queue size (default : )
Software_Class::Software_Class(const Software_Handle_Type *Handle_Pointer, Size_Type Main_Task_Stack_Size, Size_Type Queue_Size)
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
  List.remove(this);
 
  // Delete the main task of software at the end to allow the software to close itself.
  Main_Task.Delete();
}

/// @brief Start a software main task.
///
/// @param Instance_Pointer
void Software_Class::Start_Main_Task_Function(void *Instance_Pointer)
{
  static_cast<Software_Class*>(Instance_Pointer)->Main_Task_Function();
}

/// @brief 
void Software_Class::Main_Task_Function()
{
  // If no function is defined, the software will be closed.
  delete this;
}

const Software_Handle_Type* Software_Class::Get_Handle() const
{
  return this->Handle_Pointer;
}

const Accounts_Types::User_Type* Software_Class::Get_Owner_User() const
{
  return this->Owner_User;
}
