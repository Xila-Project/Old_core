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

std::vector<Software_Handle_Class *> Software_Handle_Class::List(10);

// Software handle

///
/// @brief Construct a new Software_Handle::Software_Handle object
///
Software_Handle_Class::Software_Handle_Class()
    : Create_Instance_Pointer(NULL)
{
  memset(Name, '\0', sizeof(Name));
  List.push_back(this);
}

///
/// @brief Construct and define a new Software_Handle::Software_Handle object
///
/// @param Software_Name Software name
/// @param Icon_ID Software icon
/// @param Load_Function_Pointer Load function pointer
/// @param Startup_Function_Pointer Startup function pointer (NULL by default)
Software_Handle_Class::Software_Handle_Class(const char *Software_Name, void (*Load_Function_Pointer)())
    : Create_Instance_Pointer(Load_Function_Pointer)
{
  memset(Name, '\0', sizeof(Name));
  strlcpy(Name, Software_Name, sizeof(Name));
  List.push_back(this);
}

Software_Handle_Class::Result_Type Software_Handle_Class::Create_Instance()
{
  if (Create_Instance_Pointer == NULL)
  {
    return Result_Type::Error;
  }
  else
  {
    Create_Instance_Pointer();
    return Result_Type::Success;
  }
}

///
/// @brief Compare a software handle with this object.
///
/// @param Software_Handle_To_Compare Software handle to compare
/// @return true if software handle are identical
/// @return false if software handle are different
bool Software_Handle_Class::Is_Equal(Software_Handle_Class const &Software_Handle_To_Compare) const
{
  if ((strcmp(Name, Software_Handle_To_Compare.Name)) != 0 || (Software_Handle_To_Compare.Create_Instance_Pointer != Create_Instance_Pointer))
  {
    return false;
  }
  return true;
}

const char* Software_Handle_Class::Get_Name() const
{
  return Name;
}

Software_Handle_Class::Create_Instance_Function_Pointer Software_Handle_Class::Get_Pointer_Create_Instance() const
{
  return Create_Instance_Pointer;
}

///
/// @brief Compare two software handle.
///
/// @param a 1st software handle to compare.
/// @param b 2nd software handle to compare.
/// @return true if software handle are identical
/// @return false if software handle are different
bool operator==(Software_Handle_Class const &a, Software_Handle_Class const &b)
{
  return a.Is_Equal(b);
}