#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_0A849ACF_649E_4D5E_835E_804C19F15BDA) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_A2247FF6_64D3_41E3_9756_44B3FD7DEB86) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_AEFAD586_A5F0_4801_B418_CF7DCE11E9A6) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_D9BE2C7D_36DC_476C_A6B4_BDCEBD5F4605) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_5B64BB44_F919_4354_A3EC_277491D2E45E) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_5BC0B538_7406_406C_ADC0_02D74E9E565E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_AF30FEF3_8BAC_4743_A2BB_B8E89B469E6F) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_B50184B0_1D9A_46CD_8F6D_37BA8E4E12F9) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_B05AAA85_07D2_4CF5_8F0E_F76419F9FA46) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_84942108_642E_4C31_A8D7_4C496C202964) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_488E747E_D18B_40FE_B5D1_FA88541DA968) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_E4EC2420_6CF7_44D4_AC90_CDDD8757DF89) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_05A5D56E_FFFA_42C6_95EC_AEB8FE735D81) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_91568358_F0AB_40DF_9D59_5CB3F38BCE38) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_03B458A9_1129_48F3_ADBF_7C8B8ACFE295) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_C20492FC_C872_4572_AE68_CF9AF66BEC26) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_5746B7D8_61F2_440A_8F74_ABB64EBABC2C) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_3EB33AF1_7384_4090_8B51_B83A4E46BABC) },
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
