#include "be_constobj.h"

static be_define_const_map_slots(Berry_IP_Address_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_IP_Address_Class_Initialize_F66CB07E_9E21_4547_8F50_6E0C649FD7AA) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_IP_v4, -1), be_const_ctype_func(Berry_IP_Address_Class_Is_IP_v4_1FACCF7E_B810_4101_B2CF_E792CA0F5AF4) },
    { be_const_key(To, 0), be_const_ctype_func(Berry_IP_Address_Class_To_E4F6C607_489C_41F0_8020_A9A397673EC2) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_IP_Address_Class_Operator_B2EDC75F_A93F_422E_93C9_3FC06874D0C9) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_IP_Address_Class_Deinitialize_4508D52F_BE93_4952_8672_F9763009B880) },
    { be_const_key(Set_IP_Version, 1), be_const_ctype_func(Berry_IP_Address_Class_Set_IP_Version_CF5B9FBB_8473_4321_846E_9F69EE81C566) },
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
