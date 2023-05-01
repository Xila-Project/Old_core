#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Class_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_Graphics_TypesButton_Class) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_void_Graphics_TypesObject_Class_String_Type_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type_Module_Type_Graphics_TypesEvent_Code_Type) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_Button_Class_Deinitialize_void) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Pointer, 1), be_const_ctype_func(Berry_Button_Class_Set_Pointer_void_lv_obj_t) },
};

static be_define_const_map(
    Berry_Button_Class_map,
    5
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Button_Class,
    1,
    NULL,
    Button_Type
);
