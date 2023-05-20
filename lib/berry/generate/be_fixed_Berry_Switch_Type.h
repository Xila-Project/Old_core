#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_B86962F9_56E5_443D_8A14_45BB1D067673) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_F24F8C2B_86B0_4760_94AE_D6F5D116C0FC) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_86098AEF_0096_4F16_A4C9_2A5E4F4B2149) },
};

static be_define_const_map(
    Berry_Switch_Type_map,
    4
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Switch_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Switch_Type
);
