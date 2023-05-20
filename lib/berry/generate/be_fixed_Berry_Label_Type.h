#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_EB2AE07C_3F2F_4478_B8AE_6B0922D4464E) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_F4C51DDF_FA64_4A89_9D38_41455EEBB96D) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_E2A9693D_4215_4F84_8946_11A59817A4E4) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_9CA92F05_AD27_4E6E_ADC6_ED5EDE5ED94F) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_42512DDF_559B_4593_B8E0_F6596C37B714) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_8C36683A_4781_4FEB_AFEA_66D3E97C1EC4) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_C6620937_35B4_4B49_9865_BB5B8BAA65D1) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_FE6A06F7_6ED1_421E_A988_B14EA5FD028C) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_91D06DA3_BC2D_4151_999F_7CAF3FA4E4E2) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_D0495F64_E46C_4753_8D8E_FB1F95AB56C0) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_E6636D99_9B14_45F1_B58B_B7BF1EB0BCBD) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_AE861429_60BD_4B2A_AC12_8C05387D0722) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_ED7FD186_20DA_4AD2_B52E_6791CF446524) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_EBF7CC8A_D336_446D_A645_0754CD563AF1) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_11051FC2_DD25_4EBE_81AB_0010201A5693) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_624CAC98_9424_46D2_8AC4_5AC1DD286178) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_1E716979_9817_414D_AA1C_29E4C2895C89) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_6F3253BB_4C96_4BD8_A13D_AA7508B6EA6A) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_28550CEF_E79B_49AF_A973_A6CE2C0D1A54) },
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
