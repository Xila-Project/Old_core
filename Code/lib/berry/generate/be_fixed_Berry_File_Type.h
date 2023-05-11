#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(read, 21), be_const_ctype_func(Berry_File_Class_read_4782FDB7_518C_406A_BF6F_5ECAF0A3E7AE) },
    { be_const_key(Read_Bytes, 15), be_const_ctype_func(Berry_File_Class_Read_Bytes_8B133328_2FAA_4B5C_9673_6012FE0D6318) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_5DDB7176_A0A4_4B00_A1D7_A52F5DF1D771) },
    { be_const_key(Peek, 27), be_const_ctype_func(Berry_File_Class_Peek_606BCF2A_13FC_454C_BB6E_6BE40C69C52F) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_D4C7DDAB_6F48_4828_BBBE_206239D054A7) },
    { be_const_key(Is_Directory, 12), be_const_ctype_func(Berry_File_Class_Is_Directory_76692326_4704_481C_AA36_861838938AE3) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_5C8BFEB1_0FD2_4C87_851C_AAE928628808) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_EA86D3B4_924B_42B7_81C5_5C609A303285) },
    { be_const_key(Rewind_Directory, -1), be_const_ctype_func(Berry_File_Class_Rewind_Directory_2253D421_11F2_48FD_A280_A425D834EAE6) },
    { be_const_key(readBytes, 1), be_const_ctype_func(Berry_File_Class_readBytes_40DE1176_745E_47AF_8DEB_7CDB21DF1D3C) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_4A20CCC9_C698_45D2_B075_8E0A10934BA2) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_05E0E93A_8093_4BF4_9B93_3A12CB684D56) },
    { be_const_key(Count_Items, 11), be_const_ctype_func(Berry_File_Class_Count_Items_79CE322E_C6E1_4299_8CD2_CB911310C7CF) },
    { be_const_key(Seek, 8), be_const_ctype_func(Berry_File_Class_Seek_753F1B09_3830_45B2_9377_7EB97EDFDED6) },
    { be_const_key(init, 20), be_const_ctype_func(Berry_File_Class_Initialize_906F5B24_EA49_4475_8A4C_0B713F1A9908) },
    { be_const_key(write, -1), be_const_ctype_func(Berry_File_Class_write_FF4652AD_ED14_46C8_A394_C7DD02AE3776) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_91B60346_A169_44CB_BA23_7E356609795A) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_D6500869_2D19_4F78_A3B7_6E4816055CA6) },
    { be_const_key(Read, 23), be_const_ctype_func(Berry_File_Class_Read_952DA1B7_A412_44FC_A3C9_2917C45C84BF) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_B4ED410D_FA42_4560_8D94_02D740E7A0E4) },
    { be_const_key(Get_Path, 26), be_const_ctype_func(Berry_File_Class_Get_Path_7B24D4DC_891E_4A69_9104_D11D28A956A8) },
    { be_const_key(Get_Modification_Time, 3), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_FE4B1C3D_3D85_495D_9F60_15CD0A2DE6AB) },
    { be_const_key(peek, -1), be_const_ctype_func(Berry_File_Class_peek_0D65D148_C36F_4F66_9FB1_56B6F1FA7B69) },
    { be_const_key(available, -1), be_const_ctype_func(Berry_File_Class_available_B45E3334_B549_4B7B_B5DD_E3C41476E7CD) },
    { be_const_key(flush, 4), be_const_ctype_func(Berry_File_Class_flush_76416564_C458_4FE1_BE07_47D35C6DBB41) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_769C1F89_3C19_4D5D_8BD9_3C1BFF1C2EAF) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_533F9031_AD17_4E18_B5FF_947B7BB6C9CF) },
    { be_const_key(Close, 24), be_const_ctype_func(Berry_File_Class_Close_3B04927A_8CF3_470F_BAA4_91C97814DB40) },
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
