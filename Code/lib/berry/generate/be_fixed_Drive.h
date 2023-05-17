#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_77CF90D6_55EB_49CB_B0D7_CC5A2326FB9E) },
    { be_const_key(Open, 18), be_const_ctype_func(Berry_Drive_Class_Open_533D1E89_5F5A_49D2_B0DD_8EAAEC009570) },
    { be_const_key(Rename, 13), be_const_ctype_func(Berry_Drive_Class_Rename_B2D0CFEC_89B3_420D_9968_238E8E3C41E3) },
    { be_const_key(End, 0), be_const_ctype_func(Berry_Drive_Class_End_6EEB844D_E55F_4CE1_BF3E_ADFE2F34409F) },
    { be_const_key(Drive_MMC, -1), be_const_int(1) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_7E0AD725_1EB4_4B29_82E7_A29A533BB1E8) },
    { be_const_key(Get_Used_Size, 14), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_4F1ECF26_85F5_4DBF_8E96_2B1BA1F72878) },
    { be_const_key(Seek_Mode_Current, 10), be_const_int(1) },
    { be_const_key(Get_Type, 9), be_const_ctype_func(Berry_Drive_Class_Get_Type_151A0998_9DC2_4F76_9276_8A7DB9AE1B64) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_CBA2EA4F_F068_4468_9CBC_2B3935621DC0) },
    { be_const_key(File_Type, 17), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, 15), be_const_ctype_func(Berry_Drive_Class_Exists_BDF596F0_2DDD_432F_BFD3_AD240E68634A) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Seek_Mode_End, 21), be_const_int(2) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_D631E044_70B4_4C9A_B98F_E717671B26C0) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_6B95A86D_2FA5_4D30_A75D_802FF75152E3) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Remove_File, 11), be_const_ctype_func(Berry_Drive_Class_Remove_File_8F4EC414_A789_42C9_8272_772A133F738A) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_3A329800_B5B7_49FB_BD54_E23686573F67) },
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
