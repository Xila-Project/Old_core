#include "be_constobj.h"

static be_define_const_map_slots(Berry_Software_Handle_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Software_Handle_Class_Deinitialize_691B0EBD_6EC0_45DF_9A3D_D2596C2D4207) },
    { be_const_key(Create_Instance, -1), be_const_ctype_func(Berry_Software_Handle_Class_Create_Instance_657C4500_8C39_4CF3_BD78_624D3B943BF7) },
    { be_const_key(Is_Equal, 6), be_const_ctype_func(Berry_Software_Handle_Class_Is_Equal_60EAD659_FD8D_47B9_8114_EAA1B430F482) },
    { be_const_key(Get_Name, 5), be_const_ctype_func(Berry_Software_Handle_Class_Get_Name_7F54F61B_81F8_4942_8551_AD3E14F397D8) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Software_Handle_Class_Initialize_16D7E537_7D4C_41BE_B29F_E22D2E7F2F11) },
    { be_const_key(_X21_X3D, 4), be_const_ctype_func(Berry_Software_Handle_Class_Operator_850AE5E3_0CD9_42E9_ACF3_CB3F10917468) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Software_Handle_Class_Operator_8EA35188_E497_4B7F_BB67_678BA1125B73) },
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
