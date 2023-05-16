#include "be_constobj.h"

static be_define_const_map_slots(Berry_HTTPS_Client_Type_map) {
    { be_const_key(Get_Location, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Location_80C0D80C_40B1_4815_BCEF_0A6527222D41) },
    { be_const_key(Set_Connect_Timeout, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Connect_Timeout_067328BE_67CB_4CDD_85C7_984FD0FA2745) },
    { be_const_key(Set_User_Agent, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_User_Agent_A10D1BD9_C7A9_4160_A7CA_C61912C72AC8) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Size_75056B5F_8552_4931_BDCF_ED046084B696) },
    { be_const_key(Get_Header_Name, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Name_75417AC0_F74B_424B_913D_C0FC93FD4A87) },
    { be_const_key(Get_String, 13), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_String_C284BD0B_C9E2_47EC_9091_56AA890A6DF8) },
    { be_const_key(Send_Request, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Send_Request_6E7EA970_DAC7_4858_83F5_68ED08893F3C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Clear_All_Cookies, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Clear_All_Cookies_A7D1A12C_4390_49F3_AD66_2BA531ECC0CB) },
    { be_const_key(Set_Authorization_Type, 12), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_Type_D485F75B_8ECE_4108_B26A_F75A7EB6FA07) },
    { be_const_key(Put, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Put_36D0B73D_DAC5_4D15_B41E_67F0A0E19E58) },
    { be_const_key(Set_Follow_Redirects, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Follow_Redirects_E9CC4DD5_DABB_423D_9B37_6E6D2A5E91CC) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Begin_47F049D3_445E_437D_8B65_20356B64C390) },
    { be_const_key(End, 30), be_const_ctype_func(Berry_HTTPS_Client_Class_End_0D6C2438_7DE1_4898_B1A0_04C2824028B0) },
    { be_const_key(Post, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Post_DC9F4337_91ED_4179_8B90_D75EC8C3E2F7) },
    { be_const_key(Set_URL, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_URL_18F497DD_3D53_4071_8EC9_DCD9D0582051) },
    { be_const_key(Reset_Cookie_Jar, 24), be_const_ctype_func(Berry_HTTPS_Client_Class_Reset_Cookie_Jar_C3A7EB8F_0971_48E6_BA87_BC58E066D646) },
    { be_const_key(Has_Header, 18), be_const_ctype_func(Berry_HTTPS_Client_Class_Has_Header_FF03B368_E906_4470_ACDE_19E5650042EE) },
    { be_const_key(Set_Redirect_Limit, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Redirect_Limit_0F5912D9_1C0C_4EEB_BDD0_14F57CF39324) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_30E7B2B0_57BA_4743_800F_F517DE2B9D19) },
    { be_const_key(deinit, 19), be_const_ctype_func(Berry_HTTPS_Client_Class_Deinitialize_4E348E02_384C_426D_873F_584547EC6B47) },
    { be_const_key(Set_Timeout, 16), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Timeout_0F7BABCB_87B2_4070_B7E4_A46B704030AA) },
    { be_const_key(Set_Reuse, 26), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Reuse_17A3BE12_0E02_4155_8C36_41E20899F2B3) },
    { be_const_key(Add_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Add_Header_66A436FD_56FF_4E1E_AF61_46DAC05586C8) },
    { be_const_key(Get_Header_Count, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Count_74B64026_7E9D_46D4_9C52_C202A5CC3272) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_0922D375_6F92_4A9C_8FA1_44ACE081C1A0) },
    { be_const_key(Use_HTTP_1_0, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Use_HTTP_1_0_2F40A241_10B3_4F14_9AFE_873CB4A9721F) },
    { be_const_key(Set_Authorization, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_4FCC727F_EEF7_4539_9966_E626EBEB58AE) },
    { be_const_key(Connected, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Connected_398A7987_9517_48C3_A3B4_13662FBEEEA6) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Initialize_483F7F81_2E6C_4DB2_AE60_8EEDD41C981E) },
    { be_const_key(Patch, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Patch_1C4687A7_55FA_4044_98A6_67759656CD84) },
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
