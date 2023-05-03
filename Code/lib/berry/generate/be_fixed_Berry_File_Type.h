#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(readBytes, 8), be_const_ctype_func(Berry_File_Class_readBytes_e2dc58f5_e39c_465f_9127_845957caa3f1) },
    { be_const_key(Is_Directory, 7), be_const_ctype_func(Berry_File_Class_Is_Directory_1fe03b3f_5250_4690_954c_482601cfe6cd) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_33a820a4_6bac_4310_90a2_7b3bfd49a226) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_21fb78ae_141e_40ee_9de5_c1e0232e0b12) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_File_Class_Peek_018dcc34_4271_4802_9b4a_dd8bc03c9b74) },
    { be_const_key(Read, -1), be_const_ctype_func(Berry_File_Class_Read_5fda39df_7d95_4941_b6b3_f9a3142d3fb0) },
    { be_const_key(peek, 13), be_const_ctype_func(Berry_File_Class_peek_df206709_e108_4480_9b09_3a14e7aab53d) },
    { be_const_key(flush, -1), be_const_ctype_func(Berry_File_Class_flush_e4ee47bd_15a3_4ec7_8014_ba8c5214bb90) },
    { be_const_key(Write, 27), be_const_ctype_func(Berry_File_Class_Write_7af12367_b791_4df4_8492_eb99e5746272) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_a3673e5a_16d8_477f_aed0_9be0177be496) },
    { be_const_key(Open_Next_File, 4), be_const_ctype_func(Berry_File_Class_Open_Next_File_291057bb_4fba_4657_8b9f_1bc7aed9a36a) },
    { be_const_key(Get_Position, 18), be_const_ctype_func(Berry_File_Class_Get_Position_dedb41ec_06c1_45a9_909b_e140a3044b61) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_3d54797a_488c_4e5f_bad7_4d5786dfab12) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Rewind_Directory, -1), be_const_ctype_func(Berry_File_Class_Rewind_Directory_12711685_bb8b_4929_8cc6_f58ffa52d775) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_d916f414_a745_4872_90a9_ffb3a92ebf51) },
    { be_const_key(Get_Modification_Time, 22), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_a76dd9a2_a0b4_410f_bd47_5f5514b19d9e) },
    { be_const_key(read, 1), be_const_ctype_func(Berry_File_Class_read_f43cff86_2f11_4b32_834b_677e79d618bb) },
    { be_const_key(Count_Items, -1), be_const_ctype_func(Berry_File_Class_Count_Items_0419c97d_d89f_4ea0_bb2a_4f26753525a1) },
    { be_const_key(Close, 23), be_const_ctype_func(Berry_File_Class_Close_4bc9b96c_e5f4_45ab_b143_38ca5f18563e) },
    { be_const_key(available, -1), be_const_ctype_func(Berry_File_Class_available_9a985ca1_7fc5_48cf_bcfd_eddc2c632d03) },
    { be_const_key(Get_Size, 26), be_const_ctype_func(Berry_File_Class_Get_Size_83331593_fe84_48d8_a27b_8a548340cb58) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_0a26ccd3_16af_49ca_942a_a5184eb206a6) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_3692016c_d250_49af_894a_a9c8f5672704) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_ca583bbf_6ddf_4d1b_a449_e92b08527f25) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_dd27317f_77a5_4435_b97e_ebb9ce576faf) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_25c0b949_3408_4e93_ab5b_d5331822c92d) },
    { be_const_key(write, -1), be_const_ctype_func(Berry_File_Class_write_54b0ebf0_6b40_476b_a8b4_e4da286cff4c) },
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
