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

// Software handle

///
/// @brief Construct a new Xila_Class::Software_Handle::Xila_Class::Software_Handle object
///
Xila_Class::Software_Handle::Software_Handle()
    : Icon(0),
      Load_Function_Pointer(NULL),
      Startup_Function_Pointer(NULL)
{
  memset(Name, '\0', sizeof(Name));
}

///
/// @brief Compare a software handle with this object.
///
/// @param Software_Handle_To_Compare Software handle to compare
/// @return true if software handle are identical
/// @return false if software handle are different
bool Xila_Class::Software_Handle::Is_Equal(Xila_Class::Software_Handle const &Software_Handle_To_Compare) const
{
  if (strcmp(Name, Software_Handle_To_Compare.Name) != 0)
  {
    return false;
  }
  if (Icon != Software_Handle_To_Compare.Icon)
  {
    return false;
  }
  return true;
}

///
/// @brief Construct a new Xila_Class::Software_Handle::Xila_Class::Software_Handle object
///
/// @param Software_Name Software name
/// @param Icon_ID Software icon
/// @param Load_Function_Pointer Load function pointer
/// @param Startup_Function_Pointer Startup function pointer (NULL by default)
Xila_Class::Software_Handle::Software_Handle(char const *Software_Name, uint8_t Icon_ID, Xila_Class::Software *(*Load_Function_Pointer)(), void (*Startup_Function_Pointer)())
    : Icon(Icon_ID),
      Load_Function_Pointer(Load_Function_Pointer),
      Startup_Function_Pointer(Startup_Function_Pointer)
{
  memset(Name, '\0', sizeof(Name));
  strlcpy(Name, Software_Name, sizeof(Name));
}

///
/// @brief Destroy the Xila_Class::Software_Handle::Xila_Class::Software_Handle object
///
Xila_Class::Software_Handle::~Software_Handle()
{
}

///
/// @brief Compare two software handle.
///
/// @param a 1st software handle to compare.
/// @param b 2nd software handle to compare.
/// @return true if software handle are identical
/// @return false if software handle are different
bool operator==(Xila_Class::Software_Handle const &a, Xila_Class::Software_Handle const &b)
{
  return a.Is_Equal(b);
}