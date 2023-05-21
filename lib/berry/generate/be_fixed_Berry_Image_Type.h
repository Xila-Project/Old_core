#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_3572E9F1_81F2_4FDF_9AE1_B53B919FF398) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_BB5645B3_AD43_4778_93FF_1E31A7782072) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_2567CDDA_969A_4199_AC16_9EE4E8009125) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_4B608DFE_1A23_4A20_9754_A5D9402CE6EF) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_9B0EBFF6_C832_425D_8691_7E8D33DD7A0A) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_7543E0E6_462D_47FE_891D_51E78922375B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_46C2F311_DEEE_479C_8B85_0CDCF4FF1DD3) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_EF63CF58_DBE7_4072_9360_A422556DA5EC) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_AA1E94AC_5DC8_4F17_8249_66D798D504F9) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_734AD929_FFA0_497C_BC5D_A160B2DCAD40) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_F9FA2F7E_7AFB_4437_A050_035CAEFD1ACE) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_2377E645_CC4E_489B_A34F_49137DA4DEE7) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_06135DC4_46F0_43DF_8F74_7612B8258273) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_DFB2DA20_635F_4B02_A644_E77FC473C8B5) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_86A63FF6_A99F_4F4A_9E97_F62FCBAE8EBF) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_FD8C73DB_A5DA_479B_A28C_47EA7FA1FB94) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_D2CAF18C_FBC0_4DAA_B0FC_B21E599D8C40) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_F932FCBD_2DFC_411A_A218_113AF30CC9C4) },
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
