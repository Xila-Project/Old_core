#include "be_constobj.h"

static be_define_const_map_slots(Berry_List_Class_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_List_Class_Deinitialize_void) },
    { be_const_key(Add_Text, 7), be_const_ctype_func(Berry_List_Class_Add_Text_void_char) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_List_Class_Initialize_Graphics_TypesList_Class) },
    { be_const_key(Create, 6), be_const_ctype_func(Berry_List_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(Set_Pointer, 4), be_const_ctype_func(Berry_List_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Add_Button, -1), be_const_ctype_func(Berry_List_Class_Add_Button_void_char_char) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_List_Class_Get_Button_Text_void_Graphics_TypesButton_Class) },
};

static be_define_const_map(
    Berry_List_Class_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_List_Class,
    1,
    NULL,
    List_Type
);
