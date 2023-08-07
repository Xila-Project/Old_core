/// @file Client.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 05-08-2023
///
/// @copyright Copyright (c) 2023

#ifndef Xila_Network_Client_Hpp_Included
#define Xila_Network_Client_Hpp_Included

#include "Module/Module.hpp"

namespace Xila_Namespace
{
    namespace Network_Types
    {
        typedef class Client_Class : public Xila_Namespace::Stream_Type
        {
        public:
            // - Methods

            // - - Constructors / destructors

            Client_Class();
        
            virtual Result_Type Connect(const char* Host, Word_Type Port, int32_t Timeout = 30000) = 0;

            virtual void Stop() = 0;

            virtual bool Connected() = 0;

            virtual String_Type& Last_Error(String_Type& Error_Buffer) = 0;

            virtual void Set_Insecure() = 0;

            virtual void Set_Handshake_Timeout(uint32_t Timeout) = 0;
            virtual void Set_Timeout(uint32_t Timeout) = 0;

            virtual int Available() = 0;
            virtual int Peek() = 0;

            virtual int Read() = 0;
            virtual Size_Type Read_Bytes(Byte_Type* Buffer, Size_Type Length) = 0;
            virtual String_Type& Read_String(String_Type& String) = 0;
        
            virtual void Flush() = 0;

            virtual Size_Type Write(Byte_Type Byte) = 0;
            virtual Size_Type Write_Bytes(const Byte_Type* Buffer, Size_Type Length) = 0;
            virtual Size_Type Write_String(const char* String) = 0;

            virtual operator bool() = 0;

            virtual bool operator==(Client_Class& Client) = 0;
            virtual bool operator!=(Client_Class& Client) = 0;
        
        protected:

            void* Data;
        } Client_Type;
    }

}

#endif