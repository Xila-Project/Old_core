#include "be_constobj.h"

static be_define_const_map_slots(m_libMathematics_map) {
    { be_const_key(Message_Digest_SHA_384, 1), be_const_int(7) },
    { be_const_key(Arc_Hyperbolic_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cotangent_8AB89577_3D7D_40B8_85D4_33C97A7AC446) },
    { be_const_key(Is_NAN, 12), be_const_ctype_func(Berry_Mathematics_Class_Is_NAN_3430812B_63CE_454D_AEC5_E235030D2B1D) },
    { be_const_key(Permutation, -1), be_const_ctype_func(Berry_Mathematics_Class_Permutation_31F01078_6C8B_4B5C_A8F8_5ABC5BD7E782) },
    { be_const_key(Arc_Hyperbolic_Cosine, 13), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosine_F548DDC9_D84C_47AC_B42D_AB5E812B2FAD) },
    { be_const_key(Hyperbolic_Cotangent, 9), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cotangent_4CF5CC86_027F_406F_8E60_CC1E7DCA287B) },
    { be_const_key(Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Cotangent_8ED9D663_DA3A_43CF_AFCF_7A14FAB61D85) },
    { be_const_key(Arc_Hyperbolic_Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Tangent_0991DFF3_9041_4AD9_B1FE_3A6AE1E90DB0) },
    { be_const_key(Copy_Sign, -1), be_const_ctype_func(Berry_Mathematics_Class_Copy_Sign_E3BCC1E1_3FA2_4B51_B873_064368E022D6) },
    { be_const_key(Arc_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosecant_D1E1D974_3DBA_4D8E_A6DA_7BBBC1FA3119) },
    { be_const_key(Message_Digest_MD_5, 33), be_const_int(3) },
    { be_const_key(Arc_Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Secant_42D17AF8_D195_479C_A35C_DB9B5253F105) },
    { be_const_key(Arc_Hyperbolic_Secant, 23), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Secant_F918FAF3_2D17_4E0D_B77C_D9094A025AA0) },
    { be_const_key(Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Sine_92096BD0_9774_48BB_B5C0_7DD200D58987) },
    { be_const_key(Message_Digest_MD_4, 47), be_const_int(2) },
    { be_const_key(Hyperbolic_Secant, 43), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Secant_25965ED9_9ECC_42A9_A6C2_A16790FA32AE) },
    { be_const_key(Message_Digest_SHA_256, 28), be_const_int(6) },
    { be_const_key(Degrees, 5), be_const_ctype_func(Berry_Mathematics_Class_Degrees_4476E140_30B1_454E_AC38_927C85359908) },
    { be_const_key(Message_Digest_MD_2, 37), be_const_int(1) },
    { be_const_key(Real_To_String, -1), be_const_ctype_func(Berry_Mathematics_Class_Real_To_String_A9EE4F19_A88F_42A2_8156_E00866D291E1) },
    { be_const_key(Floor, -1), be_const_ctype_func(Berry_Mathematics_Class_Floor_8F8F3915_3034_415F_BD0F_FCC0C7367B52) },
    { be_const_key(Combination, 10), be_const_ctype_func(Berry_Mathematics_Class_Combination_BA9F87CF_E7C2_4AD5_807C_4E653C89A3F9) },
    { be_const_key(Radians, -1), be_const_ctype_func(Berry_Mathematics_Class_Radians_35E8D1BB_038D_4D3B_A6B5_570B217AC3E8) },
    { be_const_key(Arc_Tangent, 41), be_const_ctype_func(Berry_Mathematics_Class_Arc_Tangent_6E78CB6A_B067_4B94_9C37_7E27475F2128) },
    { be_const_key(Arc_Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Sine_661E9DD5_338A_44B1_9891_13B21E1CDF10) },
    { be_const_key(Message_Digest_SHA_1, -1), be_const_int(4) },
    { be_const_key(Arc_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cotangent_87C17CCE_79A9_40F7_8291_5CEE4D5E4D2F) },
    { be_const_key(Is_Infinite, 36), be_const_ctype_func(Berry_Mathematics_Class_Is_Infinite_C7FB2E8E_5FAB_45D7_8157_729A3B52F8F4) },
    { be_const_key(Cosecant, 30), be_const_ctype_func(Berry_Mathematics_Class_Cosecant_72AD071A_46DE_4FC5_B4FE_9AECD330F0CF) },
    { be_const_key(Hash_Type, -1), be_const_class(Berry_Hash_Type) },
    { be_const_key(Message_Digest_MD_None, -1), be_const_int(0) },
    { be_const_key(Hyperbolic_Tangent, 7), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Tangent_7D7C66A8_DF3E_4A79_862F_44949E29F7AB) },
    { be_const_key(Hyperbolic_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosine_5CFA99FB_EEFD_44C1_A43D_3EEEF2D13456) },
    { be_const_key(Message_Digest_RIPEMD_160, -1), be_const_int(9) },
    { be_const_key(Arc_Sine, 26), be_const_ctype_func(Berry_Mathematics_Class_Arc_Sine_ED942FA0_01CD_4C06_9588_9953AA220DF8) },
    { be_const_key(Message_Digest_SHA_512, -1), be_const_int(8) },
    { be_const_key(Rational_Type, -1), be_const_class(Berry_Rational_Type) },
    { be_const_key(Message_Digest_SHA_224, 29), be_const_int(5) },
    { be_const_key(Arc_Hyperbolic_Cosecant, 20), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosecant_E5E28032_5C5D_450C_A709_FBAA6089CFD7) },
    { be_const_key(Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Cosine_F9AA8791_36A4_4509_9E51_56FEDBEF2323) },
    { be_const_key(Sine, 15), be_const_ctype_func(Berry_Mathematics_Class_Sine_11765AAF_3A1D_48A4_BCE7_C3D9C4A962C6) },
    { be_const_key(Random, 14), be_const_ctype_func(Berry_Mathematics_Class_Random_933EC3A7_C7E7_44C7_A106_1C6A2A5C7D2B) },
    { be_const_key(Arc_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosine_639597BA_916E_42F8_A908_ED6D8F3355C0) },
    { be_const_key(Modulo, -1), be_const_ctype_func(Berry_Mathematics_Class_Modulo_7D6FDEED_9981_45F0_AE63_AE1052F8FDFB) },
    { be_const_key(Hyperbolic_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosecant_F0DC5AFE_B294_46DF_B3ED_757602FAF738) },
    { be_const_key(Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Secant_73E459A1_CFEC_48FC_8AEF_91AD05D0C331) },
    { be_const_key(String_To_Float, 24), be_const_ctype_func(Berry_Mathematics_Class_String_To_Float_F08FB6D8_348F_44A6_94F2_36F18FACE3B4) },
    { be_const_key(Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Tangent_BF74D4AF_C12B_494C_9C2F_51C4BDAFF84A) },
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
