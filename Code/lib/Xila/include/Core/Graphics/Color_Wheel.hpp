///
/// @file Color_Picker.hpp
/// @author  ()
/// @brief
/// @version 0.1
/// @date 04-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Color_Wheel_Hpp_Included
#define Color_Wheel_Hpp_Included

#include "Object.hpp"

namespace Xila_Namespace
{
    typedef class Color_Wheel_Class : public Object_Class
    {
    public:
        // -- Types

        class Mode
        {
        public:
            typedef lv_colorwheel_mode_t Type;

            enum Enumeration
            {
                Hue = LV_COLORWHEEL_MODE_HUE,
                Saturation = LV_COLORWHEEL_MODE_SATURATION,
                Value = LV_COLORWHEEL_MODE_VALUE
            };
        };

        // - Methods

        void Create(Object_Class Parent_Object) override;

        // - - Getters
        Mode::Type Get_Mode();
        bool Get_Mode_Fixed();

        Color_Type Get_Color();

        // - - Setters
        bool Set_Color(Color_Type Color);
        void Set_Mode(Mode::Type Mode);
        void Set_Mode_Fixed(bool Fixed);

        bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;
    } Color_Wheel_Type;
}

#endif