#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Class_map) {
    { be_const_key(Set_Long_Mode, 15), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_void_Graphics_TypesLong_Type) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_void) },
    { be_const_key(Insert_Text, 6), be_const_ctype_func(Berry_Label_Class_Insert_Text_void_uint32_t_char) },
    { be_const_key(Is_Char_Under_Position, -1), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_void_Graphics_TypesObject_ClassPoint_Type) },
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Label_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Set_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_void_uint32_t) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_void) },
    { be_const_key(Set_Text, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_void_char) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_void_uint32_t_Graphics_TypesObject_ClassPoint_Type) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_Label_Class_Initialize_Graphics_TypesLabel_Class) },
    { be_const_key(Get_Selection_End, 21), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_void) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_void_uint32_t) },
    { be_const_key(Get_Recolor, 0), be_const_ctype_func(Berry_Label_Class_Get_Recolor_void) },
    { be_const_key(Cut_Text, 4), be_const_ctype_func(Berry_Label_Class_Cut_Text_void_uint32_t_uint32_t) },
    { be_const_key(Set_Text_Format, -1), be_const_ctype_func(Berry_Label_Class_Set_Text_Format_void_char_) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Recolor, 10), be_const_ctype_func(Berry_Label_Class_Set_Recolor_void_bool) },
    { be_const_key(Get_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_void) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_void) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_void_Graphics_TypesObject_Class_String_Type_Graphics_TypesCoordinate_Type_Graphics_TypesCoordinate_Type) },
    { be_const_key(Get_Letter_On, 5), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_void_Graphics_TypesObject_ClassPoint_Type) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_void_char) },
};

static be_define_const_map(
    Berry_Label_Class_map,
    22
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Label_Class,
    1,
    NULL,
    Label_Type
);
