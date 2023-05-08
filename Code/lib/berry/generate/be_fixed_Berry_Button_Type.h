#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_DBD39166_5317_4FBD_8061_5F4D4B286DD4) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_07388BFA_2BCE_4308_B596_82C9F67DD735) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_6F4E67FB_05BE_4D1E_B7B4_C29CE2E83125) },
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
