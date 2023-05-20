#include "be_constobj.h"

static be_define_const_map_slots(Berry_File_Player_Type_map) {
    { be_const_key(Set_Output_Stream, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Output_Stream_99498FC8_CBFB_428F_A62D_B93494E0C3B2) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_File_Player_Class_Begin_1F9CED9C_80DB_46BB_9ACD_9A3FE93AB3B3) },
    { be_const_key(Get_Total_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Total_Time_1D326684_D06B_49DA_8983_4AFE613EEE87) },
    { be_const_key(Set_Input_File, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Input_File_671ECB10_975E_42D2_BD1B_28EF3A88FD87) },
    { be_const_key(Set_Time, -1), be_const_ctype_func(Berry_File_Player_Class_Set_Time_D5CB3D48_48DC_4DBF_9A28_6C3ABAE5973B) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_File_Player_Class_Initialize_4FFCC9B9_4713_48B6_9884_3C76DDD22C5E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Stop, 8), be_const_ctype_func(Berry_File_Player_Class_Stop_5C5A1422_74DA_4167_A741_3EB9FA551745) },
    { be_const_key(Loop, -1), be_const_ctype_func(Berry_File_Player_Class_Loop_6E3FFCD3_8A42_4410_B4B8_CE4767067A21) },
    { be_const_key(Get_Time, 4), be_const_ctype_func(Berry_File_Player_Class_Get_Time_E34B59BD_7D2A_495F_8024_45936D13039B) },
    { be_const_key(Get_Channels, 1), be_const_ctype_func(Berry_File_Player_Class_Get_Channels_E3273ADB_E706_49A1_AC7A_F0F45D5B3F2F) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Sample_Rate_AD31B1B4_FB79_4C5B_A274_7EED2A0413BA) },
    { be_const_key(deinit, 0), be_const_ctype_func(Berry_File_Player_Class_Deinitialize_2A15A742_B142_46DB_AEC4_FAD8A24DFEA2) },
    { be_const_key(Get_Bits_Per_Sample, -1), be_const_ctype_func(Berry_File_Player_Class_Get_Bits_Per_Sample_F6F6F8F3_0810_4E6E_8731_3F5F3802D035) },
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
