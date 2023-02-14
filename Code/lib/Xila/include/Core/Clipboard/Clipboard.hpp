///
/// @file Clipboard.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Clipboard_Hpp_Included
#define Clipboard_Hpp_Included

#include "Arduino.h"

#include "../Module/Module.hpp"

#include "Core/Drive/Drive.hpp"

//==============================================================================//
///
/// @brief Clipboard module
///

namespace Xila_Namespace
{
    typedef class Clipboard_Class : public Module_Class
    {
    public:
        Clipboard_Class();

        void Clear();

        void Copy(uint64_t Value_To_Copy);
        void Copy(const char *Char_Array_To_Copy, size_t Char_Array_Length = 0);
        void Copy(String String_To_Copy); // deprecated : only for compatibility purpose
        void Copy(const void *Data, Size_Type Data_Size);

        uint64_t Paste() const;
        void Paste(char *Destination_Char_Array, Size_Type Char_Array_Length) const;


    protected:
        ///
        /// @brief Clipboard file.
        ///
        File_Type Clipboard_File;

        ///
        /// @brief Split number array.
        ///
        union {
            uint8_t Split_Number[8];
            uint64_t Number;
            char Char_Array[Xila_Clipboard_Size];
        };

    } Clipboard_Type;

    extern Clipboard_Type Clipboard;

}

#endif