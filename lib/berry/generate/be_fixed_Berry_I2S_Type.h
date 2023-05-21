#include "be_constobj.h"

static be_define_const_map_slots(Berry_I2S_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_I2S_Class_Initialize_C072FC21_8C3A_46CE_8885_3278400C3181) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_I2S_Class_Begin_3ED90EBC_B026_41E3_B8AF_803A08FE74EE) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_I2S_Class_Deinitialize_D1ED6441_879A_4296_A764_5A9791179746) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_I2S_Class_Get_Default_Configuration_53157193_5074_4404_AB4D_36FE9CE58C09) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_I2S_Type_map,
    5
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_I2S_Type,
    1,
    NULL,
    I2S_Type
);
