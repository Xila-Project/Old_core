/// @file Player.hpp
/// @author Alix ANNERAUD (alix@anneraud.fr)
/// @brief
/// @version 0.1.0
/// @date 28-04-2023
///
/// @copyright Copyright (c) 2023

#ifndef Player_Hpp_Included
#define Player_Hpp_Included

#include "../Drive/Drive.hpp"
#include "../Module/Module.hpp"

#include "Module/Stream.hpp"
#include "Stream.hpp"
#include "Decoder.hpp"


namespace Xila_Namespace
{
    namespace Sound_Types
    {

        using Encoded_Stream_Type = EncodedAudioStream;                 
        using Stream_Copier_Type = StreamCopy;

        /// @brief File player class.
        typedef class File_Player_Class : public Stream_Type
        {
        public:
            // - Methods
            // - - Constructors / Destructor

            /// @brief File player constructor.
            /// @param Input_File Input file to play.
            /// @param Output_Stream Output stream to play the file.
            /// @param Decoder Decoder to use to decode the file.
            File_Player_Class(Drive_Types::File_Type &Input_File, Sound_Types::Stream_Type& Output_Stream, Decoder_Type &Decoder);

            /// @brief Default destructor.
            File_Player_Class();

            // - - Operations

            /// @brief Begin the player.
            /// @return `Result_Type`.
            Result_Type Begin() override;

            /// @brief Stop the player.
            void Stop();

            /// @brief Execute the player.
            /// @return `Size_Type` number of bytes played.
            Size_Type Loop();

            // - - Getters

            /// @brief Get the player current time.
            /// @return `uint32_t` Current time in seconds.
            uint32_t Get_Time();

            /// @brief Get the player total time.
            /// @return `uint32_t` Total time in seconds.
            uint32_t Get_Total_Time();

            /// @brief Get the sample rate of the current playing file.
            /// @note At least one sample have to be played to get the sample rate.
            /// @return uint32_t Sample rate.
            int Get_Sample_Rate();

            /// @brief Get the bits per sample of the current playing file.
            /// @note At least one sample have to be played to get the bits per sample.
            /// @return Byte_Type Bits per sample.
            int Get_Bits_Per_Sample();

            /// @brief Get the number of channels of the current playing file.
            /// @note At least one sample have to be played to get the number of channels.
            /// @return Byte_Type Number of channels.
            int Get_Channels();

            // - - Setters

            /// @brief Set the input file, output stream and decoder.
            /// @param Input_File Input file to play.
            /// @param Output_Stream Output stream to play the file.
            /// @param Decoder Decoder to use to decode the file.
            void Set(Drive_Types::File_Type &Input_File, Sound_Types::Stream_Type& Output_Stream, Decoder_Type &Decoder);

            /// @brief Set the decoder.
            /// @param Decoder Decoder to use to decode the file.
            void Set_Decoder(Decoder_Type &Decoder);

            /// @brief Set the player time.
            /// @param Time Time
            void Set_Time(Time_Type Time);

            /// @brief Set the player time.
            /// @param Time Time in seconds.
            void Set_Time(uint32_t Time);   // ! : Last for Berry

            /// @brief Set the input file.
            /// @param Input_Stream Input file to play.
            void Set_File(Drive_Types::File_Type &Input_File);

            /// @brief Set the output stream.
            /// @param Output_Stream Output stream to play the file.
            void Set_Output_Stream(Sound_Types::Stream_Type& Output_Stream);

        private:
            Decoder_Type* Decoder;
            Drive_Types::File_Type Input_File;
            Encoded_Stream_Type Encoded_Stream;
            Stream_Copier_Type Stream_Copier;

        } File_Player_Type;

    }
}

#endif