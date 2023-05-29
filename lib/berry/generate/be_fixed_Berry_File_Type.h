#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(Get_Items_Count, -1), be_const_ctype_func(Berry_File_Class_Get_Items_Count_FF444C66_1BB4_42EF_8EB7_102FC62ABA79) },
    { be_const_key(readBytes, -1), be_const_ctype_func(Berry_File_Class_readBytes_6E94C4BD_76F4_4B29_97D0_BCD0730084EE) },
    { be_const_key(Rewind_Directory, 20), be_const_ctype_func(Berry_File_Class_Rewind_Directory_4F964281_5EC1_477E_B96F_41FF4F548EAF) },
    { be_const_key(Close, 14), be_const_ctype_func(Berry_File_Class_Close_662BDFF3_C647_45EC_8DA9_BFA508CB5908) },
    { be_const_key(Copy, 1), be_const_ctype_func(Berry_File_Class_Copy_F0EBA56B_A608_4932_AE71_F42F4D5DFB1D) },
    { be_const_key(Get_Extension, 23), be_const_ctype_func(Berry_File_Class_Get_Extension_CB8C6A1E_9209_4A77_84B8_B9961A0CFBA2) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_File_Class_Peek_4072D3EC_7D44_47FE_8E76_9BCDDDFB9149) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_DD787D26_C06D_425F_B868_A756501DFDDB) },
    { be_const_key(Get_Modification_Time, 25), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_18A366E5_E78E_4024_A9FD_0BA0A999D722) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_98B8FBEA_C1C8_412E_B2CC_F92E44883C18) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_BE4E1EF5_B6E7_44A9_8F9A_3FFDE02FC4DA) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_2E763313_03E8_4849_8E3B_BE135FA7C66A) },
    { be_const_key(Read, 13), be_const_ctype_func(Berry_File_Class_Read_F43D93BF_9A65_4027_A39C_104C127B6DAF) },
    { be_const_key(read, -1), be_const_ctype_func(Berry_File_Class_read_E257313E_C207_4FC6_A6B7_CEBC964F6C7A) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_File_Class_Cut_E01F4051_162D_447A_B563_52D31A8836FC) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_9F063A4F_DED1_4434_A48E_0501A1538260) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_60CF8318_3325_4DE4_8D9D_43D623DB0D6B) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_4F8BD485_90F1_4AA0_A2E1_36FBF32CEFEB) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_E80E86EF_C3BC_443F_AF92_18506D21253C) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_55FB078B_ECE3_46AF_B945_8B6781D48426) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_1E639A9E_D52F_46DA_B4F9_B20F763ECDA3) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_70D556FE_0E13_4DBE_A0C7_8DC1E4DC9F4C) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_B0BE0C8F_1211_4273_AB23_76AF41884D07) },
    { be_const_key(Is_Directory, 12), be_const_ctype_func(Berry_File_Class_Is_Directory_E4B171D3_C1E9_4682_B878_D8D6836FF51B) },
    { be_const_key(available, 18), be_const_ctype_func(Berry_File_Class_available_DB47C714_559A_4F09_A911_F9B6F944DE3E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_8DDFDE9D_F457_4EAB_AB21_71A5603F83BF) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_C392525B_C8EE_4BDE_88E3_5D1DC5CEC1BF) },
    { be_const_key(write, 10), be_const_ctype_func(Berry_File_Class_write_5CF900F7_C3F5_4501_AA8B_88A5F44510D7) },
    { be_const_key(flush, 7), be_const_ctype_func(Berry_File_Class_flush_807B5BB7_0A03_43E6_A81F_F256CBF808FB) },
    { be_const_key(peek, 6), be_const_ctype_func(Berry_File_Class_peek_A049D46B_117E_4A06_A1B7_EB8ED218D4D5) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_9611E164_59A1_4C94_BBEE_CF73C538A1C2) },
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
