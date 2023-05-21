#include "be_constobj.h"

static be_define_const_map_slots(m_libSoftwares_map) {
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Softwares_Class_Close_CC3FC3AA_9305_4659_83B6_174480A7124B) },
    { be_const_key(Open, -1), be_const_ctype_func(Berry_Softwares_Class_Open_EC7813F3_9D5C_4E0A_9286_16C603C815A1) },
    { be_const_key(Get_Handle_Count, 21), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_Count_CF595DF9_1E46_409B_9A0E_762C66E0E56B) },
    { be_const_key(Get_User_Softwares_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_Count_B7943FD6_5610_424C_9145_E4818CEB9F00) },
    { be_const_key(Get_User_Softwares, 20), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_ED4FB496_0F7A_45BE_A3F5_9B71D9C0D53D) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Softwares_Class_Start_79A9CB66_1E22_43E5_BF00_32D03236D4D8) },
    { be_const_key(Register_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Register_Handle_24FADBD3_3841_48C7_A98C_34E5D58EDB46) },
    { be_const_key(Find, -1), be_const_ctype_func(Berry_Softwares_Class_Find_8FCB3632_B998_4D48_B0CF_DDE2A17CBA84) },
    { be_const_key(Find_Handle, 9), be_const_ctype_func(Berry_Softwares_Class_Find_Handle_84079706_8F46_4B23_A257_98CD02F76A2F) },
    { be_const_key(Kill, -1), be_const_ctype_func(Berry_Softwares_Class_Kill_19D2B11F_2075_42CA_9C6C_4720BF5D5C6B) },
    { be_const_key(Get_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Count_F4E229FF_37B6_4268_9673_A1AD2561DA20) },
    { be_const_key(Stop, 10), be_const_ctype_func(Berry_Softwares_Class_Stop_5F4B5D4D_60B5_440F_9A41_82513B19C44E) },
    { be_const_key(Close_User_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Close_User_Softwares_4ED7C5F7_0FF9_4516_A071_A8D9EE03E6B2) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_Softwares_Class_Get_AFE9FC2D_EAD8_466F_8BFE_4DBB8F4170CA) },
    { be_const_key(Event_Code_Open, -1), be_const_int(0) },
    { be_const_key(Event_Code_Close, 4), be_const_int(1) },
    { be_const_key(Send_Instruction_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_Softwares_C916C839_1A19_4CBE_BC3C_03E0660786AC) },
    { be_const_key(Software_Handle_Type, -1), be_const_class(Berry_Software_Handle_Type) },
    { be_const_key(Software_Type, -1), be_const_class(Berry_Software_Type) },
    { be_const_key(Send_Instruction_User_Softwares, 12), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_User_Softwares_FFBA8108_BA6B_454B_B5FA_6043469B7853) },
    { be_const_key(Kill_User_Softwares, 22), be_const_ctype_func(Berry_Softwares_Class_Kill_User_Softwares_B40F0B84_9F88_439E_9B30_31D1AF1B97A4) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Pointer) },
    { be_const_key(Get_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_B86EF136_2EB7_42E3_925F_D4D941F649DF) },
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
