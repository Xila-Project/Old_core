#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_00635D78_D811_4285_BF61_9F95B4997C9E) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_96AC0C11_EE74_411D_848D_1916E8EED99B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_80CAC7B3_D014_4C27_9BC2_729AC2F7DB6A) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_016E6F20_772B_4D30_8991_BB04D4C2335F) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_E1B7FE0E_E405_4FE9_8DD7_9ABE1013EB65) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_D38287B0_038F_468B_A62B_84C95B17241B) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_E380C554_E31C_4932_89FB_60241E4FC663) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_1A8F35D3_3BEB_40E4_A24B_C86B8E55608E) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_21EF4C9B_E0BC_4943_874B_73C727B6AC8C) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_FB9C338D_3893_419F_8216_7932CC0FDA12) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_6023AABF_339B_4FD2_AC44_574B8471A327) },
};

static be_define_const_map(
    Berry_Keyboard_Type_map,
    12
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Keyboard_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Keyboard_Type
);
