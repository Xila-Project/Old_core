#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_9AA356B9_5F9E_49B7_97EA_39367E1E013C) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_385DDC6C_FD65_4B10_8178_2DFB948EF5DA) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_1B95EF9E_AF1E_4EA7_A79B_15278384FFA7) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_3BD684D4_C04F_4D9B_BF09_0C1EB3203270) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_E7D7B3D3_F78E_4CBB_9C24_E5483B42B464) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_C4AD4B87_AAEE_430F_894E_E5E8C8799007) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_6AC2FA3C_1681_4612_8DE6_D818F416ADCB) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_B6AA0BEE_F01B_4602_A5CC_AC2A2AAC1783) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_2B57BE6F_6C43_4CC0_B9BB_FF636FCD4CE0) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_BF8D4996_0FC1_4740_AC0F_CFB2F7BAC9F0) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_E75E0783_F3A3_44CC_8F2C_9F43C86C0B82) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_F116B8FC_EB9C_46FD_93AC_C9FCDFE9ADCF) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_E95F7135_4DF3_46CE_BB8E_A32C9B253E85) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_03161C8D_2BD8_45DB_BD57_F17B6BC96290) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_E393DCF0_62EA_4C25_9FCE_3221BDCF7757) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_DEE99FBA_0EA5_4172_AC88_DDBCDA417976) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_71AD569F_7704_4595_A12B_8A5344785958) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_5CBA3E6F_2ADD_4BCC_A25F_76F4A4A2CB60) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_496D938A_A4AD_4D91_805D_CE86CD71EEC3) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_9FEA2D34_9DFD_400F_97F3_1D22D2950E72) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_8F909228_4AEC_4DBF_9B54_CCB416989CF3) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_73E3F28C_0710_4B77_A533_17800714C07F) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_3F0C2DCE_BDFD_4F34_A9DC_A84F568BD064) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_49C756D6_3252_44F8_8CBF_036AF4405BD7) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_314ADBD1_6F3C_435F_BE8F_D1C0799F1193) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_FAC0F23D_9EC4_4C4E_93A1_E4196138D8FF) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_BEBF9B15_FD80_46F4_A4F2_9C4606E667D3) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_607917B1_3D87_49C3_9811_764F9F648A6A) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_6E9C51D6_2A06_487B_966A_4ECF09C42B5F) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_8A131F61_C1EA_4D09_A993_5A6AC44490AA) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_C3371933_5060_4764_9558_C89D53905E09) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_BD4E023E_9D3C_4346_A3F3_D1F5601D9F1A) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_34B0C74E_E0BF_4E65_BFEC_D04566D10517) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_B2007500_D724_49DB_B77B_AB5663871BC9) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_46778039_6FB4_422A_BBE1_3A51A7A70A24) },
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
