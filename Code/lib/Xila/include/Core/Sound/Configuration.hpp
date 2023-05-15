/// @file Configuration_Type.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 15-05-2023
///
/// @copyright Copyright (c) 2023

#ifndef Sound_Configuration_Hpp_Included
#define Sound_Configuration_Hpp_Included

#include "AudioTools.h"

namespace Xila_Namespace
{
    namespace Sound_Types
    {
        typedef class Configuration_Class
        {
        public:
            // - Methods

            // - - Constructors / Destructors

            Configuration_Class() = delete;

            Configuration_Class(AudioInfo Configuration, int Sample_Rate = -1, int Channel_Count = -1, int Bits_Per_Sample = -1)
                : Configuration(Configuration)
            {
                Set(Sample_Rate, Channel_Count, Bits_Per_Sample);
            }

            // - - Getters

            int Get_Sample_Rate()
            {
                return Configuration.sample_rate;
            }

            int Get_Channel_Count()
            {
                return Configuration.channels;
            }

            int Get_Bits_Per_Sample()
            {
                return Configuration.bits_per_sample;
            }

            // - - Setters

            void Set_Sample_Rate(int Sample_Rate)
            {
                Configuration.sample_rate = Sample_Rate;
            }

            void Set_Channel_Count(int8_t Channel_Count)
            {
                Configuration.channels = Channel_Count;
            }

            void Set_Bits_Per_Sample(int Bits_Per_Sample)
            {
                Configuration.bits_per_sample = Bits_Per_Sample;
            }

            void Set(int Sample_Rate = -1, int Channel_Count = -1, int Bits_Per_Sample = -1)
            {
                if (Sample_Rate != -1)
                    Configuration.sample_rate = Sample_Rate;
                if (Channel_Count != -1)
                    Configuration.channels = Channel_Count;
                if (Bits_Per_Sample != -1)
                    Configuration.bits_per_sample = Bits_Per_Sample;
            }

            // - - Operators

            Configuration_Class &operator=(const Configuration_Class &Configuration)
            {
                this->Configuration = Configuration.Configuration;
                return *this;
            }

            bool operator==(const Configuration_Class &Configuration)
            {
                return this->Configuration == Configuration.Configuration;
            }

            bool operator!=(const Configuration_Class &Configuration)
            {
                return this->Configuration != Configuration.Configuration;
            }

        private:
            // - Attributes

            AudioInfo &Configuration;

            friend class Stream_Class;

        } Configuration_Type;

    }
}

#endif