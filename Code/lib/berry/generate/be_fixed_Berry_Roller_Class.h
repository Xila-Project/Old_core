#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Class_map) {
    { be_const_key(Set_Pointer, 8), be_const_ctype_func(Berry_Roller_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Get_Selected, 0), be_const_ctype_func(Berry_Roller_Class_Get_Selected_void) },
    { be_const_key(Get_Options, 6), be_const_ctype_func(Berry_Roller_Class_Get_Options_void) },
    { be_const_key(Get_Selected_String, 11), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_void_String_Type) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_void) },
    { be_const_key(Get_Option_Count, 7), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_void) },
    { be_const_key(Set_Options, 10), be_const_ctype_func(Berry_Roller_Class_Set_Options_void_char_Graphics_TypesRoller_ClassMode_Type) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_void_uint16_t_bool) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_void_uint8_t) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Roller_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_Graphics_TypesRoller_Class) },
};

static be_define_const_map(
    Berry_Roller_Class_map,
    12
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Roller_Class,
    1,
    NULL,
    Roller_Type
);
