#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_55A9A67F_1838_4BB3_A172_63952C6C813B) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_B4548636_A911_4AFF_8190_53165C41A518) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_51FA1801_9DA9_455A_B214_663615F62164) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_7B5063EE_8416_4B29_95A8_DEE9901CE5A7) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_7008BB9A_FA3D_4272_BCFB_541E05992EA7) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_C166C4B8_C41E_4421_8127_685ACFC9ABD4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_B348A3E6_3DDC_4952_904C_645E6BEB17C9) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_9E4AAC0E_63E8_4010_A79A_10C1703E94D2) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_9868382E_1302_4B7B_B2CE_D8D37109839A) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_D40EB4C9_7900_4998_8377_D91A21AAB506) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_19DA48D6_31A0_44F7_A1AE_AFA43DD85B7D) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_6BBBF583_C280_488E_8A32_86F4B2402E80) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_F9761A57_A07B_4F21_BBD4_09D009B34E78) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_E57FBBAE_B8AF_42EE_BFB3_FCD7155DF23B) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_B98D2CF3_1999_4A99_A6BB_7AD87C225B7F) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_E298BEFE_F5BC_4880_8C7D_34F68439A283) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_BE2A8FE6_7337_4A46_B12D_52A5CC192E74) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_40878AAE_1A5C_4A17_9DE2_DB271A54BBE3) },
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
