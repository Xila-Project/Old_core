#include "be_constobj.h"

static be_define_const_map_slots(Berry_Image_Type_map) {
    { be_const_key(Get_Antialias, -1), be_const_ctype_func(Berry_Image_Class_Get_Antialias_AF7501FD_4E38_473D_B9B1_B0B703454F1C) },
    { be_const_key(Set_Pivot, 9), be_const_ctype_func(Berry_Image_Class_Set_Pivot_883B173D_8C6A_43DB_A11D_C786C08220DF) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Image_Class_Create_442B25EC_7AFB_4FA0_AAA2_C961D45056FB) },
    { be_const_key(Get_Offset_Y, -1), be_const_ctype_func(Berry_Image_Class_Get_Offset_Y_C05F6C18_C620_46F2_8513_4C91AFFEF37D) },
    { be_const_key(Set_Size_Mode, 10), be_const_ctype_func(Berry_Image_Class_Set_Size_Mode_66748EB9_29B3_4752_982A_63C72A9D1C13) },
    { be_const_key(Set_Offset_X_, -1), be_const_ctype_func(Berry_Image_Class_Set_Offset_X_42FED49A_C22A_48D9_B8F0_F83A5B4FDB9A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Antialias, 2), be_const_ctype_func(Berry_Image_Class_Set_Antialias_FFE55755_BA36_4E7A_A3C9_E0461842B39C) },
    { be_const_key(Get_Source, -1), be_const_ctype_func(Berry_Image_Class_Get_Source_B15622B0_F309_4930_848C_445D96225711) },
    { be_const_key(Get_Angle, -1), be_const_ctype_func(Berry_Image_Class_Get_Angle_B24F2515_3F53_4F49_8461_5AE46F3FA779) },
    { be_const_key(deinit, 17), be_const_ctype_func(Berry_Image_Class_Deinitialize_C84EC73B_5D01_4473_A49D_AA4A38AAC4A5) },
    { be_const_key(Get_Offset_X_, 8), be_const_ctype_func(Berry_Image_Class_Get_Offset_X_4B416363_0DA2_47EB_AEB3_61D532A9EF25) },
    { be_const_key(Get_Size_Mode, -1), be_const_ctype_func(Berry_Image_Class_Get_Size_Mode_D536CCE9_EB29_448E_92F1_2D4F4C59A946) },
    { be_const_key(Set_Angle, 15), be_const_ctype_func(Berry_Image_Class_Set_Angle_637F8D8C_1E5C_4B63_9459_6112F16CA3FD) },
    { be_const_key(Set_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Set_Zoom_2ED5986B_1142_4040_AC87_C2F7545540C6) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Image_Class_Initialize_474E15CF_6107_4C14_AA73_7C86763266F8) },
    { be_const_key(Set_Offset_Y, 4), be_const_ctype_func(Berry_Image_Class_Set_Offset_Y_F1813C0A_29FD_43A5_B779_7205C5963E7C) },
    { be_const_key(Get_Zoom, -1), be_const_ctype_func(Berry_Image_Class_Get_Zoom_2210E7B1_2912_4249_B299_A8B9E5F6DB45) },
    { be_const_key(Get_Pivot, -1), be_const_ctype_func(Berry_Image_Class_Get_Pivot_8EF2B17B_E014_417B_99DE_5D5F1818D587) },
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
