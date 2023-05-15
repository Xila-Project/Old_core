#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_4FF80252_69AD_4EB0_AEE3_9F95E6DA0A31) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_12B43818_EEBB_4B4B_9A51_18F65D3BFD9E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_B4CADA24_5B93_4087_926C_1DA27E6AC1B7) },
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
