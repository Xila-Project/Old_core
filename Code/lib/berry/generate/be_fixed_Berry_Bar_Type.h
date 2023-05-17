#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_8756CCC1_40D5_4A39_A0A5_053EE04FBB7C) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_851C58B3_9F66_41D3_928C_BF9B1122A8C3) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_6C9CE6A2_9EB3_4292_94E6_B54610440C34) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_B595FFA5_221E_44C5_B8A8_9F891481810A) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_FE12F076_383F_4D85_B389_0AFA68E2CC6E) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_1477839A_45F5_46E8_9F7F_3541F9909AAB) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_1B00CD8D_522D_432F_91B3_BD45C86E3236) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_10A690DA_D30B_462C_B0B1_E7876F7E7F73) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_096CB76F_A847_4801_9141_D80E3FF87400) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_E307533C_D140_412A_AA8B_32185EBF2A78) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_F3F94E83_C894_4C1B_9095_078BBB642673) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_71725B68_989E_41E9_ADEC_A4671B9250A8) },
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
