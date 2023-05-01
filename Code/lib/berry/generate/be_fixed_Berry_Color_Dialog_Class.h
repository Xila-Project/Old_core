#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Dialog_Class_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Color_Dialog_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Color_Dialog_Class_Initialize_Graphics_TypesColor_Dialog_Class) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Color, 1), be_const_ctype_func(Berry_Color_Dialog_Class_Set_Color_void_Graphics_TypesObject_ClassColor_Type) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Dialog_Class_Deinitialize_void) },
    { be_const_key(Get_Color, -1), be_const_ctype_func(Berry_Color_Dialog_Class_Get_Color_void) },
};

static be_define_const_map(
    Berry_Color_Dialog_Class_map,
    6
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Color_Dialog_Class,
    1,
    NULL,
    Color_Dialog_Type
);
