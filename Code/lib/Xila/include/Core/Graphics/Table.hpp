///
/// @file Table.hpp
/// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
/// @brief
/// @version 0.1.0
/// @date 04-05-2022
///
/// @copyright Copyright (c) 2022
///

#ifndef Table_Hpp_Included
#define Table_Hpp_Included

#include "Object.hpp"

namespace Xila_Namespace
{
    typedef class Table_Class : public Object_Class
    {
    public:
        // - Types

        class Cell_Control
        {
        public:
            /// @brief Cell control type.
            typedef lv_table_cell_ctrl_t Type;

            /// @brief Cell control enumeration.
            enum Enumeration
            {
                Merge_Right = LV_TABLE_CELL_CTRL_MERGE_RIGHT,
                Text_Crop = LV_TABLE_CELL_CTRL_TEXT_CROP,
                Custom_1 = LV_TABLE_CELL_CTRL_CUSTOM_1,
                Custom_2 = LV_TABLE_CELL_CTRL_CUSTOM_2,
                Custom_3 = LV_TABLE_CELL_CTRL_CUSTOM_3,
                Custom_4 = LV_TABLE_CELL_CTRL_CUSTOM_4,
            };
        };

        /// @brief Draw part enumeration and type.
        typedef enum Draw_Part_Enumeration
        {
            Cell = LV_TABLE_DRAW_PART_CELL, /**< A cell*/
        } Draw_Part_Type;

        // - Methods

        // - - Management
        void Create(Object_Class Parent_Object);

        void Add_Cell_Control(uint16_t Row, uint16_t Column, Cell_Control::Type Cell_Control);
        void Clear_Cell_Control(uint16_t Row, uint16_t Column, Cell_Control::Type Cell_Control);
        bool Has_Cell_Control(uint16_t Row, uint16_t Column, Cell_Control::Type Cell_Control);

        // -- -- Getters.
        const char *Get_Cell_Value(uint16_t Row, uint16_t Column);
        uint16_t Get_Row_Count();
        uint16_t Get_Column_Count();
        Coordinate_Type Get_Column_Width(uint16_t Column);
        void Get_Selected_Cell(uint16_t *Row, uint16_t *Column);

        // - - Setters.
        bool Set_Pointer(lv_obj_t *Object);

        void Set_Cell_Value(uint16_t Row, uint16_t Column, const char *Value);
        void Set_Cell_Value_Format(uint16_t Row, uint16_t Column, const char *Formated_Value, ...);
        void Set_Row_Count(uint16_t Row_Count);
        void Set_Column_Count(uint16_t Column_Count);
        void Set_Column_Width(uint16_t Column_Identifier, Coordinate_Type Width);
    } Table_Type;
}

#endif