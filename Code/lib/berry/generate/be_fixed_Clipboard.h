#include "be_constobj.h"

static be_define_const_map_slots(m_libClipboard_map) {
    { be_const_key(Clear, -1), be_const_ctype_func(Berry_Clipboard_Class_Clear_4DCF47A6_A142_49CC_95DB_9E1EC38981A9) },
    { be_const_key(Paste, 4), be_const_ctype_func(Berry_Clipboard_Class_Paste_37173641_6F3C_4D36_AB61_35D690C67B09) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Clipboard_Class_Start_51A27859_A5EB_49E5_BEBF_5C76B1A69D2B) },
    { be_const_key(Copy, 2), be_const_ctype_func(Berry_Clipboard_Class_Copy_D4567252_CC79_4F04_9838_6E67389821DA) },
    { be_const_key(Stop, -1), be_const_ctype_func(Berry_Clipboard_Class_Stop_DB0379C2_3ADD_4C19_9EC4_A9D01CB9BF34) },
};

static be_define_const_map(
    m_libClipboard_map,
    5
);

static be_define_const_module(
    m_libClipboard,
    "Clipboard"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Clipboard);
