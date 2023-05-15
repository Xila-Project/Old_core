#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(Read_String, 23), be_const_ctype_func(Berry_File_Class_Read_String_7AA57AE8_0B8B_4156_80F3_19CD37ACD441) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_File_Class_Close_F439CBD3_BE48_4E1A_A6D1_6A91AABC48CC) },
    { be_const_key(peek, 11), be_const_ctype_func(Berry_File_Class_peek_96919CA2_BC4D_4840_9E7E_38535C337090) },
    { be_const_key(Read, 10), be_const_ctype_func(Berry_File_Class_Read_0BEB6FDC_CCE0_4A28_A4B4_A8EB518E074A) },
    { be_const_key(Peek, 16), be_const_ctype_func(Berry_File_Class_Peek_0CD8F7B9_31EA_40FC_8F33_C7C0EF6E283C) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_D29FC392_F513_49D5_A10D_CA97CAA9672C) },
    { be_const_key(Get_Modification_Time, -1), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_A30D06EB_2AD1_4B47_928A_B124D280C669) },
    { be_const_key(flush, -1), be_const_ctype_func(Berry_File_Class_flush_46F397E2_3AA4_4733_AE79_1946B52C7786) },
    { be_const_key(Flush, 21), be_const_ctype_func(Berry_File_Class_Flush_2080A064_60E6_430D_9207_4DB6F38FC63B) },
    { be_const_key(read, -1), be_const_ctype_func(Berry_File_Class_read_5646BE5B_88EC_429C_8456_F63F4ECC3230) },
    { be_const_key(Get_Extension, -1), be_const_ctype_func(Berry_File_Class_Get_Extension_306536AA_EC54_49CD_A2D6_E6E7F2108C6B) },
    { be_const_key(_p, 13), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_FF7C7C28_6A4D_4F6E_8307_558E6247D689) },
    { be_const_key(Available, 26), be_const_ctype_func(Berry_File_Class_Available_9A43351C_D6E6_44F9_BDB2_4A5641E2E590) },
    { be_const_key(readBytes, 4), be_const_ctype_func(Berry_File_Class_readBytes_6FA33390_C00E_4335_9958_003EE804A782) },
    { be_const_key(Get_Size, 0), be_const_ctype_func(Berry_File_Class_Get_Size_6AB39B03_1F80_4147_8D02_B4D6ABE2034A) },
    { be_const_key(available, 28), be_const_ctype_func(Berry_File_Class_available_DF922D69_128E_4DBC_8B4F_5F329886541D) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_8E4E68C8_B6E0_46EB_8CC2_C78DDE96F1B4) },
    { be_const_key(Open_Next_File, 27), be_const_ctype_func(Berry_File_Class_Open_Next_File_18830E9E_DE12_4447_93BB_33CE066B894C) },
    { be_const_key(Is_Directory, 20), be_const_ctype_func(Berry_File_Class_Is_Directory_86E8E729_F932_468C_AA18_505C5DA89A52) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_EAF71068_6739_4C6B_A6F0_2ABDD6F808BD) },
    { be_const_key(Count_Items, -1), be_const_ctype_func(Berry_File_Class_Count_Items_0E30FCEA_A733_45B6_96D9_B03AF5311BD4) },
    { be_const_key(Rewind_Directory, 18), be_const_ctype_func(Berry_File_Class_Rewind_Directory_DC717E07_7942_4657_9341_9D3B9091B480) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_4C6E38B7_E661_4C87_B4E3_9D793A5052AE) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_B4CEA938_35A4_42CD_A0C8_CFB972F755A2) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_5F5F6822_7BF2_420D_B00E_329FB59414FD) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_8941A715_72B6_4D10_A8D7_674DE4570228) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_9CA9C8D4_590E_4C13_99A8_583039034EA4) },
    { be_const_key(write, -1), be_const_ctype_func(Berry_File_Class_write_3282230E_2EC5_452C_8D17_EBB1FD5E8CCC) },
    { be_const_key(Get_Position, 8), be_const_ctype_func(Berry_File_Class_Get_Position_BCBDF05B_DBA1_49D2_9C47_AE0FE7F204B8) },
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
