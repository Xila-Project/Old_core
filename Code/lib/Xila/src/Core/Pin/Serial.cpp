 /// @file Serial.cpp
 /// @author Alix ANNERAUD (alix@anneraud.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 12-05-2023
 /// 
 /// @copyright Copyright (c) 2023
 
 #include "Core/Pin/Serial.hpp"

using namespace Xila_Namespace;
using namespace Pin_Types;


Serial_Class::Serial_Class(HardwareSerial& Serial) : Serial(Serial)
{
}

void Serial_Class::Begin(unsigned long Baud_Rate, Serial_Configuration_Type Configuration, int8_t Receive_Pin, int8_t Transmit_Pin, bool Invert, unsigned long Timeout)
{
    Serial.begin(Baud_Rate, static_cast<uint32_t>(Configuration), Receive_Pin, Transmit_Pin, Invert, Timeout);
}

void Serial_Class::End()
{
    Serial.end();
}

int Serial_Class::Available()
{
    return Serial.available();
}

int Serial_Class::Available_For_Write()
{
    return Serial.availableForWrite();
}

int Serial_Class::Peek()
{
    return Serial.peek();
}

int Serial_Class::Read()
{
    return Serial.read();
}

Size_Type Serial_Class::Read_Bytes(Byte_Type* Buffer, Size_Type Length)
{
    return Serial.readBytes(Buffer, Length);
}

String_Type& Serial_Class::Read_String(String_Type& String)
{
    Serial.read((char*)String, String.Get_Size());
    return String;
}

Size_Type Serial_Class::Write(Byte_Type Byte)
{
    return Serial.write(Byte);
}

Size_Type Serial_Class::Write_Bytes(const Byte_Type* Buffer, Size_Type Length)
{
    return Serial.write(Buffer, Length);
}

Size_Type Serial_Class::Write_String(String_Type& String)
{
    return Serial.write((const char*)String);
}

// - - Setters

void Serial_Class::Set_Baud_Rate(unsigned long Baud_Rate)
{
    Serial.updateBaudRate(Baud_Rate);
}

Result_Type Serial_Class::Set_Pins(int8_t Receive_Pin, int8_t Transmit_Pin, int8_t CTS_Pin, int8_t RTS_Pin)
{
    return (Result_Type)Serial.setPins(Receive_Pin, Transmit_Pin, CTS_Pin, RTS_Pin);
}

Result_Type Serial_Class::Set_Hardware_Flow_Control(bool State, bool RTS_Enable, bool CTS_Enable, int8_t Threshold)
{
    if (State)
    {
        if ((RTS_Enable) && (CTS_Enable))
            return (Result_Type)Serial.setHwFlowCtrlMode(HW_FLOWCTRL_CTS_RTS, Threshold);
        else if (RTS_Enable)
            return (Result_Type)Serial.setHwFlowCtrlMode(HW_FLOWCTRL_RTS, Threshold);
        else if (CTS_Enable)
            return (Result_Type)Serial.setHwFlowCtrlMode(HW_FLOWCTRL_CTS, Threshold);
    }

    return (Result_Type)Serial.setHwFlowCtrlMode(HW_FLOWCTRL_DISABLE, Threshold);
}

Result_Type Serial_Class::Set_Mode(Serial_Mode_Type Mode)
{
    return (Result_Type)Serial.setMode(static_cast<uint8_t>(Mode));
}

Result_Type Serial_Class::Set_Receive_Buffer_Size(Size_Type Size)
{
    return (Result_Type)Serial.setRxBufferSize(Size);
}

Result_Type Serial_Class::Set_Transmit_Buffer_Size(Size_Type Size)
{
    return (Result_Type)Serial.setTxBufferSize(Size);
}

uint32_t Serial_Class::Get_Baud_Rate()
{
    return Serial.baudRate();
}

// - - Operators

Serial_Class::operator bool() const
{
    return (Serial);
}




