/// @file WiFi_Client.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 16-05-2023
///
/// @copyright Copyright (c) 2023

#ifndef Communication_WiFi_Client_Hpp_Included
#define Communication_WiFi_Client_Hpp_Included

#include <WiFiClientSecure.h>
#include "Core/Module/Module.hpp"

namespace Xila_Namespace
{
    namespace Communication_Types
    {
        typedef class WiFi_Client_Class : public Xila_Namespace::Stream_Type
        {
        public:
            // - Methods

            // - - Constructors / Destructors

            WiFi_Client_Class();

            // - - Operations

            Result_Type Connect(const char* Host, uint16_t Port, int32_t Timeout = 30000);

            void Stop();

            bool Connected();
            String_Type& Last_Error(String_Type& Error_Buffer);
            
            // - - Getters

            // - - Setters

            void Set_Insecure();
          
            void Set_Handshake_Timeout(uint32_t Timeout);
            void Set_Timeout(uint32_t Timeout);



            // - - - Overrided Stream_Type methods

            int Available() override;
            int Peek() override;
            int Read() override;
            Size_Type Read_Bytes(Byte_Type *Buffer, Size_Type Length) override;
            String_Type &Read_String(String_Type &String) override;

            void Flush() override;
            Size_Type Write(Byte_Type Byte) override;
            Size_Type Write_Bytes(const Byte_Type *Buffer, Size_Type Length) override;
            Size_Type Write_String(const char* String) override;

            // - - Operators

            operator bool();

            bool operator==(WiFi_Client_Class &Client);
            bool operator!=(WiFi_Client_Class &Client);


            /// @brief Cast operator to WiFiClientSecure (compatibility purpose)
            operator WiFiClientSecure&()
            {
                return Client;
            }

        private:

            WiFiClientSecure Client;
        } WiFi_Client_Type;

        
    }
}

#endif // Communication_WiFi_Client_Hpp_Included