///
/// @file Software.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.2
/// @date 11-07-2021
///
/// @copyright Copyright (c) 2021
///

#ifndef Software_HPP_INCLUDED
#define Software_HPP_INCLUDED

inline uint8_t Xila_Class::Software_Management_Class::Seek_Open_Software_Handle(Xila_Class::Software_Handle const &Software_Handle)
{
  for (uint8_t i = 1; i <= 8; i++)
  {
    if (i < 8 && *Openned[i]->Handle == Software_Handle)
    {
      return i;
    }
    else if (i == 8)
    {
      return 0;
    }
  }
}

// -- Shell shortcut -- //

inline void Xila_Class::Software_Management_Class::Shell_Set_Variable(Xila_Class::Address Address, uint8_t Type, const void *Variable)
{
  Openned[1]->Set_Variable(Address, Type, Variable);
}

inline void Xila_Class::Software_Management_Class::Shell_Send_Instruction(Xila_Class::Instruction Instruction)
{
  Openned[1]->Send_Instruction(Instruction);
}

#endif