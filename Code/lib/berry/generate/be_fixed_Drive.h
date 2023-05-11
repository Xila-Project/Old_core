#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Drive_MMC, 1), be_const_int(1) },
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size_79B34BF7_33DD_40EA_9E28_E5149F81FC74) },
    { be_const_key(Remove_File, -1), be_const_ctype_func(Berry_Drive_Class_Remove_File_F8FC4280_554C_4477_AD8C_A191D84758F9) },
    { be_const_key(Get_Type, 19), be_const_ctype_func(Berry_Drive_Class_Get_Type_051E4888_7038_480B_BA01_F9B1C3081CAB) },
    { be_const_key(Seek_Mode_End, 0), be_const_int(2) },
    { be_const_key(File_Type, -1), be_const_class(Berry_File_Type) },
    { be_const_key(Exists, -1), be_const_ctype_func(Berry_Drive_Class_Exists_F40582FC_BAED_4E5F_A430_E2AD961903D8) },
    { be_const_key(Open, 16), be_const_ctype_func(Berry_Drive_Class_Open_53C4C32F_239C_44E7_A724_58755FA242DB) },
    { be_const_key(Remove_Directory, 23), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_4B335452_1631_414B_9D0A_AA03FDF94E38) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Drive_Class_Get_Pointer) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_495D15C8_5C17_430F_9B38_3DB8535B1962) },
    { be_const_key(End, 7), be_const_ctype_func(Berry_Drive_Class_End_5BC220DA_7A55_4398_A986_89BB0F14476D) },
    { be_const_key(Drive_Unknow, -1), be_const_int(4) },
    { be_const_key(Copy, 5), be_const_ctype_func(Berry_Drive_Class_Copy_94B08B43_0A24_4D91_BA5F_EBAAA6B26F9C) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_F10E1562_B719_4FAD_8A67_2743738A2431) },
    { be_const_key(Get_Used_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size_0E9ED503_4B8D_4FA4_B49D_96003167824C) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start_0E42FF8B_D22B_4B9B_8342_405EC9790C17) },
    { be_const_key(Rename, -1), be_const_ctype_func(Berry_Drive_Class_Rename_5C3D1830_C60B_462E_8877_AB82EC78B9A4) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size_7095B273_6F3D_4BFA_BDA1_E948D94CCE97) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_Drive_Class_Cut_70104FD9_26E3_466F_BA65_E2287FFFDD69) },
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
