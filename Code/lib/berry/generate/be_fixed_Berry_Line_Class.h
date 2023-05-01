#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Class_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_void) },
    { be_const_key(Set_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_void_bool) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Points, 7), be_const_ctype_func(Berry_Line_Class_Set_Points_void_Graphics_TypesObject_ClassPoint_Type_uint16_t) },
    { be_const_key(Get_Y_Inversion, 6), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_void) },
    { be_const_key(Create, 4), be_const_ctype_func(Berry_Line_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Line_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_Graphics_TypesLine_Class) },
};

static be_define_const_map(
    Berry_Line_Class_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Line_Class,
    1,
    NULL,
    Line_Type
);
