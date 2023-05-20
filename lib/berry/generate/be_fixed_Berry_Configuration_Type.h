#include "be_constobj.h"

static be_define_const_map_slots(Berry_Configuration_Type_map) {
    { be_const_key(Set_Bits_Per_Sample, 8), be_const_ctype_func(Berry_Configuration_Class_Set_Bits_Per_Sample_E30EC6ED_6342_44AA_A738_8B8D1493744D) },
    { be_const_key(Get_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Sample_Rate_A03AABC3_972E_4A76_A00E_526C62FE6913) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Configuration_Class_Initialize_2D601331_7569_4A65_9DE6_5FC170493607) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Configuration_Class_Deinitialize_49F40616_F7CF_4F6C_9350_4E59D8BC2174) },
    { be_const_key(Get_Bits_Per_Sample, 10), be_const_ctype_func(Berry_Configuration_Class_Get_Bits_Per_Sample_74FEA4F6_BD41_4994_BE2A_77E40F8F1137) },
    { be_const_key(_X21_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_F60C3F26_ADEF_4667_976A_A93950E83E10) },
    { be_const_key(Set, 6), be_const_ctype_func(Berry_Configuration_Class_Set_AF0E1E7B_3C44_40E1_9647_5CC1B87C7099) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Configuration_Class_Operator_AA287832_5062_48B5_AC8B_CBA08EC883BC) },
    { be_const_key(Set_Sample_Rate, -1), be_const_ctype_func(Berry_Configuration_Class_Set_Sample_Rate_8272448F_5FE7_4025_8416_42BE501F0B72) },
    { be_const_key(Get_Channel_Count, -1), be_const_ctype_func(Berry_Configuration_Class_Get_Channel_Count_CA545991_B3B5_4C7F_BCB5_7CC5C3A32826) },
    { be_const_key(Set_Channel_Count, 0), be_const_ctype_func(Berry_Configuration_Class_Set_Channel_Count_99D2C966_5317_45B9_9469_E802F413EE4C) },
};

static be_define_const_map(
    Berry_Configuration_Type_map,
    12
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Configuration_Type,
    1,
    NULL,
    Configuration_Type
);
