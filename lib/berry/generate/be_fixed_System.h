#include "be_constobj.h"

static be_define_const_map_slots(m_libSystem_map) {
    { be_const_key(Set_Time_Zone, -1), be_const_ctype_func(Berry_System_Class_Set_Time_Zone_36989802_6691_4FDD_AE23_EE08E8F0F50C) },
    { be_const_key(Panic_Memory_Corruption, -1), be_const_int(14) },
    { be_const_key(Get_Up_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_F788A874_D5C1_46BB_9F41_D9CD99AC40FC) },
    { be_const_key(Get_Cycles_Count, -1), be_const_ctype_func(Berry_System_Class_Get_Cycles_Count_9847E7C6_40B8_40EE_BC31_7D5371577409) },
    { be_const_key(Panic_Failed_To_Start_Display, -1), be_const_int(5) },
    { be_const_key(Panic_Failed_To_Start_Sound, 23), be_const_int(7) },
    { be_const_key(Panic_Failed_To_Update_Display, -1), be_const_int(1) },
    { be_const_key(Panic_Failed_To_Start_Softwares, -1), be_const_int(12) },
    { be_const_key(Panic_Failed_To_Start_Accounts, 34), be_const_int(10) },
    { be_const_key(Shutdown, -1), be_const_ctype_func(Berry_System_Class_Shutdown_67423F3F_A38A_4CEC_BA1F_C9001D32709F) },
    { be_const_key(Set_NTP_Server, -1), be_const_ctype_func(Berry_System_Class_Set_NTP_Server_8C1EA493_4792_4A69_990A_4042872491AA) },
    { be_const_key(Refresh_NTP_Client, -1), be_const_ctype_func(Berry_System_Class_Refresh_NTP_Client_5C2EFCF0_57A5_45BA_9DBB_2503F4553D65) },
    { be_const_key(Panic_Low_Memory, 38), be_const_int(13) },
    { be_const_key(Panic_Failed_To_Start_Power, 28), be_const_int(8) },
    { be_const_key(Get_Chip_Model, 33), be_const_ctype_func(Berry_System_Class_Get_Chip_Model_D24D0BB7_6506_47FB_A2FA_8FE2C2487910) },
    { be_const_key(Panic_Installation_Conflict, 22), be_const_int(3) },
    { be_const_key(Get_NTP_Server, 25), be_const_ctype_func(Berry_System_Class_Get_NTP_Server_869BD70F_EE3D_4863_9E82_83B0A67775F0) },
    { be_const_key(Panic_Missing_System_Files, -1), be_const_int(0) },
    { be_const_key(Get_CPU_Frequency, 10), be_const_ctype_func(Berry_System_Class_Get_CPU_Frequency_77E8035A_897B_4474_A896_BF4644581DDA) },
    { be_const_key(Get_Date, -1), be_const_ctype_func(Berry_System_Class_Get_Date_59091634_0987_4EDC_852F_DC1736FEA196) },
    { be_const_key(Get_UTC_Offset, 3), be_const_ctype_func(Berry_System_Class_Get_UTC_Offset_DA72740F_51A1_4044_9832_B77FF13AABCE) },
    { be_const_key(Set_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Set_Device_Name_C3CCE7A9_57DC_4ECA_915C_5AF006215B51) },
    { be_const_key(Restart, -1), be_const_ctype_func(Berry_System_Class_Restart_CED58F4A_16D5_4662_9D1A_1F3622A399D9) },
    { be_const_key(Get_Up_Time_Microseconds, 37), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Microseconds_7AEB076C_B127_47CF_AEC5_1A75FA989828) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_System_Class_Get_Pointer) },
    { be_const_key(Get_Time, -1), be_const_ctype_func(Berry_System_Class_Get_Time_C0BFBCE0_CA63_4693_9788_307689C944EF) },
    { be_const_key(Panic_Failed_To_Start_Drive, 18), be_const_int(11) },
    { be_const_key(Get_Daylight_Offset, -1), be_const_ctype_func(Berry_System_Class_Get_Daylight_Offset_AE98CCCA_B9B1_40F1_8384_313A6E94FCE6) },
    { be_const_key(Get_Up_Time_Milliseconds, -1), be_const_ctype_func(Berry_System_Class_Get_Up_Time_Milliseconds_E339924A_43ED_46D0_A2EF_C94B01C89F7A) },
    { be_const_key(Task_Function, 35), be_const_ctype_func(Berry_System_Class_Task_Function_1AEC152E_867C_4CD9_9101_4767913B2F5C) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_System_Class_Start_AC9D9DA9_655D_46C7_A7D0_1EF3268A87B1) },
    { be_const_key(Panic_Damaged_System_Registry, -1), be_const_int(2) },
    { be_const_key(Get_eFuse_MAC, -1), be_const_ctype_func(Berry_System_Class_Get_eFuse_MAC_5E18F876_324A_4BA5_A009_7A2B1AFFAA57) },
    { be_const_key(Panic_Failed_To_Start_Communication, -1), be_const_int(9) },
    { be_const_key(Panic_Drive_Failure, -1), be_const_int(4) },
    { be_const_key(Get_Chip_Cores, 31), be_const_ctype_func(Berry_System_Class_Get_Chip_Cores_0681EF7C_8BC6_4746_B199_63B137F27EEE) },
    { be_const_key(Panic_Failed_To_Start_Graphics, -1), be_const_int(6) },
    { be_const_key(Get_Chip_Revision, -1), be_const_ctype_func(Berry_System_Class_Get_Chip_Revision_4CE63BC2_E8D0_4DB8_80FA_B9E71230670A) },
    { be_const_key(Get_Device_Name, -1), be_const_ctype_func(Berry_System_Class_Get_Device_Name_947F0C15_D75C_42FF_B83A_AA77E6F51829) },
};

static be_define_const_map(
    m_libSystem_map,
    39
);

static be_define_const_module(
    m_libSystem,
    "System"
);

BE_EXPORT_VARIABLE be_define_const_native_module(System);
