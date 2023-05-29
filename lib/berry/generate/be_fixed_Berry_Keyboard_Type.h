#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_E675B593_BC38_4CF3_BC2F_7DB692DCCAE7) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_2B350D2C_20E8_47EF_B357_250411657B51) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_4EA404FA_AFC0_4211_BFB0_1CEAF41D6B13) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_49EC46E8_4CCE_490C_9F55_C0F284C64297) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_290CC1BD_589E_4A32_BEE2_F33E6CB76E21) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_9FA633BF_75EA_47B5_80B8_0A9C4F96E93E) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_81BAFFF1_F9BB_4C77_86BE_D8F0ED9141B1) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_F7177129_E7E9_4763_9F3F_B495E1CC7A7B) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_52FB14EE_2FC6_447D_8F66_9512675416DD) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_C2D540BA_D5F8_47E6_BA00_BEACF7768417) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_B4CF387E_CCC2_4686_8733_2D008020AEC2) },
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
