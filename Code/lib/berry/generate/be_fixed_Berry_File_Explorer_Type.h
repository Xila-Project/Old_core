#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Explorer_Type_map) {
    { be_const_key(init, 5), be_const_ctype_func(Berry_File_Explorer_Class_Initialize_B20C6477_9B15_4616_B917_129F594E8668) },
    { be_const_key(Get_Path, 14), be_const_ctype_func(Berry_File_Explorer_Class_Get_Path_7EAF2446_0465_48D6_A1FF_81028263FC6E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Go_Parent_Folder, -1), be_const_ctype_func(Berry_File_Explorer_Class_Go_Parent_Folder_FC0DBFE8_047A_4336_8A29_027315D0B323) },
    { be_const_key(Get_Selected_Count, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Count_21195C74_FF77_48D7_93A4_C58CE25ECF52) },
    { be_const_key(Get_Selection_State, -1), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selection_State_7CBCA577_368B_4DA8_AC2C_209BB2EB8C02) },
    { be_const_key(Refresh, 13), be_const_ctype_func(Berry_File_Explorer_Class_Refresh_CE5A6E9B_A8AB_4678_8B8E_2FEB7075DA80) },
    { be_const_key(Get_Selected_Name, 11), be_const_ctype_func(Berry_File_Explorer_Class_Get_Selected_Name_EB774160_9B2F_4564_93C4_76A9E12B9A45) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_File_Explorer_Class_Delete_EBB78438_E710_453A_82F9_8A3D9F24B521) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_File_Explorer_Class_Create_20825D5C_2691_4108_829E_591D035AA026) },
    { be_const_key(Set_Selection_State, 1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Selection_State_3EBC8418_49B6_4A52_B60D_81A7DD186CEE) },
    { be_const_key(Get_Focused_Name, 12), be_const_ctype_func(Berry_File_Explorer_Class_Get_Focused_Name_F8E461BF_B685_437A_B5FD_D2739EC24B8F) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Explorer_Class_Deinitialize_4C6904DA_2C5B_4A29_AADA_B18FC6AF6C84) },
    { be_const_key(Set_Path, -1), be_const_ctype_func(Berry_File_Explorer_Class_Set_Path_5285D32A_964B_493A_BC10_406D529C34D5) },
    { be_const_key(Clear_Selection, -1), be_const_ctype_func(Berry_File_Explorer_Class_Clear_Selection_C3E2DC71_82DA_4F27_9F98_547BEBF71EA4) },
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
