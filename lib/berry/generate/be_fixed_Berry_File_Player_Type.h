#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Player_Type_map) {
    { be_const_key(Get_Channels, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Channels_80F72F3A_21EF_4A6B_BED5_BFBE1177170E) },
    { be_const_key(Get_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Time_15312877_C43F_45C4_8507_AA6F57D8F462) },
    { be_const_key(Set_File, -1), be_const_ctype_func(Berry_File_Player_Class_Set_File_915C8DD5_9C03_4C6F_9302_9083DAD4E462) },
    { be_const_key(Set, 7), be_const_ctype_func(Berry_File_Player_Class_Set_B2D42D80_16CA_48B1_9D2A_5503ADE8B601) },
    { be_const_key(Set_Decoder, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Decoder_85BD9BE9_EB2A_4EEC_A0EE_99B7355FAA7B) },
    { be_const_key(Get_Sample_Rate, 12), be_const_ctype_func(Berry_File_Player_Class_Get_Sample_Rate_23FFAE27_4036_47B7_A9DB_4CA94EE3656B) },
    { be_const_key(Get_Total_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Total_Time_28205C47_DBFD_40E2_84BA_B0093561FE96) },
    { be_const_key(Get_Bits_Per_Sample, 15), be_const_ctype_func(Berry_File_Player_Class_Get_Bits_Per_Sample_A3D6517E_B4C5_4A31_BEA1_AA9D82FE1B09) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_File_Player_Class_Deinitialize_217EB1C7_2B25_485D_A041_7DE0C9076D7D) },
    { be_const_key(Set_Output_Stream, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Output_Stream_4347A035_3329_44F1_B12E_DEC3C95913AB) },
    { be_const_key(_p, 9), be_const_var(0) },
    { be_const_key(Loop, -1), be_const_ctype_func(Berry_File_Player_Class_Loop_564EC2B1_DB10_4BCD_BE2F_7980A23F687B) },
    { be_const_key(Set_Time, 13), be_const_ctype_func(Berry_File_Player_Class_Set_Time_78FC61D7_0F3F_46FE_8E1C_D3FD673DB721) },
    { be_const_key(Stop, -1), be_const_ctype_func(Berry_File_Player_Class_Stop_B28AAA6B_B5F7_437B_87B7_D97FF67FB1D3) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_File_Player_Class_Begin_EBB3BEB8_CE9F_4A4E_8719_865351A722C3) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_File_Player_Class_Initialize_D767EE00_609C_41A9_98F4_94A51059F07F) },
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
