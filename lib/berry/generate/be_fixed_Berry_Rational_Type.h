#include "be_constobj.h"

static be_define_const_map_slots(Berry_Rational_Type_map) {
    { be_const_key(Hyperbolic_Cosine, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Cosine_E1CE3ACF_B521_4FE9_8A9C_D3A895C2C49E) },
    { be_const_key(Hyperbolic_Arc_Tangent, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Arc_Tangent_84A1ED23_3B0E_47F9_8E7B_FF28CF7D3CF1) },
    { be_const_key(Absolute_Value, -1), be_const_ctype_func(Berry_Rational_Class_Absolute_Value_D322360C_883C_4FE2_B4A5_F50473E8E510) },
    { be_const_key(Least_Common_Multiple, -1), be_const_ctype_func(Berry_Rational_Class_Least_Common_Multiple_A01635F4_224A_45C7_A378_A31DD0080DFB) },
    { be_const_key(Hyperbolic_Tangent, 21), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Tangent_FF5FF7A2_576C_4F84_A1B8_5B1F446D45A7) },
    { be_const_key(Arc_Tangent, -1), be_const_ctype_func(Berry_Rational_Class_Arc_Tangent_1B921555_739E_456A_9E39_C6D9FCACDE8A) },
    { be_const_key(Square, -1), be_const_ctype_func(Berry_Rational_Class_Square_9A53929D_ED92_448F_85B1_FC9C9C525457) },
    { be_const_key(Hyperbolic_Arc_Sine, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Arc_Sine_AEF334B2_15D8_404B_859D_A650CC5069DE) },
    { be_const_key(Exponential, -1), be_const_ctype_func(Berry_Rational_Class_Exponential_3CAB9929_50D9_4AD6_A2A8_32CB0235CEC2) },
    { be_const_key(Root, -1), be_const_ctype_func(Berry_Rational_Class_Root_5B6220C1_EEA3_4AA6_B8BA_A09E1EC8206F) },
    { be_const_key(Natural_Logarithm, -1), be_const_ctype_func(Berry_Rational_Class_Natural_Logarithm_17DAAB00_B690_45EF_9E1A_B0E85ED2167C) },
    { be_const_key(Get_Numerator, -1), be_const_ctype_func(Berry_Rational_Class_Get_Numerator_19A46B21_51B5_4523_AF48_4F22D348D1DE) },
    { be_const_key(Logarithm, 0), be_const_ctype_func(Berry_Rational_Class_Logarithm_B2DEEE55_29B5_4436_8E32_05B55CD03F1A) },
    { be_const_key(Get_Denominator, 25), be_const_ctype_func(Berry_Rational_Class_Get_Denominator_AA757BC5_1D8E_427C_9AF4_20C53A857005) },
    { be_const_key(Hyperbolic_Arc_Cosine, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Arc_Cosine_383EAC3F_478F_484E_95DD_49D411B67FCD) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Rational_Class_Initialize_2249C4E2_A8A8_4953_A921_2719149D7C77) },
    { be_const_key(Factorial, 13), be_const_ctype_func(Berry_Rational_Class_Factorial_DDE5A06E_DCBF_4778_805F_72E97F6D00F4) },
    { be_const_key(Inverse, 1), be_const_ctype_func(Berry_Rational_Class_Inverse_6EF6C8AA_BD33_449F_A74F_B639DC09DB8D) },
    { be_const_key(Simplify, -1), be_const_ctype_func(Berry_Rational_Class_Simplify_91307311_2B2E_443A_A38D_7834CF8C8C97) },
    { be_const_key(Square_Root, 7), be_const_ctype_func(Berry_Rational_Class_Square_Root_1B3FC1C7_F363_4095_82B7_DFD4D5C0A31E) },
    { be_const_key(Tangent, -1), be_const_ctype_func(Berry_Rational_Class_Tangent_30B2AAE5_2BBC_4DA4_A446_AC227BE52771) },
    { be_const_key(deinit, 32), be_const_ctype_func(Berry_Rational_Class_Deinitialize_4D5EDE33_ABF9_4A3D_88D7_A20A1DC83615) },
    { be_const_key(Hyperbolic_Sine, -1), be_const_ctype_func(Berry_Rational_Class_Hyperbolic_Sine_9B507F98_E584_442B_A147_7BD52A84D431) },
    { be_const_key(_X3D_X3D, 28), be_const_ctype_func(Berry_Rational_Class_Operator_7FFE75C6_6EF0_4A0B_B4E3_A075131DB48D) },
    { be_const_key(Cube, 27), be_const_ctype_func(Berry_Rational_Class_Cube_32D6A7C3_C837_4EC4_B670_5A1D483DB0FF) },
    { be_const_key(Binary_Logarithm, -1), be_const_ctype_func(Berry_Rational_Class_Binary_Logarithm_8940EDDC_6E46_4A56_A39F_21F2A5090492) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Decimal_Logarithm, -1), be_const_ctype_func(Berry_Rational_Class_Decimal_Logarithm_17248361_259C_4F56_B935_9B81CE0D2A12) },
    { be_const_key(Greatest_Common_Divisor, -1), be_const_ctype_func(Berry_Rational_Class_Greatest_Common_Divisor_F563F98E_2A5B_4EAD_9653_612906E4944F) },
    { be_const_key(Cube_Root, 14), be_const_ctype_func(Berry_Rational_Class_Cube_Root_640F780D_2361_4F23_BC4E_068E67B4D160) },
    { be_const_key(Cosine, 20), be_const_ctype_func(Berry_Rational_Class_Cosine_3BF30F53_DE21_4EAC_956A_AA5B9D103409) },
    { be_const_key(_X21_X3D, 17), be_const_ctype_func(Berry_Rational_Class_Operator_095CB9F0_7C23_4DC6_B173_DCEA6FB16E39) },
    { be_const_key(Sine, -1), be_const_ctype_func(Berry_Rational_Class_Sine_EFFA136D_65EA_4086_8389_389C987F0089) },
    { be_const_key(Arc_Sine, -1), be_const_ctype_func(Berry_Rational_Class_Arc_Sine_9F890467_3DF5_4E32_83F8_DA3E8CF56622) },
    { be_const_key(Power, -1), be_const_ctype_func(Berry_Rational_Class_Power_9E2CDF02_63E5_482D_B0DF_E40D89C7B810) },
    { be_const_key(Arc_Cosine, 11), be_const_ctype_func(Berry_Rational_Class_Arc_Cosine_7DFE1DDE_2B42_4FD8_9C6A_CCA71FE0B050) },
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
