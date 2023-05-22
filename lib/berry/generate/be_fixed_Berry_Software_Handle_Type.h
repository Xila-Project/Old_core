#include "be_constobj.h"

static be_define_const_map_slots(Berry_Software_Handle_Type_map) {
    { be_const_key(Get_Name, 1), be_const_ctype_func(Berry_Software_Handle_Class_Get_Name_47C68589_AD10_4A24_B6A6_A59EBDC80D71) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Software_Handle_Class_Initialize_9431523F_9046_4F88_87CD_1FB0AD3418B3) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Software_Handle_Class_Deinitialize_9EB277C5_0778_46CC_8570_E1BCB43ADB3F) },
    { be_const_key(Create_Instance, -1), be_const_ctype_func(Berry_Software_Handle_Class_Create_Instance_EB7452C7_41AE_4EBD_AF49_F833E13E123F) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Software_Handle_Type_map,
    5
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Software_Handle_Type,
    1,
    NULL,
    Software_Handle_Type
);
