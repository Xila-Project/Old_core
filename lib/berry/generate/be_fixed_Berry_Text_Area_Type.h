#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_BEF0C91B_6D05_4F33_AF78_B987A25B573E) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_9233FBB8_001E_4CC3_A82D_0128F488F94E) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_C4447FE7_D1A6_4950_A514_3AEBECF3A73F) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_3467F7DB_5E44_492B_AEF4_D65AA80224CE) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_29839575_65D0_4BAA_8117_90568106442A) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_853D5671_F558_4605_B0DC_1E843CD99E26) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_1E1ED76F_D1D0_482A_A182_2AF909729206) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_2AC88A87_9C86_435B_B43B_10958CC369B1) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_14F52ED0_319E_4C9E_B1D3_66BF1C277DB9) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_8601AD11_D2EA_4EA9_8F48_62E6A9210207) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_297752A8_00C7_4ADA_89EF_ACFF48006216) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_CF2B1786_12D1_4F28_9088_96B06ED4C661) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_65CA7BCB_2046_49C7_870D_2B3E510D64CE) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_A31DC696_62D2_4190_909C_449543A286CB) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_A176CA1A_4B11_4D07_B363_AA63EE6CDB22) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_B808D7DB_298F_40FE_8DDB_C0B25EA8036D) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_8A94859E_873A_4179_9F04_1FB85F2B4E62) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_C1F18983_186D_4502_BEF4_5695547D171E) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_301976AB_6546_4CD0_A135_0D020CB4FD71) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_5D124BA1_1177_469C_A7E6_7FEF3FF1003B) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_A5820BBD_4FCF_4C21_AA6C_F1CF59EA362C) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_876E2EEC_9418_412C_8397_5A380A32CF03) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_38A01940_C4DE_4C69_B9C2_2B91D2E049C9) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_04B25003_6AD3_4B70_9A9E_CA00EC4488FF) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_0500BA84_5664_4967_B83D_23D326B33494) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_04F1A6E5_A93F_4A79_844A_1EDE7C2CA0C4) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_98E0AAE6_A111_443A_9164_93C8DD515A96) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_BE026E60_6381_4EDC_9A53_3721F78912A0) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_F72F363D_47FF_47A0_9342_A4B71F36AF5B) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_0AC0EAC5_1CF1_49BB_8426_6C6DDC4BA829) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_8362EFB5_7506_4C00_A64A_F4D7B902BD47) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_235B600F_09D1_45B2_99D0_D3FEB39C5310) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_B039FD3D_09CA_4A0D_9B30_4ED252B4137D) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_92EAF2EC_724F_41C5_A515_5306D2A7B643) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_DD1B7E25_3C64_437A_8A0E_458579DEF4FD) },
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
