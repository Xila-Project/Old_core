#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(Read_String, 23), be_const_ctype_func(Berry_File_Class_Read_String_ED727671_FDA8_41EE_BEB3_2F6574734A6D) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_File_Class_Close_FC832A99_660F_4541_8DC3_DAF8867D3FDF) },
    { be_const_key(peek, 11), be_const_ctype_func(Berry_File_Class_peek_212548E4_E8A3_4B01_8E58_F90B3C9BBF9D) },
    { be_const_key(Read, 10), be_const_ctype_func(Berry_File_Class_Read_F24818F9_5DDA_49D7_B924_3E54599DC557) },
    { be_const_key(Peek, 16), be_const_ctype_func(Berry_File_Class_Peek_593C8219_E6E5_47F3_8A5A_063CB717F478) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_4E673E3C_F42C_476C_A5A9_8414EE698889) },
    { be_const_key(Get_Modification_Time, -1), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_2873E69F_C938_42C3_A78C_49A03AB1DD61) },
    { be_const_key(flush, -1), be_const_ctype_func(Berry_File_Class_flush_ED9F8B86_7E70_4E1B_9BF0_30939A8AE518) },
    { be_const_key(Flush, 21), be_const_ctype_func(Berry_File_Class_Flush_C5012D07_7780_4D89_8751_D1A7FE6AF0E9) },
    { be_const_key(read, -1), be_const_ctype_func(Berry_File_Class_read_E0A5C8C2_2DF5_46D8_A5D4_D8E2AA533317) },
    { be_const_key(Get_Extension, -1), be_const_ctype_func(Berry_File_Class_Get_Extension_00F267E0_1DE4_43DE_8FB1_F49D9FD12C75) },
    { be_const_key(_p, 13), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_B82CB63A_2E81_4D34_A59A_28662FD18A61) },
    { be_const_key(Available, 26), be_const_ctype_func(Berry_File_Class_Available_4CC95E24_67E3_4E3A_8173_196126736A29) },
    { be_const_key(readBytes, 4), be_const_ctype_func(Berry_File_Class_readBytes_BFD6FEAD_935B_440F_B31F_275174D2882A) },
    { be_const_key(Get_Size, 0), be_const_ctype_func(Berry_File_Class_Get_Size_39069979_FD9E_4E89_95D3_A60684E8129C) },
    { be_const_key(available, 28), be_const_ctype_func(Berry_File_Class_available_5A970DE8_ABDD_49B0_9CE8_EA1F0324E8FF) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_52A31E54_90EF_4B0B_ACB2_4D8A2C1567B7) },
    { be_const_key(Open_Next_File, 27), be_const_ctype_func(Berry_File_Class_Open_Next_File_B23E7CBC_0CF1_419E_BFEB_1EA87C74DC76) },
    { be_const_key(Is_Directory, 20), be_const_ctype_func(Berry_File_Class_Is_Directory_A91967EE_D90F_4E7B_9679_7AC0B6EFC8CF) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_C4EE774D_624F_43D3_BC7B_9FEE917835FB) },
    { be_const_key(Count_Items, -1), be_const_ctype_func(Berry_File_Class_Count_Items_189AB1BA_C781_4CF2_972A_1AE4CBE265D5) },
    { be_const_key(Rewind_Directory, 18), be_const_ctype_func(Berry_File_Class_Rewind_Directory_752E25E3_F13F_4D5B_8315_5EAE75F09404) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_C354CC68_A443_48C3_9E8C_512B2C506C63) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_A1F2B11A_C058_48BB_B22C_9474D641DB7A) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_EE4ECF2F_7C16_4121_B589_F3E68C07D773) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_F02B92F8_0B73_461D_A6C6_224D26F868BB) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_9D196A98_9633_440E_B153_BCC13429E945) },
    { be_const_key(write, -1), be_const_ctype_func(Berry_File_Class_write_3A2E0226_898D_4199_9ECC_5D35AB2D1F4C) },
    { be_const_key(Get_Position, 8), be_const_ctype_func(Berry_File_Class_Get_Position_DA5601F4_C7BB_4293_AAC9_8DFBC085DF02) },
};

static be_define_const_map(
    Berry_File_Type_map,
    30
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_File_Type,
    1,
    NULL,
    File_Type
);
