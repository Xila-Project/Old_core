#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Class_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_void) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_Graphics_TypesDialog_Class) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_void) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_void_bool) },
};

static be_define_const_map(
    Berry_Dialog_Class_map,
    6
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Dialog_Class,
    1,
    NULL,
    Dialog_Type
);
