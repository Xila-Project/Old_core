#include "be_constobj.h"

static be_define_const_map_slots(Berry_Dialog_Type_map) {
    { be_const_key(Is_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Is_Overlay_3DBB727A_82D8_43AE_BA88_169B6F046318) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Dialog_Class_Create_FE6D0AA4_E6CB_46AB_801E_71067B037407) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(init, 1), be_const_ctype_func(Berry_Dialog_Class_Initialize_3359DC08_CE64_47AC_B985_EDA0ED7399D7) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Dialog_Class_Deinitialize_BA84C6D9_F856_4767_99CA_731B03FC97CA) },
    { be_const_key(Set_Overlay, -1), be_const_ctype_func(Berry_Dialog_Class_Set_Overlay_D5C738EF_8472_4B92_8E1B_74D8E9140D2F) },
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
