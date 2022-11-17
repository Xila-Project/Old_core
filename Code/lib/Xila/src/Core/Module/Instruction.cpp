///
/// @file Instruction.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 13-11-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Module.hpp"

#include "Core/Core.hpp"

using namespace Xila_Namespace;

const Module_Class::Instruction_Class Module_Class::Instruction_Class::Open(NULL, NULL, "Open");
const Module_Class::Instruction_Class Module_Class::Instruction_Class::Close(NULL, NULL, "Clos");
const Module_Class::Instruction_Class Module_Class::Instruction_Class::Active(NULL, NULL, "Activ");
const Module_Class::Instruction_Class Module_Class::Instruction_Class::Inactive(NULL, NULL, "Inac");
const Module_Class::Instruction_Class Module_Class::Instruction_Class::Minimize(NULL, NULL, "Mini");
const Module_Class::Instruction_Class Module_Class::Instruction_Class::Maximize(NULL, NULL, "Maxi");

Module_Class::Instruction_Class::Instruction_Class(Module_Class *Sender, Module_Class *Receiver, uint32_t Arguments)
    : Sender(Sender),
      Receiver(Receiver),
      Arguments(Arguments){};

Module_Class::Instruction_Class::Instruction_Class()
    : Sender(NULL),
      Receiver(NULL),
      Arguments(0){};

Module_Class::Instruction_Class::Instruction_Class(Module_Class* Sender, Module_Class* Receiver, const char* Arguments)
    : Sender(Sender),
      Receiver(Receiver)
{
    memcpy(&this->Arguments, Arguments, sizeof(this->Arguments));
}

Module_Class* Module_Class::Instruction_Class::Get_Sender() const
{
    return Sender;
}

Module_Class* Module_Class::Instruction_Class::Get_Receiver() const
{
    return Receiver;
}

uint32_t Module_Class::Instruction_Class::Get_Arguments() const
{
    return Arguments;
}

void Module_Class::Instruction_Class::Set_Sender(Module_Class* Sender)
{
    this->Sender = Sender;
}

void Module_Class::Instruction_Class::Set_Receiver(Module_Class* Receiver)
{
    this->Receiver = Receiver;
}

void Module_Class::Instruction_Class::Set_Arguments(const char* Arguments)
{
    memcpy(&this->Arguments, Arguments, sizeof(Arguments));
}