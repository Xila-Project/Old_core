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

void Color_Filter_Descriptor_Class::Set_Callback(Callback_Type Callback)
{
    lv_color_filter_dsc_init(Get_Pointer(), Callback);
}

void Color_Class::Change_Lightness(Opacity_Type Opacity)
{
    LVGL_Color = lv_color_change_lightness(LVGL_Color, Opacity);
}

uint8_t Color_Class::Convert_To_1_Bit()
{
    return lv_color_to1(LVGL_Color);
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

void Color_Class::Set_RGB(uint8_t Red, uint8_t Green, uint8_t Blue)
{
    LVGL_Color = lv_color_make(Red, Green, Blue);
}

void Color_Class::Set_RGB(uint32_t Hex, bool Hex_3)
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

void Color_Class::Set_HSV(uint16_t Hue, uint8_t Saturation, uint8_t Value)
{
    LVGL_Color = lv_color_hsv_to_rgb(Hue, Saturation, Value);
}

void Color_Class::Set_To_Black()
{
    LVGL_Color = lv_color_black();
}

void Color_Class::Set_To_White()
{
    LVGL_Color = lv_color_white();
}

void Color_Class::Set_Darker(Opacity_Type Opacity)
{
    LVGL_Color = lv_color_darken(LVGL_Color, Opacity);
}

void Color_Class::Set_Lighter(Opacity_Type Opacity)
{
    LVGL_Color = lv_color_lighten(LVGL_Color, Opacity);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

lv_color_filter_dsc_t* Color_Filter_Descriptor_Class::Get_Pointer()
{
    return &LVGL_Color_Filter_Descriptor;
}

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

void Color_Class::Get_HSV(uint16_t& Hue, uint8_t& Saturation, uint8_t& Value)
{
    lv_color_hsv_t HSV_Color = lv_color_to_hsv(LVGL_Color);
    Hue = HSV_Color.h;
    Saturation = HSV_Color.s;
    Value = HSV_Color.v;
}

uint8_t Color_Class::Get_RGB_1_Bit()
{
    return lv_color_to1(LVGL_Color);
}

uint8_t Color_Class::Get_RGB_8_Bits()
{
    return lv_color_to8(LVGL_Color);
}

uint16_t Color_Class::Get_RGB_16_Bits()
{
    return lv_color_to16(LVGL_Color);
}

uint32_t Color_Class::Get_RGB_32_Bits()
{
    return lv_color_to32(LVGL_Color);
}
