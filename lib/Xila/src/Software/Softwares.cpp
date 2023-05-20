///
/// @file Softwares.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 25-02-2023
///
/// @copyright Copyright (c) 2023
///

#include "Software/Softwares.hpp"
#include "System/System.hpp"
#include "Log/Log.hpp"
#include <iterator>

using namespace Xila_Namespace;
using namespace Softwares_Types;

Softwares_Type Xila_Namespace::Softwares;

Result_Type Softwares_Class::Start()
{
    Static_String_Type<24> Shell_Name("Shell");
    return this->Open(Shell_Name);
}

Result_Type Softwares_Class::Stop()
{
    // - Close all software
    for (auto &Software_Pointer : Software_Class::List)
    {
        this->Close(Software_Pointer);
    }

    uint32_t Timeout = System.Get_Up_Time_Milliseconds() + 10000;

    // - Wait for all software to close
    while (Software_Class::List.size() != 0 && System.Get_Up_Time_Milliseconds() < Timeout)
    {
        Task_Type::Delay_Static(100);
    }

    // - Kill all remaining software
    for (auto &Software_Pointer : Software_Class::List)
    {
        this->Kill(Software_Pointer);
    }
    return Result_Type::Success;
}

Result_Type Softwares_Class::Open(const Software_Handle_Type *Handle, const Accounts_Types::User_Type *Owner_User)
{
    // - Check if handle is valid
    if (Handle == NULL)
    {
        return Result_Type::Error;
    }

    if (Owner_User == NULL)
    {
        Owner_User = Accounts.Get_Logged_User();
        if (Owner_User == NULL)
            return Result_Type::Error;
    }

    Handle->Create_Instance(Owner_User);

    Software_Type::List.back()->Owner_User = Owner_User;

    return Result_Type::Success;
}

Result_Type Softwares_Class::Open(const char *Name, const Accounts_Types::User_Type *Owner_User)
{
    const Software_Handle_Type *Handle = this->Find_Handle(Name);
 
    return this->Open(Handle, Owner_User);
}

/// @brief
/// @param Software
/// @param Timeout
/// @return
Result_Type Softwares_Class::Close(Software_Type *Software)
{
    if (!Software)
        return Result_Type::Error;
    Instruction_Type Instruction(this, Software);
    Instruction.Softwares.Set_Code(Event_Code_Type::Close);
    return Software->Send_Instruction(Instruction);
}

Result_Type Softwares_Class::Kill(Software_Type *Software)
{
    if (Software == NULL)
    {
        return Result_Type::Error;
    }
    else
    {
        Task_Type::Delete_Module_Tasks(Software);
        delete Software;
    }
    return Result_Type::Success;
}

void Softwares_Class::Register_Handle(Softwares_Types::Software_Handle_Type &Software_Handle)
{
    Software_Handle_Class::List.push_back(&Software_Handle);
}

Software_Type *Softwares_Class::Find(const Software_Handle_Type *Handle)
{
    for (auto &Software_Pointer : Software_Class::List)
    {
        if (Software_Pointer->Get_Handle() == Handle)
        {
            return Software_Pointer;
        }
    }
    return NULL;
}

Software_Handle_Type *Softwares_Class::Find_Handle(const char *Name)
{
    Static_String_Type<Default_Software_Name_Length> Software_Name;

    for (auto Software_Handle : Software_Handle_Class::List)
    {
        if (Software_Handle == NULL)
            break;

        Software_Handle->Get_Name(Software_Name);

        if (Software_Name == Name)
        {
            return Software_Handle;
        }
    }
    return NULL;
}

const Software_Handle_Type *Softwares_Class::Get_Handle(Size_Type Index)
{
    if (Index >= Software_Handle_Class::List.size())
        return NULL;

    return *std::next(Software_Handle_Class::List.begin(), Index);
}

Software_Type *Softwares_Class::Get(uint8_t Index)
{
    uint8_t i = 0;
    for (auto &Software_Pointer : Software_Class::List)
    {
        if (i == Index)
        {
            return Software_Pointer;
        }
        i++;
    }
    return NULL;
}

uint8_t Softwares_Class::Get_Count()
{
    return Software_Class::List.size();
}

uint8_t Softwares_Class::Get_Handle_Count()
{
    return Software_Handle_Class::List.size();
}

void Softwares_Class::Close_User_Softwares(const Accounts_Types::User_Type *User)
{
    for (auto &Software_Pointer : Software_Class::List)
    {
        if (Software_Pointer->Get_Owner_User() == User)
        {
            this->Close(Software_Pointer);
        }
    }
}

void Softwares_Class::Kill_User_Softwares(const Accounts_Types::User_Type *User)
{
    for (auto &Software_Pointer : Software_Class::List)
    {
        if (Software_Pointer->Get_Owner_User() == User)
        {
            this->Kill(Software_Pointer);
        }
    }
}

void Softwares_Class::Send_Instruction_User_Softwares(const Accounts_Types::User_Type *User, const Instruction_Type &Instruction)
{
    for (auto &Software_Pointer : Software_Class::List)
    {
        if (Software_Pointer->Get_Owner_User() == User)
        {
            Software_Pointer->Send_Instruction(Instruction);
        }
    }
}

uint8_t Softwares_Class::Get_User_Softwares_Count(const Accounts_Types::User_Type *User)
{
    uint8_t Count = 0;
    for (auto &Software_Pointer : Software_Class::List)
    {
        if (Software_Pointer->Get_Owner_User() == User)
        {
            Count++;
        }
    }
    return Count;
}

const Software_Type *Softwares_Class::Get_User_Softwares(const Accounts_Types::User_Type *User, uint8_t Index)
{
    uint8_t Count = 0;
    for (auto &Software_Pointer : Software_Class::List)
    {
        if (Software_Pointer->Get_Owner_User() == User)
        {
            if (Count == Index)
            {
                return Software_Pointer;
            }
            Count++;
        }
    }
    return NULL;
}

void Softwares_Class::Send_Instruction_Softwares(const Instruction_Type &Instruction)
{
    Instruction_Type Copy_Instruction = Instruction;
    for (auto &Software_Pointer : Software_Class::List)
    {
        Copy_Instruction.Set_Receiver(Software_Pointer);
        Software_Pointer->Send_Instruction(Copy_Instruction);
    }
}
