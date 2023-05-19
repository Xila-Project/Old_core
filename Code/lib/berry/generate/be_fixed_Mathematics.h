#include "be_constobj.h"

static be_define_const_map_slots(m_libMathematics_map) {
    { be_const_key(Message_Digest_SHA_384, 1), be_const_int(7) },
    { be_const_key(Arc_Hyperbolic_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cotangent_B9CF479A_DE93_494F_B9E3_CC6CB8DF73B8) },
    { be_const_key(Is_NAN, 12), be_const_ctype_func(Berry_Mathematics_Class_Is_NAN_91539E7F_3540_4F9A_A454_7A1EA0D7A79D) },
    { be_const_key(Permutation, -1), be_const_ctype_func(Berry_Mathematics_Class_Permutation_FABA3CCC_6608_4F53_9AD2_529B394BA6D1) },
    { be_const_key(Arc_Hyperbolic_Cosine, 13), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosine_EDBD0063_5C48_41E8_8F9D_65D5B8E5462D) },
    { be_const_key(Hyperbolic_Cotangent, 9), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cotangent_0EF6416D_5BB8_435E_BAF8_589B3EE32322) },
    { be_const_key(Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Cotangent_5BEFC602_CAD9_49CA_AAD5_92CDD6D74201) },
    { be_const_key(Arc_Hyperbolic_Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Tangent_773D309F_F1B0_4CBB_801F_D2C210198052) },
    { be_const_key(Copy_Sign, -1), be_const_ctype_func(Berry_Mathematics_Class_Copy_Sign_C42845A5_493B_40F6_84ED_2AE8DB29182D) },
    { be_const_key(Arc_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosecant_A5236A91_A91C_48F4_8E91_0E0E6873876C) },
    { be_const_key(Message_Digest_MD_5, 33), be_const_int(3) },
    { be_const_key(Arc_Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Secant_CD9FD93D_F900_4552_8809_3EF98E33FED4) },
    { be_const_key(Arc_Hyperbolic_Secant, 23), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Secant_99882751_B9AB_4DDB_901C_006E46ACE8C5) },
    { be_const_key(Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Sine_22D077C3_0113_4850_8679_D08917A37B68) },
    { be_const_key(Message_Digest_MD_4, 47), be_const_int(2) },
    { be_const_key(Hyperbolic_Secant, 43), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Secant_F59F11D4_2D60_4C6E_84C9_9CAE2F3B91C3) },
    { be_const_key(Message_Digest_SHA_256, 28), be_const_int(6) },
    { be_const_key(Degrees, 5), be_const_ctype_func(Berry_Mathematics_Class_Degrees_50CAC945_27E3_4EF7_B76B_F76F2E93C92C) },
    { be_const_key(Message_Digest_MD_2, 37), be_const_int(1) },
    { be_const_key(Real_To_String, -1), be_const_ctype_func(Berry_Mathematics_Class_Real_To_String_26C73E42_67C0_438D_B9EA_C92E5D5C7D3F) },
    { be_const_key(Floor, -1), be_const_ctype_func(Berry_Mathematics_Class_Floor_C4B0DC91_5442_433A_990C_CE0F8FCA66BF) },
    { be_const_key(Combination, 10), be_const_ctype_func(Berry_Mathematics_Class_Combination_C9BB6168_2D40_412C_8206_A8A8A5F31547) },
    { be_const_key(Radians, -1), be_const_ctype_func(Berry_Mathematics_Class_Radians_B4C4CBFD_D34E_45BE_A3E1_49F8B0B0C712) },
    { be_const_key(Arc_Tangent, 41), be_const_ctype_func(Berry_Mathematics_Class_Arc_Tangent_64389135_EA2B_4B7D_AF23_D8E26C411CF7) },
    { be_const_key(Arc_Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Sine_7145170C_6256_4F6B_B1C8_DB77D1D504DF) },
    { be_const_key(Message_Digest_SHA_1, -1), be_const_int(4) },
    { be_const_key(Arc_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cotangent_A2AA2EC5_9937_443B_830E_928EB56FE39A) },
    { be_const_key(Is_Infinite, 36), be_const_ctype_func(Berry_Mathematics_Class_Is_Infinite_FF2AA86B_FA23_483F_AF7E_02CC2775B233) },
    { be_const_key(Cosecant, 30), be_const_ctype_func(Berry_Mathematics_Class_Cosecant_89BE1CC2_209B_409A_9D36_6EA48FD25E34) },
    { be_const_key(Hash_Type, -1), be_const_class(Berry_Hash_Type) },
    { be_const_key(Message_Digest_MD_None, -1), be_const_int(0) },
    { be_const_key(Hyperbolic_Tangent, 7), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Tangent_A9E52A5A_B102_49E9_8ADD_D8A71F77FE69) },
    { be_const_key(Hyperbolic_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosine_F83DD113_57CA_46B6_ACEC_3ADB1EB8E657) },
    { be_const_key(Message_Digest_RIPEMD_160, -1), be_const_int(9) },
    { be_const_key(Arc_Sine, 26), be_const_ctype_func(Berry_Mathematics_Class_Arc_Sine_96140F12_2485_4F8B_8AC4_1EA1E0F10C2E) },
    { be_const_key(Message_Digest_SHA_512, -1), be_const_int(8) },
    { be_const_key(Rational_Type, -1), be_const_class(Berry_Rational_Type) },
    { be_const_key(Message_Digest_SHA_224, 29), be_const_int(5) },
    { be_const_key(Arc_Hyperbolic_Cosecant, 20), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosecant_5A2CCCE5_3544_407E_ADAE_CF00947254D2) },
    { be_const_key(Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Cosine_2A710703_3748_4D13_A3F8_7A9E3BA0CF5C) },
    { be_const_key(Sine, 15), be_const_ctype_func(Berry_Mathematics_Class_Sine_A69817DA_C503_4DEA_BDCC_EFDDA9F0AEB9) },
    { be_const_key(Random, 14), be_const_ctype_func(Berry_Mathematics_Class_Random_38C7408A_DD61_4D90_97BD_B23540A8E87D) },
    { be_const_key(Arc_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosine_3AFD64F4_D054_4A32_A0E2_91983839F2A0) },
    { be_const_key(Modulo, -1), be_const_ctype_func(Berry_Mathematics_Class_Modulo_563189F9_5300_4451_B6E7_C0E499AB04F0) },
    { be_const_key(Hyperbolic_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosecant_140620EA_FE23_46ED_9775_A671DF1F9E94) },
    { be_const_key(Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Secant_524183DD_C65A_44FD_B978_2F1820A7F434) },
    { be_const_key(String_To_Float, 24), be_const_ctype_func(Berry_Mathematics_Class_String_To_Float_2AEDD9E1_F2D8_4E55_9BA1_7C648B350DE1) },
    { be_const_key(Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Tangent_FCFE87BA_D4DB_4F19_BF04_E8B61E374982) },
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
