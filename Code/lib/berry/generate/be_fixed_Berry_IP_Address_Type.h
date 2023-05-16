#include "be_constobj.h"

static be_define_const_map_slots(Berry_IP_Address_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_IP_Address_Class_Initialize_D5F6D676_B433_4CC4_A31F_9E047DCDB740) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_IP_v4, -1), be_const_ctype_func(Berry_IP_Address_Class_Is_IP_v4_1AB30ECF_FE16_48DE_84B1_5E232BE723FB) },
    { be_const_key(To, 0), be_const_ctype_func(Berry_IP_Address_Class_To_AEF9D82D_2B16_499D_8F6B_F038A7335A09) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_IP_Address_Class_Operator_97C043DC_6A8C_4A52_8CE3_98462BE68E87) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_IP_Address_Class_Deinitialize_9893F34F_0DB1_4714_9180_97EC6D73A391) },
    { be_const_key(Set_IP_Version, 1), be_const_ctype_func(Berry_IP_Address_Class_Set_IP_Version_6D9BBF71_81AF_4E3F_939D_89A033F6E183) },
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
