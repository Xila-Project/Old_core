#include "be_constobj.h"

static be_define_const_map_slots(Berry_HTTPS_Client_Type_map) {
    { be_const_key(Get_Location, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Location_8F16E85E_EB6C_425A_9252_67780BB7B777) },
    { be_const_key(Set_Connect_Timeout, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Connect_Timeout_D6DF7350_4713_488D_B09C_16541F6F76CB) },
    { be_const_key(Set_User_Agent, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_User_Agent_9645DC79_6985_4301_9E10_4E2F5EAF11EC) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Size_AA999889_D1B1_4BBD_AAEA_E1761D67217D) },
    { be_const_key(Get_Header_Name, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Name_EEDE3900_404F_4066_BD70_B4BAD694C2DD) },
    { be_const_key(Get_String, 13), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_String_2C21F25D_A614_4D47_85B3_FD86384B4F09) },
    { be_const_key(Send_Request, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Send_Request_EF3AC591_F728_49D5_BAA7_5350E3A04050) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Clear_All_Cookies, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Clear_All_Cookies_8BE4812D_2583_44EC_BEAB_BD69374627E8) },
    { be_const_key(Set_Authorization_Type, 12), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_Type_1CB3109D_D96C_4C39_89A1_418D8A2B21FD) },
    { be_const_key(Put, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Put_784BDD0C_13A0_4B64_B86D_72B0010B78D8) },
    { be_const_key(Set_Follow_Redirects, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Follow_Redirects_B65F60F8_F9BF_4EED_9EEC_1B57C920DAD5) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Begin_FBC12BD1_4877_4E4D_8C96_E7AC50B5C0E4) },
    { be_const_key(End, 30), be_const_ctype_func(Berry_HTTPS_Client_Class_End_C243B52E_7A92_49BB_A8C2_94C5BB41F157) },
    { be_const_key(Post, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Post_C21F4EE4_9F54_4B0A_98A5_1970D104435D) },
    { be_const_key(Set_URL, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_URL_90649514_3B06_4064_B44E_88696D2F5F0D) },
    { be_const_key(Reset_Cookie_Jar, 24), be_const_ctype_func(Berry_HTTPS_Client_Class_Reset_Cookie_Jar_7F8842B5_90B1_4531_949A_E76C9A7C0E73) },
    { be_const_key(Has_Header, 18), be_const_ctype_func(Berry_HTTPS_Client_Class_Has_Header_842481CD_4934_4F5E_87B0_2819EC16F2F1) },
    { be_const_key(Set_Redirect_Limit, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Redirect_Limit_F43A313A_B7AF_4E93_AD68_3828D46625F3) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_3FE6C2E5_F5A7_429A_BFEE_0B30B6E6DB8E) },
    { be_const_key(deinit, 19), be_const_ctype_func(Berry_HTTPS_Client_Class_Deinitialize_603D6653_D569_4DEA_BF09_F486762594FE) },
    { be_const_key(Set_Timeout, 16), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Timeout_7E177292_6ED7_446A_A90C_D51DADBBE144) },
    { be_const_key(Set_Reuse, 26), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Reuse_8C2CF92C_1FC3_48FF_A2DF_B3C5CFE4E3B8) },
    { be_const_key(Add_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Add_Header_BE4E263C_ACD7_4FCC_B216_9032159D5201) },
    { be_const_key(Get_Header_Count, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Count_7B79304A_A385_4A12_84D2_0FBDE45A93FC) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_B48635F0_F657_41CA_A09A_20937FE25D10) },
    { be_const_key(Use_HTTP_1_0, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Use_HTTP_1_0_0B9ECDA0_9E83_4D29_B412_0009CE110C8B) },
    { be_const_key(Set_Authorization, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_AFC75F71_5683_4CC3_9BC9_52AB98DAF352) },
    { be_const_key(Connected, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Connected_6D142C12_32ED_4689_979A_3AA32EDD15F0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Initialize_B2E45545_3626_4D39_B342_BA4160B5E7D9) },
    { be_const_key(Patch, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Patch_885DFC6F_69CB_4FD5_99F7_34D5716FCE19) },
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
