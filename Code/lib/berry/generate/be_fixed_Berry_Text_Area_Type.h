#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_A7320447_BBE5_4E8F_A576_0379056FE2E7) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_FDEA3D5A_B357_40B0_BBF2_EAFCE3AC8F99) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_50A2D43C_60B7_472A_9F73_D51D32BABDFF) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_C42275E8_9B58_4EFF_A7E2_EF0244966CED) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_1BAF6E94_1ADE_4059_9808_E1DD6F36E955) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_CD4FDCFF_BF2F_4045_AE42_540CF715C557) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_7263F822_0C74_4218_ADB9_BFB06F8BDA73) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_F4F5608E_C783_4D5F_B59C_29B6FD3D2984) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_5E7089EE_536E_4E41_8F15_AD984BAB34B8) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_62D29A0B_5A5A_49A0_90BE_453A6805A0E9) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_0E4453B5_9459_4982_8526_8ABEE9B25ECB) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_D89B1F05_BA4B_4D67_AB49_6D1D99F3A8C9) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_FA72172A_0EA2_493F_ADA9_606A405FD6E7) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_86917535_C069_46BF_8498_D51E2A6218F8) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_DA5FB684_C089_4E35_8A84_ECF5F1D65EC3) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_B2178D7F_2DF5_4370_9CD4_AC8ED09ACA29) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_2540FEE2_6EF7_4F08_A91E_7F87AEBDB53F) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_EC1CDE65_C382_46C2_90E4_A7E17109BC34) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_2A7A6D7E_FB89_4847_B450_FE3930FC7510) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_E971F3A8_D072_457A_A077_3891DF4F13DA) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_109B81EA_0CD1_4328_A22A_E9AD60F20C0D) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_897158AD_DBFD_4FE2_B8E6_CA2D12BD9257) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_F530A0FE_2250_4362_ADEB_B62FD54F478E) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_5BDB7C20_E86A_4DD6_9C64_EA718B3EC0BC) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_9731444F_53E1_4FCF_9A95_E54ABC4D4362) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_0600426B_D8FA_44EC_AE4B_6CCD7CBE7FC4) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_ADF3DDEF_18D2_441C_9841_D36625A786C9) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_5F40A27C_B73F_42F3_91AC_32BAB1614EF1) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_90578BA8_2055_4BF9_A967_4350E99105AD) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_75A1A0F6_E2AC_4E69_AE13_05F2CB5FF1D3) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_E9F93557_DCCE_4926_987B_513898B219AD) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_A6C19A5A_4A89_4111_AD80_9FD40AE0F327) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_C158605B_0609_4A6E_87E5_73A8FFA61068) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_C7549893_9015_45C5_A70F_FB7FC050399F) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_8370D012_9CEB_4C12_AD80_1A232037E381) },
};

static be_define_const_map(
    Berry_Text_Area_Type_map,
    36
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Text_Area_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Text_Area_Type
);
