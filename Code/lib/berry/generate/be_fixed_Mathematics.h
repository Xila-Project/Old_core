#include "be_constobj.h"

static be_define_const_map_slots(m_libMathematics_map) {
    { be_const_key(Message_Digest_SHA_384, 1), be_const_int(7) },
    { be_const_key(Arc_Hyperbolic_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cotangent_B66C352C_6EAE_4D89_B209_BD856FE3685A) },
    { be_const_key(Is_NAN, 12), be_const_ctype_func(Berry_Mathematics_Class_Is_NAN_6AB02028_1FB1_4EB5_8DDE_41ADF48EB8A3) },
    { be_const_key(Permutation, -1), be_const_ctype_func(Berry_Mathematics_Class_Permutation_A061E435_C6A1_4803_8C63_2260F84DA59B) },
    { be_const_key(Arc_Hyperbolic_Cosine, 47), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosine_2FB3A0D6_A388_484D_80C3_86C9FC3DC528) },
    { be_const_key(Hyperbolic_Cotangent, 28), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cotangent_C7B53E8F_7CB5_4C7A_A825_510A3ABD8AAB) },
    { be_const_key(Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Cotangent_451939EA_398C_49AC_B4D1_B598F72E5D5C) },
    { be_const_key(Arc_Hyperbolic_Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Tangent_901EBEA7_016D_4C30_AFD5_076E10F61470) },
    { be_const_key(Copy_Sign, -1), be_const_ctype_func(Berry_Mathematics_Class_Copy_Sign_97C139DC_C0E7_4591_87F5_0E73D7F02669) },
    { be_const_key(Floor, -1), be_const_ctype_func(Berry_Mathematics_Class_Floor_999D4EA5_E9E8_47C3_8E32_19F61ACA3277) },
    { be_const_key(Message_Digest_MD_5, 30), be_const_int(3) },
    { be_const_key(Arc_Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Secant_95B4D99B_CCEB_4E2A_968F_43C7BEB9B3E1) },
    { be_const_key(Arc_Hyperbolic_Secant, 19), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Secant_96C11CF1_369E_40D7_A34E_545CEF333855) },
    { be_const_key(Float_To_String, -1), be_const_ctype_func(Berry_Mathematics_Class_Float_To_String_37044524_3205_4EED_B214_9E8D0D28F4B2) },
    { be_const_key(Hyperbolic_Secant, 24), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Secant_8B37469B_39C6_479E_8890_08373DD680FE) },
    { be_const_key(Random, 41), be_const_ctype_func(Berry_Mathematics_Class_Random_9C80CF4F_5A33_410F_A56C_FDFEA9ACAD6C) },
    { be_const_key(Message_Digest_SHA_256, 26), be_const_int(6) },
    { be_const_key(Degrees, 5), be_const_ctype_func(Berry_Mathematics_Class_Degrees_093A501F_FBCB_4127_BA78_D37EB40B327C) },
    { be_const_key(Message_Digest_MD_2, 36), be_const_int(1) },
    { be_const_key(Arc_Tangent, 15), be_const_ctype_func(Berry_Mathematics_Class_Arc_Tangent_2AF005D8_9E20_4F8E_8C2D_CC0A4AEC8993) },
    { be_const_key(Arc_Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Sine_85293700_73A3_4126_B24F_41C3714524B2) },
    { be_const_key(Combination, 10), be_const_ctype_func(Berry_Mathematics_Class_Combination_01E1D3DC_3217_45CA_BFFA_D50904FBBDF1) },
    { be_const_key(Radians, 13), be_const_ctype_func(Berry_Mathematics_Class_Radians_66FA50C1_0664_4CC9_87CC_B392C86C079A) },
    { be_const_key(Arc_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cotangent_F1793E3F_2078_4D02_B95F_75409106DD1D) },
    { be_const_key(Modulo, -1), be_const_ctype_func(Berry_Mathematics_Class_Modulo_2D8D0262_AB08_40E3_83AF_3CB198C024ED) },
    { be_const_key(Message_Digest_SHA_1, -1), be_const_int(4) },
    { be_const_key(Cosecant, 29), be_const_ctype_func(Berry_Mathematics_Class_Cosecant_F253A828_19BA_4B92_908C_9899D18A8D00) },
    { be_const_key(Is_Infinite, 33), be_const_ctype_func(Berry_Mathematics_Class_Is_Infinite_369AAF83_65E8_45C0_A428_862ECE44E72C) },
    { be_const_key(Arc_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosecant_DDFD151F_6942_4EB3_BA59_1C43D153BD9D) },
    { be_const_key(Message_Digest_MD_None, -1), be_const_int(0) },
    { be_const_key(Message_Digest_RIPEMD_160, -1), be_const_int(9) },
    { be_const_key(Hyperbolic_Tangent, 7), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Tangent_49720708_5F1C_411E_B0B6_19FBE11D6196) },
    { be_const_key(Hyperbolic_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosine_29D640B4_425D_440F_B6EA_492AADCD9CC2) },
    { be_const_key(Rational_Type, -1), be_const_class(Berry_Rational_Type) },
    { be_const_key(Arc_Sine, 23), be_const_ctype_func(Berry_Mathematics_Class_Arc_Sine_A7BA6115_D856_4AC1_80D1_5CDE06F909C7) },
    { be_const_key(Message_Digest_SHA_512, -1), be_const_int(8) },
    { be_const_key(Message_Digest_SHA_224, 37), be_const_int(5) },
    { be_const_key(Hash_Type, -1), be_const_class(Berry_Hash_Type) },
    { be_const_key(Arc_Hyperbolic_Cosecant, 9), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosecant_55D9259F_525A_47D2_8C26_5012A520F7C2) },
    { be_const_key(Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Cosine_CD5B755B_EDBE_4658_AE32_E60265A2A604) },
    { be_const_key(Sine, 14), be_const_ctype_func(Berry_Mathematics_Class_Sine_507786E6_D709_4CC3_8028_D6338356E078) },
    { be_const_key(Message_Digest_MD_4, 43), be_const_int(2) },
    { be_const_key(Arc_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosine_92FE9098_24C9_4DB1_AC48_B00F93EB9BC9) },
    { be_const_key(Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Tangent_9B9AF218_B8CA_43DE_8D8A_D90C7DD30F3F) },
    { be_const_key(Hyperbolic_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosecant_A9960325_DCFB_4297_BC1F_06768469BCCC) },
    { be_const_key(Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Secant_96935CA6_8B45_45B2_B9C3_1CD7F190CCC6) },
    { be_const_key(String_To_Float, 20), be_const_ctype_func(Berry_Mathematics_Class_String_To_Float_7CCBC2FE_0E8A_480D_BF24_F771289B4E59) },
    { be_const_key(Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Sine_FE9AEDED_16AF_4DDF_84CE_1549B949918F) },
    { be_const_key(Get_Pointer, -1), be_const_ctype_func(Berry_Mathematics_Class_Get_Pointer) },
};

static be_define_const_map(
    m_libMathematics_map,
    49
);

static be_define_const_module(
    m_libMathematics,
    "Mathematics"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Mathematics);
