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

Result_Type Softwares_Class::Open(Software_Handle_Type* Handle)
{
    if (Handle == NULL)
    {
        return Result_Type::Error;
    }
    else
    {
        return Handle->Create_Instance();
    }
}

Result_Type Softwares_Class::Open(String_Type& Name)
{
    for (auto & Software_Handle : this->Get_Handle_List())
    {
        if (Software_Handle->Get_Name() == Name)
        {
            return Software_Handle->Create_Instance();
        }
    }
    return Result_Type::Error;
}

/// @brief 
/// @param Software 
/// @param Timeout 
/// @return 
Result_Type Softwares_Class::Close(Software_Type* Software)
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

Result_Type Softwares_Class::Kill(Software_Type* Software)
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

const std::vector<Software_Handle_Type*> Softwares_Class::Get_Handle_List()
{
    return Software_Handle_Class::List;
}

const std::vector<Software_Type*> Softwares_Class::Get_List()
{
    return Software_Class::List;
}

Result_Type Softwares_Class::Start()
{
    // - Start shell

    for (auto& Software_Handle_Pointer : this->Get_Handle_List())
    {
        if (Software_Handle_Pointer->Get_Name())
    }

}

Result_Type Softwares_Class::Stop()
{
    for (auto & Software_Pointer : Softwares.Get_List())
    {
        this->Close(Software_Pointer);
    }

    uint32_t Timeout = System.Get_Up_Time_Milliseconds() + 10000;

    while (this->Get_List().size() != 0)
    {
        Task_Type::Delay_Static(100);
    }

    for (auto & Software_Pointer : Softwares.Get_List())
    {
        this->Kill(Software_Pointer);
    }



}