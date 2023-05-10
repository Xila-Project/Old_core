#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_310FE14E_4FB8_46AD_9913_0F253DB20C09) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_0A2CEAB3_6B6E_433D_9A05_742741705B4E) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_14C12C28_FACA_4BBB_9855_09D1727E39CE) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_34D00AC9_E7E3_4F00_A273_7DA6B21DCC60) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_54DB4C1D_A778_48C5_A678_3E1702DC237B) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_7143EDE5_60C8_4837_B2B1_85816E6638F0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_CAE2BBB5_AC9E_4674_9B07_53AE25B5A73D) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_B0DAD095_E285_44DC_A6EE_A8F258B87B5A) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_F2DAA2E1_D898_4094_85A8_FD9D067D76A7) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_CB86B629_DABD_41D9_90F6_C3A8BB1F46AC) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_F6349AD4_6F73_444D_BB1F_97F609E5101E) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_C31229EC_F2AB_40B5_98D2_E92767F2E988) },
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
