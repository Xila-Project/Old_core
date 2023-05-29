#include "be_constobj.h"

static be_define_const_map_slots(m_libSoftwares_map) {
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Softwares_Class_Close_98164576_13F1_47CC_8DC5_26A2B0DE1A74) },
    { be_const_key(Open, -1), be_const_ctype_func(Berry_Softwares_Class_Open_E4F69B72_D66C_4D1D_B123_77DBFF9A89AC) },
    { be_const_key(Get_Handle_Count, 21), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_Count_8F8EBDAB_FB78_49BC_878D_669863FF05CA) },
    { be_const_key(Get_User_Softwares_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_Count_813F3D1F_5123_424E_8B52_435A74C1AAE2) },
    { be_const_key(Get_User_Softwares, 20), be_const_ctype_func(Berry_Softwares_Class_Get_User_Softwares_190EECA0_9B18_4EDD_8A3D_DB31D4A228E1) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Softwares_Class_Start_DACDB2F5_88C3_4C2B_989E_898DE3390869) },
    { be_const_key(Register_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Register_Handle_A9D769C8_0700_4EC8_B5EF_76154B8B3A29) },
    { be_const_key(Find, -1), be_const_ctype_func(Berry_Softwares_Class_Find_65C94800_5123_4B65_BE72_4C873AFB8B20) },
    { be_const_key(Find_Handle, 9), be_const_ctype_func(Berry_Softwares_Class_Find_Handle_F8E319AF_9141_4E84_B012_A7B71EFF5BB4) },
    { be_const_key(Kill, -1), be_const_ctype_func(Berry_Softwares_Class_Kill_59C8D5F1_6F10_4FAA_B4F2_50BD70EB63A4) },
    { be_const_key(Get_Count, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Count_ACA436F9_4C57_421F_874A_12B6B5A01F86) },
    { be_const_key(Stop, 10), be_const_ctype_func(Berry_Softwares_Class_Stop_F1FFE368_176D_4758_9CD8_A825D3DCECA7) },
    { be_const_key(Close_User_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Close_User_Softwares_E8CD6677_CD34_4B74_8DDF_59D5F5389128) },
    { be_const_key(Get, -1), be_const_ctype_func(Berry_Softwares_Class_Get_FAED1112_72A6_4EB6_A429_E40461F5C6F7) },
    { be_const_key(Event_Code_Open, -1), be_const_int(0) },
    { be_const_key(Event_Code_Close, 4), be_const_int(1) },
    { be_const_key(Send_Instruction_Softwares, -1), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_Softwares_8B7A6F99_3F64_47C2_AC53_833EA1FCD3DF) },
    { be_const_key(Software_Handle_Type, -1), be_const_class(Berry_Software_Handle_Type) },
    { be_const_key(Software_Type, -1), be_const_class(Berry_Software_Type) },
    { be_const_key(Send_Instruction_User_Softwares, 12), be_const_ctype_func(Berry_Softwares_Class_Send_Instruction_User_Softwares_A472931D_D69F_4458_A56F_5388BBB2E081) },
    { be_const_key(Kill_User_Softwares, 22), be_const_ctype_func(Berry_Softwares_Class_Kill_User_Softwares_1C33EDD1_8440_49BA_AFDF_76A7615BE2A6) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Pointer) },
    { be_const_key(Get_Handle, -1), be_const_ctype_func(Berry_Softwares_Class_Get_Handle_5CB30E8B_1382_44A7_8DB4_19F5D26A8DC7) },
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
