#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Drive_Unknow, -1), be_const_int(4) },
    { be_const_key(Get_Size, 19), be_const_ctype_func(Berry_Drive_Class_Get_Size_5368D47C_377C_4AA2_B0CF_1E54F94404F5) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Cut, 4), be_const_ctype_func(Berry_Drive_Class_Cut_F6B59E0F_11E2_4317_A183_8B91459D9525) },
    { be_const_key(Rename, 22), be_const_ctype_func(Berry_Drive_Class_Rename_43C4FEB2_DB1F_4815_B898_103F9BCC8F48) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_FB88F5A4_95D2_47BC_9C54_4F9B0DA26D68) },
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_29044A6C_58E7_4282_99F4_792BB8C9588F) },
    { be_const_key(Seek_Mode_End, -1), be_const_int(2) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Drive_Class_Get_Type_D155B101_A78E_434F_862D_0946C41A70DA) },
    { be_const_key(Open, 1), be_const_ctype_func(Berry_Drive_Class_Open_7C34E87E_BC4E_47FF_8CF2_9D531145F123) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_0A87E392_593D_4053_A0E7_CB6BC4167174) },
    { be_const_key(File_Type, -1), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, -1), be_const_ctype_func(Berry_Drive_Class_Exists_A81663D8_EEC7_4916_AAAF_2BF7F308280A) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Get_Used_Size, 17), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_18ABC530_1E5C_4374_88ED_B6D5EFAAF93A) },
    { be_const_key(Remove_File, 0), be_const_ctype_func(Berry_Drive_Class_Remove_File_B9D2FA06_9C3A_432F_9EC3_D839DF5F4A0B) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_3F468282_E8B7_4C7C_8D71_FD62F012D4CD) },
    { be_const_key(End, 2), be_const_ctype_func(Berry_Drive_Class_End_3A61E5F0_366C_4835_BFE0_87D1D0B83079) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Copy, -1), be_const_ctype_func(Berry_Drive_Class_Copy_52A3E794_4B52_4275_80E9_41A1240218C5) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_64C2837B_322F_4520_A821_10CDA098FFC7) },
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
