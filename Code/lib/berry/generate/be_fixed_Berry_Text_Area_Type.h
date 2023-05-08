#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_9EA67C47_B5A1_4457_AB58_E2F4626AC1AB) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_CCFE2C70_7C75_4855_A09B_1620772FC4A3) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_BA111372_7D37_4479_AAA5_A5E8FC4669B8) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_F3EB3DB7_B96D_4CF3_9A90_C0FBBDA1DB80) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_B0C7D7BC_FC3F_4CA9_8A22_EC65E77DFC87) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_19B912DC_5A79_4D5E_BE56_679499CD2646) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_A11F0D75_6DB2_46DD_836F_D248DB468E36) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_940F365E_D67C_42A2_B3F1_A98EB47B19EC) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_7E89B129_EA64_4FCE_B656_2DC41B48AC3B) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_AC35DBAC_18FF_423F_A62F_D604F11E04EB) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_21A46DDE_75E2_4142_BE48_ACD8169CDFA6) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_F3AF8D02_0437_4CB2_A621_8B58B69F920D) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_6728EB0A_D766_4468_8B94_132745814D98) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_5A4EEBB2_9766_4AF0_A943_14B65678DBA5) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_0E6E1CF8_40CC_4D0B_8065_314FBFF38C70) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_FEBFAB26_44F6_4A31_9E05_65E1FF2BC0F4) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_BED99B96_DA93_4F0B_BFFA_2947AF1739FB) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_739748FC_DB65_4E88_BA24_48E2EB3C7808) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_4E3D49FA_38E8_4AD4_B925_62FB677D236B) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_7D370340_5D13_4109_A6E1_9A9200370B6D) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_51A599D4_3E0F_4DEC_92C4_684A59091473) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_8EE3A1AB_6A94_431A_AA31_4C4BA1BE27E4) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_1C1904FC_C4E7_4CB2_AC5E_1F9A1290A5C1) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_3B88C130_372B_44C7_81AC_755248FA4533) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_2A1B285C_EE04_4B11_8719_353AB8103473) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_E22FF2D4_752A_4BB9_9F52_24A9BF6B8929) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_C0A18324_2DAD_4B09_AE44_A518795D122B) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_4347C4F0_29ED_44A1_942A_40006086CA51) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_D0985DE0_F253_4657_A122_D65CF68B25BF) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_ABF3DC02_5512_48D0_A222_838751010198) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_C1C7B9B1_AA59_4EA7_BFC3_60881E709431) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_D7756098_B008_46CD_AE28_A2D599469E8C) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_43053490_C24F_4849_A055_37A449AF93EE) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_E2085629_7765_495B_8904_9BC24DF5CB51) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_B6F5D8E9_BBE9_46BA_B74E_1E8A9EFB4767) },
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
