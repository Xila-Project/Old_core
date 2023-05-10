#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_CF70EEF8_F2C9_49FD_B1BE_3B2C8CCAF63B) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_2F8AC238_E84C_4391_A165_B725C7E2077C) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_35A95F4C_50D8_46C7_A758_B2349F912F59) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_F687269F_81D0_4966_8E40_45A0CFB93F6F) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_0B29FCD0_EA7A_479D_9713_40F728AD44F7) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_A00AD9E7_4470_446D_83AA_22D6D85700B1) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_6910B8CC_61B6_45EC_AE9B_C5BB93B0325C) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_8B7C74B2_1AB4_479A_A196_3EB25E4F0C9E) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_68B10CFB_055B_45C6_9806_13A270A46322) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_9B98CC52_E191_410B_BF0D_4811A6E20346) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_50A4F2D3_64E9_4473_BDB1_6EA4926D66A0) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_CE9E74AB_305C_4058_8D13_6B097C491550) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_80C467F1_D5C9_4301_B317_46F6C7BB9A5B) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_B3F9C872_541D_405C_98D0_63ED175C1F33) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_45FC09D3_73F7_4A33_B1CF_7BF688932D53) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_09C3E444_58D9_4D13_BAA4_45DA59F80EE8) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_875A80D8_2FD6_404D_A04A_73B970270117) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_D5F65BFE_3A46_4AD3_BC47_B2651A823A25) },
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
