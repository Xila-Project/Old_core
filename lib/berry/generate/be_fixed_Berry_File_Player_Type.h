#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Player_Type_map) {
    { be_const_key(Set_Output_Stream, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Output_Stream_D0FB3FCD_23A3_4AFC_95EB_D23C502AD14C) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_File_Player_Class_Begin_34D3CA92_0692_43BA_8470_F90281D66FC8) },
    { be_const_key(Get_Total_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Total_Time_EF2D5C20_CD91_454F_A71D_B2C2F620ACAB) },
    { be_const_key(Set_Input_File, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Input_File_1003BD45_1D4C_47BB_9569_E805E356CB79) },
    { be_const_key(Set_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Time_3ABAA478_04F2_4EB5_99A3_82A359AF9ABD) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_File_Player_Class_Initialize_E12B4D7A_E5F9_41CC_954C_D2F82B960692) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Stop, 8), be_const_ctype_func(Berry_File_Player_Class_Stop_90405081_2A63_4CC8_9D20_C03A960D2DFE) },
    { be_const_key(Loop, -1), be_const_ctype_func(Berry_File_Player_Class_Loop_65C09BA5_1144_407B_8A43_F5280901FAAA) },
    { be_const_key(Get_Time, 4), be_const_ctype_func(Berry_File_Player_Class_Get_Time_CDA73A0C_939F_4190_A05B_14F5DEB528EF) },
    { be_const_key(Get_Channels, 1), be_const_ctype_func(Berry_File_Player_Class_Get_Channels_CFBE3AD8_C62E_4A94_AFD5_4BA1F9976ED2) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Sample_Rate_77E00649_971B_4B16_BE0D_D7D3E06C9982) },
    { be_const_key(deinit, 0), be_const_ctype_func(Berry_File_Player_Class_Deinitialize_F4D35024_C90B_4DF6_B2F0_05AE746417F2) },
    { be_const_key(Get_Bits_Per_Sample, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Bits_Per_Sample_8BE28B71_5C62_4EB7_98E7_874D28E8E424) },
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
