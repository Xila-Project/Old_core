///
/// @file Arc.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 07-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Arc_Hpp_Included
#define Arc_Hpp_Included

#include "Object.hpp"

namespace Xila_Namespace
{
    typedef class Arc_Class : public Object_Class
    {
    public:
        /// @brief Mode type.

        class Mode
        {
        public:
            typedef lv_arc_mode_t Type;

            /// @brief Mode enumeration.
            enum Enumeration
            {
                Normal = LV_ARC_MODE_NORMAL,
                Symmetrical = LV_ARC_MODE_SYMMETRICAL,
                Reverse = LV_ARC_MODE_REVERSE
            };
        };

        class Draw_Part
        {
        public:
            /// @brief Draw part type and enumeration.
            typedef enum Enumeration
            {
                Background = LV_ARC_DRAW_PART_BACKGROUND,
                Foreground = LV_ARC_DRAW_PART_FOREGROUND,
                Knob = LV_ARC_DRAW_PART_KNOB
            } Type;
        };

        // - Methods

        // - - Constructors / destructors
        Arc_Class(const Object_Class &Object_To_Copy);

        // - - Management

        virtual void Create(Object_Class& Parent_Object) override;

        // - - Setters.

        virtual bool Set_Pointer(lv_obj_t *Object_Pointer) override;

        // - - - Angles
        void Set_Start_Angle(uint16_t Start_Angle);
        void Set_End_Angle(uint16_t End_Angle);
        void Set_Angles(uint16_t Start_Angle, uint16_t End_Angle);
        void Set_Background_Start_Angle(uint16_t Start_Angle);
        void Set_Background_End_Angle(uint16_t End_Angle);
        void Set_Background_Angles(uint16_t lv_arc_set_start_angle, uint16_t End_Angle);
        void Set_Range(int16_t Minimum, int16_t Maximum);
        void Set_Change_Rate(uint16_t Rate);

        void Set_Rotation(uint16_t Rotation);

        void Set_Mode(Mode::Type Mode);
        void Set_Value(int16_t Value);

        // - - Getters.

        uint16_t Get_Angle_Start();
        uint16_t Get_Angle_End();

        uint16_t Get_Background_Angle_Start();
        uint16_t Get_Background_Angle_End();

        int16_t Get_Value();
        int16_t Get_Minimum_Value();
        int16_t Get_Maximum_Value();

        Mode::Type Get_Mode();

        // - - Attributes
        static const Graphics_Types::Class_Type& Class;
    } Arc_Type;
}

#endif