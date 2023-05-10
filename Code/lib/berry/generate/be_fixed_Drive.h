#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Drive_MMC, 1), be_const_int(1) },
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_2868489F_8502_4EFA_A259_D25857998FE5) },
    { be_const_key(Remove_File, -1), be_const_ctype_func(Berry_Drive_Class_Remove_File_D0BA00E4_17FC_4422_9DA6_52B504B4C8FA) },
    { be_const_key(Get_Type, 19), be_const_ctype_func(Berry_Drive_Class_Get_Type_EC63AD18_24E5_43B6_B1F8_DF46DB300ACC) },
    { be_const_key(Seek_Mode_End, 0), be_const_int(2) },
    { be_const_key(File_Type, -1), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, -1), be_const_ctype_func(Berry_Drive_Class_Exists_B0AC9BCB_00AF_4E51_AC1E_38EC72D01268) },
    { be_const_key(Open, 16), be_const_ctype_func(Berry_Drive_Class_Open_9A29E680_337E_43A6_8308_388F0B143515) },
    { be_const_key(Remove_Directory, 23), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_7F4F03B0_C6DB_4CB2_AA6B_2EAEC0BFE601) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_3225E8AB_7AB4_439B_B669_F8CEC7C597A7) },
    { be_const_key(End, 7), be_const_ctype_func(Berry_Drive_Class_End_D665B7E7_D642_4ADC_844A_00B0EBD17406) },
    { be_const_key(Drive_Unknow, -1), be_const_int(4) },
    { be_const_key(Copy, 5), be_const_ctype_func(Berry_Drive_Class_Copy_2B3B2FAA_B40B_45F2_92A8_0C2A73D222B6) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_92876CFE_55FE_4C85_892C_CD1DFC9D1037) },
    { be_const_key(Get_Used_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_200909D6_DF3D_46F9_A101_3CC0B1DF5A61) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_FC9ECF63_383F_4039_AA50_D2DACF26A571) },
    { be_const_key(Rename, -1), be_const_ctype_func(Berry_Drive_Class_Rename_299EF03E_FA70_4868_8E07_51EFE6BA9492) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_DFF63707_65B4_4774_8A8C_CBF550C949C9) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_Drive_Class_Cut_3A85A46C_1E97_4101_9C60_A70B619ADD29) },
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
