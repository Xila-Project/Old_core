#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_616A60D6_F57C_4667_AAF9_6DC3DC74C66E) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_3AA65770_897F_4923_8B32_A9F97450E41C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_5C27B79A_7A7D_4551_96EF_D3F209B0629B) },
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
