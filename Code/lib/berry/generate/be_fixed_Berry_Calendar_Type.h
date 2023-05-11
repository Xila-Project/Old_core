#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_0A42D3E6_01A4_4335_8937_3416B7381205) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_70A30C1C_5B65_4B9B_90D8_1DF26EAD106A) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_64026A65_C903_4247_8442_E45F0E6F0443) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_0F46C5E0_EF05_4934_AB03_8A49E0726526) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_26E14ED7_DE9B_4DFE_B410_417499B4CDAF) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_8B6B46D1_95FC_4ECF_B530_6765C07E5A24) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_6A5F89A2_79B0_4F2D_BD17_DCFED426EFAE) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_C06AA346_D7E5_4FA9_A328_E36950AB942C) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_8F98E6EF_10CD_4050_86C5_05F28A5F882F) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_F22523D4_5D9F_4142_96C9_CB3A40B3A6E8) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_209FBF38_B771_4B59_A578_DE9A34F84608) },
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
