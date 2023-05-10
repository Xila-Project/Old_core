#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_C880E520_C95A_400E_8D08_E54F0B73D708) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_FCC527F6_910C_4C25_B97F_171936764829) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_4B502257_0C58_4E08_BDA7_C1B88BBD00A3) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_A70DC47D_E3AE_41EC_8A04_6D692DC86BAA) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_A54CBB13_3B0E_4D36_8693_EBE1D21C076E) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_5F012887_92BE_4B1A_BFF9_C8EA8FCEFE85) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_759D0C6F_541D_4BAE_9438_69031A0246A6) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_958DD846_2339_4914_B504_A95D0FAA91B7) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_A0E0CB11_2CCD_4723_9355_6308EC1C14EF) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_DF6CE890_845A_4AB4_A381_CCB1D6E38004) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_7C5E3921_6DF4_4D51_9350_901837A8EE1D) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_4B3C74ED_85CF_40C8_B4E5_9698536758AD) },
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
