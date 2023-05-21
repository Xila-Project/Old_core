#include "be_constobj.h"

static be_define_const_map_slots(m_libMathematics_map) {
    { be_const_key(Message_Digest_SHA_384, 1), be_const_int(7) },
    { be_const_key(Arc_Hyperbolic_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cotangent_CC8CD74B_14D5_4FCB_8107_D68DD9ED94D1) },
    { be_const_key(Is_NAN, 12), be_const_ctype_func(Berry_Mathematics_Class_Is_NAN_47102A56_4BB9_4AB0_B87A_108773EBECB9) },
    { be_const_key(Permutation, -1), be_const_ctype_func(Berry_Mathematics_Class_Permutation_E076BB28_5EDD_44FE_9D98_EA0890D6BF9F) },
    { be_const_key(Arc_Hyperbolic_Cosine, 13), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosine_547BDE72_DFCA_4146_89E6_389469AAFDCB) },
    { be_const_key(Hyperbolic_Cotangent, 9), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cotangent_77681F42_9579_436C_9A95_920C311825B6) },
    { be_const_key(Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Cotangent_CEC11E39_EB66_40FF_9611_5BAAA8DC8B9F) },
    { be_const_key(Arc_Hyperbolic_Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Tangent_D7ABA325_B415_45D2_AEEA_53988007B921) },
    { be_const_key(Copy_Sign, -1), be_const_ctype_func(Berry_Mathematics_Class_Copy_Sign_74591786_D3E7_46A7_8A26_A75659581241) },
    { be_const_key(Arc_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosecant_93ECB196_ECE0_4B8E_BB4F_F3EB9AACF342) },
    { be_const_key(Message_Digest_MD_5, 33), be_const_int(3) },
    { be_const_key(Arc_Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Secant_56F10934_99A5_4237_A6E2_6BBB83307052) },
    { be_const_key(Arc_Hyperbolic_Secant, 23), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Secant_13AF6135_5C16_424C_9BD4_F22130B1E685) },
    { be_const_key(Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Sine_FBFF7E70_C67B_4B48_AC4E_CCD4EB60D40D) },
    { be_const_key(Message_Digest_MD_4, 47), be_const_int(2) },
    { be_const_key(Hyperbolic_Secant, 43), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Secant_789E4950_1F07_4B1E_AFC1_8B85166DE6FD) },
    { be_const_key(Message_Digest_SHA_256, 28), be_const_int(6) },
    { be_const_key(Degrees, 5), be_const_ctype_func(Berry_Mathematics_Class_Degrees_D28C70B2_AA85_4F18_AD96_DF67A2174B7D) },
    { be_const_key(Message_Digest_MD_2, 37), be_const_int(1) },
    { be_const_key(Real_To_String, -1), be_const_ctype_func(Berry_Mathematics_Class_Real_To_String_421957F8_2817_4117_BE68_A7E3C6E790C1) },
    { be_const_key(Floor, -1), be_const_ctype_func(Berry_Mathematics_Class_Floor_D04CB47F_A388_4C3A_BF2E_4348F80E56E4) },
    { be_const_key(Combination, 10), be_const_ctype_func(Berry_Mathematics_Class_Combination_74F03068_FCB2_4590_97A1_95CC551FC54D) },
    { be_const_key(Radians, -1), be_const_ctype_func(Berry_Mathematics_Class_Radians_90E85F8D_63C6_4E0C_855E_04C90E812398) },
    { be_const_key(Arc_Tangent, 41), be_const_ctype_func(Berry_Mathematics_Class_Arc_Tangent_6AD98E4F_D006_4700_BC8E_4B3A4D34644A) },
    { be_const_key(Arc_Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Sine_C60E21FE_50A6_4BDB_B7AC_E473062FCF33) },
    { be_const_key(Message_Digest_SHA_1, -1), be_const_int(4) },
    { be_const_key(Arc_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cotangent_281C46C4_9A2E_4B14_A753_7924E945AD41) },
    { be_const_key(Is_Infinite, 36), be_const_ctype_func(Berry_Mathematics_Class_Is_Infinite_D191B2E5_CB60_4814_A437_9C45FF46A0D3) },
    { be_const_key(Cosecant, 30), be_const_ctype_func(Berry_Mathematics_Class_Cosecant_39EAF173_63E1_433E_97E7_4D764C0AF5FC) },
    { be_const_key(Hash_Type, -1), be_const_class(Berry_Hash_Type) },
    { be_const_key(Message_Digest_MD_None, -1), be_const_int(0) },
    { be_const_key(Hyperbolic_Tangent, 7), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Tangent_DE1DD773_5692_4B9C_AB69_82BE25EEE775) },
    { be_const_key(Hyperbolic_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosine_B78E236B_0774_4405_B3D4_425AE07A5F3F) },
    { be_const_key(Message_Digest_RIPEMD_160, -1), be_const_int(9) },
    { be_const_key(Arc_Sine, 26), be_const_ctype_func(Berry_Mathematics_Class_Arc_Sine_E286E4F9_5CC9_402B_8CC0_E24B3E3A1227) },
    { be_const_key(Message_Digest_SHA_512, -1), be_const_int(8) },
    { be_const_key(Rational_Type, -1), be_const_class(Berry_Rational_Type) },
    { be_const_key(Message_Digest_SHA_224, 29), be_const_int(5) },
    { be_const_key(Arc_Hyperbolic_Cosecant, 20), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosecant_317C60E6_73E8_4335_9802_ED14D3A6E6EC) },
    { be_const_key(Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Cosine_396F00A0_ACAA_4C57_BFAD_17BE1E021355) },
    { be_const_key(Sine, 15), be_const_ctype_func(Berry_Mathematics_Class_Sine_81C3EABE_FAD3_45B5_8CC8_02D9785EA4DB) },
    { be_const_key(Random, 14), be_const_ctype_func(Berry_Mathematics_Class_Random_525C0291_4C41_407F_A920_00E9B31EA8E6) },
    { be_const_key(Arc_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosine_E8B9534A_2AFD_48FE_9EEA_943A50882650) },
    { be_const_key(Modulo, -1), be_const_ctype_func(Berry_Mathematics_Class_Modulo_3F47D232_E48C_433C_83CB_083713BF2A8E) },
    { be_const_key(Hyperbolic_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosecant_647AC865_078F_44DB_B36D_67A5BEC519A2) },
    { be_const_key(Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Secant_CC84FDEF_E703_41A4_B350_740AC15E3E02) },
    { be_const_key(String_To_Float, 24), be_const_ctype_func(Berry_Mathematics_Class_String_To_Float_DB9FA7B0_80D3_44F6_A5DF_FDD45B7DE99C) },
    { be_const_key(Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Tangent_8BC2EEED_3C8C_4C2F_A797_3CA8C8ACD39C) },
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
