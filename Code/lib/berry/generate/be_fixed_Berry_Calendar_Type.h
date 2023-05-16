#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_83E9B47D_3DB1_41EA_9810_262A5E2B47E4) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_CA7CD13F_0770_44C1_8D83_2C9B6A7395D9) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_7699DD45_9BAC_493B_92A3_268E34753FEA) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_5727F80E_EC1B_49E2_A80B_F0FBF903666D) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_04E7B37F_EC7C_4378_8604_FDF557C37931) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_521A1378_DFE5_4645_92F8_BA3C4933460A) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_289D6F4D_AB36_4BCF_BE26_76BB923F0F37) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_ED59EA7B_F0B0_496D_BBC3_9133D39260A4) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_33F648BA_8ADA_4655_A69D_D09A5B7AB3C7) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_B96FF89C_D19D_4C8D_AF56_E59ECC22A4B9) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_05177A01_ED3C_484B_A1A0_800B5029B85F) },
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
