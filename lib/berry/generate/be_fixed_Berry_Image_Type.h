#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_7A62EDB2_5B81_44BF_8919_833D7AB47329) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_FBE29713_9D0D_46C3_96C0_4957362F9E6F) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_4EFD87E5_3DF2_4EC7_BB38_88CBC3D731A1) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_FA55ED73_BE3E_4AD5_8C38_AA22D99B0BB0) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_95B9FB8C_F8F5_44AA_BDD5_E34643B31351) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_FD802312_6FDD_41B7_83A0_D2E6406DE90D) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_C6FF5DE7_E1A6_42A3_B7F9_74B0C758EAB8) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_A4F1137A_DB27_4995_9590_D53D02E61A0F) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_8F264F13_F679_41A0_9B59_6BAF4173FF9D) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_5EAF06CD_CED1_4C56_87AD_455306A0EFC6) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_58F6166F_80D4_4C74_B52B_5D081420B66B) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_E5578A66_233A_4353_9007_27C32BAE2A75) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_EC50F411_D444_46A7_B520_CA0E75DDC380) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_2A5D737F_24C7_4CEC_B81D_5B71DE92C3E8) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_12D6DEB4_FA94_4288_A216_39415151E64D) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_D588C27A_A413_4EB9_9FAD_C31361A8BD76) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_85A853DC_361E_4B3E_A90A_7F699963E9F0) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_BDD5A3E6_9C40_45A7_83A3_981574F35483) },
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
