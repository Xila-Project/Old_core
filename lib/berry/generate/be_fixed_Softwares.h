#include "be_constobj.h"

static be_define_const_map_slots(m_libSoftwares_map) {
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Softwares_Class_Close_17B54774_32B8_4453_A7DB_9F744DA1493D) },
    { be_const_key(Open, -1), be_const_ctype_func(Berry_Softwares_Class_Open_EF6CB123_9C28_4548_AFCC_6B6F7ED5944B) },
    { be_const_key(Get_Handle_Count, 21), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_Count_BA5E2ED2_BF14_449F_A40A_DEC278FBCC9C) },
    { be_const_key(Get_User_Softwares_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_Count_3A2CEC0B_EB8B_4769_BF1A_7F36BC448859) },
    { be_const_key(Get_User_Softwares, 20), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_4FC206B9_5674_447E_80B4_8C5F5ADB4404) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Softwares_Class_Start_1CD93EF1_250D_42CE_ABB5_6C3FFFC686BB) },
    { be_const_key(Register_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Register_Handle_8B3B76DF_CB99_4721_919B_6F7BE0A11C57) },
    { be_const_key(Find, -1), be_const_ctype_func(Berry_Softwares_Class_Find_0C4D99C3_0E73_4FD9_A407_D397F74BBD64) },
    { be_const_key(Find_Handle, 9), be_const_ctype_func(Berry_Softwares_Class_Find_Handle_1B103B68_A71A_4039_8487_1EE002D5ABED) },
    { be_const_key(Kill, -1), be_const_ctype_func(Berry_Softwares_Class_Kill_261BD8B1_97AA_4FD4_85E7_77DB6AAD7426) },
    { be_const_key(Get_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Count_8D09B1DA_4FB6_434A_B01D_C9D5A83B6307) },
    { be_const_key(Stop, 10), be_const_ctype_func(Berry_Softwares_Class_Stop_DBFA9A96_0E40_4CD4_A32A_FD7020523200) },
    { be_const_key(Close_User_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Close_User_Softwares_45B77752_FD8C_4D0F_918A_27E8EF2AA206) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_Softwares_Class_Get_DF92C9BE_A5E0_4157_982B_754D5E281D04) },
    { be_const_key(Event_Code_Open, -1), be_const_int(0) },
    { be_const_key(Event_Code_Close, 4), be_const_int(1) },
    { be_const_key(Send_Instruction_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_Softwares_CE5B0C42_0B6A_4A63_8A6A_4C0ED2570519) },
    { be_const_key(Software_Handle_Type, -1), be_const_class(Berry_Software_Handle_Type) },
    { be_const_key(Software_Type, -1), be_const_class(Berry_Software_Type) },
    { be_const_key(Send_Instruction_User_Softwares, 12), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_User_Softwares_CA59DC77_B421_40C7_B6C5_131987C03950) },
    { be_const_key(Kill_User_Softwares, 22), be_const_ctype_func(Berry_Softwares_Class_Kill_User_Softwares_8EA53A7E_FB42_47F7_AB08_8A20C7117FA3) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Pointer) },
    { be_const_key(Get_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_E4ED3233_27E3_4F2A_919B_A873EBACAF04) },
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
