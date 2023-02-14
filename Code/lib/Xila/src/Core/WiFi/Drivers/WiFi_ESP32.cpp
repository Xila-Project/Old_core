#if true

#include "Core/Communication/WiFi.hpp"

#include <WiFi.h>

// Type conversion

wl_status_t Convert_Status(WiFi_Class::Status_Type Status)
{
    switch (Status)
    {
    case No_Shield:
        return WL_NO_SHIELD;
        break;
    case Idle:
        return WL_IDLE_STATUS;
        break;
    case No_SSID_Available:
        return WL_NO_SSID_AVAIL;
        break;
    case Scan_Completed:
        return WL_SCAN_COMPLETED;
        break;
    case Connected:
        return WL_CONNECTED;
        break;
    case Connection_Failed: 
        return WL_CONNECT_FAILED;
        break;
    case Connection_Lost:
        return WL_CONNECTION_LOST;
        break;
    case Disconnected:  
        return WL_DISCONNECTED;
        break;
    }
        
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

IP_Address_Type WiFi_Class::Get_Gateway_IP_Address()
{
    // TODO : Do the convertion
    //return WiFi.gatewayIP();
}
 


#endif