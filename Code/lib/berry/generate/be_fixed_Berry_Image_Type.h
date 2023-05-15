#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_914E59D4_5B46_46E0_8DB0_FB027F35BD2A) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_E5610BBF_5497_4A1A_8D63_86E4E00FA7CD) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_8D4E2726_F120_42B2_972A_6552C3C9A1AD) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_BCA98136_EE0D_4E61_92E5_20149F8302BD) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_A6F44FAA_2631_4286_8DAE_466B0A8E18CC) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_CD010D6E_6B16_4334_9B01_D4D7ACCC5063) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_C2DF5D6F_D2E8_45EE_A2DB_1AABBD1BE5E9) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_B2BBE092_9F5D_4A0C_9BE7_FEF5D306CD39) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_7BF44240_F541_4D27_A991_FCE5928956F9) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_9D5989E9_0EC8_4751_AE5E_12C081AF2F20) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_39D60B88_019B_4D4E_98D8_080909F1820A) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_B94EC51F_31AC_4034_9233_0503778AC104) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_8FB700A4_894D_4A80_9A92_5067A3AA2B4A) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_E9C4E5F7_4774_4422_9928_0071B09388F9) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_9ED44BA3_0F23_4237_9734_A4723C9ECD14) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_E7D21069_1FB3_43CC_B622_07716B927709) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_3C9A68A1_F919_4BD0_BF74_FFE84ABB26A9) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_00316809_FA87_47B3_A46A_EBA2DD0FD6D3) },
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
