/// @file Stream.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 15-05-2023
///
/// @copyright Copyright (c) 2023

#ifndef Sound_Stream_Hpp_Included
#define Sound_Stream_Hpp_Included

#include "Core/Log/Log.hpp"
#include "../Module/Module.hpp"
#include "Configuration.hpp"

#include "AudioTools.h"

namespace Xila_Namespace
{
    namespace Sound_Types
    {
        typedef class Stream_Class
        {
        private:
            AudioStream &Sound_Stream;

        public:
            // - Methods

            // - - Constructors / Destructors

            Stream_Class() = delete;

            Stream_Class(AudioStream &Stream) : Sound_Stream(Stream)
            {
                Log_Verbose("Stream", "Sound stream created : %p", &Stream);
            }

            ~Stream_Class() {}

            // - - Operations

            virtual Result_Type Begin()
            {
                return (Result_Type)Sound_Stream.begin();
            }

            virtual void End()
            {
                Sound_Stream.end();
            }

            // - - Getters

            virtual Configuration_Type Get_Configuration()
            {
                return (Configuration_Type)Sound_Stream.audioInfo();
            }

            // - - Setters

            virtual void Set_Configuration(Configuration_Type Configuration)
            {
                Sound_Stream.setAudioInfo(Configuration.Configuration_Reference);
            }

            virtual void Set_Notify_Audio_Change(Stream_Class &Stream)
            {
                Sound_Stream.setNotifyAudioChange(Stream);
            }

            // - - Operators

            operator bool()
            {
                return Sound_Stream;
            }

            operator AudioStream &()
            {
                return Sound_Stream;
            }

        } Stream_Type;

    }
}

#endif