#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_E1FB0495_8787_4291_8014_9967A2505B73) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_71A259BD_2F94_4A62_8FA2_469F4003B54D) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_17A89D76_6C3D_4BC5_8D3A_AA5BF4E4D620) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_626641DC_C301_4C4C_8117_81AE5CBB067E) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_E8BF26CF_1817_4F82_AA2E_2B8442558E38) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_8AF608FD_D0EC_4A74_B25E_EB3EE6CEDE6F) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_52439F3C_3D3C_4C49_A51F_0C3441A9373A) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_D6ACC44D_5110_47D4_B2EC_A78712FB209B) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_C410E2C7_8E36_43FD_91C9_5A4D896313E1) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_96EC0964_45BC_4D06_882F_B2F726A8D9DA) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_1D48E840_9011_4114_A9D7_9907EAF4E87C) },
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
