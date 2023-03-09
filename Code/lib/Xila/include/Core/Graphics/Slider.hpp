///
/// @file Slider.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 08-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Slider_Hpp_Included
#define Slider_Hpp_Included

#include "Object.hpp"

namespace Xila_Namespace
{
    typedef class Slider_Class : public Object_Class
    {
    public:
        // - Types

        typedef lv_slider_mode_t Mode_Type;

        // - - Enumerations
        enum Mode_Enumeration
        {
            Normal = LV_SLIDER_MODE_NORMAL,
            Symmetrical = LV_SLIDER_MODE_SYMMETRICAL,
            Range = LV_SLIDER_MODE_RANGE,
        };

        typedef enum Draw_Part_Enumeration
        {
            Knob = LV_SLIDER_DRAW_PART_KNOB,
            Knob_Left = LV_SLIDER_DRAW_PART_KNOB_LEFT,
        } Draw_Part_Type;

        // - Methods

        // - - Constructors / destructors
        Slider_Class(const Object_Class &Object_To_Copy);

        // - - Manipulation
        virtual void Create(Object_Class& Parent_Object) override;

        bool Is_Dragged();

        // - - Setters.
        virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer) override;

        void Set_Value(int32_t Value, bool Animation);
        void Set_Left_Value(int32_t Value, bool Animation);
        void Set_Range(int32_t Minimum_Value, int32_t Maximum_Value);
        void Set_Mode(Mode_Type Mode);

        // - - Getters.
        int32_t Get_Value();
        int32_t Get_Left_Value();
        int32_t Get_Minimum_Value();
        int32_t Get_Maximum_Value();
        Mode_Type Get_Mode();

        // - Attributes
        static const Graphics_Types::Class_Type& Class;
    } Slider_Type;
}

#endif