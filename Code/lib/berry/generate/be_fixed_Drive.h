#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Drive_MMC, 1), be_const_int(1) },
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_57DAC25D_6E9F_434C_B25F_D1FD42BB3566) },
    { be_const_key(Remove_File, -1), be_const_ctype_func(Berry_Drive_Class_Remove_File_AB2A9548_5E6C_4648_B5CE_859F088D5527) },
    { be_const_key(Get_Type, 19), be_const_ctype_func(Berry_Drive_Class_Get_Type_F7A2E693_3889_433D_ACF6_E9392A024EC0) },
    { be_const_key(Seek_Mode_End, 0), be_const_int(2) },
    { be_const_key(File_Type, -1), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, -1), be_const_ctype_func(Berry_Drive_Class_Exists_E0A5217D_E14E_4112_8E01_D3C14D6BA6D2) },
    { be_const_key(Open, 16), be_const_ctype_func(Berry_Drive_Class_Open_A1E11E01_1C62_4390_AA59_A0305E25B134) },
    { be_const_key(Remove_Directory, 23), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_DF9E624B_E71F_4D28_91A7_6900BAAD0E10) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_CA0C4564_4D4F_4376_A9CD_7E2688328CED) },
    { be_const_key(End, 7), be_const_ctype_func(Berry_Drive_Class_End_55022169_2D5E_48BC_A0AD_84BF9A117226) },
    { be_const_key(Drive_Unknow, -1), be_const_int(4) },
    { be_const_key(Copy, 5), be_const_ctype_func(Berry_Drive_Class_Copy_CD239965_6D35_4151_957A_882A5FD6D0FF) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_EF6000CA_7488_473A_BAA0_9F27C9C3DC87) },
    { be_const_key(Get_Used_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_D773F68A_9B68_4B49_8AB1_31122593D2CE) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_DE8F3868_2BEA_477F_A601_BCE3F2046AA2) },
    { be_const_key(Rename, -1), be_const_ctype_func(Berry_Drive_Class_Rename_D3E17F64_4E8F_4E39_8E19_9BE3DA481226) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_58641EA9_EC62_446A_A2C1_18D4434A414D) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_Drive_Class_Cut_33225915_765C_4F22_9382_795B3B27B492) },
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
