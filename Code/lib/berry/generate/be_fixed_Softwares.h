#include "be_constobj.h"

static be_define_const_map_slots(m_libSoftwares_map) {
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Softwares_Class_Close_F8032388_A528_4378_87E7_EFAB65BDCA53) },
    { be_const_key(Open, -1), be_const_ctype_func(Berry_Softwares_Class_Open_C506BB9B_0C66_49E2_B766_087165402592) },
    { be_const_key(Get_Handle_Count, 21), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_Count_E1C8B10D_1ADC_4D95_B2CC_708BEF2DF08A) },
    { be_const_key(Get_User_Softwares_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_Count_C5BAFE01_C8DC_4955_B31F_C45E55AC69B2) },
    { be_const_key(Get_User_Softwares, 20), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_5FD2C7A7_7454_4D6F_9604_188AFB1ADAA8) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Softwares_Class_Start_3F88A669_44A6_4C4F_BA46_282477F04B6C) },
    { be_const_key(Register_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Register_Handle_B99E6369_2723_4606_82F1_D15F3F23FB7F) },
    { be_const_key(Find, -1), be_const_ctype_func(Berry_Softwares_Class_Find_82F4BF15_90EA_4BD9_A6FB_2D2360B5A07C) },
    { be_const_key(Find_Handle, 9), be_const_ctype_func(Berry_Softwares_Class_Find_Handle_15DF1C43_3F39_4F1C_8CD5_02D3300A9EE9) },
    { be_const_key(Kill, -1), be_const_ctype_func(Berry_Softwares_Class_Kill_FFDDE678_E2D2_4683_98F4_BC5994C7CE43) },
    { be_const_key(Get_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Count_771D7FE7_C632_417B_87B6_4AD8DDE48BA3) },
    { be_const_key(Stop, 10), be_const_ctype_func(Berry_Softwares_Class_Stop_E4CC0DDA_0239_4D98_BF59_1E376500300A) },
    { be_const_key(Close_User_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Close_User_Softwares_C8CA88A1_443E_4FA3_93D3_A562FA93ADA9) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_Softwares_Class_Get_568424DF_1D77_4D1D_8413_05CDD0484F12) },
    { be_const_key(Event_Code_Open, -1), be_const_int(0) },
    { be_const_key(Event_Code_Close, 4), be_const_int(1) },
    { be_const_key(Send_Instruction_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_Softwares_3977912D_4EDB_4042_879F_0F61166377BF) },
    { be_const_key(Software_Handle_Type, -1), be_const_class(Berry_Software_Handle_Type) },
    { be_const_key(Software_Type, -1), be_const_class(Berry_Software_Type) },
    { be_const_key(Send_Instruction_User_Softwares, 12), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_User_Softwares_8EDFF513_527B_43E3_8FDC_988CC7F6F4C0) },
    { be_const_key(Kill_User_Softwares, 22), be_const_ctype_func(Berry_Softwares_Class_Kill_User_Softwares_1A16319B_2580_4436_BA85_F0A00D6F6245) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Pointer) },
    { be_const_key(Get_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_3EF96205_2821_4C52_A37B_9DE7F7C5A2B6) },
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
