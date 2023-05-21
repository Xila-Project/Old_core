#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Player_Type_map) {
    { be_const_key(Set_Output_Stream, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Output_Stream_C1E4FF4F_B824_443D_BFEE_AA34F6DFCD49) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_File_Player_Class_Begin_11CA83DE_D61B_4B79_B954_B3D8139A9CC0) },
    { be_const_key(Get_Total_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Total_Time_C9FAA84E_CEEA_408D_B5BF_1F761C7C447C) },
    { be_const_key(Set_Input_File, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Input_File_01FF4F65_B1A8_44DB_8305_B91720AFB9A7) },
    { be_const_key(Set_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Time_49FA698B_9967_4049_AB07_65CAC86F46D1) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_File_Player_Class_Initialize_7D8A0F95_A169_4ACA_9CF6_FCE35759B7BC) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Stop, 8), be_const_ctype_func(Berry_File_Player_Class_Stop_7AAF11E7_27CD_4C9A_BE07_C8C0AA004897) },
    { be_const_key(Loop, -1), be_const_ctype_func(Berry_File_Player_Class_Loop_2BF7DB12_7180_448B_AD9D_9E0BD32BCC5C) },
    { be_const_key(Get_Time, 4), be_const_ctype_func(Berry_File_Player_Class_Get_Time_3AE80B29_4A50_4206_AEBF_FD6D20EB0B1E) },
    { be_const_key(Get_Channels, 1), be_const_ctype_func(Berry_File_Player_Class_Get_Channels_960FC879_3543_42BA_B039_90179B8A7E31) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Sample_Rate_D74D65CE_CF5C_4F31_9D61_D7712ADCA932) },
    { be_const_key(deinit, 0), be_const_ctype_func(Berry_File_Player_Class_Deinitialize_DF37C48C_06DA_4024_AD57_4ACADC803032) },
    { be_const_key(Get_Bits_Per_Sample, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Bits_Per_Sample_8BBD43E4_1148_4DAC_A25E_2733E8CAB85A) },
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
