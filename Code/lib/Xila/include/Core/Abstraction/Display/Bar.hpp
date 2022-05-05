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

inline Object_Type Class::Create(Object_Type Parent, const Object_Type Copy)
{
    return lv_bar_create(Parent, Copy);
}

inline void Class::Set__Value(Object_Type Bar, int16_t Value, Animation Animation_State = Enable)
{
    lv_bar_set_value(Bar, Value, Animation_State);
}

inline void Class::Set_Start_Value(Object_Type Bar, int16_t Value, Animation Animation_State)
{
    lv_bar_set_start_value(Bar, Value, Animation_State);
}

inline void Class::Set_Range(Object_Type Bar, int32_t Minimum_Value, int32_t Maximum_Value)
{
    lv_bar_set_range(Bar, Minimum_Value, Maximum_Value);
}

inline void Class::Set_Type(Object_Type Bar, Type_Enum Type)
{
    lv_bar_set_type(Bar, Type);
}




#endif