#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_44906A91_72E8_49EA_979D_81DCC143FA36) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_6EB70AA1_3DE0_4128_B755_58BF5B8A6066) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_EE5E20E1_194D_4C3B_BFFA_8B7D37FA06A7) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_1FF8F94B_9FF2_4E99_8439_D239B25A4B51) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_2139F3EF_929E_451B_B7C1_CB2EDC939DC4) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_91D7FD26_C2FD_4C03_B3F4_63783341A25B) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_1FCC9BC7_A2F9_41EA_8ACB_69DC77D11F60) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_E288F79C_C713_43C1_81E8_B4174F75C10F) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_AB548A9D_F464_4AA8_A71A_0ED0695AFAEC) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_8909DB6E_172A_47B3_9F67_4CBE9BEE8613) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_3F9D0618_9344_483E_8FF7_F76926E4C542) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_F1CEBD78_3A1B_4B46_8AA0_36E48CBDFE21) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_77A4F788_4CF5_4CAF_AFFE_B308AC9025EA) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_9E3806B3_2C13_4B2C_BC71_A23A85716C73) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_9B895BC1_C57B_4AB9_B73F_4BF3C24FF593) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_454380E2_8495_421A_B037_B0AA2510BCF9) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_9529AF7F_52A5_4EC2_B07C_BA51AD11D650) },
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
