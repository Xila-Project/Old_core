#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_2C7A7DDD_7091_45F3_ACA5_68C61E9F99C6) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_77FA1363_2869_40AF_813B_60D4D75B136A) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_3DE28B02_9E8B_4E89_91DF_9A9AD301ACB7) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_F4EC2BE3_2A35_4171_B0A8_206EA16E95E3) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_C3CADBD1_BEA9_46D2_BEDD_83705761D9A8) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_F9D4D351_30B4_422A_86D1_29E8FA2E024D) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_83C4233D_387B_4BE4_9970_93F2DBE55D56) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_80398B89_CF52_4A3F_B57C_E88704A16275) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_BB57297B_DEF4_4B1A_9908_0E6CA4581C4E) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_17AA92EC_D202_4F5A_969E_E5B8CD320BB3) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_C97B1661_363B_4BA4_A521_255426A55B31) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_537C209F_BA3D_4E80_9A42_2007B1E3894B) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_418C7F6D_6500_476E_BD18_964E73259802) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_47D26B35_52F2_4340_9A1A_559D072D34AE) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_58106BE4_0625_461E_9948_76882867B1B4) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_61AA8D86_F035_42E9_802E_B25DD96631EA) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_637F3213_A2D7_4B3D_8D42_07A59968DD99) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_8E34BA92_FA14_4222_A6F8_490AB6F298DD) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_98471AE1_25E4_4C99_A82B_B90D834CEA01) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_2527D3BF_40A1_4A4B_B65E_81D485115074) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_88544A2C_1832_4017_98DA_C54A19485DFB) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_779F644E_ED7D_4B5B_AC24_371248CACDFA) },
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
