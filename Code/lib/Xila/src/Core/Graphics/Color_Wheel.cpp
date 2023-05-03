///
/// @file Color_Wheel.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 17-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Color_Wheel.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type &Color_Wheel_Class::Class = lv_colorwheel_class;

// - Methods

// - - Constructors / destructors

Color_Wheel_Class::Color_Wheel_Class() : Object_Class()
{
}

Color_Wheel_Class::Color_Wheel_Class(const Object_Class &Object_To_Copy)
{
    Set_Pointer(Object_To_Copy.Get_Pointer());
}

// - - Manipulation

void Color_Wheel_Class::Create(Object_Class Parent_Object)
{
    this->Create(Parent_Object, true);
}

void Color_Wheel_Class::Create(Object_Class Parent_Object, bool Knob_Recolor)
{
    if (Parent_Object)
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_colorwheel_create(Parent_Object.Get_Pointer(), Knob_Recolor);
    }
}

// - - Getters

Color_Wheel_Class::Mode::Type Color_Wheel_Class::Get_Mode()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_colorwheel_get_color_mode(Get_Pointer());
}

bool Color_Wheel_Class::Get_Mode_Fixed()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_colorwheel_get_color_mode_fixed(Get_Pointer());
}

Color_Type Color_Wheel_Class::Get_Color()
{
    Color_Type Color(lv_colorwheel_get_rgb(Get_Pointer()));
    return Color;
}

// - - Setters

bool Color_Wheel_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
    {
        return false;
    }
    Object_Type Object(LVGL_Object_Pointer);
    if (!Object.Check_Class(&lv_colorwheel_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

bool Color_Wheel_Class::Set_Color(Color_Type Color)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_colorwheel_set_rgb(Get_Pointer(), Color.Get_LVGL_Color());
}

void Color_Wheel_Class::Set_Mode(Mode::Type Mode)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_colorwheel_set_mode(Get_Pointer(), Mode);
}

void Color_Wheel_Class::Set_Mode_Fixed(bool Fixed)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_colorwheel_set_mode_fixed(Get_Pointer(), Fixed);
}