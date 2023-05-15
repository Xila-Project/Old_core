#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_354FA746_2AB8_4C44_A34D_D2D923780855) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_06D854BD_4B13_45F4_B7BC_DE43AE75BCCE) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_863F2AD8_9148_499E_9EB8_10A93A2794E2) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_80ED16ED_53E3_419B_9617_EEB651DDD942) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_11806B57_3950_4BBE_8A9D_5E5D61155D5A) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_6A1BF490_8313_44FE_8B3A_6805CBD7C90F) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_EED03DDE_5FC9_44B9_80AF_86077FF2F1C3) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_907AC459_4E24_4878_A911_9062A03A48A0) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_7219DEC5_1939_4D77_A9C5_467325C917BA) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_6C9C6384_7E9A_42DD_8EE9_00D37329EACB) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_C55F2CC8_1B6D_4FB7_B91F_7C90A99F82D5) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_0E49E5DF_9345_4C2C_92F0_D6EA894086EF) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_31CA814B_3386_4E64_BD0B_ADFF8AFE82E8) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_4EFFFC01_CCC7_4D44_8D09_9C42D8A86B3D) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_B6DBAD29_B0F2_4BB1_AC0D_E82BB834E101) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_20453BFD_3CF6_4B6B_A90B_72D0AC875487) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_21A3DB19_A45E_4B93_816C_55D70B1B48EA) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_AA321EE0_F22C_4A6B_9B93_4768F00A048C) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_AA16D88B_CB55_4930_ADD4_FBE25B21714A) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_43010636_C9A6_4B84_AF26_AADB73E669BE) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_98ACBED3_5F84_4C69_B580_18E3ED8BDB64) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_32BFE497_387E_48C7_8B94_361E7BDE1785) },
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
