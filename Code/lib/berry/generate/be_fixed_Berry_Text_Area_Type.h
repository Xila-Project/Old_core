#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_F11753E8_B2AB_488F_9688_A409E6CDCDB2) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_E9D0BB13_553C_450C_8138_EBCDF8E21E0E) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_35C8A579_72DD_4CB9_B335_69930658DD0E) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_58E5A40B_2280_48E9_A7AF_94BBDA13265A) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_E9341D94_64C8_4B74_ABDF_F3194D6071EC) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_C9026672_BCE8_4107_93C8_9121BB60866E) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_50A52998_FF83_4727_BB89_B03D1DF688FC) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_7A0B4C47_1CF2_4409_823C_0DA6D3C25D9A) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_949030D3_9E16_451A_A578_78D7EADC38DD) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_29F6BE37_0C78_45D2_8979_4B6E9F5D77FC) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_816EA245_CC28_427B_881A_40D4B95CEE23) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_9F34CDDA_37AD_423F_9FB3_4C021BD7EA37) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_89377A52_FCF2_46EF_A219_ED12FC88CEE9) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_152E813E_F78E_4F23_AF8D_99819C4AC1F5) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_D32585B5_692A_411F_94F3_2C9803978560) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_9A1FF60D_AC35_471D_A099_A6DE1FFD43A8) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_A389CA47_0AB6_43B5_892B_45B6E29CD191) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_8DA16051_549C_4F47_B4B4_74DF377D8587) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_81664CAF_393C_49A9_B236_3F5459E689B4) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_A5D4580D_AEF9_454B_BD0C_8ABEA75010B9) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_78706592_0E0F_40BE_8727_7D8ACFDC4C31) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_7A73EA03_8393_4A9C_8860_4F30740202DC) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_52F6FDA2_4541_42BD_B126_BD3DFA076618) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_A4161120_02CA_4FE7_8461_E43CE60FE4AE) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_94A35F2A_7AB4_4F59_9ADA_CCD142E3711E) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_D4CD2C10_1A29_4F69_B008_4CB65000AC18) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_A30A032D_FB5C_4ED5_A9F4_2A5947AEA899) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_5DFA2F28_2834_4013_AC6D_559DEA048809) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_36D51F1F_6482_416C_86B6_727CF71D7A21) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_345F1543_BD79_45E6_ACCE_E26D9A757DDD) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_8FE981D1_B725_4D7B_BF27_2743FF219B52) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_C464E331_F0EA_4B7B_A9D6_0F4632E0D2D7) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_650D1E94_E3EA_4079_92B9_9322282FD425) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_FCA60661_F01F_4F58_B195_E1DD327F9D9B) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_C0BED8FA_10D1_4DFB_A89C_730C45F11672) },
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
