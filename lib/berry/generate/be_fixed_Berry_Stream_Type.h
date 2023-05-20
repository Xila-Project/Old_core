#include "be_constobj.h"

static be_define_const_map_slots(Berry_Stream_Type_map) {
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Stream_Class_Begin_49F4D136_7FDC_4EC9_A695_4DD5A61B1D2E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Notify_Audio_Change, 1), be_const_ctype_func(Berry_Stream_Class_Set_Notify_Audio_Change_D72FE37E_B5E7_4CFE_B155_7DA5A01693B4) },
    { be_const_key(Set_Configuration, 0), be_const_ctype_func(Berry_Stream_Class_Set_Configuration_F166703B_2767_4CBC_B5C2_2572A40046FD) },
    { be_const_key(End, -1), be_const_ctype_func(Berry_Stream_Class_End_B3F8F878_D092_442D_A800_EB9E0E7C69B2) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Stream_Class_Deinitialize_1BA10912_D7F6_48AF_9923_8BA19E8B7542) },
    { be_const_key(Get_Configuration, 2), be_const_ctype_func(Berry_Stream_Class_Get_Configuration_41A1B439_9FC8_4C64_9E6C_1CC85101D9A0) },
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
