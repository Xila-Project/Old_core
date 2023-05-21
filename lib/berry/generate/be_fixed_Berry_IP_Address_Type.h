#include "be_constobj.h"

static be_define_const_map_slots(Berry_IP_Address_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_IP_Address_Class_Initialize_5F36E8FB_BDC7_460F_B651_4216DAAEE26A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_IP_v4, -1), be_const_ctype_func(Berry_IP_Address_Class_Is_IP_v4_02BAE8C9_1DCF_4C57_BB15_07244779C419) },
    { be_const_key(To, 0), be_const_ctype_func(Berry_IP_Address_Class_To_70B32C69_9216_45E0_949E_7C9BCCBC265A) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_IP_Address_Class_Operator_1B40FFD4_BBF4_4206_9D10_CCE43E90FD8F) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_IP_Address_Class_Deinitialize_14BF6903_31BB_45CF_8148_68D9BEA59A12) },
    { be_const_key(Set_IP_Version, 1), be_const_ctype_func(Berry_IP_Address_Class_Set_IP_Version_57E1A042_B403_4F5F_AD16_154C6BA579EB) },
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
