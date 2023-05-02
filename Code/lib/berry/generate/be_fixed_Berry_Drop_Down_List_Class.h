#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Class_map) {
    { be_const_key(Set_Options, 11), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_void_char) },
    { be_const_key(Clear_Options, 9), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_void) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_void_bool) },
    { be_const_key(Get_Selected_Option, 6), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_void) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_void) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_void) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_void) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_void_void) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_void) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_void) },
    { be_const_key(Get_Option_Count, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_void) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_void_char_uint32_t) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_void_uint16_t) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_void_Graphics_TypesDirection_Type) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_void) },
    { be_const_key(Get_Symbol, 5), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_void) },
    { be_const_key(Open, 20), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_void) },
    { be_const_key(Set_Text, 22), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_void_char) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_void_char_size_t) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_Graphics_TypesDrop_Down_List_Class) },
    { be_const_key(Close, 16), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_void) },
    { be_const_key(Get_Options, 8), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_void) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_void_char) },
};

static be_define_const_map(
    Berry_Drop_Down_List_Class_map,
    26
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Drop_Down_List_Class,
    1,
    NULL,
    Drop_Down_List_Type
);
