/// @file Stream.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 15-05-2023
///
/// @copyright Copyright (c) 2023

#ifndef Sound_Stream_Hpp_Included
#define Sound_Stream_Hpp_Included

#include "Log/Log.hpp"
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

            /// @brief Construct a new stream object from an audio stream.
            /// @param Stream Audio stream to use.
            Stream_Class(AudioStream &Stream) : Sound_Stream(Stream)
            {
            }

            /// @brief Destroy the stream object.
            ~Stream_Class() {}

            // - - Operations

            /// @brief Begin the stream.
            /// @return `Result_Type::Success` if the stream has been started, `Result_Type::Error` otherwise.
            virtual Result_Type Begin()
            {
                return (Result_Type)Sound_Stream.begin();
            }

            /// @brief End the stream.
            /// @return `Result_Type::Success` if the stream has been ended, `Result_Type::Error` otherwise.
            virtual void End()
            {
                Sound_Stream.end();
            }

            // - - Getters

            /// @brief Get the configuration of the stream.
            /// @return `Configuration_Type`
            virtual Configuration_Type Get_Configuration()
            {
                return (Configuration_Type)Sound_Stream.audioInfo();
            }

            // - - Setters

            /// @brief Set the configuration of the stream.
            /// @param Configuration  Configuration to set.
            virtual void Set_Configuration(Configuration_Type Configuration)
            {
                Sound_Stream.setAudioInfo(Configuration.Configuration_Reference);
            }

            /// @brief Set the stream to notify of audio format change (sample rate, bits per sample, etc.)
            /// @param Stream Stream to notify.
            virtual void Set_Notify_Audio_Change(Stream_Class &Stream)
            {
                Sound_Stream.setNotifyAudioChange(Stream);
            }

            // - - Operators

            /// @brief Return the validity of the audio stream.
            operator bool()
            {
                return Sound_Stream;
            }

            /// @brief Return the audio stream (compatibility with AudioStream class)
            operator AudioStream &()
            {
                return Sound_Stream;
            }

        } Stream_Type;

    }
}

#endif