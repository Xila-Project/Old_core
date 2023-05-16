#include "be_constobj.h"

static be_define_const_map_slots(m_libMathematics_map) {
    { be_const_key(Message_Digest_SHA_384, 1), be_const_int(7) },
    { be_const_key(Arc_Hyperbolic_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cotangent_E2BEA786_3319_4D3E_8B2A_700D756961F2) },
    { be_const_key(Is_NAN, 12), be_const_ctype_func(Berry_Mathematics_Class_Is_NAN_99568017_89DF_4E6C_BA8B_634CDAE0062B) },
    { be_const_key(Permutation, -1), be_const_ctype_func(Berry_Mathematics_Class_Permutation_AE8C8ECB_260D_4841_B4B7_B2D83D05182B) },
    { be_const_key(Arc_Hyperbolic_Cosine, 47), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosine_68862855_6CAE_47E2_AB5B_1CBF72CEC3E4) },
    { be_const_key(Hyperbolic_Cotangent, 28), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cotangent_7725AB6D_34F0_419B_AB1B_B35C16858566) },
    { be_const_key(Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Cotangent_14700F16_9C4E_4F6A_89FF_2F07531BF640) },
    { be_const_key(Arc_Hyperbolic_Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Tangent_979A785C_E50F_4790_8616_917F784E1707) },
    { be_const_key(Copy_Sign, -1), be_const_ctype_func(Berry_Mathematics_Class_Copy_Sign_18BB8A40_FDB9_41C0_B963_9FA4DE0E642A) },
    { be_const_key(Floor, -1), be_const_ctype_func(Berry_Mathematics_Class_Floor_560E178A_AFEA_45F5_8DC1_CA702F66503D) },
    { be_const_key(Message_Digest_MD_5, 30), be_const_int(3) },
    { be_const_key(Arc_Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Secant_E1E7204D_1F03_45D7_B9E3_C61763EE3C76) },
    { be_const_key(Arc_Hyperbolic_Secant, 19), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Secant_74DD6103_DB67_4C73_A8C6_E9F5F61B2F80) },
    { be_const_key(Float_To_String, -1), be_const_ctype_func(Berry_Mathematics_Class_Float_To_String_D7E8C2A4_ED80_4A47_B30E_425936B49007) },
    { be_const_key(Hyperbolic_Secant, 24), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Secant_DC6CCE8C_A0DA_409B_8E15_818F9F0BBD22) },
    { be_const_key(Random, 41), be_const_ctype_func(Berry_Mathematics_Class_Random_D5598526_F81C_4D4E_966D_BE6955C7CBD6) },
    { be_const_key(Message_Digest_SHA_256, 26), be_const_int(6) },
    { be_const_key(Degrees, 5), be_const_ctype_func(Berry_Mathematics_Class_Degrees_2C3D44CD_FD0B_4AE8_A65F_C4C2FDECBFD2) },
    { be_const_key(Message_Digest_MD_2, 36), be_const_int(1) },
    { be_const_key(Arc_Tangent, 15), be_const_ctype_func(Berry_Mathematics_Class_Arc_Tangent_CBE53F4E_E592_400F_A215_EC6A0C6AD0B9) },
    { be_const_key(Arc_Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Sine_C575296D_EFBB_4834_B6EF_DEB04533A18F) },
    { be_const_key(Combination, 10), be_const_ctype_func(Berry_Mathematics_Class_Combination_61AD7BE1_628C_44A4_A78F_AEAA4DEBC086) },
    { be_const_key(Radians, 13), be_const_ctype_func(Berry_Mathematics_Class_Radians_B0B7BE6F_2358_43C5_AD06_4FDB710B8485) },
    { be_const_key(Arc_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cotangent_58058C1B_6945_4B2B_B541_B4C3C61B7C32) },
    { be_const_key(Modulo, -1), be_const_ctype_func(Berry_Mathematics_Class_Modulo_74D8C39C_C379_4401_9A33_C3F0DAB00D7C) },
    { be_const_key(Message_Digest_SHA_1, -1), be_const_int(4) },
    { be_const_key(Cosecant, 29), be_const_ctype_func(Berry_Mathematics_Class_Cosecant_E208FEF6_78B5_44CE_973F_3B7B54F97835) },
    { be_const_key(Is_Infinite, 33), be_const_ctype_func(Berry_Mathematics_Class_Is_Infinite_09026920_EC70_49BD_A942_22AA8ADCD8F0) },
    { be_const_key(Arc_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosecant_515C1E09_90BA_44F3_A8DB_2F91DEDD07B5) },
    { be_const_key(Message_Digest_MD_None, -1), be_const_int(0) },
    { be_const_key(Message_Digest_RIPEMD_160, -1), be_const_int(9) },
    { be_const_key(Hyperbolic_Tangent, 7), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Tangent_E5DF26B4_99F1_4004_900E_7AEBA35B3F9F) },
    { be_const_key(Hyperbolic_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosine_2EE0E5EB_6B1C_4EE9_B8DB_A67343FF8002) },
    { be_const_key(Rational_Type, -1), be_const_class(Berry_Rational_Type) },
    { be_const_key(Arc_Sine, 23), be_const_ctype_func(Berry_Mathematics_Class_Arc_Sine_6A4A76C7_F581_4292_AB76_1D09334823D3) },
    { be_const_key(Message_Digest_SHA_512, -1), be_const_int(8) },
    { be_const_key(Message_Digest_SHA_224, 37), be_const_int(5) },
    { be_const_key(Hash_Type, -1), be_const_class(Berry_Hash_Type) },
    { be_const_key(Arc_Hyperbolic_Cosecant, 9), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosecant_21AA9CCC_7630_43FB_938D_E1B066DC8223) },
    { be_const_key(Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Cosine_46E924C3_A49C_401F_A619_C4196692BF76) },
    { be_const_key(Sine, 14), be_const_ctype_func(Berry_Mathematics_Class_Sine_29744054_7BD3_4D80_A55D_4E4B0E0FC782) },
    { be_const_key(Message_Digest_MD_4, 43), be_const_int(2) },
    { be_const_key(Arc_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosine_36AA6B05_DFAA_471D_BAA2_9656CAB80DE7) },
    { be_const_key(Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Tangent_483B685B_7E65_48F4_95C4_E607EDF84932) },
    { be_const_key(Hyperbolic_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosecant_2C0835FC_C1C9_439C_B37B_CEE3951347CF) },
    { be_const_key(Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Secant_68E61126_56DE_4B74_A5AE_AE41E3C174E5) },
    { be_const_key(String_To_Float, 20), be_const_ctype_func(Berry_Mathematics_Class_String_To_Float_2EF6B041_9B6C_40BB_B4A9_DF3A7BDF4227) },
    { be_const_key(Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Sine_A0D7A469_002C_40D5_8EA0_53A9E060679F) },
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
