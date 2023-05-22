#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_50E425E5_436E_4A98_950A_8E23128EF2E3) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_9C1D1609_7D2B_41C7_9FCB_ED4B8AB16F4E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_CF546DDD_86C0_4D67_BEB3_6F0D96A88208) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_19C9EE41_6D06_4E3C_93A3_73087E50EA2D) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_63F6F36D_AF72_417E_88E9_6F6BF34D6C6F) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_02701C69_9B4A_432D_97F5_22EB53A794A9) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_7A2C09B0_065B_4138_82A6_6ECF1444479A) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_8BE9A829_5EF3_4685_BECA_E636033762C2) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_94300FC4_3C7D_455B_BDE9_85915F442430) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_2858BC78_9F27_4812_8396_5729FF8728BD) },
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
