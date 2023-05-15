#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_06700FC8_BA41_412A_B4EE_B2944745F7A0) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_259513E6_4A80_4ADB_B7B8_F32CBFF02FDC) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_57C782CE_67EC_433A_9FBA_AEC132BAE0BB) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_5F398E53_1878_470E_9CD9_715D82136D6C) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_8219FB62_2A21_4F38_AAEA_D56546F45A7D) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_5516C539_ACDB_4218_B5B8_3B90BC38EC40) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_1AF6F899_2ECD_4717_84D2_9A9AA2654DCB) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_63C39C98_1F3F_4D97_A03B_01C510F60771) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_D032E06B_85C6_4FDD_908C_BA26D6DDFC19) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_8B7C821A_2FAF_4C90_94E3_E0845F2F00E8) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_43B1ED6C_5484_4486_B996_B0E186BB5DD8) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_915970DB_F2F1_4F51_A300_8DE026DE97F9) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_6EE95303_2A5D_4B81_9FB0_4E5DE48995AA) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_627D119B_E978_4A63_891B_243D3EC104F4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_41B9A1CE_B458_4A3A_AEEB_90285ACC2EBD) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_7C72E7BD_AE55_4EFF_84B3_0CDC6EEE9142) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_AE3A0150_ED64_4BEE_9183_645EEB4873AD) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_7B91EDAB_3833_40CE_8C02_B669AF46288D) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_898B6FC1_DF55_4967_BAE9_D05263F994B3) },
};

static be_define_const_map(
    Berry_Label_Type_map,
    20
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Label_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Label_Type
);
