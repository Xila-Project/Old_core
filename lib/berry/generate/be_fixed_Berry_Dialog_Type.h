#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_D426631C_F634_49B5_844E_880CA0A38615) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_265E90E7_E6C5_417D_9256_C32B4AA5090A) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_F2177437_5F90_4D79_BADF_B1A74351F76C) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_28C89551_C790_4CC4_BDA3_8DEB5B25035B) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_47B909E9_FE2B_4C6D_8385_D086ABA74D21) },
};

static be_define_const_map(
    Berry_Dialog_Type_map,
    6
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Dialog_Type,
    1,
    (bclass *)&Berry_Window_Type,
    Dialog_Type
);
