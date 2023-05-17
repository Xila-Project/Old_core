#include "be_constobj.h"

static be_define_const_map_slots(m_libClipboard_map) {
    { be_const_key(Start, -1), be_const_ctype_func(Berry_Clipboard_Class_Start_0135C718_23CA_439E_9652_1532E171CAE1) },
    { be_const_key(Clear, -1), be_const_ctype_func(Berry_Clipboard_Class_Clear_3B8A16ED_123B_41A8_A9BB_D170EDBF3218) },
    { be_const_key(Copy, -1), be_const_ctype_func(Berry_Clipboard_Class_Copy_081C12F8_15FB_41AB_A577_34382ECFD23E) },
    { be_const_key(Get_Pointer, 0), be_const_ctype_func(Berry_Clipboard_Class_Get_Pointer) },
    { be_const_key(Paste, 1), be_const_ctype_func(Berry_Clipboard_Class_Paste_34FA2BB3_AEFD_4632_8899_7B1B89BD5F00) },
    { be_const_key(Stop, -1), be_const_ctype_func(Berry_Clipboard_Class_Stop_BA742C0E_89A8_4166_B97A_1FC32BBF51E0) },
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
