#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_75B659B5_F92D_43AA_BA21_5033B913CBED) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_2F982DB3_964F_4C59_83F9_80ED9D4B8E36) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_B51F6F40_A7AC_4CCE_ACDD_B2E57EDAF05A) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_F965532D_95EF_4D4B_BAE7_D210A8784241) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_C10B1978_5CD2_48FC_8999_F0ED397F9F42) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_6FE494A5_4F26_4E89_BF8F_DEFFC363005B) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_90DC6044_005A_47B2_A8B6_3CE37B3DD3AD) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_F91467C9_ADE9_4E1A_8109_30CC6A53A2DB) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_23A2E686_3B6D_4F72_8021_6876376D179C) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_514C2320_0451_43C4_9459_BF744B84B0E7) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_24FDF240_26FB_4BD8_B997_30F54B741758) },
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
