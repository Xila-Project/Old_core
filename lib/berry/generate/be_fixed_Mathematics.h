#include "be_constobj.h"

static be_define_const_map_slots(m_libMathematics_map) {
    { be_const_key(Message_Digest_SHA_384, 1), be_const_int(7) },
    { be_const_key(Arc_Hyperbolic_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cotangent_62482946_5547_40C8_82E7_4CD6EE2C4EA0) },
    { be_const_key(Is_NAN, 12), be_const_ctype_func(Berry_Mathematics_Class_Is_NAN_14CCE8B3_2EAA_42B9_BC65_30D3CE879A73) },
    { be_const_key(Permutation, -1), be_const_ctype_func(Berry_Mathematics_Class_Permutation_C3C44F5C_545B_43E0_AF29_97EEC753C3CD) },
    { be_const_key(Arc_Hyperbolic_Cosine, 13), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosine_3BC95D78_0E83_464D_9E47_791CDEBA2A9C) },
    { be_const_key(Hyperbolic_Cotangent, 9), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cotangent_D30FA0D0_77EF_43D1_A3D3_55E740BBCBBA) },
    { be_const_key(Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Cotangent_4C2F4B50_7046_4116_9F1C_4254C36D5A58) },
    { be_const_key(Arc_Hyperbolic_Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Tangent_C5818AE0_53B1_47FE_AA50_6B7BF7C23876) },
    { be_const_key(Copy_Sign, -1), be_const_ctype_func(Berry_Mathematics_Class_Copy_Sign_39480D56_19DB_4A65_824F_31E3B04E395A) },
    { be_const_key(Arc_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosecant_F680A1C2_7933_4C95_88FD_FB2A29AF96AD) },
    { be_const_key(Message_Digest_MD_5, 33), be_const_int(3) },
    { be_const_key(Arc_Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Secant_5979B4AA_FB3F_4D34_95B1_7B102D320B25) },
    { be_const_key(Arc_Hyperbolic_Secant, 23), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Secant_38A5E17B_27ED_4634_A787_7D6622F276F1) },
    { be_const_key(Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Sine_3A68D13E_121E_4B99_A3BE_B64EE0D34FCD) },
    { be_const_key(Message_Digest_MD_4, 47), be_const_int(2) },
    { be_const_key(Hyperbolic_Secant, 43), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Secant_21A3DBB1_555B_4C2B_ADFC_1ADE99E20BF2) },
    { be_const_key(Message_Digest_SHA_256, 28), be_const_int(6) },
    { be_const_key(Degrees, 5), be_const_ctype_func(Berry_Mathematics_Class_Degrees_198939D6_80F7_44D7_9408_5518AABFD445) },
    { be_const_key(Message_Digest_MD_2, 37), be_const_int(1) },
    { be_const_key(Real_To_String, -1), be_const_ctype_func(Berry_Mathematics_Class_Real_To_String_A29F338E_35AF_4E71_9577_88D85255DCD7) },
    { be_const_key(Floor, -1), be_const_ctype_func(Berry_Mathematics_Class_Floor_E6DABF81_0E17_4221_8277_616FA9F981AD) },
    { be_const_key(Combination, 10), be_const_ctype_func(Berry_Mathematics_Class_Combination_1B76785B_B593_44C4_B368_F021C21171DD) },
    { be_const_key(Radians, -1), be_const_ctype_func(Berry_Mathematics_Class_Radians_5377A3B4_48C1_4D42_B5A3_CC911A84C2E3) },
    { be_const_key(Arc_Tangent, 41), be_const_ctype_func(Berry_Mathematics_Class_Arc_Tangent_7E707E1E_73C0_4B7A_AA19_62D3DF85BE77) },
    { be_const_key(Arc_Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Sine_2E4A7BEF_068A_416A_8B8B_07BEA3EC8582) },
    { be_const_key(Message_Digest_SHA_1, -1), be_const_int(4) },
    { be_const_key(Arc_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cotangent_346DB4F2_4FEB_4523_BB35_C9E38BD11940) },
    { be_const_key(Is_Infinite, 36), be_const_ctype_func(Berry_Mathematics_Class_Is_Infinite_4F226156_119A_479C_AD99_BC46D899F5C9) },
    { be_const_key(Cosecant, 30), be_const_ctype_func(Berry_Mathematics_Class_Cosecant_32D0AE59_0D7B_4F5C_AA80_D632ADC9054E) },
    { be_const_key(Hash_Type, -1), be_const_class(Berry_Hash_Type) },
    { be_const_key(Message_Digest_MD_None, -1), be_const_int(0) },
    { be_const_key(Hyperbolic_Tangent, 7), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Tangent_98180009_F164_43C2_BC57_E444F680B9EE) },
    { be_const_key(Hyperbolic_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosine_E0B072BE_585F_44BD_80C4_0AE336B6A08E) },
    { be_const_key(Message_Digest_RIPEMD_160, -1), be_const_int(9) },
    { be_const_key(Arc_Sine, 26), be_const_ctype_func(Berry_Mathematics_Class_Arc_Sine_832EA0A2_AD79_4261_B807_DBE99D69AB65) },
    { be_const_key(Message_Digest_SHA_512, -1), be_const_int(8) },
    { be_const_key(Rational_Type, -1), be_const_class(Berry_Rational_Type) },
    { be_const_key(Message_Digest_SHA_224, 29), be_const_int(5) },
    { be_const_key(Arc_Hyperbolic_Cosecant, 20), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosecant_BFB3BE03_F746_472E_911D_C9DB30DDAE8A) },
    { be_const_key(Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Cosine_81691251_5BEB_446C_A589_36DB494FB4BE) },
    { be_const_key(Sine, 15), be_const_ctype_func(Berry_Mathematics_Class_Sine_2BD25383_52B0_4AD3_BC07_4C899C8F5967) },
    { be_const_key(Random, 14), be_const_ctype_func(Berry_Mathematics_Class_Random_8022CCCA_B284_41E1_A495_D0AC9183AF71) },
    { be_const_key(Arc_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosine_9B22F0E0_E856_468A_BB55_0F71A9718C34) },
    { be_const_key(Modulo, -1), be_const_ctype_func(Berry_Mathematics_Class_Modulo_8CB9B621_9A74_4AAB_A841_750B7B17E046) },
    { be_const_key(Hyperbolic_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosecant_C8BA6B2B_8B43_414C_9EE4_FFD885954772) },
    { be_const_key(Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Secant_75D4AA2C_6025_4E50_A1EC_53FC8C1702F3) },
    { be_const_key(String_To_Float, 24), be_const_ctype_func(Berry_Mathematics_Class_String_To_Float_1DB4D51A_A783_4A21_9587_659B16D8AECB) },
    { be_const_key(Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Tangent_A936474C_06BF_412B_B254_ACD85F993B7D) },
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
