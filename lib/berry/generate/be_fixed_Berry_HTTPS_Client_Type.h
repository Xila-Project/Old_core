#include "be_constobj.h"

static be_define_const_map_slots(Berry_HTTPS_Client_Type_map) {
    { be_const_key(Get_Location, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Location_B2EDAA47_DC84_4086_9B28_C80CCE6E4F5F) },
    { be_const_key(Set_Connect_Timeout, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Connect_Timeout_DA1863DA_9013_4352_9182_742392D07D8B) },
    { be_const_key(Set_User_Agent, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_User_Agent_301DB233_CD81_485F_A914_DB7CEE061C2E) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Size_84DD8A84_843F_4AC4_920C_67630CBC8CF9) },
    { be_const_key(Get_Header_Name, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Name_C9C5D16B_B4B5_44E9_8A99_1AD6B360CC98) },
    { be_const_key(Get_String, 13), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_String_4E123DA7_27AA_45E5_9C7D_9674C6616BB2) },
    { be_const_key(Send_Request, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Send_Request_9FD372F5_3110_4E6E_B7E7_7704B7DA9312) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Clear_All_Cookies, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Clear_All_Cookies_2C36CB46_33FA_41B4_8805_AF7E4894B234) },
    { be_const_key(Set_Authorization_Type, 12), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_Type_34CC6285_F80A_44FA_806B_E577BA9AD9F2) },
    { be_const_key(Put, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Put_3D0BE061_1A56_4DF2_8D2C_3ECAF89D64F8) },
    { be_const_key(Set_Follow_Redirects, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Follow_Redirects_995C404E_0AF6_422E_8B4E_FB0168500A30) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Begin_0EECEF3E_6F28_4D4B_B4B5_52635037CBA2) },
    { be_const_key(End, 30), be_const_ctype_func(Berry_HTTPS_Client_Class_End_644447A4_0AB4_4AF4_A7E4_E4D5BCFCD56F) },
    { be_const_key(Post, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Post_3D6EFD8B_87DA_43F9_8ED6_8427996D4214) },
    { be_const_key(Set_URL, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_URL_BF492864_25B8_4261_8A40_0DE01590B8A2) },
    { be_const_key(Reset_Cookie_Jar, 24), be_const_ctype_func(Berry_HTTPS_Client_Class_Reset_Cookie_Jar_58DDA4E7_332C_4E14_B722_B8AFD04408E6) },
    { be_const_key(Has_Header, 18), be_const_ctype_func(Berry_HTTPS_Client_Class_Has_Header_86614E31_CA3C_459F_AD5F_57BE08E21B70) },
    { be_const_key(Set_Redirect_Limit, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Redirect_Limit_617BE2FB_DB38_40C3_AC1D_EB23D4E28F12) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_5BA8C9B4_D493_45AF_9A3D_88F89D64C93F) },
    { be_const_key(deinit, 19), be_const_ctype_func(Berry_HTTPS_Client_Class_Deinitialize_C245DB14_8AC9_4BA5_9D6B_75264A30BE6D) },
    { be_const_key(Set_Timeout, 16), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Timeout_3E68AD37_A3DA_4A6D_A0F0_C842ED07EC79) },
    { be_const_key(Set_Reuse, 26), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Reuse_2F9F02F0_FF1F_4210_92AB_560D1A2504CB) },
    { be_const_key(Add_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Add_Header_4F1CB87C_4523_4AE5_AF33_B9484E4044EF) },
    { be_const_key(Get_Header_Count, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Count_13396EC8_C500_4216_8427_0DC2F83640AB) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_0831E1EC_AB5C_43BD_B097_D8389DC0F35E) },
    { be_const_key(Use_HTTP_1_0, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Use_HTTP_1_0_10EFFE5C_9526_4312_8CA4_3B8E8DB70448) },
    { be_const_key(Set_Authorization, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_58F0A742_FCCF_4F78_BA89_0F98DC85998C) },
    { be_const_key(Connected, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Connected_9E1BE28F_0E5F_4115_9BF5_CB7C88CC430A) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Initialize_AACD75FF_C3DB_46F9_8712_8237D9AEEBBA) },
    { be_const_key(Patch, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Patch_8F046CC4_8FAD_4129_B345_74EC09C80C65) },
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
