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
#include "Core/Log/Log.hpp"

using namespace Xila_Namespace;

Softwares_Type Xila_Namespace::Softwares;

Result_Type Softwares_Class::Start()
{
    // - Start shell
    Log_Verbose("Softwares", "Starting shell");

    Static_String_Type<24> Shell_Name("Shell");

    Log_Verbose("Softwares", "Starting shell: %s", (const char*)Shell_Name);

    return this->Open(Shell_Name, Accounts.Get_Logged_User());
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
    return Result_Type::Success;
}

Result_Type Softwares_Class::Open(const Software_Handle_Type *Handle, const Accounts_Types::User_Type *Owner_User)
{
    if (Handle == NULL)
    {
        return Result_Type::Error;
    }
    Handle->Create_Instance();
    if (Owner_User == NULL)
    {
        Software_Type::List.back()->Owner_User = Accounts.Get_Logged_User();
    }
    else
    {
        Software_Type::List.back()->Owner_User = Owner_User;
    }

    return Result_Type::Success;
}

Result_Type Softwares_Class::Open(const String_Type &Name, const Accounts_Types::User_Type *Owner_User)
{
    Log_Verbose("Softwares", "Opening software: %s", (const char*)Name);
    
    const Software_Handle_Type *Handle = this->Find_Handle(Name);
   
    Log_Verbose("Softwares", "Software handle: %p", Handle);
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
    return Result_Type::Success;
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

Software_Handle_Type *Softwares_Class::Find_Handle(const String_Type &Name)
{
    Log_Verbose("Softwares", "Searching for software handle: %s", (const char*)Name);
    Log_Verbose("Softwares", "Software handle list size: %u", this->Get_Handle_Count());
    
    Static_String_Type<Default_Software_Name_Length> Software_Name;
    
    for (auto &Software_Handle_Pointer : Software_Handle_Class::List)
    {
        if (Software_Handle_Pointer == NULL)
            break;

        Log_Verbose("Softwares", "Software handle: %p", *Software_Handle_Pointer);
        Software_Handle_Pointer->Get_Name(Software_Name);

        Log_Verbose("Softwares", "Software name: %s", (const char*)Software_Name);

        if (Software_Name == Name)
        {
            Log_Verbose("Softwares", "Software handle found: %s", (const char*)Software_Name);
            return Software_Handle_Pointer;
        }
    }
    return NULL;
}

const Software_Handle_Type *Softwares_Class::Get_Handle(uint8_t Index)
{
    if (Index >= Software_Handle_Class::List.size())
    {
        return NULL;
    }

    return Software_Handle_Class::List[Index];
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
    uint8_t i = 0;
    for (auto Software_Handle_Pointer : Software_Handle_Class::List)
    {
        if (Software_Handle_Pointer == NULL)
            return i;

        i++;
    }
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
