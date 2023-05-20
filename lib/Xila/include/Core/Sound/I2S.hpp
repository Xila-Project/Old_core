/// @file I2S.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 15-05-2023
///
/// @copyright Copyright (c) 2023

#ifndef Sound_I2S_Hpp_Included
#define Sound_I2S_Hpp_Included

#include "Stream.hpp"
#include "Core/Log/Log.hpp"

namespace Xila_Namespace
{
    namespace Sound_Types
    {

        enum class Mode_Type
        {
            Undefined = UNDEFINED_MODE,
            Transmit = TX_MODE,
            Receive = RX_MODE,
            Receive_Transmit = RXTX_MODE
        };

        enum class Format_Type
        {
            Standard = I2S_STD_FORMAT,
            Least_Significant_Bit = I2S_LSB_FORMAT,
            Most_Significant_Bit = I2S_MSB_FORMAT,
            Philips = I2S_PHILIPS_FORMAT,
            Right_Justified = I2S_RIGHT_JUSTIFIED_FORMAT,
            Left_Justified = I2S_LEFT_JUSTIFIED_FORMAT,
            Pulse_Code_Modulation = I2S_PCM
        };

        typedef class I2S_Configuration_Class : public Configuration_Type
        {

        public:
            audio_tools::I2SConfig I2S_Configuration;

        public:
            I2S_Configuration_Class(const audio_tools::I2SConfig &I2S_Configuration)
                : Configuration_Type(&this->I2S_Configuration),
                  I2S_Configuration(I2S_Configuration)
            {
            }

            I2S_Configuration_Class(Mode_Type Mode = Mode_Type::Transmit)
                : Configuration_Type(&I2S_Configuration),
                  I2S_Configuration((RxTxMode)Mode)
            {
            }

            // - - Getters

            Mode_Type Get_Mode()
            {
                return (Mode_Type)I2S_Configuration.rx_tx_mode;
            }

            int Get_Word_Select_Clock_Pin()
            {
                return I2S_Configuration.pin_ws;
            }

            int Get_Bit_Clock_Pin()
            {
                return I2S_Configuration.pin_bck;
            }

            int Get_Data_Pin()
            {
                return I2S_Configuration.pin_data;
            }

            Format_Type Get_Format()
            {
                return (Format_Type)I2S_Configuration.i2s_format;
            }

            // - - Setters

            void Set_Mode(Mode_Type Mode)
            {
                I2S_Configuration.rx_tx_mode = (RxTxMode)Mode;
            }

            void Set_Word_Select_Clock_Pin(int Pin)
            {
                I2S_Configuration.pin_ws = Pin;
            }

            void Set_Bit_Clock_Pin(int Pin)
            {
                I2S_Configuration.pin_bck = Pin;
            }

            void Set_Data_Pin(int Pin)
            {
                I2S_Configuration.pin_data = Pin;
            }

            void Set_Format(Format_Type Format)
            {
                I2S_Configuration.i2s_format = (I2SFormat)Format;
            }

            // - - Operators

            operator audio_tools::I2SConfig &()
            {
                return I2S_Configuration;
            }

        } I2S_Configuration_Type;

        typedef class I2S_Class : public Stream_Type
        {
        private:
            I2SStream I2S_Stream;

        public:
            I2S_Class(int Mute_Pin = -1) : Stream_Type(I2S_Stream),
                                           I2S_Stream()
            {
                Log_Verbose("Sound", "I2S class has been constructed.");
            }

            Result_Type Begin(I2S_Configuration_Type Configuration)
            {

                Log_Verbose("Sound", "I2S begin : ");
                Log_Verbose("Sound", "Word Select Clock Pin : %i", Configuration.Get_Word_Select_Clock_Pin());
                Log_Verbose("Sound", "Bit Clock Pin : %i", Configuration.Get_Bit_Clock_Pin());
                Log_Verbose("Sound", "Data Pin : %i", Configuration.Get_Data_Pin());
                Log_Verbose("Sound", "Bits per sample : %i", Configuration.Get_Bits_Per_Sample());
                Log_Verbose("Sound", "Sample rate : %i", Configuration.Get_Sample_Rate());
                Log_Verbose("Sound", "Channel number : %i", Configuration.Get_Channel_Count());

                return (Result_Type)I2S_Stream.begin((audio_tools::I2SConfig&)Configuration);
            }

            // - - Getters

            I2S_Configuration_Type Get_Default_Configuration(Mode_Type Mode = Mode_Type::Transmit)
            {
                auto C = (I2S_Configuration_Type)I2S_Stream.defaultConfig((RxTxMode)Mode);

                Log_Verbose("Sound", "I2S default configuration has been retrieved.");
                Log_Verbose("Sound", "I2S default configuration :");
                Log_Verbose("Sound", "Word Select Clock Pin : %i", C.Get_Word_Select_Clock_Pin());
                Log_Verbose("Sound", "Bit Clock Pin : %i", C.Get_Bit_Clock_Pin());
                Log_Verbose("Sound", "Data Pin : %i", C.Get_Data_Pin());
                Log_Verbose("Sound", "Bits per sample : %i", C.Get_Bits_Per_Sample());
                Log_Verbose("Sound", "Sample rate : %i", C.Get_Sample_Rate());
                Log_Verbose("Sound", "Channel number : %i", C.Get_Channel_Count());

                return (I2S_Configuration_Type)I2S_Stream.defaultConfig((RxTxMode)Mode);
            }

        } I2S_Type;

    }
}

#endif