#include "be_constobj.h"

static be_define_const_map_slots(m_libSoftwares_map) {
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Softwares_Class_Close_75AE89BA_276B_4200_92B8_EDE4153971BE) },
    { be_const_key(Open, -1), be_const_ctype_func(Berry_Softwares_Class_Open_A1BAFBAF_9883_4924_81A6_FEE09791F68C) },
    { be_const_key(Get_Handle_Count, 21), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_Count_DC10AC0A_DB04_4665_87B8_5D542A84FEA6) },
    { be_const_key(Get_User_Softwares_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_Count_A16F98CC_AC26_4383_BEF9_780A8B47F394) },
    { be_const_key(Get_User_Softwares, 20), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_FB2446CB_E93D_4245_B723_6C6752174865) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Softwares_Class_Start_8EB3058D_8DD3_4842_AABC_9333C85F328C) },
    { be_const_key(Register_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Register_Handle_CAFDD375_9992_4F91_818A_A138A56B05A9) },
    { be_const_key(Find, -1), be_const_ctype_func(Berry_Softwares_Class_Find_AFB83769_530E_4A25_9579_CD618B1EE703) },
    { be_const_key(Find_Handle, 9), be_const_ctype_func(Berry_Softwares_Class_Find_Handle_0E4EDD4B_B4C0_4011_A36C_6DCE90CFB4A2) },
    { be_const_key(Kill, -1), be_const_ctype_func(Berry_Softwares_Class_Kill_F1C76A3A_76A1_4BDE_80D7_ADEBF3C915E6) },
    { be_const_key(Get_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Count_E19D8DAA_B4F0_4542_93C0_965B037048EE) },
    { be_const_key(Stop, 10), be_const_ctype_func(Berry_Softwares_Class_Stop_256ADCCB_85C7_43CC_99BB_F1F3ADD8243E) },
    { be_const_key(Close_User_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Close_User_Softwares_2F7B1BAB_E48E_4FA0_A00D_011720A2F788) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_Softwares_Class_Get_EF008322_CA01_483F_BB60_47C5FFC7ECF6) },
    { be_const_key(Event_Code_Open, -1), be_const_int(0) },
    { be_const_key(Event_Code_Close, 4), be_const_int(1) },
    { be_const_key(Send_Instruction_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_Softwares_FC5D3B41_5954_4F11_B297_4B0160549EE0) },
    { be_const_key(Software_Handle_Type, -1), be_const_class(Berry_Software_Handle_Type) },
    { be_const_key(Software_Type, -1), be_const_class(Berry_Software_Type) },
    { be_const_key(Send_Instruction_User_Softwares, 12), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_User_Softwares_40411F55_B9A8_4783_A2F5_88C993274770) },
    { be_const_key(Kill_User_Softwares, 22), be_const_ctype_func(Berry_Softwares_Class_Kill_User_Softwares_C8BE0067_A7B9_4E17_8479_C74FC42C0401) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Pointer) },
    { be_const_key(Get_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_A2DCE1B4_B4CB_4E8A_82D7_E17807BA4F1C) },
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
