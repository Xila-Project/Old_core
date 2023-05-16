#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_EBFFAD11_E5BE_4CEC_B776_70CF38DC7E57) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_F75B0C8A_565A_4B6B_88FC_B23542BF6438) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_F71DE841_44E0_40CA_A27D_7AF01609F231) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_D4353D26_C457_4213_A68C_AAB51C16DF7B) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_D9B36AD2_7B21_4923_B3FB_77C2C24E24E3) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_9AD62E0C_2D14_4504_BF9A_B96FCA653F80) },
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
