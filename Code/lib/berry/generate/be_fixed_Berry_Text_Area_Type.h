#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_DFA0F092_7154_45D3_9494_F75EF1974A93) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_A94E01C0_024F_4AB0_8C21_8006F0207030) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_FA7325E2_5DD7_449C_A529_367CB48C22D8) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_7E836ACF_700D_4EB4_B5C6_59C9C3ADA557) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_F2351283_8307_4811_BA1F_2E42F8E8A21A) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_60585C8F_6BB9_454C_9720_2DD1CC363BB4) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_C1C4F815_E048_4E3D_9564_92ECD2FCE8C6) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_BEBFACA9_5437_47F5_8370_04B103983469) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_0B69D47A_97AF_4E9C_B65A_CDCCC9AE21B6) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_1262F52A_59BA_4740_83EE_3449173D7132) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_0C49001D_FEEA_48DF_8E25_4E0B403F3600) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_FF15712C_B2AF_42FE_9F8C_9BFE31567C50) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_B553CC94_2E62_4EB0_A559_6A0BBF181E86) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_AE4A79F6_DE06_4848_A8AE_91F20413DD45) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_108D7E49_FFEE_4D19_9032_6D08A0877C18) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_0B0EFA18_12D6_4C5E_BE0D_C0471CD72530) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_BB275223_B744_477A_A101_05015F2F99E4) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_DDC5A85D_66C7_4AE5_ACD6_33F031F4BE81) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_65F5A23F_D40A_4D93_BC5D_11D8C7289483) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_E5F277F8_8DB6_4456_A0E1_CE74C0C5D92C) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_D5085934_8BA1_4D69_9E7A_FC7746BE1B45) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_80D513B0_8F19_476C_84B0_CCABBD3EACB7) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_3B76DEB5_947E_4007_B3F6_7465AD1116A4) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_4015FC08_A607_4C22_8C30_782737A7794E) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_9AD03F7D_E59F_4AAB_BE8B_476F766EA985) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_AB20C03E_1C3D_4B03_8A7A_EBB8926C34D4) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_027B3CE6_A543_4F5B_ACAF_701F2BB24F2E) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_026767B1_05D3_4022_9B7F_1BECDC1F1BF9) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_23AE836C_2DF0_4AB1_80CC_3458C5C2CB59) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_4EF9B7AF_7744_4634_89FB_AD227449DA10) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_A57468D8_425E_4343_A079_7CFFDF53E8E8) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_51A6755E_EE02_4215_839C_6A9C6486738B) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_E76FF883_FA8C_4D35_B4FF_D9A9EEC87143) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_37C0B1FD_340C_4205_A019_78CC48871C88) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_F7E86AD4_F774_496E_9FD1_E96F7CA82424) },
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
