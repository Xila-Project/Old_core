#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_831C83BB_2CE1_4247_97A2_796E95BD22E5) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_19D135A4_4A23_45E6_9D89_B674A8F160CA) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_EEBD8E57_3A4E_43F2_84D0_5A33DD1470A0) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_7D3A2C54_5C4D_43C1_91C5_80C141CD9CA5) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_297ABF47_25CE_4659_B370_89E3DB93632A) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_BB7BEAF8_0CF8_4CEB_AF87_F59FD0146A78) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_C862E6FA_615C_4DEF_85F5_609FF790177C) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_BA7EE16D_AD3B_4084_A4AF_C30B96D8C26B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_6DE56842_2BED_4012_BA29_AC3D68A3530C) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_32AC4216_FF97_4FDD_8EC8_1625A9A4BF93) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_366675B5_6CE6_4DA5_8CCC_C8134BA93F50) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_C596F736_A6D4_4DF1_898E_2027141D8C50) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_7E262BC9_958D_42D7_BD27_10205ABAEE12) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_DDDEF440_8FB3_4087_99E5_5B1B1807411C) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_5FA77125_7975_4012_8920_0B3F82293A67) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_C9C64979_7CFD_4FB5_A6E7_C8732329B394) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_B1D391E0_483E_454C_8155_BD4BF005EE91) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_2BF4A32D_CAE6_498F_A27D_43DF50887488) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_3B52B67A_A55F_4962_AAC4_0FBFE2B2E99E) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_F3CA7627_3DDC_46AF_B4D8_B870034659F9) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_C95EBCAB_4089_4BD8_9DD9_358CB82A411A) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_CA1CD4AC_65EB_4FC4_BDB2_98D3B3CC0FC5) },
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
