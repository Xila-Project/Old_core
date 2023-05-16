/// @file HTTP_Client.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 16-05-2023
///
/// @copyright Copyright (c) 2023

#include "Core/Communication/HTTP_Client.hpp"

using namespace Xila_Namespace;
using namespace Communication_Types;

HTTPS_Client_Class::HTTPS_Client_Class()
{
}

Result_Type HTTPS_Client_Class::Begin(WiFi_Client_Type &Client, const char *Host, uint16_t Port, const char *URI, bool HTTPS)
{
    if (URI == NULL)
        return (Result_Type)this->Client.begin((WiFiClient &)Client, Host, Port);

    return (Result_Type)this->Client.begin((WiFiClient &)Client, Host, Port, URI, HTTPS);
}

void HTTPS_Client_Class::End()
{
    Client.end();
}

bool HTTPS_Client_Class::Connected()
{
    return Client.connected();
}

int HTTPS_Client_Class::Get()
{
    return Client.GET();
}

int HTTPS_Client_Class::Patch(const char *Payload)
{
    return Client.PATCH(Payload);
}

int HTTPS_Client_Class::Post(const char *Payload)
{
    return Client.POST(Payload);
}

int HTTPS_Client_Class::Put(const char *Payload)
{
    return Client.PUT(Payload);
}

int HTTPS_Client_Class::Send_Request(const char *Method, const char *Payload)
{
    return Client.sendRequest(Method);
}

void HTTPS_Client_Class::Add_Header(const char *Name, const char *Value, bool First, bool Replace)
{
    Client.addHeader(Name, Value, First, Replace);
}

bool HTTPS_Client_Class::Has_Header(const char *Name)
{
    return Client.hasHeader(Name);
}

void HTTPS_Client_Class::Reset_Cookie_Jar()
{
    Client.resetCookieJar();
}

void HTTPS_Client_Class::Clear_All_Cookies()
{
    Client.clearAllCookies();
}

void HTTPS_Client_Class::Set_Reuse(bool Reuse)
{
    Client.setReuse(Reuse);
}

void HTTPS_Client_Class::Set_User_Agent(const char *User_Agent)
{
    Client.setUserAgent(User_Agent);
}

void HTTPS_Client_Class::Set_Authorization(const char *User, const char *Password)
{
    Client.setAuthorization(User, Password);
}

void HTTPS_Client_Class::Set_Authorization_Type(const char *Authorization_Type)
{
    Client.setAuthorizationType(Authorization_Type);
}

void HTTPS_Client_Class::Set_Connect_Timeout(uint32_t Timeout)
{
    Client.setConnectTimeout(Timeout);
}

void HTTPS_Client_Class::Set_Timeout(uint32_t Timeout)
{
    Client.setTimeout(Timeout);
}

void HTTPS_Client_Class::Set_Follow_Redirects(bool Follow_Redirects, bool Force)
{
    if (Follow_Redirects)
    {
        if (Force)
            Client.setFollowRedirects(followRedirects_t::HTTPC_FORCE_FOLLOW_REDIRECTS);
        else
            Client.setFollowRedirects(followRedirects_t::HTTPC_STRICT_FOLLOW_REDIRECTS);
    }
    else
        Client.setFollowRedirects(followRedirects_t::HTTPC_DISABLE_FOLLOW_REDIRECTS);
}

void HTTPS_Client_Class::Set_Redirect_Limit(uint16_t Limit)
{
    Client.setRedirectLimit(Limit);
}

Result_Type HTTPS_Client_Class::Set_URL(const char *URL)
{
    return (Result_Type)Client.setURL(URL);
}

void HTTPS_Client_Class::Use_HTTP_1_0(bool Use_HTTP_1_0)
{
    Client.useHTTP10(Use_HTTP_1_0);
}

String_Type& HTTPS_Client_Class::Get_Header(String_Type& Header_Buffer, const char* Name)
{
    if (!Header_Buffer)
        return Header_Buffer;

    Header_Buffer = Client.header(Name).c_str();
    return Header_Buffer;
}

String_Type& HTTPS_Client_Class::Get_Header_Name(String_Type& Header_Buffer, Size_Type Index)
{
    if (!Header_Buffer)
        return Header_Buffer;

    Header_Buffer = Client.headerName(Index).c_str();
    return Header_Buffer;
}

Size_Type HTTPS_Client_Class::Get_Header_Count()
{
    return Client.headers();
}

Size_Type HTTPS_Client_Class::Get_Size()
{
    return Client.getSize();
}

const char* HTTPS_Client_Class::Get_Location()
{
    return Client.getLocation().c_str();
}

String_Type& HTTPS_Client_Class::Get_String(String_Type& String)
{
    if (!String)
        return String;

    String = Client.getString().c_str();
    return String;
}



