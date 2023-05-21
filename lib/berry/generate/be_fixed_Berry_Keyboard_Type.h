#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_34BF924E_4841_4796_9EAD_4BC693C49BB2) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_A828D7E5_CB14_457C_BB97_5B0A6656BF75) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_8979728F_B5C8_4840_9E8B_1E63828E2692) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_9500A128_6B67_4001_AACF_108E877FC7AD) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_5417502A_FDDB_4441_861C_112D9A640694) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_CBC3227D_AE02_4E1A_AC72_6D4A2FB65456) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_58C4CF1F_B6FD_46B0_BEA7_C04EAC4FDAC8) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_9EE65F6B_DC77_4718_A543_AAC9998F5F60) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_12DE2CB7_850D_4E58_8197_72839F29DA7E) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_061F19DC_12DB_446F_BC43_193D7B3C3ED2) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_D1E1AF11_B841_490B_8902_E6E4968246D6) },
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
