#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_BF64F8B5_03CD_4834_8BDE_043AA1DABF50) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_1B1470E7_0AEF_4204_9113_24B9383B19EB) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_B081F92F_10DB_4327_8F77_FAFA62138258) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_71EBE826_3738_4A6A_B12C_5A2AFA2E0B70) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_3D510743_CADC_4F2C_AE71_EDEB6B734F40) },
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
