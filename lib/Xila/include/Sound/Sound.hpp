///
/// @file Sound.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 21-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Sound_Hpp_Included
#define Sound_Hpp_Included

#include "../Module/Module.hpp"

#include "AudioTools.h"

#include "File_Player.hpp"
#include "I2S.hpp"
#include "Stream.hpp"
#include "Volume.hpp"
#include "Decoder.hpp"

//==============================================================================//

namespace Xila_Namespace
{
    namespace Sound_Types
    {
        // - Types

        // - - Mixer
        template <typename Type>
        using Input_Mixer_Type = InputMixer<Type>;
        template <typename Type>
        using Output_Mixer_Type = OutputMixer<Type>;
    }

    /// @brief Sound class.
    typedef class Sound_Class : public Module_Class
    {
    public:
        // - Methods

        // - - Constructor / destructor

        Sound_Class();

        /// @brief Start the sound module.
        /// @return Result_Type
        Result_Type Start();

        /// @brief Stop the sound module.
        /// @return Result_Type
        Result_Type Stop();

        // - - Getters

        /// @brief Get the general volume.
        /// @return Byte_Type Volume.
        Real_Type Get_Volume();

        /// @brief Get the stream of the current output.
        /// @return Sound_Types::Stream_Type& Stream of the current output.
        Sound_Types::Stream_Type& Get_Current_Output_Stream();

        // - - Setters

        /// @brief Set the general volume.
        /// @param Volume Volume (0 - 1 for no boost).
        void Set_Volume(Real_Type Volume);

        // - - Operation

        //   protected:
        // - Attributes

        /// @brief I2S output stream.
        Sound_Types::I2S_Type I2S_Output_Stream;

        /// @brief Volume stream used to control the general volume.
        Sound_Types::Volume_Type Volume_Stream;

        /// @brief Outputs mixer.
        //     Sound_Types::Output_Mixer_Type<int16_t> Mixer;

        /// @brief Custom pin to tone.
        uint8_t Custom_Pin;

        /// @brief Custom data pin.
        uint8_t Data_Pin;

        /// @brief Custom word select pin.
        uint8_t Word_Select_Pin;

        /// @brief Custom clock pin.
        uint8_t Clock_Pin;

        uint8_t Output;

        // - Methods
        Result_Type Save_Registry();
        Result_Type Load_Registry();
        Result_Type Create_Registry();

        friend class Unit_Test_Class;
    } Sound_Type;

    /// @brief Sound module instance.
    extern Sound_Type Sound;
};

#endif