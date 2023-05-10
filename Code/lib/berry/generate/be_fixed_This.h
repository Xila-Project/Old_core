#include "be_constobj.h"

static be_define_const_map_slots(m_libThis_map) {
    { be_const_key(Delay, 2), be_const_ctype_func(Berry_This_Delay) },
    { be_const_key(Get_Instruction, -1), be_const_ctype_func(Berry_This_Get_Instruction) },
    { be_const_key(Get_Window, 1), be_const_ctype_func(Berry_This_Get_Window) },
    { be_const_key(Instruction_Available, -1), be_const_ctype_func(Berry_This_Instruction_Available) },
};

static be_define_const_map(
    m_libThis_map,
    4
);

static be_define_const_module(
    m_libThis,
    "This"
);

BE_EXPORT_VARIABLE be_define_const_native_module(This);
