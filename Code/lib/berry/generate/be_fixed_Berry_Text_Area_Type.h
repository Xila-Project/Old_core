#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_82E90558_F9EF_46C4_93BE_A3BF24FA4B54) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_43719A00_C5C0_4952_9197_11D186AADA33) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_C1C90076_8722_411C_AFAF_4D66A4F94032) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_56E574B9_09AB_466A_A520_9794DFE70728) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_0499BE33_4847_40BD_819F_52AC86FE6CD2) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_BFCC2998_6BD1_4529_B252_351A06F2AF5E) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_FB964FCC_2122_49E7_A337_135295F33FB9) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_9C62A838_4220_4EAD_8120_40AE3ED9A846) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_BC143E2D_1D2F_4EFD_9BE4_493AC396ECB8) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_990641D5_9F8B_4514_B000_1654F35343FB) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_5A883D2A_4327_4E26_9CAA_5D3913897FCF) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_CBB9B434_D8FC_4B96_9666_8C4A3364804E) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_65AE18B6_22E7_48F7_B09E_D6081A1F5438) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_F33B733E_2BDA_4140_876D_365F6BAF311C) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_9BC92B16_3999_4AE0_BEC9_3C89315A4887) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_15FE5878_E657_4669_A565_1D4592273109) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_E896C22E_754F_4433_B733_63A331933480) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_C2F39513_2668_475D_B1D3_F3C2612CAA30) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_4EBD9253_816A_4B47_A99D_EEE07B1F0BA4) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_32CF8420_21FB_4024_ABA6_553B5A53144B) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_22204296_2F58_40B4_9556_931E76F3B4AC) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_C811F741_1F75_4B33_B91B_AB3644B510CE) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_755D380C_8F4A_4A4A_B5B7_E0A3514F9082) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_929DAF34_239F_40FF_8745_87830E574BCC) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_584AEDE7_3234_4097_92CC_A281F9E0B07D) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_7D531E2D_5E9B_4853_A3A5_5BA0E596DC59) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_EA329CB1_60CC_48DF_9571_732F56FBC913) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_F31996EE_9230_43B9_A57F_39EFDFB0404C) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_2CC9D13E_E54F_4C4F_93BF_1A6E9342C170) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_2B057542_628C_4D8E_83B4_A6B728941CF7) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_1A048EB9_D9BF_47A2_A868_A413D67D3C2D) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_D8B076B7_D14B_4CDC_A69D_DE09A0D5A392) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_0B53B20D_F221_4F43_B723_6D5FA62ADD63) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_D26D9B49_5AE6_474B_8FB4_516B92827432) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_50CAE0F8_5165_4760_8323_851C101FA248) },
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
