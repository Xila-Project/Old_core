/// @file WiFi_ESP32.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 16-02-2023
///
/// @copyright Copyright (c) 2023

#ifdef Xila_WiFi_Hardware_ESP32

#include <WiFi.h>

WiFiClass &ESP32_WiFi = WiFi;

#include "Network/WiFi/Interface.hpp"
#include "Drive/Drive.hpp"
#include "Log/Log.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Network_Types;

WiFi_Interface_Type WiFi_Interface;

// - Methods

WiFi_Interface_Class::WiFi_Interface_Class() : Station(), Access_Point(), Scan()
{
}

// - - Type conversion

Status_Type Convert_Status(wl_status_t Status)
{
    switch (Status)
    {
    case WL_NO_SHIELD:
        return Status_Type::No_Shield;

    case WL_NO_SSID_AVAIL:
        return Status_Type::No_SSID_Available;

    case WL_SCAN_COMPLETED:
        return Status_Type::Scan_Completed;

    case WL_CONNECTED:
        return Status_Type::Connected;

    case WL_CONNECT_FAILED:
        return Status_Type::Connection_Failed;

    case WL_CONNECTION_LOST:
        return Status_Type::Connection_Lost;

    case WL_DISCONNECTED:
        return Status_Type::Disconnected;
    default:
        return Status_Type::Idle;
    }
}

wl_status_t Convert_Status(Status_Type Status)
{
    switch (Status)
    {
    case Status_Type::No_Shield:
        return WL_NO_SHIELD;
    case Status_Type::No_SSID_Available:
        return WL_NO_SSID_AVAIL;
    case Status_Type::Scan_Completed:
        return WL_SCAN_COMPLETED;
    case Status_Type::Connected:
        return WL_CONNECTED;
    case Status_Type::Connection_Failed:
        return WL_CONNECT_FAILED;
    case Status_Type::Connection_Lost:
        return WL_CONNECTION_LOST;
    case Status_Type::Disconnected:
        return WL_DISCONNECTED;
    default:
        return WL_IDLE_STATUS;
    }
}

wifi_mode_t Convert_Mode(Mode_Type Mode)
{
    switch (Mode)
    {
    case Mode_Type::Station:
        return WIFI_MODE_STA;
    case Mode_Type::Access_Point:
        return WIFI_MODE_AP;
    case Mode_Type::Station_Access_Point:
        return WIFI_MODE_APSTA;
    default:
        return WIFI_MODE_NULL;
    }
}

Mode_Type Convert_Mode(wifi_mode_t Mode)
{
    switch (Mode)
    {
    case WIFI_MODE_STA:
        return Mode_Type::Station;
    case WIFI_MODE_AP:
        return Mode_Type::Access_Point;
    case WIFI_MODE_APSTA:
        return Mode_Type::Station_Access_Point;
    default:
        return Mode_Type::None;
    }
}

wifi_auth_mode_t Convert_Authentification_Mode(Authentication_Mode_Type Authentification_Mode)
{
    switch (Authentification_Mode)
    {
    case Authentication_Mode_Type::WEP:
        return WIFI_AUTH_WEP;
    case Authentication_Mode_Type::WPA_PSK:
        return WIFI_AUTH_WPA_PSK;
    case Authentication_Mode_Type::WPA2_PSK:
        return WIFI_AUTH_WPA2_PSK;
    case Authentication_Mode_Type::WPA_WPA2_PSK:
        return WIFI_AUTH_WPA_WPA2_PSK;
    case Authentication_Mode_Type::WPA2_ENTERPRISE:
        return WIFI_AUTH_WPA2_ENTERPRISE;
    case Authentication_Mode_Type::WPA3_PSK:
        return WIFI_AUTH_WPA3_PSK;
    case Authentication_Mode_Type::WPA2_WPA3_PSK:
        return WIFI_AUTH_WPA2_WPA3_PSK;
    case Authentication_Mode_Type::WAPI_PSK:
        return WIFI_AUTH_WAPI_PSK;
    case Authentication_Mode_Type::MAX:
        return WIFI_AUTH_MAX;
    default:
        return WIFI_AUTH_OPEN;
    }
}

Authentication_Mode_Type Convert_Authentification_Mode(wifi_auth_mode_t Authentification_Mode)
{
    switch (Authentification_Mode)
    {
    case WIFI_AUTH_WEP:
        return Authentication_Mode_Type::WEP;
    case WIFI_AUTH_WPA_PSK:
        return Authentication_Mode_Type::WPA_PSK;
    case WIFI_AUTH_WPA2_PSK:
        return Authentication_Mode_Type::WPA2_PSK;
    case WIFI_AUTH_WPA_WPA2_PSK:
        return Authentication_Mode_Type::WPA_WPA2_PSK;
    case WIFI_AUTH_WPA2_ENTERPRISE:
        return Authentication_Mode_Type::WPA2_ENTERPRISE;
    case WIFI_AUTH_WPA3_PSK:
        return Authentication_Mode_Type::WPA3_PSK;
    case WIFI_AUTH_WPA2_WPA3_PSK:
        return Authentication_Mode_Type::WPA2_WPA3_PSK;
    case WIFI_AUTH_WAPI_PSK:
        return Authentication_Mode_Type::WAPI_PSK;
    case WIFI_AUTH_MAX:
        return Authentication_Mode_Type::MAX;
    default:
        return Authentication_Mode_Type::Open;
    }
}

wifi_power_t Convert_Power(int16_t Power)
{
    if (Power == -1)
        return WIFI_POWER_MINUS_1dBm;
    else if (Power == 2)
        return WIFI_POWER_2dBm;
    else if (Power == 7)
        return WIFI_POWER_7dBm;
    else if (Power == 11)
        return WIFI_POWER_11dBm;
    else if (Power == 13)
        return WIFI_POWER_13dBm;
    else if (Power == 15)
        return WIFI_POWER_15dBm;
    else if (Power == 17)
        return WIFI_POWER_17dBm;
    else if (Power == 19)
        return WIFI_POWER_19dBm;
    else
        return WIFI_POWER_MINUS_1dBm;
}

// - - WiFi

void WiFi_Interface_Class::Turn_Off()
{
    ESP32_WiFi.mode(WIFI_OFF);
}

int32_t WiFi_Interface_Class::Get_Channel()
{
    return ESP32_WiFi.channel();
}

Mode_Type WiFi_Interface_Class::Get_Mode()
{
    return Convert_Mode(ESP32_WiFi.getMode());
}

int16_t WiFi_Interface_Class::Get_Transmission_Power()
{
    return ESP32_WiFi.getTxPower();
}

String_Type &WiFi_Interface_Class::Get_Host_Name(String_Type &Host_Name)
{
    Host_Name = ESP32_WiFi.getHostname();
    return Host_Name;
}

Interface_Type_Type WiFi_Interface_Class::Get_Type()
{
    return Interface_Type_Type::WiFi;
}

void WiFi_Interface_Class::Set_Long_Range(bool Enable)
{
    ESP32_WiFi.enableLongRange(Enable);
    Long_Range = Enable;
}

Result_Type WiFi_Interface_Class::Set_Transmission_Power(int16_t Power)
{
    if (ESP32_WiFi.setTxPower(Convert_Power(Power)))
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type WiFi_Interface_Class::Set_Host_Name(const char *Host_Name)
{
    if (Host_Name)
        if (ESP32_WiFi.setHostname(Host_Name) && ESP32_WiFi.softAPsetHostname(Host_Name))
            return Result_Type::Success;

    return Result_Type::Error;
}

Boolean_Type WiFi_Interface_Class::Is_IP_v6()
{
    return IP_v6;
}

Result_Type WiFi_Interface_Class::Set_IP_v6(bool Enable)
{
    if (!Enable)
        return Result_Type::Success;

    this->IP_v6 = Enable;

    if (this->Get_Mode() == Mode_Type::Access_Point)
    {
        if (!ESP32_WiFi.softAPenableIpV6())
            return Result_Type::Error;
    }
    else if (this->Get_Mode() == Mode_Type::Station)
    {
        if (!ESP32_WiFi.enableIpV6())
            return Result_Type::Error;
    }
    else
        return Result_Type::Error;

    return Result_Type::Success;
}

// - - Station

void WiFi_Interface_Class::Station_Class::Turn_On()
{
    ESP32_WiFi.mode(WIFI_STA);
}

void WiFi_Interface_Class::Station_Class::Connect(const char *SSID, const char *Password, int32_t Channel, const uint8_t *BSSID)
{
    Static_String_Type<64> Temporary_Password;
    int32_t Temporary_Channel = Channel;

    if (this->Get_Informations(SSID, Temporary_Password, Temporary_Channel) != Result_Type::Success)
    {
        this->Add(SSID, Password, Channel, BSSID);

        if (Password)
            Temporary_Password = Password;

        Temporary_Channel = Channel;
    }

    ESP32_WiFi.begin(SSID, Temporary_Password, Temporary_Channel, BSSID, true);
}

Result_Type WiFi_Interface_Class::Station_Class::Disconnect()
{
    if (ESP32_WiFi.disconnect(false))
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

bool WiFi_Interface_Class::Station_Class::Get_Automatic_Reconnection()
{
    return ESP32_WiFi.getAutoReconnect();
}

Network_Types::Status_Type WiFi_Interface_Class::Station_Class::Get_Status(bool Wait_For_Connect, uint32_t Timeout)
{
    if (Wait_For_Connect)
    {
        return Convert_Status(static_cast<wl_status_t>(ESP32_WiFi.waitForConnectResult(Timeout)));
    }
    return Convert_Status(ESP32_WiFi.status());
}

String_Type &WiFi_Interface_Class::Station_Class::Get_SSID(String_Type &SSID)
{
    SSID = ESP32_WiFi.SSID().c_str();
    return SSID;
}

String_Type &WiFi_Interface_Class::Station_Class::Get_Pre_Shared_Key(String_Type &Pre_Shared_Key)
{
    Pre_Shared_Key = ESP32_WiFi.psk().c_str();
    return Pre_Shared_Key;
}

uint8_t *WiFi_Interface_Class::Station_Class::Get_BSSID()
{
    return ESP32_WiFi.BSSID();
}

int8_t WiFi_Interface_Class::Station_Class::Get_RSSI()
{
    return ESP32_WiFi.RSSI();
}

Byte_Type& WiFi_Interface_Class::Get_MAC_Address(Byte_Type& MAC_Address)
{
    if (this->Get_Mode() == Mode_Type::Access_Point)
        return *ESP32_WiFi.softAPmacAddress(&MAC_Address);
    else if (this->Get_Mode() == Mode_Type::Station)
        return *ESP32_WiFi.macAddress(&MAC_Address);
    return MAC_Address;
}

IP_Address_Type WiFi_Interface_Class::Get_IP_Address(bool IPv6)
{
    if (this->Get_Mode() == Mode_Type::Access_Point)
    {
        if (IPv6)
            return IP_Address_Class(ESP32_WiFi.softAPIPv6());
        else
            return IP_Address_Type((uint32_t)ESP32_WiFi.softAPIP());
    }
    else if (this->Get_Mode() == Mode_Type::Station)
    {
        if (IPv6)
            return IP_Address_Class(ESP32_WiFi.localIPv6());
        else
            return IP_Address_Type((uint32_t)ESP32_WiFi.localIP());
    }
    return IP_Address_Type();
}

IP_Address_Type WiFi_Interface_Class::Get_Subnet_Mask()
{
    return IP_Address_Type((uint32_t)ESP32_WiFi.subnetMask());
}

IP_Address_Type WiFi_Interface_Class::Get_Gateway_IP_Address()
{
    return IP_Address_Type((uint32_t)ESP32_WiFi.gatewayIP());
}

IP_Address_Type WiFi_Interface_Class::Get_DNS_IP_Address(Natural_Type Index)
{
    return IP_Address_Type((uint32_t)ESP32_WiFi.dnsIP(Index));
}

IP_Address_Type WiFi_Interface_Class::Get_Broadcast_IP_Address()
{
    if (this->Get_Mode() == Mode_Type::Access_Point)
        return IP_Address_Type((uint32_t)ESP32_WiFi.softAPBroadcastIP());
    else if (this->Get_Mode() == Mode_Type::Station)
        return IP_Address_Type((uint32_t)ESP32_WiFi.broadcastIP());
    return IP_Address_Type();
}

IP_Address_Type WiFi_Interface_Class::Get_Network_ID()
{
    if (this->Get_Mode() == Mode_Type::Access_Point)
        return IP_Address_Type(ESP32_WiFi.softAPNetworkID());
    else if (this->Get_Mode() == Mode_Type::Station)
        return IP_Address_Type(ESP32_WiFi.networkID());
    return IP_Address_Type();
}

Byte_Type WiFi_Interface_Class::Get_Subnet_CIDR()
{
    if (this->Get_Mode() == Mode_Type::Access_Point)
        return ESP32_WiFi.softAPSubnetCIDR();
    else if (this->Get_Mode() == Mode_Type::Station)
        return ESP32_WiFi.subnetCIDR();
    return 0;
}

Result_Type WiFi_Interface_Class::Set_Configuration(IP_Address_Type IP_Address, IP_Address_Type Subnet_Mask, IP_Address_Type Gateway_IP_Address, IP_Address_Type DNS_1_IP_Address, IP_Address_Type DNS_2_IP_Address)
{
    if (this->Get_Mode() == Mode_Type::Access_Point)
    {
        if (ESP32_WiFi.softAPConfig((IPAddress)IP_Address, (IPAddress)Gateway_IP_Address, (IPAddress)Subnet_Mask))
        {
            this->IP_Address = IP_Address;
            this->Subnet_Mask = Subnet_Mask;
            this->Gateway_IP_Address = Gateway_IP_Address;
            return Result_Type::Success;
        }
    }
    else if (this->Get_Mode() == Mode_Type::Station)
    {
        if (ESP32_WiFi.config((IPAddress)IP_Address, (IPAddress)Gateway_IP_Address, (IPAddress)Subnet_Mask, (IPAddress)DNS_1_IP_Address, (IPAddress)DNS_2_IP_Address))
        {
            this->IP_Address = IP_Address;
            this->Subnet_Mask = Subnet_Mask;
            this->Gateway_IP_Address = Gateway_IP_Address;
            this->DNS_IP_Address[0] = DNS_1_IP_Address;
            this->DNS_IP_Address[1] = DNS_2_IP_Address;
            return Result_Type::Success;
        }
    }
    return Result_Type::Error;
}

bool WiFi_Interface_Class::Station_Class::Set_Automatic_Reconnection(bool Enabled)
{
    ESP32_WiFi.setAutoReconnect(Enabled);
    return Enabled;
}

void WiFi_Interface_Class::Station_Class::Set_Scan_Method(bool Fast)
{
    if (Fast)
        ESP32_WiFi.setScanMethod(WIFI_FAST_SCAN);
    else
        ESP32_WiFi.setScanMethod(WIFI_ALL_CHANNEL_SCAN);
}

void WiFi_Interface_Class::Station_Class::Set_Sort_Method(bool Signal)
{
    if (Signal)
        ESP32_WiFi.setSortMethod(WIFI_CONNECT_AP_BY_SIGNAL);
    else
        ESP32_WiFi.setSortMethod(WIFI_CONNECT_AP_BY_SECURITY);
}

// - Access point

Result_Type WiFi_Interface_Class::Access_Point_Class::Create(const char *SSID, const char *Password, int32_t Channel, bool Hidden, uint8_t Maximum_Stations, bool FTM_Responder)
{
    if (strlen(Password) <= this->Password.Get_Length())
    {
        if (ESP32_WiFi.softAP(SSID, Password, Channel, Hidden, Maximum_Stations, FTM_Responder))
        {
            this->Password = Password;
            this->Channel = Channel;
            this->Hidden = Hidden;
            this->Maximum_Stations = Maximum_Stations;
            return Result_Type::Success;
        }
    }
    return Result_Type::Error;
}

String_Type &WiFi_Interface_Class::Access_Point_Class::Get_SSID(String_Type &SSID)
{
    SSID = ESP32_WiFi.softAPSSID().c_str();
    return SSID;
}

String_Type &WiFi_Interface_Class::Access_Point_Class::Get_Password(String_Type &Password)
{
    Password = this->Password;
    return Password;
}

uint8_t WiFi_Interface_Class::Access_Point_Class::Get_Channel()
{
    return this->Channel;
}

bool WiFi_Interface_Class::Access_Point_Class::Get_Hidden()
{
    return this->Hidden;
}

uint8_t WiFi_Interface_Class::Access_Point_Class::Get_Maximum_Stations()
{
    return this->Maximum_Stations;
}

uint8_t WiFi_Interface_Class::Access_Point_Class::Get_Station_Number()
{
    return ESP32_WiFi.softAPgetStationNum();
}

IP_Address_Type WiFi_Interface_Class::Access_Point_Class::Get_DHCP_Start_IP_Address()
{
    return DHCP_Lease_Start_IP_Address;
}

IP_Address_Type WiFi_Interface_Class::Access_Point_Class::Get_Network_ID()
{
    return IP_Address_Type(ESP32_WiFi.softAPNetworkID());
}

uint8_t *WiFi_Interface_Class::Access_Point_Class::Get_MAC_Address(uint8_t *MAC_Address)
{
    return ESP32_WiFi.softAPmacAddress(MAC_Address);
}

// - - Scan

int16_t WiFi_Interface_Class::Scan_Class::Start(bool Asynchronous, bool Show_Hidden, bool Passive, uint32_t Maximum_Milliseconds_Per_Channel, uint8_t Channel, const char *SSID, const uint8_t *BSSID)
{
    return ESP32_WiFi.scanNetworks(Asynchronous, Show_Hidden, Passive, Maximum_Milliseconds_Per_Channel, Channel, SSID, BSSID);
}

bool WiFi_Interface_Class::Scan_Class::Is_Complete()
{
    return (ESP32_WiFi.scanComplete() >= 0);
}

int16_t WiFi_Interface_Class::Scan_Class::Get_Result()
{
    if (ESP32_WiFi.scanComplete() < 0)
    {
        return 0;
    }
    return ESP32_WiFi.scanComplete();
}

void WiFi_Interface_Class::Scan_Class::Delete()
{
    ESP32_WiFi.scanDelete();
}

Result_Type WiFi_Interface_Class::Scan_Class::Get_Informations(uint8_t Index, String_Type &SSID, uint8_t &Encryption_Type, int32_t &RSSI, uint8_t *&BSSID, int32_t &Channel)
{
    String SSID_String = "";
    if (ESP32_WiFi.getNetworkInfo(Index, SSID_String, Encryption_Type, RSSI, BSSID, Channel))
    {
        SSID = SSID_String.c_str();
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

String_Type &WiFi_Interface_Class::Scan_Class::Get_SSID(uint8_t Index, String_Type &SSID)
{
    SSID = ESP32_WiFi.SSID(Index).c_str();
    return SSID;
}

Authentication_Mode_Type WiFi_Interface_Class::Scan_Class::Get_Encryption(uint8_t Index)
{
    return Convert_Authentification_Mode(ESP32_WiFi.encryptionType(Index));
}

int32_t WiFi_Interface_Class::Scan_Class::Get_RSSI(uint8_t Index)
{
    return ESP32_WiFi.RSSI(Index);
}

uint8_t *WiFi_Interface_Class::Scan_Class::Get_BSSID(uint8_t Index)
{
    return ESP32_WiFi.BSSID(Index);
}

int32_t WiFi_Interface_Class::Scan_Class::Get_Channel(uint8_t Index)
{
    return ESP32_WiFi.channel(Index);
}

Client_Type &WiFi_Interface_Class::Create_Client()
{
    return *(new WiFi_Client_Type());
}

Result_Type WiFi_Interface_Class::Start()
{
    if (this->Load_Registry() != Result_Type::Success)
    {
        if (this->Create_Registry() != Result_Type::Success)
            return Result_Type::Error;
    }
    return Result_Type::Success;
}

Result_Type WiFi_Interface_Class::Stop()
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
Result_Type WiFi_Interface_Class::Station_Class::Add(const char *SSID, const char *Password, int32_t Channel, const uint8_t *BSSID)
{
    // - Open registry
    DynamicJsonDocument WiFi_Registry(8 * 128);

    {
        Drive_Types::File_Type Registry_File = Drive.Open(Registry("WiFi"));
        // - Check if registry is valid
        if (deserializeJson(WiFi_Registry, Registry_File) || (strcmp(WiFi_Registry["Registry"] | "", "WiFi") != 0) || WiFi_Registry["Station"]["Access points"] == NULL)
        {
            Registry_File.Close();
            return Result_Type::Error;
        }
        Registry_File.Close();
    }

    {
        // - Check if access point is already in registry
        JsonArray Access_Points = WiFi_Registry["Station"]["Access points"];
        // - Add access point to registry
        JsonObject Access_Point = Access_Points.createNestedObject();
        Access_Point["SSID"] = SSID;
        if (strncmp(Password, "", sizeof("")))
        {
            Access_Point["Password"] = Password;
        }
        if (Channel != 0)
        {
            Access_Point["Channel"] = Channel;
        }
        Drive_Types::File_Type Registry_File = Drive.Open(Registry("WiFi"), true);
        //  - Save registry
        if (serializeJson(WiFi_Registry, Registry_File) == 0)
        {
            Registry_File.Close();
            return Result_Type::Error;
        }
        // - Close registry
        Registry_File.Close();
    }

    return Result_Type::Success;
}

/// @brief Remove an access point from the registry.
/// @param SSID SSID of the access point.
/// @param Channel Channel of the access point.
/// @return Result_Type::Success if the access point has been removed from the registry, Result_Type::Error otherwise (not found, failed to open the registry or save it ...).
Result_Type WiFi_Interface_Class::Station_Class::Remove(const char *SSID, int32_t Channel)
{
    // - Open registry
    DynamicJsonDocument Network_Registry(8 * 128);
    {
        Drive_Types::File_Type Registry_File = Drive.Open(Registry("WiFi"));
        if (deserializeJson(Network_Registry, Registry_File) || (strcmp(Network_Registry["Registry"] | "", "WiFi") != 0))
        {
            Registry_File.Close();
            return Result_Type::Error;
        }
        Registry_File.Close();

        JsonArray Access_Points = Network_Registry["Station"]["Access points"];

        if (Access_Points == NULL)
        {
            return Result_Type::Error;
        }

        for (Size_Type i = 0; i < Access_Points.size(); i++)
        {
            if (strcmp(SSID, Access_Points[i]["SSID"]) == 0)
            {
                Access_Points.remove(i);
                //            if (Channel == 0)
                //            {
                //                Access_Points.remove(Access_Point);
                //            }
                //            else if (Access_Point["Channel"] == Channel)
                //            {
                //                Access_Points.remove(Access_Point);
                //            }
            }
        }
    }

    {
        Drive_Types::File_Type Registry_File = Drive.Open(Registry("WiFi"), true);

        if (serializeJson(Network_Registry, Registry_File) == 0)
        {
            Registry_File.Close();
            return Result_Type::Error;
        }

        Registry_File.Close();
    }
    return Result_Type::Success;
}

/// @brief Check if an access point is known in the registry.
/// @param SSID SSID of the access point.
/// @param Channel Channel of the access point.
/// @return true if the access point is known in the registry, false otherwise.
bool WiFi_Interface_Class::Station_Class::Is_Known(const char *SSID, const char *Password, int32_t Channel)
{
    // - Create filter
    StaticJsonDocument<64> Filter;
    Filter["Station"]["Access points"] = true;
    Filter["Registry"] = true;
    // - Open registry
    Drive_Types::File_Type Registry_File = Drive.Open(Registry("WiFi"));
    DynamicJsonDocument WiFi_Registry(8 * 128);

    while (Registry_File.available() > 0)
    {
        log_printf("%c", Registry_File.Read());
    }
    Registry_File.Seek(0);

    if (!Registry_File || deserializeJson(WiFi_Registry, Registry_File, DeserializationOption::Filter(Filter)) || (strcmp(WiFi_Registry["Registry"] | "", "WiFi") != 0))
    {
        Registry_File.Close();
        return false;
    }

    Registry_File.Close();

    JsonArray Access_Points = WiFi_Registry["Station"]["Access points"];

    if (Access_Points == NULL || Access_Points.size() == 0)
        return false;

    // - Check if access point data matches.
    Boolean_Type Match = false;
    for (JsonObject Access_Point : Access_Points)
    {
        if (strcmp(SSID, Access_Point["SSID"] | "") == 0)
        {
            Match = true;
            break;
        }

        //      if (Channel == 0 && Access_Point["Channel"] != Channel)
        //      {
        //          Match = false;
        //          break;
        //      }
        //
        //      if (strcmp(Password, Access_Point["Password"]) != 0)
        //      {
        //          Match = false;
        //          break;
        //      }
    }
    return Match;
}

Result_Type WiFi_Interface_Class::Station_Class::Get_Informations(const char *SSID, String_Type &Password, int32_t &Channel)
{
    if (!Password.Is_Valid())
        return Result_Type::Error;

    // - Create filter
    StaticJsonDocument<64> Filter;
    Filter["Station"]["Access points"] = true;
    Filter["Registry"] = true;
    // - Open registry
    Drive_Types::File_Type Registry_File = Drive.Open(Registry("WiFi"));
    DynamicJsonDocument WiFi_Registry(8 * 128);

    if (!Registry_File || deserializeJson(WiFi_Registry, Registry_File, DeserializationOption::Filter(Filter)) || (strcmp(WiFi_Registry["Registry"] | "", "WiFi") != 0))
    {
        Registry_File.Close();
        return Result_Type::Error;
    }

    Registry_File.Close();

    JsonArray Access_Points = WiFi_Registry["Station"]["Access points"];

    if (Access_Points == NULL || Access_Points.size() == 0)
        return Result_Type::Error;

    // - Check if access point data matches.
    Boolean_Type Match = false;
    for (JsonObject Access_Point : Access_Points)
    {
        if (strcmp(SSID, Access_Point["SSID"] | "") == 0)
        {
            Match = true;

            Password = Access_Point["Password"] | "";
            Channel = Access_Point["Channel"] | 0;

            break;
        }

        //      if (Channel == 0 && Access_Point["Channel"] != Channel)
        //      {
        //          Match = false;
        //          break;
        //      }
        //
        //      if (strcmp(Password, Access_Point["Password"]) != 0)
        //      {
        //          Match = false;
        //          break;
        //      }
    }

    if (!Match)
        return Result_Type::Error;
    return Result_Type::Success;
}

/// @brief A function that create the structure of the WiFi registry.
///
/// @return
Result_Type WiFi_Interface_Class::Create_Registry()
{
    StaticJsonDocument<2 * 128> WiFi_Registry;

    WiFi_Registry["Registry"] = "WiFi";
    WiFi_Registry.createNestedObject("Station").createNestedArray("Access points");

    Drive_Types::File_Type Registry_File = Drive.Open(Registry("WiFi"), true);
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
Result_Type WiFi_Interface_Class::Load_Registry()
{
    Drive_Types::File_Type Temporary_File = Drive.Open(Registry("WiFi"));
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
Result_Type WiFi_Interface_Class::Save_Registry()
{
    DynamicJsonDocument WiFi_Registry(8 * 128);
    WiFi_Registry["Registry"] = "Network";

    Drive_Types::File_Type Regisitry_File = Drive.Open(Registry("Network"), true);

    if (!Regisitry_File || deserializeJson(WiFi_Registry, Regisitry_File))
    {
        Regisitry_File.Close();
        return Result_Type::Error;
    }

    // - WiFi

    WiFi_Registry["Mode"] = static_cast<uint8_t>(Get_Mode());
    WiFi_Registry["Transmission power"] = this->Get_Transmission_Power();
    WiFi_Registry["Long range"] = Long_Range;
    WiFi_Registry["Is_IP_v6"] = this->Is_IP_v6();
    WiFi_Registry["IP Address"] = static_cast<uint32_t>(this->Get_IP_Address());
    WiFi_Registry["Subnet Mask"] = static_cast<uint32_t>(this->Get_Subnet_Mask());
    WiFi_Registry["Gateway"] = static_cast<uint32_t>(this->Get_Gateway_IP_Address());
    WiFi_Registry["DNS_1"] = static_cast<uint32_t>(this->Get_DNS_IP_Address(0));
    WiFi_Registry["DNS_2"] = static_cast<uint32_t>(this->Get_DNS_IP_Address(1));

    // - Station

    JsonObject Station = WiFi_Registry["Station"];
    Station["Automatic Reconnection"] = this->Station.Get_Automatic_Reconnection();

    // - Access Point

    JsonObject Access_Point = WiFi_Registry["Access Point"];
    Static_String_Type<32> SSID;
    this->Access_Point.Get_SSID(SSID);
    Access_Point["SSID"] = SSID;
    Access_Point["Password"] = this->Access_Point.Password;
    Access_Point["Channel"] = this->Access_Point.Channel;
    Access_Point["Hidden"] = this->Access_Point.Hidden;
    Access_Point["Maximum Stations"] = this->Access_Point.Maximum_Stations;
    Access_Point["DHCP Lease Start IP Address"] = static_cast<uint32_t>(this->Access_Point.DHCP_Lease_Start_IP_Address);

    if (serializeJson(WiFi_Registry, Regisitry_File) == 0)
    {
        Regisitry_File.Close();
        return Result_Type::Error;
    }

    Regisitry_File.Close();
    return Result_Type::Success;
}

WiFi_Interface_Class::Access_Point_Class::Access_Point_Class() : Channel(1), Hidden(false), Password(""), Maximum_Stations(4), DHCP_Lease_Start_IP_Address()
{
}

#endif