///
/// @file Softwares.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 25-02-2023
///
/// @copyright Copyright (c) 2023
///

#include "Core/Software/Softwares.hpp"
#include "Core/System/System.hpp"

using namespace Xila_Namespace;

Softwares_Type Softwares;

Result_Type Softwares_Class::Start()
{
    // - Start shell
    this->Open("Shell", Accounts.Get_Logged_User());
}

Result_Type Softwares_Class::Stop()
{
    for (auto &Software_Pointer : Software_Class::List)
    {
        this->Close(Software_Pointer);
    }

    uint32_t Timeout = System.Get_Up_Time_Milliseconds() + 10000;

    while (Software_Class::List.size() != 0 && System.Get_Up_Time_Milliseconds() < Timeout)
    {
        Task_Type::Delay_Static(100);
    }

    for (auto &Software_Pointer : Software_Class::List)
    {
        this->Kill(Software_Pointer);
    }
}

Result_Type Softwares_Class::Open(const Software_Handle_Type *Handle, const Accounts_Types::User_Type *Owner_User)
{
    if (Handle == NULL)
    {
        return Result_Type::Error;
    }
    Software_Type* Software_Pointer = Handle->Create_Instance();
    if (Owner_User == NULL)
    {
        Software_Pointer->Owner_User = Accounts.Get_Logged_User();
    }
    else
    {
        Software_Pointer->Owner_User = Owner_User;
    }
    
    return Result_Type::Success;
}

Result_Type Softwares_Class::Open(const String_Type &Name, const Accounts_Types::User_Type *Owner_User)
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
    if (Software == NULL)
    {
        return Result_Type::Error;
    }
    else
    {
        Instruction_Type Instruction(this, Software);
        Instruction.Softwares.Set_Code(Softwares_Types::Event_Code_Type::Close);
        return Software->Send_Instruction(Instruction);
    }
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
}

Software_Type* Softwares_Class::Find(const Software_Handle_Type *Handle)
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

Software_Handle_Type *Softwares_Class::Find_Handle(const String_Type &Name)
{
    Static_String_Type<Default_Software_Name_Length> Software_Name;
    for (auto &Software_Handle_Pointer : Software_Handle_Class::List)
    {
        Software_Handle_Pointer->Get_Name(Software_Name);
        if (Software_Name == Name)
        {
            return Software_Handle_Pointer;
        }
    }
    return NULL;
}

const Software_Handle_Type* Softwares_Class::Get_Handle(uint8_t Index)
{
    if (Index < Software_Handle_Class::List.size())
    {
        return Software_Handle_Class::List[Index];
    }
        return NULL;
}

Software_Type* Softwares_Class::Get(uint8_t Index)
{
    if (Index < Software_Class::List.size())
    {
        return Software_Class::List[Index];
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

void Softwares_Class::Kill_User_Softwares(const Accounts_Types::User_Type* User)
{
    for (auto& Software_Pointer : Software_Class::List)
    {
        if (Software_Pointer->Get_Owner_User() == User)
        {
            this->Kill(Software_Pointer);
        }
    }
}

void Softwares_Class::Send_Instruction_User_Softwares(const Accounts_Types::User_Type* User, const Instruction_Type& Instruction)
{
    for (auto& Software_Pointer : Software_Class::List)
    {
        if (Software_Pointer->Get_Owner_User() == User)
        {
            Software_Pointer->Send_Instruction(Instruction);
        }
    }
}

uint8_t Softwares_Class::Get_User_Softwares_Count(const Accounts_Types::User_Type* User)
{
    uint8_t Count = 0;
    for (auto& Software_Pointer : Software_Class::List)
    {
        if (Software_Pointer->Get_Owner_User() == User)
        {
            Count++;
        }
    }
    return Count;
}

void Softwares_Class::Send_Instruction_Softwares(const Instruction_Type& Instruction)
{
    Instruction_Type Copy_Instruction = Instruction;
    for (auto& Software_Pointer : Software_Class::List)
    {
        Copy_Instruction.Set_Receiver(Software_Pointer));   
        Software_Pointer->Send_Instruction(Copy_Instruction);
    }
}

