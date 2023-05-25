#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Player_Type_map) {
    { be_const_key(Get_Channels, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Channels_42C8F904_4A24_41D2_A160_44C4DD6AB234) },
    { be_const_key(Get_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Time_F5B9F875_4F5B_4E9E_A429_B4922244FC45) },
    { be_const_key(Set_File, -1), be_const_ctype_func(Berry_File_Player_Class_Set_File_8D761254_2B42_446C_A7C7_35DC72E16F29) },
    { be_const_key(Set, 7), be_const_ctype_func(Berry_File_Player_Class_Set_514FB1DB_7F20_4BED_8F6C_35B9A98F0BC6) },
    { be_const_key(Set_Decoder, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Decoder_ADB60A64_48E2_4C3D_8DF4_DEAD72A10351) },
    { be_const_key(Get_Sample_Rate, 12), be_const_ctype_func(Berry_File_Player_Class_Get_Sample_Rate_357C0E59_144C_4DCC_B968_0E94A589FA16) },
    { be_const_key(Get_Total_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Total_Time_E9180AF5_76E8_4F22_9D88_95FFB455F6A8) },
    { be_const_key(Get_Bits_Per_Sample, 15), be_const_ctype_func(Berry_File_Player_Class_Get_Bits_Per_Sample_49EC2E4C_5425_4440_9AC0_A52C2F87CD18) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Player_Class_Deinitialize_D4E85013_9111_42BC_BD38_CDA7821702B2) },
    { be_const_key(Set_Output_Stream, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Output_Stream_90A3FDB8_2D18_4B44_BC5B_0B751988A997) },
    { be_const_key(_p, 9), be_const_var(0) },
    { be_const_key(Loop, -1), be_const_ctype_func(Berry_File_Player_Class_Loop_7D8B1AE8_5C44_4E2D_AF78_01DD3FB501B5) },
    { be_const_key(Set_Time, 13), be_const_ctype_func(Berry_File_Player_Class_Set_Time_22AE3861_F251_46A1_8CCE_39D1BADF7E30) },
    { be_const_key(Stop, -1), be_const_ctype_func(Berry_File_Player_Class_Stop_E0894DF4_5080_4BE9_B2CB_5DD3B26FB359) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_File_Player_Class_Begin_ABBD3C0C_9A43_4923_B1EA_73A8D25B8189) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Player_Class_Initialize_304BD892_F7A5_44D3_A780_EC4219A38BB0) },
};

static be_define_const_map(
    Berry_File_Player_Type_map,
    16
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_File_Player_Type,
    1,
    NULL,
    File_Player_Type
);
