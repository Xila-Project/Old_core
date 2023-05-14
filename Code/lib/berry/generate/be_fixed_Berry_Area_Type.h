#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_501EF341_3B6E_474C_A5B5_B1530E6478F7) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_279AE8B2_A571_496E_B201_190AED27F339) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_87A2B2EA_237C_4A00_BC3E_7B6B275E9A2D) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_5C568E69_0C4B_45D6_8B23_1AEBBCB8B50B) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_7182332B_D603_44B6_85B7_E88B58251175) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_79FC1B5E_F908_4289_8595_49A75780FF3D) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_4346D3BF_0828_42E5_B8DB_0DBEACB39572) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_EEAA223A_DE93_42FD_ABB4_3925E8AC847B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_324789AD_FE6A_4B6A_9838_329FF2FE8AA7) },
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
