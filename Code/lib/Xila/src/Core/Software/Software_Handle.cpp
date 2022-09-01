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

std::vector<Software_Handle_Class *> Software_Handle_Class::Software_Handle_List;

// Software handle

///
/// @brief Construct a new Software_Handle::Software_Handle object
///
Software_Handle_Class::Software_Handle_Class()
    : Create_Instance_Pointer(NULL)
{
  memset(Name, '\0', sizeof(Name));
  Software_Handle_List.push_back(this);
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
  Software_Handle_List.push_back(this);
}

Software_Handle_Class::Result::Type Software_Handle_Class::Create_Instance()
{
  if (Create_Instance_Pointer == NULL)
  {
    return Result::Error;
  }
  else
  {
    Create_Instance_Pointer();
    return Result::Success;
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

///
/// @brief Function that open software.
///
/// @param Software_Handle Software's handle to open.
/// @return Result::Type
Module_Class::Result::Type Software_Class::Open(Software_Handle const &Software_Handle)
{
  if (Software_Handle == Shell_Handle)
  {
    if (Openned[1] != NULL)
    {
      Maximize(Shell_Handle);
      return Result::Success;
    }
    else
    {
      Openned[1] = (*Shell_Handle.Load_Function_Pointer)();
      Openned[0] = Openned[1];
      return Result::Success;
    }
  }

  uint8_t i = 2;
  // -- checking if software is already openned
  for (i = 2; i < 8; i++)
  {
    if (Openned[i] != NULL)
    {
      if (Software_Handle == *Openned[i]->Handle)
      {
        Maximize(*Openned[i]->Handle);
        return Result::Success;
      }
    }
  }
  // -- if the software isn't minimized, load it. -- //
  for (i = 2; i < 8; i++)
  {
    if (Openned[i] == NULL)
    {
      if (Software_Handle.Load_Function_Pointer == NULL)
      {
        return Result::Error;
      }

      Openned[i] = (*Software_Handle.Load_Function_Pointer)(); // <- at this point Openned[1] to be modified

      if (Openned[i]->Instruction_Queue_Handle == NULL)
      {
        vTaskDelete(Openned[i]->Task_Handle);
        delete Openned[i];
        Openned[i] = NULL;
        return Result::Error;
      }

      Openned[0] = Openned[i];

      return Result::Success;
    }
  }
  return Result::Error;
}

///
/// @brief Destroy the Software_Handle::Software_Handle object
///
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