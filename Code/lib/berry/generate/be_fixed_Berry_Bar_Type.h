#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_AD6B2981_994F_45AB_B0C0_68C496B99B0D) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_DE256886_4A95_448F_AA48_21E282D746D9) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_88B61BBD_2DC1_45EA_8A55_7DDB512848F2) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_7902C986_4819_4148_8E13_A88BE06C9939) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_B2662580_CD0A_4638_9435_CAEF5DA08673) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_C2FF25D2_AB5D_46F0_AB39_614308792475) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_B16B2889_7AAC_4BC6_83EE_C1FAFF780128) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_15A7A874_4A81_4CAC_8C9D_473868CB1BB4) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_79E3770A_187C_46D4_853D_9C8D7EE858F1) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_1F7DC541_B030_4BAD_9485_0137839D260F) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_B5D70019_A395_4059_B175_1ABE8EF95CC8) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_655673F1_3F70_49F6_B6BC_03935CF2D80F) },
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
