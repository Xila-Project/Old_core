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

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Color_Wheel_Class::Create(Object_Class Parent_Object)
{
    Set_Pointer(lv_colorwheel_create(Parent_Object.Get_Pointer(), true));
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

Color_Wheel_Class::Mode::Type Color_Wheel_Class::Get_Mode()
{ Graphics.Take_Semaphore_Auto();
    return lv_colorwheel_get_color_mode(Get_Pointer());
}

bool Color_Wheel_Class::Get_Mode_Fixed()
{ Graphics.Take_Semaphore_Auto();
    return lv_colorwheel_get_color_mode_fixed(Get_Pointer());
}

Object_Class::Color_Type Color_Wheel_Class::Get_Color()
{
    Color_Type Color(lv_colorwheel_get_rgb(Get_Pointer()));
    return Color;
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Color_Wheel_Class::Set_Pointer(lv_obj_t* LVGL_Object_Pointer)
{
     if (Get_Pointer() != NULL)
    {
        return false;
    }
    Graphics.Take_Semaphore_Auto();
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_colorwheel_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

bool Color_Wheel_Class::Set_Color(Color_Type Color)
{ Graphics.Take_Semaphore_Auto();
    return lv_colorwheel_set_rgb(Get_Pointer(), Color.Get_LVGL_Color());
}

void Color_Wheel_Class::Set_Mode(Mode::Type Mode)
{ Graphics.Take_Semaphore_Auto();
    lv_colorwheel_set_mode(Get_Pointer(), Mode);
}

void Color_Wheel_Class::Set_Mode_Fixed(bool Fixed)
{ Graphics.Take_Semaphore_Auto();
    lv_colorwheel_set_mode_fixed(Get_Pointer(), Fixed);
}