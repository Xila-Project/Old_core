#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_8733F80C_A60F_4A22_95E1_4BEA85AD2704) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_D1773EA9_F9E2_413C_AE4B_74973600D3E5) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_CD8739A1_5A86_4C1D_9FAF_7244660AC7F2) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_8FDBB161_1718_4CF3_9D8A_C3A42F4C179C) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_8E4DDFD1_33B0_45AD_9FEE_C05B4E2FEEEE) },
};

static be_define_const_map(
    Berry_Line_Type_map,
    6
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Line_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Line_Type
);
