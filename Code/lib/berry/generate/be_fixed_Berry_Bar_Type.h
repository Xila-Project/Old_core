#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_989869B4_6971_4C1F_9EE9_391C13516AB9) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_064A8021_FD0C_4C70_9166_FB5D38AF1C39) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_473CEA40_4B36_42DE_BD00_F0F8920D5A13) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_ACDC8003_2A4D_4FF9_9D07_7ECBE32E68BA) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_7C330654_919D_4892_9E78_5E873E685E63) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_67B962B4_9364_4D91_B245_C52B65143E07) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_70529AD2_86C9_46E7_A50C_1ADE57666499) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_E3382979_A4A0_4D40_834E_A9114929EA52) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_8E707D9E_5F04_47C5_860F_9A94955D0C9C) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_811A3668_36E8_4748_B809_89942719083F) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_36983521_4623_4AF0_A58B_B9A095F9E861) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_D7466080_D947_4967_BFC0_2F740F534333) },
};

static be_define_const_map(
    Berry_Bar_Type_map,
    13
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Bar_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Bar_Type
);
