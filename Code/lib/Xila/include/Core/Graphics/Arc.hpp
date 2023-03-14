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
                Normal = LV_ARC_MODE_NORMAL,            ///< Draw the arc from start to end angle
                Symmetrical = LV_ARC_MODE_SYMMETRICAL,  ///< Draw the arc symmetrically from the center
                Reverse = LV_ARC_MODE_REVERSE           ///< Draw the arc from end to start angle
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

        /// @brief Default constructor.
        Arc_Class();

        /// @brief Copy constructor to allow conversion from object.
        /// @param Object_To_Copy Object to copy.
        Arc_Class(const Object_Class &Object_To_Copy);

        // - - Management

        /// @brief Create an arc object.
        /// @param Parent_Object Parent object.
        virtual void Create(Object_Class Parent_Object) override;

        // - - Setters.

        /// @brief Set the object LVGL pointer.
        /// @details The current object pointer must be NULL and the new pointer must be of arc class.
        /// @param Object_Pointer Object pointer.
        /// @return true if the pointer has been set, false otherwise.
        virtual bool Set_Pointer(lv_obj_t *Object_Pointer) override;

        // - - - Angles

        /// @brief Set the start angle of the arc.
        /// @param Start_Angle Start angle in degrees in clockwise direction from 3 o'clock.
        void Set_Start_Angle(uint16_t Start_Angle);

        /// @brief Set the end angle of the arc.
        /// @param End_Angle End angle in degrees in clockwise direction from 3 o'clock.
        /// @note The end angle must be greater than the start angle.
        void Set_End_Angle(uint16_t End_Angle);

        /// @brief Set the start and end angles of the arc.
        /// @param Start_Angle Start angle in degrees.
        void Set_Angles(uint16_t Start_Angle, uint16_t End_Angle);

        /// @brief Set the start angle of the background arc.
        /// @param Start_Angle Start angle in degrees in clockwise direction from 3 o'clock.
        void Set_Background_Start_Angle(uint16_t Start_Angle);

        /// @brief Set the end angle of the arc background.
        /// @param End_Angle End angle in degrees in clockwise direction from 3 o'clock.
        void Set_Background_End_Angle(uint16_t End_Angle);

        /// @brief Set the start and end angles of the arc background.
        /// @param Start_Angle  Start angle in degrees in clockwise direction from 3 o'clock.
        /// @param End_Angle    End angle in degrees in clockwise direction from 3 o'clock.
        void Set_Background_Angles(uint16_t lv_arc_set_start_angle, uint16_t End_Angle);

        /// @brief Set the rotation of the arc.
        /// @param Rotation Rotation in degrees in clockwise direction from 3 o'clock.
        void Set_Range(int16_t Minimum, int16_t Maximum);

        /// @brief Set a change rate to limit the speed how fast the arc should reach the pressed point.
        /// @param Rate     Change rate in degrees per second.
        void Set_Change_Rate(uint16_t Rate);

        /// @brief  Set the rotation for the whole arc.
        /// @param Rotation     Rotation in degrees in clockwise direction from 3 o'clock.
        void Set_Rotation(uint16_t Rotation);

        /// @brief Set the mode of the arc.
        /// @param Mode Mode of the arc.
        void Set_Mode(Mode::Type Mode);

        /// @brief Set a new value on the arc.
        /// @param Value New value 
        void Set_Value(int16_t Value);

        // - - Getters.

        /// @brief Get the start angle of the arc.
        /// @return Start angle in degrees in clockwise direction from 3 o'clock.
        uint16_t Get_Angle_Start();

        /// @brief Get the end angle of the arc.
        /// @return End angle in degrees in clockwise direction from 3 o'clock.
        uint16_t Get_Angle_End();

        /// @brief Get the start angle of the arc background.
        /// @return Start angle in degrees in clockwise direction from 3 o'clock.
        uint16_t Get_Background_Angle_Start();

        /// @brief Get the end angle of the arc background.
        /// @return End angle in degrees in clockwise direction from 3 o'clock.
        uint16_t Get_Background_Angle_End();

        /// @brief Get the rotation of the arc.
        /// @return Rotation in degrees in clockwise direction from 3 o'clock.
        int16_t Get_Value();

        /// @brief Get the minimum value of the arc.
        /// @return Minimum value.
        int16_t Get_Minimum_Value();

        /// @brief Get the maximum value of the arc.
        /// @return Maximum value.
        int16_t Get_Maximum_Value();

        /// @brief Get the change rate of the arc.
        /// @return Change rate in degrees per second.
        Mode::Type Get_Mode();

        // - - Attributes

        /// @brief Arc class.
        static const Graphics_Types::Class_Type& Class;
    } Arc_Type;
}

#endif