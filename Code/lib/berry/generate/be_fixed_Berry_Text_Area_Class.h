#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Class_map) {
    { be_const_key(Get_Text, 2), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_void) },
    { be_const_key(Set_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_void_uint32_t) },
    { be_const_key(Get_Maximum_Length, 28), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_void) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_void_bool) },
    { be_const_key(Cursor_Up, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_void) },
    { be_const_key(Get_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_void) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cursor_Click_Position, 24), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_void_bool) },
    { be_const_key(Delete_Character_Forward, 21), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_void) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_void_bool) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_void) },
    { be_const_key(Set_Text, 23), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_void_char) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_void) },
    { be_const_key(Clear_Selection, 29), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_void) },
    { be_const_key(Cursor_Right, 33), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_void) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_void_uint32_t) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_void) },
    { be_const_key(Get_Placeholder_Text, 0), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_void) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_void_char) },
    { be_const_key(Is_Selected, 34), be_const_ctype_func(Berry_Text_Area_Class_Is_Selected_void) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_void_bool) },
    { be_const_key(Cursor_Down, 25), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_void) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_void_int32_t) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_void) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Text_Area_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(Set_Insert_Replace, 32), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_void_char) },
    { be_const_key(Set_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_void_char) },
    { be_const_key(Set_Text_Alignment, 4), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_void_Graphics_TypesText_Alignment_Type) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_void_uint16_t) },
    { be_const_key(init, 35), be_const_ctype_func(Berry_Text_Area_Class_Initialize_Graphics_TypesText_Area_Class) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_void) },
    { be_const_key(Cursor_Left, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_void) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_void) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_void) },
    { be_const_key(Set_Pointer, 36), be_const_ctype_func(Berry_Text_Area_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Get_Cursor_Click_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_void) },
    { be_const_key(Get_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_void) },
    { be_const_key(Set_Placeholder_Text, 31), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_void_char) },
};

static be_define_const_map(
    Berry_Text_Area_Class_map,
    38
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Text_Area_Class,
    1,
    NULL,
    Text_Area_Type
);
