///
/// @file Style.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 16-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Style_Hpp_Included
#define Style_Hpp_Included

#include "lvgl.h"
#include "Arduino.h"
#include "Animation.hpp"

#include "Types.hpp"
#include "Color.hpp"

namespace Xila_Namespace
{
    typedef class Style_Class : public Types_Class
    {
    public:
        // - Types

        typedef Color_Filter_Descriptor_Class Color_Filter_Descriptor_Type;

        typedef Color_Class Color_Type;

        /// @brief Transition descriptor type.
        typedef lv_style_transition_dsc_t Transition_Descriptor_Type;

        /// @brief Style properties type.
        typedef lv_style_prop_t Property_Type;

        // - Methods

        // - - Constructors and destructors
        Style_Class();

        // - - Management
        void Initialize();

        static Property_Type Register_Property(uint8_t FLag);
        bool Remove_Property(Property_Type Property);
        void Reset();

        // - - Setters
        void Set_Alignment(Alignment_Type Alignment);

        // - - - Animation
        void Set_Animation_Time(uint32_t Time);
        void Set_Animation_Speed(uint32_t Speed);

        // - - - Arc
        void Set_Arc_Color(Color_Type Color);
        void Set_Arc_Image_Source(const void *Image_Source);
        void Set_Arc_Opacity(Opacity::Type Opacity);
        void Set_Arc_Rounded(bool Rounded);
        void Set_Arc_Width(Coordinate_Type Width);

        void Set_Base_Direction(Base_Direction::Type Base_Direction);

        // - - - Background
        void Set_Background_Color(Color_Type Color);
        void Set_Background_Dither_Mode(Dither_Mode::Type Dither_Mode);
        void Set_Background_Gradient(const Gradient::Descriptor_Type *Gradient_Descriptor);
        void Set_Background_Gradient_Color(Color_Type Color);
        void Set_Background_Gradient_Direction(Gradient::Direction_Type Gradient_Direction);
        void Set_Background_Gradient_Stop(Coordinate_Type Value);
        void Set_Background_Image_Opacity(Opacity::Type Opacity);
        void Set_Background_Image_Recolor(Color_Type Color);
        void Set_Background_Image_Recolor_Opacity(Opacity::Type Opacity);
        void Set_Background_Image_Source(const void *Image_Source);
        void Set_Background_Image_Tiled(bool Tiled);
        void Set_Background_Main_Stop(Coordinate_Type Value);
        void Set_Background_Opacity(Opacity::Type Opacity);

        void Set_Blend_Mode(Blend::Mode_Type Blend_Mode);

        // - - - - Border
        void Set_Border_Color(Color_Type Color);
        void Set_Border_Opacity(Opacity::Type Opacity);
        void Set_Border_Post(bool Value);
        void Set_Border_Side(Border::Side_Type Border_Side);
        void Set_Border_Width(Coordinate_Type Width);

        void Set_Clip_Corner(bool Value);

        // - - - - Color filter
        void Set_Color_Filter_Descriptor(Color_Filter_Descriptor_Type &Color_Filter_Descriptor);
        void Set_Color_Filter_Opacity(Opacity::Type Opacity);

        // - - - - Flex
        void Set_Flex_Cross_Place(Flex::Alignment_Type Cross_Place);
        void Set_Flex_Flow(Flex::Flow_Type Flow);
        void Set_Flex_Grow(uint8_t Value);
        void Set_Flex_Main_Place(Flex::Alignment_Type Main_Place);
        void Set_Flex_Track_Place(Flex::Alignment_Type Track_Place);

        // - - - - Grid
        void Set_Grid_Cell_Column_Position(Coordinate_Type Column_Position);
        void Set_Grid_Cell_Column_Span(Coordinate_Type Column_Span);
        void Set_Grid_Cell_Row_Position(Coordinate_Type Row_Position);
        void Set_Grid_Cell_Row_Span(Coordinate_Type Row_Span);
        void Set_Grid_Cell_X_Alignment(Coordinate_Type X_Alignment);
        void Set_Grid_Cell_Y_Alignment(Coordinate_Type Y_Alignment);
        void Set_Grid_Column_Alignment(Grid::Alignment_Type Column_Alignment);
        void Set_Grid_Column_Descriptor_Array(const Coordinate_Type *Column_Descriptor_Array);
        void Set_Grid_Row_Alignment(Grid::Alignment_Type Row_Alignment);
        void Set_Grid_Row_Descriptor_Array(const Coordinate_Type *Row_Descriptor_Array);

        void Set_Height(Coordinate_Type Height);

        // - - - - Image
        void Set_Image_Opacity(Opacity::Type Opacity);
        void Set_Image_Recolor(Color_Type Color);
        void Set_Image_Recolor_Opacity(Opacity::Type Opacity);

        void Set_Layout(uint16_t Value);

        // - - - - Line
        void Set_Line_Color(Color_Type Color);
        void Set_Line_Dash_Gap(Coordinate_Type Dash_Gap);
        void Set_Line_Dash_Width(Coordinate_Type Dash_Width);
        void Set_Line_Opacity(Opacity::Type Opacity);
        void Set_Line_Rounded(bool Rounded);
        void Set_Line_Width(Coordinate_Type Width);

        void Set_Maximum_Height(Coordinate_Type Maximum_Height);
        void Set_Maximum_Width(Coordinate_Type Maximum_Width);
        void Set_Minimum_Height(Coordinate_Type Minimum_Height);
        void Set_Minimum_Width(Coordinate_Type Minimum_Width);
        void Set_Opacity(Opacity::Type Opacity);

        // - - - - Outline
        void Set_Outline_Color(Color_Type Color);
        void Set_Outline_Opacity(Opacity::Type Opacity);
        void Set_Outline_Pad(Coordinate_Type Pad);
        void Set_Outline_Width(Coordinate_Type Width);

        // - - - - Pad
        void Set_Pad_All(Coordinate_Type Pad);
        void Set_Pad_Bottom(Coordinate_Type Pad_Bottom);
        void Set_Pad_Left(Coordinate_Type Pad_Left);
        void Set_Pad_Right(Coordinate_Type Pad_Right);
        void Set_Pad_Top(Coordinate_Type Pad_Top);
        void Set_Pad_Row(Coordinate_Type Pad_Row);
        void Set_Pad_Column(Coordinate_Type Pad_Column);
        void Set_Pad_Gap(Coordinate_Type Pad_Gap);
        void Set_Pad_Horizontal(Coordinate_Type Pad_Horizontal);
        void Set_Pad_Vertical(Coordinate_Type Pad_Vertical);

        void Set_Radius(Coordinate_Type Radius);

        // - - - - Shadow
        void Set_Shadow_Color(Color_Type Color);
        void Set_Shadow_Offset_X(Coordinate_Type Offset_X);
        void Set_Shadow_Offset_Y(Coordinate_Type Offset_Y);
        void Set_Shadow_Opacity(Opacity::Type Opacity);
        void Set_Shadow_Spread(Coordinate_Type Spread);
        void Set_Shadow_Width(Coordinate_Type Width);

        void Set_Size(Coordinate_Type Value);

        // - - - - Text
        void Set_Text_Alignment(Text::Alignment_Type Alignment);
        void Set_Text_Color(Color_Type Color);
        void Set_Text_Decor(Text::Decor_Type Decor);
        void Set_Text_Font(Font_Type *Font);
        void Set_Text_Letter_Space(Coordinate_Type Letter_Space);
        void Set_Text_Line_Space(Coordinate_Type Line_Space);
        void Set_Text_Opacity(Opacity::Type Opacity);

        // - - - - Transform
        void Set_Transform_Angle(Coordinate_Type Angle);
        void Set_Transform_Height(Coordinate_Type Height);
        void Set_Transform_Width(Coordinate_Type Width);
        void Set_Transform_Zoom(Coordinate_Type Zoom);

        void Set_Transition(const Style_Class::Transition_Descriptor_Type *Transition_Descriptor);

        void Set_Translate_X(Coordinate_Type Translate_X);
        void Set_Translate_Y(Coordinate_Type Translate_Y);

        void Set_Width(Coordinate_Type Width);

        void Set_X(Coordinate_Type Style_X);
        void Set_Y(Coordinate_Type Style_Y);

        // - - Getters

        lv_style_t *Get_Pointer();

    private:
        lv_style_t LVGL_Style;
    } Style_Type;
}

#endif