/// @file Two_Wire_Interface.cpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 12-05-2023
///
/// @copyright Copyright (c) 2023

#include "Pin/Two_Wire_Interface.hpp"

using namespace Xila_Namespace;
using namespace Pin_Types;

Two_Wire_Class::Two_Wire_Class(TwoWire &Wire) : Wire(Wire)
{
}

Result_Type Two_Wire_Class::Begin(int8_t SDA_Pin, int8_t SCL_Pin, uint32_t Frequency, int16_t Slave_Address)
{
    if (Slave_Address != -1)
    {
        return (Result_Type)Wire.begin(SDA_Pin, SCL_Pin, Frequency, Slave_Address);
    }

    return (Result_Type)Wire.begin(SDA_Pin, SCL_Pin, Frequency);
}

Result_Type Two_Wire_Class::End()
{
    return (Result_Type)Wire.end();
}

void Two_Wire_Class::Begin_Transmission(uint16_t Address)
{
    Wire.beginTransmission(Address);
}

Result_Type Two_Wire_Class::End_Transmission(bool Send_Stop)
{
    return (Result_Type)Wire.endTransmission(Send_Stop);
}

Size_Type Two_Wire_Class::Request_From(uint16_t Address, Size_Type Size, bool Send_Stop)
{
    return Wire.requestFrom(Address, (size_t)Size, Send_Stop);
}

int Two_Wire_Class::Available()
{
    return Wire.available();
}

int Two_Wire_Class::Peek()
{
    return Wire.peek();
}

int Two_Wire_Class::Read()
{
    return Wire.read();
}

Size_Type Two_Wire_Class::Read_Bytes(Byte_Type *Buffer, Size_Type Length)
{
    return Wire.readBytes(Buffer, Length);
}

String_Type &Two_Wire_Class::Read_String(String_Type &String)
{
    Read_Bytes((Byte_Type *)(char*)String, String.Get_Capacity());
    return String;
}

void Two_Wire_Class::Flush()
{
    Wire.flush();
}

Size_Type Two_Wire_Class::Write(Byte_Type Data)
{
    return Wire.write(Data);
}

Size_Type Two_Wire_Class::Write_Bytes(const Byte_Type *Data, Size_Type Size)
{
    return Wire.write(Data, Size);
}

Size_Type Two_Wire_Class::Slave_Write(const Byte_Type *Data, Size_Type Size)
{
    return Wire.slaveWrite(Data, Size);
}

void Two_Wire_Class::Set_Timeout(uint16_t Timeout)
{
    Wire.setTimeout(Timeout);
}

// - - Getters

uint16_t Two_Wire_Class::Get_Timeout()
{
    return Wire.getTimeout();
}

uint32_t Two_Wire_Class::Get_Clock_Frequency()
{
    return Wire.getClock();
}

// - - Setters

void Two_Wire_Class::Set_Clock_Frequency(uint32_t Frequency)
{
    Wire.setClock(Frequency);
}

Result_Type Two_Wire_Class::Set_Pins(int SDA_Pin, int SCL_Pin)
{
    return (Result_Type)Wire.setPins(SDA_Pin, SCL_Pin);
}


