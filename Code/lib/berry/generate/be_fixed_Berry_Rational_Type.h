#include "be_constobj.h"

static be_define_const_map_slots(Berry_Rational_Type_map) {
    { be_const_key(Hyperbolic_Cosine, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Cosine_D8383F5B_ADFF_4E09_96CA_1C3AD86BEBA6) },
    { be_const_key(Hyperbolic_Arc_Tangent, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Arc_Tangent_C3D5D53B_3320_42C0_9B0A_4501A6D5D9F7) },
    { be_const_key(Absolute_Value, -1), be_const_ctype_func(Berry_Rational_Class_Absolute_Value_9DC55E6C_4C01_49F6_9A3B_46E2C194A8F3) },
    { be_const_key(Least_Common_Multiple, -1), be_const_ctype_func(Berry_Rational_Class_Least_Common_Multiple_C79B9258_15F8_4370_8B20_C081108C314A) },
    { be_const_key(Hyperbolic_Tangent, 21), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Tangent_E999922C_6290_493D_A94F_1B367F4A0535) },
    { be_const_key(Arc_Tangent, -1), be_const_ctype_func(Berry_Rational_Class_Arc_Tangent_12B03E49_ED48_43D4_96B3_31DF678A78D0) },
    { be_const_key(Square, -1), be_const_ctype_func(Berry_Rational_Class_Square_A9C02F83_DD87_4C63_A84F_5D9CE681FA60) },
    { be_const_key(Hyperbolic_Arc_Sine, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Arc_Sine_74AB2C14_D7F7_4AF7_AC52_B6F4540C6BC9) },
    { be_const_key(Exponential, -1), be_const_ctype_func(Berry_Rational_Class_Exponential_E7DA63EB_7713_4283_9947_B861A69E4FBC) },
    { be_const_key(Root, -1), be_const_ctype_func(Berry_Rational_Class_Root_34A49F0E_767A_499F_97D5_1FCBBD81A5ED) },
    { be_const_key(Natural_Logarithm, -1), be_const_ctype_func(Berry_Rational_Class_Natural_Logarithm_80B54EAB_8667_4B51_97D8_F1BF3A7E0501) },
    { be_const_key(Get_Numerator, -1), be_const_ctype_func(Berry_Rational_Class_Get_Numerator_C07E1DEA_DFF1_4B62_8E50_75EF7671F5B5) },
    { be_const_key(Logarithm, 0), be_const_ctype_func(Berry_Rational_Class_Logarithm_90DD93A3_EE4D_44B9_A459_B47261C3B1B0) },
    { be_const_key(Get_Denominator, 25), be_const_ctype_func(Berry_Rational_Class_Get_Denominator_E653B2D8_4664_483F_A92A_65756CCF45DC) },
    { be_const_key(Hyperbolic_Arc_Cosine, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Arc_Cosine_A6F2E6A2_8E66_43E9_B84D_AB2AC88B2DDA) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Rational_Class_Initialize_523C99A7_7846_4582_A58D_1C16E984EA3E) },
    { be_const_key(Factorial, 13), be_const_ctype_func(Berry_Rational_Class_Factorial_9A1DCEDF_5B07_4C94_A046_7BDD24077FE8) },
    { be_const_key(Inverse, 1), be_const_ctype_func(Berry_Rational_Class_Inverse_D9ECA4F9_C8DE_47EC_800B_519B27B5430D) },
    { be_const_key(Simplify, -1), be_const_ctype_func(Berry_Rational_Class_Simplify_F0BC2529_92D0_49CF_861A_5D41760A4337) },
    { be_const_key(Square_Root, 7), be_const_ctype_func(Berry_Rational_Class_Square_Root_90534DB2_96CE_4747_BD33_E7AC8C8520C7) },
    { be_const_key(Tangent, -1), be_const_ctype_func(Berry_Rational_Class_Tangent_7F89076E_20B8_46B7_93EC_528D890319E3) },
    { be_const_key(deinit, 32), be_const_ctype_func(Berry_Rational_Class_Deinitialize_392EF017_3381_478F_9BEB_D8808FB6DB28) },
    { be_const_key(Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Sine_182C58D4_20B2_4FC9_AF52_7FFB13A2CD66) },
    { be_const_key(_X3D_X3D, 28), be_const_ctype_func(Berry_Rational_Class_Operator_9D1372ED_1638_44E6_9C76_79D455E8820B) },
    { be_const_key(Cube, 27), be_const_ctype_func(Berry_Rational_Class_Cube_C7BAE034_9D9C_4BDD_BE93_3E3D70132B72) },
    { be_const_key(Binary_Logarithm, -1), be_const_ctype_func(Berry_Rational_Class_Binary_Logarithm_2E09875F_850E_40C8_804F_3A0060D437FF) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Decimal_Logarithm, -1), be_const_ctype_func(Berry_Rational_Class_Decimal_Logarithm_BB76AB09_08CB_4C66_AE1F_93C7729EC85F) },
    { be_const_key(Greatest_Common_Divisor, -1), be_const_ctype_func(Berry_Rational_Class_Greatest_Common_Divisor_6E126B4D_01D2_493E_8A2C_FB6E0F4C8F54) },
    { be_const_key(Cube_Root, 14), be_const_ctype_func(Berry_Rational_Class_Cube_Root_4E8D63D7_21D1_4A38_8F22_85BAB4E54388) },
    { be_const_key(Cosine, 20), be_const_ctype_func(Berry_Rational_Class_Cosine_E5CB0C5F_C3C2_4C91_B9E6_7373D9305C63) },
    { be_const_key(_X21_X3D, 17), be_const_ctype_func(Berry_Rational_Class_Operator_CF9CF63F_A1F3_4E7C_A0E8_8372D496DC01) },
    { be_const_key(Sine, -1), be_const_ctype_func(Berry_Rational_Class_Sine_3ECAA007_E0FC_47B2_96CE_31B55B511E5F) },
    { be_const_key(Arc_Sine, -1), be_const_ctype_func(Berry_Rational_Class_Arc_Sine_E30CEDD0_0469_4D50_B69F_A8DB376843D3) },
    { be_const_key(Power, -1), be_const_ctype_func(Berry_Rational_Class_Power_76261E44_6324_4EF6_9CCC_32422E13B9E0) },
    { be_const_key(Arc_Cosine, 11), be_const_ctype_func(Berry_Rational_Class_Arc_Cosine_46E7B097_71AF_4004_9CD5_981A06BFAA00) },
};

static be_define_const_map(
    Berry_Rational_Type_map,
    36
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Rational_Type,
    1,
    NULL,
    Rational_Type
);
