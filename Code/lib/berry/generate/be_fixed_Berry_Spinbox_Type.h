#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_E9799677_67F7_4E99_B3FE_BCE084B9E655) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_2FB8B1D0_7CAE_4588_94DA_CA7E58337670) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_CF7B38E8_7A61_4222_8401_718B8832039F) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_AA7B86A3_B059_4792_AB5F_A30D9441E2AD) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_3C8421C1_992C_4FCD_8EF4_DB80F7AC2A60) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_6F6EE27B_6B1E_4366_8BFB_26CF70848917) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_9DE70406_97F9_4511_8F84_5C19D1B0907C) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_578DE08A_4CAF_4919_8534_816462E71013) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_9797D81A_2549_470B_88D9_8FFE8B64209B) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_0379CCE2_1DBE_4D78_8926_5B899244AA22) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_10784051_342F_4590_A10D_713601F8173C) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_D7123E09_6E00_4563_B09B_3CEA7CE896E2) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_B919AA61_9D9E_43F2_AC8E_CB0B271B97E8) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_AE00B8DF_5D1A_4C03_882B_EF18CF9B1B38) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_3734BFB5_C6DF_4882_BB7D_CF719EBC482B) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_909F43C1_694D_408F_87FE_220483E306C3) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_D3435241_4E5E_49E2_ACB2_059C2C1C7E7D) },
};

static be_define_const_map(
    Berry_Spinbox_Type_map,
    18
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Spinbox_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Spinbox_Type
);
