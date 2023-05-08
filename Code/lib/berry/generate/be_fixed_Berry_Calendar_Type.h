#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_66157034_EB42_4F5B_8646_2F96E4B5603E) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_A5ADF34B_E893_4208_B7D1_86029A263F19) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_B59AC124_D9E5_4F7E_A7C1_3270CCE06DBA) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_7E636765_7C63_4858_978E_FEBF62CACD00) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_ED39A68E_1606_41E8_AE37_90D36601F7EF) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_930A9C5A_415E_48B1_8C89_A1132160FB70) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_4018BCBA_EB97_4B6A_A11E_1B823AF69242) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_9F9D6F3F_1493_4FBB_82FB_4CBD6D3EC8B7) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_9560E42A_32B4_425B_8049_787F69218363) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_D6007B96_3918_4158_BFDD_E1D5F2B2B884) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_0F6BA376_6CD0_45AC_8C18_920CFD041C62) },
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
