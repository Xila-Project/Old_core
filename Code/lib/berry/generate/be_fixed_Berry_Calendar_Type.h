#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_116C88C6_E351_4097_8506_7D3D5B90CF69) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_ADA6880B_88C3_4EE8_AA48_C779636004E7) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_2A854DB0_5826_4119_9F6C_0BC75298FCF2) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_510AFF50_2A35_4574_8160_41C5DDBC87F8) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_3C0BA8BE_37C2_4C5C_82F7_155A354A6892) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_96AC7E09_30A5_49D3_A127_2D468F4345A9) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_19F43B78_CDBF_4DAD_AA5D_12A5FC8FB4C1) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_680637D0_24DF_4AB8_B0B1_55F3642D6677) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_EA43ABD0_AA91_42FF_8DFC_5CB5949A6C06) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_18C19705_47C0_48C4_AA2C_3C4034A2C8AE) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_96F3FC4E_45A9_494B_8758_8A4FF7DAC660) },
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
