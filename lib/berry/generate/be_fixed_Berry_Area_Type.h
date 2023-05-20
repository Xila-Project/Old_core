#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_321132E2_E96D_4C8C_B7F0_8D683ECF13FF) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_ACCB3DBF_09BE_4D1F_89AF_E7DAE79B95C3) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_354D5B51_8B11_4815_A2A4_E60C1155C944) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_DFDFB141_966D_4851_98C4_CDD4F2C17942) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_4C657E6A_6D3E_4504_8B2A_5547D9CDFBBA) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_27F0A98F_8BB4_4412_87E1_8A332C415C1B) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_63817C3D_FB03_489A_8833_D0A98935032A) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_B077C8F2_2FB2_490E_B861_A2234B5BB318) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_0D6B4D0B_DE9D_4CED_ACB9_800D90BE55CC) },
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
