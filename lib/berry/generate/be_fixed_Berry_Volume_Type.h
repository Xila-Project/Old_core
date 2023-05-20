#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Get_Volume_5576B2E3_3730_4511_829A_9EA28A9E4276) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Volume_Class_Begin_A45848A9_F142_49E6_A62F_310B1A3C8832) },
    { be_const_key(Set_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Set_Volume_5A151DD4_0C9B_48C7_A916_92E71E08FBA6) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_Volume_Class_Get_Default_Configuration_63ECA136_A021_4843_AF36_31A03312619E) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Class_Initialize_25EA920C_F8D5_4368_92AC_169F64D9E6CE) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Class_Deinitialize_6870E57E_40DE_4319_A24B_0A15EC7600CB) },
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
