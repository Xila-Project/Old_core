#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Player_Type_map) {
    { be_const_key(Set_Output_Stream, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Output_Stream_5496CCA8_813E_41A5_9A3F_DB51D716D529) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_File_Player_Class_Begin_25A6A5EA_FD2D_4735_9901_83E63193D4EA) },
    { be_const_key(Get_Total_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Total_Time_C4AA90E6_C61B_4B87_B337_6DB266FC564C) },
    { be_const_key(Set_Input_File, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Input_File_39DFFF28_7C46_4A78_8247_E35C22038670) },
    { be_const_key(Set_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Time_189B9A0A_DF81_489A_90CB_083761A82F23) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_File_Player_Class_Initialize_DEF2EED3_FF54_4FB0_B51D_FE2EC0576C56) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Stop, 8), be_const_ctype_func(Berry_File_Player_Class_Stop_0C03F51C_341B_4F51_94FE_08111AD7CE28) },
    { be_const_key(Loop, -1), be_const_ctype_func(Berry_File_Player_Class_Loop_B09AFCFE_6012_41EF_9F5C_35E7A7901423) },
    { be_const_key(Get_Time, 4), be_const_ctype_func(Berry_File_Player_Class_Get_Time_86B0F07D_E445_488E_AACF_97F36E94151E) },
    { be_const_key(Get_Channels, 1), be_const_ctype_func(Berry_File_Player_Class_Get_Channels_B35A72DF_97FD_4600_99FA_B89E644CC993) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Sample_Rate_ABDD748F_7C38_46FF_9676_E588DB1FBEC5) },
    { be_const_key(deinit, 0), be_const_ctype_func(Berry_File_Player_Class_Deinitialize_A14EC689_4173_482C_B1FA_61CBAC48C332) },
    { be_const_key(Get_Bits_Per_Sample, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Bits_Per_Sample_48D20760_0D2A_468B_BA69_A715A8C21A4A) },
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
