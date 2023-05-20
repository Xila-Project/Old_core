#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_4C30B1E4_950E_447F_BA3D_4A78735A0868) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_AD61B0B0_BA46_4C49_B03E_445572E83F38) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_5F559FA6_CC18_432E_9F12_C3962C9E999E) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_BBE72345_D1D8_46C8_B7F3_FDE379CE8899) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_1AEA38CB_AF4A_4CB7_8CAB_E103084671DE) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_F7FA78FC_C924_42AC_ABDD_B16FEB185E6B) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_BF889704_5AD9_4679_9EEB_35001FB86C68) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_F26CBA3A_9924_4440_BD41_E7FD5348487D) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_E539CD6C_6E10_4E32_9684_1D94CDF77F6B) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_C97DCB3E_1E0A_48C5_8A5A_E8A01EEEB455) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_6AB5D29B_949D_4D04_B5CE_70697C8C41C6) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_1A46074C_16F4_46EA_81BD_CC23E135FD58) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_84AD5CBC_222A_4D75_A29E_025F3B57CBBF) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_6A05D1A3_C319_4A37_8253_5296014B38FA) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_7992AFCF_4E4B_4DF5_B5D4_D6EEBC64F1B5) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_577DE55B_E493_4F35_859A_EE3F2C5EDFFD) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_A75B3E29_AF37_4307_9C07_24C4AF106A3D) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_E7539623_6C78_4FDA_9B59_B3B2F3E321AF) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_C02E791C_4441_4473_81A7_8F146D5CBCC5) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_1D2C52AF_9FA3_4E5E_975C_BBC777AAC700) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_F72F379C_0C29_4DC6_BB43_C9A5F465D97C) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_638A20C8_D274_4611_81FE_45B8987EE002) },
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
