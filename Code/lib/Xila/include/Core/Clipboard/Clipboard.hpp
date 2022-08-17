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

#include "../Module.hpp"

//==============================================================================//
///
/// @brief Clipboard module
///
class Clipboard_Class : public Module_Class
{
public:
    Result_Type Clear();

    Result_Type Copy(uint64_t const &Value_To_Copy);
    Result_Type Copy(const char *Char_Array_To_Copy, size_t Char_Array_Length = 0);
    Result_Type Copy(String const &String_To_Copy); // deprecated : only for compatibility purpose
    Result_Type Copy(const void* Data, Size_Type Data_Size);

    Result_Type Paste(uint64_t &Value_To_Paste);
    Result_Type Paste(char *Char_Array_To_Paste, size_t Char_Array_Length);
    Result_Type Paste(String &String_To_Paste);

    friend class Xila_Class;
    friend class Shell_Class;
    friend class Unit_Test_Class;

protected:
    ///
    /// @brief Clipboard file.
    ///
    File Clipboard_File;

    ///
    /// @brief Split number array.
    ///
    uint8_t Split_Number[8];
};

#endif