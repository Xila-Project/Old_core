#include "be_constobj.h"

static be_define_const_map_slots(Berry_Stream_Type_map) {
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Stream_Class_Begin_01BD297F_58A1_40AA_BA85_FF1167FFAD10) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Notify_Audio_Change, 1), be_const_ctype_func(Berry_Stream_Class_Set_Notify_Audio_Change_CA623722_0D3B_4166_90ED_94032B6BA565) },
    { be_const_key(Set_Configuration, 0), be_const_ctype_func(Berry_Stream_Class_Set_Configuration_B90C3E79_1E66_4ABB_9CC8_050CD242ED7F) },
    { be_const_key(End, -1), be_const_ctype_func(Berry_Stream_Class_End_D2384D31_3BFF_4412_9C61_6195EC9D0327) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Stream_Class_Deinitialize_6456AEDF_E023_4C11_BCC2_DC4916A07D4F) },
    { be_const_key(Get_Configuration, 2), be_const_ctype_func(Berry_Stream_Class_Get_Configuration_CDF835CD_2776_4C8E_88E2_623D1BB17E66) },
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
