/// @file Communication.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 24-04-2023
///
/// @copyright Copyright (c) 2023

#include "Communication/Communication.hpp"
#include "Log/Log.hpp"

// - Namespaces

using namespace Xila_Namespace;
using namespace Xila_Namespace::Communication_Types;

// - Variable

Communication_Type Xila_Namespace::Communication;

// - Methods

Result_Type Communication_Class::Start()
{
    Log_Information("WiFi", "Start Communication module...");
    if (WiFi.Start() == Result_Type::Success)
        return Result_Type::Success;

    return Result_Type::Error;
}

Result_Type Communication_Class::Stop()
{
    if (WiFi.Stop() == Result_Type::Success)
        return Result_Type::Success;

    return Result_Type::Error;
}