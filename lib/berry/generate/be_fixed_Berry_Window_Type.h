#include "be_constobj.h"

static be_define_const_map_slots(Berry_Window_Type_map) {
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Window_Class_Create_6BF03B37_17E9_4D1B_99A0_CAAEED2E9539) },
    { be_const_key(Get_Minimize_Button, 4), be_const_ctype_func(Berry_Window_Class_Get_Minimize_Button_6046210F_5B78_419E_9F18_2D0BC3582E11) },
    { be_const_key(Set_Title, 13), be_const_ctype_func(Berry_Window_Class_Set_Title_1CBBC7DD_D347_4E21_A8A1_5BBE78E0F1FE) },
    { be_const_key(Get_Close_Button, -1), be_const_ctype_func(Berry_Window_Class_Get_Close_Button_46D88244_4D65_42CB_8F3E_A8B41A3B9D4A) },
    { be_const_key(Get_Header, 7), be_const_ctype_func(Berry_Window_Class_Get_Header_3F556D92_2FC0_48CF_A8F8_900BB3934DCF) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Window_Class_Initialize_42F299FD_8559_40ED_A7BE_1492C14D38F0) },
    { be_const_key(Get_Body, 8), be_const_ctype_func(Berry_Window_Class_Get_Body_F8EB5DD6_AC65_429B_8071_23516C7F0C83) },
    { be_const_key(Get_State, -1), be_const_ctype_func(Berry_Window_Class_Get_State_4DDA8BA8_5685_4DCD_A308_49144D381509) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_State, -1), be_const_ctype_func(Berry_Window_Class_Set_State_BE93725D_D0FA_469D_A39B_B04FD4989D18) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Window_Class_Delete_BA34173A_4A04_4DBA_9A1C_A8CF038A5A2F) },
    { be_const_key(Get_Owner_Software, 9), be_const_ctype_func(Berry_Window_Class_Get_Owner_Software_6DB98AEC_455A_44BE_83AE_FB2A5EBC8553) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Window_Class_Deinitialize_D6EF4A53_0781_4EE9_87B5_DFA8E0868E98) },
    { be_const_key(Set_Minimize_Button_Hidden, -1), be_const_ctype_func(Berry_Window_Class_Set_Minimize_Button_Hidden_C06DC3C0_723E_4638_B7BC_CFDC9DC3EB20) },
};

static be_define_const_map(
    Berry_Window_Type_map,
    14
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Window_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Window_Type
);
