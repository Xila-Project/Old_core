#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_0A15FE77_19F1_4369_A500_29B2E4817D4F) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_5C4071C5_9828_47D2_9338_307D6B2D6B97) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_2022E39A_B8E4_497C_9590_CEC834D86E71) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_B2063CF8_CACA_4FC2_9C7A_CFA20641B2AD) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_7F0E48F1_DCF4_4B4F_A9DF_0360586DC199) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_B5C960F4_671E_4D68_AA2E_82831B7C287D) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_A1D9A169_268B_4F44_A382_257FCC90FE42) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_268E2143_7411_4D40_96D4_6F2B2300B820) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_381AC1C3_D78D_46AA_98EA_0477E087A86B) },
};

static be_define_const_map(
    Berry_Area_Type_map,
    10
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Area_Type,
    1,
    NULL,
    Area_Type
);
