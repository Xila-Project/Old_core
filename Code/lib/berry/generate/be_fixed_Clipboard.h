#include "be_constobj.h"

static be_define_const_map_slots(m_libClipboard_map) {
    { be_const_key(Clear, -1), be_const_ctype_func(Berry_Clipboard_Class_Clear_4EA9C446_EDAA_4323_9657_EE646FA4C652) },
    { be_const_key(Paste, 4), be_const_ctype_func(Berry_Clipboard_Class_Paste_E78C465C_DCBA_490D_BDFE_EE2839B371BD) },
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Clipboard_Class_Start_1E89A984_53DB_4F03_AD40_D4E4F60178E9) },
    { be_const_key(Copy, 2), be_const_ctype_func(Berry_Clipboard_Class_Copy_DB703EB4_A1B7_4623_B7CC_3564AC3482C0) },
    { be_const_key(Stop, -1), be_const_ctype_func(Berry_Clipboard_Class_Stop_FA1DEB2C_34FE_4ED8_AF48_BFBB3BA592D4) },
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
