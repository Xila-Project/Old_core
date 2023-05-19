#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_C4359BD8_2073_4E44_A54C_A7F8FBF635C0) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_0927C8B0_5589_4D2F_9094_00CAE3C1672C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_8AB998E1_97D3_4FA8_B4D9_B7AD9DF68380) },
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
