///
/// @file Bar.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 07-05-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Core.hpp"

#define Class Xila_Class::Display_Class::Bar_Class

Class::Bar_Class::Bar_Class(Object_Type Parent_Object);
{
    this.LVGL_Object_Pointer = lv_bar_create(Parent_Object.Get_Pointer());
}

Class::Bar_Class(Object_Type Parent_Object, const Object_Type Copy);