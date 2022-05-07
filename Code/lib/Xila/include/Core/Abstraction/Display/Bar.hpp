///
 /// @file Bar.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1
 /// @date 04-05-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

///
/// @brief Create a new bar.
/// 
/// @param Parent Parent object of the new bar.
/// @param Copy Object to copy from.
/// @return Object

#include "Arduino.h"

#ifndef BAR_HPP_INCLUDED
#define BAR_HPP_INCLUDED

#define Class Xila_Class::Display_Class::Bar_Class // Shortcut

inline void Class::Set_Value(int32_t Value, bool Enable_Animation = true)
{
    if (Enable_Animation)
    {
        lv_bar_set_value(Get_Pointer(), Value, LV_ANIM_ON);
    }
    else
    {
        lv_bar_set_value(Get_Pointer(), Value, LV_ANIM_OFF);
    }
}

inline void Class::Set_Start_Value(int32_t Start_Value, bool Enable_Animation)
{
    if (Enable_Animation)
    {
        lv_bar_set_start_value(Get_Pointer(), Start_Value, LV_ANIM_ON);
    }
    else
    {
        lv_bar_set_start_value(Get_Pointer(), Start_Value, LV_ANIM_OFF);
    }
}

inline void Class::Set_Range(int32_t Minimum_Value, int32_t Maximum_Value)
{
    lv_bar_set_range(Get_Pointer(), Minimum_Value, Maximum_Value);
}

inline void Class::Set_Mode(Mode_Type Mode)
{
    lv_bar_set_mode(Get_Pointer(), Mode);
}

inline int32_t Class::Get_Value()
{
    return lv_bar_get_value(Get_Pointer());
}

inline int32_t Class::Get_Start_Value()
{
    return lv_bar_get_start_value(Get_Pointer());
}

inline int32_t Class::Get_Minimum_Value()
{
    return lv_bar_get_minimum_value(Get_Pointer());
}

inline int32_t Class::Get_Maximum_Value()
{
    return lv_bar_get_maximum_value(Get_Pointer());
}

inline Mode_Type Class::Get_Mode()
{
    return lv_bar_get_mode(Get_Pointer());
}



#undef Class

#endif