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

class Arc_Class : public Object_Class
{
public:

    /// @brief Mode type.
    typedef lv_arc_mode_t Mode_Type;

    /// @brief Mode enumeration.
    typedef enum Mode_Enumeration
    {
        Normal = LV_ARC_MODE_NORMAL,
        Symmetrical = LV_ARC_MODE_SYMMETRICAL,
        Reverse = LV_ARC_MODE_REVERSE
    };

    /// @brief Draw part type and enumeration.
    enum
    {
        Background = LV_ARC_DRAW_PART_BACKGROUND,
        Foreground = LV_ARC_DRAW_PART_FOREGROUND,
        Knob = LV_ARC_DRAW_PART_KNOB
    } Draw_Part::Type;

    // - Methods

    // - - Management

    void Create(Object_Class Parent_Object);

    // - - Setters.

    bool Set_Pointer(lv_obj_t* Object_Pointer);

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

    void Set_Mode(Mode_Type Mode);
    void Set_Value(int16_t Value);

    // - - Getters.

    uint16_t Get_Angle_Start();
    uint16_t Get_Angle_End();

    uint16_t Get_Background_Angle_Start();
    uint16_t Get_Background_Angle_End();

    int16_t Get_Value();
    int16_t Get_Minimum_Value();
    int16_t Get_Maximum_Value();

    Mode_Type Get_Mode();



protected:

};




#endif