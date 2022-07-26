///
/// @file Color.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 08-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Color_Hpp_Included
#define Color_Hpp_Included

#include "lvgl.h"
#include "Arduino.h"

class Color_Filter_Descriptor_Class
{
public:
    typedef lv_color_filter_cb_t Callback_Type;

    void Set_Callback(Callback_Type Callback);

    lv_color_filter_dsc_t *Get_Pointer();

private:
    lv_color_filter_dsc_t LVGL_Color_Filter_Descriptor;
};

class Color_Class
{
public:
    // - Types

    typedef enum Palette_Enumeration
    {
        Red = LV_PALETTE_RED,
        Pink = LV_PALETTE_PINK,
        Purple = LV_PALETTE_PURPLE,
        Deep_Purple = LV_PALETTE_DEEP_PURPLE,
        Indigo = LV_PALETTE_INDIGO,
        Blue = LV_PALETTE_BLUE,
        Light_Blue = LV_PALETTE_LIGHT_BLUE,
        Cyan = LV_PALETTE_CYAN,
        Teal = LV_PALETTE_TEAL,
        Green = LV_PALETTE_GREEN,
        Light_Green = LV_PALETTE_LIGHT_GREEN,
        Lime = LV_PALETTE_LIME,
        Yellow = LV_PALETTE_YELLOW,
        Amber = LV_PALETTE_AMBER,
        Orange = LV_PALETTE_ORANGE,
        Deep_Orange = LV_PALETTE_DEEP_ORANGE,
        Brown = LV_PALETTE_BROWN,
        Blue_Grey = LV_PALETTE_BLUE_GREY,
        Grey = LV_PALETTE_GREY,
        None = LV_PALETTE_NONE,
    } Palette_Type;

    typedef lv_opa_t Opacity::Type;

    // - Methods

    // - - Contructor

    Color_Class();
    Color_Class(lv_color_t LVGL_Color);
    Color_Class(uint8_t Red, uint8_t Green, uint8_t Blue);
    Color_Class(uint32_t Hex, bool Hex_3 = false);
    Color_Class(uint16_t Hue, uint8_t Saturation, uint8_t Value);

    // - - Management

    void Change_Lightness(Opacity::Type Opacity);

    // - - Setters

    void Set_LVGL_Color(lv_color_t LVGL_Color);
    void Set_RGB(uint8_t Red, uint8_t Green, uint8_t Blue);
    void Set_RGB(uint32_t Hex, bool Hex_3 = false);
    void Set_HSV(uint16_t Hue, uint8_t Saturation, uint8_t Value);
    void Set_To_Black();
    void Set_To_White();
    void Set_Darker(Opacity::Type Opacity);
    void Set_Lighter(Opacity::Type Opacity);

    void Set_From_Palette_Main(Palette_Type Palette);
    void Set_From_Palette_Darken(Palette_Type Palette, uint8_t Level);
    void Set_From_Palette_Lighten(Palette_Type Palette, uint8_t Level);


    // - - Getters

    void Get_HSV(uint16_t &Hue, uint8_t &Saturation, uint8_t &Value);
    uint8_t Get_RGB_1_Bit();
    uint8_t Get_RGB_8_Bits();
    uint16_t Get_RGB_16_Bits();
    uint32_t Get_RGB_32_Bits();

    uint8_t Get_Brightness();

    static Color_Class Get_From_Palette_Main(Palette_Type Palette);
    static Color_Class Get_From_Palette_Darken(Palette_Type Palette, uint8_t Level);
    static Color_Class Get_From_Palette_Lighten(Palette_Type Palette, uint8_t Level);

    lv_color_t Get_LVGL_Color();
    lv_color_hsv_t Get_LVGL_HSV_Color();

protected:
    lv_color_t LVGL_Color;
};

#endif