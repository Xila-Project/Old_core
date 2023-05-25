#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_A2DCCA94_192A_41F7_A3B1_65572D421587) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_E7D365D7_DA8E_4232_8718_587CF52DB02C) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_AB60DFC4_E442_40A6_81B3_C9F9566C8BB9) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_C649403B_FE24_4572_BA67_CB2CAF66200B) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_94999F2A_53CF_4F53_B4E1_3C13CB1E8954) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_EDAFD715_6052_45C8_8BAB_395B55D0E6B3) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_3032B212_E943_4F99_9D38_0F359CC9BB04) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_370558A5_5202_4053_9B20_0F898F3DA569) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_99AA13DE_D503_4F93_834C_7144B1BF33DF) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_647C9BE9_474B_4D8C_A4C8_05504CE9B942) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_CCC1B937_C6CF_412B_B3A8_31FCFF8865EC) },
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
