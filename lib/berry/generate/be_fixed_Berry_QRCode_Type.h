#include "be_constobj.h"

static be_define_const_map_slots(Berry_QRCode_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_QRCode_Class_Initialize_F359CA24_1353_4F4E_8366_DC1FE175333E) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(deinit, 3), be_const_ctype_func(Berry_QRCode_Class_Deinitialize_9BE98AC0_D236_4557_86E5_3F584779DA22) },
    { be_const_key(Update, 1), be_const_ctype_func(Berry_QRCode_Class_Update_2EAD79C2_D6F8_441F_BBF0_1141EFB5575A) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_QRCode_Class_Create_907242A9_F9DF_4FBF_AEAE_A05529D69DED) },
};

static be_define_const_map(
    Berry_QRCode_Type_map,
    5
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_QRCode_Type,
    1,
    (bclass *)&Berry_Object_Type,
    QRCode_Type
);
