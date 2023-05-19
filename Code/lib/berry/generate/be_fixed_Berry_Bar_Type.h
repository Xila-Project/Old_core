#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_B8C95B76_5F42_4745_8421_BD4367658159) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_A8D0C56B_6478_4957_8B37_9B968333BA71) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_08C31F77_6F95_4B00_B6CF_B1C28F437705) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_120FE3C7_3E9A_40A0_B9FE_D00C744B437F) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_785368BB_2313_47A7_9FD6_89BAD4DD6655) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_B29347C3_FF79_4B20_931A_3FDB4E0B464C) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_3EC3A1A0_145D_4B3E_8109_EC25E60D1C03) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_3720BC92_33A3_4D04_B747_19A664AC631E) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_B736D58E_DE52_4926_9D26_93C56346E111) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_73084916_234F_421F_9155_942150B6BB34) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_D2C8A1FC_72C6_4944_854D_10DA15E6D41F) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_3AAC9252_DB7C_4BC1_9AB4_694F7333043F) },
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
