#include "be_constobj.h"

static be_define_const_map_slots(m_libClipboard_map) {
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Clipboard_Class_Start_04532504_6487_4C2A_A0F3_21095FE7A455) },
    { be_const_key(Clear, -1), be_const_ctype_func(Berry_Clipboard_Class_Clear_5198F681_A885_4E52_BCF2_92CAA5B0EF42) },
    { be_const_key(Copy, -1), be_const_ctype_func(Berry_Clipboard_Class_Copy_0DE8CC69_6035_46BF_A4C5_0A9E67465DB6) },
    { be_const_key(Get_Pointer, 0), be_const_ctype_func(Berry_Clipboard_Class_Get_Pointer) },
    { be_const_key(Paste, 1), be_const_ctype_func(Berry_Clipboard_Class_Paste_41E80EC6_DC63_4B56_98FF_BD49D2B69F06) },
    { be_const_key(Stop, -1), be_const_ctype_func(Berry_Clipboard_Class_Stop_47F46CC1_2010_437B_B13E_834436E9BB17) },
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
