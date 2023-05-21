#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Get_Volume_4CA44407_2169_4F5F_914C_AF33094CAC0F) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Volume_Class_Begin_F2AE16F8_813C_44E7_8CFE_6368E1461B03) },
    { be_const_key(Set_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Set_Volume_E4E1B650_83FB_446B_BA55_86DD4FB9941E) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_Volume_Class_Get_Default_Configuration_9C856D57_23CE_4271_AC4B_EE3F733E5249) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Class_Initialize_36892B45_8616_4448_967E_34563A26078E) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Class_Deinitialize_EA3C2C23_5A07_4A91_B5E6_A24AA041E7BB) },
    { be_const_key(_p, 2), be_const_var(0) },
};

static be_define_const_map(
    Berry_Volume_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Volume_Type,
    1,
    NULL,
    Volume_Type
);
