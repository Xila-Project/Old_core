#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Class_map) {
    { be_const_key(Create, 8), be_const_ctype_func(Berry_Bar_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_void) },
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_void_int32_t_bool) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_void) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_void) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Bar_Class_Initialize_Graphics_TypesBar_Class) },
    { be_const_key(_p, 3), be_const_var(0) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_void_int32_t_int32_t) },
    { be_const_key(Set_Pointer, 9), be_const_ctype_func(Berry_Bar_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Bar_Class_Get_Mode_void) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_void) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Bar_Class_Set_Mode_void_Graphics_TypesBar_ClassModeType) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Bar_Class_Deinitialize_void) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_void_int32_t_bool) },
};

static be_define_const_map(
    Berry_Bar_Class_map,
    14
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Bar_Class,
    1,
    NULL,
    Bar_Type
);
