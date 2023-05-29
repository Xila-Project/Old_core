#include "be_constobj.h"

static be_define_const_map_slots(Berry_IP_Address_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_IP_Address_Class_Initialize_EA495F1B_E003_4913_8391_9DDBD11FEC6A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_IP_v4, -1), be_const_ctype_func(Berry_IP_Address_Class_Is_IP_v4_0B94DB72_BE0E_42B5_9CBD_533386CEC2BC) },
    { be_const_key(To, 0), be_const_ctype_func(Berry_IP_Address_Class_To_21485721_A70C_44B3_A330_CB7C543D4DD4) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_IP_Address_Class_Operator_7E33A206_3A8F_4762_B48C_0310DD88B350) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_IP_Address_Class_Deinitialize_273B492A_82B9_41A1_9F58_BF5DC0F0765B) },
    { be_const_key(Set_IP_Version, 1), be_const_ctype_func(Berry_IP_Address_Class_Set_IP_Version_CAA36ECA_1513_482B_9A78_4881C02C0BE0) },
};

static be_define_const_map(
    Berry_IP_Address_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_IP_Address_Type,
    1,
    NULL,
    IP_Address_Type
);
