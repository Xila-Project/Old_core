#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_0C7F88C6_EFE3_4115_9482_48DD7A5327A7) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_6FFBF29A_5251_4481_BD19_3C27A100C791) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_8784EC1D_65A1_4251_A7D7_CBD29C087952) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_E2C623C3_942D_4570_80A3_8E3F9AF1B60C) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_F3707C82_6F29_46C3_A975_831CBB10C8A9) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_ACB124A5_3580_42DB_B14B_DA792EBFB831) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_D617333D_5E3B_46B2_AA9C_8EFB602D7961) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_6880746C_864C_44BE_9BEA_80B55D08D7F9) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_53DF1CCE_2DD8_41E1_AEDA_0828F5F3076A) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_2CA84B12_C771_463C_B761_93C6C0EDF8B0) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_8D656C36_C5BF_4FFE_B869_2510E12CE576) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_1D090580_70CB_4DF3_9A1C_A731E0260A0A) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_0AC9B135_30AC_4C0B_9EDC_DE30F9A0967A) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_3F10C00F_6C2F_4EDB_8BC7_48B5F8603D24) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_5100DDB4_71BE_4C8A_972C_157156DB83EA) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_4D04C38A_0D9A_4B0D_B350_D0E91F9357A0) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_70E02935_EFCB_4C93_8F20_B427D6707D2F) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_02C6498E_7C6B_4534_A4B8_3BC1743E024D) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_27D5D608_3DF9_487C_94D8_F6B2EBDBA8DA) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_2F22CEFD_992C_437A_B826_A7E67A94BD4D) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_B64A9D1F_6B2A_4C0A_87B9_1D91F3009F46) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_3206DE4A_90A4_4EB7_BE9B_781917E01C88) },
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
