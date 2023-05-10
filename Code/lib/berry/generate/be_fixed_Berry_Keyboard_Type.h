#include "be_constobj.h"

static be_define_const_map_slots(Berry_Keyboard_Type_map) {
    { be_const_key(Remove_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Remove_Text_Area_CB5E971F_7213_4DAD_9F33_600B2DFB1C1D) },
    { be_const_key(Set_Text_Area, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Text_Area_7E53F1B7_AE13_4926_9EB5_9FA5CF198362) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Keyboard_Class_Initialize_2760813C_BA22_48E7_A441_50458DAA0A18) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Keyboard_Class_Deinitialize_09B0A9B8_D1EA_4BDC_8C61_7EB6765C9390) },
    { be_const_key(Set_Pop_Overs, -1), be_const_ctype_func(Berry_Keyboard_Class_Set_Pop_Overs_673B60C9_06E1_45A9_8FA6_7AEEF10AAABF) },
    { be_const_key(Get_Button_Text, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Button_Text_B865E5B8_4BBE_4690_9F67_D5F597ACE5EF) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Mode_DDCC0D89_DC6B_4B37_8C93_572B36C5D8DA) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Keyboard_Class_Create_A9035321_25E4_41E1_960B_94DDFD5ED4B3) },
    { be_const_key(Get_Text_Area, 8), be_const_ctype_func(Berry_Keyboard_Class_Get_Text_Area_67F162C3_8F23_4498_B411_2D59ED0C4E41) },
    { be_const_key(Get_Selected_Button, -1), be_const_ctype_func(Berry_Keyboard_Class_Get_Selected_Button_0753ACA2_49F2_41F0_A5F0_ED461822F6C7) },
    { be_const_key(Set_Mode, 0), be_const_ctype_func(Berry_Keyboard_Class_Set_Mode_D33E0EE8_D234_46D3_8861_EB803A05F431) },
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
