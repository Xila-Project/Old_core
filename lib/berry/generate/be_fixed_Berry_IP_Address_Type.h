#include "be_constobj.h"

static be_define_const_map_slots(Berry_IP_Address_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_IP_Address_Class_Initialize_56D01131_77F2_4A69_BAC9_CAE1E249F89A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_IP_v4, -1), be_const_ctype_func(Berry_IP_Address_Class_Is_IP_v4_D592309A_9128_447B_B09C_22FB0A21F128) },
    { be_const_key(To, 0), be_const_ctype_func(Berry_IP_Address_Class_To_E56BC88A_92A1_46A0_95FA_BECA3A48808D) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_IP_Address_Class_Operator_57FDAA6C_D7AE_47F8_8271_3C39DFAA5F39) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_IP_Address_Class_Deinitialize_B6FB7472_E3BA_4FE2_B380_6DB798CA5137) },
    { be_const_key(Set_IP_Version, 1), be_const_ctype_func(Berry_IP_Address_Class_Set_IP_Version_3D34B35B_1F6F_48EF_AF5B_6AC096334DF7) },
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
