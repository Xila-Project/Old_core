///
/// @file Slider.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 08-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef SLIDER_HPP_INCLUDED
#define SLIDER_HPP_INCLUDED

#include "Arduino.h"

#define Class Xila_Class::Diplsay_Class::Slider_Class // Shortcut

// --

inline bool Class::Is_Dragged()
{
    return lv_slider_is_dragged(this.Get_Pointer());
}

// -- Setters

inline void Class::Set_Value(int32_t Value, bool Animation)
{
    lv_slider_set_value(this.Get_Pointer(), Value);
}

inline void Class::Set_Left_Value(int32_t Value, bool Animation)
{
    lv_slider_set_left_value(this.Get_Pointer(), Value);
}

inline void Class::Set_Range(int32_t Minimum_Value, int32_t Maximum_Value)
{
    lv_slider_set_range(this.Get_Pointer(), Minimum_Value, Maximum_Value);
}

inline void Class::Set_Mode(Mode_Type Mode)
{
    lv_slider_set_mode(this.Get_Pointer(), Mode);
}

// -- Getters

inline int32_t Class::Get_Value()
{
    return lv_slider_get_value(this.Get_Pointer());
}

inline int32_t Class::Get_Left_Value()
{
    return lv_slider_get_left_value(this.Get_Pointer());
}

inline int32_t Class::Get_Minimum_Value()
{
    return lv_slider_get_min_value(this.Get_Pointer());
}

inline int32_t Class::Get_Maximum_Value()
{
    return lv_slider_get_max_value(this.Get_Pointer());
}

inline Mode_Type Class::Get_Mode()
{
    return lv_slider_get_mode(this.Get_Pointer());
}

#undef Class

#endif