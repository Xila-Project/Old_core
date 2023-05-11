#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_AE457C69_CEDB_4261_AD76_7AA398063A27) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_965402FF_E4F0_4EC3_AE6F_246EBC286564) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_53FD0160_B4D1_47B1_8F0E_5EF921DA3A57) },
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
