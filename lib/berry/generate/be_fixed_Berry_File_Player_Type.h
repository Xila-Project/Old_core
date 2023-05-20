#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Player_Type_map) {
    { be_const_key(Set_Output_Stream, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Output_Stream_BAF7FF3F_A056_4370_AC70_5BA3E9E2D616) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_File_Player_Class_Begin_DB39E2EA_C12F_48FC_BD74_AB137BAE66CB) },
    { be_const_key(Get_Total_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Total_Time_72655659_8DD5_46FD_9D44_BC60CB02268A) },
    { be_const_key(Set_Input_File, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Input_File_5D567CBE_D3FA_46C1_8B8A_DAEEB05550D4) },
    { be_const_key(Set_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Time_244EF35F_5E3A_4570_8EAA_11D030F1CD28) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_File_Player_Class_Initialize_CF874F1E_95F3_4063_8BE1_22ADFF38051A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Stop, 8), be_const_ctype_func(Berry_File_Player_Class_Stop_E7389043_BB60_43EF_9286_73EE987F086F) },
    { be_const_key(Loop, -1), be_const_ctype_func(Berry_File_Player_Class_Loop_C3D76363_22C1_4157_A43B_DE1A3AB9CDF6) },
    { be_const_key(Get_Time, 4), be_const_ctype_func(Berry_File_Player_Class_Get_Time_AF45B34B_8147_4D20_9DB6_0B2CD24C7981) },
    { be_const_key(Get_Channels, 1), be_const_ctype_func(Berry_File_Player_Class_Get_Channels_C82CF247_7024_492C_AA72_ACC948D950CA) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Sample_Rate_22734376_2FAA_4668_8836_8B151BA9D4C4) },
    { be_const_key(deinit, 0), be_const_ctype_func(Berry_File_Player_Class_Deinitialize_BA9214A9_45A1_4F59_8FFE_6E82055E8163) },
    { be_const_key(Get_Bits_Per_Sample, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Bits_Per_Sample_F90E72DB_E0F2_4329_8380_6248714262CE) },
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
