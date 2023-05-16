#include "be_constobj.h"

static be_define_const_map_slots(Berry_Decoder_Type_map) {
    { be_const_key(Get_Configuration, -1), be_const_ctype_func(Berry_Decoder_Class_Get_Configuration_06F30D34_5A2B_4FF0_B722_F9E1FADD5416) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Decoder_Class_Deinitialize_7DF739AE_FCB2_4263_91D1_93804895AB97) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Decoder_Type_map,
    3
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Decoder_Type,
    1,
    NULL,
    Decoder_Type
);
