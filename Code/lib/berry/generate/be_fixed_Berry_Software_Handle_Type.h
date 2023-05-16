#include "be_constobj.h"

static be_define_const_map_slots(Berry_Software_Handle_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Software_Handle_Class_Deinitialize_4C54CC7B_BC02_4DB4_A09B_3C7F41FD27EB) },
    { be_const_key(Create_Instance, -1), be_const_ctype_func(Berry_Software_Handle_Class_Create_Instance_B1A9D69D_EF04_4BF3_8651_B397A52AED89) },
    { be_const_key(Is_Equal, 6), be_const_ctype_func(Berry_Software_Handle_Class_Is_Equal_D420C217_9778_4805_BA53_4C749D2CFD3E) },
    { be_const_key(Get_Name, 5), be_const_ctype_func(Berry_Software_Handle_Class_Get_Name_12F644FA_439B_485D_A12B_7E15C7433B5E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Software_Handle_Class_Initialize_5A820B02_A365_47A0_B2E6_5F4597691BBD) },
    { be_const_key(_X21_X3D, 4), be_const_ctype_func(Berry_Software_Handle_Class_Operator_F62B2857_D648_4EA7_9EC3_F1DF4A950281) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Software_Handle_Class_Operator_8F196571_A028_4178_B77C_9B33054B83C1) },
};

static be_define_const_map(
    Berry_Software_Handle_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Software_Handle_Type,
    1,
    NULL,
    Software_Handle_Type
);
