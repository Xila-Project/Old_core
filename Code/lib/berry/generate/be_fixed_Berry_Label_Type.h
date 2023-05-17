#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_37C1E47D_0CF2_459F_9DE8_D781691C34B7) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_817FFAC5_CC2F_4773_BE83_3E6D7655B1BF) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_63389A42_D0D8_4E5F_9710_133AAF3C5846) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_5D938FDB_0C06_4F61_B6AC_702A2656D8BD) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_B3CD00E9_81C9_4143_BB83_BB3707C1409B) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_66658D7A_4201_40FF_AA2B_F3DEF278ED41) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_0B2AD8A0_3C18_4A08_81A0_982E5CDFBA6E) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_5735F66B_CB11_4867_B562_8375F62006F5) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_27D75D2E_6425_47D6_8457_9BD93ACB8625) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_CB9EE9BA_9E77_44E3_8D18_8673DF4C1C1D) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_47598EB7_2FD4_4828_83D8_EB49DBDA0422) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_D362C5FD_00B5_4A5F_844B_E51E8B5F1B7B) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_A7513677_7BA4_409D_91B5_9958008B0FD0) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_2BF1FD72_787D_450B_8FCD_15D5A0FFEC20) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_D934DC63_A18C_41B7_94E6_59A27B04DA57) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_1CE06103_8D9A_4F1A_AEB7_ED42E2AB94A4) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_9796FC3B_8ADE_4DC1_B74E_5BB0CE54E560) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_0CA41E34_5288_4762_B902_6CF515EE6B89) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_399FF5B1_712E_4759_A2C1_2D7A14308AF3) },
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
