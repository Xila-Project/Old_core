///
/// @file Area.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 09-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Area.hpp"

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Area_Class::Increase(Coordinate_Type Extra_Width, Coordinate_Type Extra_Height)
{
    lv_area_increase(&LVGL_Area, Extra_Width, Extra_Height);
}

void Area_Class::Move(Coordinate_Type X_Offset, Coordinate_Type Y_Offset)
{
    lv_area_move(&LVGL_Area, X_Offset, Y_Offset);
}

void Area_Class::Align(Area_Class To_Align_To, Alignment_Type Alignment, Coordinate_Type X_Offset, Coordinate_Type Y_Offset)
{
    lv_area_align(&To_Align_To.LVGL_Area, &LVGL_Area, Alignment, X_Offset, Y_Offset);
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

void Area_Class::Set(LVGL_Area_Type Area)
{
    LVGL_Area = Area;
}

void Area_Class::Set(Coordinate_Type X_1, Coordinate_Type Y_1, Coordinate_Type X_2, Coordinate_Type Y_2)
{
    lv_area_set(&LVGL_Area, X_1, Y_1, X_2, Y_2);
}


void Area_Class::Set_Width(Coordinate_Type Width)
{
    lv_area_set_width(&LVGL_Area, Width);
}

void Area_Class::Set_Height(Coordinate_Type Height)
{
    lv_area_set_height(&LVGL_Area, Height);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //


Area_Class::Coordinate_Type Area_Class::Get_Width()
{
    return lv_area_get_width(&LVGL_Area);
}

Area_Class::Coordinate_Type Area_Class::Get_Height()
{
    return lv_area_get_height(&LVGL_Area);
}

uint32_t Area_Class::Get_Size()
{
    return lv_area_get_size(&LVGL_Area);
}

const Area_Class::LVGL_Area_Type Area_Class::Get_LVGL_Area()
{
    return LVGL_Area;
}