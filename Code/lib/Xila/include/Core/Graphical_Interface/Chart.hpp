///
/// @file Chart.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 18-07-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Chart_Hpp_Included
#define Chart_Hpp_Included

/*
#include "Object.hpp"

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

    enum Draw_Part::Type
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
    Cursor_Type *Add_Cursor(Color_Type Color, Direction::Type Direction);

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
};*/

#endif