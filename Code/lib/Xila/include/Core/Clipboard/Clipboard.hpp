/// @file Clipboard.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 20-07-2022
///
/// @copyright Copyright (c) 2022

#ifndef Clipboard_Hpp_Included
#define Clipboard_Hpp_Included

#ifndef Xila_Default_Clipboard_Size
#define Xila_Default_Clipboard_Size 256
#endif

#include "../Module/Module.hpp"

//==============================================================================//
///
/// @brief Clipboard module
///

namespace Xila_Namespace
{
    namespace Clipboard_Types
    {
    }

    typedef class Clipboard_Class : public Module_Class
    {
    public:
        // - Methods

        Clipboard_Class();

        /// @brief Start the clipboard module.
        /// @return Xila_Class::Success if clipboard module is started correctly.
        Result_Type Start();

        /// @brief Stop the clipboard module.
        /// @return Xila_Class::Success if clipboard module is stopped correctly.
        Result_Type Stop();

        /// @brief Clear the clipboard.
        void Clear();

        /// @brief Copy a number to the clipboard.
        /// @param Value_To_Copy Number to copy.
        void Copy(QWord_Type Value_To_Copy);

        /// @brief Copy a string to the clipboard.
        /// @param String_To_Copy String to copy.
        void Copy(const char *String_To_Copy);

        /// @brief Copy a string to the clipboard.
        /// @param String_To_Copy String to copy.
        void Copy(const void *Data, Size_Type Data_Size);

        /// @brief Get the clipboard content as a number.
        QWord_Type Paste() const;

        /// @brief Get the clipboard content as a string.
        /// @param Destination_Char_Array Destination char array.
        /// @param Char_Array_Length Destination char array length.
        void Paste(char *Destination_Char_Array, Size_Type Char_Array_Length) const;

        /// @brief Get the clipboard content as a string.
        /// @param Destination_String Destination string.
        /// @return Destination string.
        String_Type &Paste(String_Type &Destination_String) const;

    protected:
        // - Attributes

        /// @brief Clipboard content union.
        union
        {
            uint8_t Split_Number[8];
            QWord_Type Number;
            Byte_Type Data[Xila_Default_Clipboard_Size + 1];
        };

    } Clipboard_Type;

    extern Clipboard_Type Clipboard;

}

#endif