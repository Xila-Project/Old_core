#include "be_constobj.h"

static be_define_const_map_slots(Berry_HTTPS_Client_Type_map) {
    { be_const_key(Get_Location, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Location_76DC0A6F_F89A_45AA_95B9_8C1104522A7E) },
    { be_const_key(Set_Connect_Timeout, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Connect_Timeout_E221A87F_CFAA_4F27_9908_D1246C090073) },
    { be_const_key(Set_User_Agent, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_User_Agent_727E3200_95A2_4960_88C1_269F6F9C0D8B) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Size_145933E7_9EEA_4979_A594_0B40A571BC2A) },
    { be_const_key(Get_Header_Name, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Name_2BA64C9D_8BDF_4C72_A6E3_F9914C3F94D1) },
    { be_const_key(Get_String, 13), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_String_EDA66AEE_BCD8_4E39_8AEE_4FEC2AC74DE6) },
    { be_const_key(Send_Request, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Send_Request_B5BAC284_1310_4E64_9EE0_4AC84FABC11E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Clear_All_Cookies, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Clear_All_Cookies_7737B392_BC21_44A0_A854_59D46A27DA94) },
    { be_const_key(Set_Authorization_Type, 12), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_Type_DF205A63_F91F_4A4B_A183_2B64A3428F8C) },
    { be_const_key(Put, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Put_6BE9BF6D_A4D9_4B7B_9112_3C3AA299F7AF) },
    { be_const_key(Set_Follow_Redirects, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Follow_Redirects_57525973_AB01_4FA4_A213_6F8B872AB00D) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Begin_24D81BEF_D001_4132_9C16_DA16322C4B46) },
    { be_const_key(End, 30), be_const_ctype_func(Berry_HTTPS_Client_Class_End_E795D048_DD34_49D6_990E_E52458C07C37) },
    { be_const_key(Post, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Post_8AEA7B5C_3577_4955_8D9F_BCDA7BEC4CD2) },
    { be_const_key(Set_URL, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_URL_C1B4ED7D_6979_46FD_9B21_01319592F7A8) },
    { be_const_key(Reset_Cookie_Jar, 24), be_const_ctype_func(Berry_HTTPS_Client_Class_Reset_Cookie_Jar_D3C260DD_F7AB_4288_BEFC_CBBBF9135826) },
    { be_const_key(Has_Header, 18), be_const_ctype_func(Berry_HTTPS_Client_Class_Has_Header_7821563D_CDDE_4772_80CB_655561271A76) },
    { be_const_key(Set_Redirect_Limit, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Redirect_Limit_1191F569_2E0F_4483_8CE6_611DAA36BD81) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_4BCBB295_C079_4688_9AA1_EEBD1E862ECC) },
    { be_const_key(deinit, 19), be_const_ctype_func(Berry_HTTPS_Client_Class_Deinitialize_B7E51CA3_5F8A_4D86_9851_152BFF1C64BF) },
    { be_const_key(Set_Timeout, 16), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Timeout_0A5285B6_C696_488E_872D_B16CA3307F9D) },
    { be_const_key(Set_Reuse, 26), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Reuse_5BD200B8_3896_45FB_8E92_B8DF5EE0E8FF) },
    { be_const_key(Add_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Add_Header_2AD61F90_8051_423A_AC56_49E566C05E21) },
    { be_const_key(Get_Header_Count, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Count_73A9962F_7FFA_43C4_BCB0_3092311A6D09) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_593408F5_7F49_46DB_821C_F3970DD8B69C) },
    { be_const_key(Use_HTTP_1_0, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Use_HTTP_1_0_5CCF85DC_80FF_454A_98CD_3FA172DD5317) },
    { be_const_key(Set_Authorization, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_5FC9EEEF_4F55_403B_9782_3B698572D4C9) },
    { be_const_key(Connected, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Connected_8B4045C4_F14E_4618_8A8A_2ECDAB5A34AC) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Initialize_5F333572_7284_4B3C_B0F7_A317E971C8E2) },
    { be_const_key(Patch, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Patch_F0BCAFB1_1BEA_4BEB_8E55_50B99FB73C90) },
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
