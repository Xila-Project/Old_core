#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size) },
    { be_const_key(Open, 17), be_const_ctype_func(Berry_Drive_Class_Open_char_bool_bool) },
    { be_const_key(Rename, -1), be_const_ctype_func(Berry_Drive_Class_Rename_char_char) },
    { be_const_key(End, 0), be_const_ctype_func(Berry_Drive_Class_End) },
    { be_const_key(Drive_MMC, -1), be_const_int(1) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start) },
    { be_const_key(Get_Used_Size, 14), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size) },
    { be_const_key(Seek_Mode_Current, 11), be_const_int(1) },
    { be_const_key(Get_Type, 9), be_const_ctype_func(Berry_Drive_Class_Get_Type) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_char) },
    { be_const_key(Exists, 15), be_const_ctype_func(Berry_Drive_Class_Exists_char) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_char) },
    { be_const_key(Cut, 13), be_const_ctype_func(Berry_Drive_Class_Cut_char_char) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Seek_Mode_End, 19), be_const_int(2) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Size) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_char_bool) },
    { be_const_key(Remove_File, 10), be_const_ctype_func(Berry_Drive_Class_Remove_File_char) },
    { be_const_key(Copy, -1), be_const_ctype_func(Berry_Drive_Class_Copy_char_char) },
    { be_const_key(Drive_Unknow, 18), be_const_int(4) },
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
