#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_60776D1E_4E5E_4EF7_8E03_4AD2CE31A337) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_A6FB983E_DC1D_47D5_A4C3_0A2848E66D75) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_EB40C3A4_FB3A_43B1_85B3_3A8E089279EB) },
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
