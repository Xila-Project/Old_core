#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_70D5395E_9FC2_42C7_842F_305C41E0236F) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_A34F1D26_D1CA_4A0A_8D91_38050C2089E9) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_F7E8E9AF_857E_476C_8F4C_1CC613C5D95F) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_13C67D66_F5C8_4F73_83C1_EB931D400B95) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_3DE00C24_1859_48AD_9462_540AA91FD07A) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_BB785405_55BF_498C_AE3E_C4CFF15C9DC7) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_50D5F8E7_6A3D_4CA3_BD28_1A646A1600F1) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_4636A456_DCB7_4771_B3DA_02549FAED3F8) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_04031218_831E_422E_B7C8_87DF2E1E1CAF) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_A9DB8E32_BC58_4D14_B9C3_432C1DC476E6) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_D41D8B00_91A2_4126_ABCD_9474CB5CCFB7) },
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
