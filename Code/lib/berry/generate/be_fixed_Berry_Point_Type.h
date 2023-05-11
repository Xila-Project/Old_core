#include "be_constobj.h"

static be_define_const_map_slots(Berry_Point_Type_map) {
    { be_const_key(Get_X_, 6), be_const_ctype_func(Berry_Point_Class_Get_X_8A38F857_72D8_405D_B43B_69F0522953F4) },
    { be_const_key(Set, -1), be_const_ctype_func(Berry_Point_Class_Set_50269655_56AD_481B_8550_23E22F0D5B9A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, 5), be_const_ctype_func(Berry_Point_Class_Initialize_B8CF3D6E_6F5E_4F2E_A068_731F6E5338B2) },
    { be_const_key(Set_X_, -1), be_const_ctype_func(Berry_Point_Class_Set_X_FBF19755_2DC9_47C2_8272_D3909ACCEDCC) },
    { be_const_key(Get_Y, 1), be_const_ctype_func(Berry_Point_Class_Get_Y_C4FFD48B_8569_4539_80EA_50F5E8C48AF3) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Point_Class_Deinitialize_52932FE5_AD68_4C85_95ED_F5C5E0ED8CE9) },
    { be_const_key(Set_Y, -1), be_const_ctype_func(Berry_Point_Class_Set_Y_FAE1BDFD_E5B7_43A3_A66B_6FD78F57F8A3) },
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
