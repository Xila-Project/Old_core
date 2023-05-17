#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_A1817DEF_15EA_49B9_85C5_DBCC3F623CCB) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_041DE339_5C31_4C5F_9142_8687C2A56910) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_5F902AC5_E06E_49B9_8DD1_DD8B1BFAA9AC) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_EB969768_5E27_40F1_8ACE_D141F96943D9) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_4D07F859_20B0_4F2A_AAA5_D113431C3EFC) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_07CDFDF6_5668_4B95_9646_66E8BDF2338F) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_D0545AB6_B382_465E_A8F6_B37899C7F9D8) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_FBE4A661_2669_4597_88F9_BB64139D934D) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_238904C7_F7C3_4F2E_8F5A_87A7A619524F) },
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
