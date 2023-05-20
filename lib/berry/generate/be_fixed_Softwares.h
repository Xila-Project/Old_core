#include "be_constobj.h"

static be_define_const_map_slots(m_libSoftwares_map) {
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Softwares_Class_Close_46C74302_C610_4CFD_8634_067FDD4030E3) },
    { be_const_key(Open, -1), be_const_ctype_func(Berry_Softwares_Class_Open_4343E18E_46C4_40D7_B3FE_E69BEC23741F) },
    { be_const_key(Get_Handle_Count, 21), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_Count_31E0CA0A_BED7_45D1_BCAB_6F3D5BDB37DA) },
    { be_const_key(Get_User_Softwares_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_Count_1C6168DF_93E3_42B8_9996_36B5F7EB294A) },
    { be_const_key(Get_User_Softwares, 20), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_93E638A7_DD80_4F11_BFA7_D1237FD6C26F) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Softwares_Class_Start_E50C0A58_FE92_44D4_BAD8_020F34D6440E) },
    { be_const_key(Register_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Register_Handle_9B4AEC9A_A467_4D60_A8DC_7C1E973448CE) },
    { be_const_key(Find, -1), be_const_ctype_func(Berry_Softwares_Class_Find_F29E4670_604D_4875_B13B_9E22B378B31E) },
    { be_const_key(Find_Handle, 9), be_const_ctype_func(Berry_Softwares_Class_Find_Handle_6BDD8919_BD0D_45EE_A61D_6836A26F88D7) },
    { be_const_key(Kill, -1), be_const_ctype_func(Berry_Softwares_Class_Kill_6FEF36A6_7CB8_4D2A_9BE4_284AADD2B1DF) },
    { be_const_key(Get_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Count_3993EC13_2666_4EF0_A810_2AAA1BABFF33) },
    { be_const_key(Stop, 10), be_const_ctype_func(Berry_Softwares_Class_Stop_34499AEB_69C8_4020_859A_30D27648B960) },
    { be_const_key(Close_User_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Close_User_Softwares_C91C9661_EA1A_4A97_A7BF_27E5BBE6D566) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_Softwares_Class_Get_8655BDFA_A350_4BD4_9796_FD5F27261743) },
    { be_const_key(Event_Code_Open, -1), be_const_int(0) },
    { be_const_key(Event_Code_Close, 4), be_const_int(1) },
    { be_const_key(Send_Instruction_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_Softwares_6EEB0790_E8BE_4DB5_B632_E777053E09A9) },
    { be_const_key(Software_Handle_Type, -1), be_const_class(Berry_Software_Handle_Type) },
    { be_const_key(Software_Type, -1), be_const_class(Berry_Software_Type) },
    { be_const_key(Send_Instruction_User_Softwares, 12), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_User_Softwares_892097D4_3F69_4F61_9AAC_A4B5F3A81A3D) },
    { be_const_key(Kill_User_Softwares, 22), be_const_ctype_func(Berry_Softwares_Class_Kill_User_Softwares_494FEB72_0EB4_4109_BF4C_7606E3041006) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Pointer) },
    { be_const_key(Get_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_966B0E9B_F6FA_44AD_9BDA_F8D28D7E5F7B) },
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
