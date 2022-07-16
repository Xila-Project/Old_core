///
 /// @file Chart.cpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 09-07-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

#include "Core/Graphical_Interface/Canvas.hpp"

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

void Canvas_Class::Create(Object_Class& Parent_Object)
{
    if (Parent_Object.Is_Valid())
    {
        Set_Pointer(lv_canvas_create(Parent_Object.Get_Pointer()));
    }
}

void Canvas_Class::Horizontal_Blur(const Area_Type& Area, uint16_t Radius)
{
    lv_canvas_blur_hor(Get_Pointer(), &Area.LVGL_Area, Radius);
}

void Canvas_Class::Vertical_Blur(const Area_Type& Area, uint16_t Radius)
{
    lv_canvas_blur_ver(Get_Pointer(), &Area.LVGL_Area, Radius);
}


void Canvas_Class::Copy_Buffer(const void* Buffer_To_Copy, Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Width, Coordinate_Type Height)
{
    lv_canvas_copy_buf(Get_Pointer(), Buffer_To_Copy, X, Y, Width, Height);
}

void Canvas_Class::Transform(Image_Descriptor_Type* Image, int16_t Angle, uint16_t Zoom, Coordinate_Type Offset_X, Coordinate_Type Offset_Y, int32_t Pivot_X, int32_t Pivot_Y, bool Anti_Aliasing)
{
    lv_canvas_transform(Get_Pointer(), Image, Angle, Zoom, Offset_X, Offset_Y, Pivot_X, Pivot_Y, Anti_Aliasing);
}


void Canvas_Class::Fill_Background(Color_Type Color, Opacity_Type Opacity)
{
    lv_canvas_fill_bg(Get_Pointer(), Color, Opacity);
}

void Canvas_Class::Draw_Rectangle(Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Width, Coordinate_Type Height, const Draw_Rectangle_Descriptor_Type* Draw_Rectangle_Descriptor)
{
    lv_canvas_draw_rect(Get_Pointer(), X, Y, Width, Height, Draw_Rectangle_Descriptor);
}

void Canvas_Class::Draw_Text(Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Maximum_Width, Draw_Label_Descriptor_Type* Draw_Label_Descriptor, const char* Text)
{
    lv_canvas_draw_text(Get_Pointer(), X, Y, Maximum_Width, Draw_Label_Descriptor, Text);
}

void Canvas_Class::Draw_Image(Coordinate_Type X, Coordinate_Type Y, const void* Source, const Draw_Image_Descriptor_Type* Draw_Image_Descriptor)
{
    lv_canvas_draw_img(Get_Pointer(), X, Y, Source, Draw_Image_Descriptor);
}

void Canvas_Class::Draw_Polygon(const Point_Type Points[], uint32_t Number_Of_Point, const Draw_Rectangle_Descriptor_Type* Draw_Polygon_Descriptor)
{
    lv_canvas_draw_polygon(Get_Pointer(), Points, Number_Of_Point, Draw_Polygon_Descriptor);
}

void Canvas_Class::Draw_Line(const Point_Type Points[], uint32_t Number_Of_Point, const Draw_Line_Descriptor_Type* Draw_Line_Descriptor)
{
    lv_canvas_draw_line(Get_Pointer(), Points, Number_Of_Point, Draw_Line_Descriptor);
}

void Canvas_Class::Draw_Arc(Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Radius, int32_t Start_Angle, int32_t End_Angle, const Draw_Arc_Descriptor_Type* Draw_Arc_Descriptor)
{
    lv_canvas_draw_arc(Get_Pointer(), X, Y, Radius, Start_Angle, End_Angle, Draw_Arc_Descriptor);
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

bool Canvas_Class::Set_Pointer(lv_obj_t *LVGL_Object_Pointer)
{
    if (!lv_obj_has_class(LVGL_Object_Pointer, , &lv_arc_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Canvas_Class::Set_Pixel(Coordinate_Type X, Coordinate_Type Y, Color_Type Color)
{
    lv_canvas_set_px(Get_Pointer(), X, Y, Color);
}

void Canvas_Class::Set_Pixel_Color(Coordinate_Type X, Coordinate_Type Y, Color_Type Color)
{
    lv_canvas_set_px_color(Get_Pointer(), X, Y, Color);
}

void Canvas_Class::Set_Pixel_Opacity(Coordinate_Type X, Coordinate_Type Y, Opacity_Type Opacity)
{
    lv_canvas_set_px_opa(Get_Pointer(), X, Y, Opacity);
}

void Canvas_Class::Set_Palette(uint8_t Identifier, Color_Type Color)
{
    lv_canvas_set_palette(Get_Pointer(), Identifier, Color);
}

void Canvas_Class::Set_Buffer(void* Buffer, Coordinate_Type Width, Coordinate_Type Height, Image_Class::Color_Format_Type Color_Format)
{
    lv_canvas_set_buffer(Get_Pointer(), Buffer, Width, Height, Color_Format);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //

Object_Class::Color_Type Canvas_Class::Get_Pixel(Coordinate_Type X, Coordinate_Type Y)
{
    return lv_canvas_get_px(Get_Pointer(), X, Y);
}

Canvas_Class::Image_Descriptor_Type* Canvas_Class::Get_Image()
{
    return lv_canvas_get_img(Get_Pointer());
}