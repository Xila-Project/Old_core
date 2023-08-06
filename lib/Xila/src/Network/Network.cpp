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

    Interface_Type* Interface_Pointer = Interface_Type::First_Instance_Pointer;

    while (Interface_Pointer)
    {
        Interface_Pointer->Start(); 

        Interface_Pointer = Interface_Pointer->Next_Instance_Pointer;
    }


    if (WiFi.Start() == Result_Type::Success)
        return Result_Type::Success;

    return Result_Type::Error;
}

Result_Type Network_Class::Stop()
{
    if (WiFi.Stop() == Result_Type::Success)
        return Result_Type::Success;

    return Result_Type::Error;
}

Interface_Type* Network_Class::Get_Interface(Natural_Type Index)
{
    Interface_Type* Interface_Pointer = Interface_Class::First_Instance_Pointer;
    while (Index--)
    {
        Interface_Pointer = Interface_Pointer->Next_Instance_Pointer;
    }
    return Interface_Pointer;
}

Interface_Type* Network_Class::Get_Connected_Interface(Natural_Type Index)
{
    Interface_Type* Interface_Pointer = Interface_Class::First_Instance_Pointer;

    for (Natural_Type i = 0; i < Index; i++)
    {
        Interface_Pointer = Interface_Pointer->Next_Instance_Pointer;
        // Skip if not connected
        while (Interface_Pointer->Get_Status() != Interface_Status::Connected)
        {
            Interface_Pointer = Interface_Pointer->Next_Instance_Pointer;
        }
    }

    return Interface_Pointer;
}
