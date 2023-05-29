#include "be_constobj.h"

static be_define_const_map_slots(Berry_Button_Type_map) {
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Button_Class_Deinitialize_59B3DDD4_B5F3_4B8D_95DA_F75EDD56620C) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Button_Class_Create_FC1F1362_50F8_46F1_A28B_C465D39FC7FA) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Button_Class_Initialize_CCA89751_D7EA_4DCD_B82B_15979217417F) },
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
