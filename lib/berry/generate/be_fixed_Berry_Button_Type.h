#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_EE290988_85E6_4E61_BCC6_A28E49A473AB) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_4DFFFD8B_1BB3_4C08_9E63_47E643747785) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_86DA2AF8_3465_45D3_80AB_9BD11B977116) },
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
