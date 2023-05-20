#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_8EFF404D_EFB7_4E3D_8B74_730F063C6283) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_460988B4_AAD9_4AA1_8E46_E2DF94533A2A) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_8E82FEB9_8C7C_4CF1_A38C_BF6A03FC883B) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_183B8332_E687_4906_83B2_6DF1AE7D510C) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_01F4ACF6_68F2_42D8_A1A6_589FFE73668C) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_B1121DF2_7D25_4AA0_8D73_A3AE2A9955C8) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_C7A2124D_190B_4BF8_973A_3A5C93BE53C4) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_FA52572B_2CF5_426E_B568_EF1A57B842F0) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_4B1D4B60_282F_47DC_94A8_DD3503F9B105) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_3A9BDE86_AA11_485D_B271_22F5A98D44DC) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_76FA7B18_FB6E_48DB_AFF8_C1DE1E78C7E8) },
};

static be_define_const_map(
    Berry_Calendar_Type_map,
    12
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Calendar_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Calendar_Type
);
