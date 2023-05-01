#include "be_constobj.h"

static be_define_const_map_slots(Berry_Color_Wheel_Class_map) {
    { be_const_key(Set_Pointer, 10), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Get_Mode_Fixed, 4), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Mode_Fixed_void) },
    { be_const_key(Set_Mode_Fixed, 0), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Mode_Fixed_void_bool) },
    { be_const_key(Set_Color, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Color_void_Graphics_TypesObject_ClassColor_Type) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Set_Mode_void_Graphics_TypesColor_Wheel_ClassModeType) },
    { be_const_key(Get_Color, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Color_void) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Get_Mode_void) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Create_void_Graphics_TypesObject_Class_bool) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_Color_Wheel_Class_Initialize_Graphics_TypesColor_Wheel_Class) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Color_Wheel_Class_Deinitialize_void) },
};

static be_define_const_map(
    Berry_Color_Wheel_Class_map,
    11
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Color_Wheel_Class,
    1,
    NULL,
    Color_Wheel_Type
);
