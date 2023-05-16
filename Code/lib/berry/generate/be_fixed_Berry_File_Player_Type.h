#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Player_Type_map) {
    { be_const_key(Set_Output_Stream, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Output_Stream_2199BF1B_16DB_4B03_AECA_7AE50FF1FB1A) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_File_Player_Class_Begin_D4B24CC9_B143_4E82_9A9C_61320900CEAD) },
    { be_const_key(Get_Total_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Total_Time_1479E3C1_DFDB_48F3_9AB1_5BAD599ED463) },
    { be_const_key(Set_Input_File, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Input_File_92570DB3_359A_4198_AF40_1FA6F7B790B0) },
    { be_const_key(Set_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Time_9DDFB0EE_A91E_49D0_A990_8A9B2704A968) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_File_Player_Class_Initialize_55783DCF_A43B_40B3_95FA_9521CCC8BAC4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Stop, 8), be_const_ctype_func(Berry_File_Player_Class_Stop_46B9B3EF_2C96_457F_93F4_B7019BC9B696) },
    { be_const_key(Loop, -1), be_const_ctype_func(Berry_File_Player_Class_Loop_2F2B0D38_040C_406B_A6E1_7AEEE01FBAAC) },
    { be_const_key(Get_Time, 4), be_const_ctype_func(Berry_File_Player_Class_Get_Time_0311F28A_8DF7_4025_B202_F58D6F289BBE) },
    { be_const_key(Get_Channels, 1), be_const_ctype_func(Berry_File_Player_Class_Get_Channels_D31CE908_7FDA_4156_A229_0E7A8F445DA4) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Sample_Rate_5C3AF5AA_8533_4757_BE4A_F950882617E9) },
    { be_const_key(deinit, 0), be_const_ctype_func(Berry_File_Player_Class_Deinitialize_9B80A354_438E_41A8_A656_725A4279BFF8) },
    { be_const_key(Get_Bits_Per_Sample, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Bits_Per_Sample_9785575B_0C8F_4BF4_8DA3_12CAEB7418AC) },
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
