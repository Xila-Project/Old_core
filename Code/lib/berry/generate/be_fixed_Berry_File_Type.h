#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(readBytes, 8), be_const_ctype_func(Berry_File_Class_readBytes_8A33C0B2_D1BE_4903_89BF_778AD74A49EA) },
    { be_const_key(Is_Directory, 7), be_const_ctype_func(Berry_File_Class_Is_Directory_F417517A_646E_425D_B0C1_A0D8ED8CFAE3) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_C1AA84F1_8701_464C_9A80_69F52BE09E21) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_6DBA3C3B_6A91_4ED7_BEEC_BB23C579F7FF) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_File_Class_Peek_F8F7C991_4814_4015_AEC1_7A7EFAF929AE) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_File_Class_Read_C6A71902_76B5_46DF_BD86_CE18900592C7) },
    { be_const_key(peek, 13), be_const_ctype_func(Berry_File_Class_peek_5FC756B8_87A4_4B3A_82A5_76CF28EC50F0) },
    { be_const_key(flush, -1), be_const_ctype_func(Berry_File_Class_flush_0FF2C959_71E2_433D_ADAE_AEFF4E703DE1) },
    { be_const_key(Write, 27), be_const_ctype_func(Berry_File_Class_Write_59756FEE_17A6_43FE_BEA7_53E196A1719B) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_C9C5611D_48BE_49E1_907B_437BCE7553F1) },
    { be_const_key(Open_Next_File, 4), be_const_ctype_func(Berry_File_Class_Open_Next_File_F8C702F7_27F0_4878_BBD9_885DE57F811B) },
    { be_const_key(Get_Position, 18), be_const_ctype_func(Berry_File_Class_Get_Position_680DFD35_FDBD_464B_BB7D_543CFEC82995) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_22D363F7_7CB5_479A_93BA_DB45A009A40F) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Rewind_Directory, -1), be_const_ctype_func(Berry_File_Class_Rewind_Directory_BBB9C4D1_FA96_455B_ACF8_E46588363EA3) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_D398927D_175B_45E5_9D8D_2D448288123C) },
    { be_const_key(Get_Modification_Time, 22), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_137A6F25_0968_49A7_9884_633EFF13C2AB) },
    { be_const_key(read, 1), be_const_ctype_func(Berry_File_Class_read_AC067120_F5B9_4DCA_8D04_6C43948D2A09) },
    { be_const_key(Count_Items, -1), be_const_ctype_func(Berry_File_Class_Count_Items_E6988314_7CED_4774_AB86_08C7FF0C6A59) },
    { be_const_key(Close, 23), be_const_ctype_func(Berry_File_Class_Close_F3DBA346_45DA_45F9_8D51_B9C9F65CFCB4) },
    { be_const_key(available, -1), be_const_ctype_func(Berry_File_Class_available_DA5A97BD_3838_447A_9055_991190CD4D86) },
    { be_const_key(Get_Size, 26), be_const_ctype_func(Berry_File_Class_Get_Size_F225E16D_0D33_4F3E_BB72_E8A35C0B3FD7) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_CC8C983A_341C_4C8B_AEA7_840406CDF042) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_CB14102B_A19C_447D_8E54_3EA181C343C3) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_37F54FBB_C57E_4CBA_BCB8_1D2A229EA36B) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_98718558_7145_4D49_B6CD_487EF8605343) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_F21F456A_BAF4_479D_963E_7FD34C6188E4) },
    { be_const_key(write, -1), be_const_ctype_func(Berry_File_Class_write_17AAA87F_86F0_4A48_A6A6_3AEF3ECF1B37) },
};

static be_define_const_map(
    Berry_File_Type_map,
    28
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_File_Type,
    1,
    NULL,
    File_Type
);
