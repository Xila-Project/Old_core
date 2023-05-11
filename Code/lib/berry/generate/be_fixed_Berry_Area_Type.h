#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_8D8965A4_B92B_4808_B556_B8AE4F971C39) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_882B9DF5_8254_45FC_8EF7_231CFA80623F) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_8404B13A_2887_4659_AACB_03963ECD5A49) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_7FBC20EE_9F49_42CB_84A8_629FA73EF963) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_0BC52CB3_DD65_42E5_A1A6_BEC8C37F5E38) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_B79F961F_5492_4C64_A5D9_7D4EF921307A) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_D935C24A_3564_457B_9974_54E4FAFBF172) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_14F7B14B_D70B_4855_B9A9_D7700D305E2A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_2DC87D8B_7763_4B2D_811A_4B82F8CF4E02) },
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
