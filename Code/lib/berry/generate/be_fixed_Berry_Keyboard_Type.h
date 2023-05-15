#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_FD16B507_5DD8_41D8_A9F9_99F753C04C9A) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_35608DFF_BCA1_45C1_A59B_41AF01BB37C8) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_051355C4_5EDB_41AF_AA18_5F82A22D7DDD) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_EA310FDB_54BD_44AE_8558_80B40F8290FD) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_BA27BBB2_742A_4212_B5EB_B4917F3B3107) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_A14C2DA0_D5F2_4ECB_A709_B3B9DE915346) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_753C633D_2693_49FD_B5B3_402E297AFB97) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_26D7EA3F_9549_443C_9E2F_AFBA7D67B33B) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_13AE0AB3_41E1_4040_A0A0_6DF1B36C5DB1) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_AA48B058_7289_460E_BCB9_59FF28190EB7) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_4DB14FCB_4F2D_4546_970B_7F3697555950) },
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
