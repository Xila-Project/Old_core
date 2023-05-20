#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_0DC36F34_DE22_4B0F_914F_402438B13644) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_25A46B55_38D4_4F95_8E43_F680D8DEF9AA) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_E8908F86_D8DE_40D4_9A2B_E6DF4DBBF2B5) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_C65E3106_4950_43F7_BBE1_78E9991F773B) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_164D68AD_6D07_4691_96E9_1943C797D02F) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_AF5C9EFE_6FEA_4C33_B136_A934C494A9A7) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_2DBEB035_464B_4F7C_A728_5BD4577CFF5C) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_C41D94F5_2845_471F_BE6A_AA6A5639A6CC) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_763482E3_E6C5_4C7E_B96A_2A552D909A48) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_78457B9C_8A96_4973_B9EF_2314CDE570DE) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_6FF761FC_BFBD_490A_8DD7_696B49F62ED7) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_61965F5A_3AEA_4E75_85D5_0FCCB554275F) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_3096B82E_3BCE_4E7E_A243_50D5AE5385D6) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_40841D23_D15F_468C_BE73_D76392D3E058) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_2B2A027A_165F_4CAB_8794_41556C37AD57) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_95946F97_C28B_4A1C_A6D9_A811A59A2786) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_E11D6AA4_BF6A_4502_B66E_1D1CE522384D) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_5BAF7C72_E181_4C49_92D8_A3270341003D) },
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
