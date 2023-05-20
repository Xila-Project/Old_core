#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_2341D630_64D2_4CC9_BA47_4A7EAC82BA39) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_B43C8C49_7422_4549_92A9_FD77E57B3496) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_323F914B_8BE7_4691_92D4_1F4A831155C0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_64EFDA4B_569E_492A_AFEF_5921FA0AC803) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_C223B147_0FD8_4151_AA5B_7F1495BD5555) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_0349EA91_2C07_4A4E_82EF_523026A8DA90) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_952D582D_E3F3_4610_8591_1C9BF21CE4C4) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_C43388F1_A06A_4452_B44D_D13B8B263B0C) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_2BAD3230_34B2_4555_B766_4D1A70E7ABFB) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_4723E749_529D_411B_88F7_CC93CC28BB24) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_8857AAA2_CFEC_41AB_932D_CE565E2C7298) },
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
