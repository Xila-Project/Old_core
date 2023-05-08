#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_2126CB2F_5DCD_4403_8FF8_A0549B8DBCFE) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_A0745579_25DE_4655_AC23_C0E2BB5C1CC3) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_DD556C12_D205_47E5_A342_E780ED4E4885) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_BBCA5B63_F0AF_4618_BAEC_D5293A8976B5) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_D53F2EAB_6B1B_4255_9717_4F4218A73A24) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_B293DB5C_9B76_4D67_B97B_E726228D0002) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_1217B9C9_E960_4254_B0D7_9DAD3E1C4C7B) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_E6918775_EFE3_4891_A966_A33386CA4F66) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_70C034B1_639C_4D58_A04C_79899BAA1AD5) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_96E77393_0095_4B00_A459_2EAF3D7A3E74) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_97ACED70_6483_4A0D_AAF4_E090BF1E177D) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_E8F57146_D2ED_4F44_9FBD_0B3FE9230E32) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_C7541D57_3558_4EE6_954C_C47E68C445C9) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_D5941623_2EC7_4F3B_ADEA_3735D26B3680) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_C127656F_8A10_46F3_BF85_96E440BABDCA) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_67D9C9B3_9620_465F_9304_160CAC91F2C4) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_8EEA2298_0ABD_430C_A658_4ED9A55F5544) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_A9AAEFF9_AC19_465A_B799_D28781E4EEBA) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_BD07D5BE_3AC6_4BDB_89C2_F441AA2B45BB) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_05FA63CD_540D_47B7_8EAB_A211B3AA43C3) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_C7D3820E_3DBD_4FEF_AE67_9C6803AE2AEB) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_C5EF79C0_B9A1_49E0_9854_E5E0305154E9) },
};

static be_define_const_map(
    Berry_Arc_Type_map,
    23
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Arc_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Arc_Type
);
