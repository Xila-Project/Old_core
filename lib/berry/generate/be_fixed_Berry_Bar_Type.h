#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_CE198449_A2E8_4DC1_B74C_2D87762B138C) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_F8E54477_153F_4BC8_A2A8_02159FC42FA2) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_57D79EAE_6F09_4499_ADA9_4330A27F5F1B) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_F5F10B48_B343_44A0_82A0_275ECC8F85E6) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_262A8642_D899_4CDE_B97C_E5604CC55104) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_7FCACA6D_52AB_4DFE_822A_67FB9641A681) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_9BF3A679_C4A2_49CF_9F32_2C99B047606E) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_E954A043_1B8B_4DB8_B08F_2CFDF3997BDB) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_42487337_96DF_4DD1_B323_E8CEC63D35E4) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_3834CA7D_92C0_4001_AEC7_3B9A6978D593) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_C2AB00ED_4F8D_44BA_A85A_F31A3437172A) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_10100DCD_DB9D_4760_BA6F_40349561112D) },
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
