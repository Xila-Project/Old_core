#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Player_Type_map) {
    { be_const_key(Set_Output_Stream, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Output_Stream_7AD92FDA_04D2_49BD_892C_64B24FC750AF) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_File_Player_Class_Begin_19DCEA82_DF73_413D_8D8B_08BD17BF28D7) },
    { be_const_key(Get_Total_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Total_Time_E91E387A_846A_46E7_AB65_BCAA70FDC783) },
    { be_const_key(Set_Input_File, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Input_File_D7EA3E72_F2F5_48E3_93D2_A1FF95CC349F) },
    { be_const_key(Set_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Time_05D0C7E2_91EC_4E59_A94B_C3AF66EA2D73) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_File_Player_Class_Initialize_85B26ED4_47A0_4EF7_8B5B_F663DC3096EF) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Stop, 8), be_const_ctype_func(Berry_File_Player_Class_Stop_3262A49E_065B_4718_95E0_58444C2F0E31) },
    { be_const_key(Loop, -1), be_const_ctype_func(Berry_File_Player_Class_Loop_92FE891A_2E4A_4F34_A544_9073553C248A) },
    { be_const_key(Get_Time, 4), be_const_ctype_func(Berry_File_Player_Class_Get_Time_51C3E39E_BE8C_4422_A928_9CB715C98782) },
    { be_const_key(Get_Channels, 1), be_const_ctype_func(Berry_File_Player_Class_Get_Channels_C03421B5_2DD3_450C_83F1_71E7F7E48FBE) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Sample_Rate_160AD64F_19B7_4FAE_959D_772A5EEA68AE) },
    { be_const_key(deinit, 0), be_const_ctype_func(Berry_File_Player_Class_Deinitialize_26AA8A0E_4925_47FF_92E2_4C82AF12E99A) },
    { be_const_key(Get_Bits_Per_Sample, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Bits_Per_Sample_4839DAEF_C727_4466_9195_D9C110D92733) },
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
