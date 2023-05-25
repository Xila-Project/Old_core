#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(Get_Items_Count, -1), be_const_ctype_func(Berry_File_Class_Get_Items_Count_E149470F_635F_48CF_85AB_93CC7CEF303F) },
    { be_const_key(readBytes, -1), be_const_ctype_func(Berry_File_Class_readBytes_44D60FC0_E60D_445F_A46E_B973C6FE122B) },
    { be_const_key(Rewind_Directory, 20), be_const_ctype_func(Berry_File_Class_Rewind_Directory_7F59460C_25E3_4178_9F4A_25F1E6F7FAFE) },
    { be_const_key(Close, 14), be_const_ctype_func(Berry_File_Class_Close_09712691_4744_4241_829E_191BC6B936E7) },
    { be_const_key(Copy, 1), be_const_ctype_func(Berry_File_Class_Copy_A7A28C8D_E712_4CC8_8DD2_F987FDA97280) },
    { be_const_key(Get_Extension, 23), be_const_ctype_func(Berry_File_Class_Get_Extension_EAD36356_5A87_4217_85F2_9F9265D8418A) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_File_Class_Peek_64A2C158_9439_4D7B_A788_169995CD8D05) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_08A7CC18_754F_4BF3_9BB2_CAF8E5C8282C) },
    { be_const_key(Get_Modification_Time, 25), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_6835B280_E530_4CAA_8697_8C0D62A0043B) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_FF00BEDD_A845_4AD7_9FA5_13D1A5D67B90) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_58C19D65_56AA_4C62_AF3B_D9C45C0BC090) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_CACB4324_9AA7_4860_82DB_5ED7D59524DE) },
    { be_const_key(Read, 13), be_const_ctype_func(Berry_File_Class_Read_BE235A77_289A_4520_B3BF_8D601F627B00) },
    { be_const_key(read, -1), be_const_ctype_func(Berry_File_Class_read_D5BC39E1_60AC_4094_8CBC_314D3DA085C0) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_File_Class_Cut_E5817001_7DD8_42B8_9D57_B5DA5D35AC09) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_2BF9272C_3521_4809_9B22_31D5F0C240B5) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_91C81154_2AA0_4385_A984_CF9C6EE81237) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_99A046FC_A243_4BF1_B4BA_B7D7E1F6BC4A) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_11801225_7FE0_4F79_8B73_5A783D9E000C) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_0E35AC9A_4B47_4202_AA7A_94E2B9B07773) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_EFEBFFB5_BA8F_455A_9B03_46A10617A689) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_E1732553_965E_4663_B0EC_00E781D401EA) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_21AEDB2A_4C44_4E6D_83E9_DB713D39C78A) },
    { be_const_key(Is_Directory, 12), be_const_ctype_func(Berry_File_Class_Is_Directory_45C7F458_7A43_431B_8CC1_8D6F417AA867) },
    { be_const_key(available, 18), be_const_ctype_func(Berry_File_Class_available_81D1586C_2DD5_4609_BA5E_C837C5B2A24D) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_F0CF0F52_C59D_4D10_AE52_2DBF49521775) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_A6AAE016_4038_4E97_9970_A363CDBD788E) },
    { be_const_key(write, 10), be_const_ctype_func(Berry_File_Class_write_37C65721_02B4_4FC4_ACB9_D851AFD07CDA) },
    { be_const_key(flush, 7), be_const_ctype_func(Berry_File_Class_flush_28FC9B8A_906A_44CD_98BA_2A84BD14EE8C) },
    { be_const_key(peek, 6), be_const_ctype_func(Berry_File_Class_peek_1467D7AE_DAEB_4289_8BB6_684E40CE69E9) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_1DA93BCC_4F2F_4D47_8E4D_20F418D6BE90) },
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
