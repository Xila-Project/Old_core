#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_D117A731_16A0_441E_8912_450A9BBF2075) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_A8C5881F_065A_4805_BE52_48D81CDE5E30) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_8FA3A526_94D9_4430_AF27_8E7CE6AB7C8B) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_410823AD_F8D5_4B9F_99D3_13CA4F294D9D) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_3DBC01AE_832B_4CA1_9A17_087DE4D626FB) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_2F4ED7DD_3326_42A2_9D8F_DB812FEFD878) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_0E05505C_1E43_4F39_8144_1A9D77E00449) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_3917826A_BF6F_4B52_8F78_0C42535293BD) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_4671AB2A_7887_43CD_B64D_5DDBFC294F51) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_3283BB65_69B6_417F_B517_E35888F478A6) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_AD56350A_9B05_4A1A_AEE9_29E1B9079092) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_4E6ACB85_A779_4D1A_8823_A99BF65EBDA5) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_F0960927_B474_481F_A58E_2BB839B781A0) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_7FF5B804_CDB5_48FB_89DA_668344DEB358) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_9DCC6E80_8F13_4532_B073_DFDDAB7E1A71) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_1EF809D5_8FF8_4C3C_85A6_28BD8DBF9D41) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_635CB1E5_4803_460E_B751_74F587E63BC9) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_16F37E33_7E72_44A6_882D_032173477A82) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_63BEBA26_106B_4945_956D_54017FDDE140) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_DDB6B8A4_76C4_43A1_9B87_4F63BF1BC268) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_29DD2A2D_8D97_4689_97A4_47172E2DF7BA) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_6F52728E_DE0E_472C_9A8B_60DB94E09EB9) },
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
