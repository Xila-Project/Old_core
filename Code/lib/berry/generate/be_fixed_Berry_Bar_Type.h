#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_3A29C200_DDEB_43BD_918E_6D692431547F) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_C21FBA79_D974_4E26_8D3C_A6CE8EDC38AE) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_DA4324D4_68D8_4F01_A06C_D0B5926B9642) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_03FEBD7B_4EE5_466D_9920_6FFA5DD47438) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_B353BDB0_0A0A_4194_80E0_EF39933D33DE) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_B25ECF1E_3FC4_4A8F_881C_C0D72C39BBD0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_CC0D3E37_F369_4174_9176_CF02039AAA95) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_6F1A4E76_E29C_42DA_B4AD_F2BCA7A5EE21) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_47591D6B_8399_4338_AB96_4D685211A1FA) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_F2CDC188_EEFA_41B4_9073_856095F2A066) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_8FB3D09D_047B_4687_A998_60FC495B6E34) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_2504B2C0_48E7_4C48_8733_03B2A811DFFF) },
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
