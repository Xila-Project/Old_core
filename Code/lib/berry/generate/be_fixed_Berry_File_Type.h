#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(read, 21), be_const_ctype_func(Berry_File_Class_read_29902466_7CEF_42E7_BE8B_6FD85126413E) },
    { be_const_key(Read_Bytes, 15), be_const_ctype_func(Berry_File_Class_Read_Bytes_0DB12BC3_FF42_460F_AE11_1DA2252FF27C) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_09A18CFF_C54F_49EC_9E12_3AB285CAA4BE) },
    { be_const_key(Peek, 27), be_const_ctype_func(Berry_File_Class_Peek_B77270EE_C92D_4104_9671_99ED6AAEB336) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_A3C1716B_9BBE_429C_A438_DE5671A98DED) },
    { be_const_key(Is_Directory, 12), be_const_ctype_func(Berry_File_Class_Is_Directory_C237F8E2_F545_4294_85BB_83B1AD0613AD) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_86529848_AD89_4150_9CDE_46C92C293C7D) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_9DE66D34_D644_4D5E_A392_3E3E6B6FDFD3) },
    { be_const_key(Rewind_Directory, -1), be_const_ctype_func(Berry_File_Class_Rewind_Directory_A1379974_046C_4742_8631_DC56F37AF4DF) },
    { be_const_key(readBytes, 1), be_const_ctype_func(Berry_File_Class_readBytes_ADC4581C_08E1_4178_9F4F_6D48B176AF34) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_22266F64_A46A_42CF_9AD4_0944FE2992C3) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_542201F2_12A1_4BC4_AD79_FBF227D01C1C) },
    { be_const_key(Count_Items, 11), be_const_ctype_func(Berry_File_Class_Count_Items_6C9E0028_B1F2_472A_A4B2_A556B4E44D9E) },
    { be_const_key(Seek, 8), be_const_ctype_func(Berry_File_Class_Seek_E9A09E59_CA26_45C6_8539_3D86985C39B6) },
    { be_const_key(init, 20), be_const_ctype_func(Berry_File_Class_Initialize_508B927C_A45B_4656_88F5_5F6D52ED4BFC) },
    { be_const_key(write, -1), be_const_ctype_func(Berry_File_Class_write_51B361B0_D723_4CFE_BAE5_3436357FE8B4) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_9C965691_A71E_4E2C_9EE4_E1A9923549FF) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_00E8D493_E0AE_46F7_BC18_C0554EEA687A) },
    { be_const_key(Read, 23), be_const_ctype_func(Berry_File_Class_Read_5339B0CE_D310_49A6_9821_468317858378) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_CC260678_B125_41AD_9C53_8A589F15A1DF) },
    { be_const_key(Get_Path, 26), be_const_ctype_func(Berry_File_Class_Get_Path_3B734ECA_5CA2_42D4_B222_3DA66AE16291) },
    { be_const_key(Get_Modification_Time, 3), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_DD0DD7B8_1545_43D9_8792_94670F4E6FDC) },
    { be_const_key(peek, -1), be_const_ctype_func(Berry_File_Class_peek_B23668A3_B44B_47FC_98D3_D750082E4124) },
    { be_const_key(available, -1), be_const_ctype_func(Berry_File_Class_available_AE37BFF6_5828_4CCC_81CD_D09DE1AC145E) },
    { be_const_key(flush, 4), be_const_ctype_func(Berry_File_Class_flush_6D25654C_AFB4_4669_B3DA_8E4025903F17) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_174422F2_C060_4793_A76D_F042DB7572C7) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_B9E3CB89_9BDE_4A19_8800_6EB0B9DA72A9) },
    { be_const_key(Close, 24), be_const_ctype_func(Berry_File_Class_Close_46B0A99F_3434_46B7_A8CB_DBCDFCA49237) },
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
