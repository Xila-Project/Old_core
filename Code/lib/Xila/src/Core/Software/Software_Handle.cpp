/// @file Software_Handle.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021

#include "Core/Software/Software_Handle.hpp"
#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Softwares_Types;

std::list<Software_Handle_Class*> Software_Handle_Class::List;

/// @brief Construct and define a new Software_Handle::Software_Handle object
///
/// @param Software_Name Software name
/// @param Icon_ID Software icon
/// @param Load_Function_Pointer Load function pointer
/// @param Startup_Function_Pointer Startup function pointer (NULL by default)
Software_Handle_Class::Software_Handle_Class(const char* Name)
    : Name(Name)
{
 // Log_Verbose("Software", "Software handle constructor %s", Name);
}

Software_Handle_Class::~Software_Handle_Class()
{
}

///
/// @brief Compare a software handle with this object.
///
/// @param Software_Handle_To_Compare Software handle to compare
/// @return true if software handle are identical
/// @return false if software handle are different
bool Software_Handle_Class::Is_Equal(const Software_Handle_Class &Software_Handle) const
{
  if (Software_Handle.Name == this->Name)
  {
    return true;
  }
  return false;
}

String_Type& Software_Handle_Class::Get_Name(String_Type& Name) const
{
  Name = this->Name;
  return Name;
}

void Software_Handle_Class::Create_Instance(const Accounts_Types::User_Type* Owner_User) const
{
  // 
}

bool Software_Handle_Class::operator==(const Software_Handle_Class &Software_Handle_To_Compare) const
{
  return Is_Equal(Software_Handle_To_Compare);
}

bool Software_Handle_Class::operator!=(const Software_Handle_Class &Software_Handle_To_Compare) const
{
  return !Is_Equal(Software_Handle_To_Compare);
}