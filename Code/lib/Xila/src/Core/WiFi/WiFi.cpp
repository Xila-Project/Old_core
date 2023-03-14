///
/// @file WiFi.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr) - Espressif
/// @brief Xila WiFi abstraction layer source file.
/// @version 0.1.1
/// @date 08-04-2021
///
/// @copyright Copyright (c) 2021
///

// - Includes

#include "Core/Communication/WiFi.hpp"
#include "Core/Drive/Drive.hpp"
#include "Core/Log/Log.hpp"

// - Namespaces

using namespace Xila_Namespace;
using namespace Xila_Namespace::WiFi_Types;

// - Variables

WiFi_Type Xila_Namespace::WiFi;

// - Methods

WiFi_Class::WiFi_Class() : Station(), Access_Point(), Scan()
{
}

Result_Type WiFi_Class::Start()
{
    Log_Information("WiFi", "Start WiFi module...");
    if (this->Load_Registry() != Result_Type::Success)
    {
        if (this->Create_Registry() != Result_Type::Success)
        {
            return Result_Type::Error;
        }
    }
    return Result_Type::Success;
}

Result_Type WiFi_Class::Stop()
{
    this->Turn_Off();
    return this->Save_Registry();
}

/// @brief Add an access point to the registry.
/// @param SSID SSID of the access point.
/// @param Password Password of the access point.
/// @param Channel Channel of the access point.
/// @param BSSID BSSID of the access point.
/// @return Result_Type::Success if the access point has been added to the registry, Result_Type::Error otherwise (doublon, failed to open the registry or save it ...).
Result_Type WiFi_Class::Station_Class::Add(const String_Type &SSID, const String_Type &Password, int32_t Channel, const uint8_t *BSSID)
{
    // - Open registry
    DynamicJsonDocument WiFi_Registry(8 * 128);
    File_Type Registry_File = Drive.Open(Registry("WiFi"), true);
    // - Check if registry is valid
    if (!Registry_File || deserializeJson(WiFi_Registry, Registry_File) || (strcmp(WiFi_Registry["Registry"] | "", "WiFi") != 0) || WiFi_Registry["Access points"] == NULL)
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    // - Check if access point is already in registry
    JsonArray Access_Points = WiFi_Registry["Access points"];
    for (JsonObject Access_Point : Access_Points)
    {
        if (SSID == Access_Point["SSID"].as<const char*>())
        {
            if (Channel == 0)
            {
                Registry_File.Close();
                return Result_Type::Error;
            }
            else if (Channel == Access_Point["Channel"])
            {

                Registry_File.Close();
                return Result_Type::Error;
            }
        }
    }
    // - Add access point to registry
    JsonObject Access_Point = Access_Points.createNestedObject();
    Access_Point["SSID"] = SSID;
    if (Password != "")
    {
        Access_Point["Password"] = Password;
    }
    if (Channel != 0)
    {
        Access_Point["Channel"] = Channel;
    }
    //  - Save registry
    if (serializeJson(WiFi_Registry, Registry_File) == 0)
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    // - Close registry
    Registry_File.Close();
    return Result_Type::Success;
}

/// @brief Remove an access point from the registry.
/// @param SSID SSID of the access point.
/// @param Channel Channel of the access point.
/// @return Result_Type::Success if the access point has been removed from the registry, Result_Type::Error otherwise (not found, failed to open the registry or save it ...).
Result_Type WiFi_Class::Station_Class::Remove(const String_Type &SSID, int32_t Channel)
{
    // - Open registry
    DynamicJsonDocument Network_Registry(512);
    File_Type Registry_File = Drive.Open(Registry("WiFi"));
    if (!Registry_File || deserializeJson(Network_Registry, Registry_File) || (strcmp(Network_Registry["Registry"] | "", "WiFi") != 0))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    Registry_File.Close();

    JsonArray Access_Points = Network_Registry["Access points"];

    if (Access_Points == NULL)
    {
        return Result_Type::Error;
    }

    for (JsonObject Access_Point : Access_Points)
    {
        if (SSID == Access_Point["SSID"].as<const char*>())
        {
            if (Channel == 0)
            {
                Access_Points.remove(Access_Point);
            }
            else if (Access_Point["Channel"] == Channel)
            {
                Access_Points.remove(Access_Point);
            }
        }
    }

    Registry_File = Drive.Open(Registry("WiFi"), true);
    if (serializeJson(Network_Registry, Registry_File) == 0)
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    Registry_File.Close();
    return Result_Type::Success;
}

/// @brief Check if an access point is known in the registry.
/// @param SSID SSID of the access point.
/// @param Channel Channel of the access point.
/// @return true if the access point is known in the registry, false otherwise.
bool WiFi_Class::Station_Class::Is_Known(const String_Type &SSID, const String_Type& Password, int32_t Channel)
{
    // - Create filter
    StaticJsonDocument<32> Filter;
    Filter["Station"]["Access points"] = true;
    // - Open registry
    File_Type Registry_File = Drive.Open(Registry("WiFi"), true);
    DynamicJsonDocument WiFi_Registry(8 * 128);

    if (!Registry_File || deserializeJson(WiFi_Registry, Registry_File, DeserializationOption::Filter(Filter)) || (strcmp(WiFi_Registry["Registry"] | "", "WiFi") != 0))
    {
        Registry_File.Close();
        return false;
    }
  

    JsonArray Access_Points = WiFi_Registry["Access points"];

    if (Access_Points == NULL)
    {
        Registry_File.Close();
        return false;
    }

    // - Check if access point data matches.
    Boolean_Type Match = true;
    for (JsonObject Access_Point : Access_Points)
    {
        if (SSID != Access_Point["SSID"].as<const char*>())
        {
            Match = false;
            break;
        }

        if (Channel != 0 && Access_Point["Channel"] != Channel)
        {
            Match = false;
            break;
        }
     
        if (Password.Is_Valid() && Password != Access_Point["Password"].as<const char*>())
        {
            Match = false;
            break;
        }
    }

    return Match;
}

/// @brief A function that create the structure of the WiFi registry.
///
/// @return
Result_Type WiFi_Class::Create_Registry()
{
    StaticJsonDocument<2 * 128> WiFi_Registry;

    WiFi_Registry["Registry"] = "WiFi";
    WiFi_Registry.createNestedObject("Station").createNestedArray("Access points");

    File_Type Registry_File = Drive.Open(Registry("WiFi"), true);
    if (!Registry_File || (serializeJson(WiFi_Registry, Registry_File) == 0))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    Registry_File.Close();
    return Result_Type::Success;
}

/// @brief Load WiFi registry.
///
/// @return Result_Type
Result_Type WiFi_Class::Load_Registry()
{
    File_Type Temporary_File = Drive.Open(Registry("WiFi"), true);
    DynamicJsonDocument WiFi_Registry(8 * 128);
    if (deserializeJson(WiFi_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.Close();
        return Result_Type::Error;
    }
    Temporary_File.Close();
    if (strcmp(WiFi_Registry["Registry"] | "", "WiFi") != 0)
    {
        return Result_Type::Error;
    }


    return Result_Type::Success;
}

/// @brief Save WiFi registry.
///
/// @return Result_Type
Result_Type WiFi_Class::Save_Registry()
{
    DynamicJsonDocument WiFi_Registry(8 * 128);
    WiFi_Registry["Registry"] = "Network";

    File_Type Regisitry_File = Drive.Open(Registry("Network"), true);

    if (!Regisitry_File || deserializeJson(WiFi_Registry, Regisitry_File))
    {
        Regisitry_File.Close();
        return Result_Type::Error;
    }

    // - WiFi

    WiFi_Registry["Mode"] = static_cast<uint8_t>(Get_Mode());
    WiFi_Registry["Transmission power"] = Get_Transmission_Power();
    WiFi_Registry["Long range"] = Long_Range;

    // - Station

    JsonObject Station = WiFi_Registry["Station"];

    Station["IP Address"] = static_cast<uint32_t>(this->Station.IP_Address);
    Station["Subnet Mask"] = static_cast<uint32_t>(this->Station.Subnet_Mask);
    Station["Gateway"] = static_cast<uint32_t>(this->Station.Gateway_IP_Address);
    Station["DNS_1"] = static_cast<uint32_t>(this->Station.DNS_1_IP_Address);
    Station["DNS_2"] = static_cast<uint32_t>(this->Station.DNS_2_IP_Address);
    Station["IP v6"] = this->Station.IP_v6;
    Station["Automatic Reconnection"] = this->Station.Get_Automatic_Reconnection();

    // - Access Point

    JsonObject Access_Point = WiFi_Registry["Access Point"];

    Access_Point["IP v6"] = this->Access_Point.IP_v6;
    Static_String_Type<32> SSID;
    this->Access_Point.Get_SSID(SSID);
    Access_Point["SSID"] = SSID;
    Access_Point["Password"] = this->Access_Point.Password;
    Access_Point["Channel"] = this->Access_Point.Channel;
    Access_Point["Hidden"] = this->Access_Point.Hidden;
    Access_Point["Maximum Stations"] = this->Access_Point.Maximum_Stations;
    Access_Point["IP Address"] = static_cast<uint32_t>(this->Access_Point.IP_Address);
    Access_Point["Subnet Mask"] = static_cast<uint32_t>(this->Access_Point.Subnet_Mask);
    Access_Point["Gateway"] = static_cast<uint32_t>(this->Access_Point.Gateway_IP_Address);
    Access_Point["DHCP Lease Start IP Address"] = static_cast<uint32_t>(this->Access_Point.DHCP_Lease_Start_IP_Address);

    if (serializeJson(WiFi_Registry, Regisitry_File) == 0)
    {
        Regisitry_File.Close();
        return Result_Type::Error;
    }

    Regisitry_File.Close();
    return Result_Type::Success;
}

WiFi_Class::Station_Class::Station_Class() : IP_v6(true), IP_Address(), Subnet_Mask(), Gateway_IP_Address(), DNS_1_IP_Address(), DNS_2_IP_Address()
{
}

WiFi_Class::Access_Point_Class::Access_Point_Class() : IP_v6(true), Channel(1), Hidden(false), Password(""), Maximum_Stations(4), IP_Address(), Subnet_Mask(), Gateway_IP_Address(), DHCP_Lease_Start_IP_Address()
{
}