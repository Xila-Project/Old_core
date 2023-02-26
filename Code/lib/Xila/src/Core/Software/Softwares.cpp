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
