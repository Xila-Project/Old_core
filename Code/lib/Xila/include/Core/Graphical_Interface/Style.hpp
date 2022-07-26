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
#include "Color.hpp"

class Style_Class
{
public:
    // - Types

    /// @brief Transition descriptor type.
    typedef lv_style_transition_dsc_t Transition_Descriptor_Type;

    /// @brief Style properties type.
    typedef lv_style_prop_t Property_Type;

    typedef lv_align_t Alignment_Type;

    typedef lv_opa_t Opacity::Type;

    typedef lv_coord_t Coordinate_Type;

    /// @brief Base direction type.
    typedef lv_base_dir_t Base_Direction::Type;

    /// @brief Base directions enumeration.
    enum Base_Direction_Enumeration
    {
        Left_To_Right = LV_BASE_DIR_LTR,
        Right_To_Left = LV_BASE_DIR_RTL,
        Automatic = LV_BASE_DIR_AUTO,
        Neutral = LV_BASE_DIR_NEUTRAL,
        Weak = LV_BASE_DIR_WEAK
    };

    typedef Color_Class Color_Type;

    /// @brief Dither mode type.
    typedef lv_dither_mode_t Dither_Mode_Type;

    /// @brief Dither mode enumeration.
    enum Dither_Mode_Enumeration
    {
        None = LV_DITHER_NONE,                /**< No dithering, colors are just quantized to the output resolution*/
        Ordered = LV_DITHER_ORDERED,          /**< Ordered dithering. Faster to compute and use less memory but lower quality*/
        Error_diffusion = LV_DITHER_ERR_DIFF, /**< Error diffusion mode. Slower to compute and use more memory but give highest dither quality*/
    };

    /// @brief Gradient descriptor type.
    typedef lv_grad_dsc_t Gradient_Descriptor_Type;

    /// @brief Gradient direction type.
    typedef lv_grad_dir_t Gradient::Direction_Type;

    /// @brief Gradient enumeration type.
    enum Gradient::Direction_Enumeration
    {
        None = LV_GRAD_DIR_NONE,      /**< No gradient (the `grad_color` property is ignored)*/
        Vertical = LV_GRAD_DIR_VER,   /**< Vertical (top to bottom) gradient*/
        Horizontal = LV_GRAD_DIR_HOR, /**< Horizontal (left to right) gradient*/
    };

    class Blend
    {
        /// @brief Blend mode type.
        typedef lv_blend_mode_t Mode_Type;

        /// @brief Blend mode enumeration.
        enum Mode_Enumeration
        {
            Normal = LV_BLEND_MODE_NORMAL,           /**< Simply mix according to the opacity value*/
            Additive = LV_BLEND_MODE_ADDITIVE,       /**< Add the respective color channels*/
            Subtractive = LV_BLEND_MODE_SUBTRACTIVE, /**< Subtract the foreground from the background*/
            Multiply = LV_BLEND_MODE_MULTIPLY,       /**< Multiply the foreground and background*/
            Replace = LV_BLEND_MODE_REPLACE,         /**< Replace background with foreground in the area*/
        };
    };

    /// @brief Grid alignment type.
    typedef enum Grid_Alignment_Enumeration
    {
        Start = LV_GRID_ALIGN_START,
        Center = LV_GRID_ALIGN_CENTER,
        End = LV_GRID_ALIGN_END,
        Stretch = LV_GRID_ALIGN_STRETCH,
        Space_Evenly = LV_GRID_ALIGN_SPACE_EVENLY,
        Space_Around = LV_GRID_ALIGN_SPACE_AROUND,
        Space_Between = LV_GRID_ALIGN_SPACE_BETWEEN,
    } Grid::Alignment_Type;

    /// @brief Text alignment enumeration.
    enum Text_Alignment_Enumeration
    {

        Automatic = LV_TEXT_ALIGN_AUTO, /**< Align text auto*/
        Left = LV_TEXT_ALIGN_LEFT,      /**< Align text to left*/
        Center = LV_TEXT_ALIGN_CENTER,  /**< Align text to center*/
        Right = LV_TEXT_ALIGN_RIGHT,    /**< Align text to right*/
    };

    /// @brief Text alignment type.
    typedef lv_text_align_t Text::Alignment_Type;

    /// @brief Text decor enumeration
    enum Text_Decor_Enumeration
    {
        None = LV_TEXT_DECOR_NONE,
        Underline = LV_TEXT_DECOR_UNDERLINE,
        Strikethrough = LV_TEXT_DECOR_STRIKETHROUGH,
    };

    /// @brief Text decor type.
    typedef lv_text_decor_t Text::Decor_Type;

    /// @brief Text font type
    typedef lv_font_t Font_Type;

    /// @brief Flex align type.
    typedef enum Flex_Alignment_Enumeration
    {
        Start = LV_FLEX_ALIGN_START,
        End = LV_FLEX_ALIGN_END,
        Center = LV_FLEX_ALIGN_CENTER,
        Space_Evenly = LV_FLEX_ALIGN_SPACE_EVENLY,
        Space_Around = LV_FLEX_ALIGN_SPACE_AROUND,
        Space_Between = LV_FLEX_ALIGN_SPACE_BETWEEN
    } Flex::Alignment_Type;

    /// @brief Border side type.
    typedef lv_border_side_t Border::Side_Type;

    /// @brief Border side enumeration.
    enum Border_Side_Enumeration
    {
        None = LV_BORDER_SIDE_NONE,
        Bottom = LV_BORDER_SIDE_BOTTOM,
        Top = LV_BORDER_SIDE_TOP,
        Left = LV_BORDER_SIDE_LEFT,
        Right = LV_BORDER_SIDE_RIGHT,
        Full = LV_BORDER_SIDE_FULL,
        Internal = LV_BORDER_SIDE_INTERNAL, /**< FOR matrix-like objects (e.g. Button matrix)*/
    };

    /// @brief Flex flow enumeration and type.
    typedef enum Flex_Flow_Enumeration
    {
        Row = LV_FLEX_FLOW_ROW,
        Column = LV_FLEX_FLOW_COLUMN,
        Wrap = LV_FLEX_FLOW_ROW_WRAP,
        Reverse = LV_FLEX_FLOW_ROW_REVERSE,
        Wrap_Reverse = LV_FLEX_FLOW_ROW_WRAP_REVERSE,
        Column_Wrap = LV_FLEX_FLOW_COLUMN_WRAP,
        Column_Reverse = LV_FLEX_FLOW_COLUMN_REVERSE,
        Column_Wrap_Reverse = LV_FLEX_FLOW_COLUMN_WRAP_REVERSE,
    } Flex::Flow_Type;

    // - Methods

    // - - Constructors and destructors
    Style_Class();

    // - - Management
    void Initialize();

    static Property_Type Register_Property();
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
    void Set_Background_Dither_Mode(Dither_Mode_Type Dither_Mode);
    void Set_Background_Gradient(const Gradient_Descriptor_Type *Gradient_Descriptor);
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
    void Set_Color_Filter_Descriptor(const Color_Filter_Descriptor_Type *Color_Filter_Descriptor);
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

private:
    lv_style_t LVGL_Style;
};

#endif