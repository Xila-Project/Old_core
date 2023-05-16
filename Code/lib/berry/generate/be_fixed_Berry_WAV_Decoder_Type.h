#include "be_constobj.h"

static be_define_const_map_slots(Berry_WAV_Decoder_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_WAV_Decoder_Class_Initialize_9E765027_4BA0_45BE_97C8_8513AF6CEAEA) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WAV_Decoder_Class_Deinitialize_34E473AD_1CC8_45D1_A900_28EDE8ADCFA2) },
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
