#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_B7AC2097_2A0A_4008_B933_6AE1837F354B) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_504ECE34_8B08_4A47_BD97_4691B0A46EF2) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_5AD28A97_7584_4857_88EE_99EEA84DC9D3) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_6485A57D_B8B4_401E_AA31_4A557227A78B) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_3FA3CA33_91D9_489F_8D7E_9E5E9FAA3764) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_DEDA5A21_E39F_4A71_9393_6115CDE9F909) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_35774A89_588E_45C5_BC94_26DAFFF6190D) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_555ADECC_C9B8_4B8C_B23F_AD4A8A415081) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_41BFE171_AC0F_47AE_9C18_B51D3A20D6F0) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_64145234_54F1_48A3_A574_77BDA7FF019F) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_E51BA1E9_78B0_4C2F_B4E2_6CD2BD03F494) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_05F7DF88_1C4E_411F_A75E_447236229FCB) },
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
