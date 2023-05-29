#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_6B802837_C960_461F_AA23_BCD0EC1ADAD9) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_95C54D31_1B5F_4816_BEF8_4A951EE0FA25) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_EE136701_5B92_4C67_9E89_B9C008693235) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_FCCE5818_3654_4BD2_BE3F_5697EC136510) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_689DD275_A3CC_4898_BC1C_8F4A7BC52C49) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_FDAA8D8B_60C5_4877_8415_2BD5DAE2CB90) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_A1C82A56_0A1C_428B_8180_15E353835D44) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_1E99336D_B94E_4AA2_9791_A0D2867D38F0) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_D1343B66_4DD9_468C_BA1C_4ED2BF0C382E) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_6FA8EA42_4E23_4949_90E9_19D88513B2D5) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_F12B897E_5B01_4F0C_A9AE_7C8969D4FBE6) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_904394CB_0344_4CA4_BCE1_FEA7ECE063A1) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_71E04DCF_C1BD_42E4_8379_FD085335B62E) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_2628DBD3_BDAD_48F2_B387_2ABBD722911F) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_F11A2F45_3512_452F_A640_F42DD37DC48D) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_1953A99C_1947_4F18_8BC4_7523ADD33C98) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_F6C90A38_CC33_4A65_9834_1F7DD1F80F3B) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_E4312B78_3DEC_4FAB_AA94_CF867B2EC94C) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_217292E5_26C4_43A0_98F7_71E8AD554E94) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_CDEA2924_C483_4769_9092_6CFCD070D317) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_14519265_07BD_4F0F_BA80_CC92C7F6AB75) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_852A2131_1443_4142_8708_8E775381D09A) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_8A134C9B_0807_4F44_986F_8B7610723D1C) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_0F6E1F21_EC3D_4B4D_A50B_EB0182EFDDD1) },
};

static be_define_const_map(
    Berry_Drop_Down_List_Type_map,
    25
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Drop_Down_List_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Drop_Down_List_Type
);
