#include "be_constobj.h"

static be_define_const_map_slots(Berry_Decoder_Type_map) {
    { be_const_key(Get_Configuration, -1), be_const_ctype_func(Berry_Decoder_Class_Get_Configuration_7CCE6473_0B4E_4CF5_8C9E_77548F68D01F) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Decoder_Class_Deinitialize_9DB6B30C_D774_4B09_983B_1B079A92AC36) },
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
