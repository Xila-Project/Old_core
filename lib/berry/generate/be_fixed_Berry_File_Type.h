#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(Get_Items_Count, -1), be_const_ctype_func(Berry_File_Class_Get_Items_Count_FA908000_BFA3_4A82_B929_AF7B45780E05) },
    { be_const_key(readBytes, -1), be_const_ctype_func(Berry_File_Class_readBytes_F78FD973_36EB_44E1_8E18_4CECD0C23572) },
    { be_const_key(Rewind_Directory, 20), be_const_ctype_func(Berry_File_Class_Rewind_Directory_A64CC7E4_74DE_41B2_9AB3_66C0C342ED06) },
    { be_const_key(Close, 14), be_const_ctype_func(Berry_File_Class_Close_0C2452EF_C97A_4930_AC83_98754746C2F9) },
    { be_const_key(Copy, 1), be_const_ctype_func(Berry_File_Class_Copy_7EF77F59_B357_477C_A2DB_7124A60C880B) },
    { be_const_key(Get_Extension, 23), be_const_ctype_func(Berry_File_Class_Get_Extension_7C147AC0_2678_4007_9486_9D93755CB212) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_File_Class_Peek_C5BF0B82_6FB9_4E7A_9CEF_78743C779AE0) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_4EC74F0E_3602_4317_9014_474EF01745AE) },
    { be_const_key(Get_Modification_Time, 25), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_A39EEE4D_9599_4E75_BCE5_56ACC6B56841) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_5FD6D746_78B7_4E34_A2A6_23B19BFB9B2D) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_7B8F47B6_7D0E_4988_8AD5_1CA351585869) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_C5B0C826_2B79_4594_99BB_0603FE277B28) },
    { be_const_key(Read, 13), be_const_ctype_func(Berry_File_Class_Read_222ECA61_D03B_4FED_B2EB_461CE0F906F6) },
    { be_const_key(read, -1), be_const_ctype_func(Berry_File_Class_read_14CFFF8D_6C20_4B85_B632_059861DD8566) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_File_Class_Cut_24F1B617_7909_4E13_8B79_D1C2AE78B0C0) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_3E4E2D40_BF25_40B0_9814_7DD6D02590B8) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_A7C35AB5_B4F9_492A_9D2F_2FE4E81F3A0C) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_605A9120_5885_41FA_B2C3_C9E735E20EDB) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_8469AA1D_87B1_4C5C_910D_DE69C0F413EE) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_28C1D217_370F_4003_A053_3C04A2F5B0FC) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_1BBEC06E_585E_4CBC_A8A8_F96A4A8E4AE0) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_D243A3E0_6990_499A_A4BB_23BB682D4C14) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_45169985_7305_43E7_8D30_EFAAEBC4516C) },
    { be_const_key(Is_Directory, 12), be_const_ctype_func(Berry_File_Class_Is_Directory_CCA67165_8C57_4C05_8C1E_B77A22AD4347) },
    { be_const_key(available, 18), be_const_ctype_func(Berry_File_Class_available_A223393A_6064_4230_B6FE_E8530053D02D) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_D9366483_D236_4B76_ADAD_986FBD785252) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_A6CA562D_59D3_4DD9_A1B1_A11423FBE899) },
    { be_const_key(write, 10), be_const_ctype_func(Berry_File_Class_write_848469FD_EE02_41BC_A1D9_B0A80F25EBDA) },
    { be_const_key(flush, 7), be_const_ctype_func(Berry_File_Class_flush_B503E014_DF67_4AEC_9A58_B0E087B1377C) },
    { be_const_key(peek, 6), be_const_ctype_func(Berry_File_Class_peek_C4C54B90_801A_4E21_9134_886BF79A67F4) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_5682975E_635F_41CD_8F5D_661854FAB12D) },
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
