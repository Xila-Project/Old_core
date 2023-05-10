#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(read, 21), be_const_ctype_func(Berry_File_Class_read_58C254A5_6BFF_452F_87B2_2BB584B87095) },
    { be_const_key(Read_Bytes, 15), be_const_ctype_func(Berry_File_Class_Read_Bytes_C69A78F4_2A49_4EA1_8D40_EF5E26A608B2) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_6284A425_AC61_4AD9_A02F_0D3F59CF040F) },
    { be_const_key(Peek, 27), be_const_ctype_func(Berry_File_Class_Peek_826DB653_030E_441F_B484_5D37A4B2888D) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_AA401690_577D_4009_935A_9BCD37C73AE6) },
    { be_const_key(Is_Directory, 12), be_const_ctype_func(Berry_File_Class_Is_Directory_382D6DD5_9905_429A_BA75_C49B89F95DFC) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_3D63CDDB_F3B3_491E_B612_1EF20CF1381C) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_2B47DDA8_4F5E_4B5F_A384_AEA965909344) },
    { be_const_key(Rewind_Directory, -1), be_const_ctype_func(Berry_File_Class_Rewind_Directory_EE1E2E93_D6D2_4197_A8C8_EC9314D29CC9) },
    { be_const_key(readBytes, 1), be_const_ctype_func(Berry_File_Class_readBytes_1E39155E_30B1_407F_9729_FC328F2871E0) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_FF3FE386_1EF5_419A_BB53_154990B55D9A) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_E98254BF_4EBD_44C9_B355_6559707DC288) },
    { be_const_key(Count_Items, 11), be_const_ctype_func(Berry_File_Class_Count_Items_38DAB241_22C9_4BCC_8D15_BCFCADD04208) },
    { be_const_key(Seek, 8), be_const_ctype_func(Berry_File_Class_Seek_5947BCC1_84C7_473A_957B_7796693EA313) },
    { be_const_key(init, 20), be_const_ctype_func(Berry_File_Class_Initialize_62AEF542_51ED_414E_BFE2_0BBB5640734C) },
    { be_const_key(write, -1), be_const_ctype_func(Berry_File_Class_write_D0104591_DCC2_4ED2_BA3E_3A85394B758C) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_AB814046_17E3_49A7_BABD_B7882092A97B) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_8F3B40BF_7483_4B21_9A38_DBBD3F9E6669) },
    { be_const_key(Read, 23), be_const_ctype_func(Berry_File_Class_Read_473F8098_4748_4B10_907F_084F865FB109) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_58AEC63F_EDDC_4297_BE91_46B446861468) },
    { be_const_key(Get_Path, 26), be_const_ctype_func(Berry_File_Class_Get_Path_F115F3C2_DA51_40FF_8E53_9FA0BC0559D8) },
    { be_const_key(Get_Modification_Time, 3), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_BD075E36_CF04_476A_BF0A_E2F234F55888) },
    { be_const_key(peek, -1), be_const_ctype_func(Berry_File_Class_peek_D3A6D094_8E66_4C50_8144_997097F08E21) },
    { be_const_key(available, -1), be_const_ctype_func(Berry_File_Class_available_829DE9C0_B8A7_420D_868F_915E4E8CB45E) },
    { be_const_key(flush, 4), be_const_ctype_func(Berry_File_Class_flush_C9EA15C9_CC7E_4F59_8A2B_F20195108620) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_58D37AEE_335C_4901_8DA4_0ABBA84455CC) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_7A5CB824_5383_4BF7_87FB_3C5FCB8D33BE) },
    { be_const_key(Close, 24), be_const_ctype_func(Berry_File_Class_Close_5D74F20F_3E2C_4015_894D_A7672B88061D) },
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
