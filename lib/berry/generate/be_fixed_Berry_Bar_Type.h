#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_B15BA767_2D35_405A_9DF8_E4D950377B60) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_82720663_32BB_4C73_8525_841C0DCF38CF) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_B3645752_851F_46F9_B4B5_95267737D7CC) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_D3CB33E5_2B1E_4AE4_ACDE_12AE26BB7384) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_3A229E8A_8FC6_4DC6_90E7_F11790EFEA9F) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_5E7CA6E8_DC05_4CF1_BFC1_AAABB327E8AA) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_E50FACA5_AA3A_4B8A_A07D_A8040279776E) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_2310B8AF_CCB8_4CDF_8D1F_27AEBA9217D0) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_333A5B48_A3D7_4D3D_9907_66739E6D327F) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_5430FF54_5EDA_41CB_A4A0_129DB6C10824) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_6B01CB49_F8E7_4B2D_91D1_93721995D663) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_B7CCE1B7_31AC_480D_9924_4128FF62C52C) },
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
