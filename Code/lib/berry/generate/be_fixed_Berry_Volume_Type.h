#include "be_constobj.h"

static be_define_const_map_slots(Berry_Volume_Type_map) {
    { be_const_key(Get_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Get_Volume_71E926FB_EC0D_4684_B3F3_8800E73F8010) },
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Volume_Class_Begin_2967F586_3356_460C_9B95_D3B978CB11FF) },
    { be_const_key(Set_Volume, -1), be_const_ctype_func(Berry_Volume_Class_Set_Volume_FB32458C_C101_4E8D_B425_FEB898BEAD98) },
    { be_const_key(Get_Default_Configuration, 1), be_const_ctype_func(Berry_Volume_Class_Get_Default_Configuration_705A4847_DBD1_48A2_A327_D4005E550D4A) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Volume_Class_Initialize_B2952E23_DDC9_4E93_944B_244205FD4932) },
    { be_const_key(deinit, 4), be_const_ctype_func(Berry_Volume_Class_Deinitialize_C66EEC19_01FA_440B_9C54_B6F355618858) },
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
