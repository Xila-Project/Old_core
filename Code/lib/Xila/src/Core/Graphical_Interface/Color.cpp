///
/// @file Color.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 09-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Color.hpp"

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Color_Class::Change_Lightness(Opacity_Type Opacity)
{
    LVGL_Color = lv_color_change_lightness(LVGL_Color, Opacity);
}



// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

void Color_Class::Set(uint8_t Red, uint8_t Green, uint8_t Blue)
{
    LVGL_Color = lv_color_make(Red, Green, Blue);
}

void Color_Class::Set(uint32_t Hex, bool Hex_3)
{
    if (Hex_3)
    {
        LVGL_Color = lv_color_hex3(Hex);
    }
    else
    {
        LVGL_Color = lv_color_hex(Hex);
    }
}

void Color_Class::Set_To_Black()
{
    LVGL_Color = lv_color_black();
}

void Color_Class::Set_To_White()
{
    LVGL_Color = lv_color_white();
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

uint8_t Color_Class::Get_Brightness()
{
    return lv_color_brightness(LVGL_Color);
}

lv_color_t Color_Class::Get_LVGL_Color()
{
    return LVGL_Color;
}

lv_color_hsv_t Color_Class::Get_LVGL_HSV_Color()
{
    return lv_color_to_hsv(LVGL_Color);
}