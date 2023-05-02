#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Class_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_void) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_void_char) },
    { be_const_key(Set_Text_Static, 6), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_void_char) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_Graphics_TypesCheckbox_Class) },
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Create, 4), be_const_ctype_func(Berry_Checkbox_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_void) },
};

static be_define_const_map(
    Berry_Checkbox_Class_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Checkbox_Class,
    1,
    NULL,
    Checkbox_Type
);
