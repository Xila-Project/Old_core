#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(Get_Items_Count, -1), be_const_ctype_func(Berry_File_Class_Get_Items_Count_67A38E71_3EE7_491E_A06C_B511E08CE44E) },
    { be_const_key(readBytes, -1), be_const_ctype_func(Berry_File_Class_readBytes_045D1989_391F_4E6A_B403_C8449CDC4DE3) },
    { be_const_key(Rewind_Directory, 20), be_const_ctype_func(Berry_File_Class_Rewind_Directory_927466F3_236B_4400_B29F_CBBDBD3FE25A) },
    { be_const_key(Close, 14), be_const_ctype_func(Berry_File_Class_Close_D7A7C774_60B3_4DA0_894E_658A564CECF4) },
    { be_const_key(Copy, 1), be_const_ctype_func(Berry_File_Class_Copy_4E7306D5_756B_4E66_B143_B8A39FCFED6E) },
    { be_const_key(Get_Extension, 23), be_const_ctype_func(Berry_File_Class_Get_Extension_8FC448D3_A414_4C1E_B41C_ED2E26386929) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_File_Class_Peek_03DABA68_557C_497A_A01C_FD5E7A3B124E) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_3FC53393_0282_401D_AF2A_5A80D321904A) },
    { be_const_key(Get_Modification_Time, 25), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_05A20BE0_2E22_40F9_B3C1_01BD9B708412) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_5022C52A_0568_47DD_815A_3DDBD1E880B7) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_99B591C8_4D7D_45FB_A458_FF62CCE36996) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_C336ADF5_E762_4D17_9966_A6941C3E3103) },
    { be_const_key(Read, 13), be_const_ctype_func(Berry_File_Class_Read_576CB4A8_2323_4721_9C84_5C2BCCF00575) },
    { be_const_key(read, -1), be_const_ctype_func(Berry_File_Class_read_BB92CAB2_6860_4738_92FB_30FE2D8DC1BD) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_File_Class_Cut_90D84D7B_38E9_4AD9_86BF_F4C6A7F172DA) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_158F5501_D79D_4415_ACD1_54F658EA70C7) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_2538D22B_2A4D_454E_BFCD_0A5F4C94FFBB) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_2BCFF159_BF99_4D66_8521_7BF06FEA2CBD) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_44EDAD57_C4E0_4B29_8359_DD21C5A0C5C8) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_2CD7CEE1_1349_4C12_BED6_9B669090E83E) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_4462E001_391A_427E_B302_BFE2C21D352E) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_D451757C_3398_4565_8738_E77B9F6F19D1) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_A559F2B8_897F_4816_9E3E_AD22DE2C2F80) },
    { be_const_key(Is_Directory, 12), be_const_ctype_func(Berry_File_Class_Is_Directory_777B9CD4_67FA_4D4D_8FEB_3AF3B1C757A0) },
    { be_const_key(available, 18), be_const_ctype_func(Berry_File_Class_available_4CD36276_E4B3_4E33_9D9D_C91CDFD29B55) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_560B9E10_6AFE_4C00_864A_AC88F7B25552) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_38A29CCD_CFF6_4C50_AD1F_DE2B72F73BB1) },
    { be_const_key(write, 10), be_const_ctype_func(Berry_File_Class_write_E3B6E346_FACB_4407_91F6_E807026A58EA) },
    { be_const_key(flush, 7), be_const_ctype_func(Berry_File_Class_flush_9CDFC0BC_1044_4AB9_93BC_A01D284C87B8) },
    { be_const_key(peek, 6), be_const_ctype_func(Berry_File_Class_peek_722A50F7_4FAD_48E1_9ED4_DD3D927B4C89) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_3C384466_C44D_440A_BA04_3F416C95A9EC) },
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
