/// @file Volume.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 15-05-2023
///
/// @copyright Copyright (c) 2023

#ifndef Sound_Volume_Hpp_Included
#define Sound_Volume_Hpp_Included

#include "Stream.hpp"

#include "Log/Log.hpp"

namespace Xila_Namespace
{
    namespace Sound_Types
    {
        typedef class Volume_Configuration_Class : public Configuration_Type
        {
        public:
            // - Methods
            
            /// @brief Construct a new Volume_Configuration_Class object from a VolumeStreamConfig (legacy).
            /// @param Volume_Configuration Volume stream configuration to copy.
            Volume_Configuration_Class(const VolumeStreamConfig &Volume_Configuration)
                : Configuration_Type(&this->Volume_Configuration),
                  Volume_Configuration(Volume_Configuration)
            {
            }

            /// @brief Default constructor.
            Volume_Configuration_Class()
                : Configuration_Type(&Volume_Configuration),
                  Volume_Configuration()
            {
            }

            // - - Getters

            /// @brief Get
            /// @return 
            bool Get_Allow_Boost()
            {
                return Volume_Configuration.allow_boost;
            }

            /// @brief Get the volume value.
            /// @return Byte_Type Volume value (0-255)
            float Get_Volume()
            {
                return Volume_Configuration.volume;
            }

            // - - Setters

            /// @brief Set the volume boost.
            /// @param Allow_Boost Allow boost.
            void Set_Allow_Boost(bool Allow_Boost)
            {
                Volume_Configuration.allow_boost = Allow_Boost;
            }

            /// @brief Set the volume value.
            /// @param Volume Volume value (0-255)
            void Set_Volume(float Volume)
            {
                Volume_Configuration.volume = Volume;
            }

            operator VolumeStreamConfig &()
            {
                return Volume_Configuration;
            }

        private:
            VolumeStreamConfig Volume_Configuration;

        } Volume_Configuration_Type;

        typedef class Volume_Class : public Stream_Type
        {
        public:
            // - Methods

            // - - Constructors / Destructors

            Volume_Class() = delete;
            Volume_Class(Stream_Type &Output)
                : Stream_Type(Volume_Stream),
                  Volume_Stream(Output)
            {
            }

            // - - Operations

            /// @brief Begin the volume stream.
            /// @param Configuration Volume stream configuration.
            /// @return Result_Type
            Result_Type Begin(Volume_Configuration_Type Configuration)
            {
                return (Result_Type)Volume_Stream.begin((audio_tools::I2SConfig &)Configuration);
            }
            
            /// @brief Begin the volume stream.
            /// @param Configuration Volume stream configuration.
            /// @return Result_Type
            Result_Type Begin(Configuration_Type Configuration)
            {
                return (Result_Type)Volume_Stream.begin((audio_tools::AudioInfo &)Configuration);
            }


            // - - Getters

            /// @brief Get the default volume stream configuration.
            /// @return Volume_Configuration_Type
            Volume_Configuration_Type Get_Default_Configuration()
            {
                return Volume_Stream.defaultConfig();
            }

            /// @brief Get the volume stream volume.
            /// @param Channel Channel to get the volume from (-1 for all channels).
            /// @return Byte_Type Volume (0-255).
            float Get_Volume(int8_t Channel = -1)
            {
                if (Channel != -1)
                    return Volume_Stream.volume(Channel);
                return Volume_Stream.volume();
            }

            // - - Setters

            /// @brief Set the volume stream volume.
            /// @param Volume Volume (0-255).
            /// @param Channel Channel to set the volume to (-1 for all channels).
            void Set_Volume(float Volume, int8_t Channel = -1)
            {
                if (Channel != -1)
                    Volume_Stream.setVolume(Volume, Channel);
                else
                    Volume_Stream.setVolume(Volume);
            }

        private:
            VolumeStream Volume_Stream;

        } Volume_Type;
    }
}

#endif