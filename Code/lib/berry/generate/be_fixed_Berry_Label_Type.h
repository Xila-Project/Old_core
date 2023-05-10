#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_F2D744B6_D3BA_47E3_AA88_4DFF4E035B4D) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_88A23469_047C_4372_BB45_83ABEC66930B) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_7E2B847B_F455_4341_B6CA_3F4AE27E0D02) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_4748D688_E758_4DDD_870A_6F17A922D4A3) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_CD6BE489_E3EB_4B34_AC0E_A7A0C95A9756) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_3B2A9F59_B0CD_4D17_A20A_95D80DD8EEBD) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_8AEF174C_49FE_49DA_9E1F_C8FFB9972AD0) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_6A5BAB3C_07B0_4DE4_8DF5_F192C39B1936) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_7146FF15_E5DA_4997_B335_51B56188014A) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_8796052D_B47E_422E_BB21_C72FD7038467) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_7E545BCF_A2D5_4DCD_A4A7_84B937BA6CEF) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_D88CA358_3171_472E_A601_04CD6B98AAD7) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_B2F2FA1A_ECE9_4E8C_A3D4_C41F15F4D579) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_E8C07E89_7790_4B4E_9B8C_C55A1C620A58) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_7912937E_20E1_41BC_8FB0_15968866138A) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_B72D3E9C_255D_4978_83E3_850ADD18A53C) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_BAADFA91_21DF_4DE1_A72E_A534E0B18310) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_4E51B7E1_693A_4D08_A57A_62A489DD2364) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_11039353_46FC_4A1A_A6F6_1FA6DC44F7DF) },
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
