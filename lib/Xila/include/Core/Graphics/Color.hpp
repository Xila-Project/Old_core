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

// - Basic types inclusion
#include "Types.hpp"

namespace Xila_Namespace
{
    namespace Graphics_Types
    {
        typedef class Color_Filter_Descriptor_Class
        {
        public:
            typedef lv_color_filter_cb_t Callback_Type;

            void Set_Callback(Callback_Type Callback);

            operator lv_color_filter_dsc_t*()
            {
                return &LVGL_Color_Filter_Descriptor;
            }

            lv_color_filter_dsc_t *Get_Pointer();

        private:
            lv_color_filter_dsc_t LVGL_Color_Filter_Descriptor;
        } Color_Filter_Descriptor_Type;

        typedef class Color_Class 
        {
        public:
            // - Attributes

            static const Color_Class White;
            static const Color_Class Black;
            static const Color_Class Red[10];
            static const Color_Class Pink[10];
            static const Color_Class Purple[10];
            static const Color_Class Deep_Purple[10];
            static const Color_Class Indigo[10];
            static const Color_Class Blue[10];
            static const Color_Class Light_Blue[10];
            static const Color_Class Cyan[10];
            static const Color_Class Teal[10];
            static const Color_Class Green[10];
            static const Color_Class Light_Green[10];
            static const Color_Class Lime[10];
            static const Color_Class Yellow[10];
            static const Color_Class Amber[10];
            static const Color_Class Orange[10];
            static const Color_Class Deep_Orange[10];
            static const Color_Class Brown[10];
            static const Color_Class Blue_Grey[10];
            static const Color_Class Grey[10];
            static const Color_Class Xila_Red;
            static const Color_Class Xila_Green;
            static const Color_Class Xila_Blue;
            static const Color_Class Xila_Yellow;

            // - Methods

            // - - Constructor

            Color_Class();
            Color_Class(lv_color_t LVGL_Color);
            Color_Class(uint8_t Red, uint8_t Green, uint8_t Blue, bool HSV = false);
            Color_Class(uint32_t Hex, bool Hex_3 = false);

            // - - Management

            void Change_Lightness(Opacity_Type Opacity);

            // - - Setters

            void Set_LVGL_Color(lv_color_t LVGL_Color);
            void Set_RGB(uint8_t Red, uint8_t Green, uint8_t Blue);
            void Set_RGB(uint32_t Hex, bool Hex_3 = false);
            void Set_HSV(uint16_t Hue, uint8_t Saturation, uint8_t Value);
            void Set_To_Black();
            void Set_To_White();
            void Set_Darker(Opacity_Type Opacity);
            void Set_Lighter(Opacity_Type Opacity);

            // - - Getters

            void Get_HSV(uint16_t &Hue, uint8_t &Saturation, uint8_t &Value) const;
            uint8_t Get_RGB_1_Bit() const;
            uint8_t Get_RGB_8_Bits() const;
            uint16_t Get_RGB_16_Bits() const;
            uint32_t Get_RGB_32_Bits() const;

            uint8_t Get_Brightness() const;

            lv_color_t Get_LVGL_Color() const;
            lv_color_hsv_t Get_LVGL_HSV_Color() const;

            // - - Operators
            operator uint32_t() const;

        protected:
            lv_color_t LVGL_Color;

        } Color_Type;
    } // namespace Graphics_Types
} // namespace Xila_Namespace

#endif