#include "be_constobj.h"

static be_define_const_map_slots(Berry_Hash_Type_map) {
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(Is_Valid, 2), be_const_ctype_func(Berry_Hash_Class_Is_Valid_C1B1237E_8AFC_46FE_ACFA_02E5D5DE8D36) },
    { be_const_key(Delete, -1), be_const_ctype_func(Berry_Hash_Class_Delete_AF279C57_285B_44C6_9D18_94F21271FEE3) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Hash_Class_Create_F45F6B27_D665_4F12_B7EB_D6256A52A3B6) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Hash_Class_Deinitialize_6E1E4738_D869_40A1_A6DE_261A893ABF82) },
    { be_const_key(Get_Type, -1), be_const_ctype_func(Berry_Hash_Class_Get_Type_90336E1D_B27B_41CA_B1E3_F09DDC7981E2) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_Hash_Class_Initialize_46C88304_3CE6_42A1_87C8_3EA5A2163593) },
    { be_const_key(Get_Size, -1), be_const_ctype_func(Berry_Hash_Class_Get_Size_314F2C0E_E538_4679_92A3_CF1DA9E0D85A) },
    { be_const_key(Add, 0), be_const_ctype_func(Berry_Hash_Class_Add_B37641CC_16F4_434A_BB07_02DF53809B3A) },
};

static be_define_const_map(
    Berry_Hash_Type_map,
    9
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Hash_Type,
    1,
    NULL,
    Hash_Type
);
