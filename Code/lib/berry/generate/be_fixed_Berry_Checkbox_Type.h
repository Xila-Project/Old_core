#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_3C4AB65B_6893_4695_8553_26D163453914) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_9A766D7B_A27C_4A07_8840_E9E995483376) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_AC51539E_3A50_4DCE_A710_406942F1C404) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_B2C63919_E99D_4397_BF34_1F260FEC5E35) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_66274377_0494_4082_B5D3_0AFB5754854A) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_DB198F2E_DFF3_4C7A_827E_7C16C2057480) },
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
