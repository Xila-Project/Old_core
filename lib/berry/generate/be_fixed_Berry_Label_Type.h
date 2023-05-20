#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_BDD64045_6674_43E3_A8AA_0BCA28BBBFFF) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_18E2C42C_E2EB_4B75_B74C_6A3492135C6E) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_73802D33_F461_4845_8EA2_F55479E2572C) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_2CD06FC1_C3CE_407C_9237_C365F6B47CE1) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_12512182_8D3F_4DF3_8C27_056142D5A9AC) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_FF5FF454_CB28_47C3_8C06_B12D82DA9E21) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_B1612D6A_390D_4147_9F3F_DC32A9A9D57D) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_3DEDBB8D_7A29_4C00_A4D9_78988589FC8F) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_7E06735F_5CD5_4C1D_B857_E016E70B1690) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_14695954_4990_4596_B9A6_1BE2B98E7FA6) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_259AC2A5_8E8C_4255_8B7F_B6F3CCACD264) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_0DF8C2A2_238D_473B_81C6_911C2F97E772) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_4F9FC9BF_977E_428F_99B1_4C73D7AE3017) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_D9A6C6E3_FBFC_4BD1_9687_CD11C8E42872) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_86538947_7939_4444_873C_0F8287144FB0) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_B2E0131B_ED7C_4D1D_BCD5_3C96BF1F9C11) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_81454DB5_CE62_441A_8C2D_12A9BF1FF965) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_8CDDDC66_4A17_459E_A7B5_B2F77A1A56E6) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_167BF2B1_F699_4F1F_9A6E_5BD8B38376A7) },
};

static be_define_const_map(
    Berry_Label_Type_map,
    20
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Label_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Label_Type
);
