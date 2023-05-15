#include "be_constobj.h"

static be_define_const_map_slots(Berry_Calendar_Type_map) {
    { be_const_key(Get_Highlighted_Dates, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_F5975333_4923_4EE5_BC0A_FEF70407B5CA) },
    { be_const_key(Get_Highlighted_Dates_Number, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Highlighted_Dates_Number_22246E43_94F6_4C7C_A71F_70BD39661F5A) },
    { be_const_key(Get_Today_Date, 6), be_const_ctype_func(Berry_Calendar_Class_Get_Today_Date_DC037894_A4E4_4999_A5B5_0734CBBCC6FB) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Calendar_Class_Initialize_10D57059_A9F8_45DE_BAE2_E8F436854BF3) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Calendar_Class_Deinitialize_22A338AF_2FBB_4635_B2EC_A0310B2A063D) },
    { be_const_key(Get_Showed_Date, 7), be_const_ctype_func(Berry_Calendar_Class_Get_Showed_Date_49BAF952_C8BD_4BC7_8CD8_CAAEABB8CC92) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Set_Showed_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Showed_Date_E4388F61_5853_42C4_863C_BB6264695B60) },
    { be_const_key(Get_Button_Matrix, -1), be_const_ctype_func(Berry_Calendar_Class_Get_Button_Matrix_F747E236_07D8_4609_8762_DBD39EF3F629) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Calendar_Class_Create_3900918C_195E_49C1_BBD8_1A93E3556C80) },
    { be_const_key(Set_Today_Date, -1), be_const_ctype_func(Berry_Calendar_Class_Set_Today_Date_788C75A5_BBB1_4D35_8C62_9D7DE736F616) },
    { be_const_key(Get_Pressed_Date, 0), be_const_ctype_func(Berry_Calendar_Class_Get_Pressed_Date_EF2962EF_E30A_48FF_B29E_E50C720D89F7) },
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
