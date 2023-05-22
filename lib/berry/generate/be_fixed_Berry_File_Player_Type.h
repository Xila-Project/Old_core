#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Player_Type_map) {
    { be_const_key(Set_Output_Stream, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Output_Stream_0E7D3C1D_866C_4A70_BC11_3C27C9019763) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_File_Player_Class_Begin_FABA5086_227C_4CC9_B9F9_D95E96D2C509) },
    { be_const_key(Get_Total_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Total_Time_F781273E_2414_496A_857C_18AAB85B1F37) },
    { be_const_key(Set_Input_File, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Input_File_695B2019_92D3_41D0_BC35_BC8A04F3E915) },
    { be_const_key(Set_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Time_C4C58EBC_CD83_44C2_8177_0A7B70BCE2DF) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_File_Player_Class_Initialize_5F36FF8E_7AAF_4AF3_B8BF_97B68F75F2BA) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Stop, 8), be_const_ctype_func(Berry_File_Player_Class_Stop_0B9FADD0_345A_43C4_A6D7_866A7EA87BE0) },
    { be_const_key(Loop, -1), be_const_ctype_func(Berry_File_Player_Class_Loop_5ED5249C_4C8C_45E6_942F_B8455B30A9CF) },
    { be_const_key(Get_Time, 4), be_const_ctype_func(Berry_File_Player_Class_Get_Time_C23732F0_85CD_45B4_8D89_B1911C30EDDD) },
    { be_const_key(Get_Channels, 1), be_const_ctype_func(Berry_File_Player_Class_Get_Channels_7ADB33EE_2725_4979_A398_BD78D4E83191) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Sample_Rate_9399DB12_2148_42F5_A1C4_6DA4BFFCDBE3) },
    { be_const_key(deinit, 0), be_const_ctype_func(Berry_File_Player_Class_Deinitialize_61582872_106C_4A59_B978_3AAFA9092ACF) },
    { be_const_key(Get_Bits_Per_Sample, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Bits_Per_Sample_05531832_8FC2_402D_B3D2_A9D5153D7384) },
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
