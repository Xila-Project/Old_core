#include "be_constobj.h"

static be_define_const_map_slots(Berry_WAV_Decoder_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_WAV_Decoder_Class_Initialize_6ED44695_855A_44DB_B446_C839B9B7F35C) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WAV_Decoder_Class_Deinitialize_9667D83F_B169_41DA_A9EC_4D3A1BC54F74) },
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
