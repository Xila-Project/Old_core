#include "be_constobj.h"

static be_define_const_map_slots(Berry_Line_Type_map) {
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Line_Class_Create_FFC0163D_DA36_469F_AEBF_AB67F1D289F7) },
    { be_const_key(Get_Y_Inversion, -1), be_const_ctype_func(Berry_Line_Class_Get_Y_Inversion_B0018128_D41A_451C_9B93_99B44EE517B7) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Y_Inversion, 0), be_const_ctype_func(Berry_Line_Class_Set_Y_Inversion_995727AD_B067_4594_89A4_6EF01E028416) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Line_Class_Deinitialize_B11D196F_B732_4C01_B661_EE56A85CD4C4) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Line_Class_Initialize_33DD1961_4B56_405D_AB61_4728274493B4) },
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
