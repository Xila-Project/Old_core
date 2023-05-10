#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_1823816E_624E_44F1_ABFC_047AB0D3F528) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_6E59107D_E214_4065_BA77_C718AF21F215) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_240ABC60_B236_4444_8E88_7D1D7558B941) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_FAE60919_717D_41C7_8D3A_A29E5AD6F1B3) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_3DF18086_4328_4E0B_BF61_91AB8C4F572E) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_B6E0205D_E6B1_4170_A924_747EDFF61059) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_953C3AE9_5E5B_4D30_82AD_89E573482704) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_1B370666_A8FC_4BEF_AF76_042F9CCD1A34) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_546D4643_7EAD_4865_BDB7_63CCAB1A8F56) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_7D0866F0_A9A4_468B_9038_9B30104C70A1) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_DF710E27_E61A_4379_9270_A30F5553669C) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_19987DAC_55DE_410B_AD32_6C024FC1C49F) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_4BC5D1EB_A2CC_4F9A_9CB5_FE43056F7B04) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_04543394_0E6C_4838_9FB8_8524C1C9E7B7) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_7F909FF1_BB81_4DEF_A4A3_4DA44E03AE7B) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_893A5BA6_6E6E_4CFD_839B_4C4E12C6B989) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_0E82ABDF_451E_4C57_9E4D_99936CA510B9) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_A661EE39_7E4D_4EAA_B488_F04D6E83DDDD) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_7885FEAE_B1DE_49A0_950A_F10A6008BC8E) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_3E0F15B0_7B46_42EF_A4C5_0F40B2C5DC07) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_7B750237_2584_46DE_999D_74C334CF3E5B) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_5839801B_A3CC_4C6B_B705_732D9B5A4EF9) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_2F0D028C_AB5E_4578_8CFC_90D729B04D17) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_5573AED2_F7C4_4775_AA4E_0237116B4134) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_54E68FF0_D05B_4D7F_8B8E_C9D8C38AC066) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_68F37DF7_BFE1_4475_BDAC_043EB77B9FEF) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_12E76306_81E2_45BD_8840_4482202B6901) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_9C1F15B5_19D3_4EB1_BCFC_41035FF4A488) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_BCFFC046_ED5F_4A90_B7BB_12BF139EBD52) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_9F49FA6D_3096_4572_9B75_BBFEFA81F596) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_C0FCDF0E_D188_478E_BD2B_64C6BA5EF15F) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_0466C09E_FA43_48FA_93A4_96766B78FBCA) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_98DE913B_D419_450B_B79D_C3D170A1355C) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_A63EAE39_AE0B_414A_A8C3_BEB0E48F7A0A) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_438015C0_8864_48A6_8C51_FC5DB16CA851) },
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
