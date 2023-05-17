#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_1415D7D6_4624_4518_96F4_413344EC5395) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_9D70E267_61AB_44A7_8DE0_0BBA45B2E1F8) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_65761CA6_3AAD_49CA_84A2_4E99E0E29416) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_0A83AE7B_18DF_4F84_8268_6D0CDA5D6BFC) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_4521EDEF_B7C3_4E1E_8B00_FBD213591E93) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_1522C48B_1944_45D8_A9B6_24181A977E23) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_C9187A4F_0C51_4D4B_9373_3C481C09A21A) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_D99F0882_3C61_42C8_928E_823694073278) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_38323A05_3371_4E16_A7A4_390E41328FB5) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_EF7877BB_97BE_4116_9487_F9606FE4674D) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_4778BF18_CFBD_4CC7_8E7E_545CF16D262D) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_75C5AD29_C3EF_4219_AA31_32EE5B105D88) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_511FB6B9_61C5_4CD9_8C0F_9ADCB3184FE4) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_9BA24049_8A6B_454F_9381_8C006BBC7ED9) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_A7FF18DB_A8E5_4338_9F21_9066EC04412E) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_DAC54538_F55A_4563_99D3_6A5D9A2064A7) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_C02B0927_31CD_46B1_9197_6D4655185196) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_B761FCAB_0FB9_4565_9FAF_8AA6434F1461) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_A3E9F064_0088_4F46_950B_BCFFEFC0E63B) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_C18820A1_F31F_42EF_8B91_63C2F301D3C4) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_922B9832_6597_473F_AEFB_3119642709E6) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_165555D9_9AC6_4818_B9D1_C39D886ADE3B) },
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
