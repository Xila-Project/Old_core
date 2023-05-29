#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_3FADC225_184F_4A87_8B10_4A00EA7361EE) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_618E175C_C2DB_4F69_9FB9_A2C3482708B7) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_BEC2FA96_C0A7_45C1_A050_B7D6D841668D) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_68791752_0A73_4FF1_9281_11EE3A9E7CD8) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_0A21CB10_84B2_4821_871D_7B37ED816FC5) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_F4E06E19_4AE1_4203_B46E_450BEB0EEC98) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_76A2DFC0_0CB2_4989_AE63_295959BEB522) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_8831B762_6B50_4EDB_930E_3ACB5AD1DED2) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_D1A7624D_4BD6_44FB_AE63_E7AD99CD69E9) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_16566304_9425_44A5_94B3_7F9C4C3FBED7) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_9C011BE0_2E2D_4CD6_80A7_50A99570B8AE) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_FC628585_69A5_43EE_AFFC_D3466B708C7A) },
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
