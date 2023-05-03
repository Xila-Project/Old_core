
 /// @file IP_Address.cpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 16-02-2023
 /// 
 /// @copyright Copyright (c) 2023

#include "Core/Communication/IP_Address.hpp"

#include <WiFi.h>

using namespace Xila_Namespace;
using namespace Xila_Namespace::Communication_Types;

IP_Address_Class::IP_Address_Class() : Is_IPv4(true)
{

}

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

IP_Address_Class& IP_Address_Class::operator=(const uint8_t* Address)
{
    if (Is_IPv4)
    {
        memcpy(this->Address.Bytes, Address, sizeof(this->Address.Bytes));
    }
    else
    {
        memcpy(this->Address.Bytes, Address, sizeof(this->Address.Bytes));
    }
    return *this;
}

IP_Address_Class& IP_Address_Class::operator=(const uint32_t Address)
{
    this->Address.DWord = Address;
    return *this;
}

String_Type& IP_Address_Class::To(String_Class& String) const
{
    if (Is_IPv4)
    {
        String.Copy_Format("%d.%d.%d.%d", Address.Bytes[0], Address.Bytes[1], Address.Bytes[2], Address.Bytes[3]);
    }
    else
    {
        String.Copy_Format("%x%x:%x%x:%x%x:%x%x:%x%x:%x%x:%x%x:%x%x", Address.Bytes[0], Address.Bytes[1], Address.Bytes[2], Address.Bytes[3], Address.Bytes[4], Address.Bytes[5], Address.Bytes[6], Address.Bytes[7], Address.Bytes[8], Address.Bytes[9], Address.Bytes[10], Address.Bytes[11], Address.Bytes[12], Address.Bytes[13], Address.Bytes[14], Address.Bytes[15]);
    }
}

bool IP_Address_Class::Is_IP_v4() const
{
    return Is_IPv4;
}

void IP_Address_Class::Set_IP_Version(bool Is_IPv4)
{
    this->Is_IPv4 = Is_IPv4;
}