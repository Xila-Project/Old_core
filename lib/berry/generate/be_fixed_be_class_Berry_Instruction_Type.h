#include "be_constobj.h"

static be_define_const_map_slots(be_class_Berry_Instruction_Type_map) {
    { be_const_key(Get_Sender, -1), be_const_ctype_func(Berry_Instruction_Class_Get_Sender) },
    { be_const_key(_p, 5), be_const_var(0) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Instruction_Class_Deinitialize) },
    { be_const_key(Graphics_Get_Current_Target, 10), be_const_ctype_func(Berry_Instruction_Class_Graphics_Get_Current_Target) },
    { be_const_key(Softwares_Get_Code, 8), be_const_ctype_func(Berry_Instruction_Class_Softwares_Get_Code) },
    { be_const_key(Set_Receiver, -1), be_const_ctype_func(Berry_Instruction_Class_Set_Receiver) },
    { be_const_key(Get_Receiver, -1), be_const_ctype_func(Berry_Instruction_Class_Get_Receiver) },
    { be_const_key(Graphics_Get_Target, -1), be_const_ctype_func(Berry_Instruction_Class_Graphics_Get_Target) },
    { be_const_key(Set_Sender, -1), be_const_ctype_func(Berry_Instruction_Class_Set_Sender) },
    { be_const_key(init, 7), be_const_ctype_func(Berry_Instruction_Class_Initialize) },
    { be_const_key(Graphics_Get_Code, -1), be_const_ctype_func(Berry_Instruction_Class_Graphics_Get_Code) },
};

static be_define_const_map(
    be_class_Berry_Instruction_Type_map,
    11
);

BE_EXPORT_VARIABLE be_define_const_class(
    be_class_Berry_Instruction_Type,
    1,
    NULL,
    Instruction_Type
);
