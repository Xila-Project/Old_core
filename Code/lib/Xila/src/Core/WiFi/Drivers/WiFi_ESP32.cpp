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

WiFiClass& ESP32_WiFi = WiFi;

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

wifi_auth_mode_t Convert_Authentification_Mode(Authentification_Mode_Type Authentification_Mode)
{
    switch (Authentification_Mode)
    {
    case Authentification_Mode_Type::WEP:
        return WIFI_AUTH_WEP;
    case Authentification_Mode_Type::WPA_PSK:
        return WIFI_AUTH_WPA_PSK;
    case Authentification_Mode_Type::WPA2_PSK:
        return WIFI_AUTH_WPA2_PSK;
    case Authentification_Mode_Type::WPA_WPA2_PSK:
        return WIFI_AUTH_WPA_WPA2_PSK;
    case Authentification_Mode_Type::WPA2_ENTERPRISE:
        return WIFI_AUTH_WPA2_ENTERPRISE;
    case Authentification_Mode_Type::WPA3_PSK:
        return WIFI_AUTH_WPA3_PSK;
    case Authentification_Mode_Type::WPA2_WPA3_PSK:
        return WIFI_AUTH_WPA2_WPA3_PSK;
    case Authentification_Mode_Type::WAPI_PSK:
        return WIFI_AUTH_WAPI_PSK;
    case Authentification_Mode_Type::MAX:
        return WIFI_AUTH_MAX;
    default:
        return WIFI_AUTH_OPEN;
    }
}

Authentification_Mode_Type Convert_Authentification_Mode(wifi_auth_mode_t Authentification_Mode)
{
    switch (Authentification_Mode)
    {
    case WIFI_AUTH_WEP:
        return Authentification_Mode_Type::WEP;
    case WIFI_AUTH_WPA_PSK:
        return Authentification_Mode_Type::WPA_PSK;
    case WIFI_AUTH_WPA2_PSK:
        return Authentification_Mode_Type::WPA2_PSK;
    case WIFI_AUTH_WPA_WPA2_PSK:
        return Authentification_Mode_Type::WPA_WPA2_PSK;
    case WIFI_AUTH_WPA2_ENTERPRISE:
        return Authentification_Mode_Type::WPA2_ENTERPRISE;
    case WIFI_AUTH_WPA3_PSK:
        return Authentification_Mode_Type::WPA3_PSK;
    case WIFI_AUTH_WPA2_WPA3_PSK:
        return Authentification_Mode_Type::WPA2_WPA3_PSK;
    case WIFI_AUTH_WAPI_PSK:
        return Authentification_Mode_Type::WAPI_PSK;
    case WIFI_AUTH_MAX:
        return Authentification_Mode_Type::MAX;
    default:
        return Authentification_Mode_Type::Open;
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

void WiFi_Class::Turn_Off()
{
    ESP32_WiFi.mode(WIFI_OFF);
}

int32_t WiFi_Class::Get_Channel()
{
    return ESP32_WiFi.channel();
}

Mode_Type WiFi_Class::Get_Mode()
{
    return Convert_Mode(ESP32_WiFi.getMode());
}

int16_t WiFi_Class::Get_Transmission_Power()
{
    return ESP32_WiFi.getTxPower();
}

void WiFi_Class::Get_Host_Name(String_Type& Host_Name)
{
    Host_Name = ESP32_WiFi.getHostname();
}

void WiFi_Class::Set_Long_Range(bool Enable)
{
    ESP32_WiFi.enableLongRange(Enable);
    Long_Range = Enable;
}

Result_Type WiFi_Class::Set_Transmission_Power(int16_t Power)
{
    if (ESP32_WiFi.setTxPower(Convert_Power(Power)))
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

Result_Type WiFi_Class::Set_Host_Name(const String_Type& Host_Name)
{
    if (Host_Name)
    {
        if (ESP32_WiFi.setHostname(Host_Name))
        {
            return Result_Type::Success;
        }
    }
    return Result_Type::Error;
}

// - - Station

/// @brief Connect to an access point.
/// @param SSID SSID of the access point.
/// @param Password Password of the access point.
/// @param Channel Channel of the access point.
/// @param BSSID BSSID of the access point.
void WiFi_Class::Station_Class::Connect(const String_Type& SSID, const String_Type& Password, int32_t Channel, const uint8_t *BSSID)
{
    if (Password == "")
    {
        ESP32_WiFi.begin(SSID, NULL, Channel, BSSID, true);
    }
    else
    {
        ESP32_WiFi.begin(SSID, Password, Channel, BSSID, true);
    }
}

/// @brief Disconnect from the current access point.
/// @return Result_Type
Result_Type WiFi_Class::Station_Class::Disconnect()
{
    if (ESP32_WiFi.disconnect(false))
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

/// @brief Get the current automatic reconnection status.
/// @return true if automatic reconnection is enabled, false otherwise.
bool WiFi_Class::Station_Class::Get_Automatic_Reconnection()
{
    return ESP32_WiFi.getAutoReconnect();
}

/// @brief Get the station status.
/// @param Wait_For_Connect
/// @param Timeout
/// @return Status_Type
WiFi_Types::Status_Type WiFi_Class::Station_Class::Get_Status(bool Wait_For_Connect, uint32_t Timeout)
{
    if (Wait_For_Connect)
    {
        return Convert_Status(static_cast<wl_status_t>(ESP32_WiFi.waitForConnectResult(Timeout)));
    }
    return Convert_Status(ESP32_WiFi.status());
}

/// @brief Get the current SSID (Service Set Identifier) of the connected AP.
/// @return Pointer to a null-terminated string containing the SSID.
void WiFi_Class::Station_Class::Get_SSID(String_Type& SSID)
{
    SSID = ESP32_WiFi.SSID();
}

/// @brief Get the current Pre-Shared Key (PSK) of the connected AP.
/// @return Pointer to a null-terminated string containing the PSK.
void WiFi_Class::Station_Class::Get_Pre_Shared_Key(String_Type& Pre_Shared_Key)
{
    Pre_Shared_Key = ESP32_WiFi.psk();
}

/// @brief Get the current BSSID (Basic Service Set Identifier) of the connected AP.
/// @return Pointer to an array of 6 bytes containing the BSSID.
uint8_t *WiFi_Class::Station_Class::Get_BSSID()
{
    return ESP32_WiFi.BSSID();
}

/// @brief Get the current RSSI /Received Signal Strength in dBm) value.
/// @return RSSI in dBm (negative value)
int8_t WiFi_Class::Station_Class::Get_RSSI()
{
    return ESP32_WiFi.RSSI();
}

/// @brief Get the MAC address of the WiFi controller
/// @param MAC_Address Pointer to an array of 6 bytes to store the MAC address.
/// @return uint8_t*
uint8_t *WiFi_Class::Station_Class::Get_MAC_Address(uint8_t *MAC_Address)
{
    return ESP32_WiFi.macAddress(MAC_Address);
}

/// @brief Get the IP address of the station.
/// @param IPv6 If true, return the IPv6 address, otherwise return the IPv4 address.
/// @return IP_Address_Type
IP_Address_Type WiFi_Class::Station_Class::Get_IP_Address(bool IPv6)
{
    if (IPv6)
    {
        return ESP32_WiFi.localIPv6();
    }
    return IP_Address_Type(ESP32_WiFi.localIP());
}

/// @brief Get the subnet mask of the station.
/// @return IP_Address_Type
IP_Address_Type WiFi_Class::Station_Class::Get_Subnet_Mask()
{
    return IP_Address_Type(ESP32_WiFi.subnetMask());
}

/// @brief Get the gateway IP address of the station.
/// @return IP_Address_Type
IP_Address_Type WiFi_Class::Station_Class::Get_Gateway_IP_Address()
{
    return IP_Address_Type(ESP32_WiFi.gatewayIP());
}

/// @brief Get the IP address of the DNS server.
/// @param Index Index of the DNS server to get the IP address of.
/// @return IP_Address_Type
IP_Address_Type WiFi_Class::Station_Class::Get_DNS_IP_Address(uint8_t Index)
{
    return IP_Address_Type(ESP32_WiFi.dnsIP(Index));
}

/// @brief Get the broadcast IP address of the station.
/// @return IP_Address_Type Broadcast IP address.
IP_Address_Type WiFi_Class::Station_Class::Get_Broadcast_IP_Address()
{
    return IP_Address_Type(ESP32_WiFi.broadcastIP());
}

/// @brief Get the network ID of the station.
/// @return IP_Address_Type Network ID.
IP_Address_Type WiFi_Class::Station_Class::Get_Network_ID()
{
    return IP_Address_Type(ESP32_WiFi.networkID());
}

/// @brief Get the subnet CIDR of the station.
/// @return uint8_t Subnet CIDR.
uint8_t WiFi_Class::Station_Class::Get_Subnet_CIDR()
{
    return ESP32_WiFi.subnetCIDR();
}

/// @brief Set the network configuration of the station.
/// @param IP_Address Local IP address.
/// @param Subnet_Mask Subnet mask.
/// @param Gateway_IP_Address Gateway IP address.
/// @param DNS_1_IP_Address Primary DNS server IP address.
/// @param DNS_2_IP_Address Secondary DNS server IP address.
/// @return Result_Type
Result_Type WiFi_Class::Station_Class::Set_Configuration(IP_Address_Type IP_Address, IP_Address_Type Subnet_Mask, IP_Address_Type Gateway_IP_Address, IP_Address_Type DNS_1_IP_Address, IP_Address_Type DNS_2_IP_Address)
{
    if (ESP32_WiFi.config(IP_Address, Gateway_IP_Address, Subnet_Mask, DNS_1_IP_Address, DNS_2_IP_Address))
    {
        this->IP_Address = IP_Address;
        this->Subnet_Mask = Subnet_Mask;
        this->Gateway_IP_Address = Gateway_IP_Address;
        this->DNS_1_IP_Address = DNS_1_IP_Address;
        this->DNS_2_IP_Address = DNS_2_IP_Address;
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

/// @brief
/// @param Enabled
/// @return
bool WiFi_Class::Station_Class::Set_Automatic_Reconnection(bool Enabled)
{
    ESP32_WiFi.setAutoReconnect(Enabled);
    return Enabled;
}

/// @brief Set the scan method when connecting to an access point.
/// @param Fast If true, first SSID match, otherwise wait until the end of the scan (RSSI and Security).
void WiFi_Class::Station_Class::Set_Scan_Method(bool Fast)
{
    if (Fast)
    {
        ESP32_WiFi.setScanMethod(WIFI_FAST_SCAN);
    }
    else
    {
        ESP32_WiFi.setScanMethod(WIFI_ALL_CHANNEL_SCAN);
    }
}

/// @brief Set the way that access points are sorted.
/// @param Retries If true, first SSID match, otherwise Security match.
void WiFi_Class::Station_Class::Set_Sort_Method(bool Signal)
{
    if (Signal)
    {
        ESP32_WiFi.setSortMethod(WIFI_CONNECT_AP_BY_SIGNAL);
    }
    else
    {
        ESP32_WiFi.setSortMethod(WIFI_CONNECT_AP_BY_SECURITY);
    }
}

// - Access point

Result_Type WiFi_Class::Access_Point_Class::Create(const String_Type& SSID, const String_Type& Password, int32_t Channel, bool Hidden, uint8_t Maximum_Stations, bool FTM_Responder)
{
    if (Password.Get_Length() <= this->Password.Get_Length())
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

void WiFi_Class::Access_Point_Class::Get_SSID(String_Type& SSID)
{
    SSID = ESP32_WiFi.softAPSSID();
}

void WiFi_Class::Access_Point_Class::Get_Password(String_Type& Password)
{
    Password = this->Password;
}

uint8_t WiFi_Class::Access_Point_Class::Get_Channel()
{
    return this->Channel;
}

bool WiFi_Class::Access_Point_Class::Get_Hidden()
{
    return this->Hidden;
}

uint8_t WiFi_Class::Access_Point_Class::Get_Maximum_Stations()
{
    return this->Maximum_Stations;
}

uint8_t WiFi_Class::Access_Point_Class::Get_Station_Number()
{
    return ESP32_WiFi.softAPgetStationNum();
}

IP_Address_Type WiFi_Class::Access_Point_Class::Get_IP_Address()
{
    return IP_Address_Type(ESP32_WiFi.softAPIP());
}

IP_Address_Type WiFi_Class::Access_Point_Class::Get_Subnet_Mask()
{
    return Subnet_Mask;
}

IP_Address_Type WiFi_Class::Access_Point_Class::Get_Gateway_IP_Address()
{
    return Gateway_IP_Address;
}

IP_Address_Type WiFi_Class::Access_Point_Class::Get_DHCP_Start_IP_Address()
{
    return DHCP_Lease_Start_IP_Address;
}

IP_Address_Type WiFi_Class::Access_Point_Class::Get_Broadcast_IP_Address()
{
    return IP_Address_Type(ESP32_WiFi.softAPBroadcastIP());
}

IP_Address_Type WiFi_Class::Access_Point_Class::Get_Network_ID()
{
    return IP_Address_Type(ESP32_WiFi.softAPNetworkID());
}

uint8_t WiFi_Class::Access_Point_Class::Get_Subnet_CIDR()
{
    return ESP32_WiFi.softAPSubnetCIDR();
}

Result_Type WiFi_Class::Access_Point_Class::Set_IP_v6(bool Enable)
{
    if (Enable)
    {
        if (!ESP32_WiFi.enableIpV6())
        {
            return Result_Type::Error;
        }
    }
    return Result_Type::Success;
}

uint8_t *WiFi_Class::Access_Point_Class::Get_MAC_Address(uint8_t *MAC_Address)
{
    return ESP32_WiFi.softAPmacAddress(MAC_Address);
}

Result_Type WiFi_Class::Access_Point_Class::Set_Configuration(IP_Address_Type Local_IP, IP_Address_Type Gateway, IP_Address_Type Subnet, IP_Address_Type DHCP_Lease_Start_IP_Address)
{
    this->IP_Address = IP_Address;
    this->Subnet_Mask = Subnet_Mask;
    this->Gateway_IP_Address = Gateway_IP_Address;
    this->DHCP_Lease_Start_IP_Address = DHCP_Lease_Start_IP_Address;

    if (ESP32_WiFi.softAPConfig(IP_Address, Gateway_IP_Address, Subnet_Mask, DHCP_Lease_Start_IP_Address))
    {
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

// - - Scan

/// @brief Start a WiFi scan.
/// @param Async If true, start the scan in the background, otherwise wait for the scan to complete.
/// @param Show_Hidden If true, show hidden access points.
/// @param Passive If true, do not send probe requests.
/// @param Maximum_Milliseconds_Per_Channel Maximum time to spend on each channel.
/// @param Channel Channel to scan, 0 for all channels.
/// @param SSID SSID to scan for, NULL for all SSIDs.
/// @param BSSID BSSID to scan for, NULL for all BSSIDs.
/// @return uint16_t Number of access points found.
int16_t WiFi_Class::Scan_Class::Start(bool Asynchronous, bool Show_Hidden, bool Passive, uint32_t Maximum_Milliseconds_Per_Channel, uint8_t Channel, const String_Type& SSID, const uint8_t *BSSID)
{
    return ESP32_WiFi.scanNetworks(Asynchronous, Show_Hidden, Passive, Maximum_Milliseconds_Per_Channel, Channel, SSID, BSSID);
}

/// @brief Return if the scan is complete. Must be used in Asynchronous mode.
/// @return bool True if the scan is complete, otherwise false.
bool WiFi_Class::Scan_Class::Is_Complete()
{
    return (ESP32_WiFi.scanComplete() >= 0);
}

/// @brief Return the number of access points found.
/// @return bool True if the scan is complete, otherwise false.
int16_t WiFi_Class::Scan_Class::Get_Result()
{
    if (ESP32_WiFi.scanComplete() < 0)
    {
        return 0;
    }
    return ESP32_WiFi.scanComplete();
}

/// @brief Delete the scan results from memory.
void WiFi_Class::Scan_Class::Delete()
{
    ESP32_WiFi.scanDelete();
}

/// @brief Get the informations of a scanned access point.
/// @param Index Index of the access point.
/// @param SSID SSID of the access point.
/// @param Encryption_Type Encryption type of the access point.
/// @param RSSI RSSI of the access point.
/// @param BSSID BSSID of the access point.
/// @param Channel Channel of the access point.
/// @return Result_Type::Success if the informations are retrieved, otherwise Result_Type::Error.
Result_Type WiFi_Class::Scan_Class::Get_Informations(uint8_t Index, String_Type& SSID, uint8_t &Encryption_Type, int32_t &RSSI, uint8_t *&BSSID, int32_t &Channel)
{
    String SSID_String = "";
    if (ESP32_WiFi.getNetworkInfo(Index, SSID_String, Encryption_Type, RSSI, BSSID, Channel))
    {
        SSID = SSID_String;
        return Result_Type::Success;
    }
    return Result_Type::Error;
}

void WiFi_Class::Scan_Class::Get_SSID(uint8_t Index, String_Type& SSID)
{
    SSID = ESP32_WiFi.SSID(Index);
}

Authentification_Mode_Type WiFi_Class::Scan_Class::Get_Encryption(uint8_t Index)
{
    return Convert_Authentification_Mode(ESP32_WiFi.encryptionType(Index));
}

int32_t WiFi_Class::Scan_Class::Get_RSSI(uint8_t Index)
{
    return ESP32_WiFi.RSSI(Index);
}

uint8_t *WiFi_Class::Scan_Class::Get_BSSID(uint8_t Index)
{
    return ESP32_WiFi.BSSID(Index);
}

int32_t WiFi_Class::Scan_Class::Get_Channel(uint8_t Index)
{
    return ESP32_WiFi.channel(Index);
}

#endif