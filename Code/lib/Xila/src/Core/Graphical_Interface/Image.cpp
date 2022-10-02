///
/// @file Image.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 14-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphical_Interface/Image.hpp"

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Image_Class::Create(Object_Class Parent_Object)
{
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_img_create(Parent_Object.Get_Pointer()));
    }
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Image_Class::Set_Pointer(lv_obj_t* LVGL_Object_Pointer)
{
     if (Get_Pointer() == NULL)
    {
        return false;
    }
    if (!lv_obj_has_class(LVGL_Object_Pointer, &lv_img_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Image_Class::Set_Source(const void* Source)
{
    lv_img_set_src(Get_Pointer(), Source);
}

void Image_Class::Set_Angle(int16_t Angle)
{
    lv_img_set_angle(Get_Pointer(), Angle);
}

void Image_Class::Set_Antialias(bool Enable)
{
    lv_img_set_antialias(Get_Pointer(), Enable);
}

void Image_Class::Set_Offset_X(Coordinate_Type X_Offset)
{
    lv_img_set_offset_x(Get_Pointer(), X_Offset);
}

void Image_Class::Set_Offset_Y(Coordinate_Type Y_Offset)
{
    lv_img_set_offset_y(Get_Pointer(), Y_Offset);
}

void Image_Class::Set_Pivot(Coordinate_Type X, Coordinate_Type Y)
{
    lv_img_set_pivot(Get_Pointer(), X, Y);
}

void Image_Class::Set_Size_Mode(Size_Mode_Type Mode)
{
    lv_img_set_size_mode(Get_Pointer(), Mode);
}

void Image_Class::Set_Zoom(uint16_t Zoom)
{
    lv_img_set_zoom(Get_Pointer(), Zoom);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

uint16_t Image_Class::Get_Angle()
{
    return lv_img_get_angle(Get_Pointer());
}

bool Image_Class::Get_Antialias()
{
    return lv_img_get_antialias(Get_Pointer());
}

Object_Class::Coordinate_Type Image_Class::Get_Offset_X()
{
    return lv_img_get_offset_x(Get_Pointer());
}

Object_Class::Coordinate_Type Image_Class::Get_Offset_Y()
{
    return lv_img_get_offset_y(Get_Pointer());
}

void Image_Class::Get_Pivot(Point_Type& Pivot)
{
    return lv_img_get_pivot(Get_Pointer(), &Pivot);
}

Image_Class::Size_Mode_Type Image_Class::Get_Size_Mode()
{
    return lv_img_get_size_mode(Get_Pointer());
}

const void* Image_Class::Get_Source()
{
    return lv_img_get_src(Get_Pointer());
}

uint16_t Image_Class::Get_Zoom()
{
    return lv_img_get_zoom(Get_Pointer());
}