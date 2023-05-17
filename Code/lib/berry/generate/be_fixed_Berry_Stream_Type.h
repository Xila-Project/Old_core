#include "be_constobj.h"

static be_define_const_map_slots(Berry_Stream_Type_map) {
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Stream_Class_Begin_5DF3A673_CA9B_4A5B_B6BE_E4826515BAA0) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Notify_Audio_Change, 1), be_const_ctype_func(Berry_Stream_Class_Set_Notify_Audio_Change_45936D08_7E8C_4128_A04E_28A38A0DF3EF) },
    { be_const_key(Set_Configuration, 0), be_const_ctype_func(Berry_Stream_Class_Set_Configuration_C0362BB9_3E4F_4704_9ED7_61480684567D) },
    { be_const_key(End, -1), be_const_ctype_func(Berry_Stream_Class_End_1056EBC4_5371_4BF2_94E9_736A1AF4B071) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Stream_Class_Deinitialize_301AA7F2_867E_4683_868A_040FF4C072C1) },
    { be_const_key(Get_Configuration, 2), be_const_ctype_func(Berry_Stream_Class_Get_Configuration_CABF1483_AD4F_41FA_A656_CE37312F2589) },
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
