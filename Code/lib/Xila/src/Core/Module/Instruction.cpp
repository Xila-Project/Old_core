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

#include "Core/Graphics/Graphics.hpp"

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

Instruction_Class::Graphics_Class::Graphics_Class() : Target_Pointer(NULL)
{
}

// - - Setters

void Instruction_Class::Graphics_Class::Set_Code(Graphics_Types::Event_Code_Type Code)
{
    this->Code = Code;
}

void Instruction_Class::Graphics_Class::Set_Target_Pointer(Graphics_Types::Object_Type Object)
{
    Target_Pointer = Object.Get_Pointer();
}

void Instruction_Class::Graphics_Class::Set_Current_Target_Pointer(Graphics_Types::Object_Type Object)
{
    Current_Target_Pointer = Object.Get_Pointer();
}

// - - Getters

Graphics_Types::Event_Code_Type Instruction_Class::Graphics_Class::Get_Code() const
{
    return Code;
}

Graphics_Types::Object_Type Instruction_Class::Graphics_Class::Get_Target() const
{
    return Graphics_Types::Object_Type(static_cast<lv_obj_t *>(Target_Pointer));
}

Graphics_Types::Object_Type Instruction_Class::Graphics_Class::Get_Current_Target() const
{
    return Graphics_Types::Object_Type(static_cast<lv_obj_t *>(Current_Target_Pointer));
}
