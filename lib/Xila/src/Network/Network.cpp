/// @file Communication.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 24-04-2023
///
/// @copyright Copyright (c) 2023

#include "Network/Network.hpp"
#include "Log/Log.hpp"

// - Namespaces

using namespace Xila_Namespace;
using namespace Xila_Namespace::Network_Types;

// - Variable

Network_Type Xila_Namespace::Network;

// - Methods

Result_Type Network_Class::Start()
{
    Log_Information("WiFi", "Start Communication module...");

    Result_Type Result = Result_Type::Success;

    Interface_Type* Interface_Pointer = Interface_Type::First_Instance_Pointer;

    while (Interface_Pointer)
    {
        if (Interface_Pointer->Start() != Result_Type::Success)
            Result = Result_Type::Error;

        Interface_Pointer = Interface_Pointer->Next_Instance_Pointer;
    }

    return Result;
}

Result_Type Network_Class::Stop()
{
    Result_Type Result = Result_Type::Success;

    Interface_Type* Interface_Pointer = Interface_Type::First_Instance_Pointer;

    while (Interface_Pointer)
    {
        if (Interface_Pointer->Start() != Result_Type::Success)
            Result = Result_Type::Error;
        
        Interface_Pointer = Interface_Pointer->Next_Instance_Pointer;
    }

    return Result;
}

Interface_Type* Network_Class::Get_Interface(Natural_Type Index)
{
    Interface_Type* Interface_Pointer = Interface_Class::First_Instance_Pointer;
    while (Index-- && Interface_Pointer)
    {
        Interface_Pointer = Interface_Pointer->Next_Instance_Pointer;
    }
    return Interface_Pointer;
}

Natural_Type Network_Class::Get_Interface_Count()
{
    Natural_Type Count = 0;
    Interface_Type* Interface_Pointer = Interface_Class::First_Instance_Pointer;
    while (Interface_Pointer)
    {
        Count++;
        Interface_Pointer = Interface_Pointer->Next_Instance_Pointer;
    }
    return Count;
}

Interface_Type* Network_Class::Get_Connected_Interface(Natural_Type Index)
{
    Interface_Type* Interface_Pointer = Interface_Class::First_Instance_Pointer;

    while (Index-- && Interface_Pointer)
    {
        Interface_Pointer = Interface_Pointer->Next_Instance_Pointer;

        while (Interface_Pointer->Get_State() != State_Type::Connected && Interface_Pointer)
        {
            Interface_Pointer = Interface_Pointer->Next_Instance_Pointer;
        }
    }

    return Interface_Pointer;
}

Natural_Type Network_Class::Get_Connected_Interface_Count()
{
    Natural_Type Count = 0;
    Interface_Type* Interface_Pointer = Interface_Class::First_Instance_Pointer;
    while (Interface_Pointer)
    {
        if (Interface_Pointer->Get_State() == State_Type::Connected)
            Count++;

        Interface_Pointer = Interface_Pointer->Next_Instance_Pointer;
    }
    return Count;
}

Result_Type Network_Class::Set_Host_Name(const char* Host_Name)
{
    Result_Type Result = Result_Type::Success;
    Interface_Type* Interface_Pointer = Interface_Class::First_Instance_Pointer;
    while (Interface_Pointer)
    {
        if (Interface_Pointer->Set_Host_Name(Host_Name) != Result_Type::Success)
            Result = Result_Type::Error;

        Interface_Pointer = Interface_Pointer->Next_Instance_Pointer;
    }
    return Result;
}

String_Type& Network_Class::Get_Host_Name(String_Type& Host_Name)
{
    if (Interface_Class::First_Instance_Pointer)
        return Interface_Class::First_Instance_Pointer->Get_Host_Name(Host_Name);
    
    return Host_Name;
}