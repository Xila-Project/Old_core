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

    /// @brief Sound class API
    typedef class Sound_Class : public Module_Class
    {
    public:
        // - Methods

        // - - Constructor / destructor

        Sound_Class();

        Result_Type Start();
        Result_Type Stop();

        // - - Getters

        Byte_Type Get_Volume();
        Sound_Types::Stream_Type& Get_Current_Output_Stream();

        // - - Setters

        void Set_Volume(Byte_Type Volume);

        // - - Operation

        //   protected:
        // - Attributes

        /// @brief Output stream.
        Sound_Types::I2S_Type I2S_Output_Stream;

        /// @brief Stream volume.
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

    extern Sound_Type Sound;
};

#endif