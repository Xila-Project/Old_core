#include "be_constobj.h"

static be_define_const_map_slots(Berry_HTTPS_Client_Type_map) {
    { be_const_key(Get_Location, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Location_4D4FCF77_BCE9_41DB_BF5F_2B5E153C8878) },
    { be_const_key(Set_Connect_Timeout, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Connect_Timeout_7F15A567_F6AA_4125_BB0B_4FCBF0A53599) },
    { be_const_key(Set_User_Agent, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_User_Agent_105520DD_5C89_4061_B395_2A90A7616D88) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Size_C927F839_FA7B_4E50_9FCC_0CE1588707AE) },
    { be_const_key(Get_Header_Name, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Name_AA139DBA_18FE_4C35_BD49_44800A7E9C4C) },
    { be_const_key(Get_String, 13), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_String_92BE6EED_03C9_4B88_99BC_9A9AD78680BE) },
    { be_const_key(Send_Request, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Send_Request_37ED36A4_1DDD_459F_A64C_19102FE68C72) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Clear_All_Cookies, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Clear_All_Cookies_622535C7_EBD6_4212_9C42_A415061C19BA) },
    { be_const_key(Set_Authorization_Type, 12), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_Type_577F2BF7_44AA_44BC_8738_7DE83D2B24C7) },
    { be_const_key(Put, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Put_8FA50E0F_18C7_44E9_B020_97F4BCD0822B) },
    { be_const_key(Set_Follow_Redirects, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Follow_Redirects_2360DF65_914C_4A7E_9A97_B778ADCC9851) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Begin_F55AF10A_CB2A_4948_A50B_2C9C34863CEA) },
    { be_const_key(End, 30), be_const_ctype_func(Berry_HTTPS_Client_Class_End_358C1692_F919_4932_80A2_0DB75619DA05) },
    { be_const_key(Post, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Post_A2D60E06_F985_47AB_B6C4_0BC719EAF513) },
    { be_const_key(Set_URL, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_URL_29652BCC_1AFD_42FB_BDA1_7EEC26F8340A) },
    { be_const_key(Reset_Cookie_Jar, 24), be_const_ctype_func(Berry_HTTPS_Client_Class_Reset_Cookie_Jar_D057F1FA_0781_46CB_A9C2_AD9533C6D5DB) },
    { be_const_key(Has_Header, 18), be_const_ctype_func(Berry_HTTPS_Client_Class_Has_Header_32B34630_CC63_4425_90AD_F473213380BB) },
    { be_const_key(Set_Redirect_Limit, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Redirect_Limit_A83637BD_8850_4265_94E1_CA5C3F8AEA60) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_5C9C4CD7_8632_4B24_8246_8ECCFE6A8A1A) },
    { be_const_key(deinit, 19), be_const_ctype_func(Berry_HTTPS_Client_Class_Deinitialize_7E73C782_297C_422A_8080_8D69EBB123AF) },
    { be_const_key(Set_Timeout, 16), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Timeout_37A0A7A3_3756_488E_9564_7BB9E577FAF7) },
    { be_const_key(Set_Reuse, 26), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Reuse_2E6A61C0_6952_4D15_9A7D_74678C488C47) },
    { be_const_key(Add_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Add_Header_94FF66C9_1D67_4616_8EAA_A1F56FC09505) },
    { be_const_key(Get_Header_Count, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Count_118FB327_AFF1_4006_BDFE_432A61E20E71) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_11CB90F7_2E5E_451B_918B_1F03CCE323F6) },
    { be_const_key(Use_HTTP_1_0, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Use_HTTP_1_0_47FB4CA5_D105_4CE2_BA1A_A66F28789F35) },
    { be_const_key(Set_Authorization, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_F2BDF5AA_628C_4BE1_8702_CE1DF5974C10) },
    { be_const_key(Connected, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Connected_4DA2CF39_F5B8_4AC9_81FE_FA261E79B291) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Initialize_062BB6E0_03DE_484A_9788_F60C31A719E4) },
    { be_const_key(Patch, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Patch_304E5D44_BA97_4E5C_B7F0_22DE2C6618A3) },
};

static be_define_const_map(
    Berry_HTTPS_Client_Type_map,
    31
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_HTTPS_Client_Type,
    1,
    NULL,
    HTTPS_Client_Type
);
