#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Drive_Unknow, -1), be_const_int(4) },
    { be_const_key(Get_Size, 19), be_const_ctype_func(Berry_Drive_Class_Get_Size_9d2ff59e_e709_4275_8eba_56d31d82c280) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Cut, 4), be_const_ctype_func(Berry_Drive_Class_Cut_e2dfb374_e8ff_42de_b3d9_f86905998ab9) },
    { be_const_key(Rename, 22), be_const_ctype_func(Berry_Drive_Class_Rename_e88ed949_991c_4310_9c94_1550ddeb1e1d) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_3d794879_f3ba_482e_bafd_94344aea7fe0) },
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_8e1d5375_c3f5_4ceb_a543_8bf22e7338b7) },
    { be_const_key(Seek_Mode_End, -1), be_const_int(2) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Drive_Class_Get_Type_4cf428df_da87_4aae_9463_224aa40e27c9) },
    { be_const_key(Open, 1), be_const_ctype_func(Berry_Drive_Class_Open_b42a8888_7fb3_4bb0_bcb0_3a7a91190a0e) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_dba28075_5838_466c_b70b_c6acdc78d3cb) },
    { be_const_key(File_Type, -1), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, -1), be_const_ctype_func(Berry_Drive_Class_Exists_3be84a62_0169_4e7d_ab7b_996258954fcc) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Get_Used_Size, 17), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_d9b93ece_09b4_4561_bcde_1b2f74c7931b) },
    { be_const_key(Remove_File, 0), be_const_ctype_func(Berry_Drive_Class_Remove_File_c996d82f_0104_4617_9259_3429565c0542) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_67c6b939_7020_4a81_9ab5_2f6b9189197b) },
    { be_const_key(End, 2), be_const_ctype_func(Berry_Drive_Class_End_db1695d8_e437_40c5_80b2_89a2aa4c6487) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Copy, -1), be_const_ctype_func(Berry_Drive_Class_Copy_43864cf7_5514_485e_ab74_447780ad1f8f) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_6b1df7a3_362c_4869_960f_99121a85eba1) },
    { be_const_key(Seek_Mode_Current, -1), be_const_int(1) },
    { be_const_key(Drive_MMC, -1), be_const_int(1) },
};

static be_define_const_map(
    m_libDrive_map,
    24
);

static be_define_const_module(
    m_libDrive,
    "Drive"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Drive);
