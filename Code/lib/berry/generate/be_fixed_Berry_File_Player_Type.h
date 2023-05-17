#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Player_Type_map) {
    { be_const_key(Set_Output_Stream, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Output_Stream_B6701AD0_87EA_4539_AE59_61423D924FD2) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_File_Player_Class_Begin_4CEB773D_D238_4D30_AD45_3F6984A0810B) },
    { be_const_key(Get_Total_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Total_Time_C3021C86_7D90_4738_954E_80CD7DBDF6A9) },
    { be_const_key(Set_Input_File, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Input_File_DC0E29B0_E899_4287_9468_850F92409CA1) },
    { be_const_key(Set_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Time_11B86278_E0EE_4020_A795_0BDE4C7CAB71) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_File_Player_Class_Initialize_4861C890_6AB5_407B_9715_A3322D8C36F7) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Stop, 8), be_const_ctype_func(Berry_File_Player_Class_Stop_0E4C7C2C_298E_4AEB_9B02_F7CD44E353D9) },
    { be_const_key(Loop, -1), be_const_ctype_func(Berry_File_Player_Class_Loop_84A09DC9_6E8C_4FAD_BD51_7F5CE19B44AE) },
    { be_const_key(Get_Time, 4), be_const_ctype_func(Berry_File_Player_Class_Get_Time_73DFFFB8_FEAD_4CB8_840E_437E9BA187CC) },
    { be_const_key(Get_Channels, 1), be_const_ctype_func(Berry_File_Player_Class_Get_Channels_B0C57F5C_C246_4050_ABF1_46A0CBF8CDC9) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Sample_Rate_65BC3472_5D2B_4C79_9AFB_04AAD104DBDF) },
    { be_const_key(deinit, 0), be_const_ctype_func(Berry_File_Player_Class_Deinitialize_637A9B07_92C9_4217_B9FB_92E3E690A937) },
    { be_const_key(Get_Bits_Per_Sample, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Bits_Per_Sample_60147131_9549_45C8_9C7D_FA77B5FE2B20) },
};

static be_define_const_map(
    Berry_File_Player_Type_map,
    14
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_File_Player_Type,
    1,
    NULL,
    File_Player_Type
);
