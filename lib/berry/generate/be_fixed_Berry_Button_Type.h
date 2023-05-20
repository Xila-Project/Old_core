#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_4C7FD1A9_8445_4C7F_8DD0_08D67E9291FD) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_9EC849A1_289E_432B_B99B_8C37F4415016) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_546B7EEC_A24A_473A_AF41_E21E3AB70CB3) },
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
