#include "be_constobj.h"

static be_define_const_map_slots(m_libSoftwares_map) {
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Softwares_Class_Close_A0ECF4D1_4A07_4F72_BBB5_7513230006F2) },
    { be_const_key(Open, -1), be_const_ctype_func(Berry_Softwares_Class_Open_49D4AC2B_D2EA_4C56_BEA5_CB87DDC71CF2) },
    { be_const_key(Get_Handle_Count, 21), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_Count_EB2398B2_41BA_4C53_9CB2_A3B038C49801) },
    { be_const_key(Get_User_Softwares_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_Count_DCFE53CA_11F2_4FD9_ABE7_951C7B583683) },
    { be_const_key(Get_User_Softwares, 20), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_9DE31049_F486_47E0_AE65_B8D21858F62A) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Softwares_Class_Start_29CF102E_B9C6_4992_873D_B15BCCDCA4FA) },
    { be_const_key(Register_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Register_Handle_096ED58F_DE20_47CD_ADF2_FDA0DF236CD1) },
    { be_const_key(Find, -1), be_const_ctype_func(Berry_Softwares_Class_Find_4249F5CC_366A_40AB_A295_34AA90000837) },
    { be_const_key(Find_Handle, 9), be_const_ctype_func(Berry_Softwares_Class_Find_Handle_FD71F9A4_4011_4A2E_B8F0_78FDD87CC0F0) },
    { be_const_key(Kill, -1), be_const_ctype_func(Berry_Softwares_Class_Kill_D015FB26_88F8_4C7D_9497_95925DE7FEE4) },
    { be_const_key(Get_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Count_BBC81456_46FB_42DC_9205_E41E364A0760) },
    { be_const_key(Stop, 10), be_const_ctype_func(Berry_Softwares_Class_Stop_56A45A0F_637E_46A1_A91B_CA3524F01964) },
    { be_const_key(Close_User_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Close_User_Softwares_ABB3AC75_EB2D_44F1_B22C_3E4C74D51ED4) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_Softwares_Class_Get_F34349A2_A633_487D_9688_4127C019F8B1) },
    { be_const_key(Event_Code_Open, -1), be_const_int(0) },
    { be_const_key(Event_Code_Close, 4), be_const_int(1) },
    { be_const_key(Send_Instruction_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_Softwares_64DB55F1_7A18_450A_B3C1_CA0058A69BDE) },
    { be_const_key(Software_Handle_Type, -1), be_const_class(Berry_Software_Handle_Type) },
    { be_const_key(Software_Type, -1), be_const_class(Berry_Software_Type) },
    { be_const_key(Send_Instruction_User_Softwares, 12), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_User_Softwares_C7DE727D_6781_4438_8250_5E172B0F1AC2) },
    { be_const_key(Kill_User_Softwares, 22), be_const_ctype_func(Berry_Softwares_Class_Kill_User_Softwares_A0982A54_0CAE_4AB2_B117_47F7BF8C9C83) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Pointer) },
    { be_const_key(Get_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_01600034_E172_49B0_AAFC_8DBB5FA5D6C0) },
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
