#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_49CE5095_80A5_4FF6_85FC_C6EA6C57A406) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_EB77A98E_8AE7_4BF6_8CC4_3D86FD54BA49) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_2B178A5E_B936_4144_ADA6_E431A97C26FA) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_B107A95D_F137_4BFA_98D4_F9AF492C6D9A) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_98463952_741C_47B2_B73E_B2652C957A79) },
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
