///
/// @file Instruction.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 13-11-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Module/Instruction.hpp"

#include "Core/Core.hpp"

using namespace Xila_Namespace;

// - Instruction class

Instruction_Class::Instruction_Class(Module_Class *Sender, Module_Class *Receiver)
    : Sender(Sender),
      Receiver(Receiver)
{
}

Instruction_Class::Instruction_Class()
    : Sender(NULL),
      Receiver(NULL)
{
}

Module_Class *Instruction_Class::Get_Sender() const
{
    return Sender;
}

Module_Class *Instruction_Class::Get_Receiver() const
{
    return Receiver;
}

void Instruction_Class::Set_Sender(Module_Class *Sender)
{
    this->Sender = Sender;
}

void Instruction_Class::Set_Receiver(Module_Class *Receiver)
{
    this->Receiver = Receiver;
}

// - Graphics class

// - - Constructor

Instruction_Class::Graphics_Class::Graphics_Class() : Object_Pointer(NULL)
{
}

void Instruction_Class::Graphics_Class::Set_Code(Graphics_Types::Event_Code_Type Code)
{
    this->Code = Code;
}

void Instruction_Class::Graphics_Class::Set_Object(Object_Type Object)
{
    Object_Pointer = Object.Get_Pointer();
}

Graphics_Types::Event_Code_Type Instruction_Class::Graphics_Class::Get_Code() const
{
    return Code;
}

Object_Type Instruction_Class::Graphics_Class::Get_Object() const
{
    Object_Type Object(static_cast<lv_obj_t *>(Object_Pointer));
    return Object;
}
