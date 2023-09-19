
/// @file IP_Address.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 16-02-2023
///
/// @copyright Copyright (c) 2023

#include "Network/IP_Address.hpp"

#include "arpa/inet.h"

#include <WiFi.h>

using namespace Xila_Namespace;
using namespace Xila_Namespace::Network_Types;

IP_Address_Class::IP_Address_Class() : Is_IPv4(true)
{
    memset(this->Bytes, 0, sizeof(this->Bytes));
}

IP_Address_Class::IP_Address_Class(DWord_Type Address)
    : Is_IPv4(true)
{
    this->DWord = Address;
}

IP_Address_Class::IP_Address_Class(const uint8_t *Address, bool Is_IPv4)
    : Is_IPv4(Is_IPv4)
{
    if (Is_IPv4)
        memcpy(this->Bytes, Address, 4);
    else
        memset(this->Bytes, 0, sizeof(this->Bytes));
}

IP_Address_Class::IP_Address_Class(const String_Type &String) : IP_Address_Class()
{
    if (Parse_IP_v4(String, this->DWord) == Result_Type::Success)
        Is_IPv4 = true;
    else if (Parse_IP_v6(String, *this->Words) == Result_Type::Success)
        Is_IPv4 = false;
    
}

IP_Address_Class::IP_Address_Class(uint8_t Byte_1, uint8_t Byte_2, uint8_t Byte_3, uint8_t Byte_4)
{
    this->Bytes[0] = Byte_1;
    this->Bytes[1] = Byte_2;
    this->Bytes[2] = Byte_3;
    this->Bytes[3] = Byte_4;
}

IP_Address_Class::operator uint32_t() const
{
    return this->DWord;
}

IP_Address_Class::operator IPAddress() const
{
    return IPAddress(this->DWord);
}

IP_Address_Class::operator IPv6Address() const
{
    return IPv6Address(this->Bytes);
}

bool IP_Address_Class::operator==(const IP_Address_Class &IP_Address) const
{
    return (IP_Address.DWord == this->DWord) && (IP_Address.Is_IPv4 == this->Is_IPv4);
}

bool IP_Address_Class::operator==(const uint8_t *Address) const
{
    return (memcmp(Address, this->Bytes, sizeof(this->Bytes)) == 0);
}

uint8_t IP_Address_Class::operator[](uint8_t Index) const
{
    if ((Index < 4) && (Is_IPv4))
        return this->Bytes[Index];
    else if ((Index < 16) && (!Is_IPv4))
        return this->Bytes[Index];
    return 0;
}

uint8_t &IP_Address_Class::operator[](uint8_t Index)
{
    if ((Index < 4) && (Is_IPv4))
        return this->Bytes[Index];
    else if ((Index < 16) && (!Is_IPv4))
        return this->Bytes[Index];
    return this->Bytes[0];
}

IP_Address_Class &IP_Address_Class::operator=(const uint8_t *Address)
{
    if (Is_IPv4)
    {
        memcpy(this->Bytes, Address, sizeof(this->Bytes));
    }
    else
    {
        memcpy(this->Bytes, Address, sizeof(this->Bytes));
    }
    return *this;
}

IP_Address_Class &IP_Address_Class::operator=(const uint32_t Address)
{
    this->DWord = Address;
    return *this;
}

String_Type &IP_Address_Class::To(String_Class &String) const
{
    if (Is_IPv4)
        String.Copy_Format("%u.%u.%u.%u", this->Bytes[0], this->Bytes[1], this->Bytes[2], this->Bytes[3]);
    else
        String.Copy_Format("%x:%x:%x:%x:%x:%x:%x:%x", this->Words[0], this->Words[1], this->Words[2], this->Words[3], this->Words[4], this->Words[5], this->Words[6], this->Words[7]);

    return String;
}

bool IP_Address_Class::Is_IP_v4() const
{
    return Is_IPv4;
}

void IP_Address_Class::Set_IP_Version(bool Is_IPv4)
{
    this->Is_IPv4 = Is_IPv4;
}

Result_Type IP_Address_Class::Parse_IP_v4(const String_Type &String, uint32_t& Address)
{
    Natural_Type Values[4];
    memset(Values, 0, sizeof(Values));
   
    Integer_Type Count = String.Scan("%u.%u.%u.%u", Values[0], Values[1], Values[2], Values[3]);

    if (Count != 4)
        return Result_Type::Error;

    for (uint8_t i = 0; i < 4; i++)
    {
        if (Values[i] > 0xFF)
            return Result_Type::Error;
    }

    Address = 0;

    for (uint8_t i = 0; i < 4; i++)
        Address |= ((Byte_Type)Values[3 - i]) << (i * 8);


    return Result_Type::Success;
}

Result_Type IP_Address_Class::Parse_IP_v6(const String_Type& String, uint16_t& Address)
{
    // TODO
    return Result_Type::Error;
}