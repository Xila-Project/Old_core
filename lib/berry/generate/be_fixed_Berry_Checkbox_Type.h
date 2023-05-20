#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_D04B4594_2DA1_419B_86AF_C9CFE057A93B) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_B2F50A1C_C3F7_4905_BE03_B6EEABC104F5) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_03541199_5726_4BAF_8BDD_315113BD4A93) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_E43FDE20_D208_4F46_B4E0_9819C3E3A5E8) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_8A6C4A5E_8A61_4EB1_923F_420F58F236C6) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_B8C70242_8A13_4DE7_82BE_D2E182C9BE69) },
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
