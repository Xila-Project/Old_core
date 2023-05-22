#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Explorer_Type_map) {
    { be_const_key(init, 5), be_const_ctype_func(Berry_File_Explorer_Class_Initialize_5A112D8B_32D8_4A75_B820_B5AAF6AC39EC) },
    { be_const_key(Get_Path, 14), be_const_ctype_func(Berry_File_Explorer_Class_Get_Path_06A9D5D9_DC4A_4882_86CE_18E8047084B1) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Go_Parent_Folder, -1), be_const_ctype_func(Berry_File_Explorer_Class_Go_Parent_Folder_33EEC698_83B2_44DA_8F49_358052D703B2) },
    { be_const_key(Get_Selected_Count, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Count_5AAC43DB_D24B_4A84_A4E6_D1FAE6CE1838) },
    { be_const_key(Get_Selection_State, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selection_State_2CDA33A8_08DC_493D_8CFA_F706503EC972) },
    { be_const_key(Refresh, 13), be_const_ctype_func(Berry_File_Explorer_Class_Refresh_97B6E26C_BD6B_4F69_87D0_F3B7A690AD99) },
    { be_const_key(Get_Selected_Name, 11), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Name_3E3EF0CF_457C_403B_9B80_8B114C631EDE) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_File_Explorer_Class_Delete_59DAA5D0_9C96_4DBB_B725_2B05D24E72F5) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_File_Explorer_Class_Create_EB1F052A_1FFD_498D_9EC9_43BF88CC3ABE) },
    { be_const_key(Set_Selection_State, 1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Selection_State_6E21FDA1_477B_4BDB_A27B_4B531DA88839) },
    { be_const_key(Get_Focused_Name, 12), be_const_ctype_func(Berry_File_Explorer_Class_Get_Focused_Name_3987FADE_2C62_448F_87B2_18730169D1F7) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Explorer_Class_Deinitialize_E433D6B8_D141_458D_9ACE_99DF5F2FC12B) },
    { be_const_key(Set_Path, -1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Path_B9AAF209_D12D_46B7_B1ED_CE8779859E8B) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_File_Explorer_Class_Clear_Selection_F5542D52_04D8_45FC_A6D2_ADC1E4739859) },
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
