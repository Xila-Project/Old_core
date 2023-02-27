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

Result_Type Softwares_Class::Open(const Software_Handle_Type *Handle)
{
    if (Handle == NULL)
    {
        return Result_Type::Error;
    }
    Handle->Create_Instance();
    return Result_Type::Success;
}

Result_Type Softwares_Class::Open(const String_Type &Name)
{
    const Software_Handle_Type *Handle = this->Find_Handle(Name);
    if (Handle == NULL)
    {
        return Result_Type::Error;
    }
    return this->Open(Handle);
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
        delete Software;
    }
}

const std::vector<Software_Handle_Type *> Softwares_Class::Get_Handle_List()
{
    return Software_Handle_Class::List;
}

const std::vector<Software_Type *> Softwares_Class::Get_List()
{
    return Software_Class::List;
}

Result_Type Softwares_Class::Start()
{
    // - Start shell
    Static_String_Type<Default_Software_Name_Length> Software_Name;
    for (auto &Software_Handle_Pointer : this->Get_Handle_List())
    {
        Software_Handle_Pointer->Get_Name(Software_Name);
        if (Software_Name == "Shell")
        {
            return this->Open(Software_Handle_Pointer);
        }
    }
}

Result_Type Softwares_Class::Stop()
{
    for (auto &Software_Pointer : Softwares.Get_List())
    {
        this->Close(Software_Pointer);
    }

    uint32_t Timeout = System.Get_Up_Time_Milliseconds() + 10000;

    while (this->Get_List().size() != 0)
    {
        Task_Type::Delay_Static(100);
    }

    for (auto &Software_Pointer : Softwares.Get_List())
    {
        this->Kill(Software_Pointer);
    }
}

const Software_Handle_Type *Softwares_Class::Find_Handle(const String_Type &Name)
{
    Static_String_Type<Default_Software_Name_Length> Software_Name;
    for (auto &Software_Handle_Pointer : this->Get_Handle_List())
    {
        Software_Handle_Pointer->Get_Name(Software_Name);
        if (Software_Name == Name)
        {
            return Software_Handle_Pointer;
        }
    }
    return NULL;
}