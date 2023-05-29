#include "be_constobj.h"

static be_define_const_map_slots(Berry_HTTPS_Client_Type_map) {
    { be_const_key(Get_Location, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Location_4DB6D04F_13F7_4356_A556_0C0908A5EA4A) },
    { be_const_key(Set_Connect_Timeout, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Connect_Timeout_D426648B_51BE_4368_B4BE_FE2BBFBF6661) },
    { be_const_key(Set_User_Agent, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_User_Agent_F4CA001B_03A4_4094_BF30_0A3A3C5EC313) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Size_BFED2116_3522_4912_AC93_54FE9FE9516D) },
    { be_const_key(Get_Header_Name, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Name_6780D537_66C3_47AC_8794_2C6227EE2337) },
    { be_const_key(Get_String, 13), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_String_CE04D31B_3026_4CDB_9FD6_A4EB9C078608) },
    { be_const_key(Send_Request, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Send_Request_6FFE7B03_942F_4334_924E_1A6C3C7E955F) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Clear_All_Cookies, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Clear_All_Cookies_CB9859F0_B98A_48A3_8C03_5B6E175692FD) },
    { be_const_key(Set_Authorization_Type, 12), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_Type_9E63EA17_BA34_4B65_AF8E_70D4A2E0B6B2) },
    { be_const_key(Put, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Put_28418085_22CB_4B21_8617_BE69849C7777) },
    { be_const_key(Set_Follow_Redirects, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Follow_Redirects_83E9A196_BCCC_4C44_8E97_7B599E8C6BC5) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Begin_C422BA5E_41B0_47AB_8D84_C4F94A64C519) },
    { be_const_key(End, 30), be_const_ctype_func(Berry_HTTPS_Client_Class_End_CA0E7D9C_54CE_4F11_A54C_0D157FE1C322) },
    { be_const_key(Post, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Post_245992EB_6A82_463B_B946_C0125D87454E) },
    { be_const_key(Set_URL, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_URL_A73E1D55_5A5B_48A7_8FE4_343A52AC73B3) },
    { be_const_key(Reset_Cookie_Jar, 24), be_const_ctype_func(Berry_HTTPS_Client_Class_Reset_Cookie_Jar_77B3963F_9420_48D4_A574_BA787CC8F196) },
    { be_const_key(Has_Header, 18), be_const_ctype_func(Berry_HTTPS_Client_Class_Has_Header_0FD1FCD8_D0A0_4F7C_8EE7_B98B0B88CB31) },
    { be_const_key(Set_Redirect_Limit, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Redirect_Limit_F6099C75_6B63_4F24_9E51_0A16A9A2F3A8) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_BD4B909F_E493_4257_98C8_A26F64BACB3A) },
    { be_const_key(deinit, 19), be_const_ctype_func(Berry_HTTPS_Client_Class_Deinitialize_DCE5106F_0AE8_42B4_9DC4_233882775104) },
    { be_const_key(Set_Timeout, 16), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Timeout_10596B1C_3FB3_4AB9_AE40_37E4EC6C5856) },
    { be_const_key(Set_Reuse, 26), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Reuse_3FB02C49_B4FC_475A_9F9A_36A22C47CBB2) },
    { be_const_key(Add_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Add_Header_CC1F49C9_9F97_463A_ACE8_B0F7E68410DB) },
    { be_const_key(Get_Header_Count, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Count_F2B6EAE9_3CD8_4D8D_950F_D23D4A5566D6) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_BF4DCF49_5053_495C_B5FC_790D83442AF3) },
    { be_const_key(Use_HTTP_1_0, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Use_HTTP_1_0_873DEEFA_25B5_4098_AC06_F6512297C0D2) },
    { be_const_key(Set_Authorization, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_64D2C99B_2B1C_4681_B945_90DC3810CC11) },
    { be_const_key(Connected, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Connected_79758474_B527_413D_A8EC_A34E7AC594BA) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Initialize_2807E391_786E_4348_820E_305B19910D66) },
    { be_const_key(Patch, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Patch_FC6F3E12_0DED_4605_8044_169B09314868) },
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
