#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_E4221539_12A0_45ED_9589_1064BC066AAC) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_4A9CA48E_3CB1_42E1_BF5F_B50DDD6B601C) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_F9A9D334_58D6_4411_9CFB_A7FBA58B6278) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_30E1DEDA_A4F9_497E_9674_A163CC43B910) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_9DB7500B_CEC4_474C_AF75_EEE968F57EDD) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_81BE97DD_DE0E_4C56_B9F2_9AD951D1E2F3) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_D2674166_E5DD_438D_A975_3C51169F406C) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_95E55A15_647A_458A_9A6B_4E330FFFDE2A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_D5116240_3E32_453E_B4F7_D6D26DC4F404) },
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
