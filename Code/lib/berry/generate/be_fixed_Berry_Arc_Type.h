#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_E32D6633_C613_4CC6_8ECB_C4FDFDF2B4D6) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_14E36646_285B_414B_98A0_C20692E9510B) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_0E18C5EC_A291_4B7E_A066_F746E751FF2E) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_F0DBEC47_F1D9_4543_9EE0_A68E8D08064C) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_67486E0E_BDBE_49A7_A96F_D9F66DE2C280) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_E8B9BBA4_DD56_4A46_9653_BFCFAB4D2F88) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_EEAB0E7A_6649_41D0_B4F5_A4D8932EE464) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_697D8370_2D91_4C4A_85FF_CADAA041DFB0) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_A3D7A999_FC05_4391_A961_1C52C525B17D) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_AAB3F3EA_696D_4C6E_A5F0_5F8837081D09) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_FC1F6A9B_C025_481C_9225_2F4E51F8C8B1) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_F11F2F65_B6D5_45C9_8474_07BCDD715EA6) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_B903F950_C393_4EF7_AF32_07FC8D038ADE) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_993E3D12_11A4_4F8F_85FB_485E0E0E7FED) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_DD8065BE_EC82_4D33_AC08_D4F1E7969B1C) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_D798686C_25DD_433D_B2AF_4441BB9912B5) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_9ECBF370_CBE4_4B2E_9BF2_1AF6B44EAA65) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_32219222_14C8_47FF_A44C_C9697E450A1B) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_D2532025_351E_40B3_A091_8FDEE5B107C2) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_5216B38F_BE8E_4201_BB35_AA05E0E83549) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_11F4CBA6_9766_4D1E_AAA6_6FCA8E9A5CEE) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_DFAD3666_DC5F_4979_995D_E4DC3FC63401) },
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
