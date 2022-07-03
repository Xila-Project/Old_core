///
 /// @file Table.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief 
 /// @version 0.1.0
 /// @date 04-05-2022
 /// 
 /// @copyright Copyright (c) 2022
 /// 

 #ifndef TABLE_HPP_INCLUDED
 #define TABLE_HPP_INCLUDED

#include "Arduino.h"

#define Class Xila_Class::Display_Class::Table_Class

// -- Setters

inline void Class::Set_Cell_Value(uint16_t Row, uint16_t Column, const char* Value)
{
    lv_table_set_cell_value(Get_Pointer(), Row, Column, Value);
}

inline void Class::Set_Cell_Value(uint16_t Row, uint16_t Column, const char* Formated_Value, ...)
{
    lv_table_set_cell_value_fmt(Get_Pointer(), Row, Column, Formated_Value, var_args);
}

inline void Class::Set_Row_Count(uint16_t Row_Count)
{
    lv_table_set_row_cnt(Get_Pointer(), Row_Count);
}

inline void Class::Set_Column_Count(uint16_t Column_Count)
{
    lv_table_set_col_cnt(Get_Pointer(), Column_Count);
}

inline void Class::Set_Column_Width(uint16_t Column, Coordinates_Type Width)
{
    lv_table_set_col_width(Get_Pointer(), Column, Width);
}

inline void Class::Set_Cell_Alignment(uint16_t Row, uint16_t Column, Label_Align_Type Align)
{
    lv_table_set_cell_align(Get_Pointer(), Row, Column, Align);
}

inline void Class::Set_Cell_Type(uint16_t Row, uint16_t Column, uint8_t Type)
{
    lv_table_set_cell_type(Get_Pointer(), Row, Column, Type);
}

inline void Class::Set_Cell_Crop(uint16_t Row, uint16_t Column, bool Crop)
{
    lv_table_set_cell_crop(Get_Pointer(), Row, Column, Crop);
}

inline void Class::Set_Cell_Merge_Right(uint16_t Row, uint16_t Column, bool Merge)
{
    lv_table_set_cell_merge_right(Get_Pointer(), Row, Column, Merge);
}

// -- Getters

const char* Class::Get_CEll_Value(uint16_t Row, uint16_t Column)
{
    return lv_table_get_cell_value(Get_Pointer(), Row, Column);
}

inline uint16_t Class::Get_Row_Count()
{
    return lv_table_get_row_cnt(Get_Pointer());
}

inline uint16_t Class::Get_Column_Count()
{
    return lv_table_get_col_cnt(Get_Pointer());
}

inline Coordinates_Type Class::Get_Column_Width(uint16_t Column)
{
    return lv_table_get_col_width(Get_Pointer(), Column);
}

inline Label_Align_Type Class::Get_Cell_Alignment(uint16_t Row, uint16_t Column)
{
    return lv_table_get_cell_align(Get_Pointer(), Row, Column);
}

inline Label_Align_Type Class::Get_Cell_Type(uint16_t Row, uint16_t Column)
{
    return lv_table_get_cell_type(Get_Pointer(), Row, Column);
}

inline Label_Align_Type Class::Get_Cell_Crop(uint16_t Row, uint16_t Column)
{
    return lv_table_get_cell_crop(Get_Pointer(), Row, Column);
}

inline bool Class::Get_Cell_Merge_Right(uint16_t Row, uint16_t Column)
{
    return lv_table_get_cell_merge_right(Get_Pointer(), Row, Column);
}

inline Ressource_Type Class::Get_Pressed_Cell(uint16_t* Row, uint16_t* Column)
{
    return lv_table_get_pressed_cell(Get_Pointer(), Row, Column);
}

#undef Class

 #endif