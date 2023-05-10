#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_8248CEE4_B78A_499B_B8F7_B36170B621FC) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_B7CA9D52_DCB9_4888_B4E2_0D14E5451986) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_076D7752_0185_4750_89F8_61220FE5B56A) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_356057A8_C062_42AA_AC55_2DAD496DE7F5) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_2F06CB32_9F1A_4915_AAB2_ED95B296A66E) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_83A34FDC_8EAB_4A99_83BC_6F5B455148F1) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_8E5EF622_8A1F_4A44_A2B9_9780550A95E8) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_3785811A_0B25_4815_9495_ABC4180F3FD5) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_A3D6A5D2_E789_43A5_9077_15A0063954CC) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_EC72A019_6B8F_4A22_9EB2_756EED800331) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_A6AD4A24_D0E1_4300_9788_366D74BE754C) },
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
