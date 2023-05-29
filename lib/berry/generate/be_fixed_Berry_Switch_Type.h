#include "be_constobj.h"

static be_define_const_map_slots(Berry_Switch_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Switch_Class_Deinitialize_95043993_475E_48D9_8D20_926DAA221118) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Switch_Class_Create_522B0698_F4CA_4A79_856C_2C249B50EFFC) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Switch_Class_Initialize_68C7BD98_BF4C_4AEB_9CE9_B9652A99C909) },
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
