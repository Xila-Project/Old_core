#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(read, 21), be_const_ctype_func(Berry_File_Class_read_272647DD_31CA_48D4_B882_EE6E6938408B) },
    { be_const_key(Read_Bytes, 15), be_const_ctype_func(Berry_File_Class_Read_Bytes_2F538C2E_E1DE_4133_B1EC_E26BD5F16867) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_F00979AA_6B58_49E4_8FAC_0D14D58D3908) },
    { be_const_key(Peek, 27), be_const_ctype_func(Berry_File_Class_Peek_7E10E103_6CAC_4751_8371_7AF2A6A407D6) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_D925123F_F9A3_461A_866C_4C2EDDDE03C7) },
    { be_const_key(Is_Directory, 12), be_const_ctype_func(Berry_File_Class_Is_Directory_7BF7071C_CDAD_464F_BB72_934D77EEE250) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_71405CDC_C3B9_4567_8476_DF0C76D2861F) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_A2BE2F61_88F0_477B_B875_F17348706E7D) },
    { be_const_key(Rewind_Directory, -1), be_const_ctype_func(Berry_File_Class_Rewind_Directory_7F4DF965_1970_4A46_82EF_5D217C75FFB3) },
    { be_const_key(readBytes, 1), be_const_ctype_func(Berry_File_Class_readBytes_36F32719_B49A_44E1_B3C6_FB626B528484) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_433E7398_906C_4390_8305_4978BE944283) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_6643C48D_17AD_4952_8786_C8A801352F42) },
    { be_const_key(Count_Items, 11), be_const_ctype_func(Berry_File_Class_Count_Items_4FB1ACC4_7BB3_4263_ACBA_D5DE8AD4D4D2) },
    { be_const_key(Seek, 8), be_const_ctype_func(Berry_File_Class_Seek_45EC2DFA_5CB0_4165_BC2A_DE51A27AF225) },
    { be_const_key(init, 20), be_const_ctype_func(Berry_File_Class_Initialize_DAAF2316_FE74_4BFF_8AB4_1C9E39B52B36) },
    { be_const_key(write, -1), be_const_ctype_func(Berry_File_Class_write_1C0A5FDA_2131_4D9E_96FD_98B8CA6D3AB1) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_633926BB_93DE_4C01_82B1_F753461C4C2B) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_A4CB12C0_23D4_462C_8A7B_A7437DA9EEDB) },
    { be_const_key(Read, 23), be_const_ctype_func(Berry_File_Class_Read_7524BDC5_7739_4331_9773_EC620E472DDB) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_EEA9092C_00B3_4BBE_8C5F_DA9701334D80) },
    { be_const_key(Get_Path, 26), be_const_ctype_func(Berry_File_Class_Get_Path_22CE9FEB_6B00_49D4_93D3_20686E66A168) },
    { be_const_key(Get_Modification_Time, 3), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_385306A8_1BF5_42AC_9682_9429D61EFBA7) },
    { be_const_key(peek, -1), be_const_ctype_func(Berry_File_Class_peek_FDFF4D4B_13AF_4BE4_BADD_FF80796FC37F) },
    { be_const_key(available, -1), be_const_ctype_func(Berry_File_Class_available_5E731108_3AA3_4ED8_998E_ABA364BBE5A5) },
    { be_const_key(flush, 4), be_const_ctype_func(Berry_File_Class_flush_680162F5_E86E_4BDF_A67C_EE72C77BADE2) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_ABEA58A6_7DD6_489B_A5B5_F91B1F957CC8) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_F34E02FF_ED13_49F1_8C7F_D27A4F3C94F9) },
    { be_const_key(Close, 24), be_const_ctype_func(Berry_File_Class_Close_A0992C63_8E10_4B90_A036_EFF121A247FA) },
};

static be_define_const_map(
    Berry_File_Type_map,
    29
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_File_Type,
    1,
    NULL,
    File_Type
);
