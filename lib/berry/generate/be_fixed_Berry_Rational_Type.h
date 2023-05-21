#include "be_constobj.h"

static be_define_const_map_slots(Berry_Rational_Type_map) {
    { be_const_key(Hyperbolic_Cosine, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Cosine_BC5FDEA5_4C5A_407D_B6FF_6657FAFED1F4) },
    { be_const_key(Hyperbolic_Arc_Tangent, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Arc_Tangent_2D76FDC1_A0CB_4B8D_A376_532C638A8CCC) },
    { be_const_key(Absolute_Value, -1), be_const_ctype_func(Berry_Rational_Class_Absolute_Value_F1C30237_2519_4D52_9294_6B1C76E1ECE9) },
    { be_const_key(Least_Common_Multiple, -1), be_const_ctype_func(Berry_Rational_Class_Least_Common_Multiple_578A7FD7_9938_44A6_995B_E29BCC8EB3F2) },
    { be_const_key(Hyperbolic_Tangent, 21), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Tangent_56444C5C_5163_4507_9F71_5B87A9088A34) },
    { be_const_key(Arc_Tangent, -1), be_const_ctype_func(Berry_Rational_Class_Arc_Tangent_8E74C90E_DDD9_417B_B2B1_FF8E5AB7B938) },
    { be_const_key(Square, -1), be_const_ctype_func(Berry_Rational_Class_Square_B8424122_4408_445F_A6A6_6B3E1B4A8E0B) },
    { be_const_key(Hyperbolic_Arc_Sine, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Arc_Sine_803A47C0_9D87_4279_865A_633CB004B8D8) },
    { be_const_key(Exponential, -1), be_const_ctype_func(Berry_Rational_Class_Exponential_F5F2F210_38D0_4BD9_AC3E_EBAFA17DE043) },
    { be_const_key(Root, -1), be_const_ctype_func(Berry_Rational_Class_Root_A7367957_B48D_4FC2_A56C_2495013CCA85) },
    { be_const_key(Natural_Logarithm, -1), be_const_ctype_func(Berry_Rational_Class_Natural_Logarithm_C64E8712_3D19_46C9_81F7_9ABB3591095C) },
    { be_const_key(Get_Numerator, -1), be_const_ctype_func(Berry_Rational_Class_Get_Numerator_FBA61F7F_7E42_4987_8503_B5D9684DE045) },
    { be_const_key(Logarithm, 0), be_const_ctype_func(Berry_Rational_Class_Logarithm_5F50F0E1_99DF_4C1B_A76B_4AD15B0439EF) },
    { be_const_key(Get_Denominator, 25), be_const_ctype_func(Berry_Rational_Class_Get_Denominator_7D2B6D23_640D_42EC_937F_AC5DE34CEDCD) },
    { be_const_key(Hyperbolic_Arc_Cosine, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Arc_Cosine_C17D76D5_300C_44BF_A102_A6E3C79C9383) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Rational_Class_Initialize_7A82BF78_98F8_427D_AD56_85F464167153) },
    { be_const_key(Factorial, 13), be_const_ctype_func(Berry_Rational_Class_Factorial_1F447DFD_22B7_49DD_A386_1AF1FE6D7A76) },
    { be_const_key(Inverse, 1), be_const_ctype_func(Berry_Rational_Class_Inverse_E3ECC064_94C8_4F8F_B98A_1DEB50C48F0F) },
    { be_const_key(Simplify, -1), be_const_ctype_func(Berry_Rational_Class_Simplify_5D070C2A_E218_4D7B_BC93_5DE0828BC131) },
    { be_const_key(Square_Root, 7), be_const_ctype_func(Berry_Rational_Class_Square_Root_23FD44CF_189B_4EB3_B7FC_1F2B0671555C) },
    { be_const_key(Tangent, -1), be_const_ctype_func(Berry_Rational_Class_Tangent_A87E360A_8A31_4CA7_9C90_875A687EE4B5) },
    { be_const_key(deinit, 32), be_const_ctype_func(Berry_Rational_Class_Deinitialize_BC11A816_AF6F_4D00_AF70_5BBC65B2BB8A) },
    { be_const_key(Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Sine_D20A7E3B_57EF_4B2A_B84E_20F33A0E9030) },
    { be_const_key(_X3D_X3D, 28), be_const_ctype_func(Berry_Rational_Class_Operator_CF0BD43C_A6C3_4F76_88B0_98482EC75127) },
    { be_const_key(Cube, 27), be_const_ctype_func(Berry_Rational_Class_Cube_029D882F_4ABB_44AA_8C6E_CEEA2D11DBF2) },
    { be_const_key(Binary_Logarithm, -1), be_const_ctype_func(Berry_Rational_Class_Binary_Logarithm_D7C907AC_578B_42E9_A27A_560F08C27953) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Decimal_Logarithm, -1), be_const_ctype_func(Berry_Rational_Class_Decimal_Logarithm_F353739E_9643_4E4D_A6A9_4E7FC9C11B56) },
    { be_const_key(Greatest_Common_Divisor, -1), be_const_ctype_func(Berry_Rational_Class_Greatest_Common_Divisor_ED518120_5615_485D_8B96_49582ED63D12) },
    { be_const_key(Cube_Root, 14), be_const_ctype_func(Berry_Rational_Class_Cube_Root_BCA0313C_81D2_4E21_83C5_7A104239282E) },
    { be_const_key(Cosine, 20), be_const_ctype_func(Berry_Rational_Class_Cosine_AE09E93E_8FD2_49D0_91CA_049C55D8364E) },
    { be_const_key(_X21_X3D, 17), be_const_ctype_func(Berry_Rational_Class_Operator_4A294321_9FA8_4337_B93B_6D2AFFF26394) },
    { be_const_key(Sine, -1), be_const_ctype_func(Berry_Rational_Class_Sine_FA643E66_2C3B_42F8_9925_E9E0FFAF7943) },
    { be_const_key(Arc_Sine, -1), be_const_ctype_func(Berry_Rational_Class_Arc_Sine_B68EDE33_F905_4A97_B6D3_2D17CD7FACEA) },
    { be_const_key(Power, -1), be_const_ctype_func(Berry_Rational_Class_Power_897D8183_1575_4F20_ACD8_7D06F64828FD) },
    { be_const_key(Arc_Cosine, 11), be_const_ctype_func(Berry_Rational_Class_Arc_Cosine_AFF80848_32A0_4944_8F87_DDE9FD07A761) },
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
