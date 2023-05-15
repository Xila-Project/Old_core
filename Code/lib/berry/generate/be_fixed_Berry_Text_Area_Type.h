#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_0ECD125D_6A03_4692_83DD_09197E9825F7) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_9C66DBAF_CD9A_4BA8_8EB3_1A38FAE8E0ED) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_818E948D_F787_43B2_BFC5_62AC32D779C2) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_AD193C57_DC8B_4657_894C_3D987B72D040) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_4DC1C73A_B96A_4C01_B792_204034DBED9D) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_F7AE4CAF_20C1_455F_8A1B_632453D77923) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_616FD205_1BF8_456B_80BB_B6C3C4F74BE7) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_9F807C02_DAC1_4D9C_B70E_BEDB74D7415C) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_8058E3D5_AA9D_4F7C_9DF4_E1951B7C2F8E) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_0F35DB8B_E782_4580_B718_CB391CF38777) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_B00E3A95_618A_4200_9D94_DF222F72CD51) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_F8F5EEE1_9F7A_4D02_B671_FD11E154680A) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_6CBE78B2_E82E_4402_9F5A_DCBDCCAA20BF) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_8AEF75E7_0A1D_4AA0_AA44_A8C7B7582BD0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_FAE7C81B_5D83_4823_84E9_BECB8FC3ED8E) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_3F93AF4E_239D_4E76_8962_34BE11D67092) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_83DED390_8D56_47AD_9E7F_BD4109935D0E) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_51D8B2B1_F2EE_4F6D_AF40_507F10F20C9E) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_58CA705A_3F1A_4CF1_A605_945F872FAD53) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_61821909_EA50_4C22_8A3A_FD6E8D289E4E) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_797BEA4A_82DA_4A2F_9E84_5977AADB43FB) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_1234A1D9_4F3D_46F6_8924_315B9CA1A2C8) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_94DB3643_052C_4D91_B0ED_37F97018E6AD) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_B0A55D87_2D12_4CC7_B7C7_65E7AA8E0E10) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_0138BDD3_37C0_4F3D_96E1_671E0300BFDF) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_4C3FC6E5_F485_4AD9_B25D_43ED00C8E779) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_56604824_A7B6_4816_95FD_258A221A558A) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_0B263FDE_4364_4CC0_A414_78A57E056E86) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_F8B49E1E_9B8A_49AE_A2A5_F2930B883079) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_611E1DE3_AA93_4147_A5E3_0BC9E5A99B58) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_7C51C972_D2FA_4DD9_9E07_D88848208A6C) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_86861B4A_6B6B_48BB_A773_B0666E4FBCEB) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_9E8FB1BA_C7B6_470E_86EE_EA7C5EEDF059) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_80F84FD7_8797_4EF4_83DB_3D974A3097C2) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_80222FE0_9DF3_40C8_80F3_4266909048E3) },
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
