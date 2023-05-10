#include "be_constobj.h"

static be_define_const_map_slots(Berry_Area_Type_map) {
    { be_const_key(Move, 3), be_const_ctype_func(Berry_Area_Class_Move_3CDC0C89_1D94_401F_9301_3C49D91B6711) },
    { be_const_key(Set_Height, -1), be_const_ctype_func(Berry_Area_Class_Set_Height_3CCEC528_D3D4_47C0_B334_F44F48BE6D78) },
    { be_const_key(deinit, 8), be_const_ctype_func(Berry_Area_Class_Deinitialize_862ED29E_E234_4F6B_870C_A311EE9CDF7E) },
    { be_const_key(Align, -1), be_const_ctype_func(Berry_Area_Class_Align_9CB1D63A_570B_48CF_8965_345E6F990E3C) },
    { be_const_key(Set_Width, -1), be_const_ctype_func(Berry_Area_Class_Set_Width_6AD58C08_190F_48D4_8873_1B3D6AC2CC78) },
    { be_const_key(Get_Height, 7), be_const_ctype_func(Berry_Area_Class_Get_Height_7319D45F_3EF4_415E_AFA6_04CA4F79972E) },
    { be_const_key(Get_Width, -1), be_const_ctype_func(Berry_Area_Class_Get_Width_A134D6B6_9FA3_4E0B_B56D_0F0DFD91215D) },
    { be_const_key(Increase, 9), be_const_ctype_func(Berry_Area_Class_Increase_181BFF02_2DB0_46A4_9DB2_3C061E82013A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Area_Class_Get_Size_9A82F15A_7164_46B2_A4EF_C1288F6EC253) },
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
