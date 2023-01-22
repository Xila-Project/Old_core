#if WiFi_Hardware == WiFi_Hardware_ESP32

#include "Core/Communication/WiFi.hpp"

#include <WiFi.h>

// Type conversion

wl_status_t Convert_Status(WiFi_Class::Status_Type Status)
{
    switch (Status)
    {
    case WiFi_Class::Status_Type::Ready:
        return WL_IDLE_STATUS;
    case WiFi_Class::Status_Type::Scan_Done:
        return WL_SCAN_COMPLETED;
    case WiFi_Class::Status_Type::Station_Start:
        return WL_CONNECTED;
    case WiFi_Class::Status_Type::Station_Stop:
        return WL_DISCONNECTED;
    case WiFi_Class::Status_Type::Station_Connect:
        return WL_CONNECTED;
    case WiFi_Class::Status_Type::Station_Disconnected:
        return WL_DISCONNECTED;
    case WiFi_Class::Status_Type::Station_Authentication_Mode_Changed:
        return WL_CONNECTED;
    case WiFi_Class::Status_Type::Station_Got_IP:
        return WL_CONNECTED;
    case WiFi_Class::Status_Type::Station_Got_IP_V6:
        return WL_CONNECTED;
    case WiFi_Class::Status_Type::Station_Lost_IP:
        return WL_DISCONNECTED;
    case WiFi_Class::Status_Type::Station_WPS_Enrolment_Success:
        return WL_CONNECTED;
    case WiFi_Class::Status_Type::Station_WPS_Enrolment_Failed:
        return WL_DISCONNECTED;
    case WiFi_Class::Status_Type::Station_WPS_Enrolment_Timeout:
        return WL_DISCONNECTED;
    case WiFi_Class::Status_Type::Station_WPS_Enrolment_Pin:
        return WL_CONNECTED;
    case WiFi_Class::Status_Type::Access_Point_Start:
        return WL_CONNECTED;
    case WiFi_Class::Status_Type::Access_Point_Stop:
        return WL_DISCONNECTED;
    case WiFi_Class::Status_Type::Access_Point_Station_Connected:
        return WL_CONNECTED;
    case WiFi_Class::Status_Type::Access_Point_Station_IP_Assigned:
        return WL_CONNECTED;
    case WiFi_Class::Status_Type::Access_Point_Probe_Request_Received:

        
}



WiFi_Class::WIFi_Class()
{

}

void WiFi_Class::Use_Static_Buffers(bool Static)
{
    WiFi.useStaticBuffers(Static);
}

WiFi_Type::Status_Type WiFi_Class::Connect(const char* SSID, const char* Password, int32_t Channel, const uint8_t* BSSID, bool Connect)
{
    wl_status_t Status = WiFi.begin(SSID, Password, Channel, BSSID, Connect);
    if (Status == true)
    {
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
        }
    }
    return WiFi.status();
}

WiFi_Type::Status_Type WiFi_Class::Connect(char* SSID, char* Password, int32_t Channel, const uint8_t* BSSID, bool Connect)
{
    wl_status_t Status = WiFi.begin(SSID, Password, Channel, BSSID, Connect);
    if (Connect == true)
    {
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
        }
    }
    return WiFi.status();
}

void WiFi_Class::Set_Configuration(IP_Address_Type IP_Address, IP_Address_Type Subnet_Mask, IP_Address_Type Gateway)
{
    // TODO : Do the convertion
    //WiFi.config(IP_Address, Subnet_Mask, Gateway);
}

void WiFi_Class::Set_Configuration(IP_Address_Type IP_Address, IP_Address_Type Subnet_Mask, IP_Address_Type Gateway, IP_Address_Type DNS_1, IP_Address_Type DNS_2)
{
    // TODO : Do the convertion 
    //WiFi.config(IP_Address, Subnet_Mask, Gateway, DNS_1, DNS_2);
}

IP_Address_Type WiFi_Class::Get_IP_Address()
{
    // TODO : Do the convertion
    //return WiFi.localIP();
}

#endif