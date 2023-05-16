#include "be_constobj.h"

static be_define_const_map_slots(Berry_Stream_Type_map) {
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Stream_Class_Begin_11ADBB03_8280_4912_85A6_C9FFE1313001) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Notify_Audio_Change, 1), be_const_ctype_func(Berry_Stream_Class_Set_Notify_Audio_Change_A7CF0A4E_4EF2_40CD_9655_ACAAB8E69896) },
    { be_const_key(Set_Configuration, 0), be_const_ctype_func(Berry_Stream_Class_Set_Configuration_AD1A42DC_A641_459C_9BC9_65C9134EA57A) },
    { be_const_key(End, -1), be_const_ctype_func(Berry_Stream_Class_End_91708FEE_B393_450D_AFB8_2E663FE81352) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Stream_Class_Deinitialize_4371F19B_D5FB_49F5_80E2_6CC7E31F8ED7) },
    { be_const_key(Get_Configuration, 2), be_const_ctype_func(Berry_Stream_Class_Get_Configuration_3B6C028E_6CB7_4B38_893B_EEFAA21206D8) },
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
