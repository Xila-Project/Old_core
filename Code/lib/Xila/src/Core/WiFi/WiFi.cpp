///
/// @file WiFi.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr) - Espressif
/// @brief Xila WiFi abstraction layer source file.
/// @version 0.1.1
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021
///

#include "Core/Communication/WiFi.hpp"

WiFi_Type WiFi();

 /// @brief Construct a new WiFi_Class object
 /// 
Xila_Namespace::WiFi_Class::WiFi_Class()
{
    memset(Password, '\0', sizeof(Password));
}

/// @brief Load WiFi registry.
///
/// @return Result_Type
Module_Class::Result_Type Xila_Namespace::WiFi_Class::Load_Registry()
{
    File Temporary_File = Drive.Open((Registry("Network")));
    DynamicJsonDocument Network_Registry(512);
    if (deserializeJson(Network_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.close();
        return Result_Type::Error;
    }
    Temporary_File.close();
    if (strcmp(Network_Registry["Registry"] | "", "Network") != 0)
    {
        return Result_Type::Error;
    }
    JsonObject WiFi_Registry = Network_Registry["WiFi"];
    strlcpy(this->Password, WiFi_Registry["Password"] | "\0", sizeof(Password));
    char Temporary_Char[33];
    strlcpy(Temporary_Char, WiFi_Registry["Name"] | "\0", sizeof(Temporary_Char));
    Set_Credentials(Temporary_Char, Password);
    return Result_Type::Success;
}

///
/// @brief Save WiFi registry.
///
/// @return Result_Type
///
Module_Class::Result_Type Xila_Namespace::WiFi_Class::Save_Registry()
{
    DynamicJsonDocument Network_Registry(512);
    Network_Registry["Registry"] = "Network";
    JsonObject WiFi_Registry = Network_Registry.createNestedObject("WiFi");
    WiFi_Registry["Name"] = SSID();
    WiFi_Registry["Password"] = Password;
    File Temporary_File = Drive.Open(Registry("Network"), FILE_WRITE);
    if (serializeJson(Network_Registry, Temporary_File) == 0)
    {
        Temporary_File.close();
        return Result_Type::Error;
    }
    Temporary_File.close();
    return Result_Type::Success;
}

 /// @brief Function that allow to set credentials and connect to a WiFi network.
 /// 
 /// @param Name SSID of the access point.
 /// @param Password Password of the access point.
void Xila_Namespace::WiFi_Class::Set_Credentials(const char *Name, const char *Password)
{
    strlcpy(this->Password, Password, sizeof(this->Password));
    setAutoConnect(false);
    begin(Name, this->Password);
}