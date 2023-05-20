#include "be_constobj.h"

static be_define_const_map_slots(m_libMathematics_map) {
    { be_const_key(Message_Digest_SHA_384, 1), be_const_int(7) },
    { be_const_key(Arc_Hyperbolic_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cotangent_B8C66A97_25D2_4D35_83DC_3093F3B1A564) },
    { be_const_key(Is_NAN, 12), be_const_ctype_func(Berry_Mathematics_Class_Is_NAN_9DA82679_E54C_4AC5_9D86_81EA7C6E2A83) },
    { be_const_key(Permutation, -1), be_const_ctype_func(Berry_Mathematics_Class_Permutation_5D636B4D_48DA_4274_8A5A_0B2E3A895FAD) },
    { be_const_key(Arc_Hyperbolic_Cosine, 13), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosine_7FE44E67_0E0B_4C09_B176_9898DF2055C1) },
    { be_const_key(Hyperbolic_Cotangent, 9), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cotangent_76FBB23D_C4DD_4C6E_B335_7FA1D9029226) },
    { be_const_key(Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Cotangent_9566B043_B53A_4280_AC55_54D0E552B6A3) },
    { be_const_key(Arc_Hyperbolic_Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Tangent_0B68D691_E8D5_4D1E_BBB9_086F5325BD2D) },
    { be_const_key(Copy_Sign, -1), be_const_ctype_func(Berry_Mathematics_Class_Copy_Sign_2BE41653_2455_4EF9_BE70_BAADE51EBA5A) },
    { be_const_key(Arc_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosecant_868A0D0E_65CF_4D64_B9B5_7964477873DA) },
    { be_const_key(Message_Digest_MD_5, 33), be_const_int(3) },
    { be_const_key(Arc_Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Secant_616A92C5_F952_42DE_BC13_CC52D42B3925) },
    { be_const_key(Arc_Hyperbolic_Secant, 23), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Secant_388EF2E3_8F60_4662_AF41_D253B73414CA) },
    { be_const_key(Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Sine_0A4E11B4_037D_4380_87F8_977A14CCF2B0) },
    { be_const_key(Message_Digest_MD_4, 47), be_const_int(2) },
    { be_const_key(Hyperbolic_Secant, 43), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Secant_828B8EBC_5454_4716_A255_9903F1FB218A) },
    { be_const_key(Message_Digest_SHA_256, 28), be_const_int(6) },
    { be_const_key(Degrees, 5), be_const_ctype_func(Berry_Mathematics_Class_Degrees_AA9BEDB3_C8D9_42F5_B70B_1833C5471C94) },
    { be_const_key(Message_Digest_MD_2, 37), be_const_int(1) },
    { be_const_key(Real_To_String, -1), be_const_ctype_func(Berry_Mathematics_Class_Real_To_String_570946EF_9E8F_4A99_953A_36BD5619FDB1) },
    { be_const_key(Floor, -1), be_const_ctype_func(Berry_Mathematics_Class_Floor_C904AFD3_EA2B_41E5_92B9_5198C1234C9D) },
    { be_const_key(Combination, 10), be_const_ctype_func(Berry_Mathematics_Class_Combination_DB104B5D_1772_49E4_A30B_09DF46B017FB) },
    { be_const_key(Radians, -1), be_const_ctype_func(Berry_Mathematics_Class_Radians_433D3E8B_3207_4A0F_91F6_250DFB3664B4) },
    { be_const_key(Arc_Tangent, 41), be_const_ctype_func(Berry_Mathematics_Class_Arc_Tangent_49DCB705_23F1_43F9_9889_94BAC75B710E) },
    { be_const_key(Arc_Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Sine_8E320856_E78B_4BF7_A4A9_03569D8D2225) },
    { be_const_key(Message_Digest_SHA_1, -1), be_const_int(4) },
    { be_const_key(Arc_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cotangent_2F26422D_DD54_4AA8_A676_828EC7E10BA3) },
    { be_const_key(Is_Infinite, 36), be_const_ctype_func(Berry_Mathematics_Class_Is_Infinite_FE85F358_65AD_4E85_91DC_F5FB344C2677) },
    { be_const_key(Cosecant, 30), be_const_ctype_func(Berry_Mathematics_Class_Cosecant_94EA114D_4A1C_486A_9F52_709C12F72846) },
    { be_const_key(Hash_Type, -1), be_const_class(Berry_Hash_Type) },
    { be_const_key(Message_Digest_MD_None, -1), be_const_int(0) },
    { be_const_key(Hyperbolic_Tangent, 7), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Tangent_7BD5CA83_E3D0_4259_B3DF_83E66711DBF6) },
    { be_const_key(Hyperbolic_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosine_61FB1EA4_9021_43A3_B606_462C8215B37D) },
    { be_const_key(Message_Digest_RIPEMD_160, -1), be_const_int(9) },
    { be_const_key(Arc_Sine, 26), be_const_ctype_func(Berry_Mathematics_Class_Arc_Sine_1E5133BD_BEC3_4698_9F17_1CBC21C1146D) },
    { be_const_key(Message_Digest_SHA_512, -1), be_const_int(8) },
    { be_const_key(Rational_Type, -1), be_const_class(Berry_Rational_Type) },
    { be_const_key(Message_Digest_SHA_224, 29), be_const_int(5) },
    { be_const_key(Arc_Hyperbolic_Cosecant, 20), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosecant_A9781E80_F076_432D_AEC8_07ABC65024B4) },
    { be_const_key(Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Cosine_2201CE91_D5EE_4F1A_AB64_D0F84E7E3198) },
    { be_const_key(Sine, 15), be_const_ctype_func(Berry_Mathematics_Class_Sine_AE6E7EE2_6B36_4C68_B933_04287F76CD4B) },
    { be_const_key(Random, 14), be_const_ctype_func(Berry_Mathematics_Class_Random_48FFE94C_60F1_48F6_9CA6_5D51E556D4DA) },
    { be_const_key(Arc_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosine_7E8E6990_C553_4F98_99D3_1B83AB4DF2CC) },
    { be_const_key(Modulo, -1), be_const_ctype_func(Berry_Mathematics_Class_Modulo_8F696478_BF73_446F_920D_95F59C81F23A) },
    { be_const_key(Hyperbolic_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosecant_C144FA47_5538_48BF_AEC1_F8945059373D) },
    { be_const_key(Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Secant_F8636763_D2FC_4BFC_8773_0F7441F0CCC9) },
    { be_const_key(String_To_Float, 24), be_const_ctype_func(Berry_Mathematics_Class_String_To_Float_0F591B61_1C38_46F1_9014_D7EDF9344F1F) },
    { be_const_key(Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Tangent_F89EFA64_8962_45F0_9611_2B525369BC3F) },
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
