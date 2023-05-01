#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Matrix_Class_map) {
    { be_const_key(Set_Button_Control, 1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Control_void_uint16_t_Graphics_TypesButton_Matrix_Control_Type) },
    { be_const_key(Set_Button_Control_All, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Control_All_void_Graphics_TypesButton_Matrix_Control_Type) },
    { be_const_key(_p, 0), be_const_var(0) },
    { be_const_key(Set_Button_Width, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Button_Width_void_uint16_t_uint8_t) },
    { be_const_key(Set_Pointer, 7), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Get_One_Checked, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Get_One_Checked_void) },
    { be_const_key(Set_One_Checked, 11), be_const_ctype_func(Berry_Button_Matrix_Class_Set_One_Checked_void_bool) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(Set_Control_Map, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Control_Map_void_Graphics_TypesButton_Matrix_Control_Type) },
    { be_const_key(Clear_Button_Control, 4), be_const_ctype_func(Berry_Button_Matrix_Class_Clear_Button_Control_void_uint16_t_Graphics_TypesButton_Matrix_Control_Type) },
    { be_const_key(Clear_All_Buttons_Control, 17), be_const_ctype_func(Berry_Button_Matrix_Class_Clear_All_Buttons_Control_void_Graphics_TypesButton_Matrix_Control_Type) },
    { be_const_key(Set_Map, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Map_void_char) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Deinitialize_void) },
    { be_const_key(Get_Popovers, 16), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Popovers_void) },
    { be_const_key(Has_Button_Control, 13), be_const_ctype_func(Berry_Button_Matrix_Class_Has_Button_Control_void_uint16_t_Graphics_TypesButton_Matrix_Control_Type) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Initialize_Graphics_TypesButton_Matrix_Class) },
    { be_const_key(Set_Selected_Button, 19), be_const_ctype_func(Berry_Button_Matrix_Class_Set_Selected_Button_void_uint16_t) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Selected_Button_void) },
    { be_const_key(Get_Button_Text, 5), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Button_Text_void_uint16_t) },
    { be_const_key(Get_Map, -1), be_const_ctype_func(Berry_Button_Matrix_Class_Get_Map_void) },
};

static be_define_const_map(
    Berry_Button_Matrix_Class_map,
    20
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Button_Matrix_Class,
    1,
    NULL,
    Button_Matrix_Type
);
