#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_8A86D709_3C97_48C3_99A7_D30EB35D4835) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_A5818C7E_974B_4C27_A012_E6F338DAFD92) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_B8FA0EBF_7979_4A3F_972C_365D355F767E) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_FBC4BB42_C50B_4933_A9E1_23CC7B169979) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_820B8D16_84F9_426A_9FF4_D148877B7F06) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_25AFC2DE_8F90_463D_B06D_DBD37C26D7FE) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_5D4C9F21_D141_495C_8AD1_F93908EBBDFE) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_C8649847_B031_47C7_87B4_C8281019EBC4) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_AC3B3BE0_D3FF_41AF_B230_589394877717) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_7C72174E_8EA3_4398_9FC6_97C24A8A8A3B) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_00A6E883_B90C_4BE5_8F4C_87C0959E68C5) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_BC66A439_34D4_4C6B_AD26_13E7E1DC7AA2) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_3341A6A4_C2AD_4C4F_BE7A_6CAD3AD1FB15) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_E90B2E10_2CF6_4999_AD26_48B151DCFCF0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_A335011D_6EFE_4683_8C37_5CFD30F6438C) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_326EBA7F_0345_430D_97A2_6523FD4AB319) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_641B1E61_032F_4B70_9A68_17CC7268B0C7) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_D8F54753_9E8A_49E4_BCC0_5518677ADE60) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_A48CFDF3_A347_4939_9D8B_CD136A88197E) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_A1F1B19D_C55C_4E26_A94B_D9EB1F98ACE4) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_90737299_77E7_479C_AFF6_8FAA4706032D) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_DEFF9698_FEAD_44AB_873A_D0BA9A00F0EB) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_4789FECA_FA9A_4147_92BA_8E5DAE15E4B3) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_5721242F_2433_4F0F_8F6C_4D02C4023F9E) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_74BBA982_F6CC_4B7D_B666_0EA411C859E8) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_EBB76167_F1B4_4B7C_9F3B_46622C4409F6) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_3EABA188_395C_4F9F_8A3B_0D6F9CDDF7FD) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_E0C8E241_E1D4_4884_AB23_332F8D029D4D) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_FF2E0124_1C2D_46AA_A03F_6CFE797C8553) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_BDDDAB1C_24E6_4E87_AEBE_C0AC002B6BE7) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_4245EC6E_BBC2_40FD_821E_E545B2330DFE) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_E09EE26E_1A83_4D61_A1DA_4EF75B0981B6) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_6FB0EF3A_CF4D_4C1D_9208_7A3F2012E584) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_167D7F10_29AD_46F9_B143_96D3B0558E0C) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_272018E1_7C2A_445F_8B2D_1BD3237A3D64) },
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
