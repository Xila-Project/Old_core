#include "be_constobj.h"

static be_define_const_map_slots(Berry_HTTPS_Client_Type_map) {
    { be_const_key(Get_Location, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Location_672E218F_AF08_4436_BEBA_10704CC01300) },
    { be_const_key(Set_Connect_Timeout, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Connect_Timeout_0AD790CA_2850_456C_AA70_1872F229D312) },
    { be_const_key(Set_User_Agent, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_User_Agent_97F61736_27CF_474B_B246_376BE4721DFC) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Size_611BA0CB_1248_4B96_AB86_7AE75C3B79F5) },
    { be_const_key(Get_Header_Name, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Name_4B0A1466_F927_40A2_9307_FEBEFFF73A96) },
    { be_const_key(Get_String, 13), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_String_86F94119_DB58_4AEB_AE84_50882507B52A) },
    { be_const_key(Send_Request, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Send_Request_C0CA038F_6E4D_4DAC_A5C3_CD6FF8712E4C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Clear_All_Cookies, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Clear_All_Cookies_C7686B6C_2808_4066_806E_3DA4E2534F5B) },
    { be_const_key(Set_Authorization_Type, 12), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_Type_24403C24_043B_4CA7_B80F_2F9CB4F4DB89) },
    { be_const_key(Put, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Put_D301BD6B_009C_48BD_BB9C_F91F028E8BB5) },
    { be_const_key(Set_Follow_Redirects, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Follow_Redirects_3BA48072_3080_4156_953F_148250684C20) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Begin_F7F43604_84CF_4195_AD31_E8C0387A40A3) },
    { be_const_key(End, 30), be_const_ctype_func(Berry_HTTPS_Client_Class_End_B3C61388_F5EA_4729_B1B1_ECC653DF1D2B) },
    { be_const_key(Post, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Post_CDDB20B9_AC61_4583_B99D_6C242D9639E3) },
    { be_const_key(Set_URL, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_URL_027CE300_C143_4EF9_A078_1708CA9DC74E) },
    { be_const_key(Reset_Cookie_Jar, 24), be_const_ctype_func(Berry_HTTPS_Client_Class_Reset_Cookie_Jar_E5A3FDFC_1BD6_41AD_8102_986F2E2CC169) },
    { be_const_key(Has_Header, 18), be_const_ctype_func(Berry_HTTPS_Client_Class_Has_Header_A9B8D524_390E_44F8_8711_ABD6000356AA) },
    { be_const_key(Set_Redirect_Limit, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Redirect_Limit_855BEB75_60DF_4551_BDCD_A33474028C6B) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_C533B2E3_31DF_4D4F_B659_52E838DA1A65) },
    { be_const_key(deinit, 19), be_const_ctype_func(Berry_HTTPS_Client_Class_Deinitialize_08AC5E71_B7E1_4FE1_BB44_8275168B5FD8) },
    { be_const_key(Set_Timeout, 16), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Timeout_246B623F_ACD2_4E72_93E9_80BF9F288412) },
    { be_const_key(Set_Reuse, 26), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Reuse_69CAF116_B296_4465_B290_10FE0430D2CF) },
    { be_const_key(Add_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Add_Header_C43BBA6D_D2B7_4B0B_84B0_992AAAA7F502) },
    { be_const_key(Get_Header_Count, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Count_E437E903_2B2A_4C1F_BD06_3A204991B4BF) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_0DB20D71_7495_4DF1_81F5_0B23D31B1AC0) },
    { be_const_key(Use_HTTP_1_0, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Use_HTTP_1_0_AC3DB76F_EAF4_4F9B_A363_503E0FFDE5B2) },
    { be_const_key(Set_Authorization, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_FCC22B5D_6608_47A7_952B_800F471E1CA9) },
    { be_const_key(Connected, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Connected_BB52AB9E_0E27_4291_B488_089D9475D06F) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Initialize_A2917F4D_E23B_4054_B9CF_EE98C72C7D13) },
    { be_const_key(Patch, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Patch_6BA3FC37_9E3B_4043_84BB_A4F17555D62C) },
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
