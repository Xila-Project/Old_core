#include "be_constobj.h"

static be_define_const_map_slots(Berry_IP_Address_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_IP_Address_Class_Initialize_56337033_C868_4526_888A_783923ADF17E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_IP_v4, -1), be_const_ctype_func(Berry_IP_Address_Class_Is_IP_v4_AF9FE2DF_19DB_42F5_B33A_73C98CF980E0) },
    { be_const_key(To, 0), be_const_ctype_func(Berry_IP_Address_Class_To_99515416_7617_4900_BC12_42DD70A939DD) },
    { be_const_key(_X3D_X3D, -1), be_const_ctype_func(Berry_IP_Address_Class_Operator_82F803FD_F943_4FBF_BA33_A8C1148736D2) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_IP_Address_Class_Deinitialize_65E1CAF0_3E9A_4B09_9F74_FB41310B4CEC) },
    { be_const_key(Set_IP_Version, 1), be_const_ctype_func(Berry_IP_Address_Class_Set_IP_Version_2CE8B007_7E9A_442C_B54E_9A041328AF51) },
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
