#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_C59D4176_8C60_40CD_8B3D_80362AE60BB6) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_C8FF0AFB_3AAE_4270_845C_F949CAFAF82E) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_A9F5A83F_6DA7_415E_B44A_4EB5B7DB4E0B) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_579A1031_8E50_4294_AE62_903AFE57913D) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_FAF2ADE4_8624_455A_9652_740F2DB48395) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_2EF86D34_D2D8_442C_BF04_08F0D122F5CC) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_E7E4B195_CC1F_4C19_9ED9_23FCE49098A7) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_B9F5F609_25EA_4E60_8E1A_39E32BAC1605) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_9E16811F_BBB3_452E_8DA1_B7AB77FC22D8) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_C5664FBB_C992_4D4C_A605_7C084FC0228E) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_D481D971_91CE_4A34_B11D_DDCF1C1B721A) },
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
