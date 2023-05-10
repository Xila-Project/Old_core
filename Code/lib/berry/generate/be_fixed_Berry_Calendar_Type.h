#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_DC262628_F209_4E9F_9A72_87A7F7E18F94) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_2C8D3035_2874_4D12_8EF6_AF921E4C725B) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_0765BC04_7C44_4FCD_AB58_69FA3E9169AD) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_4692D792_B8DC_4289_BA69_743E7D4BCD62) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_0080C06F_9813_4C5E_A277_C244E2A92EA3) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_11F2A812_B8D6_4E36_B0BE_9E76ECC05C8D) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_631319D7_BBA0_4978_986D_D7B5028ECA2D) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_DD9290C3_E330_4A42_AFCD_805241281761) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_454DDC7A_CB5A_4438_B111_8F2AEDC23E04) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_417D4700_4D8A_4F29_A832_5B5030C6C699) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_538801E9_B91A_4C1C_BB39_4EE6F150E145) },
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
