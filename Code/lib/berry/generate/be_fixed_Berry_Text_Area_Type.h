#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_D7DEB1AD_4B22_4D17_95EF_790948598141) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_A81CBFC1_CC3E_4F0B_A43B_C47CEA918E8F) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_C9DAF642_A7AF_4B7A_AC6D_2851945C81D5) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_FDEF0E01_CA8B_4AE2_9AA9_32E4082EBFD4) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_CD72578C_990E_475A_8524_234A57BA0470) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_4BB452E5_3E85_4458_A82F_3C214BA94DA9) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_B56951C7_48B1_45ED_AEB2_F53F8197F274) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_780BF69F_57DC_41F0_8532_35FA9159150D) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_1611E947_C8E0_4663_BF52_5F973FC6EFF9) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_3CFFD789_E62D_4A6B_B8EF_715F53A16599) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_D28A3C3F_58AF_42BF_9F43_29567317637D) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_3211961F_4EF8_44DC_8DD2_2888831CF899) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_979EEE72_E711_4C69_BEA6_0C09E6C1567B) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_DADAFF31_5BD5_4229_B7E3_E04B1E1BBE95) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_E5DEF0B6_2FC4_4875_92E3_D868B38C4B33) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_41DB7A2B_DE2C_4358_B599_67FB7F5759B9) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_06D1B43C_A409_4967_A17D_779F7CEB90AE) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_08BBA688_452F_4336_855E_F90DCFB8F0BC) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_86623A19_7ACC_4E32_A976_595CDB20DE3B) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_8E6D5BFC_0531_4AAA_BB77_4892B00A9EF9) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_F85B8D06_1CAC_47F2_943E_4E4D4CE87D4D) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_2B9289CD_6A26_4D7D_A28E_37B0730CFEB5) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_5ECCAD31_2B98_4D75_92B0_9D5B4AE652B9) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_2D1AC13B_0516_452B_A412_906D18D8F6F6) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_7F9CCB68_3CA2_440E_A206_34E36AB69519) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_FA9DD1F4_2C29_4537_855E_B237E4CFE99F) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_D92C6098_DAFD_4476_8E01_1CCD22AA7763) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_A9060E80_BC47_4CAA_93D9_9DABBCBADA20) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_171CB314_2456_4DEE_A0BD_84C7F1A655DD) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_18343C57_74B1_4E6C_9578_CCCC3F09A7B7) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_E2820661_0BDA_4067_B16B_41988C774BA4) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_37A06AF9_544D_4AEF_AEA3_A105B41C66B6) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_0F29B8F7_5931_4648_B2AA_9F81E862E040) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_EAC9BE9C_4B5F_4746_9876_62523C396C39) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_27DB9DCF_4B5E_49E8_AE31_95807C3F4EAC) },
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
