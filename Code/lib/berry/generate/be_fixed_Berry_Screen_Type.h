#include "be_constobj.h"

static be_define_const_map_slots(Berry_Screen_Type_map) {
    { be_const_key(Get_User_Screen, 7), be_const_ctype_func(Berry_Screen_Class_Get_User_Screen_C36FB5F6_5411_4123_ABDE_AA3486B65C10) },
    { be_const_key(Load, -1), be_const_ctype_func(Berry_Screen_Class_Load_7242A105_0C8A_4B2E_A426_600BAD5FF8AA) },
    { be_const_key(Delete, 4), be_const_ctype_func(Berry_Screen_Class_Delete_F9B4DE82_5532_43C8_85B3_E12737A214AE) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Screen_Class_Initialize_DD8ADBD9_574E_471A_9E35_119EB59D0485) },
    { be_const_key(Get_Active, 6), be_const_ctype_func(Berry_Screen_Class_Get_Active_5DF67B0B_E306_4C6B_A474_23C7A1F9F3DD) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Screen_Class_Create_60445515_13C5_4012_B1D7_A831BD954C94) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Screen_Class_Deinitialize_7386A94A_3C45_4A2B_9BCD_079ABEA35945) },
};

static be_define_const_map(
    Berry_Screen_Type_map,
    8
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Screen_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Screen_Type
);
