#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_B7B4B892_E916_4D1C_9C1E_549BD8986C80) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_3C04660A_C7AE_4D75_9128_14B8EAD011E2) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_A8A638FD_EF0C_42F4_A3B1_8E6B70480897) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_F074AB0C_35FE_4776_89B2_335803BF96DF) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_616A54AE_2D51_4A93_8DAE_C05EB9BD2EC5) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_737437FE_9B4F_43A7_AFDF_A39A41EE4353) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_AE1A1315_D143_4390_9CA1_F706E0C1F402) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_75D69FCF_DE14_4082_B4FE_8FFF681ED074) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_6DC3CCCE_AACA_4209_8743_16AAE9CD4761) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_E88C847E_CBFE_4429_86A9_1A1C72D20175) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_3A3D2720_8C58_40C8_BFD0_98D1111962AA) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_98537D34_BCB8_4D3C_BE15_0C23AE01E307) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_ACEB565C_1184_4178_A75E_D01F4988AB75) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_88A96D88_3598_457C_9209_2F6CA2B65A1E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_85A03B16_DD5E_4C31_80CA_FC1139E72E59) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_55C836C0_9F4F_4AED_92F3_F856554925B0) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_1ED04189_A247_47AC_AAF5_6E91A81E71C5) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_B296B2C2_CA4A_4821_95E3_16E85265E18C) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_A5E6DE79_BD80_485E_845F_01BE46541713) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_4C92F7BB_5A99_4514_A625_030B9D77D5B7) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_0BA08E29_A701_40BA_B70B_2A9AF97D042D) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_27B81D5A_3F4B_4F13_BFC9_99001A59B695) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_7ADABE6B_8B0E_4150_8270_EC1B6574A8AF) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_5FDECF7F_4F27_4975_A312_89EA9CD1C1FE) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_37188747_ECD4_400A_9AE7_D983261502AE) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_B7F99472_CBDE_4647_809E_F0341DB5B4A6) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_412042EA_4C34_46D4_8113_9AEA5083F54A) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_75DB8DAA_9E47_4A02_A091_A28C5C5F92D8) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_E38D4D34_0C58_487E_81AF_E4AB3CF2C798) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_9B0015A6_A4D4_489E_872F_F924FAAB7D28) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_9DF58C89_07DA_445D_B76F_0D3FA5CF49AC) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_2624F9E0_1545_43F0_B42F_D9321A1CAE9F) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_D3DC57F7_8440_4235_B33A_C1E068C917DC) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_3383E31A_325B_4FFF_B5B5_A9D807D30A18) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_AE0192A3_E2E8_419D_A800_E4928F187CFE) },
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
