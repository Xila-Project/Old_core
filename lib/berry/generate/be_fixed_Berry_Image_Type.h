#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_2FC7B3E0_FFB8_42A5_B139_63ABD51B590F) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_DC611323_3D6B_4BC6_AAB3_DD5303940D88) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_9AB15FFE_50D0_4629_BAF2_6FAA20E932B6) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_BD881A68_DA73_4275_9FA4_110400E10A5F) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_14C17D1F_7A9B_479D_9888_64B63728FB31) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_0FE912EE_B597_415E_82DF_08FD8C076671) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_82F3E06E_5E4F_414C_B34E_EAB373D0D83B) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_B774F953_EB49_4188_B2EB_C4A3980E3251) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_AA7AE0BD_A37F_4A6A_A6E9_2DA6FC5D38DF) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_9DCC1A71_6813_4520_85D9_81CE43E61120) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_A6F7CCB5_4AFA_449F_87F8_387D1DB40D05) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_DED37026_68F9_43D1_9A4B_D2325FBAE961) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_32F6B1EE_5DA3_41E8_B1B1_D6F1CE3ED34A) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_AC223681_ADBD_452D_9005_371562A91166) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_3670F67B_7358_4935_9E53_9EB263B29947) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_C11A19C5_1F4C_44A0_A2B7_ADD25DF41D8E) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_B6D97F7D_D2EC_48EA_BD1B_63BE7BCAAE82) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_66EF0FDB_8129_4821_B550_2D3CFAD85A29) },
};

static be_define_const_map(
    Berry_Image_Type_map,
    19
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Image_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Image_Type
);
