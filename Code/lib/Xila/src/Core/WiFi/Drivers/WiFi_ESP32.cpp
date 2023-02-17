///
/// @file WiFi_ESP32.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 16-02-2023
///
/// @copyright Copyright (c) 2023
///

// #if WiFi_Hardware == WiFi_Hardware_ESP32

#if true

#include <WiFi.h>

WiFiClass &ESP32_WiFi = WiFi;

#include "Core/Communication/WiFi.hpp"
#include "Core/Drive/Drive.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::WiFi_Types;

// - Methods

// - - Type conversion

Status_Type Convert_Status(wl_status_t Status)
{
    switch (Status)
    {
    case WL_NO_SHIELD:
        return Status_Type::No_Shield;

    case WL_IDLE_STATUS:
        return Status_Type::Idle;

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
    }
}

wl_status_t Convert_Status(Status_Type Status)
{
    switch (Status)
    {
    case Status_Type::No_Shield:
        return WL_NO_SHIELD;

    case Status_Type::Idle:
        return WL_IDLE_STATUS;

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
    }
}

wifi_mode_t Convert_Mode(Mode_Type Mode)
{
    switch (Mode)
    {
    case Mode_Type::None:
        return WIFI_MODE_NULL;
    case Mode_Type::Station:
        return WIFI_MODE_STA;
    case Mode_Type::Access_Point:
        return WIFI_MODE_AP;
    case Mode_Type::Station_Access_Point:
        return WIFI_MODE_APSTA;
    }
}

Mode_Type Convert_Mode(wifi_mode_t Mode)
{
    switch (Mode)
    {
    case WIFI_MODE_NULL:
        return Mode_Type::None;
    case WIFI_MODE_STA:
        return Mode_Type::Station;
    case WIFI_MODE_AP:
        return Mode_Type::Access_Point;
    case WIFI_MODE_APSTA:   
        return Mode_Type::Station_Access_Point;
    }
}


// - - Station


void WiFi_Class::Station_Class::Connect(const char* SSID, const char* Password, int32_t Channel, const uint8_t* BSSID)
{
    ESP32_WiFi.begin(SSID, Password, Channel, BSSID, true);
}

void WiFi_Class::Station_Class::Connect(char* SSID, char* Password, int32_t Channel, const uint8_t* BSSID)
{
    ESP32_WiFi.begin(SSID, Password, Channel, BSSID, true);
}

Result_Type WiFi_Class::Station_Class::Disconnect()
{
    ESP32_WiFi.disconnect(false);
}




//


Status_Type WiFi_Class::Get_Status()
{
    return Convert_Status(ESP32_WiFi.status());
}

bool WiFi_Class::Get_Automatic_Reconnection()
{
    return ESP32_WiFi.getAutoReconnect();
}

uint8_t *WiFi_Class::Get_MAC_Address(uint8_t *MAC_Address)
{
    return ESP32_WiFi.macAddress(MAC_Address);
}

IP_Address_Type WiFi_Class::Get_IP_Address(bool IPv6)
{
    if (IPv6)
    {
        return ESP32_WiFi.localIPv6();
    }
    return IP_Address_Type(ESP32_WiFi.localIP());
}

IP_Address_Type WiFi_Class::Get_Subnet_Mask()
{
    return IP_Address_Type(ESP32_WiFi.subnetMask());
}

IP_Address_Type WiFi_Class::Get_Gateway_IP_Address()
{
    return IP_Address_Type(ESP32_WiFi.gatewayIP());
}

IP_Address_Type WiFi_Class::Get_DNS_IP_Address(uint8_t Index)
{
    return IP_Address_Type(ESP32_WiFi.dnsIP(Index));
}

IP_Address_Type WiFi_Class::Get_Broadcast_IP_Address()
{
    return IP_Address_Type(ESP32_WiFi.broadcastIP());
}

IP_Address_Type WiFi_Class::Get_Network_ID()
{
    return IP_Address_Type(ESP32_WiFi.networkID());
}

uint8_t WiFi_Class::Get_Subnet_CIDR()
{
    return ESP32_WiFi.subnetCIDR();
}

const char *WiFi_Class::Get_SSID()
{
    return ESP32_WiFi.SSID().c_str();
}

uint8_t *WiFi_Class::Get_BSSID()
{
    return ESP32_WiFi.BSSID();
}

int8_t WiFi_Class::Get_RSSI()
{
    return ESP32_WiFi.RSSI();
}

Result_Type WiFi_Class::Station_Class::Set_Configuration(IP_Address_Type IP_Address, IP_Address_Type Subnet_Mask, IP_Address_Type Gateway_IP_Address, IP_Address_Type DNS_1_IP_Address, IP_Address_Type DNS_2_IP_Address)
{
    this->IP_Address = IP_Address;
    this->Subnet_Mask = Subnet_Mask;
    this->Gateway_IP_Address = Gateway_IP_Address;
    this->DNS_1_IP_Address = DNS_1_IP_Address;
    this->DNS_2_IP_Address = DNS_2_IP_Address;

    if (ESP32_WiFi.config(IP_Address, Gateway_IP_Address, Subnet_Mask, DNS_1_IP_Address, DNS_2_IP_Address))
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type WiFi_Class::Access_Point_Class::Set_Configuration(IP_Address_Type Local_IP, IP_Address_Type Gateway, IP_Address_Type Subnet, IP_Address_Type DHCP_Lease_Start = static_cast<uint32_t>(0))
{
    this->IP_Address = IP_Address;
    this->Subnet_Mask = Subnet_Mask;
    this->Gateway_IP_Address = Gateway_IP_Address;
    this->DHCP_Lease_Start_IP_Adress = DHCP_Lease_Start_IP_Adress;

    if (ESP32_WiFi.softAPConfig(IP_Address, Gateway_IP_Address, Subnet_Mask, DHCP_Lease_Start_IP_Adress))
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}


Result_Type WiFi_Class::Set_Host_Name(const char *Hostname)
{
    if (ESP32_WiFi.setHostname(Hostname))
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

const char* WiFi_Class::Get_Host_Name()
{
    return ESP32_WiFi.getHostname();
}

void WiFi_Class::Use_Static_Buffers(bool Status)
{
    ESP32_WiFi.useStaticBuffers(Status);
}

int16_t WiFi_Class::Scan(bool Async = false, bool Show_Hidden = false, bool Passive = false, uint32_t Max_Ms_Per_Channel = 300, uint8_t Channel = 0)
{
    return ESP32_WiFi.scanNetworks(Async);
}

int16_t WiFi_Class::Scan_Complete()
{
    return ESP32_WiFi.scanComplete();
}

void WiFi_Class::Scan_Delete()
{
    ESP32_WiFi.scanDelete();
}

void WiFi_Class::Get_Informations(uint8_t Index, String& SSID, uint8_t& Encryption_Type, int32_t& RSSI, uint8_t*& BSSID, int32_t& Channel)
{
    ESP32_WiFi.getNetworkInfo(Index, SSID, Encryption_Type, RSSI, BSSID, Channel);
}

void WiFi_Class::Set_Automatic_Reconnection(bool Enable)
{
    ESP32_WiFi.setAutoReconnect(Enable);
}

bool WiFi_Class::Set_Mode(Mode_Type Mode)
{
    return ESP32_WiFi.mode(Convert_Mode(Mode));
}

void WiFi_Class::Set_Channel(uint8_t Channel)
{
    ESP32_WiFi.setChannel(Channel);
}

void WiFi_Class::Set_Power(int8_t dBm)
{
    ESP32_WiFi.setOutputPower(dBm);
}



#endif