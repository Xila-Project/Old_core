#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Class_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_Slider_Class_Initialize_Graphics_TypesSlider_Class) },
    { be_const_key(Get_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_void) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_void_int32_t_bool) },
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Slider_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_void) },
    { be_const_key(Is_Dragged, 10), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_void) },
    { be_const_key(deinit, 13), be_const_ctype_func(Berry_Slider_Class_Deinitialize_void) },
    { be_const_key(Set_Mode, 3), be_const_ctype_func(Berry_Slider_Class_Set_Mode_void_Graphics_TypesSlider_ClassMode_Type) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Slider_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_void) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_void) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_void_int32_t_bool) },
    { be_const_key(Get_Mode, 14), be_const_ctype_func(Berry_Slider_Class_Get_Mode_void) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_void_int32_t_int32_t) },
};

static be_define_const_map(
    Berry_Slider_Class_map,
    15
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Slider_Class,
    1,
    NULL,
    Slider_Type
);
