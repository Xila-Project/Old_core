#include "be_constobj.h"

static be_define_const_map_slots(m_libSoftwares_map) {
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Softwares_Class_Close_68780FE3_68D0_4CC2_BE12_998C506735BE) },
    { be_const_key(Open, -1), be_const_ctype_func(Berry_Softwares_Class_Open_0BCAA9EF_4EDD_4643_9E0B_301162C75E91) },
    { be_const_key(Get_Handle_Count, 21), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_Count_50066AF0_D37F_4795_BCC4_D705A5F3A351) },
    { be_const_key(Get_User_Softwares_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_Count_D3F2EF60_C447_4E89_BFBD_C4CDCD017104) },
    { be_const_key(Get_User_Softwares, 20), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_480BF045_538F_4A27_9CCD_2DD085DC8D45) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Softwares_Class_Start_BDD9F464_03CB_4DD4_A4E4_FD84DDD4C7D9) },
    { be_const_key(Register_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Register_Handle_26C81BCA_69F3_430B_B181_4B2E2E82CFA9) },
    { be_const_key(Find, -1), be_const_ctype_func(Berry_Softwares_Class_Find_225F74F8_D29B_4A3D_B4FF_6B1C01226960) },
    { be_const_key(Find_Handle, 9), be_const_ctype_func(Berry_Softwares_Class_Find_Handle_347EA99E_5DF3_429E_8C39_45AE2AF40327) },
    { be_const_key(Kill, -1), be_const_ctype_func(Berry_Softwares_Class_Kill_B4CD4084_65B3_427C_A7B6_B7BF1F66A7EB) },
    { be_const_key(Get_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Count_6C245576_C1C5_459C_9AE2_88A90F296754) },
    { be_const_key(Stop, 10), be_const_ctype_func(Berry_Softwares_Class_Stop_16D7CFBB_07D0_4CC4_A9C2_FE99B9BDCCF5) },
    { be_const_key(Close_User_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Close_User_Softwares_039510C5_B2B0_46D2_887E_19E3A62EE64F) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_Softwares_Class_Get_A207ACC9_370B_4C5C_899F_08333EABC50B) },
    { be_const_key(Event_Code_Open, -1), be_const_int(0) },
    { be_const_key(Event_Code_Close, 4), be_const_int(1) },
    { be_const_key(Send_Instruction_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_Softwares_431D9BC7_5A57_4978_A1F7_72E9BCB7ECB5) },
    { be_const_key(Software_Handle_Type, -1), be_const_class(Berry_Software_Handle_Type) },
    { be_const_key(Software_Type, -1), be_const_class(Berry_Software_Type) },
    { be_const_key(Send_Instruction_User_Softwares, 12), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_User_Softwares_FBA0DC11_2C99_4641_A069_D3CA2E2CAC44) },
    { be_const_key(Kill_User_Softwares, 22), be_const_ctype_func(Berry_Softwares_Class_Kill_User_Softwares_DDC44481_1EC2_4336_8EFB_14B7B5B1B866) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Pointer) },
    { be_const_key(Get_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_EE43B453_021A_4980_9698_4E52184EBB94) },
};

static be_define_const_map(
    m_libSoftwares_map,
    23
);

static be_define_const_module(
    m_libSoftwares,
    "Softwares"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Softwares);
