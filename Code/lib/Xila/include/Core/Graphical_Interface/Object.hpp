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

#include "Types.hpp"

#include "../Module.hpp"

#ifndef Object_Hpp_Included
#define Object_Hpp_Included

#define Percentage(x) LV_PCT(x)

/// @brief Object class.
class Object_Class : public Types_Class
{
public:
    // - Types

    /// @brief Animation type.
    typedef Animation_Class Animation_Type;

    /// @brief Point type.
    typedef lv_point_t Point_Type;

    /// @brief Area type.
    typedef Area_Class Area_Type;

    /// @brief Style type.
    typedef Style_Class Style_Type;

    /// @brief Color type.
    typedef Color_Class Color_Type;

    /// @brief Color descriptor type.
    typedef Color_Filter_Descriptor_Class Color_Filter_Descriptor_Type;

    // -- Types and enumerations

    typedef lv_coord_t Coordinate_Type;

   

    class State
    {
    public:
        typedef lv_state_t Type;

        /// @brief Possible states of a widget. ORed values are possible.
        enum Enumeration
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
    };

    class Part
    {
    public:
        typedef lv_part_t Type;

        /// @brief Part enumeration.
        enum Enumeration
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
    };

    class Flag
    {
    public:
        typedef lv_obj_flag_t Type;

        /// @brief Flag enumeration.
        enum Enumeration
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
    };

    typedef lv_obj_class_t Class_Type;
    typedef lv_style_selector_t Style_Selector_Type;

    class Direction
    {
    public:
        /// @brief Direction type.
        typedef lv_dir_t Type;

        /// @brief Direction enumeration.
        enum Enumeration
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
    };

    class Draw_Part
    {
    public:
        /// @brief Event enumeration.
        // TODO : Don't forget to convert the draw part to LVGL draw part (no auto-cast).
        typedef enum Enumeration
        {
            Rectangle = LV_OBJ_DRAW_PART_RECTANGLE,
            Border_Post = LV_OBJ_DRAW_PART_BORDER_POST,
            Scrollbar = LV_OBJ_DRAW_PART_SCROLLBAR
        } Type;
    };

    // -- Methods

    // -- Constructors

    Object_Class();

    // - Management
    virtual void Create(Object_Class Parent_Object);
    void Delete();
    void Clean();
    // - - Flags
    void Add_Flag(Flag::Type Flag);
    void Clear_Flag(Flag::Type Flag);
    bool Has_Flag(Flag::Type Flag);
    bool Has_Any_Flag(Flag::Type Flag);
    // - - States
    void Add_State(State::Type State);
    void Clear_State(State::Type State);
    bool Has_State(State::Type State);
    // - - Swap
    void Swap(Object_Class Object_To_Swap_With);
    // - - Events
    void Add_Event(Event::Code_Type Event, Xila_Namespace::Module_Class::Instruction_Type* Instruction);
    //TODO : Find a way add this method to the class :
    // bool Remove_Event(Event::Code_Type Event); 
    void Send_Event(Event::Code_Type Event);
    // - - Layer management
    void Move_Foreground();
    void Move_Background();

    void Allocate_Special_Data();

    bool Check_Type(const Class_Type *Class);
    bool Has_Class(const Class_Type *Class);

    bool Is_Valid();

    void Add_Style(Style_Type& Style, Style_Selector_Type Style_Selector);

    Coordinate_Type DPX(Coordinate_Type Coordinate);

    // - - Setters methods.
    void Set_Index(uint32_t Index);
    void Set_Parent(Object_Class Parent_Object);

    void Set_User_Data(void *User_Data);

    // - - - Position and size.
    void Set_Position_X(Coordinate_Type X);
    void Set_Position_Y(Coordinate_Type Y);
    void Set_Position(Coordinate_Type X, Coordinate_Type Y);
    void Set_Alignment(Alignment::Type Alignment);                                                                                        // -- Relative to parent object.
    void Set_Alignment(Alignment::Type Alignment, Coordinate_Type X_Offset, Coordinate_Type Y_Offset);                                    // -- Relative to parent object.
    void Set_Alignment(Object_Class Object_To_Align_With, Alignment::Type Alignment, Coordinate_Type X_Offset, Coordinate_Type Y_Offset); // -- Relative to parent object.
    void Set_Size(Coordinate_Type Width, Coordinate_Type Height);
    void Set_Width(Coordinate_Type Width);
    void Set_Height(Coordinate_Type Height);

    // - - - Flex
    void Set_Flex_Alignment(Flex::Alignment_Type Main_Place_Alignment, Flex::Alignment_Type Cross_Place_Alignment, Flex::Alignment_Type Track_Cross_Place);
    void Set_Flex_Flow(Flex::Flow_Type Flow);
    void Set_Flex_Grow(uint8_t Grow);

    // - - - Grid
    void Set_Grid_Alignment(Grid::Alignment_Type Column_Alignment, Grid::Alignment_Type Row_Alignment);
    void Set_Grid_Cell(Grid::Alignment_Type Column_Alignment, uint8_t Column_Position, uint8_t Column_Span, Grid::Alignment_Type Row_Alignment, uint8_t Row_Position, uint8_t Row_Span);
    void Set_Grid_Descriptor_Array(const Coordinate_Type *Column_Descriptor, const Coordinate_Type *Row_Descriptor);

    // - - - Style

    // - - - - Position
    void Set_Style_Alignment(Alignment::Type Alignment, Style_Selector_Type Style_Selector);

    // - - - - Animation
    void Set_Style_Animation_Speed(uint32_t Value, Style_Selector_Type Style_Selector);
    void Set_Style_Animation_Time(uint32_t Value, Style_Selector_Type Style_Selector);

    // - - - - Arc
    void Set_Style_Arc_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Arc_Image_Source(const void *Image_Source, Style_Selector_Type Style_Selector);
    void Set_Style_Arc_Opacity(Opacity::Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Arc_Rounded(bool Rounded, Style_Selector_Type Style_Selector);
    void Set_Style_Arc_Width(Coordinate_Type Width, Style_Selector_Type Style_Selector);

    void Set_Style_Base_Direction(Direction::Type Direction, Style_Selector_Type Style_Selector);

    // - - - - Background
    void Set_Style_Background_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Dither_Mode(Dither_Mode::Type Dither_Mode, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Gradient(const Gradient::Descriptor_Type *Gradient_Descriptor, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Gradient_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Gradient_Direction(Gradient::Direction_Type Gradient_Direction, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Gradient_Stop(Coordinate_Type Value, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Image_Opacity(Opacity::Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Image_Recolor(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Image_Recolor_Opacity(Opacity::Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Image_Source(const void *Image_Source, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Image_Tiled(bool Tiled, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Main_Stop(Coordinate_Type Value, Style_Selector_Type Style_Selector);
    void Set_Style_Background_Opacity(Opacity::Type Opacity, Style_Selector_Type Style_Selector);

    // - - - - Blend
    void Set_Style_Blend_Mode(Blend::Mode_Type Blend_Mode, Style_Selector_Type Style_Selector);

    // - - - - Border
    void Set_Style_Border_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Border_Opacity(Opacity::Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Border_Post(bool Value, Style_Selector_Type Style_Selector);
    void Set_Style_Border_Side(Border::Side_Type Border_Side, Style_Selector_Type Style_Selector);
    void Set_Style_Border_Width(Coordinate_Type Width, Style_Selector_Type Style_Selector);

    void Set_Style_Clip_Corner(bool Value, Style_Selector_Type Style_Selector);

    // - - - - Color filter
    void Set_Style_Color_Filter_Descriptor(Color_Filter_Descriptor_Class& Color_Filter_Descriptor, Style_Selector_Type Style_Selector);
    void Set_Style_Color_Filter_Opacity(Opacity::Type Opacity, Style_Selector_Type Style_Selector);

    // - - - - Flex
    void Set_Style_Flex_Cross_Place(Flex::Alignment_Type Cross_Place, Style_Selector_Type Style_Selector);
    void Set_Style_Flex_Flow(Flex::Flow_Type Flow, Style_Selector_Type Style_Selector);
    void Set_Style_Flex_Grow(uint8_t Value, Style_Selector_Type Style_Selector);
    void Set_Style_Flex_Main_Place(Flex::Alignment_Type Main_Place, Style_Selector_Type Style_Selector);
    void Set_Style_Flex_Track_Place(Flex::Alignment_Type Track_Place, Style_Selector_Type Style_Selector);

    // - - - - Grid
    void Set_Style_Grid_Cell_Column_Position(Coordinate_Type Column_Position, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Cell_Column_Span(Coordinate_Type Column_Span, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Cell_Row_Position(Coordinate_Type Row_Position, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Cell_Row_Span(Coordinate_Type Row_Span, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Cell_X_Alignment(Coordinate_Type X_Alignment, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Cell_Y_Alignment(Coordinate_Type Y_Alignment, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Column_Alignment(Grid::Alignment_Type Column_Alignment, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Column_Descriptor_Array(const Coordinate_Type *Column_Descriptor_Array, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Row_Alignment(Grid::Alignment_Type Row_Alignment, Style_Selector_Type Style_Selector);
    void Set_Style_Grid_Row_Descriptor_Array(const Coordinate_Type *Row_Descriptor_Array, Style_Selector_Type Style_Selector);

    void Set_Style_Height(Coordinate_Type Height, Style_Selector_Type Style_Selector);

    // - - - - Image
    void Set_Style_Image_Opacity(Opacity::Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Image_Recolor(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Image_Recolor_Opacity(Opacity::Type Opacity, Style_Selector_Type Style_Selector);

    void Set_Style_Layout(uint16_t Value, Style_Selector_Type Style_Selector);

    // - - - - Line
    void Set_Style_Line_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Line_Dash_Gap(Coordinate_Type Dash_Gap, Style_Selector_Type Style_Selector);
    void Set_Style_Line_Dash_Width(Coordinate_Type Dash_Width, Style_Selector_Type Style_Selector);
    void Set_Style_Line_Opacity(Opacity::Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Line_Rounded(bool Rounded, Style_Selector_Type Style_Selector);
    void Set_Style_Line_Width(Coordinate_Type Width, Style_Selector_Type Style_Selector);

    void Set_Style_Maximum_Height(Coordinate_Type Maximum_Height, Style_Selector_Type Style_Selector);
    void Set_Style_Maximum_Width(Coordinate_Type Maximum_Width, Style_Selector_Type Style_Selector);
    void Set_Style_Minimum_Height(Coordinate_Type Minimum_Height, Style_Selector_Type Style_Selector);
    void Set_Style_Minimum_Width(Coordinate_Type Minimum_Width, Style_Selector_Type Style_Selector);
    void Set_Style_Opacity(Opacity::Type Opacity, Style_Selector_Type Style_Selector);

    // - - - - Outline
    void Set_Style_Outline_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Outline_Opacity(Opacity::Type Opacity, Style_Selector_Type Style_Selector);
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
    void Set_Style_Shadow_Opacity(Opacity::Type Opacity, Style_Selector_Type Style_Selector);
    void Set_Style_Shadow_Spread(Coordinate_Type Spread, Style_Selector_Type Style_Selector);
    void Set_Style_Shadow_Width(Coordinate_Type Width, Style_Selector_Type Style_Selector);

    // - - - - Text
    void Set_Style_Text_Alignment(Text::Alignment_Type Alignment, Style_Selector_Type Style_Selector);
    void Set_Style_Text_Color(Color_Type Color, Style_Selector_Type Style_Selector);
    void Set_Style_Text_Decor(Text::Decor_Type Decor, Style_Selector_Type Style_Selector);
    void Set_Style_Text_Font(Font_Type *Font, Style_Selector_Type Style_Selector);
    void Set_Style_Text_Letter_Space(Coordinate_Type Letter_Space, Style_Selector_Type Style_Selector);
    void Set_Style_Text_Line_Space(Coordinate_Type Line_Space, Style_Selector_Type Style_Selector);
    void Set_Style_Text_Opacity(Opacity::Type Opacity, Style_Selector_Type Style_Selector);

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

    void Set_Layout(uint32_t Layout);

    // - - - Tile
    void Set_Tile(Object_Class Tile, bool Animation);
    void Set_Tile_Identifier(uint16_t Column_Identifier, uint16_t Row_Identifier, bool Animation);

    // - - Getters values.

    const Class_Type *Get_Class();

    State::Type Get_State();

    void *Get_Group();
    void *Get_User_Data();

    bool Get_Object_Visibility();

    // Family relationship.
    Object_Class Get_Parent();
    uint32_t Get_Child_Count();
    Object_Class Get_Child(uint16_t Index);

    // - - Style

    Alignment::Type Get_Style_Alignment(uint32_t Part);
    // - - - Animation
    // const Animation_Class Get_Style_Animation(uint32_t Part);
    uint32_t Get_Style_Animation_Time(uint32_t Part);
    uint32_t Get_Style_Animation_Speed(uint32_t Part);
    // - - - Arc
    Color_Type Get_Style_Arc_Color(uint32_t Part);
    Color_Type Get_Style_Arc_Color_Filtered(uint32_t Part);
    const void *Get_Style_Arc_Image_Source(uint32_t Part);
    Opacity::Type Get_Style_Arc_Opacity(uint32_t Part);
    bool Get_Style_Arc_Rounded(uint32_t Part);
    Coordinate_Type Get_Style_Arc_Width(uint32_t Part);

    Base_Direction::Type Get_Style_Base_Direction(uint32_t Part);
    // - - - Background
    Color_Type Get_Style_Background_Color(uint32_t Part);
    Color_Type Get_Style_Background_Color_Filtered(uint32_t Part);
    Opacity::Type Get_Style_Background_Opacity(uint32_t Part);
    Color_Type Get_Style_Background_Gradient_Color(uint32_t Part);
    Color_Type Get_Style_Background_Gradient_Color_Filtered(uint32_t Part);
    Gradient::Direction_Type Get_Style_Background_Gradient_Direction(uint32_t Part);
    Coordinate_Type Get_Style_Background_Main_Stop(uint32_t Part);
    Coordinate_Type Get_Style_Background_Gradient_Stop(uint32_t Part);
    const Gradient::Descriptor_Type *Get_Style_Background_Gradient(uint32_t Part);
    Dither_Mode::Type Get_Style_Background_Dither_Mode(uint32_t Part);
    const void *Get_Style_Background_Image_Source(uint32_t Part);
    Opacity::Type Get_Style_Background_Image_Opacity(uint32_t Part);
    Color_Type Get_Style_Background_Image_Recolor(uint32_t Part);
    Color_Type Get_Style_Background_Image_Recolor_Filtered(uint32_t Part);
    Opacity::Type Get_Style_Background_Image_Recolor_Opacity(uint32_t Part);
    bool Get_Style_Background_Image_Tiled(uint32_t Part);

    Blend::Mode_Type Get_Style_Blend_Mode(uint32_t Part);

    // - - - Border
    Color_Type Get_Style_Border_Color(uint32_t Part);
    Color_Type Get_Style_Border_Color_Filtered(uint32_t Part);
    Opacity::Type Get_Style_Border_Opacity(uint32_t Part);
    Coordinate_Type Get_Style_Border_Width(uint32_t Part);
    Border::Side_Type Get_Style_Border_Side(uint32_t Part);
    bool Get_Style_Border_Post(uint32_t Part);

    bool Get_Style_Clip_Corner(uint32_t Part);
    const Color_Filter_Descriptor_Class Get_Style_Color_Filter_Descriptor(uint32_t Part);
    Opacity::Type Get_Style_Color_Filter_Opacity(uint32_t Part);

    // - - - Flex

    Flex::Flow_Type Get_Style_Flex_Flow(uint32_t Part);
    Flex::Alignment_Type Get_Style_Flex_Main_Place(uint32_t Part);
    Flex::Alignment_Type Get_Style_Flex_Cross_Place(uint32_t Part);
    Flex::Alignment_Type Get_Style_Flex_Track_Place(uint32_t Part);
    uint8_t Get_Style_Flex_Grow(uint32_t Part);

    // - - - Grid
    Coordinate_Type Get_Style_Grid_Cell_Column_Position(uint32_t Part);
    Coordinate_Type Get_Style_Grid_Cell_Column_Span(uint32_t Part);
    Coordinate_Type Get_Style_Grid_Cell_Row_Position(uint32_t Part);
    Coordinate_Type Get_Style_Grid_Cell_Row_Span(uint32_t Part);
    Coordinate_Type Get_Style_Grid_Cell_X_Alignment(uint32_t Part);
    Coordinate_Type Get_Style_Grid_Cell_Y_Alignment(uint32_t Part);
    Grid::Alignment_Type Get_Style_Grid_Column_Alignment(uint32_t Part);
    const Coordinate_Type *Get_Style_Grid_Column_Descriptor_Array(uint32_t Part);
    Grid::Alignment_Type Get_Style_Grid_Row_Alignment(uint32_t Part);
    const Coordinate_Type *Get_Style_Grid_Row_Descriptor_Array(uint32_t Part);

    Coordinate_Type Get_Style_Height(uint32_t Part);

    // - - - Image
    Opacity::Type Get_Style_Image_Opacity(uint32_t Part);
    Color_Type Get_Style_Image_Recolor(uint32_t Part);
    Color_Type Get_Style_Image_Recolor_Filtered(uint32_t Part);
    Opacity::Type Get_Style_Image_Recolor_Opacity(uint32_t Part);

    uint16_t Get_Style_Layout(uint32_t Part);

    // - - - Line
    Color_Type Get_Style_Line_Color(uint32_t Part);
    Color_Type Get_Style_Line_Color_Filtered(uint32_t Part);
    Coordinate_Type Get_Style_Line_Dash_Gap(uint32_t Part);
    Coordinate_Type Get_Style_Line_Dash_Width(uint32_t Part);
    Opacity::Type Get_Style_Line_Opacity(uint32_t Part);
    bool Get_Style_Line_Rounded(uint32_t Part);
    Coordinate_Type Get_Style_Line_Width(uint32_t Part);

    // - - - Size
    Coordinate_Type Get_Style_Maximum_Height(uint32_t Part);
    Coordinate_Type Get_Style_Maximum_Width(uint32_t Part);
    Coordinate_Type Get_Style_Minimum_Height(uint32_t Part);
    Coordinate_Type Get_Style_Minimum_Width(uint32_t Part);

    Opacity::Type Get_Style_Opacity(uint32_t Part);

    // - - - Outline
    Color_Type Get_Style_Outline_Color(uint32_t Part);
    Color_Type Get_Style_Outline_Color_Filtered(uint32_t Part);
    Opacity::Type Get_Style_Outline_Opacity(uint32_t Part);
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
    Opacity::Type Get_Style_Shadow_Opacity(uint32_t Part);
    Coordinate_Type Get_Style_Shadow_Spread(uint32_t Part);
    Coordinate_Type Get_Style_Shadow_Width(uint32_t Part);

    // - - - Text
    Text::Alignment_Type Get_Style_Text_Alignment(uint32_t Part);
    Color_Type Get_Style_Text_Color(uint32_t Part);
    Color_Type Get_Style_Text_Color_Filtered(uint32_t Part);
    Text::Decor_Type Get_Style_Text_Decor(uint32_t Part);
    const Font_Type *Get_Style_Text_Font(uint32_t Part);
    Coordinate_Type Get_Style_Text_Letter_Space(uint32_t Part);
    Coordinate_Type Get_Style_Text_Line_Space(uint32_t Part);
    Opacity::Type Get_Style_Text_Opacity(uint32_t Part);

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

    virtual bool Set_Pointer(lv_obj_t *LVGL_Object_Pointer);
    // TODO : See the encapsulation of these following methods.

    inline lv_obj_t *Get_Pointer()
    {
        return LVGL_Object_Pointer;
    };

    void Clear_Pointer() {
        LVGL_Object_Pointer = NULL;
    };

    lv_obj_t *LVGL_Object_Pointer;

protected:
};

// -- Management -- //

#endif