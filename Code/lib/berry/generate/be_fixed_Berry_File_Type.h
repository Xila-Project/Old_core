#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(Read_String, 23), be_const_ctype_func(Berry_File_Class_Read_String_3CFEF4E3_3BD6_43A4_B680_6DF6E66C4988) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_File_Class_Close_C777D254_C4A1_4173_A38E_1BEDE4FD3B3E) },
    { be_const_key(peek, 11), be_const_ctype_func(Berry_File_Class_peek_1D64A45E_DEFA_4A7F_9549_FF29B8AE3FE1) },
    { be_const_key(Read, 10), be_const_ctype_func(Berry_File_Class_Read_2B47340C_4C49_4492_A18C_44572B492A22) },
    { be_const_key(Peek, 16), be_const_ctype_func(Berry_File_Class_Peek_A81283E5_9BDC_477F_849D_F3ED56EDF4FF) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_92B9A103_4011_4024_9144_B704200C6AF3) },
    { be_const_key(Get_Modification_Time, -1), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_B82B757B_62F6_4F1D_916F_5915B497B90F) },
    { be_const_key(flush, -1), be_const_ctype_func(Berry_File_Class_flush_4D01C099_2D12_4C8E_8012_7A3289740196) },
    { be_const_key(Flush, 21), be_const_ctype_func(Berry_File_Class_Flush_ED583772_B1EA_455F_A693_1A7D9CD13CAF) },
    { be_const_key(read, -1), be_const_ctype_func(Berry_File_Class_read_0C0B52AA_862C_4086_8EE2_EC8744478F06) },
    { be_const_key(Get_Extension, -1), be_const_ctype_func(Berry_File_Class_Get_Extension_12BFCABE_9FBA_44C6_AF72_C03CABCE598C) },
    { be_const_key(_p, 13), be_const_var(0) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_64322406_BE5E_4A0F_B2B1_6F3AF0BF2837) },
    { be_const_key(Available, 26), be_const_ctype_func(Berry_File_Class_Available_ECFFDF70_3F66_45BB_A148_39C37C432825) },
    { be_const_key(readBytes, 4), be_const_ctype_func(Berry_File_Class_readBytes_A6514DD5_A0B7_4360_999D_373B1BFEE4F4) },
    { be_const_key(Get_Size, 0), be_const_ctype_func(Berry_File_Class_Get_Size_219028E3_96B9_4C32_A8FB_C7EE5EA5FCFE) },
    { be_const_key(available, 28), be_const_ctype_func(Berry_File_Class_available_315064AF_EC45_4ADC_8EB4_F797776F72C2) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_BC7A9D6E_D6C4_45E2_9A9A_CF7311D4750B) },
    { be_const_key(Open_Next_File, 27), be_const_ctype_func(Berry_File_Class_Open_Next_File_F6BADC66_7CCE_4D42_97E5_F5C1A2D2A7AB) },
    { be_const_key(Is_Directory, 20), be_const_ctype_func(Berry_File_Class_Is_Directory_D3F8DE3B_96DF_4EC8_B955_975D603EEF8B) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_73D14356_A8CF_4BBF_A9CE_E0D149D27967) },
    { be_const_key(Count_Items, -1), be_const_ctype_func(Berry_File_Class_Count_Items_1ECE2572_736D_45CA_80E0_D8FC3357C12C) },
    { be_const_key(Rewind_Directory, 18), be_const_ctype_func(Berry_File_Class_Rewind_Directory_ACEE0FF5_6E3A_4202_8905_0F78853D5D87) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_E27F4C51_50F2_48FC_82F0_3899089323BD) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_4281A6F9_2EBF_460F_9106_ACA41934E6B1) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_FB00BB45_DB0D_4001_A266_03EB16F220D0) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_633AA7A7_23FE_4750_8CAC_3DD4A9470AFF) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_34FE2769_12ED_432E_8365_208366A7E721) },
    { be_const_key(write, -1), be_const_ctype_func(Berry_File_Class_write_3B6F680C_5F7E_40E6_9943_A9E0B3CEB454) },
    { be_const_key(Get_Position, 8), be_const_ctype_func(Berry_File_Class_Get_Position_CFBCA540_ACCF_4D46_95E0_E9371A18FBAB) },
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
