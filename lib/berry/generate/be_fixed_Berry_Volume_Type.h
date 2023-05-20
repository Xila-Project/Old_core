#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Get_Volume_32E2293C_CD25_4263_A147_37813F54949E) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Volume_Class_Begin_329D7430_04CD_4B49_877D_367CA81A7BD2) },
    { be_const_key(Set_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Set_Volume_A17A6FF2_711A_40E6_9D4F_C186533D1408) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_Volume_Class_Get_Default_Configuration_20533D4E_9351_4862_99B7_EC26CDD8ABBB) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Class_Initialize_ECC4B3D7_7900_4D46_A2E6_813598C58221) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Class_Deinitialize_31BA73CA_6030_426B_B599_50AB468139C3) },
    { be_const_key(_p, 2), be_const_var(0) },
};

static be_define_const_map(
    Berry_Volume_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Volume_Type,
    1,
    NULL,
    Volume_Type
);
