#include "be_constobj.h"

static be_define_const_map_slots(m_libClipboard_map) {
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Clipboard_Class_Start_AB52E442_D5D3_4C3E_9867_27379F387270) },
    { be_const_key(Clear, -1), be_const_ctype_func(Berry_Clipboard_Class_Clear_DF3777E0_5D4E_4DE8_A410_5C2610387CE9) },
    { be_const_key(Copy, -1), be_const_ctype_func(Berry_Clipboard_Class_Copy_506F0E26_A045_45D9_B259_C1F3B3BCF57B) },
    { be_const_key(Get_Pointer, 0), be_const_ctype_func(Berry_Clipboard_Class_Get_Pointer) },
    { be_const_key(Paste, 1), be_const_ctype_func(Berry_Clipboard_Class_Paste_3231D5A1_04B5_4E08_BA8F_EB17AA0BF666) },
    { be_const_key(Stop, -1), be_const_ctype_func(Berry_Clipboard_Class_Stop_FD06D5AF_1BBC_4CC9_B47C_55DFEA1A2220) },
};

static be_define_const_map(
    m_libClipboard_map,
    6
);

static be_define_const_module(
    m_libClipboard,
    "Clipboard"
);

BE_EXPORT_VARIABLE be_define_const_native_module(Clipboard);
