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
    typedef class Clipboard_Class : public Module_Class
    {
    public:
        // - Methods
        Clipboard_Class();

        Result_Type Start();
        Result_Type Stop();

        void Clear();

        void Copy(QWord_Type Value_To_Copy);
        void Copy(const char*String_To_Copy);
        void Copy(const char *Char_Array_To_Copy, size_t Char_Array_Length = 0);
        void Copy(const void *Data, Size_Type Data_Size);

        QWord_Type Paste() const;
        void Paste(char *Destination_Char_Array, Size_Type Char_Array_Length) const;
        void Paste(String_Type &Destination_String) const;

    protected:
        // - Attributes

        /// @brief Split number array.
        union
        {
            uint8_t Split_Number[8];
            QWord_Type Number;
            Static_String_Type<Xila_Default_Clipboard_Size> String;
            Byte_Type Data[Xila_Default_Clipboard_Size + 1];
  
        };

    } Clipboard_Type;

    extern Clipboard_Type Clipboard;

}

#endif