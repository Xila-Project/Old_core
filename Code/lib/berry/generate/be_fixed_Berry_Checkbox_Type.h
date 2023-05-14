#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_9945B777_FF84_4DE2_A463_E7D38233B56E) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_C1038A11_0628_4717_BC27_053B0378194F) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_93341133_6B79_40BC_807B_8071AE469EC7) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_08753C28_B6FD_417C_9A52_95ADCD6A3C33) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_1E93489B_49FB_4439_B909_B9FE1777903F) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_A4B79244_9522_445B_8183_3A63476DE4D5) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Checkbox_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Checkbox_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Checkbox_Type
);
