#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Drive_Unknow, -1), be_const_int(4) },
    { be_const_key(Get_Size, 19), be_const_ctype_func(Berry_Drive_Class_Get_Size_570C15CC_446B_4D1E_8CD4_87EAC55AA554) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Cut, 4), be_const_ctype_func(Berry_Drive_Class_Cut_CD197EDA_8829_424F_BEE5_3FF8EDC7BEA4) },
    { be_const_key(Rename, 22), be_const_ctype_func(Berry_Drive_Class_Rename_98FA04E7_9B0D_4BE6_B117_52427EF0051E) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_682F951C_D5FB_4208_A472_89756E81000B) },
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_335ED589_88BF_41CC_82E1_BAF1EB298326) },
    { be_const_key(Seek_Mode_End, -1), be_const_int(2) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Drive_Class_Get_Type_89357959_6D63_49B1_A2AB_D0CA834559A0) },
    { be_const_key(Open, 1), be_const_ctype_func(Berry_Drive_Class_Open_5A61C7AF_5361_440A_9F67_01A96E22B28C) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_2DA78E74_96C8_4B27_B7BF_03BE0EE3DCB4) },
    { be_const_key(File_Type, -1), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, -1), be_const_ctype_func(Berry_Drive_Class_Exists_3804AF5B_66FB_4B58_97AA_8DB8A8CC57FA) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Get_Used_Size, 17), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_40422863_FF4C_4680_AC92_20684EACD2BF) },
    { be_const_key(Remove_File, 0), be_const_ctype_func(Berry_Drive_Class_Remove_File_F3AC4F06_BF57_4D3A_98B0_C9FA531D2635) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_04E283AF_F303_423B_9EA8_AC3025A2F6E2) },
    { be_const_key(End, 2), be_const_ctype_func(Berry_Drive_Class_End_2F58AF8E_11D5_4CFA_8200_51DA72617865) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Copy, -1), be_const_ctype_func(Berry_Drive_Class_Copy_97DB1454_9DED_40D9_B753_6DDD16B0ADA1) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_C1CC33AF_649B_4E03_A2FA_47E4160C7171) },
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
