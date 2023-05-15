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
#include "Core/Log/Log.hpp"

namespace Xila_Namespace
{
    namespace Sound_Types
    {
        typedef class Configuration_Class
        {
        public:
            // - Methods

            // - - Constructors / Destructors

            Configuration_Class(AudioInfo *Configuration)
                : Configuration_Reference(*Configuration)
            {
            }

            Configuration_Class(AudioInfo Configuration)
                : Configuration_Reference(Configuration)
            {
            }

            Configuration_Class(int Sample_Rate = -1, int Channel_Count = -1, int Bits_Per_Sample = -1)
                : Configuration_Reference(Configuration)
            {
                Set(Sample_Rate, Channel_Count, Bits_Per_Sample);
                Log_Verbose("Sound", "Sound configuration created.");
            }

            // - - Getters

            int Get_Sample_Rate()
            {
                return Configuration_Reference.sample_rate;
            }

            int Get_Channel_Count()
            {
                return Configuration_Reference.channels;
            }

            int Get_Bits_Per_Sample()
            {
                return Configuration_Reference.bits_per_sample;
            }

            // - - Setters

            void Set_Sample_Rate(int Sample_Rate)
            {
                Configuration_Reference.sample_rate = Sample_Rate;
            }

            void Set_Channel_Count(int8_t Channel_Count)
            {
                Configuration_Reference.channels = Channel_Count;
            }

            void Set_Bits_Per_Sample(int Bits_Per_Sample)
            {
                Configuration_Reference.bits_per_sample = Bits_Per_Sample;
            }

            void Set(int Sample_Rate = -1, int Channel_Count = -1, int Bits_Per_Sample = -1)
            {
                if (Sample_Rate != -1)
                    Configuration_Reference.sample_rate = Sample_Rate;
                if (Channel_Count != -1)
                    Configuration_Reference.channels = Channel_Count;
                if (Bits_Per_Sample != -1)
                    Configuration_Reference.bits_per_sample = Bits_Per_Sample;
            }

            // - - Operators

            Configuration_Class &operator=(const Configuration_Class &Configuration)
            {
                this->Configuration_Reference = Configuration.Configuration_Reference;
                return *this;
            }

            bool operator==(const Configuration_Class &Configuration)
            {
                return this->Configuration_Reference == Configuration.Configuration_Reference;
            }

            bool operator!=(const Configuration_Class &Configuration)
            {
                return this->Configuration_Reference != Configuration.Configuration_Reference;
            }

        private:
            // - Attributes

            AudioInfo &Configuration_Reference;
            AudioInfo Configuration; // TODO : Find another way

            friend class Stream_Class;

        } Configuration_Type;

    }
}

#endif