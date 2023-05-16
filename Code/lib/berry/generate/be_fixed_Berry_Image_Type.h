#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_BDDFCD05_8831_49B1_896B_4108B46007E2) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_4F6081FE_2E56_4BB4_B24C_577F7177AF51) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_F6C9C84D_6E78_443D_A351_C993C346EB4F) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_CA4E6AEE_6D8B_4872_B713_1990FC7494D8) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_C38D5C09_98AE_4BC7_AC7F_869F636D9521) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_FBFF8E5C_7564_44EE_8E34_71F1EC53457C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_AD65AE9C_C82D_4980_9C23_09FF03D21182) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_AFDB9766_3576_4B74_A838_856386862DD3) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_747C7130_F1A4_4CE4_947B_ABA0C02D5E2D) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_200DD019_BF1C_40E8_B714_F88B9F7A0505) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_788478CB_4B32_46E4_97EF_EE8A0DD38BC9) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_E02AE3AE_6534_4532_8B31_664407167367) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_3C07B3E6_169E_473E_B64C_DB94621BA929) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_C894A72C_E7D7_4C92_A430_BDE5D36C9F20) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_368E87A7_F8C8_40B6_8294_44C98D28470F) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_C50187EE_4FA0_4B6C_B8FB_E321730C731D) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_7DCEE544_DE37_47A0_885F_28CAA98F23F4) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_3B05A017_8B00_4A6B_8A41_33EC1F3B3D59) },
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
