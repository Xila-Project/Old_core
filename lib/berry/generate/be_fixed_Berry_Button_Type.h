#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_D5C36032_E473_48FE_8BD9_4655AB73F9FC) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_C3FDBAD0_CEC3_4FA5_AF59_C10918333F93) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_3BC1DDDE_AD15_45F7_A339_FEF8FD268C67) },
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
