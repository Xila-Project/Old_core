#include "be_constobj.h"

static be_define_const_map_slots(Berry_HTTPS_Client_Type_map) {
    { be_const_key(Get_Location, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Location_50C1B44E_6A57_4AD5_9394_357AD8C0FA70) },
    { be_const_key(Set_Connect_Timeout, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Connect_Timeout_5E0B873A_72C5_4609_9B0A_8B54F08F0FEE) },
    { be_const_key(Set_User_Agent, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_User_Agent_302ABE05_6FF6_4F19_B609_72D4DBEF4F1A) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Size_83633558_12C4_48B2_A22F_42015EFB31ED) },
    { be_const_key(Get_Header_Name, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Name_808E3BB9_E63C_471A_B98D_1AEE366980E2) },
    { be_const_key(Get_String, 13), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_String_9CFC19E6_7633_49F2_A129_0EF7A9BE76E0) },
    { be_const_key(Send_Request, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Send_Request_D83E691E_73D1_4A4B_AF26_57610B0233A8) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Clear_All_Cookies, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Clear_All_Cookies_28C886AB_D0B5_4AA3_BB9C_C37847875E37) },
    { be_const_key(Set_Authorization_Type, 12), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_Type_8FE17A70_5558_47D7_B949_A8AD25343D3B) },
    { be_const_key(Put, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Put_B18C5D45_984C_4A22_B079_2C6A7A0CF3DE) },
    { be_const_key(Set_Follow_Redirects, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Follow_Redirects_FFCE3E36_9209_433E_9A63_09A3AC99733C) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Begin_60DE9498_38B0_458E_8943_58B53857D047) },
    { be_const_key(End, 30), be_const_ctype_func(Berry_HTTPS_Client_Class_End_28798F66_C3A5_47A5_B59C_E633F55162ED) },
    { be_const_key(Post, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Post_19384BC3_8D0A_4362_8F34_A3F1C186A4BC) },
    { be_const_key(Set_URL, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_URL_E04F34F5_FDDA_4816_A67C_DFC1FBD4DED3) },
    { be_const_key(Reset_Cookie_Jar, 24), be_const_ctype_func(Berry_HTTPS_Client_Class_Reset_Cookie_Jar_60430A77_3B15_4A9D_93B5_16B82323A581) },
    { be_const_key(Has_Header, 18), be_const_ctype_func(Berry_HTTPS_Client_Class_Has_Header_69E005BF_74C7_4BB9_97CE_16AF9838DE74) },
    { be_const_key(Set_Redirect_Limit, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Redirect_Limit_129E2F25_41BB_498C_9AD8_1DE5D6FADD9E) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_49D15286_B551_4537_8EA2_DF814BDF06BC) },
    { be_const_key(deinit, 19), be_const_ctype_func(Berry_HTTPS_Client_Class_Deinitialize_02DAEE61_963B_4E90_ABC7_2CD7137AC322) },
    { be_const_key(Set_Timeout, 16), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Timeout_1606879B_3218_4B52_AB9C_274CC414A388) },
    { be_const_key(Set_Reuse, 26), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Reuse_45AE5B7E_2569_4D8D_B221_E661576EC2FC) },
    { be_const_key(Add_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Add_Header_D2588710_EAFF_420E_97B1_8D32C74D91EE) },
    { be_const_key(Get_Header_Count, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_Count_1897E38D_092F_44A5_A2EF_99CF97799431) },
    { be_const_key(Get_Header, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Get_Header_7C082763_3610_4D43_BEA3_D362E2B23293) },
    { be_const_key(Use_HTTP_1_0, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Use_HTTP_1_0_16235078_C0E9_4485_B927_5D2BAF73189C) },
    { be_const_key(Set_Authorization, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Set_Authorization_F72246A1_1019_4085_8ED0_6138837C2AD7) },
    { be_const_key(Connected, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Connected_A1E182C6_5451_4D75_A988_1BE88323A505) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Initialize_EDBF3719_F362_4BC1_8102_78E4E1EFDA51) },
    { be_const_key(Patch, -1), be_const_ctype_func(Berry_HTTPS_Client_Class_Patch_F9C6E175_015C_4652_9E48_E1CC9F0D89DA) },
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
