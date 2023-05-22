#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_B4F87F48_BD21_4A83_AA83_F4C94431F3EA) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_9FD1A83A_9881_47BE_B8A8_08B5146B0ED9) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_7D34C7CC_CA2E_4B26_B84A_506379FF3E62) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_0351ACB6_4163_4CFC_B13C_3BA31B777BC1) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_A4F876FB_70A1_4E2C_9247_6007A9577E4A) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_B948187D_743A_4C87_B8E8_3D44017F5304) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_ED27125D_CB5B_4D67_BFBB_59E8CFA9EA5B) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_79391E67_820C_45BE_B052_73E64202192A) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_25EF78C4_B3BB_437A_9F0F_659054B8AFA0) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_E3BA7B39_5814_41FE_A4EC_E2FCCF0B543D) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_75757981_339E_4D25_9194_1B61E72C7296) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_004CAC62_8011_42CF_8D60_CF944656CAAD) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_31C94D2B_FAB7_48C8_B821_038EC3A021A8) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_8B0CAFDB_7805_4A9E_9AE0_C9FE932339A7) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_2113FD6F_7D10_4001_853C_73EDD27D28FE) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_52F438FE_DAE4_447C_9D85_AA09190B6599) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_4D9A1D19_C467_45E4_BC69_FC740B01C91B) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_D596D369_E556_45FE_902E_C9750FE25B13) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_786DA247_09F2_4D35_977D_130E72C16ECD) },
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
