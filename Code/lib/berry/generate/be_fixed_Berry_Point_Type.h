#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_C1ED353D_F6B8_4CA4_B2DE_23047881EF50) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_D5B1F460_E4CF_4268_947E_6D99D270242B) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_DFF4C3F7_B1FE_45C5_A147_2A2F8756BE93) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_6FBD950D_CA61_4E84_BA8B_3E9379CAC0A5) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_497DF31E_BE2B_4FFD_A24E_433D26EEB7F2) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_2E08E5C7_A979_44EA_9A2B_AC19C9319529) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_788C3D45_DA78_43CE_AA88_FC35ECB94B6B) },
};

static be_define_const_map(
    Berry_Point_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Point_Type,
    1,
    NULL,
    Point_Type
);
