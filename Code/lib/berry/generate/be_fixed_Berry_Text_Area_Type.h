#include "be_constobj.h"

static be_define_const_map_slots(Berry_Text_Area_Type_map) {
    { be_const_key(Get_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Placeholder_Text_468B70A8_BD89_4E74_B302_8CF8B6DDE2FC) },
    { be_const_key(Set_Insert_Replace, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Insert_Replace_B0667EBB_0213_421A_A547_273D4659E523) },
    { be_const_key(Get_Label, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Label_4925A739_4023_4FC1_9F84_1D05697FB096) },
    { be_const_key(Set_Maximum_Length, 17), be_const_ctype_func(Berry_Text_Area_Class_Set_Maximum_Length_6A4C0FBC_0352_4281_93FF_878D55FA1EC6) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Text_Area_Class_Deinitialize_CF554621_C0E3_4D2B_8A3D_4FA2B80D6588) },
    { be_const_key(Set_Password_Show_Time, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Show_Time_ADC9DD14_D9C3_402B_A427_9F9E22AC6560) },
    { be_const_key(Cursor_Up, 0), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Up_0764356E_0046_4EA2_8202_FBA577C6FD60) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Clear_Selection_08E91E68_B5BC_4BB2_B972_3B028C8DABF5) },
    { be_const_key(Delete_Character_Forward, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_Forward_301173A3_B104_49BE_B257_8E29E136AA2F) },
    { be_const_key(Cursor_Left, 6), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Left_82C8391B_8CFE_43D6_B102_CD9F80C10F64) },
    { be_const_key(Delete_Character, -1), be_const_ctype_func(Berry_Text_Area_Class_Delete_Character_A587CF4D_E17C_4030_A641_BD82D4FDF848) },
    { be_const_key(Get_Password_Show_Time, 20), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Show_Time_EE719740_E614_4BE9_BE4D_CF188F29585B) },
    { be_const_key(Get_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Password_Mode_9BBFD2FD_D354_4239_A818_A27592717C5A) },
    { be_const_key(_p, 28), be_const_var(0) },
    { be_const_key(Add_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Text_2716A22D_E529_450F_AF03_95CFB47925E1) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Text_Area_Class_Initialize_6831C572_E68B_4505_B3EE_5EC13AD09E7D) },
    { be_const_key(Cursor_Down, -1), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Down_779A9362_5866_48BF_8101_F5B947A9CFF6) },
    { be_const_key(Get_Maximum_Length, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Maximum_Length_3371D819_8448_4643_A9C8_F75BB51FC0CA) },
    { be_const_key(Get_Accepted_Characters, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Accepted_Characters_B64E60F6_C4F8_4B43_9502_DEF66F7F6D73) },
    { be_const_key(Set_One_Line, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_One_Line_B36830F9_8522_48B8_B8F3_7E6DDA2F9E33) },
    { be_const_key(Create, 31), be_const_ctype_func(Berry_Text_Area_Class_Create_DD3FC061_41B2_4851_93CA_71DB73EFE1A0) },
    { be_const_key(Set_Text_Alignment, 11), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Alignment_E746ADFA_B52A_4B5C_A61D_FFC3FBBB2C10) },
    { be_const_key(Set_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_Selection_ABBD04DE_C480_4219_9044_87E84E608BFD) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Text_FBE04E06_9A34_4F66_98FE_B8240CD5C279) },
    { be_const_key(Set_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Position_023E3925_7133_4D9F_B53F_DC4F3CF13F95) },
    { be_const_key(Get_Cursor_Click_Position, 12), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Click_Position_512E2015_07FC_4A67_8F7F_363CB38DF81E) },
    { be_const_key(Cursor_Right, 13), be_const_ctype_func(Berry_Text_Area_Class_Cursor_Right_D89DC437_663C_4A72_A787_C14422F62ADF) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_4567E8F2_ED8A_4D28_9292_0558FD82F301) },
    { be_const_key(Get_Text_Selection, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Text_Selection_09CF6F3D_9AF6_4DD1_82D6_D211EC3FA935) },
    { be_const_key(Set_Password_Mode, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Password_Mode_180B545B_E410_4CC1_BD10_7D41889ABBC1) },
    { be_const_key(Set_Accepted_Characters, 1), be_const_ctype_func(Berry_Text_Area_Class_Set_Accepted_Characters_3E0BD07F_C17F_45C2_8C47_7E40480225DE) },
    { be_const_key(Add_Char, -1), be_const_ctype_func(Berry_Text_Area_Class_Add_Char_C82DEA72_2AB8_4A16_8DD5_C8D87F0E9CDA) },
    { be_const_key(Get_Cursor_Position, -1), be_const_ctype_func(Berry_Text_Area_Class_Get_Cursor_Position_1EDE5EA5_E7FB_4481_A9DC_1CE5611FDF45) },
    { be_const_key(Set_Cursor_Click_Position, 34), be_const_ctype_func(Berry_Text_Area_Class_Set_Cursor_Click_Position_4C89AD1A_47AB_49C2_B120_B74BF4B7DDD8) },
    { be_const_key(Set_Placeholder_Text, -1), be_const_ctype_func(Berry_Text_Area_Class_Set_Placeholder_Text_951ABB0F_657E_46A5_942A_6BE6DA79CF33) },
    { be_const_key(Get_One_Line, 23), be_const_ctype_func(Berry_Text_Area_Class_Get_One_Line_A8B4D95C_021E_4E82_92AB_CBE2CCD6AE58) },
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
