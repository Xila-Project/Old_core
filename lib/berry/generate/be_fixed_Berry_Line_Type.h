#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_08042FD9_48FC_4888_A425_59BA0DC9EA3D) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_D3FF0738_82F0_44EC_A5A7_A00E3D818650) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_D93459A3_BACE_4086_8F8C_A802161EB334) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_BF6423D5_FE41_4AFA_9292_9B87B1983A89) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_F6DE9177_920F_45B4_A50C_BCBD92BF7157) },
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
