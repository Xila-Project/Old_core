/// @file Client.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 16-05-2023
///
/// @copyright Copyright (c) 2023

#ifndef Xila_Network_WiFi_Client_Hpp_Included
#define Xila_Network_WiFi_Client_Hpp_Included

#include "../Client.hpp"

namespace Xila_Namespace
{
    namespace Network_Types
    {
        typedef class WiFi_Client_Class : public Client_Class
        {
        public:
            // - Methods

            // - - Constructors / Destructors

            WiFi_Client_Class();

            // - - Operations

            Result_Type Connect(const char *Host, uint16_t Port, int32_t Timeout = 30000) override;

            void Stop() override;

            bool Connected() override;
            String_Type &Last_Error(String_Type &Error_Buffer) override;

            // - - Getters

            // - - Setters

            void Set_Insecure() override;

            void Set_Handshake_Timeout(uint32_t Timeout) override;
            void Set_Timeout(uint32_t Timeout) override;

            // - - - Overrided Stream_Type methods

            int Available() override;
            int Peek() override;
            int Read() override;
            Size_Type Read_Bytes(Byte_Type *Buffer, Size_Type Length) override;
            String_Type &Read_String(String_Type &String) override;

            void Flush() override;
            Size_Type Write(Byte_Type Byte) override;
            Size_Type Write_Bytes(const Byte_Type *Buffer, Size_Type Length) override;
            Size_Type Write_String(const char *String) override;

            // - - Operators

            operator bool() override;

            bool operator==(WiFi_Client_Class &Client) override;
            bool operator!=(WiFi_Client_Class &Client) override;
        } WiFi_Client_Type;

    }
}

#endif // Communication_WiFi_Client_Hpp_Included