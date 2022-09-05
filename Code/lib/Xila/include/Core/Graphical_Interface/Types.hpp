///
/// @file Types.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 27-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Types_Hpp_Included
#define Types_Hpp_Included

#include "Arduino.h"
#include "lvgl.h"

class Types_Class
{
public:
    // - Types

    /// @brief Text font type
    typedef lv_font_t Font_Type;

    typedef lv_coord_t Coordinate_Type;

    class Alignment
    {
    public:
        /// @brief Alignment type.
        typedef lv_align_t Type;

        /// @brief Alignment enumeration.
        enum Enumeration
        {
            Default = LV_ALIGN_DEFAULT,
            Top_Left = LV_ALIGN_TOP_LEFT,
            Top_Middle = LV_ALIGN_TOP_MID,
            Top_Right = LV_ALIGN_TOP_RIGHT,
            Middle_Left = LV_ALIGN_LEFT_MID,
            Center = LV_ALIGN_CENTER,
            Middle_Right = LV_ALIGN_RIGHT_MID,
            Bottom_Left = LV_ALIGN_BOTTOM_LEFT,
            Bottom_Middle = LV_ALIGN_BOTTOM_MID,
            Bottom_Right = LV_ALIGN_BOTTOM_RIGHT,

            Out_Top_Left = LV_ALIGN_OUT_TOP_LEFT,
            Out_Top_Middle = LV_ALIGN_OUT_TOP_MID,
            Out_Top_Right = LV_ALIGN_OUT_TOP_RIGHT,
            Out_Bottom_Left = LV_ALIGN_OUT_BOTTOM_LEFT,
            Out_Bottom_Middle = LV_ALIGN_OUT_BOTTOM_MID,
            Out_Bottom_Right = LV_ALIGN_OUT_BOTTOM_RIGHT,
            Out_Left_Top = LV_ALIGN_OUT_LEFT_TOP,
            Out_Left_Middle = LV_ALIGN_OUT_LEFT_MID,
            Out_Left_Bottom = LV_ALIGN_OUT_LEFT_BOTTOM,
            Out_Right_Top = LV_ALIGN_OUT_RIGHT_TOP,
            Out_Right_Middle = LV_ALIGN_OUT_RIGHT_MID,
            Out_Right_Bottom = LV_ALIGN_OUT_RIGHT_BOTTOM,
        };
    };

    class Base_Direction
    {
    public:
        /// @brief Base direction type.
        typedef lv_base_dir_t Type;

        /// @brief Base directions enumeration.
        enum Enumeration
        {
            Left_To_Right = LV_BASE_DIR_LTR,
            Right_To_Left = LV_BASE_DIR_RTL,
            Automatic = LV_BASE_DIR_AUTO,
            Neutral = LV_BASE_DIR_NEUTRAL,
            Weak = LV_BASE_DIR_WEAK
        };
    };

    class Opacity
    {
    public:
        /// @brief Opacity type.
        typedef lv_opa_t Type;

        /// @brief Opacity presets.
        enum Enumeration
        {
            Transparent = LV_OPA_TRANSP,
            Opacity_0_Percent = LV_OPA_0,
            Opacity_10_Percent = LV_OPA_10,
            Opacity_20_Percent = LV_OPA_20,
            Opacity_30_Percent = LV_OPA_30,
            Opacity_40_Percent = LV_OPA_40,
            Opacity_50_Percent = LV_OPA_50,
            Opacity_60_Percent = LV_OPA_60,
            Opacity_70_Percent = LV_OPA_70,
            Opacity_80_Percent = LV_OPA_80,
            Opacity_90_Percent = LV_OPA_90,
            Opacity_100_Percent = LV_OPA_100,
            Cover = LV_OPA_COVER
        };
    };

    class Gradient
    {
    public:
        /// @brief Gradient descriptor type.
        typedef lv_grad_dsc_t Descriptor_Type;

        /// @brief Gradient direction type.
        typedef lv_grad_dir_t Direction_Type;

        /// @brief Gradient enumeration type.
        enum Direction_Enumeration
        {
            None = LV_GRAD_DIR_NONE,      /**< No gradient (the `grad_color` property is ignored)*/
            Vertical = LV_GRAD_DIR_VER,   /**< Vertical (top to bottom) gradient*/
            Horizontal = LV_GRAD_DIR_HOR, /**< Horizontal (left to right) gradient*/
        };

        /// @brief Gradient stop type.
        typedef lv_gradient_stop_t Stop_Type;
    };

    class Blend
    {
    public:
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

    class Grid
    {
    public:
        /// @brief Grid alignment type.
        typedef enum Alignment_Enumeration
        {
            Start = LV_GRID_ALIGN_START,
            Center = LV_GRID_ALIGN_CENTER,
            End = LV_GRID_ALIGN_END,
            Stretch = LV_GRID_ALIGN_STRETCH,
            Space_Evenly = LV_GRID_ALIGN_SPACE_EVENLY,
            Space_Around = LV_GRID_ALIGN_SPACE_AROUND,
            Space_Between = LV_GRID_ALIGN_SPACE_BETWEEN,
        } Alignment_Type;
    };

    class Flex
    {
    public:
        /// @brief Flex flow enumeration and type.
        typedef enum Flow_Enumeration
        {
            Row = LV_FLEX_FLOW_ROW,
            Column = LV_FLEX_FLOW_COLUMN,
            Wrap = LV_FLEX_FLOW_ROW_WRAP,
            Reverse = LV_FLEX_FLOW_ROW_REVERSE,
            Wrap_Reverse = LV_FLEX_FLOW_ROW_WRAP_REVERSE,
            Column_Wrap = LV_FLEX_FLOW_COLUMN_WRAP,
            Column_Reverse = LV_FLEX_FLOW_COLUMN_REVERSE,
            Column_Wrap_Reverse = LV_FLEX_FLOW_COLUMN_WRAP_REVERSE,
        } Flow_Type;

        /// @brief Flex align type.
        typedef enum Alignment_Enumeration
        {
            Start = LV_FLEX_ALIGN_START,
            End = LV_FLEX_ALIGN_END,
            Center = LV_FLEX_ALIGN_CENTER,
            Space_Evenly = LV_FLEX_ALIGN_SPACE_EVENLY,
            Space_Around = LV_FLEX_ALIGN_SPACE_AROUND,
            Space_Between = LV_FLEX_ALIGN_SPACE_BETWEEN
        } Alignment_Type;
    };

    class Border
    {
    public:
        /// @brief Border side type.
        typedef lv_border_side_t Side_Type;

        /// @brief Border side enumeration.
        enum Side_Enumeration
        {
            None = LV_BORDER_SIDE_NONE,
            Bottom = LV_BORDER_SIDE_BOTTOM,
            Top = LV_BORDER_SIDE_TOP,
            Left = LV_BORDER_SIDE_LEFT,
            Right = LV_BORDER_SIDE_RIGHT,
            Full = LV_BORDER_SIDE_FULL,
            Internal = LV_BORDER_SIDE_INTERNAL, /**< FOR matrix-like objects (e.g. Button matrix)*/
        };
    };

    class Text
    {
    public:
        /// @brief Text decor enumeration
        enum Decor_Enumeration
        {
            None = LV_TEXT_DECOR_NONE,
            Underline = LV_TEXT_DECOR_UNDERLINE,
            Strikethrough = LV_TEXT_DECOR_STRIKETHROUGH,
        };

        /// @brief Text decor type.
        typedef lv_text_decor_t Decor_Type;

        /// @brief Text alignment enumeration.
        enum Alignment_Enumeration
        {

            Automatic = LV_TEXT_ALIGN_AUTO, /**< Align text auto*/
            Left = LV_TEXT_ALIGN_LEFT,      /**< Align text to left*/
            Center = LV_TEXT_ALIGN_CENTER,  /**< Align text to center*/
            Right = LV_TEXT_ALIGN_RIGHT,    /**< Align text to right*/
        };

        /// @brief Text alignment type.
        typedef lv_text_align_t Alignment_Type;
    };

    class Dither_Mode
    {
    public:
        /// @brief Dither mode type.
        typedef lv_dither_mode_t Type;

        /// @brief Dither mode enumeration.
        enum Enumeration
        {
            None = LV_DITHER_NONE,                /**< No dithering, colors are just quantized to the output resolution*/
            Ordered = LV_DITHER_ORDERED,          /**< Ordered dithering. Faster to compute and use less memory but lower quality*/
            Error_diffusion = LV_DITHER_ERR_DIFF, /**< Error diffusion mode. Slower to compute and use more memory but give highest dither quality*/
        };
    };
};

#endif