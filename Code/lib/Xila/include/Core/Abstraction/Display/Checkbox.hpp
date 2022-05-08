///
/// @file Checkbox.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 08-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED

#include "Arduino.h"
#include "lvgl.h"

#define Class Xila_Class::Display_Class::Checkbox_Class // Shortcut

inline void Class::Set_Text(const char* Text)
{
    lv_checkbox_set_text(this.Get_Pointer(), Text);
}

inline void Class::Set_Text_Static(const char* Text)
{
    lv_checkbox_set_text_static(this.Get_Pointer(), Text);
}

inline const char* Class::Get_Text()
{
    return lv_checkbox_get_text(this.Get_Pointer());
}

#undef Class

#endif
