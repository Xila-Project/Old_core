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

#ifndef Object_Hpp_Included
#define Object_Hpp_Included

#define Class Xila_Class::Display_Class::Object_Class // Shortcut

/// @brief Object class.
class Object_Class
{
public:
    
    // -- Types and enumerations

    typedef lv_coord_t Coordinate_Type;
    typedef lv_opa_t Opacity_Type;

    typedef lv_state_t State_Type;

    /// @brief Possible states of a widget. ORed values are possible.
    enum
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
    enum
    {
        Main = LV_PART_MAIN,
        Scrollbar = LV_PART_SCROLLBAR,
        Indicator = LV_PART_INDICATOR,
        Knob = LV_PART_KNOB,
        Selected = LV_PART_SELECTED,
        Items = LV_PART_ITEMS,
        Ticks = LV_PART_TICKS,
        Cursor = LV_PART_CURSOR,
        Custom_First = LV_PART_CUSTOM_FIRST,
        Any = LV_PART_ANY
    };

    typedef lv_obj_flag_t Flag_Type;

    /// @brief Flag enumeration.
    enum
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
    enum
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
    typedef enum
    {
        Rectangle = LV_OBJ_DRAW_PART_RECTANGLE,
        Border_Post = LV_OBJ_DRAW_PART_BORDER_POST,
        Scrollbar = LV_OBJ_DRAW_PART_SCROLLBAR
    } lv_obj_draw_part_type_t;

    // -- Methods

    // -- Constructors

    Object_Class();

    //  -- Management
    virtual void Create(const Object_Class &Parent_Object);
    void Delete();
    void Clean();
    // -- -- Flags
    void Add_Flag(Flag_Type Flag);
    void Clear_Flag(Flag_Type Flag);
    bool Has_Flag(Flag_Type Flag);
    bool Has_Any_Flag(Flag_Type Flag);
    // -- -- States
    void Add_State(State_Type State);
    void Clear_State(State_Type State);
    bool Has_State(State_Type State);
    // -- -- Swap
    void Swap(Object_Class Object_To_Swap_With);
    // -- -- Events
    void Add_Event(Event_Type Event);
    void Remove_Event(Event_Type Event);
    void Send_Event(Event_Type Event);
    // -- -- Layer management
    void Move_Foreground();
    void Move_Background();

    void Allocate_Special_Data();

    bool Check_Type(const Class_Type *Class);
    bool Has_Class(const Class_Type *Class);
    const Class_Type *Get_Class();

    bool Is_Valid();
    bool Is_Focused();

    static Coordinate_Type DPX(Coordinate_Type Coordinate);

    // -- Setters values
    void Set_Index(uint32_t Index);
    void Set_Parent(Object_Class Parent_Object);

    void Set_User_Data(void *User_Data);

    // -- -- Position and size.a
    void Set_Position_X(Coordinate_Type X);
    void Set_Position_Y(Coordinate_Type Y);
    void Set_Position(Coordinate_Type X, Coordinate_Type Y);
    void Set_Alignment(Alignment_Type Alignment);   // -- Relative to parent object.
    void Set_Alignment(Alignment_Type Alignment, Coordinate_Type X_Offset,Coordinate_Type Y_Offset);    // -- Relative to parent object.
    void Set_Alignment(Object_Class Object_To_Align_With, Alignment_Type Alignment, Coordinate_Type X_Offset, Coordinate_Type Y_Offset);    // -- Relative to parent object.
    



    void Set_Size(Xila_Class::Object_Class, Coordinates Width = Keep, Coordinates Height = Keep, char Fit = 'N');

    // Style
    void Add_Style(Style_Type Style, Style_Selector_Type *Style_Selector);

    // -- Getters values.
    State_Type Get_State();
    void *Get_Group();
    void *Get_User_Data();
    State_Type Get_Object_Visibility(Object_Class);
    void Get_Identifier(Object_Class Object);

    uint16_t Get_Child_Count(Object_Class Parent_Object);
    Object_Class Get_Child(Object_Class Object, uint16_t Index);

    // -- Operator
    Object_Class& operator=(const Object_Class Object_Class);
    operator bool() const;

protected:
    LVGL_Object_Type* Get_Parent();

    virtual bool Set_Pointer(LVGL_Object_Type *Object);
    LVGL_Object_Type* Get_Pointer();

    static void Event_Handler(Event_Type Event);

private:
    LVGL_Object_Class *LVGL_Object_Pointer;
};

// -- Management -- //



#endif