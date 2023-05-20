#include "be_constobj.h"

static be_define_const_map_slots(m_libSoftwares_map) {
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Softwares_Class_Close_111CB8EB_63F2_4A98_A32D_740758C0B0C0) },
    { be_const_key(Open, -1), be_const_ctype_func(Berry_Softwares_Class_Open_421AF0F1_1942_4C8A_934D_D5705A8A3967) },
    { be_const_key(Get_Handle_Count, 21), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_Count_3DE6CF5E_8980_449B_A216_3C2DAC29B0C2) },
    { be_const_key(Get_User_Softwares_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_Count_7F0D0076_4964_4F25_B190_0F8F2891BE3E) },
    { be_const_key(Get_User_Softwares, 20), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_9B11B34B_1A61_45C9_AD1F_507677E5EBCB) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Softwares_Class_Start_6F130DF0_FFB5_4CDA_A261_29F90CCB48AB) },
    { be_const_key(Register_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Register_Handle_AB2C1DEA_D093_471F_B940_FC246C77DFF6) },
    { be_const_key(Find, -1), be_const_ctype_func(Berry_Softwares_Class_Find_D58402B6_1ED0_46D2_979E_7B50B9C6E689) },
    { be_const_key(Find_Handle, 9), be_const_ctype_func(Berry_Softwares_Class_Find_Handle_3979D0C5_A7A0_48C3_8E11_90AAB5E40150) },
    { be_const_key(Kill, -1), be_const_ctype_func(Berry_Softwares_Class_Kill_F5A97610_DB0E_4366_A100_468F489D985B) },
    { be_const_key(Get_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Count_C36F6933_8D74_41F0_80A8_553820762EC0) },
    { be_const_key(Stop, 10), be_const_ctype_func(Berry_Softwares_Class_Stop_4F82F8BD_DEBE_4E5D_A6A2_B50933E34773) },
    { be_const_key(Close_User_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Close_User_Softwares_1F95B328_5FB2_4859_8A24_576163588ADB) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_Softwares_Class_Get_055D356D_8F5D_446E_B877_711562B88AEC) },
    { be_const_key(Event_Code_Open, -1), be_const_int(0) },
    { be_const_key(Event_Code_Close, 4), be_const_int(1) },
    { be_const_key(Send_Instruction_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_Softwares_D83250D7_3707_49B4_9500_DD12E2103FA8) },
    { be_const_key(Software_Handle_Type, -1), be_const_class(Berry_Software_Handle_Type) },
    { be_const_key(Software_Type, -1), be_const_class(Berry_Software_Type) },
    { be_const_key(Send_Instruction_User_Softwares, 12), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_User_Softwares_17FD729C_64D8_4066_9F1F_9513D7581BF5) },
    { be_const_key(Kill_User_Softwares, 22), be_const_ctype_func(Berry_Softwares_Class_Kill_User_Softwares_D35CC38E_24E9_4A11_BC58_A719158B8E95) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Pointer) },
    { be_const_key(Get_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_77ECBEC2_3343_46D5_A8A9_EC93B7061D8C) },
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
