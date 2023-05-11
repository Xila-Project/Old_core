#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_76EF642D_0F8E_4F9E_A718_C2A626D8DACF) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_E6C60D07_5754_42C8_B590_F92259A1B5D0) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_930A11C3_B659_4FF4_8C2B_77A3493139DA) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_1A78A8D7_2047_4D3D_974B_2527DD3B19DE) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_CBFD5663_6960_4DFD_8DF4_DEF54AF73F2D) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_BDF0E4FF_0995_44B4_8AA3_307E55183B66) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_6B507E20_E2C1_4055_ACE0_AD37ED3C24F5) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_4C6EAD6E_C0F3_4FE6_B0E1_84D155D23833) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_B0A11EAA_03FA_453B_AD88_EFA94BD739A6) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_72AC70F4_BDC9_4563_B78A_ECCA881574AF) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_E21BE062_9979_47BE_A72E_43E32ECD6999) },
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
