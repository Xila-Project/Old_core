#include "be_constobj.h"

static be_define_const_map_slots(Berry_HTTPS_Client_Type_map) {
    { be_const_key(Get_Location, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Location_9D5B5601_1981_4F4B_A8D7_B6E0719B09FE) },
    { be_const_key(Set_Connect_Timeout, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Connect_Timeout_7F41AFAF_33C3_43DD_8719_AF04249D5B46) },
    { be_const_key(Set_User_Agent, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_User_Agent_764967F5_D9EB_41EF_A7DC_6BC3BCD6CA13) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Size_85982BA2_8A05_4331_8D29_30958D5301EC) },
    { be_const_key(Get_Header_Name, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Name_D4C68A63_4C6D_450D_B006_26EDBF6FBF6E) },
    { be_const_key(Get_String, 13), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_String_D125BEC0_371F_4AD6_88F0_BE31EA5ABA19) },
    { be_const_key(Send_Request, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Send_Request_392F3205_CEE4_4EB7_8B83_55B089032560) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Clear_All_Cookies, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Clear_All_Cookies_D3D00C27_1C8C_4712_9192_4B5F645BF458) },
    { be_const_key(Set_Authorization_Type, 12), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_Type_A2CD3038_16B6_4D66_9676_8CBAEB9A2357) },
    { be_const_key(Put, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Put_B1619554_F655_44F5_8D60_6A062EB3AD2C) },
    { be_const_key(Set_Follow_Redirects, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Follow_Redirects_F263BC29_4F43_40B5_B585_937800E76B61) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Begin_CC44BAD5_3471_4264_85AA_8F61BFCE8F7D) },
    { be_const_key(End, 30), be_const_ctype_func(Berry_HTTPS_Client_Class_End_1B4D5967_AD17_4213_B356_67210F2C50DA) },
    { be_const_key(Post, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Post_2AA1684A_D770_4A62_B941_9D2306CFBD1C) },
    { be_const_key(Set_URL, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_URL_B20E60E2_BB53_45E5_BC70_247DE3835F9E) },
    { be_const_key(Reset_Cookie_Jar, 24), be_const_ctype_func(Berry_HTTPS_Client_Class_Reset_Cookie_Jar_C30F294E_BE00_4A52_B9AF_2BB7805EED30) },
    { be_const_key(Has_Header, 18), be_const_ctype_func(Berry_HTTPS_Client_Class_Has_Header_8E975445_6BFB_439F_BDE2_F48C36AE758F) },
    { be_const_key(Set_Redirect_Limit, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Redirect_Limit_585DED50_CE8E_4DCD_A67D_8450A8D69CE0) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_2362DC71_2E39_4C0A_8FDD_544583F2402F) },
    { be_const_key(deinit, 19), be_const_ctype_func(Berry_HTTPS_Client_Class_Deinitialize_6E435F30_A552_452D_8E52_CB36CFB76409) },
    { be_const_key(Set_Timeout, 16), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Timeout_7544CE25_94D9_494E_8C20_19AD879AD6AD) },
    { be_const_key(Set_Reuse, 26), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Reuse_C6756036_D29D_465D_85A8_11AD223B2DB0) },
    { be_const_key(Add_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Add_Header_E112F7D0_6D5C_4497_9FE7_A522E528AA20) },
    { be_const_key(Get_Header_Count, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Count_EB3F087D_DEF4_45C4_971C_E22B6E83CD41) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_6C557BE5_3E18_4F9C_9E94_FC745ADB26AD) },
    { be_const_key(Use_HTTP_1_0, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Use_HTTP_1_0_7D8079A9_DF95_45A9_9FC2_A48F77BCF94F) },
    { be_const_key(Set_Authorization, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_0795A3D6_9308_47B1_9616_F92DBE798D5E) },
    { be_const_key(Connected, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Connected_BA6B173D_87FE_440A_ABA7_85102AC18549) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Initialize_2A9A79B7_69F3_4ABD_8902_474699190521) },
    { be_const_key(Patch, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Patch_DFC1663F_711F_45CA_8323_110CA0C24160) },
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
