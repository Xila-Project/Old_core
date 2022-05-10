///
 /// @file Line.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 10-05-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #ifndef LINE_HPP_INCLUDED
 #define LINE_HPP_INCLUDED

#include "Arduino.h"
#include "lvgl.h"

#define Class Xila_Class::Display_Class::Line_Class

inline void Class::Set_Points(const Point_Type Points[], uint16_t Count)
{
    lv_line_set_points(Get_Pointer(), Points, Count);
}

inline void Class::Set_Y_Inversion(bool Inversion)
{
    lv_line_set_y_invert(Get_Pointer(), Inversion);
}

inline bool Class::Get_Y_Inversion()
{
    return lv_line_get_y_invert(Get_Pointer());
}

#undef Class

#endif