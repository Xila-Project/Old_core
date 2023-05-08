#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_AB9D958C_8A0E_462A_8997_8CAFAA1998F6) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_C470A315_88F1_4E2E_B422_D8F8911B0799) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_421C4232_4B33_4A3B_8204_B4ED06EA2A4C) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_1252F7C5_D8EC_419B_B739_0BD813833883) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_EBFAA200_D42B_4D8F_ACE0_D4072E8BE887) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_D04DE316_1883_4D99_90E0_646FF72C9AD0) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_0A1D408A_8661_48EA_A215_30C4EA0A9C81) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_C1E63F46_FF07_49C8_9100_64BC3866E27B) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_7FA7CCB0_F703_4AF1_8738_62806DF23A87) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_FF3159CF_2998_4F67_AE13_B22761EEC1BA) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_00E356D3_0EFE_4E78_8B6C_8B9C5DFBF744) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_961942E3_D043_42F7_A3CD_30C6CBC02E73) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_25A24430_1605_4A29_8C46_6D225A2CF5D2) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_741BFEEB_11EB_42F0_9546_84C68CBDD34B) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_AA1C34A2_09E5_4524_B655_E72CD448B1B6) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_C6829F51_0EC2_4EB1_ABF8_99991396286D) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_639F6BD3_3218_4C9C_8E5F_0710741A6AD8) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_13FCC346_2EF3_4EE6_ADDB_B2A50FFFEC06) },
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
