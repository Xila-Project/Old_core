#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(Get_Items_Count, -1), be_const_ctype_func(Berry_File_Class_Get_Items_Count_813EA2D7_E99B_4502_B9E7_C358063A7A76) },
    { be_const_key(readBytes, -1), be_const_ctype_func(Berry_File_Class_readBytes_611D451E_94B6_47A6_95F0_107469A6FA29) },
    { be_const_key(Rewind_Directory, 20), be_const_ctype_func(Berry_File_Class_Rewind_Directory_CDE02B4A_E256_4FAF_98F2_0388E87A4520) },
    { be_const_key(Close, 14), be_const_ctype_func(Berry_File_Class_Close_FCF7E87F_D5DE_414F_B00E_7E75ABA15201) },
    { be_const_key(Copy, 1), be_const_ctype_func(Berry_File_Class_Copy_25D5949F_A3EE_4D0A_A4F6_30D091C24B1D) },
    { be_const_key(Get_Extension, 23), be_const_ctype_func(Berry_File_Class_Get_Extension_1412AA3D_BF48_457A_8901_DC087F4BA91A) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_File_Class_Peek_9E9C1C23_AAA3_4BE7_8235_15B9DA750350) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_5C82D54E_EBB8_4883_8928_F97330C5D8DD) },
    { be_const_key(Get_Modification_Time, 25), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_C633B5BF_AFE3_4E0F_BD56_5B754660C09D) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_7306D974_E5C8_4BB1_9A34_5E9833824220) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_8F57A01F_D3F0_411A_981D_B40031649A2E) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_1F969022_53F6_4FFD_897A_E98F62819CFF) },
    { be_const_key(Read, 13), be_const_ctype_func(Berry_File_Class_Read_2085D6C8_86D4_4CF5_8980_B847AFC609AC) },
    { be_const_key(read, -1), be_const_ctype_func(Berry_File_Class_read_83324CF5_9668_4A27_96D0_55E1652805F9) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_File_Class_Cut_436A39CB_D73E_4B8A_859C_5E1E2331E16F) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_6FD099B8_BAD3_421E_A2E3_372455DA9DBA) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_ED6CE6D6_DC6F_451F_BA5A_B78059BA5A21) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_3FD2CE70_1BEA_4C66_9684_56BA10FD8551) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_31D6B7E2_3D97_4154_A8B3_DC795C48B830) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_1D6C6DFE_2564_4DC9_A944_25277FA5FB7E) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_96F87E33_7811_44B4_9501_96387CF5F7F3) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_8CB3E841_AE72_4ADA_BA34_DC2A84DC6BEB) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_80D0747A_B4C5_4245_9D3B_6AF47D22114D) },
    { be_const_key(Is_Directory, 12), be_const_ctype_func(Berry_File_Class_Is_Directory_5F4633AC_8091_4961_A785_3C2261ECD2FD) },
    { be_const_key(available, 18), be_const_ctype_func(Berry_File_Class_available_162FFF95_29BD_42EE_911C_867B1CC83403) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_FFD82397_7620_48EF_A778_58F568D1E4EB) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_BC7999DE_D737_46FC_88E8_64FC0DD31646) },
    { be_const_key(write, 10), be_const_ctype_func(Berry_File_Class_write_08251178_9391_4301_BFCE_8831A95DF6AF) },
    { be_const_key(flush, 7), be_const_ctype_func(Berry_File_Class_flush_BBED29B4_26EE_43AA_AFFA_377113363695) },
    { be_const_key(peek, 6), be_const_ctype_func(Berry_File_Class_peek_D07DE3C8_1B8D_4AD9_917F_46E89170100A) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_1D75D1BA_C549_468E_80EC_0BAA09D1F9AA) },
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
