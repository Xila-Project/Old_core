#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_7E3A4AF1_07DF_4FD6_9E83_636221377311) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_14C2D0BA_FA51_4C55_8B95_FF96AA95C297) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_F6698072_F177_4626_AAA1_0C116F407A3F) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_2F494C3F_1CE9_4256_BDD1_BBDA25FFB773) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_8AADEBB5_AC17_4F3E_96AD_5A8CE542FA6F) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_E9A40081_04DE_4C2A_82ED_A7767177F2E8) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_B0DDEB6F_C228_4B8A_ADEC_588E4E7D2B08) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_DD9704B0_F6F4_49EB_AEBA_D0968FD96E41) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_9E387BBA_85EC_4362_8076_AFD63D78255B) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_4C37359D_8F78_465C_B87F_8A10D84792D5) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_718F81ED_6A9C_4494_AE7D_D79E2BAA6CC9) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_A953ECC3_F97E_48D7_9F6B_2E4F44125310) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_4E6CB9AA_6B43_40C4_B4FA_C02902F67826) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_D75FE2E9_2236_4493_8BD3_7A78E10D0000) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_7D7053CC_8B12_4913_9FE0_1A0A8E1C0A0B) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_EEA2D641_FD12_4A65_9C09_375A63106C4D) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_3CC867C6_4B45_4FAD_A646_96549228E230) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_E9B4095B_7DF8_4EAF_B835_FD70BC76A62E) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_650236E6_10DA_42A7_BBC0_CB03F22BFDA9) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_238B7116_87EC_4EEC_B9C3_85EC734D5489) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_E8DE1562_D2D0_4BAB_A0C8_255D9AB32374) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_BFDAD6FD_B6C9_4F91_A693_DDFDF844CB00) },
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
