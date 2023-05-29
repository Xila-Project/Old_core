#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Get_Volume_2587964A_4D8E_46DC_A1F1_E362E5A31690) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Volume_Class_Begin_A24AD730_3ADB_43E7_9771_D3B52CA8BB55) },
    { be_const_key(Set_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Set_Volume_ECAF170C_E91B_4061_BF75_AF10A5DD250B) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_Volume_Class_Get_Default_Configuration_D41DA7CB_0FAB_408E_9AB7_D5CAE5723653) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Class_Initialize_4F39A22B_4494_4358_9D13_0AAF0901C14A) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Class_Deinitialize_BF4E88A0_02C1_4833_892B_AA4838E550B2) },
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
