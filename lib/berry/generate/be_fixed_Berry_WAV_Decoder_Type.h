#include "be_constobj.h"

static be_define_const_map_slots(Berry_WAV_Decoder_Type_map) {
    { be_const_key(init, -1), be_const_ctype_func(Berry_WAV_Decoder_Class_Initialize_DCDA6E89_1DFB_44C5_9B0A_F903F913BEB8) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_WAV_Decoder_Class_Deinitialize_AD70DC4B_3B3F_43E6_BD7D_1D779A25C08F) },
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
