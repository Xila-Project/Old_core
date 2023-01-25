///
/// @file Style.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 17-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Style.hpp"

using namespace Xila_Namespace;

// ------------------------------------------------------------------------- //
//
//                                  Constructor
//
// ------------------------------------------------------------------------- //

Style_Class::Style_Class()
{
    Initialize();
}

// ------------------------------------------------------------------------- //
//
//                                  Management
//
// ------------------------------------------------------------------------- //

Style_Class::Property_Type Style_Class::Register_Property(uint8_t Flag)
{
    return lv_style_register_prop(Flag);
}

bool Style_Class::Remove_Property(Property_Type Property)
{
    return lv_style_remove_prop(&LVGL_Style, Property);
}

void Style_Class::Reset()
{
    lv_style_reset(&LVGL_Style);
}


lv_style_t* Style_Class::Get_Pointer()
{
    return &LVGL_Style;
}

// ------------------------------------------------------------------------- //
//
//                                    Setters
//
// ------------------------------------------------------------------------- //

void Style_Class::Initialize()
{
    lv_style_init(&LVGL_Style);
}

void Style_Class::Set_Alignment(Alignment_Type Alignment)
{
    lv_style_set_align(&LVGL_Style, (lv_align_t)Alignment);
}

void Style_Class::Set_Animation_Time(uint32_t Time)
{
    lv_style_set_anim_time(&LVGL_Style, Time);
}

void Style_Class::Set_Animation_Speed(uint32_t Speed)
{
    lv_style_set_anim_speed(&LVGL_Style, Speed);
}

void Style_Class::Set_Arc_Color(Color_Type Color)
{
    lv_style_set_arc_color(&LVGL_Style, Color.Get_LVGL_Color());
}

void Style_Class::Set_Arc_Image_Source(const void* Image_Source)
{
    lv_style_set_arc_img_src(&LVGL_Style, Image_Source);
}

void Style_Class::Set_Arc_Opacity(Opacity_Type Opacity)
{
    lv_style_set_arc_opa(&LVGL_Style, static_cast<lv_opa_t>(Opacity));
}

void Style_Class::Set_Arc_Rounded(bool Rounded)
{
    lv_style_set_arc_rounded(&LVGL_Style, Rounded);
}

void Style_Class::Set_Arc_Width(Coordinate_Type Width)
{
    lv_style_set_arc_width(&LVGL_Style, Width);
}

void Style_Class::Set_Base_Direction(Base_Direction::Type Base_Direction)
{
    lv_style_set_base_dir(&LVGL_Style, Base_Direction);
}

void Style_Class::Set_Background_Color(Color_Type Color)
{
    lv_style_set_bg_color(&LVGL_Style, Color.Get_LVGL_Color());
}

void Style_Class::Set_Background_Dither_Mode(Dither_Mode::Type Dither_Mode)
{
    lv_style_set_bg_dither_mode(&LVGL_Style, Dither_Mode);
}

void Style_Class::Set_Background_Gradient(const Gradient::Descriptor_Type* Gradient_Descriptor)
{
    lv_style_set_bg_grad(&LVGL_Style, Gradient_Descriptor);
}

void Style_Class::Set_Background_Gradient_Color(Color_Type Color)
{
    lv_style_set_bg_grad_color(&LVGL_Style, Color.Get_LVGL_Color());
}

void Style_Class::Set_Background_Gradient_Direction(Gradient::Direction_Type Gradient_Direction)
{
    lv_style_set_bg_grad_dir(&LVGL_Style, Gradient_Direction);
}

void Style_Class::Set_Background_Gradient_Stop(Coordinate_Type Value)
{
    lv_style_set_bg_grad_stop(&LVGL_Style, Value);
}

void Style_Class::Set_Background_Image_Opacity(Opacity_Type Opacity)
{
    lv_style_set_bg_img_opa(&LVGL_Style, static_cast<lv_opa_t>(Opacity));
}

void Style_Class::Set_Background_Image_Recolor(Color_Type Recolor)
{
    lv_style_set_bg_img_recolor(&LVGL_Style, Recolor.Get_LVGL_Color());
}

void Style_Class::Set_Background_Image_Recolor_Opacity(Opacity_Type Opacity)
{
    lv_style_set_bg_img_recolor_opa(&LVGL_Style, static_cast<lv_opa_t>(Opacity));
}

void Style_Class::Set_Background_Image_Source(const void* Image_Source)
{
    lv_style_set_bg_img_src(&LVGL_Style, Image_Source);
}

void Style_Class::Set_Background_Image_Tiled(bool Tiled)
{
    lv_style_set_bg_img_tiled(&LVGL_Style, Tiled);
}

void Style_Class::Set_Background_Main_Stop(Coordinate_Type Value)
{
    lv_style_set_bg_main_stop(&LVGL_Style, Value);
}

void Style_Class::Set_Background_Opacity(Opacity_Type Opacity)
{
    lv_style_set_bg_opa(&LVGL_Style, static_cast<lv_opa_t>(Opacity));
}

void Style_Class::Set_Blend_Mode(Blend::Mode_Type Blend_Mode)
{
    lv_style_set_blend_mode(&LVGL_Style, Blend_Mode);
}

void Style_Class::Set_Border_Color(Color_Type Color)
{
    lv_style_set_border_color(&LVGL_Style, Color.Get_LVGL_Color());
}

void Style_Class::Set_Border_Opacity(Opacity_Type Opacity)
{
    lv_style_set_border_opa(&LVGL_Style, static_cast<lv_opa_t>(Opacity));
}

void Style_Class::Set_Border_Post(bool Value)
{
    lv_style_set_border_post(&LVGL_Style, Value);
}

void Style_Class::Set_Border_Side(Border_Side_Type Border_Side)
{
    lv_style_set_border_side(&LVGL_Style, static_cast<lv_border_side_t>(Border_Side));
}

void Style_Class::Set_Border_Width(Coordinate_Type Width)
{
    lv_style_set_border_width(&LVGL_Style, Width);
}

void Style_Class::Set_Clip_Corner(bool Value)
{
    lv_style_set_clip_corner(&LVGL_Style, Value);
}

void Style_Class::Set_Color_Filter_Descriptor(Color_Filter_Descriptor_Class& Color_Filter_Descriptor)
{
    lv_style_set_color_filter_dsc(&LVGL_Style, Color_Filter_Descriptor.Get_Pointer());
}

void Style_Class::Set_Color_Filter_Opacity(Opacity_Type Opacity)
{
    lv_style_set_color_filter_opa(&LVGL_Style, static_cast<lv_opa_t>(Opacity));
}

void Style_Class::Set_Flex_Cross_Place(Flex_Alignment_Type Cross_Place)
{
    lv_style_set_flex_cross_place(&LVGL_Style, (lv_flex_align_t)Cross_Place);
}

void Style_Class::Set_Flex_Flow(Flex_Flow_Type Flow)
{
    lv_style_set_flex_flow(&LVGL_Style, (lv_flex_flow_t)Flow);
}

void Style_Class::Set_Flex_Grow(uint8_t Value)
{
    lv_style_set_flex_grow(&LVGL_Style, Value);
}

void Style_Class::Set_Flex_Main_Place(Flex_Alignment_Type Main_Place)
{
    lv_style_set_flex_main_place(&LVGL_Style, (lv_flex_align_t)Main_Place);
}

void Style_Class::Set_Flex_Track_Place(Flex_Alignment_Type Track_Place)
{
    lv_style_set_flex_track_place(&LVGL_Style, (lv_flex_align_t)Track_Place);
}

void Style_Class::Set_Grid_Cell_Column_Position(Coordinate_Type Column_Position)
{
    lv_style_set_grid_cell_column_pos(&LVGL_Style, Column_Position);
}

void Style_Class::Set_Grid_Cell_Column_Span(Coordinate_Type Column_Span)
{
    lv_style_set_grid_cell_column_span(&LVGL_Style, Column_Span);
}

void Style_Class::Set_Grid_Cell_Row_Position(Coordinate_Type Row_Position)
{
    lv_style_set_grid_cell_row_pos(&LVGL_Style, Row_Position);
}

void Style_Class::Set_Grid_Cell_Row_Span(Coordinate_Type Row_Span)
{
    lv_style_set_grid_cell_row_span(&LVGL_Style, Row_Span);
}

void Style_Class::Set_Grid_Cell_X_Alignment(Coordinate_Type X_Alignment)
{
    lv_style_set_grid_cell_x_align(&LVGL_Style, X_Alignment);
}

void Style_Class::Set_Grid_Cell_Y_Alignment(Coordinate_Type Y_Alignment)
{
    lv_style_set_grid_cell_y_align(&LVGL_Style, Y_Alignment);
}

void Style_Class::Set_Grid_Column_Alignment(Grid_Alignment_Type Column_Alignment)
{
    lv_style_set_grid_column_align(&LVGL_Style, (lv_grid_align_t)Column_Alignment);
}

void Style_Class::Set_Grid_Column_Descriptor_Array(const Coordinate_Type* Column_Descriptor_Array)
{
    lv_style_set_grid_column_dsc_array(&LVGL_Style, Column_Descriptor_Array);
}

void Style_Class::Set_Grid_Row_Alignment(Grid_Alignment_Type Row_Alignment)
{
    lv_style_set_grid_row_align(&LVGL_Style, (lv_grid_align_t)Row_Alignment);
}

void Style_Class::Set_Grid_Row_Descriptor_Array(const Coordinate_Type* Row_Descriptor_Array)
{
    lv_style_set_grid_row_dsc_array(&LVGL_Style, Row_Descriptor_Array);
}

void Style_Class::Set_Height(Coordinate_Type Height)
{
    lv_style_set_height(&LVGL_Style, Height);
}

void Style_Class::Set_Image_Opacity(Opacity_Type Opacity)
{
    lv_style_set_img_opa(&LVGL_Style, static_cast<lv_opa_t>(Opacity));
}

void Style_Class::Set_Image_Recolor(Color_Type Color)
{
    lv_style_set_img_recolor(&LVGL_Style, Color.Get_LVGL_Color());
}

void Style_Class::Set_Image_Recolor_Opacity(Opacity_Type Opacity)
{
    lv_style_set_img_recolor_opa(&LVGL_Style, static_cast<lv_opa_t>(Opacity));
}

void Style_Class::Set_Layout(uint16_t Value)
{
    lv_style_set_layout(&LVGL_Style, Value);
}

void Style_Class::Set_Line_Color(Color_Type Color)
{
    lv_style_set_line_color(&LVGL_Style, Color.Get_LVGL_Color());
}

void Style_Class::Set_Line_Dash_Gap(Coordinate_Type Dash_Gap)
{
    lv_style_set_line_dash_gap(&LVGL_Style, Dash_Gap);
}

void Style_Class::Set_Line_Dash_Width(Coordinate_Type Dash_Width)
{
    lv_style_set_line_dash_width(&LVGL_Style, Dash_Width);
}

void Style_Class::Set_Line_Opacity(Opacity_Type Opacity)
{
    lv_style_set_line_opa(&LVGL_Style, static_cast<lv_opa_t>(Opacity));
}

void Style_Class::Set_Line_Rounded(bool Rounded)
{
    lv_style_set_line_rounded(&LVGL_Style, Rounded);
}

void Style_Class::Set_Line_Width(Coordinate_Type Width)
{
    lv_style_set_line_width(&LVGL_Style, Width);
}

void Style_Class::Set_Maximum_Height(Coordinate_Type Maximum_Height)
{
    lv_style_set_max_height(&LVGL_Style, Maximum_Height);
}

void Style_Class::Set_Maximum_Width(Coordinate_Type Maximum_Width)
{
    lv_style_set_max_width(&LVGL_Style, Maximum_Width);
}

void Style_Class::Set_Minimum_Height(Coordinate_Type Minimum_Height)
{
    lv_style_set_min_height(&LVGL_Style, Minimum_Height);
}

void Style_Class::Set_Minimum_Width(Coordinate_Type Minimum_Width)
{
    lv_style_set_min_width(&LVGL_Style, Minimum_Width);
}

void Style_Class::Set_Opacity(Opacity_Type Opacity)
{
    lv_style_set_opa(&LVGL_Style, static_cast<lv_opa_t>(Opacity));
}

void Style_Class::Set_Outline_Color(Color_Type Color)
{
    lv_style_set_outline_color(&LVGL_Style, Color.Get_LVGL_Color());
}

void Style_Class::Set_Outline_Opacity(Opacity_Type Opacity)
{
    lv_style_set_outline_opa(&LVGL_Style, static_cast<lv_opa_t>(Opacity));
}

void Style_Class::Set_Outline_Pad(Coordinate_Type Pad)
{
    lv_style_set_outline_pad(&LVGL_Style, Pad);
}

void Style_Class::Set_Outline_Width(Coordinate_Type Width)
{
    lv_style_set_outline_width(&LVGL_Style, Width);
}

void Style_Class::Set_Pad_All(Coordinate_Type Pad)
{
    lv_style_set_pad_all(&LVGL_Style, Pad);
}

void Style_Class::Set_Pad_Bottom(Coordinate_Type Pad_Bottom)
{
    lv_style_set_pad_bottom(&LVGL_Style, Pad_Bottom);
}

void Style_Class::Set_Pad_Left(Coordinate_Type Pad_Left)
{
    lv_style_set_pad_left(&LVGL_Style, Pad_Left);
}

void Style_Class::Set_Pad_Right(Coordinate_Type Pad_Right)
{
    lv_style_set_pad_right(&LVGL_Style, Pad_Right);
}

void Style_Class::Set_Pad_Top(Coordinate_Type Pad_Top)
{
    lv_style_set_pad_top(&LVGL_Style, Pad_Top);
}

void Style_Class::Set_Pad_Row(Coordinate_Type Pad_Row)
{
    lv_style_set_pad_row(&LVGL_Style, Pad_Row);
}

void Style_Class::Set_Pad_Column(Coordinate_Type Pad_Column)
{
    lv_style_set_pad_column(&LVGL_Style, Pad_Column);
}

void Style_Class::Set_Pad_Gap(Coordinate_Type Pad_Gap)
{
    lv_style_set_pad_gap(&LVGL_Style, Pad_Gap);
}

void Style_Class::Set_Pad_Horizontal(Coordinate_Type Pad_Horizontal)
{
    lv_style_set_pad_hor(&LVGL_Style, Pad_Horizontal);
}

void Style_Class::Set_Pad_Vertical(Coordinate_Type Pad_Vertical)
{
    lv_style_set_pad_ver(&LVGL_Style, Pad_Vertical);
}

void Style_Class::Set_Radius(Coordinate_Type Radius)
{
    lv_style_set_radius(&LVGL_Style, Radius);
}

void Style_Class::Set_Shadow_Color(Color_Type Color)
{
    lv_style_set_shadow_color(&LVGL_Style, Color.Get_LVGL_Color());
}

void Style_Class::Set_Shadow_Offset_X(Coordinate_Type Offset_X)
{
    lv_style_set_shadow_ofs_x(&LVGL_Style, Offset_X);
}

void Style_Class::Set_Shadow_Offset_Y(Coordinate_Type Offset_Y)
{
    lv_style_set_shadow_ofs_y(&LVGL_Style, Offset_Y);
}

void Style_Class::Set_Shadow_Opacity(Opacity_Type Opacity)
{
    lv_style_set_shadow_opa(&LVGL_Style, static_cast<lv_opa_t>(Opacity));
}

void Style_Class::Set_Shadow_Spread(Coordinate_Type Spread)
{
    lv_style_set_shadow_spread(&LVGL_Style, Spread);
}

void Style_Class::Set_Shadow_Width(Coordinate_Type Width)
{
    lv_style_set_shadow_width(&LVGL_Style, Width);
}

void Style_Class::Set_Size(Coordinate_Type Value)
{
    lv_style_set_size(&LVGL_Style, Value);
}

void Style_Class::Set_Text_Alignment(Text::Alignment_Type Text_Alignment)
{
    lv_style_set_text_align(&LVGL_Style, Text_Alignment);
}

void Style_Class::Set_Text_Color(Color_Type Color)
{
    lv_style_set_text_color(&LVGL_Style, Color.Get_LVGL_Color());
}

void Style_Class::Set_Text_Decor(Text::Decor_Type Text_Decor)
{
    lv_style_set_text_decor(&LVGL_Style, Text_Decor);
}

void Style_Class::Set_Text_Font(Font_Type* Font)
{
    lv_style_set_text_font(&LVGL_Style, Font);
}

void Style_Class::Set_Text_Letter_Space(Coordinate_Type Letter_Space)
{
    lv_style_set_text_letter_space(&LVGL_Style, Letter_Space);
}

void Style_Class::Set_Text_Line_Space(Coordinate_Type Line_Space)
{
    lv_style_set_text_line_space(&LVGL_Style, Line_Space);
}

void Style_Class::Set_Text_Opacity(Opacity_Type Opacity)
{
    lv_style_set_text_opa(&LVGL_Style, static_cast<lv_opa_t>(Opacity));
}

void Style_Class::Set_Transform_Angle(Coordinate_Type Angle)
{
    lv_style_set_transform_angle(&LVGL_Style, Angle);
}

void Style_Class::Set_Transform_Height(Coordinate_Type Height)
{
    lv_style_set_transform_height(&LVGL_Style, Height);
}

void Style_Class::Set_Transform_Width(Coordinate_Type Width)
{
    lv_style_set_transform_width(&LVGL_Style, Width);
}

void Style_Class::Set_Transform_Zoom(Coordinate_Type Zoom)
{
    lv_style_set_transform_zoom(&LVGL_Style, Zoom);
}

void Style_Class::Set_Transition(const Style_Class::Transition_Descriptor_Type* Transition_Descriptor)
{
    lv_style_set_transition(&LVGL_Style, Transition_Descriptor);
}

void Style_Class::Set_Translate_X(Coordinate_Type Translate_X)
{
    lv_style_set_translate_x(&LVGL_Style, Translate_X);
}

void Style_Class::Set_Translate_Y(Coordinate_Type Translate_Y)
{
    lv_style_set_translate_y(&LVGL_Style, Translate_Y);
}

void Style_Class::Set_Width(Coordinate_Type Width)
{
    lv_style_set_width(&LVGL_Style, Width);
}

void Style_Class::Set_X(Coordinate_Type X)
{
    lv_style_set_x(&LVGL_Style, X);
}

void Style_Class::Set_Y(Coordinate_Type Y)
{
    lv_style_set_y(&LVGL_Style, Y);
}

// ------------------------------------------------------------------------- //
//
//                                    Getters
//
// ------------------------------------------------------------------------- //