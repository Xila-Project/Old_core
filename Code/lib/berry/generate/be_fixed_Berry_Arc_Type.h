#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_D71BCFDD_7C68_4F83_AC1F_C582821C20C2) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_52B43D4F_7D97_4E3A_8CF5_7E9007EB148B) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_51A5B938_40E3_4F58_B25F_7FF3F24B8B78) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_7B552846_01BC_4F96_93AC_4585A7A37E74) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_594A6F74_C146_4A19_BF69_AA6F743B2047) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_E04471F3_CD25_44D6_BD97_F787F8A42C96) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_57068958_2617_4B0C_9FCE_74210BD36526) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_E26D1CC0_9089_4325_B437_E1ACE8D0B5F3) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_C238BF35_46F3_4BC3_A48A_B7BAE7441C26) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_65463AC9_FF45_47D5_B2A6_D65441F8BEEB) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_0B5A498A_0F88_45EE_B7BB_2F03DC6D3391) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_78B2A380_2C1C_4624_B1FE_A80BDF6DB527) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_68591F41_AF5E_4184_99AC_C84063F52C9F) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_25A17477_B430_49EA_BDA7_EE7560011AAB) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_13E46280_CE58_4F54_B871_F1BCC7D982B2) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_D2939888_8AA1_4047_A82A_260E66CED163) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_4EDBC721_1D09_4145_953A_90EA832B90BE) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_60E153F4_B7BD_4444_B161_A39E2323E9A0) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_5FB5351A_A2EC_4F59_B309_0C4BF07A1688) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_86CEDAB6_DD2E_494A_9996_D0D4674DB786) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_44CDFCC8_2E69_44FC_A3AE_84E04DDA9EC2) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_A784EA1F_6A14_493B_8569_814BD9F41DCB) },
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
