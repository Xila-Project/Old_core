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

class Color_Class
{
public:

    // - Types

    typedef lv_opa_t Opacity_Type;


    // - Methods

    // - - Management

    void Change_Lightness(Opacity_Type Opacity);
    uint8_t Convert_To_1_Bit();
    uint8_t Convert_To_8_Bits();
    uint16_t Convert_To_16_Bits();
    uint32_t Convert_To_32_Bits();
    
    // - - Setters

    void Set(uint8_t Red, uint8_t Green, uint8_t Blue);
    void Set(uint32_t Hex, bool Hex_3 = false);
    void Set_To_Black();
    void Set_To_White();
    
    // - - Getters

    uint8_t Get_Brightness();

    lv_color_t Get_LVGL_Color();
    lv_color_hsv_t Get_LVGL_HSV_Color();
    
protected:

    lv_color_t LVGL_Color;
};

#endif