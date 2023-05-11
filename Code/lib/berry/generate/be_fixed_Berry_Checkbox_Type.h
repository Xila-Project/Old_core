#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_24193845_022E_414C_82EE_7D498D12F219) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_B37AB58F_FDBE_4A41_8C13_D573A82DE036) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_1EEBD920_E3CC_4C21_94DE_66E29B06ECC1) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_112BF91F_1D05_45F7_9AD2_8D99A0C2935B) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_2A2F4FC2_89DC_41CB_A4C8_0C761B1630D4) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_76A68B5A_3D6D_48CB_91AF_CEFAF662F8B1) },
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
