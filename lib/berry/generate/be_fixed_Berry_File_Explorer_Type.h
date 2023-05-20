#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Explorer_Type_map) {
    { be_const_key(init, 5), be_const_ctype_func(Berry_File_Explorer_Class_Initialize_8B9E52B1_DA3F_4E96_B20E_F81D4CCE06E8) },
    { be_const_key(Get_Path, 14), be_const_ctype_func(Berry_File_Explorer_Class_Get_Path_78A8FE86_F99D_4642_A922_C037D12A7C7C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Go_Parent_Folder, -1), be_const_ctype_func(Berry_File_Explorer_Class_Go_Parent_Folder_8A0011E9_1B28_4ACD_9471_36279B5B5A38) },
    { be_const_key(Get_Selected_Count, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Count_3C75D6FA_9113_4956_8C05_43F0905A5B99) },
    { be_const_key(Get_Selection_State, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selection_State_E145EBBC_870F_4BA6_B882_3D0A227AC649) },
    { be_const_key(Refresh, 13), be_const_ctype_func(Berry_File_Explorer_Class_Refresh_ED4E0905_A33B_41B5_B5A8_38D7E09DA48D) },
    { be_const_key(Get_Selected_Name, 11), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Name_B62CC36A_30C9_4E33_B547_B965AADB96D3) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_File_Explorer_Class_Delete_DDF2D95A_5EEE_4B1B_ACF9_A46CF2CAEA70) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_File_Explorer_Class_Create_60DA9192_3B2F_4867_A99C_837721653B6E) },
    { be_const_key(Set_Selection_State, 1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Selection_State_7E769020_FFA4_479B_9149_B09B80C58D7F) },
    { be_const_key(Get_Focused_Name, 12), be_const_ctype_func(Berry_File_Explorer_Class_Get_Focused_Name_939568FD_E4F4_4749_A215_0D18B35EDBA4) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Explorer_Class_Deinitialize_F5EF6B76_8683_4880_A00B_9309225632A4) },
    { be_const_key(Set_Path, -1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Path_B73BD075_3BE5_48B1_AC8F_07288787F34B) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_File_Explorer_Class_Clear_Selection_77E65935_4E4B_4D9D_90CE_569808993EB1) },
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
