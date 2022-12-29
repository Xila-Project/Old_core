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

// - Basic types inclusion
#include "Types.hpp"

namespace Xila_Namespace
{
    typedef class Color_Filter_Descriptor_Class
    {
    public:
        typedef lv_color_filter_cb_t Callback_Type;

        void Set_Callback(Callback_Type Callback);

        lv_color_filter_dsc_t *Get_Pointer();

    private:
        lv_color_filter_dsc_t LVGL_Color_Filter_Descriptor;
    } Color_Filter_Descriptor_Type;

    typedef class Color_Class : public Types_Class
    {
    public:
        // - Types

        typedef enum Tag_Enumeration
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
        } Tag_Type;

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

        void Set_From_Palette(Tag_Type Color_Tag, int8_t Level = 0);
        // - - Getters

        void Get_HSV(uint16_t &Hue, uint8_t &Saturation, uint8_t &Value) const;
        uint8_t Get_RGB_1_Bit() const;
        uint8_t Get_RGB_8_Bits() const;
        uint16_t Get_RGB_16_Bits() const;
        uint32_t Get_RGB_32_Bits() const;

        uint8_t Get_Brightness() const;

        static Color_Class Get_From_Palette(Tag_Type Color_Tag, int8_t Level = 0);
        static Color_Class Get_White();
        static Color_Class Get_Black();

        lv_color_t Get_LVGL_Color() const;
        lv_color_hsv_t Get_LVGL_HSV_Color() const;

    protected:
        lv_color_t LVGL_Color;
    } Color_Type;
}

#endif