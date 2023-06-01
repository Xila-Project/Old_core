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
#include "Log/Log.hpp"

namespace Xila_Namespace
{
    namespace Sound_Types
    {

        /// @brief I2S Mode enumeration.
        enum class Mode_Type
        {
            Undefined = UNDEFINED_MODE,  ///< Undefined mode.
            Transmit = TX_MODE,          ///< Transmit mode.
            Receive = RX_MODE,           ///< Receive mode.
            Receive_Transmit = RXTX_MODE ///< Receive and transmit mode.
        };

        /// @brief I2S Format enumeration.
        enum class Format_Type
        {
            Standard = I2S_STD_FORMAT,                    ///< Standard format.
            Least_Significant_Bit = I2S_LSB_FORMAT,       ///< Least significant bit format.
            Most_Significant_Bit = I2S_MSB_FORMAT,        ///< Most significant bit format.
            Philips = I2S_PHILIPS_FORMAT,                 ///< Philips format.
            Right_Justified = I2S_RIGHT_JUSTIFIED_FORMAT, ///< Right justified format.
            Left_Justified = I2S_LEFT_JUSTIFIED_FORMAT,   ///< Left justified format.
            Pulse_Code_Modulation = I2S_PCM               ///< Pulse code modulation format.
        };

        /// @brief I2S configuration class.
        typedef class I2S_Configuration_Class : public Configuration_Type
        {

        public:
            audio_tools::I2SConfig I2S_Configuration;

        public:
            // - Methods

            // - - Constructors

            /// @brief Construct a new I2S_Configuration_Class object from audio_tools::I2SConfig.
            /// @param I2S_Configuration audio_tools::I2SConfig.
            I2S_Configuration_Class(const audio_tools::I2SConfig &I2S_Configuration)
                : Configuration_Type(&this->I2S_Configuration),
                  I2S_Configuration(I2S_Configuration)
            {
            }

            /// @brief Construct a new I2S_Configuration_Class object.
            /// @param Mode  I2S mode.
            I2S_Configuration_Class(Mode_Type Mode = Mode_Type::Transmit)
                : Configuration_Type(&I2S_Configuration),
                  I2S_Configuration((RxTxMode)Mode)
            {
            }

            // - - Getters

            /// @brief Get I2S mode.
            /// @return Mode_Type I2S mode.
            Mode_Type Get_Mode()
            {
                return (Mode_Type)I2S_Configuration.rx_tx_mode;
            }

            /// @brief Get I2S word select clock pin.
            /// @return  int I2S word select clock pin.
            int Get_Word_Select_Clock_Pin()
            {
                return I2S_Configuration.pin_ws;
            }

            /// @brief Get I2S bit clock pin.
            /// @return  int I2S bit clock pin.
            int Get_Bit_Clock_Pin()
            {
                return I2S_Configuration.pin_bck;
            }

            /// @brief Get I2S data pin.
            /// @return  int I2S data pin.
            int Get_Data_Pin()
            {
                return I2S_Configuration.pin_data;
            }

            /// @brief Get I2S bits per sample.
            /// @return  int I2S bits per sample.
            Format_Type Get_Format()
            {
                return (Format_Type)I2S_Configuration.i2s_format;
            }

            // - - Setters

            /// @brief Set I2S mode.
            /// @param Mode I2S mode.
            void Set_Mode(Mode_Type Mode)
            {
                I2S_Configuration.rx_tx_mode = (RxTxMode)Mode;
            }

            /// @brief Set I2S word select clock pin.
            /// @param Pin I2S word select clock pin.
            void Set_Word_Select_Clock_Pin(int Pin)
            {
                I2S_Configuration.pin_ws = Pin;
            }

            /// @brief Set I2S bit clock pin.
            /// @param Pin I2S bit clock pin.
            void Set_Bit_Clock_Pin(int Pin)
            {
                I2S_Configuration.pin_bck = Pin;
            }

            /// @brief Set I2S data pin.
            /// @param Pin I2S data pin.
            void Set_Data_Pin(int Pin)
            {
                I2S_Configuration.pin_data = Pin;
            }

            /// @brief Set I2S bits per sample.
            /// @param Format I2S bits per sample.
            void Set_Format(Format_Type Format)
            {
                I2S_Configuration.i2s_format = (I2SFormat)Format;
            }

            // - - Operators

            /// @brief Cast operator to audio_tools::I2SConfig.
            /// @return audio_tools::I2SConfig
            operator audio_tools::I2SConfig &()
            {
                return I2S_Configuration;
            }

        } I2S_Configuration_Type;

        /// @brief I2S stream class.
        typedef class I2S_Class : public Stream_Type
        {
        private:
            I2SStream I2S_Stream;

        public:
            /// @brief Construct a new I2S_Class object.
            /// @param Mute_Pin Mute pin.
            I2S_Class(int Mute_Pin = -1) : Stream_Type(I2S_Stream),
                                           I2S_Stream()
            {
            }

            /// @brief Start I2S stream.
            /// @param Configuration I2S configuration.
            /// @return Result_Type
            Result_Type Begin(I2S_Configuration_Type Configuration)
            {
                return (Result_Type)I2S_Stream.begin((audio_tools::I2SConfig &)Configuration);
            }

            // - - Getters

            /// @brief Get I2S default configuration.
            /// @param Mode I2S mode.
            /// @return I2S_Configuration_Type I2S configuration.
            I2S_Configuration_Type Get_Default_Configuration(Mode_Type Mode = Mode_Type::Transmit)
            {
                return (I2S_Configuration_Type)I2S_Stream.defaultConfig((RxTxMode)Mode);
            }

        } I2S_Type;

    }
}

#endif