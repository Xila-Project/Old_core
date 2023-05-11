#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_D818ABF8_AD4E_4008_A6C5_342AEC200568) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_F2A07F81_401B_4EC7_9515_92C16EF2A4B8) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_217CC1CE_AA7D_44D9_9E92_6174C9322A49) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_B7205DC5_258D_4693_B9D8_69995832906F) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_AD1DEA9C_2825_41D4_A57E_790B18B415C6) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_ACBD5324_DAA9_4D8B_ADE8_29457AC783CE) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_663EC8AA_F064_4A34_BE06_F54B5CB013E1) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_6662B0A9_3DF0_4569_9B6E_7ED9977D03F7) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_754D2FE0_1A4B_4A81_A29B_4842F609039D) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_0338F91E_7739_4764_8384_C4F7B4CB93BE) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_025BEB21_0D3B_4106_9E7A_4EE46C211E43) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_25AD6629_D450_4DD1_80D0_46032449E475) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_2FA386BB_77DC_417C_820F_F5A36743FDBB) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_ECCE0023_EEFA_428D_9936_3C627A5DE4CE) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_60C45224_DA19_478D_93B5_27FCE382CB9E) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_94793332_32D3_452B_944C_7F82BDE0C656) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_7688A10D_A81C_4F51_86E9_E0AA4B25135D) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_D4D99AFE_D564_48A7_93C1_03C0F0C8F53F) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_F7E4C3C4_ED23_40AE_AF2F_7C122363C59C) },
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
