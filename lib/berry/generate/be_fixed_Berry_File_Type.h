#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(Get_Items_Count, -1), be_const_ctype_func(Berry_File_Class_Get_Items_Count_A575B768_D646_47D3_89AB_28E0F80E79FA) },
    { be_const_key(readBytes, -1), be_const_ctype_func(Berry_File_Class_readBytes_3226C194_7AAF_4B46_9F05_BC5B99E728DF) },
    { be_const_key(Rewind_Directory, 20), be_const_ctype_func(Berry_File_Class_Rewind_Directory_0FEFFA33_88FA_4508_882B_97B8CFA84C0B) },
    { be_const_key(Close, 14), be_const_ctype_func(Berry_File_Class_Close_D795B127_0CD7_436C_BD91_A3AA75446446) },
    { be_const_key(Copy, 1), be_const_ctype_func(Berry_File_Class_Copy_8C9BCB1E_FA9B_4C3F_A3F6_1AEE2092B2EB) },
    { be_const_key(Get_Extension, 23), be_const_ctype_func(Berry_File_Class_Get_Extension_6F2EE6DB_F398_4E24_A9E5_AF25324C74EF) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_File_Class_Peek_B86AA826_5D1F_421E_A474_1153A84AB7D7) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_BEFAB510_52C3_4DC6_AA3C_FFF07714B538) },
    { be_const_key(Get_Modification_Time, 25), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_B922BFD2_8BDD_45B0_ABA0_5AD2D7601DAD) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_E20DA144_5A26_4C03_91B1_3DD771F1AC91) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_802D3C5A_900B_43E8_B55A_5D9D719BCFDB) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_3BC639C8_1694_4A51_A3B5_F69A615DEDEB) },
    { be_const_key(Read, 13), be_const_ctype_func(Berry_File_Class_Read_70B63568_396D_4B27_B7B6_212FE44F8603) },
    { be_const_key(read, -1), be_const_ctype_func(Berry_File_Class_read_51160FCD_CAF6_4DBA_9CC3_10445AA11A60) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_File_Class_Cut_0829DAD3_3200_4598_9F98_84D1156DE198) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_FBEC0960_28E0_42C9_878E_7FBCE4AC3CF4) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_9EDE5BEA_B386_482D_AF1D_45482F44DE78) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_5682A22D_4589_45F7_B9E7_723D594BB834) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_CA3E3D14_153A_4622_B4DC_E2A9BE405665) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_48DA1214_D3E3_4148_8838_5C88EA6096A9) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_EB06A449_2B13_4B17_AC58_D4D8FB29F6B3) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_12EA1C3E_F3A5_4EC7_B035_4ADCB94D3E2F) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_F5C58BAB_2D00_4FE5_A829_9A71C513FC96) },
    { be_const_key(Is_Directory, 12), be_const_ctype_func(Berry_File_Class_Is_Directory_B4C505AE_8C97_4632_91A2_DA6A08E7A4A2) },
    { be_const_key(available, 18), be_const_ctype_func(Berry_File_Class_available_89055E78_4658_44A3_80C6_10E2D96CC2BD) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_CB88A9E6_5337_40D7_BBC6_EE453D891071) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_04B10A96_EB33_45D3_BEAC_63E820125B69) },
    { be_const_key(write, 10), be_const_ctype_func(Berry_File_Class_write_F20F00C4_D3EF_4D6A_B20D_6C56C4CEAD2A) },
    { be_const_key(flush, 7), be_const_ctype_func(Berry_File_Class_flush_1C206E12_CDC9_4BFF_BF44_63FCA6EF6321) },
    { be_const_key(peek, 6), be_const_ctype_func(Berry_File_Class_peek_365A219B_CF31_431C_B767_44613C7AEE0D) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_E246B49B_4FE9_4FF0_B6CA_ACB3257532CD) },
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
