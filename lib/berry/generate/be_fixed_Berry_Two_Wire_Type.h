#include "be_constobj.h"

static be_define_const_map_slots(Berry_Two_Wire_Type_map) {
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Two_Wire_Class_Write_4BC8DED4_A828_4C03_868A_B4351FCF4A61) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Two_Wire_Class_Read_String_35A68179_C3F0_467E_9BB6_8DDD75C99B6E) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Two_Wire_Class_Available_F4F19619_CF7A_46F9_8838_AABE5F696A73) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Two_Wire_Class_Peek_D0C93F67_581D_467C_AE6A_B42733893DC6) },
    { be_const_key(Get_Clock_Frequency, -1), be_const_ctype_func(Berry_Two_Wire_Class_Get_Clock_Frequency_60F164B7_C3D8_42DB_8D82_47E679BF4260) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Two_Wire_Class_Write_Bytes_050AC144_6F69_4D4E_B10F_A2B78692E561) },
    { be_const_key(Slave_Write, -1), be_const_ctype_func(Berry_Two_Wire_Class_Slave_Write_683587A1_43F1_4B00_93E4_B781FB04B78A) },
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Two_Wire_Class_Set_Pins_46D78B1C_5349_4CC3_9DCD_2071FBB748E0) },
    { be_const_key(End_Transmission, -1), be_const_ctype_func(Berry_Two_Wire_Class_End_Transmission_4DFD48EA_422C_4936_8DE6_03F49C0E770E) },
    { be_const_key(Set_Timeout, -1), be_const_ctype_func(Berry_Two_Wire_Class_Set_Timeout_D90BCCBD_B0D2_43DD_95C0_7E4C271139F1) },
    { be_const_key(Request_From, 13), be_const_ctype_func(Berry_Two_Wire_Class_Request_From_C1781B1E_6F85_4C6C_A019_831E67D1182A) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Two_Wire_Class_Flush_B7F88ECE_0E98_4AD6_ADCD_0C4DB6C1ABCF) },
    { be_const_key(Read, 1), be_const_ctype_func(Berry_Two_Wire_Class_Read_5EF3697E_E9C8_417B_8672_7D27415541B1) },
    { be_const_key(Begin, 14), be_const_ctype_func(Berry_Two_Wire_Class_Begin_79E20CD8_0139_4AAE_9A6C_00D8706EDE6E) },
    { be_const_key(Begin_Transmission, 15), be_const_ctype_func(Berry_Two_Wire_Class_Begin_Transmission_3A75290F_D13D_4B21_A046_D9C7BFEB7659) },
    { be_const_key(Set_Clock_Frequency, -1), be_const_ctype_func(Berry_Two_Wire_Class_Set_Clock_Frequency_14141973_6DF1_4C79_BBFC_62B9A75505B2) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_Two_Wire_Class_Read_Bytes_78311E62_2776_4F00_9918_C0D9350495BF) },
    { be_const_key(Get_Timeout, 3), be_const_ctype_func(Berry_Two_Wire_Class_Get_Timeout_0B781774_F9A8_4EF2_A9AF_72375574BD20) },
    { be_const_key(End, 9), be_const_ctype_func(Berry_Two_Wire_Class_End_26085972_25B9_42CD_A984_3F6824D218BE) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Two_Wire_Class_Deinitialize_655D10A0_5B43_429E_B844_4F73DC1AEEDE) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Two_Wire_Type_map,
    21
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Two_Wire_Type,
    1,
    NULL,
    Two_Wire_Type
);
