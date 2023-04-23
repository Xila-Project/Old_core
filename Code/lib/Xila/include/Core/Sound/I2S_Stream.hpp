/// @file I2S_Stream.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 17-04-2023
///
/// @copyright Copyright (c) 2023

#ifndef I2S_Stream_Hpp_Included
#define I2S_Stream_Hpp_Included

#include "Audio_Stream.hpp"

// - Forward declaration
namespace audio_tools { class I2SStream; }

namespace Xila_Namespace
{
    namespace Audio_Types
    {
        /// @brief
        typedef class I2S_Stream_Class : public Audio_Stream_Type
        {
        public:
            // - Methods
            // - - Constructor / destructor

            I2S_Stream_Class() = default;
            I2S_Stream_Class(int Mute_Pin);

            virtual Result_Type Begin() override;
            virtual Result_Type Begin(Communication_Type Mode, int Channels = 2, int Sample_Rate = 44100, int Bits_Per_Sample = 16);
            void End();

            // - - Stream methods override

            virtual size_t readBytes(uint8_t*, size_t) override;
            virtual size_t write(const uint8_t*, size_t) override;
            virtual int available() override;

            // - - Operations
            virtual Size_Type Read_Bytes(uint8_t* , Size_Type) override;
            virtual Size_Type(const uint8_t*, Size_Type) override;
            virtual int Available() override;
            virtual int Available_For_Write() override;
            
            void Flush();




        protected:

            inline I2SStream* Get_Pointer() const
            {
                return static_cast<I2SStream*>(Get_Pointer());
            }



        } I2S_Stream_Type;
    }
}

#endif