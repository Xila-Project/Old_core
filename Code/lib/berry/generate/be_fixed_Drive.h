#include "be_constobj.h"

static be_define_const_map_slots(m_libDrive_map) {
    { be_const_key(Drive_Unknow, -1), be_const_int(4) },
    { be_const_key(Get_Size, 19), be_const_ctype_func(Berry_Drive_Class_Get_Size) },
    { be_const_key(Seek_Mode_Set, -1), be_const_int(0) },
    { be_const_key(Cut, 4), be_const_ctype_func(Berry_Drive_Class_Cut_char_char) },
    { be_const_key(Rename, 22), be_const_ctype_func(Berry_Drive_Class_Rename_char_char) },
    { be_const_key(Remove, -1), be_const_ctype_func(Berry_Drive_Class_Remove_char) },
    { be_const_key(Get_Total_Size, -1), be_const_ctype_func(Berry_Drive_Class_Get_Total_Size) },
    { be_const_key(Seek_Mode_End, -1), be_const_int(2) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Drive_Class_Get_Type) },
    { be_const_key(Open, 1), be_const_ctype_func(Berry_Drive_Class_Open_char_bool_bool) },
    { be_const_key(Drive_None, -1), be_const_int(0) },
    { be_const_key(Make_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Make_Directory_char) },
    { be_const_key(File_Type, -1), be_const_class(Berry_File_Class) },
    { be_const_key(Exists, -1), be_const_ctype_func(Berry_Drive_Class_Exists_char) },
    { be_const_key(Drive_SD_SC, -1), be_const_int(2) },
    { be_const_key(Get_Used_Size, 17), be_const_ctype_func(Berry_Drive_Class_Get_Used_Size) },
    { be_const_key(Remove_File, 0), be_const_ctype_func(Berry_Drive_Class_Remove_File_char) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Drive_Class_Start) },
    { be_const_key(End, 2), be_const_ctype_func(Berry_Drive_Class_End) },
    { be_const_key(Drive_SD_HC, -1), be_const_int(3) },
    { be_const_key(Copy, -1), be_const_ctype_func(Berry_Drive_Class_Copy_char_char) },
    { be_const_key(Remove_Directory, -1), be_const_ctype_func(Berry_Drive_Class_Remove_Directory_char_bool) },
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
