#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_9D75AF3F_675D_403A_9FB1_7E165588EB9D) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_B9547154_6FF8_475D_B51A_2364B197EBD7) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_C9037E7A_2075_4894_A085_B1527A97E0AA) },
};

static be_define_const_map(
    Berry_Button_Type_map,
    4
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Button_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Button_Type
);
