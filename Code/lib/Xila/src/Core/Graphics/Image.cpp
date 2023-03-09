///
/// @file Image.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 14-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Image.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type &Image_Class::Class = lv_img_class;

// - Methods

// - - Constructors / destructors

Image_Class::Image_Class(const Object_Class &Object_To_Copy) : Object_Class(Object_To_Copy)
{
}

// - - Manipulation

void Image_Class::Create(Object_Class& Parent_Object)
{
    if (Parent_Object)
    {
        Set_Pointer(lv_img_create(Parent_Object.Get_Pointer()));
    }
}

// - - Setters
bool Image_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (Get_Pointer() != NULL)
    {
        return false;
    }
    if (!Has_Class(&lv_img_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Image_Class::Set_Source(const void *Source)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_img_set_src(Get_Pointer(), Source);
}

void Image_Class::Set_Angle(int16_t Angle)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_img_set_angle(Get_Pointer(), Angle);
}

void Image_Class::Set_Antialias(bool Enable)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_img_set_antialias(Get_Pointer(), Enable);
}

void Image_Class::Set_Offset_X(Coordinate_Type X_Offset)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_img_set_offset_x(Get_Pointer(), X_Offset);
}

void Image_Class::Set_Offset_Y(Coordinate_Type Y_Offset)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_img_set_offset_y(Get_Pointer(), Y_Offset);
}

void Image_Class::Set_Pivot(Coordinate_Type X, Coordinate_Type Y)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_img_set_pivot(Get_Pointer(), X, Y);
}

void Image_Class::Set_Size_Mode(Size_Mode_Type Mode)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_img_set_size_mode(Get_Pointer(), Mode);
}

void Image_Class::Set_Zoom(uint16_t Zoom)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_img_set_zoom(Get_Pointer(), Zoom);
}

// - - Getters

uint16_t Image_Class::Get_Angle()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_img_get_angle(Get_Pointer());
}

bool Image_Class::Get_Antialias()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_img_get_antialias(Get_Pointer());
}

Coordinate_Type Image_Class::Get_Offset_X()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_img_get_offset_x(Get_Pointer());
}

Coordinate_Type Image_Class::Get_Offset_Y()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_img_get_offset_y(Get_Pointer());
}

void Image_Class::Get_Pivot(Point_Type &Pivot)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_img_get_pivot(Get_Pointer(), &Pivot);
}

Image_Class::Size_Mode_Type Image_Class::Get_Size_Mode()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_img_get_size_mode(Get_Pointer());
}

const void *Image_Class::Get_Source()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_img_get_src(Get_Pointer());
}

uint16_t Image_Class::Get_Zoom()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_img_get_zoom(Get_Pointer());
}