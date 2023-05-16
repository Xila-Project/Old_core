#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_CD998FED_20EF_4DDE_830C_2553B930E414) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_A7B15D28_776E_4F04_963F_83D98E5E1686) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_0B429D03_0D76_4AB4_AFB7_B5C495EAA864) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_4A478DF0_5847_4AFA_9AEA_C73B1E11B04B) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_485F94B3_9BF4_4911_9504_254059AEAFCB) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_6E07A2BA_C636_4672_BC83_F090D06E083F) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_DE65FEA1_9691_4DEB_BD80_036D94E029AC) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_92225D8E_594D_422F_B3C1_25EA40926C48) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_F67710F1_D076_4C43_9337_D534A19D9BC7) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_5D3504AC_312A_4200_8AA1_D38A69782E06) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_4069AAAA_2827_43F5_ADAA_DB5D5248068B) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_2712BBDD_6142_473C_B9E9_0BE814BF9D89) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_83D9E48F_2390_434A_B8A2_9F3FDBF1C563) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_155EB4E7_BE91_43C8_B67F_67B8CE3EEB27) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_87F908BD_9A00_4DF6_BED7_9023118548CD) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_2B8422C2_50B2_4BA2_B56B_445D770B18C2) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_3FC43B5D_C397_4C3E_864C_F8C2A441555B) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_6CF97D33_4240_49BC_B6B4_330CC0863719) },
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
