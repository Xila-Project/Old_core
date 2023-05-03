#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Class_map) {
    { be_const_key(readBytes, 8), be_const_ctype_func(Berry_File_Class_readBytes_void_char_size_t) },
    { be_const_key(Is_Directory, 7), be_const_ctype_func(Berry_File_Class_Is_Directory_void) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_void_Size_Type) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_void) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_File_Class_Peek_void) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_File_Class_Read_void_uint8_t_Size_Type) },
    { be_const_key(peek, 13), be_const_ctype_func(Berry_File_Class_peek_void) },
    { be_const_key(flush, -1), be_const_ctype_func(Berry_File_Class_flush_void) },
    { be_const_key(Write, 27), be_const_ctype_func(Berry_File_Class_Write_void_uint8_t_Size_Type) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_void_char_Size_Type) },
    { be_const_key(Open_Next_File, 4), be_const_ctype_func(Berry_File_Class_Open_Next_File_void_bool_bool) },
    { be_const_key(Get_Position, 18), be_const_ctype_func(Berry_File_Class_Get_Position_void) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_void) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Rewind_Directory, -1), be_const_ctype_func(Berry_File_Class_Rewind_Directory_void) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_void) },
    { be_const_key(Get_Modification_Time, 22), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_void) },
    { be_const_key(read, 1), be_const_ctype_func(Berry_File_Class_read_void) },
    { be_const_key(Count_Items, -1), be_const_ctype_func(Berry_File_Class_Count_Items_void) },
    { be_const_key(Close, 23), be_const_ctype_func(Berry_File_Class_Close_void) },
    { be_const_key(available, -1), be_const_ctype_func(Berry_File_Class_available_void) },
    { be_const_key(Get_Size, 26), be_const_ctype_func(Berry_File_Class_Get_Size_void) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_void) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_Drive_TypesFile_Class) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_void) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_void) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_void_uint32_t) },
    { be_const_key(write, -1), be_const_ctype_func(Berry_File_Class_write_void_uint8_t_size_t) },
};

static be_define_const_map(
    Berry_File_Class_map,
    28
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_File_Class,
    1,
    NULL,
    File_Type
);
