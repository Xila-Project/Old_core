/// @file Decoder.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 15-05-2023
///
/// @copyright Copyright (c) 2023

#ifndef Sound_Decoder_Hpp_Included
#define Sound_Decoder_Hpp_Included

#include "AudioTools.h"
#include "Configuration.hpp"
//#include "AudioCodecs/CodecMP3Helix.h"

namespace Xila_Namespace
{
    namespace Sound_Types
    {
        typedef class Decoder_Class
        {
        private:
            audio_tools::AudioDecoder &Decoder;

        public:
            Decoder_Class(audio_tools::AudioDecoder &Decoder)
                : Decoder(Decoder)
            {
            }

            Configuration_Type Get_Configuration()
            {
                return (Configuration_Type)Decoder.audioInfo();
            }

            operator audio_tools::AudioDecoder &()
            {
                return Decoder;
            }
        } Decoder_Type;

        typedef class WAV_Decoder_Class : public Decoder_Class
        {
        private:
            audio_tools::WAVDecoder WAV_Decoder;

        public:
            WAV_Decoder_Class() : Decoder_Class(WAV_Decoder)
            {

                Log_Verbose("Sound", "WAV decoder created : %p", this);
            }
        } WAV_Decoder_Type;


        /*
        typedef class MP3_Decoder_Class : public Decoder_Class
        {
        private:
            audio_tools::MP3DecoderHelix MP3_Decoder;

        public:

            MP3_Decoder_Class() : Decoder_Class(MP3_Decoder)
            {
            }

        } MP3_Decoder_Type;
        */



    } // namespace Sound_Types

} // namespace Xila_Namespace

#endif // Sound_Decoder_Hpp_Included