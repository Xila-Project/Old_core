#include "be_constobj.h"

static be_define_const_map_slots(Berry_Stream_Type_map) {
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Stream_Class_Begin_7D001644_493A_4F0C_8554_32F9B78FAF4A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Notify_Audio_Change, 1), be_const_ctype_func(Berry_Stream_Class_Set_Notify_Audio_Change_08E15504_7211_443A_B1A4_A925A9997386) },
    { be_const_key(Set_Configuration, 0), be_const_ctype_func(Berry_Stream_Class_Set_Configuration_C39CBF39_39AB_4C6C_B4CE_C559ADDD2BCB) },
    { be_const_key(End, -1), be_const_ctype_func(Berry_Stream_Class_End_7C3774CF_9929_42BA_9B36_50022474A3A7) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Stream_Class_Deinitialize_9AB61937_0BDB_4B7F_B673_BDA65FD3B7AF) },
    { be_const_key(Get_Configuration, 2), be_const_ctype_func(Berry_Stream_Class_Get_Configuration_0E710A2F_3D97_4377_949C_1941D89FC8AC) },
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
