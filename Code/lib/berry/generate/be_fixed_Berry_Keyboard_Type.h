#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_C478308D_C358_44EF_A45A_633CB497626E) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_037392A2_F293_41CD_8985_6010A38C5606) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_DAD6E30E_3FE6_4062_8B65_CC86E22D4CD7) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_8A6A7017_3DE8_48F0_A23F_720E675111D8) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_5C858016_B770_4445_AC18_9A7683A388FB) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_4A9276B6_3775_425B_9AFF_69511F314861) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_D2C50EEC_C5B3_4F19_8820_5C946B502E46) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_03771371_8AFB_4E55_AFA9_FBBB2E809008) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_E8FF56BA_C8FB_4DAA_9E26_C79AF68BA148) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_6E9BF5AD_BFCC_4088_8ABC_57952E31C4C7) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_9C02A87A_9E80_4772_B3F9_AFF011DA4D79) },
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
