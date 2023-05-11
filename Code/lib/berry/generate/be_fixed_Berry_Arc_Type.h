#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_DB093F57_B253_4CE3_BF46_F42A84BF5B98) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_844F82F8_D59D_4C7E_882A_4672E807EA2E) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_F2D914BC_581E_42BF_B49C_D7E1EA416BB4) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_1D469201_710B_4364_92BE_2A383CFB22D7) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_5EF5E906_2F60_4B0E_9BF9_7792BC24EFB1) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_FD2CD751_52AC_4C54_A736_706F4ED50BA5) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_8E0DB5A8_D16D_4022_8BAB_68D1CC44CF6C) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_02C84A35_1BBC_45C4_917F_3334DFB6B11B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_0ED836AF_30D4_4887_A77E_BE6CAA7EE301) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_C8C70F85_B30A_42F0_8F8C_517AFDD1FFFA) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_22C43DB5_9FAD_45DF_BD99_A5428211C791) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_2A4C1EED_9850_437B_98FF_BDF6BEC842CA) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_600F4764_41D3_4FF4_8655_657A9C9FAAA2) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_AF836F2E_3979_4C61_96EE_D64BBE6572C5) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_E862E2A5_A450_4CC0_826B_4990E41E5487) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_DCE967FA_4EEC_413B_96D0_E862BC15C2A4) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_8B81B889_48B4_402F_ABD8_77CB19AC9891) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_47A069E4_7523_4F5A_B129_25B32A63AB45) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_08459196_F2BB_4D02_AC83_469EA4175C03) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_961C8060_23D1_4D7C_98B4_CBE63951FDCB) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_1D517D1A_7FD5_4E7A_9DFB_F4EA9BA57A35) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_F0D25733_EA5A_4F36_9AAD_D85883A21FA8) },
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
