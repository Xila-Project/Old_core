#include "be_constobj.h"

static be_define_const_map_slots(Berry_Decoder_Type_map) {
    { be_const_key(Get_Configuration, -1), be_const_ctype_func(Berry_Decoder_Class_Get_Configuration_2FCC83D2_4731_4067_8C90_DD9F16B568F8) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Decoder_Class_Deinitialize_337EE1C5_440E_429B_9361_8D4DAED308FE) },
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
