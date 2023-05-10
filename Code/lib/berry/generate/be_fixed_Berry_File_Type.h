#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(read, 21), be_const_ctype_func(Berry_File_Class_read_5D0B527F_04BE_4C44_82D8_A5BBCBDA743D) },
    { be_const_key(Read_Bytes, 15), be_const_ctype_func(Berry_File_Class_Read_Bytes_2C672C21_626F_487F_B6F5_DD8144D531A2) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_C97B9B61_B31D_436C_8926_99A487401B4F) },
    { be_const_key(Peek, 27), be_const_ctype_func(Berry_File_Class_Peek_156BB136_C5F7_4B1D_85A7_3CF009F56241) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_DBDC787A_24DE_44BE_9D8B_E6C279FB9FA4) },
    { be_const_key(Is_Directory, 12), be_const_ctype_func(Berry_File_Class_Is_Directory_93FB99ED_1D78_4AF3_9664_D69713768B12) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_49C9CD88_8547_425C_A9BB_D02FD426F259) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_054FD756_CF3D_40B7_85C0_1D59C9C017B1) },
    { be_const_key(Rewind_Directory, -1), be_const_ctype_func(Berry_File_Class_Rewind_Directory_BC515C35_1EA6_4603_BC64_3ADDEF5A9243) },
    { be_const_key(readBytes, 1), be_const_ctype_func(Berry_File_Class_readBytes_7F5CC2E5_9ADC_4A96_8CA1_7C7F3EB63413) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_E3CE36BF_D3CC_4C18_8341_331A729230B6) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_6F76D8E5_764E_4607_B338_EE9FAE7709C0) },
    { be_const_key(Count_Items, 11), be_const_ctype_func(Berry_File_Class_Count_Items_C76986E2_EC7C_423B_A42F_A6BBFAA0EC65) },
    { be_const_key(Seek, 8), be_const_ctype_func(Berry_File_Class_Seek_0F16360B_C3E9_4256_9E0F_49A83CDD2AB5) },
    { be_const_key(init, 20), be_const_ctype_func(Berry_File_Class_Initialize_89E5F6EB_EFC2_4E9D_A0B1_0063991E5B02) },
    { be_const_key(write, -1), be_const_ctype_func(Berry_File_Class_write_AA006604_831E_47B3_9FCB_D9B0387D9D78) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_063996C6_F76D_46C9_8A1B_A84DCE9DD092) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_F3A440A2_B03D_463D_AAEE_4F8A6FC6098F) },
    { be_const_key(Read, 23), be_const_ctype_func(Berry_File_Class_Read_BD66E371_9976_4ABA_AD23_0650827FC446) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_38338FE1_B5E7_4BCD_8B88_2D2593FB90E6) },
    { be_const_key(Get_Path, 26), be_const_ctype_func(Berry_File_Class_Get_Path_4FE8C7D8_1299_45C4_BC74_F24470ED3851) },
    { be_const_key(Get_Modification_Time, 3), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_0C9FF412_40B1_4A82_BAC7_A5A7B8E90430) },
    { be_const_key(peek, -1), be_const_ctype_func(Berry_File_Class_peek_2311D02B_A322_4AE8_B62C_33CE52C9A95A) },
    { be_const_key(available, -1), be_const_ctype_func(Berry_File_Class_available_5F6F5EAD_6B77_45F9_AACE_CC63C100E65F) },
    { be_const_key(flush, 4), be_const_ctype_func(Berry_File_Class_flush_C914F5C7_BF0C_4C33_AE40_926C66943EB4) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_67130317_9E1F_4679_B6D3_CEB4BC13C597) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_1610240B_B654_4F27_B26B_B6E279DCD342) },
    { be_const_key(Close, 24), be_const_ctype_func(Berry_File_Class_Close_8EF45F80_D103_4A3A_AE8F_DB9B3ECB2D8D) },
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
