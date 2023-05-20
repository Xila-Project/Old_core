#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_4D792BD3_D774_4514_8AD4_CCBDDF4F176E) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_A2D725B5_AD52_468D_96D2_476B14B41153) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_1EE07AB3_5DA2_4444_8F18_FFF39BF7B0DA) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_8C7F2CC2_1E29_4F2E_9083_754841E71571) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_DF0E63CF_DB9C_4C08_B85C_91B83CEA1153) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_DF7713EA_6AC3_4AE3_B7F1_A9A2F6148A7D) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_D787B01E_EE80_4767_96F3_3A3799C22CE4) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_4677484A_AB30_4E58_9683_DB2CEFB722EA) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_5389F347_D599_4207_AC43_A9FB042AAD62) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_B06E6310_B2E5_4950_A302_9459EC8DDFEB) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_D3EF41A1_6412_48A9_AB16_8754F1FCF661) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_F6F04077_D514_45E3_BE08_74C9ECD5F874) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_942FC14A_DF59_4A25_8090_B3341B7E18C3) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_48F2C85C_9EB1_4A98_B103_67874BC05401) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_792B28DE_B13E_4B73_928E_65603CF63AB5) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_30E887FA_7A75_43BF_B9E1_840DC61A9755) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_382350DA_C4EB_40FF_BFFA_35DCE0D9B2F7) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_166347AE_C973_4F4E_9E9E_B13D58090915) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_04C0C10C_55D4_44DB_8C8F_65708F741F7B) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_67362A5F_BCE3_4C27_A1E3_98B135187554) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_F09BC104_8D92_4408_BFB1_14E7E43BCF0A) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_88C0293D_AD2C_43A3_A45B_4A952094B362) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_131359BE_E55B_4A2D_B29F_9148F5CAFCC9) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_AF7A98A7_D609_414C_8A97_41D1BB39BD17) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_1C828DD2_889A_45B2_9BF8_3F3F41AB4066) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_15DA9722_1A31_4D0A_8E88_CC5439BD2A88) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_69CAA48A_C21C_4260_AF01_6F29914E9581) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_351D6397_CF92_47B0_B134_30AE2DE1620D) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_5A163A67_0631_4DF6_8877_4305B8AC9D9E) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_EC9E2AEB_B633_432F_BCEE_1C75A775C2FE) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_5DBAF2D2_C4C3_4E57_BA17_43E6723F0E0C) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_A61787C3_B17D_4CAF_A324_C9E49203534D) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_38AE6ED1_C8E6_450D_9172_7FF37DCD6EAB) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_DEF24D11_8A1D_40F8_A6CB_17D1AC324678) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_21E8FFDE_08F3_40D5_904D_F23C2AAE09E5) },
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
