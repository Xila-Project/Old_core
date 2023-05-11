#include "be_constobj.h"

static be_define_const_map_slots(m_libClipboard_map) {
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Clipboard_Class_Start_2879F0CE_031D_477D_9D72_B0059ECF9AA4) },
    { be_const_key(Clear, -1), be_const_ctype_func(Berry_Clipboard_Class_Clear_A4C6BB4A_B7F5_4CF7_9C7D_1349233CB7C4) },
    { be_const_key(Copy, -1), be_const_ctype_func(Berry_Clipboard_Class_Copy_8E061566_456D_4FA3_95ED_792462FBB110) },
    { be_const_key(Get_Pointer, 0), be_const_ctype_func(Berry_Clipboard_Class_Get_Pointer) },
    { be_const_key(Paste, 1), be_const_ctype_func(Berry_Clipboard_Class_Paste_C479B7FC_F33E_4FF8_861B_49F47ECDED65) },
    { be_const_key(Stop, -1), be_const_ctype_func(Berry_Clipboard_Class_Stop_E1C72402_A9C8_4407_8BE1_D195926F0986) },
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
