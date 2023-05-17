#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_D6303B75_0187_496A_B041_BA420D2F6453) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_B639457E_D869_4821_9858_56E86DC7186A) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_F88C0755_3B65_4FB4_9D2D_C63BDC2EF2EA) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_C1AE72E4_92EA_40FC_8424_AB2D6B51749A) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_23885C19_AB30_4F77_B47F_047914D68D89) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_8302990D_2FF8_4609_A2D6_3B34BA822ACA) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_EB245301_6ED5_44EE_A88D_C027836ABCD8) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_E44ED737_58EC_42E6_A98A_341AF3FBA403) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_22EE0B4F_A60F_48FA_A8FA_E274BD8866E5) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_9271FDE7_65C5_4F37_BAF9_3AB58A341686) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_189F1C4B_BF61_41BC_8AF8_7A5783BA6719) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_A31E0A6F_026B_4700_97DD_36220BBA44E5) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_14DC5A03_F6A5_451C_A21E_54769196CEA8) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_69FE2DBE_DC7A_4137_AEAF_2C4E40680609) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_F7951BC0_3785_4A39_8B66_0AD6437CB466) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_94F33C4E_57CB_4C1B_893C_15DE920B2BE4) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_C4BB5C64_E05F_4442_9E7C_4057A9621408) },
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
