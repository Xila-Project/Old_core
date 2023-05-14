#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_C83CE1B1_82E1_4BEF_B4A4_E339E21E4489) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_BB72CDE2_CBD6_41BC_90A0_9F651B952F1C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_DCB17587_B164_417E_B632_B54CBD747657) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_62D5E4F5_53A7_4954_99FA_0FBAB0CF303B) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_9689C4C8_E728_41B4_B0E7_59A53415ED95) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_3E6D2265_0344_403A_B6E0_D9E1C6DD4714) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_3ED519E6_14EA_4302_8658_610CD3C80A4F) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_5512EF5B_36EB_43F7_89C6_9638EFDA74CB) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_FEA28C2A_63EC_4E41_9D28_2A51FE8ABFEF) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_541D7ADC_2508_4AD7_986B_BE204DC51F12) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_A6FAF487_48F9_4915_A82F_F0429A864503) },
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
