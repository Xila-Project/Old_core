#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_2EEDA639_B98D_493F_8EAE_7814A025D2A4) },
    { be_const_key(Open, 18), be_const_ctype_func(Berry_Drive_Class_Open_52E0E52B_7E2F_48CF_B0C4_303A1A4842F1) },
    { be_const_key(Rename, 13), be_const_ctype_func(Berry_Drive_Class_Rename_0FF7A251_03C2_4096_BC21_D0DF464D4914) },
    { be_const_key(End, 0), be_const_ctype_func(Berry_Drive_Class_End_0D86E1FB_65E8_466E_B3F2_C989207B204C) },
    { be_const_key(Drive_MMC, -1), be_const_int(1) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_86BFD65A_0BF8_45FE_87C3_1888FDB7ADD6) },
    { be_const_key(Get_Used_Size, 14), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_20A552C8_737F_4BFA_B98F_4ABF7AD4DEF5) },
    { be_const_key(Seek_Mode_Current, 10), be_const_int(1) },
    { be_const_key(Get_Type, 9), be_const_ctype_func(Berry_Drive_Class_Get_Type_1BA7EC4B_146A_4C02_A9D4_D690B0794C6D) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_BC29D93A_8725_4419_9E2A_1514A88D6B92) },
    { be_const_key(File_Type, 17), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, 15), be_const_ctype_func(Berry_Drive_Class_Exists_49E12FAA_2427_4FBB_A458_DECD62891DB0) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Seek_Mode_End, 21), be_const_int(2) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_46CF778F_9305_4463_A62E_760CE3A47A29) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_2C4E46DA_BF2F_4524_A8F8_61C46E9FD685) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Remove_File, 11), be_const_ctype_func(Berry_Drive_Class_Remove_File_1C197165_3CA9_4BF0_B8A6_320B676C8F2F) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_F9FBC0CB_922C_4742_9D7B_8FD7A8FC85D3) },
    { be_const_key(Drive_Unknow, 19), be_const_int(4) },
};

static be_define_const_map(
    m_libDrive_map,
    23
);

static be_define_const_module(
    m_libDrive,
    "Drive"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Drive);
