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

namespace Xila_Namespace
{

    enum class Alignment_Type
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
        Out_Right_Bottom = LV_ALIGN_OUT_RIGHT_BOTTOM
    };

    class Types_Class
    {
    public:
        // - Types

        /// @brief Text font type
        typedef lv_font_t Font_Type;

        typedef lv_coord_t Coordinate_Type;

        class Event
        {
        public:
            typedef enum Code_Enumeration
            {
                All = LV_EVENT_ALL,
                // -- Interaction related events
                Pressed = LV_EVENT_PRESSED,
                Pressing = LV_EVENT_PRESSING,
                Press_Lost = LV_EVENT_PRESS_LOST,

                Short_Clicked = LV_EVENT_SHORT_CLICKED,
                Long_Pressed = LV_EVENT_LONG_PRESSED,
                Long_Pressed_Repeat = LV_EVENT_LONG_PRESSED_REPEAT,

                Clicked = LV_EVENT_CLICKED,
                Released = LV_EVENT_RELEASED,
                Scroll_Begin = LV_EVENT_SCROLL_BEGIN,
                Scroll_End = LV_EVENT_SCROLL_END,
                Scroll = LV_EVENT_SCROLL,
                Gesture = LV_EVENT_GESTURE,
                Key = LV_EVENT_KEY,
                Focused = LV_EVENT_FOCUSED,
                Defocused = LV_EVENT_DEFOCUSED,
                Leave = LV_EVENT_LEAVE,
                Hit_Test = LV_EVENT_HIT_TEST,
                // -- Drawing context
                Cover_Check = LV_EVENT_COVER_CHECK,

                Extra_Draw_Size = LV_EVENT_REFR_EXT_DRAW_SIZE,
                Draw_Main_Begin = LV_EVENT_DRAW_MAIN_BEGIN,
                Draw_Main = LV_EVENT_DRAW_MAIN,
                Draw_Main_End = LV_EVENT_DRAW_MAIN_END,

                Draw_Post_Begin = LV_EVENT_DRAW_POST_BEGIN,
                Draw_Post = LV_EVENT_DRAW_POST,
                Draw_Post_End = LV_EVENT_DRAW_POST_END,
                Draw_Part_Begin = LV_EVENT_DRAW_PART_BEGIN,
                Draw_Part_End = LV_EVENT_DRAW_PART_END,

                // -- Special events
                Value_Changed = LV_EVENT_VALUE_CHANGED,
                Insert = LV_EVENT_INSERT,
                Refresh = LV_EVENT_REFRESH,
                Ready = LV_EVENT_READY,
                Cancel = LV_EVENT_CANCEL,

                // -- State events
                Delete = LV_EVENT_DELETE,
                Child_Changed = LV_EVENT_CHILD_CHANGED,
                Child_Created = LV_EVENT_CHILD_CREATED,
                Child_Deleted = LV_EVENT_CHILD_DELETED,

                // -- Screen events
                Screen_Unload_Start = LV_EVENT_SCREEN_UNLOAD_START,
                Screen_Load_Start = LV_EVENT_SCREEN_LOAD_START,
                Screen_Loaded = LV_EVENT_SCREEN_LOADED,
                Screen_Unloaded = LV_EVENT_SCREEN_UNLOADED,

                // -- Appearance events
                Size_Changed = LV_EVENT_SIZE_CHANGED,
                Style_Changed = LV_EVENT_STYLE_CHANGED,
                Layout_Changed = LV_EVENT_LAYOUT_CHANGED,
                Get_Self_Size = LV_EVENT_GET_SELF_SIZE,

                Last_Event = _LV_EVENT_LAST
            } Code_Type;
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

}

#endif