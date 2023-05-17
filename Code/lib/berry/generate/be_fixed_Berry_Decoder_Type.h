#include "be_constobj.h"

static be_define_const_map_slots(Berry_Decoder_Type_map) {
    { be_const_key(Get_Configuration, -1), be_const_ctype_func(Berry_Decoder_Class_Get_Configuration_37EC197C_6B20_4CDF_8C0A_4B6B31FB01C3) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Decoder_Class_Deinitialize_D4513A0A_5FFC_4E16_B8BF_A4C58065D6B4) },
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
