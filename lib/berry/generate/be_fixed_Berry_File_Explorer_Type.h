#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Explorer_Type_map) {
    { be_const_key(init, 5), be_const_ctype_func(Berry_File_Explorer_Class_Initialize_36A85895_61D3_45FD_9C71_0831B16711A7) },
    { be_const_key(Get_Path, 14), be_const_ctype_func(Berry_File_Explorer_Class_Get_Path_889722FF_2CE6_4D7A_BE86_6EC41609A313) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Go_Parent_Folder, -1), be_const_ctype_func(Berry_File_Explorer_Class_Go_Parent_Folder_F95FDEAE_3206_42ED_BA72_163BDD174F10) },
    { be_const_key(Get_Selected_Count, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Count_54F2203F_D8E1_483B_AF92_0D5E71AFBAF1) },
    { be_const_key(Get_Selection_State, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selection_State_0DDB481F_E615_4F3A_84D7_1F2F9842EE13) },
    { be_const_key(Refresh, 13), be_const_ctype_func(Berry_File_Explorer_Class_Refresh_2F2FF1CC_6DBC_4705_B811_EAC64BD34690) },
    { be_const_key(Get_Selected_Name, 11), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Name_9F075C86_9DA3_4ADB_AEA1_4721F3F178C1) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_File_Explorer_Class_Delete_7BF0B0C0_A938_4EBB_BE81_2E96206575C3) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_File_Explorer_Class_Create_BEA62053_6C72_47DA_AA6C_B9BCA8D17AB6) },
    { be_const_key(Set_Selection_State, 1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Selection_State_216E1358_FAE5_4C20_AB0B_FC0B387563A7) },
    { be_const_key(Get_Focused_Name, 12), be_const_ctype_func(Berry_File_Explorer_Class_Get_Focused_Name_D66DA507_0F24_4EA1_8D52_A53CBEBE53C0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Explorer_Class_Deinitialize_EF8C0AC2_02BA_4A36_AB25_FB13DB68D98B) },
    { be_const_key(Set_Path, -1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Path_42E4C3CE_5670_40FD_951A_5120CE197614) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_File_Explorer_Class_Clear_Selection_8889B42E_A804_489F_A2DD_9416F6CB53C2) },
};

static be_define_const_map(
    Berry_File_Explorer_Type_map,
    15
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_File_Explorer_Type,
    1,
    (bclass *)&Berry_Object_Type,
    File_Explorer_Type
);
