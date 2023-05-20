#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_F9E4FC16_9ED0_43E1_88BA_CB4162C8B03E) },
    { be_const_key(Open, 18), be_const_ctype_func(Berry_Drive_Class_Open_324F4382_FB6E_4101_BDBA_DF2C35717409) },
    { be_const_key(Rename, 13), be_const_ctype_func(Berry_Drive_Class_Rename_9972C156_EB7D_4828_91CD_2D5D283A63E5) },
    { be_const_key(End, 0), be_const_ctype_func(Berry_Drive_Class_End_FE42B1B8_96BF_44B2_BCD1_41A5F2DBC1C0) },
    { be_const_key(Drive_MMC, -1), be_const_int(1) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_57D4ADBE_0405_454B_A9F4_C1ADB97C1EAC) },
    { be_const_key(Get_Used_Size, 14), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_07365CEC_7FB3_44D6_BA3A_37A42BFF6439) },
    { be_const_key(Seek_Mode_Current, 10), be_const_int(1) },
    { be_const_key(Get_Type, 9), be_const_ctype_func(Berry_Drive_Class_Get_Type_70330BE1_2179_462A_B414_F6048E8D267E) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_6AE4A940_1984_4A61_BC67_F4D38FB15810) },
    { be_const_key(File_Type, 17), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, 15), be_const_ctype_func(Berry_Drive_Class_Exists_3F194997_C7AF_40DB_A236_63E86913C908) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Seek_Mode_End, 21), be_const_int(2) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_A3C5C159_4773_4F05_9A8E_9D2B8A84FBDC) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_489A69E5_8D12_4A98_BBC2_71FE3E126DD2) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Remove_File, 11), be_const_ctype_func(Berry_Drive_Class_Remove_File_6BEEE90C_FB02_4549_A4F2_7C90F47F4256) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_20C56C9F_EE34_44A8_A645_9A5011DD65A8) },
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
