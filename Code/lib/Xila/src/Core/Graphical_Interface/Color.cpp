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
//                                  Constructor
//
// ------------------------------------------------------------------------- //

Color_Class::Color_Class()
{
}

Color_Class::Color_Class(lv_color_t LVGL_Color)
{
    Set_LVGL_Color(LVGL_Color);
}

Color_Class::Color_Class(uint8_t Red, uint8_t Green, uint8_t Blue)
{
    Set_RGB(Red, Green, Blue);
}

Color_Class::Color_Class(uint32_t Hex, bool Hex_3)
{
    Set_RGB(Hex, Hex_3);
}

Color_Class::Color_Class(uint16_t Hue, uint8_t Saturation, uint8_t Value)
{
    Set_HSV(Hue, Saturation, Value);
}

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Color_Filter_Descriptor_Class::Set_Callback(Callback_Type Callback)
{
    lv_color_filter_dsc_init(Get_Pointer(), Callback);
}

void Color_Class::Change_Lightness(Opacity::Type Opacity)
{
    LVGL_Color = lv_color_change_lightness(LVGL_Color, Opacity);
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

void Color_Class::Set_LVGL_Color(lv_color_t LVGL_Color)
{
    this->LVGL_Color = LVGL_Color;
}

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

void Color_Class::Set_Darker(Opacity::Type Opacity)
{
    LVGL_Color = lv_color_darken(LVGL_Color, Opacity);
}

void Color_Class::Set_Lighter(Opacity::Type Opacity)
{
    LVGL_Color = lv_color_lighten(LVGL_Color, Opacity);
}

void Color_Class::Set_From_Palette_Main(Palette_Type Palette)
{
    LVGL_Color = lv_palette_main((lv_palette_t)Palette);
}

void Color_Class::Set_From_Palette_Lighten(Palette_Type Palette, uint8_t Level)
{
    LVGL_Color = lv_palette_lighten((lv_palette_t)Palette, Level);
}

void Color_Class::Set_From_Palette_Darken(Palette_Type Palette, uint8_t Level)
{
    LVGL_Color = lv_palette_darken((lv_palette_t)Palette, Level);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

lv_color_filter_dsc_t *Color_Filter_Descriptor_Class::Get_Pointer()
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

void Color_Class::Get_HSV(uint16_t &Hue, uint8_t &Saturation, uint8_t &Value)
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

Color_Class Color_Class::Get_From_Palette_Main(Palette_Type Palette)
{
    return Color_Class(lv_palette_main((lv_palette_t)Palette));
}

Color_Class Color_Class::Get_From_Palette_Lighten(Palette_Type Palette, uint8_t Level)
{
    return Color_Class(lv_palette_lighten((lv_palette_t)Palette, Level));
}

Color_Class Color_Class::Get_From_Palette_Darken(Palette_Type Palette, uint8_t Level)
{
    return Color_Class(lv_palette_darken((lv_palette_t)Palette, Level));
}

