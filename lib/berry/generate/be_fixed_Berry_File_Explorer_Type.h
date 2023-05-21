#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Explorer_Type_map) {
    { be_const_key(init, 5), be_const_ctype_func(Berry_File_Explorer_Class_Initialize_2326D7B5_AE77_4680_87B1_D28330C5E3D8) },
    { be_const_key(Get_Path, 14), be_const_ctype_func(Berry_File_Explorer_Class_Get_Path_5197D147_7DF8_4E4D_B3A9_CD461C8D59F5) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Go_Parent_Folder, -1), be_const_ctype_func(Berry_File_Explorer_Class_Go_Parent_Folder_12E00230_9D36_4CF6_BD48_9605F7BE38B9) },
    { be_const_key(Get_Selected_Count, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Count_579A243B_E7EA_4EDA_B73B_E00B917C2520) },
    { be_const_key(Get_Selection_State, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selection_State_12069B59_83E7_48B6_B3A8_7A45DEEA050F) },
    { be_const_key(Refresh, 13), be_const_ctype_func(Berry_File_Explorer_Class_Refresh_E77A12B6_C219_4FBF_AA9C_616E35353671) },
    { be_const_key(Get_Selected_Name, 11), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Name_3BAA0C77_923D_4734_A709_134C0BEC3560) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_File_Explorer_Class_Delete_41CCBE87_1698_4BA0_A564_9FEE7DC2DE47) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_File_Explorer_Class_Create_A6274570_AF91_4694_9EAC_E5967F706ED7) },
    { be_const_key(Set_Selection_State, 1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Selection_State_9DD38CF3_4D0E_44D8_B7C8_17976D7F386F) },
    { be_const_key(Get_Focused_Name, 12), be_const_ctype_func(Berry_File_Explorer_Class_Get_Focused_Name_3A4E63E6_D9D4_46C4_8462_E8D3705736F5) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Explorer_Class_Deinitialize_60AC6392_FEF6_494F_BB85_0C26243626AC) },
    { be_const_key(Set_Path, -1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Path_DFED1D09_89AA_4E3C_A78C_3CB0EDC17DEE) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_File_Explorer_Class_Clear_Selection_9B2DA7B7_82E8_476F_AA5C_DE5A8E69BA51) },
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
