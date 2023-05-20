#include "be_constobj.h"

static be_define_const_map_slots(Berry_IP_Address_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_IP_Address_Class_Initialize_186548D5_5294_4FAB_8B11_A1A97A3419A6) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_IP_v4, -1), be_const_ctype_func(Berry_IP_Address_Class_Is_IP_v4_9F39CB8D_8C28_4A68_92E9_1B65C6FEE850) },
    { be_const_key(To, 0), be_const_ctype_func(Berry_IP_Address_Class_To_051EB0B8_9E65_4536_BDF6_90869A024611) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_IP_Address_Class_Operator_E3F64586_3F9C_4697_A475_430C1D117188) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_IP_Address_Class_Deinitialize_D38853AA_8088_4AD2_A87B_DC86A4BD1031) },
    { be_const_key(Set_IP_Version, 1), be_const_ctype_func(Berry_IP_Address_Class_Set_IP_Version_5FD29F9A_579C_4F9A_9742_D54654EFBF5F) },
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
