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

    typedef lv_opa_t Opacity_Type;

    // - Methods

    // - - Management

    void Change_Lightness(Opacity_Type Opacity);

    // - - Setters

    void Set_RGB(uint8_t Red, uint8_t Green, uint8_t Blue);
    void Set_RGB(uint32_t Hex, bool Hex_3 = false);
    void Set_HSV(uint16_t Hue, uint8_t Saturation, uint8_t Value);
    void Set_To_Black();
    void Set_To_White();
    void Set_Darker(Opacity_Type Opacity);
    void Set_Lighter(Opacity_Type Opacity);

    // - - Getters

    void Get_HSV(uint16_t &Hue, uint8_t &Saturation, uint8_t &Value);
    uint8_t Get_RGB_1_Bit();
    uint8_t Get_RGB_8_Bits();
    uint16_t Get_RGB_16_Bits();
    uint32_t Get_RGB_32_Bits();

    uint8_t Get_Brightness();

    lv_color_t Get_LVGL_Color();
    lv_color_hsv_t Get_LVGL_HSV_Color();

protected:
    lv_color_t LVGL_Color;
};

#endif