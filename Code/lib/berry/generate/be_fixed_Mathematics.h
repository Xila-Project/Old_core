#include "be_constobj.h"

static be_define_const_map_slots(m_libMathematics_map) {
    { be_const_key(Message_Digest_SHA_384, 1), be_const_int(7) },
    { be_const_key(Arc_Hyperbolic_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cotangent_7061CC7C_85AF_4957_A2BE_E223631215BA) },
    { be_const_key(Is_NAN, 12), be_const_ctype_func(Berry_Mathematics_Class_Is_NAN_AFA71828_4AAB_4A98_84BF_F4F02141206A) },
    { be_const_key(Permutation, -1), be_const_ctype_func(Berry_Mathematics_Class_Permutation_0C123E92_D9AD_40E6_BA60_4DEF74159CF7) },
    { be_const_key(Arc_Hyperbolic_Cosine, 47), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosine_9B739376_A3C2_4521_9CEC_27C02757BB75) },
    { be_const_key(Hyperbolic_Cotangent, 28), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cotangent_0F8F41D0_499A_482A_A4F3_2D4EEBB3E387) },
    { be_const_key(Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Cotangent_917BBE5E_8E54_423F_A09B_1EE057D9B6ED) },
    { be_const_key(Arc_Hyperbolic_Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Tangent_9E8286E4_D24C_411A_8853_F5C0AB2EA1F5) },
    { be_const_key(Copy_Sign, -1), be_const_ctype_func(Berry_Mathematics_Class_Copy_Sign_3F298A80_14A9_4F0B_A7E1_9F409F5BD94D) },
    { be_const_key(Floor, -1), be_const_ctype_func(Berry_Mathematics_Class_Floor_1B28E13D_1B8E_45D8_A192_A42E36F81762) },
    { be_const_key(Message_Digest_MD_5, 30), be_const_int(3) },
    { be_const_key(Arc_Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Secant_A13F2C62_3DB9_429A_825D_08C5B85A3EAA) },
    { be_const_key(Arc_Hyperbolic_Secant, 19), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Secant_8DF97718_B6F9_4E48_A36E_2B01E792FE2E) },
    { be_const_key(Float_To_String, -1), be_const_ctype_func(Berry_Mathematics_Class_Float_To_String_53941FDA_4F0B_4190_888F_EA7F36FC61D6) },
    { be_const_key(Hyperbolic_Secant, 24), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Secant_7158479E_4E03_4ADD_8565_E6CE2608C66B) },
    { be_const_key(Random, 41), be_const_ctype_func(Berry_Mathematics_Class_Random_0A60A102_10A4_449B_94AD_A47C4D38836F) },
    { be_const_key(Message_Digest_SHA_256, 26), be_const_int(6) },
    { be_const_key(Degrees, 5), be_const_ctype_func(Berry_Mathematics_Class_Degrees_B93D9654_0851_4422_9EF7_B671031207C6) },
    { be_const_key(Message_Digest_MD_2, 36), be_const_int(1) },
    { be_const_key(Arc_Tangent, 15), be_const_ctype_func(Berry_Mathematics_Class_Arc_Tangent_9E5EA050_D45A_4EB5_B1BE_69A2E31DD189) },
    { be_const_key(Arc_Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Sine_1D25D963_27B2_4E47_B673_EFB97DFAA65B) },
    { be_const_key(Combination, 10), be_const_ctype_func(Berry_Mathematics_Class_Combination_4F0193C5_13A0_4B27_AB03_58374A416758) },
    { be_const_key(Radians, 13), be_const_ctype_func(Berry_Mathematics_Class_Radians_D5EED028_3714_425D_8EA6_500BA28580B9) },
    { be_const_key(Arc_Cotangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cotangent_FF0786FF_177C_4426_BB3E_0EC25AA9E2B6) },
    { be_const_key(Modulo, -1), be_const_ctype_func(Berry_Mathematics_Class_Modulo_8F8D1577_690C_4817_B2FD_489545747BEE) },
    { be_const_key(Message_Digest_SHA_1, -1), be_const_int(4) },
    { be_const_key(Cosecant, 29), be_const_ctype_func(Berry_Mathematics_Class_Cosecant_464D475B_0613_4951_B322_DC0FB1B2E209) },
    { be_const_key(Is_Infinite, 33), be_const_ctype_func(Berry_Mathematics_Class_Is_Infinite_49540EBE_CFD5_423F_9250_D0E1E53FD9C5) },
    { be_const_key(Arc_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosecant_2F231ECD_E89C_4A1A_8EC6_5188A7EAEAAA) },
    { be_const_key(Message_Digest_MD_None, -1), be_const_int(0) },
    { be_const_key(Message_Digest_RIPEMD_160, -1), be_const_int(9) },
    { be_const_key(Hyperbolic_Tangent, 7), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Tangent_ED0E281B_6198_491E_A864_E1EA58C7325C) },
    { be_const_key(Hyperbolic_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosine_0B7FF947_57B4_4029_89AC_3E8A19CF9203) },
    { be_const_key(Rational_Type, -1), be_const_class(Berry_Rational_Type) },
    { be_const_key(Arc_Sine, 23), be_const_ctype_func(Berry_Mathematics_Class_Arc_Sine_3ED9DCC1_EE03_4C00_8F7C_8B8A2666E759) },
    { be_const_key(Message_Digest_SHA_512, -1), be_const_int(8) },
    { be_const_key(Message_Digest_SHA_224, 37), be_const_int(5) },
    { be_const_key(Hash_Type, -1), be_const_class(Berry_Hash_Type) },
    { be_const_key(Arc_Hyperbolic_Cosecant, 9), be_const_ctype_func(Berry_Mathematics_Class_Arc_Hyperbolic_Cosecant_3B06B042_3878_4CE4_84EE_E56A47075E0A) },
    { be_const_key(Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Cosine_87F866B4_A01E_4D64_92CA_EF9B8D4784A4) },
    { be_const_key(Sine, 14), be_const_ctype_func(Berry_Mathematics_Class_Sine_1D631B5B_2877_43D1_97D0_AE4C0BFE886B) },
    { be_const_key(Message_Digest_MD_4, 43), be_const_int(2) },
    { be_const_key(Arc_Cosine, -1), be_const_ctype_func(Berry_Mathematics_Class_Arc_Cosine_6D000397_7C3F_49AE_9E68_FCD071AAC65F) },
    { be_const_key(Tangent, -1), be_const_ctype_func(Berry_Mathematics_Class_Tangent_18DAC7F6_EEDE_4388_AE6D_D87EBC2A881F) },
    { be_const_key(Hyperbolic_Cosecant, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Cosecant_BE91120D_B96F_48A7_8CA2_DEF59FE7F230) },
    { be_const_key(Secant, -1), be_const_ctype_func(Berry_Mathematics_Class_Secant_A46C1C5D_886C_448B_BC5F_DD6E30DC69B7) },
    { be_const_key(String_To_Float, 20), be_const_ctype_func(Berry_Mathematics_Class_String_To_Float_E335878A_387D_4FBD_BA68_9AB3C16597E5) },
    { be_const_key(Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Mathematics_Class_Hyperbolic_Sine_AD2F4969_A912_45EA_A7F0_44D8A513E081) },
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
