#include "be_constobj.h"

static be_define_const_map_slots(Berry_Spinbox_Type_map) {
    { be_const_key(Set_Step, 16), be_const_ctype_func(Berry_Spinbox_Class_Set_Step_A4617CFF_3EDD_4D26_8563_FF3FE39845AE) },
    { be_const_key(Get_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Rollover_2ADB6929_C777_4F7A_9442_3F79F1D6EE38) },
    { be_const_key(Get_Step, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Step_50E93914_F290_47E3_B89A_196D2F8F8FE6) },
    { be_const_key(Set_Value, 11), be_const_ctype_func(Berry_Spinbox_Class_Set_Value_A924D85D_2C87_4E0C_8BD7_3EACE60D2160) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Spinbox_Class_Deinitialize_1E993C37_1E18_490F_824E_8B7B740A288A) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Spinbox_Class_Get_Value_136075EE_D276_454B_937F_BCF3DDB41ED7) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Cursor_Position_E6B7D77B_C556_4E11_8F95_51EEBF4A9405) },
    { be_const_key(Step_Previous, 14), be_const_ctype_func(Berry_Spinbox_Class_Step_Previous_93D52E78_C713_43E9_ABF8_C82C9F366FCB) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Rollover, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Rollover_714E490F_E913_4E01_A0E6_123AEA44F691) },
    { be_const_key(Increment, -1), be_const_ctype_func(Berry_Spinbox_Class_Increment_BC1B361D_A731_439B_9916_DA1DE56BC24E) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Spinbox_Class_Create_0606CD00_83A1_480E_9A5E_633DE45A221D) },
    { be_const_key(Set_Digit_Step_Direction, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Step_Direction_DBD34327_23F5_4123_B232_AACF238DCE12) },
    { be_const_key(Step_Next, -1), be_const_ctype_func(Berry_Spinbox_Class_Step_Next_74B8AAE5_E68E_439F_AAFA_65C454F609B1) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Range_660DF80D_CA2A_4DAD_AB7C_F842F0FBFD98) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Spinbox_Class_Initialize_E11F9B6F_EC67_485A_A9A4_1D3023B3A9C5) },
    { be_const_key(Decrement, -1), be_const_ctype_func(Berry_Spinbox_Class_Decrement_EC4D6830_6FB1_4047_9110_F69BEE8973DF) },
    { be_const_key(Set_Digit_Format, -1), be_const_ctype_func(Berry_Spinbox_Class_Set_Digit_Format_8AE5D453_DA60_49C3_8DC5_2F5F924BA101) },
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
