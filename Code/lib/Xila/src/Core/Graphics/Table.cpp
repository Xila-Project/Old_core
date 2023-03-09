///
/// @file Table.cpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 17-07-2022
///
/// @copyright Copyright (c) 2022
///

#include "Core/Graphics/Table.hpp"
#include "Core/Graphics/Graphics.hpp"

using namespace Xila_Namespace;
using namespace Xila_Namespace::Graphics_Types;

// - Attributes

const Class_Type &Table_Class::Class = lv_table_class;

// - Methods

// - - Constructors / Destructors

Table_Class::Table_Class(const Object_Class &Object_To_Copy) : Object_Class(Object_To_Copy)
{
}

// - - Manipulation

void Table_Class::Create(Object_Class& Parent_Object)
{
    if (Parent_Object)
    {
        Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
        this->LVGL_Object_Pointer = lv_table_create(Parent_Object.Get_Pointer());
    }
}

void Table_Class::Add_Cell_Control(uint16_t Row, uint16_t Column, Cell_Control::Type Cell_Control)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_table_add_cell_ctrl(Get_Pointer(), Row, Column, Cell_Control);
}

void Table_Class::Clear_Cell_Control(uint16_t Row, uint16_t Column, Cell_Control::Type Cell_Control)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_table_clear_cell_ctrl(Get_Pointer(), Row, Column, Cell_Control);
}

bool Table_Class::Has_Cell_Control(uint16_t Row, uint16_t Column, Cell_Control::Type Cell_Control)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_table_has_cell_ctrl(Get_Pointer(), Row, Column, Cell_Control);
}

// - - Getters

const char *Table_Class::Get_Cell_Value(uint16_t Row, uint16_t Column)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_table_get_cell_value(Get_Pointer(), Row, Column);
}

uint16_t Table_Class::Get_Row_Count()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_table_get_row_cnt(Get_Pointer());
}

uint16_t Table_Class::Get_Column_Count()
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_table_get_col_cnt(Get_Pointer());
}

Coordinate_Type Table_Class::Get_Column_Width(uint16_t Column)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    return lv_table_get_col_width(Get_Pointer(), Column);
}

void Table_Class::Get_Selected_Cell(uint16_t *Row, uint16_t *Column)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_table_get_selected_cell(Get_Pointer(), Row, Column);
}

// - - Setters

bool Table_Class::Set_Pointer(lv_obj_t *Object)
{
    if (Get_Pointer() != NULL)
    {
        return false;
    }
    if (!Has_Class( &lv_table_class))
    {
        return false;
    }
    this->LVGL_Object_Pointer = LVGL_Object_Pointer;
    return true;
}

void Table_Class::Set_Cell_Value(uint16_t Row, uint16_t Column, const char *Value)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_table_set_cell_value(Get_Pointer(), Row, Column, Value);
}

void Table_Class::Set_Cell_Value_Format(uint16_t Row, uint16_t Column, const char *Formated_Value, ...)
{
    va_list Arguments;
    lv_table_set_cell_value_fmt(Get_Pointer(), Row, Column, Formated_Value, Arguments);
}

void Table_Class::Set_Row_Count(uint16_t Row_Count)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_table_set_row_cnt(Get_Pointer(), Row_Count);
}

void Table_Class::Set_Column_Count(uint16_t Column_Count)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_table_set_col_cnt(Get_Pointer(), Column_Count);
}

void Table_Class::Set_Column_Width(uint16_t Column_Identifier, Coordinate_Type Width)
{
    Auto_Semaphore_Type Semaphore = Graphics.Take_Semaphore_Auto();
    lv_table_set_col_width(Get_Pointer(), Column_Identifier, Width);
}