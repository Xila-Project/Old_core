#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_E7F0DE28_561B_49CB_843A_368133419B89) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_FCF0B695_F569_484B_A7AE_8E5BF1E44656) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_636E7894_762A_425D_BC89_896B332C3C50) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_24489389_C80F_4F0B_B1D8_2A337CFB82B7) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_3A2D2FF1_A5E4_480B_8A47_21BB231E0FBA) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_5FFAA6FD_2692_4071_9863_0B1631F3CFB5) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_DA522171_050F_4D35_9F3B_C84E1855B1EE) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_DEC6D571_15A7_416F_8285_79EF95F69D30) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_10C5BBBA_231D_4728_8A6B_C6AB7DF2EB51) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_6BF2FBA6_F90E_4D65_BAD8_40D756971341) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_7A4FAA43_D272_49F4_AF27_955618690307) },
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
