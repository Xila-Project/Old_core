/// @file Client.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 16-05-2023
///
/// @copyright Copyright (c) 2023

#ifdef Xila_WiFi_Hardware_ESP32

#include <WiFiClientSecure.h>

#include "Network/WiFi/Client.hpp"

using namespace Xila_Namespace;
using namespace Network_Types;

WiFi_Client_Class::WiFi_Client_Class()
{
    Data = new 
}

Result_Type WiFi_Client_Class::Connect(const char *Host, uint16_t Port, int32_t Timeout)
{

    return (Result_Type)Client.connect(Host, Port, Timeout);
}

void WiFi_Client_Class::Stop()
{
    Client.stop();
}

bool WiFi_Client_Class::Connected()
{
    return Client.connected();
}

String_Type &WiFi_Client_Class::Last_Error(String_Type &Error_Buffer)
{
    if (!Error_Buffer)
        return Error_Buffer;

    if (Client.lastError((char *)Error_Buffer, Error_Buffer.Get_Size()) == 0)
        Error_Buffer = "";

    return Error_Buffer;
}

void WiFi_Client_Class::Set_Insecure()
{
    Client.setInsecure();
}

void WiFi_Client_Class::Set_Handshake_Timeout(uint32_t Timeout)
{
    Client.setHandshakeTimeout(Timeout);
}

void WiFi_Client_Class::Set_Timeout(uint32_t Timeout)
{
    Client.setTimeout(Timeout);
}

int WiFi_Client_Class::Available()
{
    return Client.available();
}

int WiFi_Client_Class::Peek()
{
    return Client.peek();
}

int WiFi_Client_Class::Read()
{
    return Client.read();
}

Size_Type WiFi_Client_Class::Read_Bytes(Byte_Type *Buffer, Size_Type Length)
{
    return Client.read(Buffer, Length);
}

String_Type &WiFi_Client_Class::Read_String(String_Type &String)
{
    if (!String)
        return String;

    Client.read((uint8_t *)(char *)String, String.Get_Size());
    return String;
}

void WiFi_Client_Class::Flush()
{
    Client.flush();
}

Size_Type WiFi_Client_Class::Write(Byte_Type Byte)
{
    return Client.write(Byte);
}

Size_Type WiFi_Client_Class::Write_Bytes(const Byte_Type *Buffer, Size_Type Length)
{
    return Client.write(Buffer, Length);
}

Size_Type WiFi_Client_Class::Write_String(const char *String)
{
    return Client.write((uint8_t *)String, strlen(String));
}

WiFi_Client_Class::operator bool()
{
    return Client;
}

bool WiFi_Client_Class::operator==(WiFi_Client_Class &Client)
{
    return Client == Client;
}

bool WiFi_Client_Class::operator!=(WiFi_Client_Class &Client)
{
    return Client != Client;
}

#endif
