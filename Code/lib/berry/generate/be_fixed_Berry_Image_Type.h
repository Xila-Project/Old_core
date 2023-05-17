#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_1290A7CE_1D48_4D99_8FB0_6788F61A7C70) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_28F9BF8D_6A19_4E59_8240_7E6E973335F3) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_C8847CCB_E696_4225_8306_799CF7BC8C3A) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_9119905B_5A31_4781_8041_4154A977B05C) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_F4B1A84B_8C01_48BB_B3F2_1C42364DE2E6) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_8C91BC7B_074C_4C77_A46A_7AF808C858E3) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_0503E9E9_70CD_429B_B990_D6F9D7CCEE3A) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_23CC51FF_ACA9_4053_9C70_A26DC4364CCE) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_E49A5A97_CD14_47A3_A145_770B37F7E32C) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_3A928A52_DEED_4980_9823_8B3E9B46DE26) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_EF972941_5249_4841_A4BF_E7418FD625DD) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_4156701C_8441_4745_BD1D_05C1B4B5B982) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_6BB6A938_9B06_4186_98CF_A72E2C17D860) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_CDDF9D1F_73F8_4614_8256_27815D0B3930) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_4CCF203F_B534_4781_9CE8_57311125F453) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_7D92DB2D_0BBA_47B3_9E33_43003BBC016B) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_59B74960_1964_42A2_86E8_94D11B5D2624) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_792CE429_5F01_4272_BC44_B44F9DF70B6E) },
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
