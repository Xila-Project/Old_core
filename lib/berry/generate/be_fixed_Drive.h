#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_63F5D4DD_8F3C_4A35_B6A7_7DD5DDAD61BF) },
    { be_const_key(Open, 18), be_const_ctype_func(Berry_Drive_Class_Open_A671EC0B_CDDB_4604_BBF3_2E0E98E12F5D) },
    { be_const_key(Rename, 13), be_const_ctype_func(Berry_Drive_Class_Rename_5F494E4C_6C6E_40D9_994F_305D95DBE682) },
    { be_const_key(End, 0), be_const_ctype_func(Berry_Drive_Class_End_1E38B018_57C3_45A9_AC34_C7EB2529BD59) },
    { be_const_key(Drive_MMC, -1), be_const_int(1) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_62DD9671_B881_477D_B2F7_6B010A63963F) },
    { be_const_key(Get_Used_Size, 14), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_CBF4AA68_D919_4A97_9BAD_5C181EA519CD) },
    { be_const_key(Seek_Mode_Current, 10), be_const_int(1) },
    { be_const_key(Get_Type, 9), be_const_ctype_func(Berry_Drive_Class_Get_Type_BB7EFCE9_9673_4B18_8AFC_D17A610B7EBA) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_125A36EB_ECE9_43A0_B966_D0315A089E2E) },
    { be_const_key(File_Type, 17), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, 15), be_const_ctype_func(Berry_Drive_Class_Exists_EC4147C1_F17F_4ECB_9E71_09A55815137D) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Seek_Mode_End, 21), be_const_int(2) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_2FB9397F_7069_4650_961E_D8156E27C948) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_9DA5FD4F_B37C_4F89_9ACB_381FEEC5388F) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Remove_File, 11), be_const_ctype_func(Berry_Drive_Class_Remove_File_67CCA658_7B68_4E4D_A47F_620FB13CFE7F) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_5EE48F34_32AA_4058_AC68_8468AE2CCEB1) },
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
