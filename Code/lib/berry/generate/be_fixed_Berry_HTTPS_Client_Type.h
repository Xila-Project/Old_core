#include "be_constobj.h"

static be_define_const_map_slots(Berry_HTTPS_Client_Type_map) {
    { be_const_key(Get_Location, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Location_ED4598B1_C70B_430A_8F0B_E29EF58BDE6E) },
    { be_const_key(Set_Connect_Timeout, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Connect_Timeout_5A234C48_8F93_43AD_98C6_4E8F75FFEB2E) },
    { be_const_key(Set_User_Agent, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_User_Agent_88CC6F58_3AEB_4F95_8E7C_FB689B33FB5A) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Size_9FEC396B_836A_426B_A633_D53B51CD9583) },
    { be_const_key(Get_Header_Name, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Name_8809A246_40CF_4BCB_8101_5AB111495DCB) },
    { be_const_key(Get_String, 13), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_String_786615EA_0A21_4AD3_AA2E_D74C9D52025E) },
    { be_const_key(Send_Request, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Send_Request_4FDBEDFE_BE3C_4105_BB3B_7CF73C7F7F46) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Clear_All_Cookies, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Clear_All_Cookies_7E5BA325_10C4_4730_838D_5FB541A92E22) },
    { be_const_key(Set_Authorization_Type, 12), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_Type_AA57CA3D_934F_4AE0_9E16_64490C88F271) },
    { be_const_key(Put, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Put_BB2C5CF7_B50C_4122_8D50_4EDFE9D33DF1) },
    { be_const_key(Set_Follow_Redirects, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Follow_Redirects_73293DE4_F8BF_4A27_8F0A_E42377EA1485) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Begin_9D536B85_50D7_4181_B8EB_954DC3D6A694) },
    { be_const_key(End, 30), be_const_ctype_func(Berry_HTTPS_Client_Class_End_78D06AD5_08F4_47D1_8D89_A569ABD60DE0) },
    { be_const_key(Post, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Post_58749148_1496_4830_A782_9F5AC2D6F52B) },
    { be_const_key(Set_URL, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_URL_89D6C2F7_5ABF_4067_803F_F42DDF652CF1) },
    { be_const_key(Reset_Cookie_Jar, 24), be_const_ctype_func(Berry_HTTPS_Client_Class_Reset_Cookie_Jar_E804EE70_C54D_4C4F_97AE_5597D5119F31) },
    { be_const_key(Has_Header, 18), be_const_ctype_func(Berry_HTTPS_Client_Class_Has_Header_ADDF9A42_6084_4909_908D_FEF6C6797463) },
    { be_const_key(Set_Redirect_Limit, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Redirect_Limit_7C8D1AE8_E0C0_4CFA_BF95_973F34C35DE7) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_888BDB45_BA53_4285_BAEF_827BE5159C64) },
    { be_const_key(deinit, 19), be_const_ctype_func(Berry_HTTPS_Client_Class_Deinitialize_8AD6C0BC_0CE6_4EC4_82BA_D6D9D3BC3BA4) },
    { be_const_key(Set_Timeout, 16), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Timeout_578119F9_AB04_4674_A456_C230151AC9E7) },
    { be_const_key(Set_Reuse, 26), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Reuse_F0BBE0FC_FA7F_4D4E_AB97_ACDB94543E32) },
    { be_const_key(Add_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Add_Header_FB64FA68_9E62_4D89_8C59_793C74A41120) },
    { be_const_key(Get_Header_Count, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Count_2BAA15B5_6E5F_47A7_9187_F645A77D1265) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_907A744D_06B2_4374_AFD6_133CF0959172) },
    { be_const_key(Use_HTTP_1_0, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Use_HTTP_1_0_92D72489_BA9F_485D_B25E_3F19CC40F46C) },
    { be_const_key(Set_Authorization, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_8B80703C_88D5_456E_9B5E_A182A183735D) },
    { be_const_key(Connected, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Connected_07B84DE2_DE89_4DC8_9FAA_5488A79E5E20) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Initialize_7D5C00CA_732C_4847_BBC1_38DE94C4CE6D) },
    { be_const_key(Patch, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Patch_41F55B77_A5CE_4911_9945_E3BCF37DE35B) },
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
