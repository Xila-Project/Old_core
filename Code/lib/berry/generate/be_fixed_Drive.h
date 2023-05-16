#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Drive_MMC, 1), be_const_int(1) },
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_718A4387_1F71_420A_A176_EA7B02B5CB09) },
    { be_const_key(Remove_File, -1), be_const_ctype_func(Berry_Drive_Class_Remove_File_819552F3_F068_46BF_BF6A_E17B8A1F8054) },
    { be_const_key(Get_Type, 19), be_const_ctype_func(Berry_Drive_Class_Get_Type_50871E43_AA3A_4851_921E_B32E390052F6) },
    { be_const_key(Seek_Mode_End, 0), be_const_int(2) },
    { be_const_key(File_Type, -1), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, -1), be_const_ctype_func(Berry_Drive_Class_Exists_CE6AC7EA_3116_473B_A21F_D34FAE79EC0F) },
    { be_const_key(Open, 16), be_const_ctype_func(Berry_Drive_Class_Open_DC60F01F_0E42_49CA_95D3_952D695BBC89) },
    { be_const_key(Remove_Directory, 23), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_E21DDEFD_155B_4365_83BD_1CCA112889FE) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_BE99F982_D9FD_4EAA_BA88_BACC0159DD34) },
    { be_const_key(End, 7), be_const_ctype_func(Berry_Drive_Class_End_93F6E2F7_27B5_4CB4_A9CA_7036E16B1740) },
    { be_const_key(Drive_Unknow, -1), be_const_int(4) },
    { be_const_key(Copy, 5), be_const_ctype_func(Berry_Drive_Class_Copy_2484C084_31EE_40E5_80A4_4C6CA1890CCC) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_4D1DE5C9_A9C0_4050_AA18_B52406A6C4B5) },
    { be_const_key(Get_Used_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_0EE04163_B77D_4EAB_B791_7D43EF9B1364) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_35D15F16_7284_4397_BA6E_4AB9782D38F4) },
    { be_const_key(Rename, -1), be_const_ctype_func(Berry_Drive_Class_Rename_282FF67E_0258_4A01_B0B5_7A148A03953E) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_3C2F1AE0_34C3_459C_8F7A_8DC42B1245E2) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_Drive_Class_Cut_33A2443D_FEDB_4304_A2B3_32C0F993632D) },
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
