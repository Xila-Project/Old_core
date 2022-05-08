///
/// @file Canvas.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 08-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef CANVAS_HPP_INCLUDED
#define CANVAS_HPP_INCLUDED

#include "Arduino.h"

#define Class Xila_Class::Display_Class::Canvas_Class

inline void Class::Copy_Buffer(const void* Buffer_To_Copy, Coordinate_Type X, Coordinate_Type Y, uint16_t Width, uint16_t Height)
{
    lv_canvas_copy_buf(this.Get_Pointer(), Buffer_To_Copy, X, Y, Width, Height);
}

inline void Class::Transform(Image_Descriptor_Type* Image, int16_t Angle, uint16_t Zoom, Coordinate_Type Offset_X, Coordinate_Type Offset_Yn int32_t Pivot_X, int32_t Pivot_Y, bool Anti_Aliasing)
{
    lv_canvas_transform(this.Get_Pointer(), Image, Angle, Zoom, Offset_X, Offset_Y, Pivot_X, Pivot_Y, Anti_Aliasing);
}

inline void Class::Horizontal_Blur(const Area_Type* Area, uint16_t Radius)
{
    lv_canvas_blur_hor(this.Get_Pointer(), Area, Radius);
}

inline void Class::Vertical_Blur(const Area_Type* Area, uint16_t Radius)
{
    lv_canvas_blur_ver(this.Get_Pointer(), Area, Radius);
}

inline void Class::Fill_Background(Color_Type Color, Opacity_Type Opacity)
{
    lv_canvas_fill_bg(this.Get_Pointer(), Color, Opacity);
}

inline void Class::Fill_Background(Color_Type Color, Opacity_Type Opacity)
{
    lv_canvas_fill_bg_img(this.Get_Pointer(), Color, Opacity);
}

inline void Class::Draw_Rectangle(Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Width, Coordinate_Type Height, Draw_Rectangle_Descriptor_Type* Draw_Rectangle_Descriptor)
{
    lv_canvas_draw_rect(this.Get_Pointer(), X, Y, Width, Height, Draw_Rectangle_Descriptor);
}

inline void Class::Draw_Text(Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Maximum_Width, Draw_Label_Descriptor_Type* Draw_Label_Descriptor, const char* Text)
{
    lv_canvas_draw_text(this.Get_Pointer(), X, Y, Maximum_Width, Draw_Label_Descriptor, Text);
}

inline void Class::Draw_Image(Coordinate_Type X, Coordinate_Type Y, Draw_Image_Descriptor_Type* Draw_Image_Descriptor)
{
    lv_canvas_draw_img(this.Get_Pointer(), X, Y, Draw_Image_Descriptor);
}

inline void Class::Draw_Polygon(const Point_Type Points[], uint32_t Number_Of_Point, const Draw_Rectangle_Descriptor_Type* Draw_Polygon_Descriptor)
{
    lv_canvas_draw_polygon(this.Get_Pointer(), Points, Number_Of_Point, Draw_Polygon_Descriptor);
}

inline void Class::Draw_Line(const Point_Type Points[], uint32_t Number_Of_Point, const Draw_Line_Descriptor_Type* Draw_Line_Descriptor)
{
    lv_canvas_draw_line(this.Get_Pointer(), Points, Number_Of_Point, Draw_Line_Descriptor);
}

inline void Class::Draw_Arc(Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Radius, int32_t Start_Angle, int32_t End_Angle, const Draw_Arc_Descriptor* Draw_Arc_Descriptor)
{
    lv_canvas_draw_arc(this.Get_Pointer(), X, Y, Radius, Start_Angle, End_Angle, Draw_Arc_Descriptor);
}

inline void Class::Set_Pixel_Color(Coordinate_Type X, Coordinate_Type Y, Color_Type Color)
{
    lv_canvas_set_px_color(this.Get_Pointer(), X, Y, Color);
}

inline void Class::Set_Pixel_Opacity(Coordinate_Type X, Coordinate_Type Y, Opacity_Type Opacity)
{
    lv_canvas_set_px_opacity(this.Get_Pointer(), X, Y, Opacity);
}

inline void Class::Set_Palette(uint8_t Identifier, Color_Type Color)
{
    lv_canvas_set_palette(this.Get_Pointer(), Identifier, Color);
}

inline void Set_Buffer(void* Buffer, Coordinate_Type Width, COordinate_Type Height, Image_Color_Format_Type Color_Format)
{
    lv_canvas_set_buf(this.Get_Pointer(), Buffer, Width, Height, Color_Format);
}

inline Color_Type Class::Get_Pixel(Coordinate_Type X, Coordinate_Type Y)
{
    return lv_canvas_get_px_color(this.Get_Pointer(), X, Y);
}

inline Image_Descriptor_Type Class::Get_Image()
{
    return lv_canvas_get_img_desc(this.Get_Pointer());
}

#undef Class

#endif