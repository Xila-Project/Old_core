///
 /// @file IP_Address.cpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 16-02-2023
 /// 
 /// @copyright Copyright (c) 2023
 /// 

#include "Core/Communication/IP_Address.hpp"

#include <WiFi.h>

using namespace Xila_Namespace;

IP_Address_Class::IP_Address_Class(const IPAddress& IP_Address)
    : Is_IPv4(true)
{
    Address.DWord = IP_Address;
}

IP_Address_Class::IP_Address_Class(const IPv6Address& IP_Address)
    : Is_IPv4(false)
{
    memcpy(Address.Bytes, (const uint8_t*)IP_Address, sizeof(Address.Bytes));
}

IP_Address_Class::IP_Address_Class(bool Is_IPv4)
    : Is_IPv4(Is_IPv4)
{
    memset(Address.Bytes, 0, sizeof(Address.Bytes));
}

IP_Address_Class::IP_Address_Class(uint32_t Address)
    : Is_IPv4(true)
{
    this->Address.DWord = Address;
}

IP_Address_Class::IP_Address_Class(const uint8_t *Address, bool Is_IPv4)
    : Is_IPv4(Is_IPv4)
{
    if (Is_IPv4)
    {
        memcpy(this->Address.Bytes, Address, 4);
    }
    else
    {
        memset(this->Address.Bytes, 0, sizeof(this->Address.Bytes));
    }
}

IP_Address_Class::IP_Address_Class(uint8_t Byte_1, uint8_t Byte_2, uint8_t Byte_3, uint8_t Byte_4)
{
    Address.Bytes[0] = Byte_1;
    Address.Bytes[1] = Byte_2;
    Address.Bytes[2] = Byte_3;
    Address.Bytes[3] = Byte_4;
}

IP_Address_Class::operator uint32_t() const
{
    return Address.DWord;
}

IP_Address_Class::operator IPAddress() const
{
    return IPAddress(Address.DWord);
}

IP_Address_Class::operator IPv6Address() const
{
    return IPv6Address(Address.Bytes);
}

bool IP_Address_Class::operator==(const IP_Address_Class& IP_Address) const
{
    return (IP_Address.Address.DWord == this->Address.DWord) && (IP_Address.Is_IPv4 == this->Is_IPv4);
}

bool IP_Address_Class::operator==(const uint8_t* Address) const
{

    return (memcmp(Address, this->Address.Bytes, sizeof(this->Address.Bytes)) == 0);
}

uint8_t IP_Address_Class::operator[](uint8_t Index) const
{
    if ((Index < 4) && (Is_IPv4))
    {
        return Address.Bytes[Index];
    }
    else if ((Index < 16) && (!Is_IPv4))
    {
        return Address.Bytes[Index];
    }
    return 0;
}

uint8_t& IP_Address_Class::operator[](uint8_t Index)
{
    if ((Index < 4) && (Is_IPv4))
    {
        return Address.Bytes[Index];
    }
    else if ((Index < 16) && (!Is_IPv4))
    {
        return Address.Bytes[Index];
    }
    return Address.Bytes[0];
}

void IP_Address_Class::Set_IP_Version(bool Is_IPv4)
{
    this->Is_IPv4 = Is_IPv4;
}

bool IP_Address_Class::Get_IP_Version() const
{
    return Is_IPv4;
}