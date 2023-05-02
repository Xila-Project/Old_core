#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Class_map) {
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_void_uint16_t) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_void_uint16_t_uint16_t_Graphics_TypesTable_ClassCell_ControlType) },
    { be_const_key(Set_Column_Width, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_void_uint16_t_Graphics_TypesCoordinate_Type) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(Set_Column_Count, 9), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_void_uint16_t) },
    { be_const_key(Get_Column_Width, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_void_uint16_t) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_void_uint16_t_uint16_t_Graphics_TypesTable_ClassCell_ControlType) },
    { be_const_key(Get_Cell_Value, 17), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_void_uint16_t_uint16_t) },
    { be_const_key(Get_Row_Count, 10), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_void) },
    { be_const_key(Set_Cell_Value, 12), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_void_uint16_t_uint16_t_char) },
    { be_const_key(_p, 7), be_const_var(0) },
    { be_const_key(Clear_Cell_Control, 2), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_void_uint16_t_uint16_t_Graphics_TypesTable_ClassCell_ControlType) },
    { be_const_key(deinit, 6), be_const_ctype_func(Berry_Table_Class_Deinitialize_void) },
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Table_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Get_Selected_Cell, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_void_uint16_t_uint16_t) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Table_Class_Initialize_Graphics_TypesTable_Class) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_void) },
    { be_const_key(Set_Cell_Value_Format, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_Format_void_uint16_t_uint16_t_char_) },
};

static be_define_const_map(
    Berry_Table_Class_map,
    18
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Table_Class,
    1,
    NULL,
    Table_Type
);
