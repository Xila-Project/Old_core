#include "be_constobj.h"

static be_define_const_map_slots(Berry_WAV_Decoder_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_WAV_Decoder_Class_Initialize_432389AD_F1F7_4E16_93D6_7F253A81B851) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WAV_Decoder_Class_Deinitialize_1D4CD908_E2C7_4BE5_804F_028B08CA25F2) },
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
