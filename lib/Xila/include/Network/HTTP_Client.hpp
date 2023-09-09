/// @file HTTPS_Client.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 14-04-2023
///
/// @copyright Copyright (c) 2023

#ifndef Communication_HTTP_Client_Hpp_Included
#define Communication_HTTP_Client_Hpp_Included

#ifdef Xila_WiFi_Hardware_ESP32
    #include "HTTPClient.h"
#endif

#include "Client.hpp"

namespace Xila_Namespace
{
    namespace Network_Types
    {
        enum class HTTP_Code_Type
        {
            Continue,
            Switching_Protocols,
            Processing,
            OK,
            Created,
            Accepted,
            Non_Authoritative_Information,
            No_Content,
            Reset_Content,
            Partial_Content,
            Multi_Status,
            Already_Reported,
            I_M_Used,
            Multiple_Choices,
            Moved_Permanently,
            Found,
            See_Other,
            Not_Modified,
            Use_Proxy,
            Temporary_Redirect,
            Permanent_Redirect,
            Bad_Request,
            Unauthorized,
            Payment_Required,
            Forbidden,
            Not_Found,
            Method_Not_Allowed,
            Not_Acceptable,
            Proxy_Authentication_Required,
            Request_Timeout,
            Conflict,
            Gone,
            Length_Required,
            Precondition_Failed,
            Payload_Too_Large,
            URI_Too_Long,
            Unsupported_Media_Type,
            Range_Not_Satisfiable,
            Expectation_Failed,
            Misdirected_Request,
            Unprocessable_Entity,
            Locked,
            Failed_Dependency,
            Upgrade_Required,
            Precondition_Required,
            Too_Many_Requests,
            Request_Header_Fields_Too_Large,
            Internal_Server_Error,
            Not_Implemented,
            Bad_Gateway,
            Service_Unavailable,
            Gateway_Timeout,
            HTTP_Version_Not_Supported,
            Variant_Also_Negotiates,
            Insufficient_Storage,
            Loop_Detected,
            Not_Extended,
            Network_Authentication_Required
        };

        typedef class HTTPS_Client_Class
        {
        public:
            // - Methods

            // - - Constructors / Destructors

            HTTPS_Client_Class();

            // - - Operations

            Result_Type Begin(Client_Type &Client, const char *Host, uint16_t Port, const char *URI = NULL, bool HTTPS = false);

            void End();

            bool Connected();

            int Get();
            int Patch(const char *Payload);
            int Post(const char *Payload);
            int Put(const char *Payload);

            int Send_Request(const char *Method, const char *Payload = NULL);
            void Add_Header(const char *Header, const char *Value, bool First = false, bool Replace = true);
            void Collect_Headers(const char *Header_Keys[], Size_Type Header_Keys_Count);
            bool Has_Header(const char *Name);

            void Use_HTTP_1_0(bool Use_HTTP_1_0);

            // void Set_Cookie_Jar(Cookie_Jar_Type* Cookie_Jar);
            void Reset_Cookie_Jar();
            void Clear_All_Cookies();

            // - - Setters

            void Set_Reuse(bool Reuse);
            void Set_User_Agent(const char *User_Agent);
            void Set_Authorization(const char *User, const char *Password = NULL);
            void Set_Authorization_Type(const char *Authorization_Type);
            void Set_Connect_Timeout(uint32_t Timeout);
            void Set_Timeout(uint32_t Timeout);

            void Set_Follow_Redirects(bool Follow_Redirects, bool Force = false);
            void Set_Redirect_Limit(uint16_t Limit);
            Result_Type Set_URL(const char *URL);

            // - - Getters

            String_Type &Get_Header(String_Type &Header_Buffer, const char *Name);
            String_Type &Get_Header_Name(String_Type &Header_Buffer, Size_Type Index);
            Size_Type Get_Header_Count();

            Size_Type Get_Size();
            const char *Get_Location();

            String_Type &Get_String(String_Type &String);

        protected:

#ifdef Xila_WiFi_Hardware_ESP32
            HTTPClient Client;
#endif

        } HTTPS_Client_Type;
    }
}

#endif // Communication_HTTP_Client_Hpp_Included