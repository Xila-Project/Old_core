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

#ifndef Object_Hpp_Included
#define Object_Hpp_Included

#define Class Xila_Class::Display_Class::Object_Class // Shortcut

/// @brief Object class.
class Object_Class
{
public:
    // - Types

    enum Image_Color_Fomrat_Enumeration
    {
        Unknow = LV_IMG_CF_UNKNOWN,

        Raw= LV_IMG_CF_RAW,              /**< Contains the file as it is. Needs custom decoder function*/
        Raw_Alpha = LV_IMG_CF_RAW_ALPHA,        /**< Contains the file as it is. The image has alpha. Needs custom decoder
                                       function*/
        Raw_Chroma_Keyed = LV_IMG_CF_RAW_CHROMA_KEYED, /**< Contains the file as it is. The image is chroma keyed. Needs
                                       custom decoder function*/

        True_Color = LV_IMG_CF_TRUE_COLOR,              /**< Color format and depth should match with LV_COLOR settings*/
        True_Color_Alpha = LV_IMG_CF_TRUE_COLOR_ALPHA,        /**< Same as `LV_IMG_CF_TRUE_COLOR` but every pixel has an alpha byte*/
        True_Color_Chroma_Keyed = LV_IMG_CF_TRUE_COLOR_CHROMA_KEYED, /**< Same as `LV_IMG_CF_TRUE_COLOR` but LV_COLOR_TRANSP pixels
                                              will be transparent*/

        Indexed_1_Bit = LV_IMG_CF_INDEXED_1BIT, /**< Can have 2 different colors in a palette (always chroma keyed)*/
        Indexed_2_Bits = LV_IMG_CF_INDEXED_2BIT, /**< Can have 4 different colors in a palette (always chroma keyed)*/
        Indexed_4_Bits = LV_IMG_CF_INDEXED_4BIT, /**< Can have 16 different colors in a palette (always chroma keyed)*/
        Indexed_8_Bits = LV_IMG_CF_INDEXED_8BIT, /**< Can have 256 different colors in a palette (always chroma keyed)*/

        Alpha_1_Bit = LV_IMG_CF_ALPHA_1BIT, /**< Can have one color and it can be drawn or not*/
        Alpha_2_Bits = LV_IMG_CF_ALPHA_2BIT, /**< Can have one color but 4 different alpha value*/
        Alpha_4_Bits = LV_IMG_CF_ALPHA_4BIT, /**< Can have one color but 16 different alpha value*/
        Alpha_8_Bits = LV_IMG_CF_ALPHA_8BIT, /**< Can have one color but 256 different alpha value*/

        Reserved_15 = LV_IMG_CF_RESERVED_15, /**< Reserved for further use.*/
        Reserved_16 = LV_IMG_CF_RESERVED_16, /**< Reserved for further use.*/
        Reserved_17 = LV_IMG_CF_RESERVED_17, /**< Reserved for further use.*/
        Reserved_18 = LV_IMG_CF_RESERVED_18, /**< Reserved for further use.*/
        Reserved_19 = LV_IMG_CF_RESERVED_19, /**< Reserved for further use.*/
        Reserved_20 = LV_IMG_CF_RESERVED_20, /**< Reserved for further use.*/
        Reserved_21 = LV_IMG_CF_RESERVED_21, /**< Reserved for further use.*/
        Reserved_22 = LV_IMG_CF_RESERVED_22, /**< Reserved for further use.*/
        Reserved_23 = LV_IMG_CF_RESERVED_23, /**< Reserved for further use.*/

        User_Encoded_0 = LV_IMG_CF_USER_ENCODED_0, /**< User holder encoding format.*/
        User_Encoded_1 = LV_IMG_CF_USER_ENCODED_1, /**< User holder encoding format.*/
        User_Encoded_2 = LV_IMG_CF_USER_ENCODED_2, /**< User holder encoding format.*/
        User_Encoded_3 = LV_IMG_CF_USER_ENCODED_3, /**< User holder encoding format.*/
        User_Encoded_4 = LV_IMG_CF_USER_ENCODED_4, /**< User holder encoding format.*/
        User_Encoded_5 = LV_IMG_CF_USER_ENCODED_5, /**< User holder encoding format.*/
        User_Encoded_6 = LV_IMG_CF_USER_ENCODED_6, /**< User holder encoding format.*/
        User_Encoded_7 = LV_IMG_CF_USER_ENCODED_7, /**< User holder encoding format.*/
    };

    /// @brief Image color format type.
    typedef lv_img_cf_t Image_Color_Format_Type;

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
    typedef lv_color_t Color_Type;

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

    typedef lv_obj_t LVGL_Object_Type;

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
    void Add_Event(Event_Type Event);
    void Remove_Event(Event_Type Event);
    void Send_Event(Event_Type Event);
    // - - Layer management
    void Move_Foreground();
    void Move_Background();

    void Allocate_Special_Data();

    bool Check_Type(const Class_Type *Class);
    bool Has_Class(const Class_Type *Class);

    bool Is_Valid();

    void Add_Style(Style_Type *Style, Style_Selector_Type Style_Selector);

    Coordinate_Type DPX(Coordinate_Type Coordinate);

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

    // - - - Flex
    void Set_Flex_Align(Flex_Alignment_Type Main_Place_Alignment, Flex_Alignment_Type Cross_Place_Alignment, Flex_Alignment_Type Track_Cross_Place);
    void Set_Flex_Flow(Flex_Flow_Type Flow);
    void Set_Flex_Grow(uint8_t Grow);

    // - - - Grid
    void Set_Grid_Alignment(Grid_Alignment_Type Column_Alignment, Grid_Alignment_Type Row_Alignment);
    void Set_Grid_Cell(Grid_Alignment_Type Column_Alignment, uint8_t Column_Position, uint8_t Column_Span, Grid_Alignment_Type Row_Alignment, uint8_t Row_Position, uint8_t Row_Span);
    void Set_Grid_Descriptor_Array(const Coordinate_Type Column_Descriptor[], const Coordinate_Type Row_Descriptor[]);

    // - - - Style
    // TODO : Implement all styles methods.

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
    Alignment_Type Get_Style_Align(uint32_t Part);
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
    const Color_Filter_Descriptor_Type *Get_Style_Color_Filter_Descriptor(uint32_t Part);
    Opacity_Type Get_Style_Color_Filter_Opacity(uint32_t Part);

    Flex_Flow_Type Get_Style_Flex_Flow(uint32_t Part);
    Flex_Alignment_Type Get_Style_Flex_Main_Place(uint32_t Part);
    Flex_Alignment_Type Get_Style_Flex_Cross_Place(uint32_t Part);
    Flex_Alignment_Type Get_Style_Flex_Track_Place(uint32_t Part);
    uint8_t Get_Style_Flex_Grow(uint32_t Part);
    // TODO : Implement other styles properties.

    // - - Operator
    Object_Class &operator=(const Object_Class Object_Class);
    operator bool() const;

    // TODO : See the encapsulation of these following methods.
    virtual bool Set_Pointer(LVGL_Object_Type *Object);
    inline LVGL_Object_Type *Get_Pointer()
    {
        return LVGL_Object_Pointer;
    };

    LVGL_Object_Type *LVGL_Object_Pointer;

    static void Event_Handler(Event_Type Event);

protected:
private:
};

// -- Management -- //

#endif