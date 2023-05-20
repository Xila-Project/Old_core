#include "be_constobj.h"

static be_define_const_map_slots(Berry_Stream_Type_map) {
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Stream_Class_Begin_C2E0C403_64CF_41A9_8FE3_662DCA7824FB) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Notify_Audio_Change, 1), be_const_ctype_func(Berry_Stream_Class_Set_Notify_Audio_Change_E8341B52_BD60_4C09_BBF1_6C60B1247AD5) },
    { be_const_key(Set_Configuration, 0), be_const_ctype_func(Berry_Stream_Class_Set_Configuration_9E16E7EC_6340_461C_AC2B_4CD252144663) },
    { be_const_key(End, -1), be_const_ctype_func(Berry_Stream_Class_End_70D4EDC9_A613_494C_BDE1_D32947D15724) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Stream_Class_Deinitialize_62ACE6F5_99A5_47EF_800A_B48EA9520688) },
    { be_const_key(Get_Configuration, 2), be_const_ctype_func(Berry_Stream_Class_Get_Configuration_B01A749F_85BE_490E_82D8_2539A13D0D4C) },
};

static be_define_const_map(
    Berry_Stream_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Stream_Type,
    1,
    NULL,
    Stream_Type
);
