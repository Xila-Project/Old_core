#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_0FCC1DE1_B969_4CC7_BBB6_9F72AE237DDB) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_AA32C08C_E205_43EF_ADD3_6979873D048C) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_0BA23D50_E23C_41FF_A19F_E3A5CF6289A9) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_C920194C_0627_42F0_9BBF_8782BB2FA7B8) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_C6E91E36_D4BC_41F4_9FCE_57B05AA42981) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_A9099593_A135_420A_A099_F904C96D46D7) },
    { be_const_key(_p, -1), be_const_var(0) },
};

static be_define_const_map(
    Berry_Checkbox_Type_map,
    7
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Checkbox_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Checkbox_Type
);
