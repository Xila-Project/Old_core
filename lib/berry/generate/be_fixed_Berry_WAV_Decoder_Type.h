#include "be_constobj.h"

static be_define_const_map_slots(Berry_WAV_Decoder_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_WAV_Decoder_Class_Initialize_99656F40_EEA4_4D46_8B83_DC3321BBA65A) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WAV_Decoder_Class_Deinitialize_53482198_DC2B_4277_9F4D_AA77B0A92756) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_WAV_Decoder_Type_map,
    3
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_WAV_Decoder_Type,
    1,
    NULL,
    WAV_Decoder_Type
);
