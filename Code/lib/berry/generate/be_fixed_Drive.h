#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Drive_MMC, 1), be_const_int(1) },
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_DCEAB5F6_7E5D_4114_9C52_D23870557AAD) },
    { be_const_key(Remove_File, -1), be_const_ctype_func(Berry_Drive_Class_Remove_File_4EA2594D_365F_462D_ACD9_E4DDF2AEB8CB) },
    { be_const_key(Get_Type, 19), be_const_ctype_func(Berry_Drive_Class_Get_Type_B6CCC1FE_927E_44F7_9A31_D0D9EEABFA0F) },
    { be_const_key(Seek_Mode_End, 0), be_const_int(2) },
    { be_const_key(File_Type, -1), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, -1), be_const_ctype_func(Berry_Drive_Class_Exists_63B3A557_FECB_4A4C_81FA_AA70400662A6) },
    { be_const_key(Open, 16), be_const_ctype_func(Berry_Drive_Class_Open_3F0AA84E_3997_468F_AD48_4271826441A0) },
    { be_const_key(Remove_Directory, 23), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_D5572DCE_93EB_43F1_B135_11AE5A4FA83F) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_BDDA9818_2D05_4756_B89D_9FA1BEAA87CA) },
    { be_const_key(End, 7), be_const_ctype_func(Berry_Drive_Class_End_56557808_93DA_4648_BF15_9128B0C231C9) },
    { be_const_key(Drive_Unknow, -1), be_const_int(4) },
    { be_const_key(Copy, 5), be_const_ctype_func(Berry_Drive_Class_Copy_6C9E38CD_E4D9_44A2_AEC5_BAA86C380C06) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_D7A08B72_8354_4B1E_A888_E8F703D00D08) },
    { be_const_key(Get_Used_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_E54306ED_933E_4886_A2B4_C0841B038106) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_0C095F69_2D41_4A51_BAA9_A54AAB315385) },
    { be_const_key(Rename, -1), be_const_ctype_func(Berry_Drive_Class_Rename_ACD8389F_E619_409A_B731_3E08FA731A4B) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_C6DEDB60_6AF0_449B_87A0_F1FC00FBA715) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_Drive_Class_Cut_F71A58EC_C349_4154_B3BA_13E169FD4B6C) },
    { be_const_key(Seek_Mode_Current, 9), be_const_int(1) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
};

static be_define_const_map(
    m_libDrive_map,
    25
);

static be_define_const_module(
    m_libDrive,
    "Drive"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Drive);
