#include "be_constobj.h"

static be_define_const_map_slots(m_libClipboard_map) {
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Clipboard_Class_Start_B468DBB1_297A_42A2_95B7_B01D66EFB5D2) },
    { be_const_key(Clear, -1), be_const_ctype_func(Berry_Clipboard_Class_Clear_66497560_B8CF_46B6_8405_3CCC2551E9D9) },
    { be_const_key(Copy, -1), be_const_ctype_func(Berry_Clipboard_Class_Copy_BA164F50_687F_4DCD_AA10_59FE9F5DD0FD) },
    { be_const_key(Get_Pointer, 0), be_const_ctype_func(Berry_Clipboard_Class_Get_Pointer) },
    { be_const_key(Paste, 1), be_const_ctype_func(Berry_Clipboard_Class_Paste_03C0FF05_B194_45CD_B8C3_B358BCB313CF) },
    { be_const_key(Stop, -1), be_const_ctype_func(Berry_Clipboard_Class_Stop_DAD9CC89_595F_48F3_88D2_53422B18DE2C) },
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
