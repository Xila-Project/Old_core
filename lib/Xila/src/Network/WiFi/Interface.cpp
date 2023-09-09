/// @file Interface.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief 
/// @version 0.1.0
/// @date 08-08-2023
///
/// @copyright Copyright (c) 2023

#ifdef Xila_WiFi_Hardware_ESP32

#include "Network/WiFi/Interface.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Network_Types;

IP_Address_Type WiFi_Interface_Class::Get_IP_Address(bool IPv6)
{
    if (Get_Mode() == Mode_Type::Access_Point)
        return Access_Point.Get_IP_Address();

    return Station.Get_IP_Address(IPv6);
}

IP_Address_Type WiFi_Interface_Class::Get_Gateway_IP_Address()
{
    if (Get_Mode() == Mode_Type::Access_Point)
        return Access_Point.Get_Gateway_IP_Address();

    return Station.Get_Gateway_IP_Address();
}

IP_Address_Type WiFi_Interface_Class::Get_Subnet_Mask()
{
    if (Get_Mode() == Mode_Type::Access_Point)
        return Access_Point.Get_Subnet_Mask();

    return Station.Get_Subnet_Mask();
}

IP_Address_Type WiFi_Interface_Class::Get_DNS_IP_Address(Natural_Type Index)
{
    return Station.Get_DNS_IP_Address(Index);
}

Byte_Type WiFi_Interface_Class::Get_Subnet_CIDR()
{
    if (Get_Mode() == Mode_Type::Access_Point)
        return Access_Point.Get_Subnet_CIDR();

    return Station.Get_Subnet_CIDR();
}

Result_Type WiFi_Interface_Type::Set_Configuration(IP_Address_Type IP_Address, IP_Address_Type Subnet_Mask, IP_Address_Type Gateway, IP_Address_Type DNS_1_IP_Address, IP_Address_Type DNS_2_IP_Address)
{
    if (Get_Mode() == Mode_Type::Access_Point)
        return Access_Point.Set_Configuration(IP_Address, Gateway, Subnet_Mask);

    return Station.Set_Configuration(IP_Address, Subnet_Mask, Gateway, DNS_1_IP_Address, DNS_2_IP_Address);
}


#endif