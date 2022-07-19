///
/// @file Object.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1
/// @date 04-05-2022
///
/// @copyright Copyright (c) 2022
///

#include "Arduino.h"

#include "lvgl.h"

#include "Area.hpp"
#include "Animation.hpp"
#include "Style.hpp"
#include "Color.hpp"
#include "Event.hpp"

#ifndef Object_Hpp_Included
#define Object_Hpp_Included

#define Class Xila_Class::Display_Class::Object_Class // Shortcut

#define Percentage(x) LV_PCT(x)

/// @brief Object class.
class Object_Class
{
public:
    // - Types

    typedef enum Event_Code_Enumeration
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
    } Event_Code_Type;

    /// @brief Animation type.
    typedef Animation_Class Animation_Type;

    /// @brief Text font type
    typedef lv_font_t Font_Type;

    /// @brief Text decor enumeration
    enum Text_Decor_Enumeration
    {
        None = LV_TEXT_DECOR_NONE,
        Underline = LV_TEXT_DECOR_UNDERLINE,
        Strikethrough = LV_TEXT_DECOR_STRIKETHROUGH,
    };

    /// @brief Text decor type.
    typedef lv_text_decor_t Text_Decor_Type;

    /// @brief Text alignment enumeration.
    enum Text_Alignment_Enumeration
    {

        Automatic = LV_TEXT_ALIGN_AUTO, /**< Align text auto*/
        Left = LV_TEXT_ALIGN_LEFT,      /**< Align text to left*/
        Center = LV_TEXT_ALIGN_CENTER,  /**< Align text to center*/
        Right = LV_TEXT_ALIGN_RIGHT,    /**< Align text to right*/
    };

    /// @brief Text alignment type.
    typedef lv_text_align_t Text_Alignment_Type;

    /// @brief Point type.
    typedef lv_point_t Point_Type;

    /// @brief Area type.
    typedef Area_Class Area_Type;

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
    } Grid_Alignment_Type;

    /// @brief Style type.
    typedef lv_style_t Style_Type;

    /// @brief Style selector type.
    typedef lv_style_selector_t Style_Selector_Type;

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
    } Flex_Flow_Type;

    /// @brief Flex align type.
    typedef enum Flex_Alignment_Enumeration
    {
        Start = LV_FLEX_ALIGN_START,
        End = LV_FLEX_ALIGN_END,
        Center = LV_FLEX_ALIGN_CENTER,
        Space_Evenly = LV_FLEX_ALIGN_SPACE_EVENLY,
        Space_Around = LV_FLEX_ALIGN_SPACE_AROUND,
        Space_Between = LV_FLEX_ALIGN_SPACE_BETWEEN
    } Flex_Alignment_Type;

    /// @brief Color filter descriptor type.
    typedef lv_color_filter_dsc_t Color_Filter_Descriptor_Type;

    /// @brief Border side type.
    typedef lv_border_side_t Border_Side_Type;

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

    /// @brief Blend mode type.
    typedef lv_blend_mode_t Blend_Mode_Type;

    /// @brief Blend mode enumeration.
    enum Blend_Mode_Enumeration
    {
        Normal = LV_BLEND_MODE_NORMAL,           /**< Simply mix according to the opacity value*/
        Additive = LV_BLEND_MODE_ADDITIVE,       /**< Add the respective color channels*/
        Subtractive = LV_BLEND_MODE_SUBTRACTIVE, /**< Subtract the foreground from the background*/
        Multiply = LV_BLEND_MODE_MULTIPLY,       /**< Multiply the foreground and background*/
        Replace = LV_BLEND_MODE_REPLACE,         /**< Replace background with foreground in the area*/
    };

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
    typedef lv_grad_dir_t Gradient_Direction_Type;

    /// @brief Gradient stop type.
    typedef lv_gradient_stop_t Gradient_Stop_Type;

    /// @brief Gradient enumeration type.
    enum Gradient_Direction_Enumeration
    {
        None = LV_GRAD_DIR_NONE,      /**< No gradient (the `grad_color` property is ignored)*/
        Vertical = LV_GRAD_DIR_VER,   /**< Vertical (top to bottom) gradient*/
        Horizontal = LV_GRAD_DIR_HOR, /**< Horizontal (left to right) gradient*/
    };

    /// @brief Base direction type.
    typedef lv_base_dir_t Base_Direction_Type;

    /// @brief Base directions enumeration.
    enum Base_Direction_Enumeration
    {
        Left_To_Right = LV_BASE_DIR_LTR,
        Right_To_Left = LV_BASE_DIR_RTL,
        Automatic = LV_BASE_DIR_AUTO,
        Neutral = LV_BASE_DIR_NEUTRAL,
        Weak = LV_BASE_DIR_WEAK
    };

    /// @brief Color type.
    typedef Color_Class Color_Type;

    /// @brief Alignment type.
    typedef lv_align_t Alignment_Type;

    /// @brief Alignment enumeration.
    enum Alignment_Enumeration
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

    // -- Types and enumerations

    typedef lv_coord_t Coordinate_Type;

    /// @brief Opacity type.
    typedef lv_opa_t Opacity_Type;

    /// @brief Opacity presets.
    enum Opacity_Enumeration
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

    typedef lv_state_t State_Type;

    /// @brief Possible states of a widget. ORed values are possible.
    enum State_Enumeration
    {
        Default = LV_STATE_DEFAULT,
        Checked = LV_STATE_CHECKED,
        Focused = LV_STATE_FOCUSED,
        Focus_Key = LV_STATE_FOCUS_KEY,
        Edited = LV_STATE_EDITED,
        Hovered = LV_STATE_HOVERED,
        Pressed = LV_STATE_PRESSED,
        Scrolled = LV_STATE_SCROLLED,
        Disabled = LV_STATE_DISABLED,
        Custom_1 = LV_STATE_USER_1,
        Custom_2 = LV_STATE_USER_2,
        Custom_3 = LV_STATE_USER_3,
        Custom_4 = LV_STATE_USER_4,
        Any = LV_STATE_ANY
    };

    typedef lv_part_t Part_Type;

    /// @brief Part enumeration.
    enum Part_Enumeration
    {
        Main = LV_PART_MAIN,                        /// < Main part of the object.
        Scrollbar = LV_PART_SCROLLBAR,              /// < Scrollbar part.
        Indicator = LV_PART_INDICATOR,              /// < Indicator part of a scrollbar.
        Knob = LV_PART_KNOB,                        /// < Knob of a scrollbar
        Selected = LV_PART_SELECTED,                /// < The part of a list is selected.
        Items = LV_PART_ITEMS,                      /// < The part of the list where the items are drawn.
        Ticks = LV_PART_TICKS,                      /// < Ticks of a gauge
        Cursor = LV_PART_CURSOR,                    /// < Cursor of a slider
        Custom_First = LV_PART_CUSTOM_FIRST,        /// < First custom part
        Placeholder = LV_PART_TEXTAREA_PLACEHOLDER, /// < (only for text area objects).
        Any = LV_PART_ANY                           /// < Any part of the object.
    };

    typedef lv_obj_flag_t Flag_Type;

    /// @brief Flag enumeration.
    enum Flag_Enumeration
    {
        Hidden = LV_OBJ_FLAG_HIDDEN,
        Clickable = LV_OBJ_FLAG_CLICKABLE,
        Click_Focusable = LV_OBJ_FLAG_CLICK_FOCUSABLE,
        Checkable = LV_OBJ_FLAG_CHECKABLE,
        Scrollable = LV_OBJ_FLAG_SCROLLABLE,
        Scroll_Elastic = LV_OBJ_FLAG_SCROLL_ELASTIC,
        Scroll_Momentum = LV_OBJ_FLAG_SCROLL_MOMENTUM,
        Scroll_One = LV_OBJ_FLAG_SCROLL_ONE,
        Scroll_Chain_Horizontal = LV_OBJ_FLAG_SCROLL_CHAIN_HOR,
        Scroll_Chain_Vertical = LV_OBJ_FLAG_SCROLL_CHAIN_VER,
        Scroll_Chain = LV_OBJ_FLAG_SCROLL_CHAIN,
        Scroll_On_Focus = LV_OBJ_FLAG_SCROLL_ON_FOCUS,
        Scroll_With_Arrow = LV_OBJ_FLAG_SCROLL_WITH_ARROW,
        Snappable = LV_OBJ_FLAG_SNAPPABLE,
        Press_Lock = LV_OBJ_FLAG_PRESS_LOCK,
        Event_Bubble = LV_OBJ_FLAG_EVENT_BUBBLE,
        Gesture_Bubble = LV_OBJ_FLAG_GESTURE_BUBBLE,
        Adv_Hittest = LV_OBJ_FLAG_ADV_HITTEST,
        Ignore_Layout = LV_OBJ_FLAG_IGNORE_LAYOUT,
        Floating = LV_OBJ_FLAG_FLOATING,
        Overflow_Visible = LV_OBJ_FLAG_OVERFLOW_VISIBLE,
        Layout_1 = LV_OBJ_FLAG_LAYOUT_1,
        Layout_2 = LV_OBJ_FLAG_LAYOUT_2,
        Widget_1 = LV_OBJ_FLAG_WIDGET_1,
        Widget_2 = LV_OBJ_FLAG_WIDGET_2,
        Custom_1 = LV_OBJ_FLAG_USER_1,
        Custom_2 = LV_OBJ_FLAG_USER_2,
        Custom_3 = LV_OBJ_FLAG_USER_3,
        Custom_4 = LV_OBJ_FLAG_USER_4,
    };

    typedef lv_obj_class_t Class_Type;
    typedef lv_style_selector_t Style_Selector_Type;

    typedef lv_dir_t Direction_Type;

    /// @brief Direction enumeration.
    enum Direction_Enumeration
    {
        None = LV_DIR_NONE,
        Left = LV_DIR_LEFT,
        Right = LV_DIR_RIGHT,
        Top = LV_DIR_TOP,
        Bottom = LV_DIR_BOTTOM,
        Horizontal = LV_DIR_HOR,
        Vertical = LV_DIR_VER,
        All = LV_DIR_ALL,
    };

    /// @brief Event enumeration.

    // TODO : Don't forget to convert the draw part to LVGL draw part (no auto-cast).
    typedef enum Draw_Part_Enumeration
    {
        Rectangle = LV_OBJ_DRAW_PART_RECTANGLE,
        Border_Post = LV_OBJ_DRAW_PART_BORDER_POST,
        Scrollbar = LV_OBJ_DRAW_PART_SCROLLBAR
    } Draw_Part_Type;

    // -- Methods

    // -- Constructors

    Object_Class();

    // - Management
    virtual void Create(Object_Class &Parent_Object);
    void Delete();
    void Clean();
    // - - Flags
    void Add_Flag(Flag_Type Flag);
    void Clear_Flag(Flag_Type Flag);
    bool Has_Flag(Flag_Type Flag);
    bool Has_Any_Flag(Flag_Type Flag);
    // - - States
    void Add_State(State_Type State);
    void Clear_State(State_Type State);
    bool Has_State(State_Type State);
    // - - Swap
    void Swap(Object_Class Object_To_Swap_With);
    // - - Events
    void Add_Event(Event_Class::Event_Code_Type Event);
    bool Remove_Event(Event_Class::Event_Code_Type Event);
    void Send_Event(Event_Class::Event_Code_Type Event);
    // - - Layer management
    void Move_Foreground();
    void Move_Background();

    void Allocate_Special_Data();

    bool Check_Type(const Class_Type *Class);
    bool Has_Class(const Class_Type *Class);

    bool Is_Valid();

    void Add_Style(Style_Type *Style, Style_Selector_Type Style_Selector);

    Coordinate_Type DPX(Coordinate_Type Coordinate);

    static void Event_Callback(lv_event_t *Event);

    // - - Setters methods.
    void Set_Index(uint32_t Index);
    void Set_Parent(Object_Class Parent_Object);

    void Set_User_Data(void *User_Data);

    // - - - Position and size.
    void Set_Position_X(Coordinate_Type X);
    void Set_Position_Y(Coordinate_Type Y);
    void Set_Position(Coordinate_Type X, Coordinate_Type Y);
    void Set_Alignment(Alignment_Type Alignment);                                                                                        // -- Relative to parent object.
    void Set_Alignment(Alignment_Type Alignment, Coordinate_Type X_Offset, Coordinate_Type Y_Offset);                                    // -- Relative to parent object.
    void Set_Alignment(Object_Class Object_To_Align_With, Alignment_Type Alignment, Coordinate_Type X_Offset, Coordinate_Type Y_Offset); // -- Relative to parent object.
    void Set_Size(Coordinate_Type Width, Coordinate_Type Height);
    void Set_Width(Coordinate_Type Width);
    void Set_Height(Coordinate_Type Height);

    // - - - Flex
    void Set_Flex_Alignment(Flex_Alignment_Type Main_Place_Alignment, Flex_Alignment_Type Cross_Place_Alignment, Flex_Alignment_Type Track_Cross_Place);
    void Set_Flex_Flow(Flex_Flow_Type Flow);
    void Set_Flex_Grow(uint8_t Grow);

    // - - - Grid
    void Set_Grid_Alignment(Grid_Alignment_Type Column_Alignment, Grid_Alignment_Type Row_Alignment);
    void Set_Grid_Cell(Grid_Alignment_Type Column_Alignment, uint8_t Column_Position, uint8_t Column_Span, Grid_Alignment_Type Row_Alignment, uint8_t Row_Position, uint8_t Row_Span);
    void Set_Grid_Descriptor_Array(const Coordinate_Type *Column_Descriptor, const Coordinate_Type *Row_Descriptor);

    // - - - Style

    // - - - - Position
    void Set_Style_Alignment(Alignment_Type Alignment, Style_Selector_Type Style_Selector);

    // - - - - Animation
    void Set_Style_Animation_Speed(uint32_t Value, Style_Selector_Type Style_Selector);
    void Set_Style_Animation_Time(uint32_t Value, Style_Selector_Type Style_Selector);

    // - - - - Arc
    void Set_Style_Arc_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Arc_Image_Source(const void *Image_Source, Style_Selector_Type Style_Selector);
    void Set_Style_Arc_Opacity(Opacity_Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Arc_Rounded(bool Rounded, Style_Selector_Type Style_Selector);
    void Set_Style_Arc_Width(Coordinate_Type Width, Style_Selector_Type Style_Selector);

    void Set_Style_Base_Direction(Direction_Type Direction, Style_Selector_Type Style_Selector);

    // - - - - Background
    void Set_Style_Background_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Dither_Mode(Dither_Mode_Type Dither_Mode, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Gradient(const Gradient_Descriptor_Type *Gradient_Descriptor, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Gradient_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Gradient_Direction(Gradient_Direction_Type Gradient_Direction, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Gradient_Stop(Coordinate_Type Value, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Image_Opacity(Opacity_Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Image_Recolor(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Image_Recolor_Opacity(Opacity_Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Image_Source(const void *Image_Source, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Image_Tiled(bool Tiled, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Main_Stop(Coordinate_Type Value, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Opacity(Opacity_Type Opacity, Style_Selector_Type Style_Selector);

    // - - - - Blend
    void Set_Style_Blend_Mode(Blend_Mode_Type Blend_Mode, Style_Selector_Type Style_Selector);

    // - - - - Border
    void Set_Style_Border_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Border_Opacity(Opacity_Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Border_Post(bool Value, Style_Selector_Type Style_Selector);
    void Set_Style_Border_Side(Border_Side_Type Border_Side, Style_Selector_Type Style_Selector);
    void Set_Style_Border_Width(Coordinate_Type Width, Style_Selector_Type Style_Selector);

    void Set_Style_Clip_Corner(bool Value, Style_Selector_Type Style_Selector);

    // - - - - Color filter
    void Set_Style_Color_Filter_Descriptor(const Color_Filter_Descriptor_Class *Color_Filter_Descriptor, Style_Selector_Type Style_Selector);
    void Set_Style_Color_Filter_Opacity(Opacity_Type Opacity, Style_Selector_Type Style_Selector);

    // - - - - Flex
    void Set_Style_Flex_Cross_Place(Flex_Alignment_Type Cross_Place, Style_Selector_Type Style_Selector);
    void Set_Style_Flex_Flow(Flex_Flow_Type Flow, Style_Selector_Type Style_Selector);
    void Set_Style_Flex_Grow(uint8_t Value, Style_Selector_Type Style_Selector);
    void Set_Style_Flex_Main_Place(Flex_Alignment_Type Main_Place, Style_Selector_Type Style_Selector);
    void Set_Style_Flex_Track_Place(Flex_Alignment_Type Track_Place, Style_Selector_Type Style_Selector);

    // - - - - Grid
    void Set_Style_Grid_Cell_Column_Position(Coordinate_Type Column_Position, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Cell_Column_Span(Coordinate_Type Column_Span, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Cell_Row_Position(Coordinate_Type Row_Position, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Cell_Row_Span(Coordinate_Type Row_Span, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Cell_X_Alignment(Coordinate_Type X_Alignment, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Cell_Y_Alignment(Coordinate_Type Y_Alignment, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Column_Alignment(Grid_Alignment_Type Column_Alignment, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Column_Descriptor_Array(const Coordinate_Type *Column_Descriptor_Array, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Row_Alignment(Grid_Alignment_Type Row_Alignment, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Row_Descriptor_Array(const Coordinate_Type *Row_Descriptor_Array, Style_Selector_Type Style_Selector);

    void Set_Style_Height(Coordinate_Type Height, Style_Selector_Type Style_Selector);

    // - - - - Image
    void Set_Style_Image_Opacity(Opacity_Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Image_Recolor(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Image_Recolor_Opacity(Opacity_Type Opacity, Style_Selector_Type Style_Selector);

    void Set_Style_Layout(uint16_t Value, Style_Selector_Type Style_Selector);

    // - - - - Line
    void Set_Style_Line_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Line_Dash_Gap(Coordinate_Type Dash_Gap, Style_Selector_Type Style_Selector);
    void Set_Style_Line_Dash_Width(Coordinate_Type Dash_Width, Style_Selector_Type Style_Selector);
    void Set_Style_Line_Opacity(Opacity_Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Line_Rounded(bool Rounded, Style_Selector_Type Style_Selector);
    void Set_Style_Line_Width(Coordinate_Type Width, Style_Selector_Type Style_Selector);

    void Set_Style_Maximum_Height(Coordinate_Type Maximum_Height, Style_Selector_Type Style_Selector);
    void Set_Style_Maximum_Width(Coordinate_Type Maximum_Width, Style_Selector_Type Style_Selector);
    void Set_Style_Minimum_Height(Coordinate_Type Minimum_Height, Style_Selector_Type Style_Selector);
    void Set_Style_Minimum_Width(Coordinate_Type Minimum_Width, Style_Selector_Type Style_Selector);
    void Set_Style_Opacity(Opacity_Type Opacity, Style_Selector_Type Style_Selector);

    // - - - - Outline
    void Set_Style_Outline_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Outline_Opacity(Opacity_Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Outline_Pad(Coordinate_Type Pad, Style_Selector_Type Style_Selector);
    void Set_Style_Outline_Width(Coordinate_Type Width, Style_Selector_Type Style_Selector);

    // - - - - Pad
    void Set_Style_Pad_Bottom(Coordinate_Type Pad_Bottom, Style_Selector_Type Style_Selector);
    void Set_Style_Pad_Left(Coordinate_Type Pad_Left, Style_Selector_Type Style_Selector);
    void Set_Style_Pad_Right(Coordinate_Type Pad_Right, Style_Selector_Type Style_Selector);
    void Set_Style_Pad_Top(Coordinate_Type Pad_Top, Style_Selector_Type Style_Selector);
    void Set_Style_Pad_Row(Coordinate_Type Pad_Row, Style_Selector_Type Style_Selector);
    void Set_Style_Pad_Column(Coordinate_Type Pad_Column, Style_Selector_Type Style_Selector);
    void Set_Style_Pad_All(Coordinate_Type Pad_All, Style_Selector_Type Style_Selector);

    void Set_Style_Radius(Coordinate_Type Radius, Style_Selector_Type Style_Selector);

    // - - - - Shadow
    void Set_Style_Shadow_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Shadow_Offset_X(Coordinate_Type Offset_X, Style_Selector_Type Style_Selector);
    void Set_Style_Shadow_Offset_Y(Coordinate_Type Offset_Y, Style_Selector_Type Style_Selector);
    void Set_Style_Shadow_Opacity(Opacity_Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Shadow_Spread(Coordinate_Type Spread, Style_Selector_Type Style_Selector);
    void Set_Style_Shadow_Width(Coordinate_Type Width, Style_Selector_Type Style_Selector);

    // - - - - Text
    void Set_Style_Text_Alignment(Text_Alignment_Type Alignment, Style_Selector_Type Style_Selector);
    void Set_Style_Text_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Text_Decor(Text_Decor_Type Decor, Style_Selector_Type Style_Selector);
    void Set_Style_Text_Font(Font_Type *Font, Style_Selector_Type Style_Selector);
    void Set_Style_Text_Letter_Space(Coordinate_Type Letter_Space, Style_Selector_Type Style_Selector);
    void Set_Style_Text_Line_Space(Coordinate_Type Line_Space, Style_Selector_Type Style_Selector);
    void Set_Style_Text_Opacity(Opacity_Type Opacity, Style_Selector_Type Style_Selector);

    // - - - - Transform
    void Set_Style_Transform_Angle(Coordinate_Type Angle, Style_Selector_Type Style_Selector);
    void Set_Style_Transform_Height(Coordinate_Type Height, Style_Selector_Type Style_Selector);
    void Set_Style_Transform_Width(Coordinate_Type Width, Style_Selector_Type Style_Selector);
    void Set_Style_Transform_Zoom(Coordinate_Type Zoom, Style_Selector_Type Style_Selector);

    void Set_Style_Transition(const Style_Class::Transition_Descriptor_Type *Transition_Descriptor, Style_Selector_Type Style_Selector);

    void Set_Style_Translate_X(Coordinate_Type Translate_X, Style_Selector_Type Style_Selector);
    void Set_Style_Translate_Y(Coordinate_Type Translate_Y, Style_Selector_Type Style_Selector);

    void Set_Style_Width(Coordinate_Type Width, Style_Selector_Type Style_Selector);

    void Set_Style_X(Coordinate_Type Style_X, Style_Selector_Type Style_Selector);
    void Set_Style_Y(Coordinate_Type Style_Y, Style_Selector_Type Style_Selector);

    // - - - Tile
    void Set_Tile(Object_Class &Tile, bool Animation);
    void Set_Tile_Identifier(uint16_t Column_Identifier, uint16_t Row_Identifier, bool Animation);
    void Set_User_Data(void *User_Data);

    // - - Getters values.

    const Class_Type *Get_Class();

    State_Type Get_State();

    void *Get_Group();
    void *Get_User_Data();

    bool Get_Object_Visibility();

    // Family relationship.
    Object_Class Get_Parent();
    uint32_t Get_Child_Count();
    Object_Class Get_Child(uint16_t Index);

    // - - Style

    Alignment_Type Get_Style_Alignment(uint32_t Part);
    // - - - Animation
    // const Animation_Class Get_Style_Animation(uint32_t Part);
    uint32_t Get_Style_Animation_Time(uint32_t Part);
    uint32_t Get_Style_Animation_Speed(uint32_t Part);
    // - - - Arc
    Color_Type Get_Style_Arc_Color(uint32_t Part);
    Color_Type Get_Style_Arc_Color_Filtered(uint32_t Part);
    const void *Get_Style_Arc_Image_Source(uint32_t Part);
    Opacity_Type Get_Style_Arc_Opacity(uint32_t Part);
    bool Get_Style_Arc_Rounded(uint32_t Part);
    Coordinate_Type Get_Style_Arc_Width(uint32_t Part);

    Base_Direction_Type Get_Style_Base_Direction(uint32_t Part);
    // - - - Background
    Color_Type Get_Style_Background_Color(uint32_t Part);
    Color_Type Get_Style_Background_Color_Filtered(uint32_t Part);
    Opacity_Type Get_Style_Background_Opacity(uint32_t Part);
    Color_Type Get_Style_Background_Gradient_Color(uint32_t Part);
    Color_Type Get_Style_Background_Gradient_Color_Filtered(uint32_t Part);
    Gradient_Direction_Type Get_Style_Background_Gradient_Direction(uint32_t Part);
    Coordinate_Type Get_Style_Background_Main_Stop(uint32_t Part);
    Coordinate_Type Get_Style_Background_Gradient_Stop(uint32_t Part);
    const Gradient_Descriptor_Type *Get_Style_Background_Gradient(uint32_t Part);
    Dither_Mode_Type Get_Style_Background_Dither_Mode(uint32_t Part);
    const void *Get_Style_Background_Image_Source(uint32_t Part);
    Opacity_Type Get_Style_Background_Image_Opacity(uint32_t Part);
    Color_Type Get_Style_Background_Image_Recolor(uint32_t Part);
    Color_Type Get_Style_Background_Image_Recolor_Filtered(uint32_t Part);
    Opacity_Type Get_Style_Background_Image_Recolor_Opacity(uint32_t Part);
    bool Get_Style_Background_Image_Tiled(uint32_t Part);

    Blend_Mode_Type Get_Style_Blend_Mode(uint32_t Part);

    // - - - Border
    Color_Type Get_Style_Border_Color(uint32_t Part);
    Color_Type Get_Style_Border_Color_Filtered(uint32_t Part);
    Opacity_Type Get_Style_Border_Opacity(uint32_t Part);
    Coordinate_Type Get_Style_Border_Width(uint32_t Part);
    Border_Side_Type Get_Style_Border_Side(uint32_t Part);
    bool Get_Style_Border_Post(uint32_t Part);

    bool Get_Style_Clip_Corner(uint32_t Part);
    const Color_Filter_Descriptor_Class Get_Style_Color_Filter_Descriptor(uint32_t Part);
    Opacity_Type Get_Style_Color_Filter_Opacity(uint32_t Part);

    // - - - Flex

    Flex_Flow_Type Get_Style_Flex_Flow(uint32_t Part);
    Flex_Alignment_Type Get_Style_Flex_Main_Place(uint32_t Part);
    Flex_Alignment_Type Get_Style_Flex_Cross_Place(uint32_t Part);
    Flex_Alignment_Type Get_Style_Flex_Track_Place(uint32_t Part);
    uint8_t Get_Style_Flex_Grow(uint32_t Part);

    // - - - Grid
    Coordinate_Type Get_Style_Grid_Cell_Column_Position(uint32_t Part);
    Coordinate_Type Get_Style_Grid_Cell_Column_Span(uint32_t Part);
    Coordinate_Type Get_Style_Grid_Cell_Row_Position(uint32_t Part);
    Coordinate_Type Get_Style_Grid_Cell_Row_Span(uint32_t Part);
    Coordinate_Type Get_Style_Grid_Cell_X_Alignment(uint32_t Part);
    Coordinate_Type Get_Style_Grid_Cell_Y_Alignment(uint32_t Part);
    Grid_Alignment_Type Get_Style_Grid_Column_Alignment(uint32_t Part);
    const Coordinate_Type *Get_Style_Grid_Column_Descriptor_Array(uint32_t Part);
    Grid_Alignment_Type Get_Style_Grid_Row_Alignment(uint32_t Part);
    const Coordinate_Type *Get_Style_Grid_Row_Descriptor_Array(uint32_t Part);

    Coordinate_Type Get_Style_Height(uint32_t Part);

    // - - - Image
    Opacity_Type Get_Style_Image_Opacity(uint32_t Part);
    Color_Type Get_Style_Image_Recolor(uint32_t Part);
    Color_Type Get_Style_Image_Recolor_Filtered(uint32_t Part);
    Opacity_Type Get_Style_Image_Recolor_Opacity(uint32_t Part);

    uint16_t Get_Style_Layout(uint32_t Part);

    // - - - Line
    Color_Type Get_Style_Line_Color(uint32_t Part);
    Color_Type Get_Style_Line_Color_Filtered(uint32_t Part);
    Coordinate_Type Get_Style_Line_Dash_Gap(uint32_t Part);
    Coordinate_Type Get_Style_Line_Dash_Width(uint32_t Part);
    Opacity_Type Get_Style_Line_Opacity(uint32_t Part);
    bool Get_Style_Line_Rounded(uint32_t Part);
    Coordinate_Type Get_Style_Line_Width(uint32_t Part);

    // - - - Size
    Coordinate_Type Get_Style_Maximum_Height(uint32_t Part);
    Coordinate_Type Get_Style_Maximum_Width(uint32_t Part);
    Coordinate_Type Get_Style_Minimum_Height(uint32_t Part);
    Coordinate_Type Get_Style_Minimum_Width(uint32_t Part);

    Opacity_Type Get_Style_Opacity(uint32_t Part);

    // - - - Outline
    Color_Type Get_Style_Outline_Color(uint32_t Part);
    Color_Type Get_Style_Outline_Color_Filtered(uint32_t Part);
    Opacity_Type Get_Style_Outline_Opacity(uint32_t Part);
    Coordinate_Type Get_Style_Outline_Pad(uint32_t Part);
    Coordinate_Type Get_Style_Outline_Width(uint32_t Part);

    // - - - Padding
    Coordinate_Type Get_Style_Pad_Bottom(uint32_t Part);
    Coordinate_Type Get_Style_Pad_Top(uint32_t Part);
    Coordinate_Type Get_Style_Pad_Left(uint32_t Part);
    Coordinate_Type Get_Style_Pad_Right(uint32_t Part);
    Coordinate_Type Get_Style_Pad_Row(uint32_t Part);
    Coordinate_Type Get_Style_Pad_Column(uint32_t Part);

    Coordinate_Type Get_Style_Radius(uint32_t Part);

    // - - - Shadow
    Color_Type Get_Style_Shadow_Color(uint32_t Part);
    Color_Type Get_Style_Shadow_Color_Filtered(uint32_t Part);
    Coordinate_Type Get_Style_Shadow_Offset_X(uint32_t Part);
    Coordinate_Type Get_Style_Shadow_Offset_Y(uint32_t Part);
    Opacity_Type Get_Style_Shadow_Opacity(uint32_t Part);
    Coordinate_Type Get_Style_Shadow_Spread(uint32_t Part);
    Coordinate_Type Get_Style_Shadow_Width(uint32_t Part);

    // - - - Text
    Text_Alignment_Type Get_Style_Text_Alignment(uint32_t Part);
    Color_Type Get_Style_Text_Color(uint32_t Part);
    Color_Type Get_Style_Text_Color_Filtered(uint32_t Part);
    Text_Decor_Type Get_Style_Text_Decor(uint32_t Part);
    const Font_Type *Get_Style_Text_Font(uint32_t Part);
    Coordinate_Type Get_Style_Text_Letter_Space(uint32_t Part);
    Coordinate_Type Get_Style_Text_Line_Space(uint32_t Part);
    Opacity_Type Get_Style_Text_Opacity(uint32_t Part);

    // - - - Transform
    Coordinate_Type Get_Style_Transform_Angle(uint32_t Part);
    Coordinate_Type Get_Style_Transform_Height(uint32_t Part);
    Coordinate_Type Get_Style_Transform_Width(uint32_t Part);
    Coordinate_Type Get_Style_Transform_Zoom(uint32_t Part);

    const Style_Class::Transition_Descriptor_Type *Get_Style_Transition(uint32_t Part);
    Coordinate_Type Get_Style_Translate_X(uint32_t Part);
    Coordinate_Type Get_Style_Translate_Y(uint32_t Part);
    Coordinate_Type Get_Style_Width(uint32_t Part);
    Coordinate_Type Get_Style_X(uint32_t Part);
    Coordinate_Type Get_Style_Y(uint32_t Part);

    // - - Operator
    Object_Class &operator=(Object_Class Object_Class);
    operator bool();

    // TODO : See the encapsulation of these following methods.
    virtual bool Set_Pointer(lv_obj_t *Object);
    inline lv_obj_t *Get_Pointer()
    {
        return LVGL_Object_Pointer;
    };

    lv_obj_t *LVGL_Object_Pointer;

protected:
};

// -- Management -- //

#endif