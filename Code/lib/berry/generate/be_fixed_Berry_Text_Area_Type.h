#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_81578838_2619_41D0_BDA3_33BF44638ADD) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_F2A7605F_6F23_4B0D_B108_FE05EC01908A) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_44A00ABC_8EFA_453B_9386_0E37F5C9C125) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_FD3AB67F_0515_4D04_ADE6_4073A667ACE7) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_A3E90F7C_8737_4696_BC74_CA66D797F6CE) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_2433D93F_B396_417D_96AC_28F8BBE40A41) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_178D058A_6533_4DD7_935D_95197DC80FBA) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_77377CEA_6D32_4606_8B2F_34FD1068C0C0) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_25793E55_3BD1_42B8_A686_1B90307B3E39) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_E297FD83_2BD4_410D_978C_4D673FD729A5) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_14E80B49_E380_4195_875E_D637E26BB28F) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_C13264CD_D65E_4D4C_9F14_9AEA6033827C) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_8AFBC82F_BED2_456D_A1E7_A9D41114CCB1) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_EA1CEEEB_7C82_4581_AA7D_95361E31BF4F) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_CA746132_53CF_4226_85D7_1685EB31A156) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_0E84632E_D846_4A16_B8E2_C5E5576F7782) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_22B392DB_74B5_4F2F_B14E_19C92314F298) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_21891E07_15B1_4700_B672_750A03F121C1) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_546F8011_7A39_4110_BFA8_FB12043638D1) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_3EE7F841_5F67_49A6_AAAE_D912C56316C2) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_8F511AD8_41DD_41EC_BDAD_D4769667AADD) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_94D95C1D_0E39_480C_8B0A_B08D40726B3C) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_8FC932C9_2B58_450E_84A0_BA379ED14F59) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_5D5DF756_41C8_4218_96E8_E94017BF0D8D) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_9478A4AD_65E8_4EC2_86C6_FCFBB0613111) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_B6227B3A_0D48_4B6A_904B_F30AFB88EA31) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_3066829B_B844_4058_B8EA_8907A78AA8D6) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_69F968C7_A0CF_4BF8_B6E2_FBA07AD20361) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_01B00922_2292_49DD_9223_E30BD1FBC376) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_DEAEC521_E2B2_4F15_B39D_0C586BE76B29) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_C575D5B0_B5C3_4EFE_A353_17BDD82FC118) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_70CD6C9F_8D16_44C7_852D_0FF4EC40C08F) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_2BB52658_0857_459D_A793_E95F6E96C874) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_326810C1_1597_4081_8E3E_4EBD5BD939F4) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_FEC8D607_4EEA_43D1_B5C7_4CE23D7F3680) },
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
