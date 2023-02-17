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

// - Namespaces

using namespace Xila_Namespace;
using namespace Xila_Namespace::WiFi_Types;

// - Variables

WiFi_Type WiFi();

// - Methods

// - - Constructors / Destructors

/// @brief Construct a new WiFi_Class object
WiFi_Class::WiFi_Class() : Long_Range(true), Station(), Access_Point(), Scan()
{
}

WiFi_Class::~WiFi_Class()
{
}

/// @brief
/// @param SSID
/// @param Password
/// @param Channel
/// @param BSSID
/// @return
Result_Type WiFi_Class::Station_Class::Add(const char *SSID, const char *Password, int32_t Channel, const uint8_t *BSSID)
{
    // Add access point to registry
    DynamicJsonDocument WiFi_Registry(512);

    File_Type Registry_File = Drive.Open(Registry("WiFi"), true);

    if (!Registry_File || deserializeJson(WiFi_Registry, Registry_File) || (strcmp(WiFi_Registry["Registry"] | "", "WiFi") != 0))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    JsonArray Access_Points = WiFi_Registry["Access_Points"];

    if (Access_Points == NULL)
    {
        return Result_Type::Error;
    }

    // Check for doublon

    for (JsonObject Access_Point : Access_Points)
    {
        if (strcmp(Access_Point["SSID"] | "", SSID) == 0)
        {
            if (Channel == 0)
            {
                return Result_Type::Error;
            }
            else (Access_Point["Channel"] == Channel)
            {
                return Result_Type::Error;
            }
        }
            
    }

    JsonObject Access_Point = Access_Points.createNestedObject();

    Access_Point["SSID"] = SSID;

    if (Password != NULL)
    {
        Access_Point["Password"] = Password;
    }
    if (Channel != 0)
    {
        Access_Point["Channel"] = Channel;
    }

    if (serializeJson(WiFi_Registry, Registry_File) == 0)
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    Registry_File.Close();
    return Result_Type::Success;
}

Result_Type WiFi_Class::Station_Class::Remove(const char *SSID, int32_t Channel = 0)
{
    // Remove access point from registry
    DynamicJsonDocument Network_Registry(512);

    File_Type Registry_File = Drive.Open(Registry("WiFi"));

    if (deserializeJson(Network_Registry, Registry_File))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    Registry_File.Close();

    if (strcmp(Network_Registry["Registry"] | "", "WiFi") != 0)
    {
        return Result_Type::Error;
    }

    JsonArray Access_Points = Network_Registry["Access_Points"];

    if (Access_Points == NULL)
    {
        return Result_Type::Error;
    }

    for (JsonObject Access_Point : Access_Points)
    {
        if (strcmp(Access_Point["SSID"] | "", SSID) == 0)
        {
            if (Channel == 0)
            {
                Access_Points.remove(Access_Point);
            }
            else (Access_Point["Channel"] == Channel)
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

/// @brief A function that create the structure of the WiFi registry.
///
/// @return
Result_Type WiFi_Class::Create_Registry()
{
    DynamicJsonDocument WiFi_Registry(512);
    WiFi_Registry["Registry"] = "WiFi";

    WiFi_Registry.createNestedObject("Station").createNestedArray("Access Points");
    
    WiFi_Registry.createNestedObject("Access Point");
    
    JsonArray Access_Points = WiFi_Registry.createNestedArray("Access_Points");  

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
    DynamicJsonDocument Network_Registry(512);
    if (deserializeJson(Network_Registry, Temporary_File) != DeserializationError::Ok)
    {
        Temporary_File.Close();
        return Result_Type::Error;
    }
    Temporary_File.Close();
    if (strcmp(Network_Registry["Registry"] | "", "WiFi") != 0)
    {
        return Result_Type::Error;
    }

    return Result_Type::Success;
}

///
/// @brief Save WiFi registry.
///
/// @return Result_Type
///
Result_Type WiFi_Class::Save_Registry()
{
    DynamicJsonDocument WiFi_Registry(8 * 128);
    WiFi_Registry["Registry"] = "Network";  
   
    File_Type Temporary_File = Drive.Open(Registry("Network"), true);

    if (!Temporary_File || deserializeJson(WiFi_Registry, Temporary_File))
    {
        Temporary_File.Close();
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
    Station["Gateway"] = static_cast<uint32_t>(this->Station.Gateway);
    Station["DNS_1"] = static_cast<uint32_t>(this->Station.DNS_1);
    Station["DNS_2"] = static_cast<uint32_t>(this->Station.DNS_2);
    Station["IP v6"] = this->Station.IP_v6;
    Station["Automatic Reconnection"] = this->Station.Get_Automatic_Reconnection();

    // - Access Point

    JsonObject Access_Point = WiFi_Registry["Access Point"];

    Access_Point["IP v6"] = this->Access_Point.IP_v6;
    Access_Point["SSID"] = this->Access_Point.Get_SSID();
    Access_Point["Password"] = this->Access_Point.Password;
    Access_Point["Channel"] = this->Access_Point.Channel;
    Access_Point["Hidden"] = this->Access_Point.Hidden;
    Access_Point["Maximum Stations"] = this->Access_Point.Maximum_Stations;
    Access_Point["IP Address"] = static_cast<uint32_t>(this->Access_Point.IP_Address);
    Access_Point["Subnet Mask"] = static_cast<uint32_t>(this->Access_Point.Subnet_Mask);
    Access_Point["Gateway"] = static_cast<uint32_t>(this->Access_Point.Gateway_IP_Address);
    Access_Point["DHCP Lease Start IP Address"] = static_cast<uint32_t>(this->Access_Point.DHCP_Lease_Start_IP_Address);
   
    if (serializeJson(WiFi_Registry, Temporary_File) == 0)
    {
        Temporary_File.Close();
        return Result_Type::Error;
    }   

    Temporary_File.Close();
    return Result_Type::Success;
}


Result_Type WiFi_Class::Station_Class::Connect(const char *SSID)
{
    File_Type Registry_File = Drive.Open(Registry("WiFi"), true);
    DynamicJsonDocument Network_Registry(512);
    if (deserializeJson(Network_Registry, Registry_File))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }
    Registry_File.Close();

    JsonArray Access_Points = Network_Registry["Access_Points"];

    if ((strcmp(Network_Registry["Registry"] | "", "WiFi") != 0) || (Access_Points == NULL))
    {

        return Result_Type::Error;
    }

    for (JsonObject Access_Point : Access_Points)
    {
        if (strcmp(Access_Point["SSID"] | "", SSID) == 0)
        {
            Connect(Access_Point["SSID"] | "", Access_Point["Password"] | "", static_cast<int32_t>(Access_Point["Channel"] | 0));
            
            return Result_Type::Success;
        }
    }
}

WiFi_Class::Station_Class::Station_Class() : IP_v6(true), IP_Address(), Subnet_Mask(), Gateway(), DNS_1(), DNS_2()
{
}

WiFi_Class::Access_Point_Class::Access_Point_Class() : IP_v6(true), Channel(1), Hidden(false), Maximum_Stations(4), IP_Address(), Subnet_Mask(), Gateway_IP_Address(), DHCP_Lease_Start_IP_Address()
{
    memset(Password, '\0', sizeof(Password));

}