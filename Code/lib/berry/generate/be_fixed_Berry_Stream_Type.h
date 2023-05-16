#include "be_constobj.h"

static be_define_const_map_slots(Berry_Stream_Type_map) {
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Stream_Class_Begin_3BA22E3C_6679_4354_9054_5A8EEB9F0F13) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Notify_Audio_Change, 1), be_const_ctype_func(Berry_Stream_Class_Set_Notify_Audio_Change_D95CC92A_7CA0_479B_92E8_F336CDFD6425) },
    { be_const_key(Set_Configuration, 0), be_const_ctype_func(Berry_Stream_Class_Set_Configuration_4434C844_CB84_4BFE_AD7F_1751F32FF604) },
    { be_const_key(End, -1), be_const_ctype_func(Berry_Stream_Class_End_6EA8AF75_189D_46BD_A000_B34AEF3C4CB3) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Stream_Class_Deinitialize_B9AACD49_5A4C_45D2_8738_D07B62BBE195) },
    { be_const_key(Get_Configuration, 2), be_const_ctype_func(Berry_Stream_Class_Get_Configuration_285321CD_7974_41DC_BAC8_8D3C65F4590E) },
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
