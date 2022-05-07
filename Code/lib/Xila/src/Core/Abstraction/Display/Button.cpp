///
/// @file Button.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 07-05-2022
///
/// @copyright Copyright (c) 2022
///

#include "Xila.hpp"

#define Class Xila_Class::Display_Class::Button_Class

#include "Core/Core.hpp"

Class::Button_Class(Object_Type& Parent_Object)
{
    this.LVGL_Object_Pointer = lv_btn_create(Parent_Object.Get_Pointer());

#undef Class