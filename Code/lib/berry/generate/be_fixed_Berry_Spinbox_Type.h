#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_8F35D17C_522E_4EFD_8442_E294F0D9FC90) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_5E040510_7974_4E72_B976_93E8041C62DA) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_A38541FA_47F7_427D_B180_35ABE542A73F) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_0F310E1E_736B_451D_849E_28283C78D608) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_72B99B62_FB65_4C5B_8904_A9CC13E429F1) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_A4D2F89F_1086_4827_B7C4_2AFF33AEEFB0) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_70E45771_88BC_420D_9B10_33FD6C379C5A) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_B21EE1C8_E966_43AA_9894_1D34C73FBAA9) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_4DC4C9EA_F243_4CDB_8BFA_36FCC3EBEF1F) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_5A7C9CE9_3C58_4568_A8A3_8BC53F5EE61E) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_4C15D70B_9BBE_485C_B9D8_51201B1B5ECF) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_6A1FBFC7_E4A7_44E2_9232_B8F1F8BBE48D) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_9EE1612D_83FC_4FAE_A210_E806EEC283BB) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_73F36C6A_5A85_4F14_BF73_69C100551DA1) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_B4B845E9_CE65_4C77_AFE2_8505864720B8) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_FB7D4E90_A866_42AD_A76B_1FE107ED23EC) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_6B62309B_9AF8_4BB3_8229_381CBFF0BF8F) },
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
