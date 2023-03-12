///
/// @file Software_Handle.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Software/Software_Handle.hpp"

using namespace Xila_Namespace;

std::list<Software_Handle_Class *> Software_Handle_Class::List(10);

// Software handle

/// @brief Construct and define a new Software_Handle::Software_Handle object
///
/// @param Software_Name Software name
/// @param Icon_ID Software icon
/// @param Load_Function_Pointer Load function pointer
/// @param Startup_Function_Pointer Startup function pointer (NULL by default)
Software_Handle_Class::Software_Handle_Class(const String_Type& Software_Name)
    : Name(Name)
{
  List.push_back(this);
}

Software_Handle_Class::~Software_Handle_Class()
{
      List.remove(this);
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

void Software_Handle_Class::Get_Name(String_Type& Name) const
{
  Name = this->Name;
}

void Software_Handle_Class::Create_Instance() const
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