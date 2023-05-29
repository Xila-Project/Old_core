#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_49426111_09B0_45AD_9E00_DDF8FA3709A7) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_43AFA640_7D25_4EEF_836A_A80E8A58C746) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_8352F26E_FD59_4FB8_AEEF_46F4B3C00E78) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_91FA8E45_14F6_49D8_85A9_FE9A9A41B828) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_8023145E_4FC6_4FF1_B6FC_28C12EFF3640) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_EC2FC5BD_4128_4F1C_8B46_0F015BE445EF) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_A2C402AC_042F_4AD1_9647_D2F80B705DFD) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_F4BED8E2_6114_49C5_85D6_6DA3B51C24F1) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_B4268FCC_E54D_4100_8E2E_C0750A78B81F) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_A5B37691_296E_4E19_9A29_54BEE93F6D45) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_89009C99_37A6_42F2_9860_44BEB0EFB03F) },
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
