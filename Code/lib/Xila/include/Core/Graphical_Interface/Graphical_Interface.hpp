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