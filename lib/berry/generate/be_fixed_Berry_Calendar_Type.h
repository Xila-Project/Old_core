#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_76C9126B_F060_4D97_A0D5_7750075CCCD5) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_0FED6AA9_7730_4A4B_836E_E5214D7F61AC) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_0D0F5079_CB7C_467D_B3CA_90EFFF72C719) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_750C6795_5F4F_4714_AA72_52B08C80394B) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_E59D3ED5_88C7_472F_A1A3_96CA7F34813D) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_F11432ED_D251_4D10_95DE_17B2FBC3E5EB) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_D57860CB_EF17_4609_AA27_3414C5C7C5FC) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_352899F4_E26F_49EE_87D5_DA0B23B89523) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_CCD9F361_D44B_484F_B582_0F791DCB4C48) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_CD427003_E4BF_4D34_9F1A_5B0A689E814E) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_27F9C94C_C566_4F40_8E36_4C812F3EC864) },
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
