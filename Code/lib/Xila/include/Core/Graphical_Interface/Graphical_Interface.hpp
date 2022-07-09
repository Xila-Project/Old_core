///
/// @file Graphic_Interface.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 03-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Graphical_Interface_Hpp_Included
#define Graphical_Interface_Hpp_Included

#include <Arduino.h>

#include "lvgl.h"

// Base object
#include "Display/Object.hpp"
// Widgets
#include "Display/Arc.hpp"
#include "Display/Bar.hpp"
#include "Display/Button.hpp"
#include "Display/Button_Matrix.hpp"
#include "Display/Canvas.hpp"
#include "Display/Checkbox.hpp"
#include "Display/Dropdown_List.hpp"
#include "Display/Image.hpp"
#include "Display/Line.hpp"
#include "Display/Roller.hpp"
#include "Display/Slider.hpp"
#include "Display/Switch.hpp"
#include "Display/Table.hpp"
#include "Display/Text_Area.hpp"
// Extra widgets
#include "Display/Animaton_Image.hpp"
#include "Display/Calendar.hpp"
#include "Display/Chart.hpp"
#include "Display/Color_Wheel.hpp"
#include "Display/Image_Button.hpp"
#include "Display/Keyboard.hpp"
#include "Display/List.hpp"
#include "Display/Menu.hpp"
#include "Display/Meter.hpp"
#include "Display/Message_Box.hpp"
#include "Display/Span.hpp"
#include "Display/Spinbox.hpp"
#include "Display/Spinner.hpp"
#include "Display/Tab.hpp"
#include "Display/Tileview.hpp"
#include "Display/Window.hpp"

class Graphic_Interface_Class
{


    /// @brief Animations enumeration
    enum Animation
    {
        Enable = LV_ANIM_ON,
        Disable = LV_ANIM_OFF
    };

    /// @brief Event class.
    class Event_Class
    {
    public:
        Event_Code_Type Get_Code();
        Object_Class Get_Current_Target();
        Object_Class Get_Target();
        void *Get_User_Data();

        typedef enum
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

    private:
        lv_event_t LVGL_Event;
    };

    void Initialise();
    bool Initialisation_State();

    /// @brief Screnn class.
    class Screen_Class : public Object_Class
    {
        // TODO : Implement screen API.
    };





    /// @brief Button matrix class.
    

    /// @brief Canvas class.


    class Checkbox_Class : public Object_Class
    {
    public:
        enum Draw_Part_Type
        {
            Box = LV_CHECKBOX_DRAW_PART_BOX,
        };

        // -- Methods

        Checkbox_Class(Object_Class &Parent_Object);

        // -- -- Set attributes values.
        void Set_Text(const char *Text);
        void Set_Text_Static(const char *Text);

        // -- -- Get attributes values.
        const char *Get_Text();
    };

    class Drop_Down_List_Class : public Object_Class
    {
    public:
        // -- Methods

        Drop_Down_List_Class(Object_Class &Parent_Object);

        // Management

        void Add_Option(const char *Option, uint32_t Position);
        void Clear_Options();

        void Open();
        void Close();

        //  Setters
        void Set_Text(const char *Text);
        void Set_Options(const char *Options);
        void Set_Options_Static(const char *Options);
        void Set_Selected(uint16_t Selected_Option);
        void Set_Direction(Direction_Type Direction);
        void Set_Symbol(const void *Symbol);
        void Set_Selected_Highlight(bool Enabled);

        //  Getters
        Object_Class Get_List();
        const char *Get_Text();
        const char *Get_Options();
        uint16_t Get_Selected();
        uint16_t Get_Option_Count();
        void Get_Selected_String(char *Buffer, Size_Type Buffer_Size);
        int32_t Get_Option_Index(const char *Option);
        const char *Get_Symbol();
        bool Get_Selected_Highlight();
        Direction_Type Get_Direction();
        bool Is_Open();
    };

    /// @brief image class
    class Image_Class : public Object_Class
    {
    public:
        typedef lv_img_size_mode_t Image_Size_Mode_Type;

        enum
        {
            Virtual = LV_IMG_SIZE_MODE_VIRTUAL,
            Real = LV_IMG_SIZE_MODE_REAL
        };

        // -- Methods
        Image_Class(Object_Class &Parent_Object);

        // -- Setters
        void Set_Source(const void *Source);
        void Set_Offset_X(Coordinate_Type X);
        void Set_Offset_Y(Coordinate_Type Y);
        void Set_Angle(int16_t Angle);
        void Set_Pivot(Coordinate_Type X, Coordinate_Type Y);
        void Set_Zoom(uint16_t Zoom);
        void Set_Antialias(bool Enabled);
        void Set_Size_Mode(Image_Size_Mode_Type Size_Mode);

        // -- Getters
        const void *Get_Size_Mode();
        Coordinate_Type Get_Offset_X();
        Coordinate_Type Get_Offset_Y();
        uint16_t Get_Angle();
        void Get_Pivot(Coordinate_Type *X, Coordinate_Type *Y);
        uint16_t Get_Zoom();
        bool Get_Antialias();
        Image_Size_Mode_Type Get_Size_Mode();
    };

    /// @brief Label class.
    class Label_Class : public Label_Class
    {
    public:
        // -- Types
        typedef lv_label_long_mode_t Long_Mode_Type;

        enum
        {
            Long_Wrap = LV_LABEL_LONG_WRAP,
            Long_Dot = LV_LABEL_LONG_DOT,
            Long_Scroll = LV_LABEL_LONG_SCROLL,
            Long_Scroll_Circular = LV_LABEL_LONG_SCROLL_CIRCULAR,
            Long_Clip = LV_LABEL_LONG_CLIP
        };

        // -- Methods
        Label_Class(const Object_Class &Parent_Object);
        void Insert_Text(uint32_t Position, const char *Text);
        void Cut_Text(uint32_t Position, uint32_t Length);
        bool Is_Char_Under_Position(Point_Type *Position);

        // -- Setters
        void Set_Text(const char *Text);
        void Set_Text_Format(const char *Format, ...);
        void Set_Text_Static(const char *Text);
        void Set_Long_Mode(Long_Mode_Type Long_Mode);
        void Set_Recolor(bool Recolor);
        void Set_Selection_Start(uint32_t Index);
        void Set_Selection_End(uint32_t Index);

        // -- Getters
        char *Get_Text();
        Long_Mode_Type Get_Long_Mode();
        bool Get_Recolor();
        void Get_Letter_Position(uint32_t Index, Point_Type *Position);
        uint32_t Get_Letter_On(Point_Type *Position_In);
        uint32_t Get_Selection_Start();
        uint32_t Get_Selection_End();
    };

    /// @brief Line class.
    class Line_Class : public Object_Class
    {
    public:
        // -- Methods
        Line_Class(const Object_Class &Parent_Object);

        void Set_Points(const Point_Type Points[], uint16_t Point_Number);
        void Set_Y_Inversion(bool Inversion);

        bool Get_Y_Inversion();
    }

    /// @brief Roller class.
    class Roller_Class : public Object_Class
    {
    public:
        // -- Types
        typedef lv_roller_mode_t Mode_Type;
        enum
        {
            Normal = LV_ROLLER_MODE_NORMAL,
            Infinite = LV_ROLLER_MODE_INFINITE
        };

        // -- Methods
        Roller_Class(Parent_Object &Parent_Object);

        // -- Setters
        void Set_Options(const char *Options, Mode_Type Mode);
        void Set_Selected(uint16_t Index, Animation_Enable_Type Animation);
        void Set_Visible_Row_Count(uint8_t Row_Count);

        // -- Getters
        uint16_t Get_Selected();
        void Get_Selected_String(char *Buffer, uint32_t Buffer_Size);
        const char *Get_Options();
        uint16_t Get_Option_Count();
    };

    class Slider_Class : public Object_Class
    {
    public:
        // -- Types
        typedef lv_slider_mode_t Slider_Mode;

        // -- Enumerations
        enum
        {
            Normal = LV_SLIDER_MODE_NORMAL,
            Symmetrical = LV_SLIDER_MODE_SYMMETRICAL,
            Range = LV_SLIDER_MODE_RANGE,
        };

        typedef enum
        {
            Knob = LV_SLIDER_TYPE_KNOB,
            Knob_Left = LV_SLIDER_TYPE_KNOB_LEFT,
        } Part_Type;

        // -- Methods
        Slider_Class(Object_Class &Parent_Object);

        bool Is_Dragged();

        // -- -- Setters.
        void Set_Value(int32_t Value, bool Animation);
        void Set_Left_Value(int32_t Value, bool Animation);
        void Set_Range(int32_t Minimum_Value, int32_t Maximum_Value);
        void Set_Mode(Mode_Type Mode);

        // -- -- Getters.
        int32_t Get_Value();
        int32_t Get_Left_Value();
        int32_t Get_Minimum_Value();
        int32_t Get_Maximum_Value();
        Mode_Type Get_Mode();
    };

    class Switch_Class : public Object_Class
    {
    public:
        // -- Methods
        Switch_Class(Object_Class &Parent_Object);
    };

    class Table_Class : public Object_Class
    {
    public:
        // -- Typedef

        typedef lv_table_cell_format_t Cell_Format;

        enum
        {
            Background,
            Cell_1,
            Cell_2,
            Cell_3,
            Cell_4
        };

        // -- Methods

        Table_Class(Object_Class &Parent_Object);

        // -- -- Setters.

        void Set_Cell_Value(uint16_t Row, uint16_t Column, const char *Value);
        void Set_Cell_Value_Format(uint16_t Row, uint16_t Column, const char *Formated_Value, ...);
        void Set_Row_Count(uint16_t Row_Count);
        void Set_Column_Count(uint16_t Column_Count);
        void Set_Column_Width(uint16_t Column, Coordinates_Type Width);
        void Set_Cell_Alignment(uint16_t Row, uint16_t Column, Label_Align_Type Align);
        void Set_Cell_Type(uint16_t Row, uint16_t Column, uint8_t Type);
        void Set_Cell_Crop(uint16_t Row, uint16_t Column, bool Crop);
        void Set_Cell_Merge_Right(uint16_t Row, uint16_t Column, bool Merge);

        // -- -- Getters.
        const char *Get_Cell_Value(uint16_t Row, uint16_t Column);
        uint16_t Get_Row_Count();
        uint16_t Get_Column_Count();
        Coordinates_Type Get_Column_Width(uint16_t Column);
        Label_Align_Type Get_Cell_Alignment(uint16_t Row, uint16_t Column);
        Label_Align_Type Get_Cell_Type(uint16_t Row, uint16_t Column);
        Label_Align_Type Get_Cell_Crop(uint16_t Row, uint16_t Column);
        bool Get_Cell_Merge_Right(uint16_t Row, uint16_t Column);
        Ressource_Type Get_Pressed_Cell(uint16_t *Row, uint16_t *Column);
    };

    class Text_Area_Class : public Object_Class
    {
        /// @brief Text area custom part enumeration.
        enum
        {
            Placeholder = LV_TEXTAREA_PLACEHOLDER
        };

        // -- Methods

        Text_Area_Class(Object_Class &Parent_Object);

        void Add_Char(uint32_t Character);
        void Add_Text(const char *Text);
        void Delete_Character();
        void Delete_Character_Forward();

        // -- Setters
        void Set_Text(const char *Text);
        void Set_Placeholder_Text(const char *Text);
        void Set_Cursor_Click_Position(bool Enabled);
        void Set_Password_Bullet(const char *Bullet);
        void Set_One_Line(bool Enabled);
        void Set_Accepted_Characters(const char *List);
        void Set_Maximum_Length(uint32_t Length);
        void Set_Insert_Replace(const char *Text);
        void Set_Text_Selection(bool Enabled);
        void Set_Password_Show_Time(uint16_t Time);
        void Set_Text_Alignment(Text_Align_Type Alignment);

        // -- Getters
        const char *Get_Text();
        const char *Get_Placeholder_Text();
        Label_Class *Get_Label();
        uint32_t Get_Cursor_Position();
        bool Get_Cursor_Click_Position();
        bool Get_Password_Mode();
        const char *Get_Password_Bullet();
        bool Get_One_Line();
        const char *Get_Accepted_Characters();
        uint32_t Get_Maximum_Length();
        bool Get_Text_Selection();
        uint16_t Get_Password_Show_Time();

        void Clear_Selection();
        void Cursor_Right();
        void Cursor_Left();
        void Cursor_Up();
        void Cursor_Down();

        bool Is_Selected();
    };

    // -- Widgets

  
    class Chart_Class : public Object_Class
    {
    public:
        typedef lv_chart_series_t Series_Type;
        typedef lv_chart_cursor_t Cursor_Type;
        typedef lv_chart_tick_dsc_t Tick_Descriptor_Type;

        typedef uint8_t Type_Type;

        enum
        {
            None = LV_CHART_TYPE_NONE,
            Line = LV_CHART_TYPE_LINE,
            Bar = LV_CHART_TYPE_BAR,
            Scatter = LV_CHART_TYPE_SCATTER
        };

        typedef uint8_t Update_Mode_Type;

        enum
        {
            Shift = LV_CHART_UPDATE_MODE_SHIFT,
            Circular = LV_CHART_UPDATE_MODE_CIRCULAR
        };

        typedef uint8_t Axis_Type;

        enum
        {
            Primary_Y = LV_CHART_AXIS_PRIMARY_Y,
            Secondary_Y = LV_CHART_AXIS_SECONDARY_Y,
            Primary_X = LV_CHART_AXIS_PRIMARY_X,
            Secondary_X = LV_CHART_AXIS_SECONDARY_X,
            Last = LV_CHART_AXIS_LAST
        };

        enum Draw_Part_Type
        {
            Div_Line_Init = LV_CHART_DRAW_PART_DIV_LINE_INIT,
            Div_Line_Horizontal = LV_CHART_DRAW_PART_DIV_LINE_HORIZONTAL,
            Div_Line_Vertical = LV_CHART_DRAW_PART_DIV_LINE_VERTICAL,
            Line_And_Point = LV_CHART_DRAW_PART_LINE_AND_POINT,
            Bar = LV_CHART_DRAW_PART_BAR,
            Cursor = LV_CHART_DRAW_PART_CURSOR,
            Tick_Label = LV_CHART_DRAW_PART_TICK_LABEL
        };

        // -- Methods

        Chart_Class(Object_Class &Parent_Object);

        void Chart_Refresh();
        Series_Type *Add_Series(Color_Type Color, Axis_Type Axis);
        void Remove_Series(Series_Type *Series);
        void Hide_Series(Series_Type *Series, bool Hide);
        Cursor_Type *Add_Cursor(Color_Type Color, Direction_Type Direction);

        // -- -- Setters.

        void Set_Type(Type_Type Type);
        void Set_Point_Count(uint16_t Count);
        void Set_Range(Axis_Type Axis, Coordinates_Type Minimum, Coordinates_Type Maximum);
        void Set_Update_Mode(Update_Mode_Type Update_Mode);
        void Set_Div_Line_Count(uint8_t Horizontal_Div, uint8_t Vertical_Div);
        void Set_Zoom_X(uint16_t Zoom_X);
        void Set_Zoom_Y(uint16_t Zoom_Y);
        void Set_Axis_Tick(Axis_Type Axis, Coordinate_Type Major_Length, Coordinate_Type Minor_Length, Coordinate_Type Major_Count, Coordinate_Type Minor_Count, bool Label_Enabled, Coordinate_Type Draw_Size);
        void Set_Series_Color(Series_Type *Series, Color_Type Color);
        void Set_X_Start_Point(Series_Type *Series, uint16_t Identifier);
        void Set_Cursor_Position(Cursor_Type *Cursor, Point_Type *Position);
        void Set_Cursor_Point(Cursor_Type *Cursor, Series_Type *Series, uint16_t Identifier);
        void Set_All_Value(Series_Type *Series, Coordinate_Type Value);
        void Set_Next_Value(Series_Type *Series, Coordinate_Type Value);
        void Set_Next_Value(Series_Type *Series, Coordinate_Type X_Value, Coordinate_Type Y_Value);
        void Set_Value_By_Identifier(Series_Type *Series, uint16_t Identifier, Coordinate_Type Value);
        void Set_Value_By_Identifier(Series_Type *Series, uint16_t Identifier, Coordinate_Type X_Value, Coordinate_Type Y_Value);
        void Set_External_Y_Array(Series_Type *Series, Coordinate_Type Array[]);
        void Set_External_X_Array(Series_Type *Series, Coordinate_Type Array[]);

        // -- -- Getters.
        uint16_t Get_Zoom_X();
        uint16_t Get_Zoom_Y();
        Type_Type Get_Type();
        uint16_t Get_Point_Count();
        uint16_t Get_X_Start_Point(Series_Type *Series);
        void Get_Point_Position_By_Identifier(Series_Type *Series, uint16_t Identifier, Point_Type *Point_Out);
        Series_Type *Get_Series_Next(const Series_Type *Series);
        Point_Type Get_Cursor_Point(Cursor_Type *Cursor);
        Coordinate_Type *Get_Y_Array(Series_Type *Series);
        Coordinate_Type *Get_X_Array(Series_Type *Series);
        uint32_t Get_Pressed_Point();
    };

    // @brief Color wheel class.
    class Color_Wheel_Class : public Object_Class
    {
    public:
        // -- Types
        typedef lv_colorwheel_mode_t Mode_Type;

        enum
        {
            Hue = LV_COLORWHEEL_MODE_HUE,
            Saturation = LV_COLORWHEEL_MODE_SATURATION,
            Value = LV_COLORWHEEL_MODE_VALUE
        };

        // -- Methods
        Color_Wheel_Class(const Object_Class &Parent_Object);

        // -- -- Setters
        bool Set_HSV(Color_HSV_Type HSV_Color);
        bool Set_RGB(Color_Type Color);
        void Set_Mode(Mode_Type Mode);
        void Set_Mode_Fixed(bool Fixed);

        // -- Getters
        Color_HSV_Type Get_HSV();
        Color_Type Get_RGB();
        Mode_Type Get_Mode();
        bool Get_Mode_Fixed();
    };

    /// @brief Keyboard object class.
    class Keyboard_Class : public Object_Class
    {
        typedef lv_keyboard_mode_t Mode_Type;

        enum
        {
            Text_Lower = LV_KEYBOARD_MODE_TEXT_LOWER,
            Text_Upper = LV_KEYBOARD_MODE_TEXT_UPPER,
            Special = LV_KEYBOARD_MODE_SPECIAL,
            Number = LV_KEYBOARD_MODE_NUMBER,
            User_1 = LV_KEYBOARD_MODE_USER_1,
            User_2 = LV_KEYBOARD_MODE_USER_2,
            User_3 = LV_KEYBOARD_MODE_USER_3,
            User_4 = LV_KEYBOARD_MODE_USER_4
        };

        // -- Methods
        Keyboard_Class(const Object_Class &Parent_Object);

        void Define_Event_Callback(Event_Type *Event);

        // -- -- Setters
        void Set_Text_Area(Text_Area_Class &Text_Area);
        void Set_Mode(Mode_Type Mode);
        void Set_Pop_Overs(bool Enabled);
        void Set_Map(Mode_Type Mode, const char *Map[], const Xila_Class::Display_Class::Button_Matrix_Class::Control_Type Control_Map[]);

        // -- Getters
        Text_Area_Class &Get_Text_Area();
        Mode_Type Get_Mode();
        bool Get_Pop_Overs();
        static const char **Get_Map_Array();
        static const uint16_t Get_Selected_Button();
        static const char *Get_Button_Text();
    };

    /// @brief List class.
    class List_Class : public Object_Class
    {
    public:
        // -- Methods
        List_Class(const Object_Class &Parent_Object);

        const Text_Area_Class &Add_Text(const char *Text);
        const Button_Class &Add_Button(const void *Icon, const char *Text);

        // -- Getters
        const char *Get_Button_Text(Button_Class &Button);
    };

    /// @brief Menu class
    class Menu_Class : public Object_Class
    {
    public:
        // -- Methods
        typedef lv_menu_mode_header_t Mode_Header_Type;

        enum
        {
            Top_Fixed = LV_MENU_HEADER_TOP_FIXED,
            Top_Unfixed = LV_MENU_HEADER_TOP_UNFIXED,
            Bottom_Fixed = LV_MENU_HEADER_BOTTOM_FIXED,
        };

        typedef lv_menu_mode_root_back_btn_t Mode_Root_Back_Button_Type;

        enum
        {
            Back_Button_Disabled = LV_MENU_ROOT_BACK_BTN_DISABLED,
            Back_Button_Enabled = LV_MENU_ROOT_BACK_BTN_ENABLED,
        };

        Object_Class Create_Content(Object_Class Parent_Object);
        Object_Class Create_Section(Object_Class Parent_Object);
        Object_Class Create_Separator(Object_Class Parent_Object);

        void Set_Page(Object_Class Page);
        void Set_Sidebar_Page(Object_Class Page);
    };

    //

    class Tabs_Class : public Object_Class
    {
    public:
        // -- Types
        typedef lv_tabview_btns_pos_t Buttons_Position_Type;
        typedef lv_tabview_part_t Part_Type;
        enum
        {
            None = LV_TABVIEW_TAB_POS_NONE,
            Top = LV_ALIGN_TAB_POS_TOP,
            Bottom = LV_ALIGN_TAB_POS_BOTTOM,
            Left = LV_ALIGN_TAB_POS_LEFT,
            Right = LV_ALIGN_TAB_POS_RIGHT,
        };

        enum
        {
            Background = LV_TABVIEW_PART_BG,
            Virtual_Last = LV_TABVIEW_PART_VIRTUAL_LAST,
            Background_Scrollable = LV_TABVIEW_PART_BG_SCROLLABLE,
            Tab_Background = LV_TABVIEW_PART_TAB_BG,
            Tab_Button = LV_TABVIEW_PART_TAB_BTN,
            Part_Indicator = LV_TABVIEW_PART_INDICATOR,
            Real_Last = LV_TABVIEW_PART_REAL_LAST
        };

        // -- Methods
        Tabs_Class(Object_Class &Parent_Object);

        void Clean_Tab();

        // -- -- Setters.
        void Set_Active_Tab(uint16_t Identifier, Animation_Type Animation);
        void Set_Tab_Name(uint16_t Identifier, char *Name);
        void Set_Animation_Time(uint16_t Animation_Time);
        void Set_Buttons_Position(Buttons_Position_Type Buttons_Position);

        // -- -- Getters.
        uint16_t Get_Active_Tab();
        uint16_t Get_Tab_Count();
        Object_Class Get_Tab(uint16_t Identifier);
        uint16_t Get_Animation_Time();
        Buttons_Position_Type Get_Buttons_Position();
    };

    class Windows_Class : public Object_Class
    {
    public:
        typedef Xila_Class::Object_Class Object_Class;

        Object_Class Load(File);

        Object_Class Create();

        void Set_Title(Object_Class Window, const char *Title);

    protected:
        Object_Class Add_Button(Object_Class Parent_Window);

    private:
        Object_Class Title_Label;
        Object_Class Clock_Label;

        Object_Class Network_Button;
        Object_Class Battery_Button;
        Object_Class Sound_Button;

        Object_Class Close_Button;
        Object_Class Minimize_Button;
    };

    static void Task(void *);

    Xila_Class::Task_Handle Task_Handle;

    Xila_Class::Semaphore_Handle_Type Mutex_Semaphore_Handle;

    // -- Display state
    uint16_t Get_Horizontal_Definition();
    uint16_t Get_Vertical_Definition();

    Xila_Class::Event Compile_Page(File);
    Xila_Class::Event Load_Page(File, Object *, uint16_t);

protected:
    static lv_fs_drv_t File_System_Driver;

    static void *File_System_Open(lv_fs_drv_t *, const char *, lv_fs_mode_t);
    static lv_fs_res_t File_System_Close(lv_fs_drv_t *, void *);
    static lv_fs_res_t File_System_Read(lv_fs_drv_t *, void *, void *, uint32_t, uint32_t *);
    static lv_fs_res_t File_System_Write(lv_fs_drv_t *, void *, const void *, uint32_t, uint32_t *);
    static lv_fs_res_t File_System_Set_Position(lv_fs_drv_t *, void *, uint32_t, lv_fs_whence_t);
    static lv_fs_res_t File_System_Get_Position(lv_fs_drv_t *, void *, uint32_t *);
    static void *File_System_Open_Directory(lv_fs_drv_t *, const char *);
    static lv_fs_res_t File_System_Directory_Read(lv_fs_drv_t *, void *, char *);
    static lv_fs_res_t File_System_Close_Directory(lv_fs_drv_t *, void *);

    void Initialize_File_System();

    void Set_State(uint8_t State);

    void Set_State(uint8_t State);

    uint8_t State;

    uint8_t Brightness, Receive_Pin, Standby_Time, Transmit_Pin;

    Xila_Class::Address Current_Address;
};

#endif