#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_BB2226E6_D604_435D_A921_1805606E786F) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_6ED59C2A_F76D_451E_9388_B6C0E6BD7FE9) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_A0E4EF90_A121_4AAD_9DAE_C87132CC1709) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_35D81AD2_B1F6_4A86_9142_CAB7E4ECC257) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_E714A5C6_BF90_444F_818B_7390E0532C41) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_1BD8591E_907F_4D29_9940_6F34744E4EB1) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_08450699_D37C_4029_B248_C7F3104FBAC9) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_7DF11FB0_61E7_4549_9803_AE2E9029B7D0) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_4C78EA9C_E18F_47FB_9811_6371B28E2942) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_D77FC9F8_0249_4219_AC9C_33FE77BC9131) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_2D31D91A_36C9_4BAD_98D1_A97DFB7F12F0) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_BA80BB63_E1C2_40AE_BEF9_540E8DB03F96) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_CFB61959_2D2E_42DB_9ED7_61A9E7BB97C8) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_65D98E0A_26A4_40FA_8F1E_3746D2273912) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_575EE3FD_C841_4590_9A70_734F97C9154F) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_69358C14_3870_4F10_8BFE_CEA4AB7CBEC1) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_32A0005B_93A8_4204_968B_8DF686FA3D63) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_C03C379D_A220_414E_8690_A0D5DE0DB238) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_112E5F8B_B6D4_4B51_996C_451922A2F31E) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_6E884FA6_CA75_40F4_8CCC_73F737201FD0) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_12853CE1_E540_48D4_96D6_9288D5616B1E) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_608DD3C2_7611_4D75_B1D3_375E65A4EF17) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_B9F5AA69_A2B9_4FF2_812D_5E1B5D151F29) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_0735EDD4_65D4_46F3_8CCC_A4D54D14E4B1) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_070C341E_F940_4E9B_9958_B10728E6B4EB) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_C206D690_B3E5_4E49_A434_DA777837821B) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_CD22B9AC_CDA5_4CB6_AC8C_DE57FFD8C03A) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_EE95BFAC_97F7_4054_8D95_674BE9B8B56A) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_8658BAEB_044F_4739_B6D6_8B38C6B3230D) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_A937E73E_4F73_4ED8_B0D2_5EB747E18B29) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_38BBDB39_7940_4243_BA3F_817B4464B299) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_07238075_B319_4983_8AA3_3DECC34F001A) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_993E7529_4C68_46B9_9ED7_ECEF20067969) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_A6CB7796_01F1_4C2B_A90A_11B3EBE3F3CC) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_03F3139D_297A_4119_8DCD_E76779A09DAD) },
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
