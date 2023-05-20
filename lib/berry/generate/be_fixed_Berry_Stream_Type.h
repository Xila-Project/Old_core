#include "be_constobj.h"

static be_define_const_map_slots(Berry_Stream_Type_map) {
    { be_const_key(Begin, -1), be_const_ctype_func(Berry_Stream_Class_Begin_6A0B789C_4E59_4C37_ACE9_1C9A9E68C656) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Notify_Audio_Change, 1), be_const_ctype_func(Berry_Stream_Class_Set_Notify_Audio_Change_13319474_AA05_4EE0_BAD8_CBB451E5E598) },
    { be_const_key(Set_Configuration, 0), be_const_ctype_func(Berry_Stream_Class_Set_Configuration_F52FE95F_2AB7_4F0D_8DCA_7ED949156F5D) },
    { be_const_key(End, -1), be_const_ctype_func(Berry_Stream_Class_End_688788BD_FD4E_419D_8B9A_0A35A6001F86) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Stream_Class_Deinitialize_01033885_C873_4B51_93AD_207A810F5AE3) },
    { be_const_key(Get_Configuration, 2), be_const_ctype_func(Berry_Stream_Class_Get_Configuration_542286A4_D004_4DC9_A79C_91B1287AE1D5) },
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
