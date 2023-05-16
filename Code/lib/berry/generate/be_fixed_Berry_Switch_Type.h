#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_5B76D414_6682_45D5_91E6_0C84A72F8909) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_E0F6811F_22F6_4670_9C2F_F46CA8F5ED25) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_74FCE366_771E_4AFB_9738_329C92E679B8) },
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
