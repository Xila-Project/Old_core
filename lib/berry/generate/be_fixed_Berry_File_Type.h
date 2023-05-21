#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(Get_Items_Count, -1), be_const_ctype_func(Berry_File_Class_Get_Items_Count_385FC72C_609A_4E1D_AC93_6BE12E9E8576) },
    { be_const_key(readBytes, -1), be_const_ctype_func(Berry_File_Class_readBytes_9BE09C1F_D889_4CE4_88C1_3B9B3FA8928F) },
    { be_const_key(Rewind_Directory, 20), be_const_ctype_func(Berry_File_Class_Rewind_Directory_F554B7BD_5A82_4355_AB2F_46F230F07BAE) },
    { be_const_key(Close, 14), be_const_ctype_func(Berry_File_Class_Close_825CDE11_2B5C_41A2_A99F_D4B162704E4D) },
    { be_const_key(Copy, 1), be_const_ctype_func(Berry_File_Class_Copy_B9A87D01_8C02_4ED4_BCDB_855758D7808D) },
    { be_const_key(Get_Extension, 23), be_const_ctype_func(Berry_File_Class_Get_Extension_29850CF3_7C51_4362_A786_21A6C4B1C96B) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_File_Class_Peek_F9A21E3F_B733_4684_8060_CDA60E9024D5) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_E4768B22_6A49_4721_9889_D1FB5764DE0A) },
    { be_const_key(Get_Modification_Time, 25), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_4A899300_8C4C_4F79_8D51_573B74658350) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_047DD33D_F5B7_4636_89BA_D0869CF596B8) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_9B670DE5_AEED_4349_B750_C8BA716E52C6) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_79F7ABFF_BC90_4B7F_BF85_CD6F743738A7) },
    { be_const_key(Read, 13), be_const_ctype_func(Berry_File_Class_Read_F971325D_C12B_4B35_9BEC_0893882F9F35) },
    { be_const_key(read, -1), be_const_ctype_func(Berry_File_Class_read_6D86F851_931C_4682_9D64_9E460889F64D) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_File_Class_Cut_E5B1F71D_57BC_4D6C_BA04_798BD70535DE) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_FA7EA9B5_0FF2_4E7B_9BAB_83ADB5339F0E) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_5068FC8D_7D27_4BA4_B225_CFF5F4E592BB) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_E0EACD98_8940_407E_990D_1E4B476640D5) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_4901AF1C_4301_44FB_B9E8_3940CCFDB72E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_09E7ED51_4B7E_48C1_8893_71AE2ADDB9AA) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_97905F33_F6CD_459E_8A4E_AD8123E6AEAE) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_D49B4BAE_5004_434B_BE79_211EB1639D89) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_1A8778E8_2B53_46C9_B12B_0D38DE398670) },
    { be_const_key(Is_Directory, 12), be_const_ctype_func(Berry_File_Class_Is_Directory_BF8604F8_08F5_49B4_8F47_A43A58790ED6) },
    { be_const_key(available, 18), be_const_ctype_func(Berry_File_Class_available_A41FD296_F804_4ACC_B59D_7EDE3F095FBD) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_443A4FC5_47C0_4281_A248_3CFEA2E306E2) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_DDB84AC4_0D13_45A2_B0DD_57E452070D3E) },
    { be_const_key(write, 10), be_const_ctype_func(Berry_File_Class_write_EBEFDBE6_30B9_4236_A4EB_798389655D84) },
    { be_const_key(flush, 7), be_const_ctype_func(Berry_File_Class_flush_5F839DAA_9A0A_4437_AA7F_F981D46DC9A9) },
    { be_const_key(peek, 6), be_const_ctype_func(Berry_File_Class_peek_87770DF4_E1A5_453D_A190_E4A027F075ED) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_B05B5146_A335_4354_8176_004B2A89F1C6) },
};

static be_define_const_map(
    Berry_File_Type_map,
    32
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_File_Type,
    1,
    NULL,
    File_Type
);
