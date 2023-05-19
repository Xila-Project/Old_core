#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_6ADEA94F_2353_4EC6_8402_29AD74836A22) },
    { be_const_key(Open, 18), be_const_ctype_func(Berry_Drive_Class_Open_3EA739C3_B124_483C_A040_7DC2F1BC4131) },
    { be_const_key(Rename, 13), be_const_ctype_func(Berry_Drive_Class_Rename_2CA3570A_48ED_470D_80B1_CA856E06D59F) },
    { be_const_key(End, 0), be_const_ctype_func(Berry_Drive_Class_End_A601CF45_B945_4063_ADE1_46E0466CE9EF) },
    { be_const_key(Drive_MMC, -1), be_const_int(1) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_C5D91E29_6AC8_4AD1_AB65_7DCCA86C4060) },
    { be_const_key(Get_Used_Size, 14), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_352449B0_F65B_408F_82F1_A23B4458D604) },
    { be_const_key(Seek_Mode_Current, 10), be_const_int(1) },
    { be_const_key(Get_Type, 9), be_const_ctype_func(Berry_Drive_Class_Get_Type_D9366C7F_B1E4_4F4F_A5BF_8F4E592F97F5) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_6E30F93B_72C2_4A98_9343_132F120C3B50) },
    { be_const_key(File_Type, 17), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, 15), be_const_ctype_func(Berry_Drive_Class_Exists_52C9B9B4_2BAC_4457_B020_8824A5942817) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Seek_Mode_End, 21), be_const_int(2) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_C1937352_7479_4E9A_9AE4_7B09250532C1) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_23BD648D_27A5_41CB_BE39_2B445AA3F32F) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Remove_File, 11), be_const_ctype_func(Berry_Drive_Class_Remove_File_8A4A7473_1F12_4232_A1AB_31E0EABE37C1) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_14C7A308_1F54_4C5E_A357_639E757AB382) },
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
