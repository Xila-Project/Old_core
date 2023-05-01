#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Class_map) {
    { be_const_key(Set_Pointer, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Pointer_void_lv_obj_t) },
    { be_const_key(Set_Digit_Format, 15), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_void_uint8_t_uint8_t) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_void) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_void_uint8_t) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_void_bool) },
    { be_const_key(Decrement, 2), be_const_ctype_func(Berry_Spinbox_Class_Decrement_void) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Rollover, 8), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_void) },
    { be_const_key(Create, 18), be_const_ctype_func(Berry_Spinbox_Class_Create_void_Graphics_TypesObject_Class) },
    { be_const_key(Get_Value, 1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_void) },
    { be_const_key(Get_Step, 11), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_void) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_void_int32_t_int32_t) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_void_Graphics_TypesDirection_Type) },
    { be_const_key(init, 4), be_const_ctype_func(Berry_Spinbox_Class_Initialize_Graphics_TypesSpinbox_Class) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_void) },
    { be_const_key(Step_Previous, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_void) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_void) },
    { be_const_key(Set_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_void_uint32_t) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_void_int32_t) },
};

static be_define_const_map(
    Berry_Spinbox_Class_map,
    19
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Spinbox_Class,
    1,
    NULL,
    Spinbox_Type
);
