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

#include "Arduino.h"
#include "lvgl.h"

#define Class Xila_Class::Display_Class::Arc_Class // Shortcut

inline void Class::Set_Start_Angle(uint16_t Start_Angle)
{
    lv_arc_set_start_angle(this.Get_Pointer(), Start_Angle);
}

inline void Class::Set_End_Angle(uint16_t End_Angle)
{
    lv_arc_set_end_angle(this.Get_Pointer(), End_Angle);
}

inline void Class::Set_Angles(uint16_t Start_Angle, uint16_t End_Angle)
{
    lv_arc_set_angles(this.Get_Pointer(), Start_Angle, End_Angle);
}

inline void Class::Set_Background_Start_Angle(uint16_t Start_Angle)
{
    lv_arc_set_bg_start_angle(this.Get_Pointer(), Start_Angle);
}

inline void Class::Set_Background_End_Angle(uint16_t End_Angle)
{
    lv_arc_set_bg_end_angle(this.Get_Pointer(), End_Angle);
}

inline void Class::Set_Background_Angles(uint16_t Start_Angle, uint16_t End_Angle)
{
    lv_arc_set_bg_angles(this.Get_Pointer(), Start_Angle, End_Angle);
}

inline void Class::Set_Rotation(uint16_t Rotation)
{
    lv_arc_set_rotation(this.Get_Pointer(), Rotation);
}

inline void Class::Set_Mode(Class::Mode_Type Mode)
{
    lv_arc_set_mode(this.Get_Pointer(), Mode);
}

inline void Class::Set_Value(int16_t Value)
{
    lv_arc_set_value(this.Get_Pointer(), Value);
}

inline void Class::Set_Range(int16_t Minimum_Value, int16_t Maximum_Value)
{
    lv_arc_set_range(this.Get_Pointer(), Min_Value, Max_Value);
}

inline void Class::Set_Change_Rate(uint16_t Rate)
{
    lv_arc_set_change_rate(this.Get_Pointer(), Rate);
}

inline uint16_t Class::Get_Angle_Start()
{
    return lv_arc_get_angle_start(this.Get_Pointer());
}

inline uint16_t Class::Get_Angle_End()
{
    return lv_arc_get_angle_end(this.Get_Pointer());
}

inline uint16_t Class::Get_Background_Angle_Start()
{
    return lv_arc_get_bg_angle_start(this.Get_Pointer());
}

inline uint16_t Class::Get_Background_Angle_End()
{
    return lv_arc_get_bg_angle_end(this.Get_Pointer());
}

inline int16_t Class::Get_Value()
{
    return lv_arc_get_value(this.Get_Pointer());
}

inline int16_t Class::Get_Minimum_Value()
{
    return lv_arc_get_min_value(this.Get_Pointer());
}

inline int16_t Class::Get_Maximum_Value()
{
    return lv_arc_get_max_value(this.Get_Pointer());
}

inline Mode_Type Class::Get_Mode()
{
    return lv_arc_get_mode(this.Get_Pointer());
}


#endif