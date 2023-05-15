#include "be_constobj.h"

static be_define_const_map_slots(Berry_Stream_Type_map) {
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Stream_Class_Begin_40540A38_52DE_449C_8228_869FB954D2DF) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Notify_Audio_Change, 1), be_const_ctype_func(Berry_Stream_Class_Set_Notify_Audio_Change_8725C760_68FF_4E2B_BEB9_175F643E5B57) },
    { be_const_key(Set_Configuration, 0), be_const_ctype_func(Berry_Stream_Class_Set_Configuration_6722298E_369D_418D_86A0_3286BF5811E3) },
    { be_const_key(End, -1), be_const_ctype_func(Berry_Stream_Class_End_8C8462DC_4287_4048_849D_22C9340907A3) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Stream_Class_Deinitialize_0F2A3A74_D76D_4447_9F6F_C0EF58FD7E38) },
    { be_const_key(Get_Configuration, 2), be_const_ctype_func(Berry_Stream_Class_Get_Configuration_EA3FBCDC_47C8_4CF6_BA88_EB84D337B62A) },
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
