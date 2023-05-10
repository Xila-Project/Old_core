#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_5C3E6800_9F5B_4264_AD50_5895B73219F4) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_DF8A0015_7EF1_46B5_9674_370C9874F84A) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_81647BC2_89C5_4002_BC30_B2AF91781312) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_897E8991_B5B3_4433_9E2D_A12D18323E8B) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_B9644507_AB17_4189_8F94_86BD83134CBF) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_044B3D69_6BF8_49C5_B6D9_28218080D62B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_7C71F628_FFF7_4264_86E6_523C9B00DA98) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_09A0E0F0_1DAD_4674_B382_8AD279985773) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_C8AE3E23_FFA4_43AB_ABA0_11EF03B76570) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_CE622352_7ECB_4774_93FB_51859F235CD3) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_81C6D4CF_A7BC_48C9_8FC1_31833C2A3E05) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_E8E3B953_7190_4EBA_B8E7_F91DA2FC0C02) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_DC8E7653_B795_417A_A628_2C21171ACED6) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_0589CEFD_1072_494F_BFB8_FCD62A7FB6A3) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_48908776_334F_4E67_82D4_21767CA7F055) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_FCAAD286_1CE4_4DAB_BA2F_FA2EABF41D83) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_E5E908C9_0C03_4E11_91F7_94B9DC67AA16) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_44ABF7B0_1F88_4460_AF59_C17635F30DB0) },
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
