#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_4EAD883F_34B0_4DC2_98C4_81FD5CF23B68) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_703B5731_5C36_4681_A751_B183B0885AD0) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_C8330C29_A640_42E5_8164_FF01F597E499) },
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
