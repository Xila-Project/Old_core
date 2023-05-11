#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_FF71BC8D_30C4_4DC7_9C73_CE402E831730) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_E7AEADC8_EB96_4835_99EE_8AA51711D636) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_F09B94A8_2670_4613_BA43_F35E4B97273C) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_F4CDB705_EFB2_4281_8990_BED8EF5A4D1F) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_3FC84265_B446_4FBD_9568_A0C724A59963) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_AD3FE2D4_6C08_449F_8C3D_4ACBE94C4F94) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_522A5C3D_02E6_4FF3_A03F_AD8DEEBB162F) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_4F137754_413D_4506_AD54_CC62C2E21DF6) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_840485E6_1B35_45F2_8F96_EAD0E50B398A) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_B568F6E3_7951_4BF0_97BF_A293B84DB794) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_29B5DCC9_7CD7_419B_97CD_A2DC09F2E67C) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_61B1F52C_DA65_402D_83E7_9A43916464E9) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_00CA7A36_34C8_48EE_8E22_0B375CE0D4DA) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_C370680F_5EE1_4C93_AB9C_1B6B07FCE007) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_35E9BD67_B61D_4E77_8186_B80D94555355) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_AE177E5B_8036_4D17_9A41_EFEAD930B55C) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_A93216F5_D7FE_493A_90F6_917CC3F5EFAB) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_4F1682DF_9EF7_458D_838C_DFEA254B2BB3) },
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
