 /// @file Audio_Player.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 23-04-2023
 /// 
 /// @copyright Copyright (c) 2023

#ifndef Audio_Player_Hpp_Included
#define Audio_Player_Hpp_Included

#include "Audio_Stream.hpp"

namespace Xila_Namespace
{
    namespace Audio_Types
    {
        typedef class Audio_Player_Class : public Audio_Stream_Type
        {
        public:
            // - Methods

            // - - Constructor / destructor

            Audio_Player_Class() = default;
            Audio_Player_Class(int Mute_Pin);

            bool Begin();
            void End();

            // - - Stream methods override

            virtual size_t readBytes(uint8_t*, size_t) override;
            virtual size_t write(const uint8_t*, size_t) override;
            virtual int available() override;

            // - - Operations

            virtual Size_Type Read_Bytes(uint8_t* , Size_Type) override;
            virtual Size_Type Write(const uint8_t*, Size_Type) override;
            virtual int Available() override;
            virtual int Available_For_Write() override;
            
            void Flush();
    }
}

#endif