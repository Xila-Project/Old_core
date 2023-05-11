#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Type_map) {
    { be_const_key(read, 21), be_const_ctype_func(Berry_File_Class_read_89AD3930_674E_4CF2_8D02_40993732DFB8) },
    { be_const_key(Read_Bytes, 15), be_const_ctype_func(Berry_File_Class_Read_Bytes_C7C7FD68_BCFE_4D36_8350_F8D096B5A562) },
    { be_const_key(Get_Name, -1), be_const_ctype_func(Berry_File_Class_Get_Name_91256F6E_5C20_4E21_9454_BB8C70C41794) },
    { be_const_key(Peek, 27), be_const_ctype_func(Berry_File_Class_Peek_C44DB730_A673_47F0_A73D_C0BC09546792) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_File_Class_Flush_7A94D919_792B_4985_8A42_8374F69E6BB1) },
    { be_const_key(Is_Directory, 12), be_const_ctype_func(Berry_File_Class_Is_Directory_826132F8_2B93_45F0_A484_037CF74C5B42) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Class_Deinitialize_7C028B57_73E1_4561_B039_E61E9CF65D48) },
    { be_const_key(Write, -1), be_const_ctype_func(Berry_File_Class_Write_5B945FC5_D43C_416A_A2EE_BE6E77F20CD5) },
    { be_const_key(Rewind_Directory, -1), be_const_ctype_func(Berry_File_Class_Rewind_Directory_AC5A7A13_719C_4AC5_A772_E0BA6465B6F5) },
    { be_const_key(readBytes, 1), be_const_ctype_func(Berry_File_Class_readBytes_393A6A65_CC0D_4A98_B5A2_411862A96EE5) },
    { be_const_key(Set_Buffer_Size, -1), be_const_ctype_func(Berry_File_Class_Set_Buffer_Size_FEFD28C7_BF06_455D_AB3F_99331FC9ADD4) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_File_Class_Available_042F6648_3165_4439_9027_BD9B4420BA43) },
    { be_const_key(Count_Items, 11), be_const_ctype_func(Berry_File_Class_Count_Items_30168E85_5CBA_4059_9F07_A362FC9AD8DC) },
    { be_const_key(Seek, 8), be_const_ctype_func(Berry_File_Class_Seek_9249AC89_7D3C_4661_A7A4_1DFDA1597986) },
    { be_const_key(init, 20), be_const_ctype_func(Berry_File_Class_Initialize_0D20DBEF_76CE_44BA_8930_4377033FA7BA) },
    { be_const_key(write, -1), be_const_ctype_func(Berry_File_Class_write_C5E44CBB_79EA_4ED0_83AF_CAA7CACFFE28) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_File_Class_Read_String_034FB7C8_5DA0_4163_B952_EAE8369440CD) },
    { be_const_key(Open_Next_File, -1), be_const_ctype_func(Berry_File_Class_Open_Next_File_A738BECB_00A0_462A_B2BB_D91B3A5CAB3F) },
    { be_const_key(Read, 23), be_const_ctype_func(Berry_File_Class_Read_1D21BAE4_CE5B_44DB_87E3_76B6C0E05EF3) },
    { be_const_key(Is_Valid, -1), be_const_ctype_func(Berry_File_Class_Is_Valid_E63E1E98_AFB5_41B1_B601_3FC212AFD589) },
    { be_const_key(Get_Path, 26), be_const_ctype_func(Berry_File_Class_Get_Path_2543520A_88E6_4CE3_9ED7_9454DFFC1107) },
    { be_const_key(Get_Modification_Time, 3), be_const_ctype_func(Berry_File_Class_Get_Modification_Time_F4D33A7B_311C_40B5_9F00_F17FA31FA4BB) },
    { be_const_key(peek, -1), be_const_ctype_func(Berry_File_Class_peek_D664C459_8060_4331_B536_CCD7540CADBC) },
    { be_const_key(available, -1), be_const_ctype_func(Berry_File_Class_available_C9054E84_505B_4E19_9EDF_109720697ECA) },
    { be_const_key(flush, 4), be_const_ctype_func(Berry_File_Class_flush_89C9A3F0_7B62_4AEF_A88D_9A837CF676D7) },
    { be_const_key(Get_Position, -1), be_const_ctype_func(Berry_File_Class_Get_Position_1637BFFF_330D_4321_A052_7DD41B479B52) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_File_Class_Get_Size_A1504DDB_5186_4FC1_8A10_9811147930A5) },
    { be_const_key(Close, 24), be_const_ctype_func(Berry_File_Class_Close_A34BBE81_0A4A_4BE4_BF71_E1CEBCC79761) },
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
