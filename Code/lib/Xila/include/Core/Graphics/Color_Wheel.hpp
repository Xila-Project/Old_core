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
    namespace Graphics_Types
    {
        enum class Color_Wheel_Mode_Type : lv_colorwheel_mode_t
        {
            Hue = LV_COLORWHEEL_MODE_HUE,
            Saturation = LV_COLORWHEEL_MODE_SATURATION,
            Value = LV_COLORWHEEL_MODE_VALUE
        };

        typedef class Color_Wheel_Class : public Object_Class
        {
        public:
            // - Methods

            // - - Constructors / destructors
            Color_Wheel_Class();
            Color_Wheel_Class(const Object_Class &Object_To_Copy);

            // - - Manipulation
            virtual void Create(Object_Class Parent_Object) override;
            virtual void Create(Object_Class Parent_Object, bool Knob_Recolor);

            // - - Getters
            Color_Wheel_Mode_Type Get_Mode();
            bool Get_Mode_Fixed();
            Color_Type Get_Color();

            // - - Setters
            bool Set_Color(Color_Type Color);
            void Set_Mode(Color_Wheel_Mode_Type Mode);
            void Set_Mode_Fixed(bool Fixed);
            virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

            // - Attributes
            static const Class_Type &Class;

        } Color_Wheel_Type;
    } // namespace Graphics_Types
} // namespace Xila_Namespace

#endif