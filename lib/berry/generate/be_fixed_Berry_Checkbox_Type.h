#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_FF452BD3_086C_47A5_9D9E_4AA8EE6641D5) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_1262EAED_03BB_4BCF_AA5F_4151DCBCF3C1) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_5341556C_AE53_433A_AD72_103D43007876) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_402B01F3_C437_4B81_8DC2_F01ED60A599F) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_2EC8480F_C61B_47D4_8A86_4A401C1A5505) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_4251986B_E64C_4790_9C66_5844AB3D737B) },
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
