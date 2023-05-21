#include "be_constobj.h"

static be_define_const_map_slots(Berry_Software_Handle_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Software_Handle_Class_Deinitialize_04B54CAB_F1A8_4B18_9EC3_707D78160DBA) },
    { be_const_key(Create_Instance, -1), be_const_ctype_func(Berry_Software_Handle_Class_Create_Instance_1BFABBD2_352F_4FF5_A2A3_3BEE09A5AFB9) },
    { be_const_key(Is_Equal, 6), be_const_ctype_func(Berry_Software_Handle_Class_Is_Equal_6EB0CB27_CB52_41CB_8FAA_E7BA1254744A) },
    { be_const_key(Get_Name, 5), be_const_ctype_func(Berry_Software_Handle_Class_Get_Name_DE16F0A7_458F_4236_B598_B7785A876B94) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Software_Handle_Class_Initialize_E497D8D5_7CD4_4532_8D03_A08FE32100F2) },
    { be_const_key(_X21_X3D, 4), be_const_ctype_func(Berry_Software_Handle_Class_Operator_8BB878E8_705E_4287_8D79_33297E46909E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_Software_Handle_Class_Operator_80439055_0719_4702_A8F8_A7DA3FA64E56) },
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
