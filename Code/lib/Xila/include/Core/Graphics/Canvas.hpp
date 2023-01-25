///
/// @file Canvas.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 08-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Canvas_Hpp_Included
#define Canvas_Hpp_Included

#include "Object.hpp"
#include "Image.hpp"

namespace Xila_Namespace
{
    typedef class Canvas_Class : public Object_Class
    {
    public:
        // - Types

        typedef lv_draw_label_dsc_t Draw_Label_Descriptor_Type;
        typedef lv_draw_arc_dsc_t Draw_Arc_Descriptor_Type;
        typedef lv_draw_img_dsc_t Draw_Image_Descriptor_Type;
        typedef lv_draw_line_dsc_t Draw_Line_Descriptor_Type;
        typedef lv_draw_rect_dsc_t Draw_Rectangle_Descriptor_Type;

        typedef lv_img_dsc_t Image_Descriptor_Type;

        // - Methods

        void Create(Object_Class Parent_Object);

        // - Management

        void Copy_Buffer(const void *Buffer_To_Copy, Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Width, Coordinate_Type Height);

        void Transform(Image_Descriptor_Type *Image, int16_t Angle, uint16_t Zoom, Coordinate_Type Offset_X, Coordinate_Type Offset_Y, int32_t Pivot_X, int32_t Pivot_Y, bool Anti_Aliasing);
        void Horizontal_Blur(const Area_Type &Area, uint16_t Radius);
        void Vertical_Blur(const Area_Type &Area, uint16_t Radius);
        void Fill_Background(Color_Type Color, Opacity_Type Opacity);

        void Draw_Rectangle(Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Width, Coordinate_Type Height, const Draw_Rectangle_Descriptor_Type *Draw_Rectangle_Descriptor);
        void Draw_Text(Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Maximum_Width, Draw_Label_Descriptor_Type *Draw_Label_Descriptor, const char *Text);
        void Draw_Image(Coordinate_Type X, Coordinate_Type Y, const void *Source, const Draw_Image_Descriptor_Type *Draw_Image_Descriptor);
        void Draw_Line(const Point_Type Points[], uint32_t Number_Of_Point, const Draw_Line_Descriptor_Type *Draw_Line_Descriptor);
        void Draw_Polygon(const Point_Type Points[], uint32_t Number_Of_Point, const Draw_Rectangle_Descriptor_Type *Draw_Polygon_Descriptor);
        void Draw_Arc(Coordinate_Type X, Coordinate_Type Y, Coordinate_Type Radius, int32_t Start_Angle, int32_t End_Angle, const Draw_Arc_Descriptor_Type *Draw_Arc_Descriptor);

        // - - Setters

        bool Set_Pointer(lv_obj_t *Pointer);

        void Set_Pixel(Coordinate_Type X, Coordinate_Type Y, Color_Type Color);
        void Set_Pixel_Color(Coordinate_Type X, Coordinate_Type Y, Color_Type Color);
        void Set_Pixel_Opacity(Coordinate_Type X, Coordinate_Type Y, Opacity_Type Opacity);
        void Set_Palette(uint8_t Identifier, Color_Type Color);
        void Set_Buffer(void *Buffer, Coordinate_Type Width, Coordinate_Type Height, Image_Class::Color_Format_Type Color_Format);

        // - - Getters

        Color_Type Get_Pixel(Coordinate_Type X, Coordinate_Type Y);
        Image_Descriptor_Type *Get_Image();
    } Canvas_Type;
}

#endif