#include "be_constobj.h"

static be_define_const_map_slots(Berry_IP_Address_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_IP_Address_Class_Initialize_6702F18A_C4E1_487A_AF4B_273CF87AB5F2) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_IP_v4, -1), be_const_ctype_func(Berry_IP_Address_Class_Is_IP_v4_E90204DD_9DA4_4A04_842E_A4A9DD45BCCE) },
    { be_const_key(To, 0), be_const_ctype_func(Berry_IP_Address_Class_To_C29F1C51_65C9_47B8_A093_D605ADC3DECE) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_IP_Address_Class_Operator_63BF6932_8C67_487C_8C93_8017DFEA6B3F) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_IP_Address_Class_Deinitialize_9C5C7853_E99E_426B_A7D1_EAB8CCE9600F) },
    { be_const_key(Set_IP_Version, 1), be_const_ctype_func(Berry_IP_Address_Class_Set_IP_Version_C2017810_56BE_4908_8885_76916C691363) },
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
