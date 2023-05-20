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

            Volume_Configuration_Class(const VolumeStreamConfig &Volume_Configuration)
                : Configuration_Type(&this->Volume_Configuration),
                  Volume_Configuration(Volume_Configuration)
            {
            }

            Volume_Configuration_Class()
                : Configuration_Type(&Volume_Configuration),
                  Volume_Configuration()
            {
            }

            // - - Getters

            bool Get_Allow_Boost()
            {
                return Volume_Configuration.allow_boost;
            }

            float Get_Volume()
            {
                return Volume_Configuration.volume;
            }

            // - - Setters

            void Set_Allow_Boost(bool Allow_Boost)
            {
                Volume_Configuration.allow_boost = Allow_Boost;
            }

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
                Log_Verbose("Sound", "Volume stream created : %p / %p", &Output, &Volume_Stream);
            }

            // - - Operations

            Result_Type Begin(Volume_Configuration_Type Configuration)
            {
                return (Result_Type)Volume_Stream.begin((audio_tools::I2SConfig &)Configuration);
            }
            
            Result_Type Begin(Configuration_Type Configuration)
            {
                Log_Verbose("Sound", "Volume stream begin.");
                Log_Verbose("Sound", "Bits per sample : %i",Configuration.Get_Bits_Per_Sample());
                Log_Verbose("Sound", "Sample rate : %i", Configuration.Get_Sample_Rate());
                Log_Verbose("Sound", "Channel number : %i", Configuration.Get_Channel_Count());

                return (Result_Type)Volume_Stream.begin((audio_tools::AudioInfo &)Configuration);
            }


            // - - Getters

            Volume_Configuration_Type Get_Default_Configuration()
            {
                return Volume_Stream.defaultConfig();
            }

            float Get_Volume(int8_t Channel = -1)
            {
                if (Channel != -1)
                    return Volume_Stream.volume(Channel);
                return Volume_Stream.volume();
            }

            // - - Setters

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