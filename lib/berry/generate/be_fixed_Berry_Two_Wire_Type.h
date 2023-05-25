#include "be_constobj.h"

static be_define_const_map_slots(Berry_Two_Wire_Type_map) {
    { be_const_key(Write, -1), be_const_ctype_func(Berry_Two_Wire_Class_Write_CA7D5522_ED2C_4532_B7C7_B893B1682984) },
    { be_const_key(Read_String, -1), be_const_ctype_func(Berry_Two_Wire_Class_Read_String_D01F4822_DFA1_49D0_9BF6_8547261E365B) },
    { be_const_key(Available, -1), be_const_ctype_func(Berry_Two_Wire_Class_Available_7D5304A5_4060_4570_8697_BF442AB836D1) },
    { be_const_key(Peek, -1), be_const_ctype_func(Berry_Two_Wire_Class_Peek_690D5623_C502_41F6_BFA9_5D41AD90263A) },
    { be_const_key(Get_Clock_Frequency, -1), be_const_ctype_func(Berry_Two_Wire_Class_Get_Clock_Frequency_89EA0DBC_901B_4A2C_B338_24F5A34356FF) },
    { be_const_key(Write_Bytes, -1), be_const_ctype_func(Berry_Two_Wire_Class_Write_Bytes_D30BE65E_5CBE_4157_A1FC_72B2EA1336E2) },
    { be_const_key(Slave_Write, -1), be_const_ctype_func(Berry_Two_Wire_Class_Slave_Write_BBCE7EAE_7371_4DFE_AF4E_62056A709EE4) },
    { be_const_key(Set_Pins, -1), be_const_ctype_func(Berry_Two_Wire_Class_Set_Pins_87A666C3_5232_4D74_9DAB_766F743AB7F4) },
    { be_const_key(End_Transmission, -1), be_const_ctype_func(Berry_Two_Wire_Class_End_Transmission_ACCC333B_B30D_43B2_81C2_CF25747B0DE5) },
    { be_const_key(Set_Timeout, -1), be_const_ctype_func(Berry_Two_Wire_Class_Set_Timeout_B9C1AEB0_0E0C_4434_B212_320630DEC6EA) },
    { be_const_key(Request_From, 13), be_const_ctype_func(Berry_Two_Wire_Class_Request_From_D7A77685_EE42_43AE_8469_727F8BA2D59E) },
    { be_const_key(Flush, -1), be_const_ctype_func(Berry_Two_Wire_Class_Flush_D92BF166_3E2F_41CE_BEC0_0568AF53E491) },
    { be_const_key(Read, 1), be_const_ctype_func(Berry_Two_Wire_Class_Read_D811B787_85C6_49DA_985A_DF2512DCD4F6) },
    { be_const_key(Begin, 14), be_const_ctype_func(Berry_Two_Wire_Class_Begin_8A3C95E7_B843_4CE1_826A_B5E989B534E8) },
    { be_const_key(Begin_Transmission, 15), be_const_ctype_func(Berry_Two_Wire_Class_Begin_Transmission_2ACAB4BD_8DEF_4D5B_AEA7_04903E8BCAAC) },
    { be_const_key(Set_Clock_Frequency, -1), be_const_ctype_func(Berry_Two_Wire_Class_Set_Clock_Frequency_C15745A0_6451_4B58_A374_C4C201DF6549) },
    { be_const_key(Read_Bytes, -1), be_const_ctype_func(Berry_Two_Wire_Class_Read_Bytes_A6DA10F5_6724_4F22_8A94_F9BB2EC03F05) },
    { be_const_key(Get_Timeout, 3), be_const_ctype_func(Berry_Two_Wire_Class_Get_Timeout_F9F866CD_4E09_4204_9ABA_596F78D7A06E) },
    { be_const_key(End, 9), be_const_ctype_func(Berry_Two_Wire_Class_End_23DC729D_857E_4074_934E_52ADD8F1DFA4) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Two_Wire_Class_Deinitialize_8AEA079C_0A1D_4CB6_AC62_B90CC01489A9) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Two_Wire_Type_map,
    21
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Two_Wire_Type,
    1,
    NULL,
    Two_Wire_Type
);
