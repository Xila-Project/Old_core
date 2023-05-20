/// @file HTTPS_Client.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 14-04-2023
///
/// @copyright Copyright (c) 2023

#ifndef Communication_HTTP_Client_Hpp_Included
#define Communication_HTTP_Client_Hpp_Included

#include "HTTPClient.h"
#include "WiFi_Client.hpp"

namespace Xila_Namespace
{
    namespace Communication_Types
    {
        enum class HTTP_Code_Type
        {
            Continue = HTTP_CODE_CONTINUE,
            Switching_Protocols = HTTP_CODE_SWITCHING_PROTOCOLS,
            Processing = HTTP_CODE_PROCESSING,
            OK = HTTP_CODE_OK,
            Created = HTTP_CODE_CREATED,
            Accepted = HTTP_CODE_ACCEPTED,
            Non_Authoritative_Information = HTTP_CODE_NON_AUTHORITATIVE_INFORMATION,
            No_Content = HTTP_CODE_NO_CONTENT,
            Reset_Content = HTTP_CODE_RESET_CONTENT,
            Partial_Content = HTTP_CODE_PARTIAL_CONTENT,
            Multi_Status = HTTP_CODE_MULTI_STATUS,
            Already_Reported = HTTP_CODE_ALREADY_REPORTED,
            I_M_Used = HTTP_CODE_IM_USED,
            Multiple_Choices = HTTP_CODE_MULTIPLE_CHOICES,
            Moved_Permanently = HTTP_CODE_MOVED_PERMANENTLY,
            Found = HTTP_CODE_FOUND,
            See_Other = HTTP_CODE_SEE_OTHER,
            Not_Modified = HTTP_CODE_NOT_MODIFIED,
            Use_Proxy = HTTP_CODE_USE_PROXY,
            Temporary_Redirect = HTTP_CODE_TEMPORARY_REDIRECT,
            Permanent_Redirect = HTTP_CODE_PERMANENT_REDIRECT,
            Bad_Request = HTTP_CODE_BAD_REQUEST,
            Unauthorized = HTTP_CODE_UNAUTHORIZED,
            Payment_Required = HTTP_CODE_PAYMENT_REQUIRED,
            Forbidden = HTTP_CODE_FORBIDDEN,
            Not_Found = HTTP_CODE_NOT_FOUND,
            Method_Not_Allowed = HTTP_CODE_METHOD_NOT_ALLOWED,
            Not_Acceptable = HTTP_CODE_NOT_ACCEPTABLE,
            Proxy_Authentication_Required = HTTP_CODE_PROXY_AUTHENTICATION_REQUIRED,
            Request_Timeout = HTTP_CODE_REQUEST_TIMEOUT,
            Conflict = HTTP_CODE_CONFLICT,
            Gone = HTTP_CODE_GONE,
            Length_Required = HTTP_CODE_LENGTH_REQUIRED,
            Precondition_Failed = HTTP_CODE_PRECONDITION_FAILED,
            Payload_Too_Large = HTTP_CODE_PAYLOAD_TOO_LARGE,
            URI_Too_Long = HTTP_CODE_URI_TOO_LONG,
            Unsupported_Media_Type = HTTP_CODE_UNSUPPORTED_MEDIA_TYPE,
            Range_Not_Satisfiable = HTTP_CODE_RANGE_NOT_SATISFIABLE,
            Expectation_Failed = HTTP_CODE_EXPECTATION_FAILED,
            Misdirected_Request = HTTP_CODE_MISDIRECTED_REQUEST,
            Unprocessable_Entity = HTTP_CODE_UNPROCESSABLE_ENTITY,
            Locked = HTTP_CODE_LOCKED,
            Failed_Dependency = HTTP_CODE_FAILED_DEPENDENCY,
            Upgrade_Required = HTTP_CODE_UPGRADE_REQUIRED,
            Precondition_Required = HTTP_CODE_PRECONDITION_REQUIRED,
            Too_Many_Requests = HTTP_CODE_TOO_MANY_REQUESTS,
            Request_Header_Fields_Too_Large = HTTP_CODE_REQUEST_HEADER_FIELDS_TOO_LARGE,
            Internal_Server_Error = HTTP_CODE_INTERNAL_SERVER_ERROR,
            Not_Implemented = HTTP_CODE_NOT_IMPLEMENTED,
            Bad_Gateway = HTTP_CODE_BAD_GATEWAY,
            Service_Unavailable = HTTP_CODE_SERVICE_UNAVAILABLE,
            Gateway_Timeout = HTTP_CODE_GATEWAY_TIMEOUT,
            HTTP_Version_Not_Supported = HTTP_CODE_HTTP_VERSION_NOT_SUPPORTED,
            Variant_Also_Negotiates = HTTP_CODE_VARIANT_ALSO_NEGOTIATES,
            Insufficient_Storage = HTTP_CODE_INSUFFICIENT_STORAGE,
            Loop_Detected = HTTP_CODE_LOOP_DETECTED,
            Not_Extended = HTTP_CODE_NOT_EXTENDED,
            Network_Authentication_Required = HTTP_CODE_NETWORK_AUTHENTICATION_REQUIRED
        };

        typedef class HTTPS_Client_Class
        {
        public:
            // - Methods

            // - - Constructors / Destructors

            HTTPS_Client_Class();

            // - - Operations

            Result_Type Begin(WiFi_Client_Type &Client, const char* Host, uint16_t Port, const char* URI = NULL, bool HTTPS = false);

            void End();

            bool Connected();

            int Get();
            int Patch(const char* Payload);
            int Post(const char* Payload);
            int Put(const char* Payload);

            int Send_Request(const char* Method, const char* Payload = NULL);
            void Add_Header(const char* Header, const char* Value, bool First =false, bool Replace = true);
            void Collect_Headers(const char* Header_Keys[], Size_Type Header_Keys_Count);
            bool Has_Header(const char* Name);

            void Use_HTTP_1_0(bool Use_HTTP_1_0);
            
            //void Set_Cookie_Jar(Cookie_Jar_Type* Cookie_Jar);
            void Reset_Cookie_Jar();
            void Clear_All_Cookies();

            // - - Setters

            void Set_Reuse(bool Reuse);
            void Set_User_Agent(const char* User_Agent);
            void Set_Authorization(const char* User, const char* Password = NULL);
            void Set_Authorization_Type(const char* Authorization_Type);
            void Set_Connect_Timeout(uint32_t Timeout);
            void Set_Timeout(uint32_t Timeout);

            void Set_Follow_Redirects(bool Follow_Redirects, bool Force = false);
            void Set_Redirect_Limit(uint16_t Limit);
            Result_Type Set_URL(const char* URL);

            // - - Getters

            String_Type& Get_Header(String_Type& Header_Buffer, const char* Name);
            String_Type& Get_Header_Name(String_Type& Header_Buffer, Size_Type Index);
            Size_Type Get_Header_Count();
            
            Size_Type Get_Size();
            const char* Get_Location();
            
            String_Type& Get_String(String_Type& String);
            
        private:

            HTTPClient Client;
        } HTTPS_Client_Type;
    }
}

#endif // Communication_HTTP_Client_Hpp_Included