#include "be_constobj.h"

static be_define_const_map_slots(Berry_IP_Address_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_IP_Address_Class_Initialize_A413ED9C_39B7_4F5A_96E8_BE3FF2EEAB81) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_IP_v4, -1), be_const_ctype_func(Berry_IP_Address_Class_Is_IP_v4_7319FD28_6E65_4967_B497_B2122D23D401) },
    { be_const_key(To, 0), be_const_ctype_func(Berry_IP_Address_Class_To_5D6683FA_77E1_418B_B731_8829A57D8B89) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_IP_Address_Class_Operator_1D7C49D6_F4B2_4B58_8028_2449E0B0E740) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_IP_Address_Class_Deinitialize_5638A5D8_26D8_47DF_A0C3_AA46F6F01EDF) },
    { be_const_key(Set_IP_Version, 1), be_const_ctype_func(Berry_IP_Address_Class_Set_IP_Version_F78196AD_3403_420F_A990_B06D133F0790) },
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
