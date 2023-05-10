#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_8FC70037_2F10_437D_91D2_A88BC6402292) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_B7687DBB_3E75_4B00_9544_FF13F175FFDE) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_7DD9C218_597F_477D_B3B4_274C6F64DC45) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_0B0625A5_B408_478A_B8AA_B532936FEB4D) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_1A8FFF6F_B5CD_4982_8D07_CA5B136D6132) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_D8177B74_4F61_4549_B21D_760AEDCDBD66) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_16117343_98A6_42C5_90A0_BF5ED3E155E4) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_A45489E8_8E68_4BE3_9E65_889AC2180D2B) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_2EEDEB83_2EB5_411D_BE89_18BFC9070E71) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_E3FE38D9_CA88_4AE4_8F75_AEDC071FD6AC) },
};

static be_define_const_map(
    Berry_Roller_Type_map,
    11
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Roller_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Roller_Type
);
