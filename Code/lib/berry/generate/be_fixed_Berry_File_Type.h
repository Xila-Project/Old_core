#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(Copy, -1), be_const_ctype_func(Berry_File_Class_Copy_7625A934_5A34_498C_AADA_1F76328E52E6) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_File_Class_Peek_51B0C5EA_A973_4C76_9BA7_2F11FB71E744) },
    { be_const_key(Rewind_Directory, 20), be_const_ctype_func(Berry_File_Class_Rewind_Directory_9F6D7643_6AE2_418A_857A_A5B829401990) },
    { be_const_key(Close, 18), be_const_ctype_func(Berry_File_Class_Close_78F13853_A7E5_4D09_9644_881F1678D499) },
    { be_const_key(readBytes, 0), be_const_ctype_func(Berry_File_Class_readBytes_3E9C79F4_C587_4188_9C42_81AC1544E5B0) },
    { be_const_key(Is_Directory, 13), be_const_ctype_func(Berry_File_Class_Is_Directory_60C87D2F_2D3F_4A43_8E2B_B22963F5FA5A) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_E83903C4_9D6B_4D9E_9A1B_0EBC51EC209B) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_DBB6E7F8_B74B_479E_9B80_EF92AA417441) },
    { be_const_key(Get_Modification_Time, 25), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_72CDDF85_064D_4750_9367_D7590B24B4C6) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_753E5519_F8AE_43C1_BB67_47C61C3378D7) },
    { be_const_key(Count_Items, -1), be_const_ctype_func(Berry_File_Class_Count_Items_43A0A7B7_2304_4C74_ACC9_7B50C946CBE6) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_C0CCFA8F_D290_477C_9767_F02F5E6DB04D) },
    { be_const_key(read, -1), be_const_ctype_func(Berry_File_Class_read_7D6E8B68_EC33_407E_85AD_2023709B8477) },
    { be_const_key(Read, 23), be_const_ctype_func(Berry_File_Class_Read_AEDF70BF_AB76_4E3D_9402_C0EAA01073A5) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_8844B43B_7339_4584_B671_12B537F162E5) },
    { be_const_key(Get_Path, -1), be_const_ctype_func(Berry_File_Class_Get_Path_94FD98A4_2EFB_4C02_8A9D_705F7BB7786E) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_5F0692A6_8486_45B7_949C_5563FB9B86C7) },
    { be_const_key(Seek, -1), be_const_ctype_func(Berry_File_Class_Seek_36D27F39_F01D_47D8_8C75_A36746DF6F1D) },
    { be_const_key(Cut, -1), be_const_ctype_func(Berry_File_Class_Cut_399AB1D9_458B_49A0_B6AA_8E9BBE68FE5F) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Class_Initialize_AC0B56A7_3802_4952_A292_8A7669B64CE4) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_860BAA44_76BC_4112_AD99_9C065D03CACC) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_File_Class_Read_Bytes_A7985196_4EBC_4E7F_A59F_DD925BC30F79) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_698C19CB_CBE4_4EF9_99A9_695520AAB2E3) },
    { be_const_key(Get_Extension, 12), be_const_ctype_func(Berry_File_Class_Get_Extension_62E4CED0_BB4E_4A2F_9A47_E9326FD77A64) },
    { be_const_key(available, 14), be_const_ctype_func(Berry_File_Class_available_A4CC13E7_99AC_4044_9CCC_63EF2F9E694E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_4E1F17FB_A553_468B_ABC7_98A8CA229474) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Name, 10), be_const_ctype_func(Berry_File_Class_Get_Name_A0763E6C_434B_4690_88F9_E04CF20048F8) },
    { be_const_key(write, 7), be_const_ctype_func(Berry_File_Class_write_4C2C4B28_DEBE_46EF_AB7F_0423D1B52233) },
    { be_const_key(flush, 6), be_const_ctype_func(Berry_File_Class_flush_EBFF91C8_B39B_4129_BEA6_ADB564DF3759) },
    { be_const_key(peek, 1), be_const_ctype_func(Berry_File_Class_peek_67218AEB_1139_4A3D_AA0E_A4E8D826C39A) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_90AD899D_4C62_4DF4_96FD_37D562316571) },
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
