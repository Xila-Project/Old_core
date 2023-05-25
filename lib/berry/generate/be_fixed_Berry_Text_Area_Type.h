#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_34FB5F9A_51F2_4173_B822_01BCD0236542) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_73F9B7FD_13A6_4474_8A4F_B5ADB5F8B083) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_51C3448F_031C_4ED0_A5BA_37090A97BE9E) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_3C8D1777_EFE6_4A92_ADFC_94B47E1F73A7) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_94E4600C_0B28_4CD3_B56D_F3B1375A8689) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_3FB06D4E_F28E_4EFD_A25E_6D0C2E862CC3) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_2657AE03_49CD_4779_9D80_F8735237F53E) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_10DC9550_F778_4CA7_81CA_8FB7DB1094E9) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_D22D940E_1368_4751_9ED8_2FD18CA74822) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_1F1A7F70_6521_4055_8C86_4A9DCF21CFA8) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_CBAD4682_DB6F_4444_A1ED_A0CD81F9AF76) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_23964B43_4CDC_488E_AA31_FDEE7057A9DB) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_0FBBA277_808C_469C_8F14_E01E50C1D183) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_E00648E1_6C13_4761_9B9B_9E6FACE1DAE6) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_61EDFF3E_F04C_47C7_8A31_6F734787AC20) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_4EAA281E_3790_485C_AF41_4811A679813F) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_DEACD001_C998_46F9_873F_0942441E9737) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_8510F5A7_7A23_4F40_8BE5_20049520EE15) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_D5624F2B_1BB9_4FC9_A7AE_8875C3858EAA) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_F0175E18_C8F1_4A0E_8166_8396323639CC) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_ACA2F4D0_8AAA_46B3_B4A0_D2CC015867B2) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_6A9D8E08_C4DE_4371_A32F_53EB26EBA03C) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_6772DEEC_AB52_44B6_AE02_B4DE30FFA29F) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_F6299EF2_FF49_44C3_B384_4CFA61177A86) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_7D82D18A_5B53_4121_B98F_4D35C368B3B3) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_0E0D36D6_E40F_4799_AF40_4F4CE815C109) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_385649DD_444A_466B_9741_4B674A5AA37B) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_D578871C_39BD_45A8_8BE0_82DCC40E3373) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_EC7EAFA0_AD94_4D88_A83E_F94B231F3932) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_E78A5EA9_F998_43FF_AF6A_E8A787DCEEF1) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_3934F849_6647_45FB_B12A_F031F1E5D28B) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_8C7C1230_25F4_4193_92E7_8E188D69405E) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_089C9ED6_B962_49B4_9972_0D8DD803B12B) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_F0D25CE8_88A0_48F7_8A33_11126D62FE66) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_69554290_3F93_4A49_8C6C_FD0B484A2B9E) },
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
