#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_1CDEA9D8_A76D_4AA2_B5A1_835446BD8314) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_FB3A793F_92B8_4D0F_9A89_D884F0E95FAD) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_9689089B_5C44_4988_9E30_3A2E5F0E3AC6) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_37580180_886A_4C83_B5C6_6C76BC1B5B82) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_5FFE2FFA_B7DE_4DFE_8B41_5533127781C3) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_E7C3BBBD_2520_4697_8D52_FFCB6DB30AF7) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_974562DD_D6BA_4114_8948_F88494E03152) },
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
