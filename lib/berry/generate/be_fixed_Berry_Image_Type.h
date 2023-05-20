#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_C7B79321_45E3_4055_9CD5_6B5D0484B162) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_1E16DB71_028A_4FEE_A9D4_1070D11A8DB9) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_258A65AC_5286_4013_91B8_451CF45B7AC8) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_AE7506D3_C2C5_48B3_890B_5C66F955A8EB) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_714E6D0D_28B4_4D5B_81AB_DA2784DFBC26) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_D290E6F9_2941_4B49_9331_6C221FAA65D4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_25B10A2D_5DB9_4C52_9316_2657E299E3BE) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_7E5C7D11_88A3_4FA3_82A3_28A7D0ED23D7) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_49C33A4D_1FC7_4F86_83B1_22E1628783D9) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_8CFABA8B_7A04_4D60_9F51_733207DFA32F) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_CBBE4460_54E2_4ADA_9543_EF0D0F45451E) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_FA6DBFE7_2E1F_49D6_AD7A_973F92C5D0F1) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_58ECBF53_9521_42ED_8153_8C83C1F69B74) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_D3C7011A_0AE8_4D32_AD23_A57A3CC7952A) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_063912F9_D18A_4853_A8AE_A8EC74CC3CC3) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_6965D256_9CDB_415E_88C5_EE254E17FD2B) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_730D80D2_9707_4508_A206_484985A7CD82) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_D5ED8B89_71A7_4BF2_99AF_F5ADBE3A96CE) },
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
