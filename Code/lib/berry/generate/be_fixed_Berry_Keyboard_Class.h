#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Class_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_Keyboard_Class_Initialize_Graphics_TypesKeyboard_Class) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_void_uint16_t) },
    { be_const_key(Set_Text_Area, 12), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_void_Graphics_TypesText_Area_Class_bool) },
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_void_bool) },
    { be_const_key(Set_Pop_Overs, 14), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_void_bool) },
    { be_const_key(deinit, 13), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_void) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_void_Graphics_TypesKeyboard_ClassMode_Type) },
    { be_const_key(Get_Text_Area, 1), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_void) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_void) },
    { be_const_key(Set_Map, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Map_void_Graphics_TypesKeyboard_ClassMode_Type_char_Graphics_TypesButton_Matrix_Control_Type) },
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_void) },
    { be_const_key(Get_Map_Array, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Map_Array_void) },
};

static be_define_const_map(
    Berry_Keyboard_Class_map,
    15
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Keyboard_Class,
    1,
    NULL,
    Keyboard_Type
);
