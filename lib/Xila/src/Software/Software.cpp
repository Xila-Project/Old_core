///
/// @file Software.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

#include "Software/Software.hpp"
#include "Account/Accounts.hpp"
#include "Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Softwares_Types;

std::vector<Software_Class *> Software_Class::List;

/// @brief Construct a new Xila_Class::Software object
///
/// @param Software_Handle Current software handle
/// @param Queue_Size Instructions queue size (default : )
Software_Class::Software_Class(const Software_Handle_Type& Handle_Pointer, const Accounts_Types::User_Type* Owner_User, Size_Type Main_Task_Stack_Size, Size_Type Queue_Size)
    : Module_Class(Queue_Size),
      Main_Task(this, Start_Main_Task_Function, (const char*)Handle_Pointer.Name, Main_Task_Stack_Size, this),
      Handle_Pointer(Handle_Pointer),
      Owner_User(Owner_User)
{
  if (Handle_Pointer == NULL || Owner_User == NULL)
  {
    delete this;
    return;
  }
  
  List.reserve(10);
  List.push_back(this); // Add software to the list.
}

/// @brief Destroy the Xila_Class::Software object
Software_Class::~Software_Class() // Destructor : close
{
  // Don't forget to remove the software pointer from the software list.
  List.erase(std::remove(List.begin(), List.end(), this), List.end());

  // Delete the main task of software at the end to allow the software to close itself.
  Main_Task.Delete();
}

/// @brief Start a software main task.
///
/// @param Instance_Pointer
void Software_Class::Start_Main_Task_Function(void *Instance_Pointer)
{
  // TODO : Find another way to wait for the constructor to initialize virtual functions -> not safe
  static_cast<Software_Class*>(Instance_Pointer)->Main_Task.Delay(50);  // Wait for the constructor to initialize virtual functions.
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
  return &this->Handle_Pointer;
}

const Accounts_Types::User_Type* Software_Class::Get_Owner_User() const
{
  return this->Owner_User;
}
