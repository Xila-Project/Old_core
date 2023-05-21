#include "be_constobj.h"

static be_define_const_map_slots(Berry_Checkbox_Type_map) {
    { be_const_key(init, 1), be_const_ctype_func(Berry_Checkbox_Class_Initialize_C91742DE_982E_4CF9_B43A_12718B116ACB) },
    { be_const_key(Set_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_91AE904E_A976_4ECE_87FC_42F1D587FA9F) },
    { be_const_key(Create, 0), be_const_ctype_func(Berry_Checkbox_Class_Create_20E8F945_2CBB_42FA_97EB_17DFD36C902C) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Checkbox_Class_Get_Text_613BC34A_2D74_4606_80E7_02952130CE8E) },
    { be_const_key(Set_Text_Static, -1), be_const_ctype_func(Berry_Checkbox_Class_Set_Text_Static_C786DBFE_1852_43B9_A9CA_6DE34871466F) },
    { be_const_key(deinit, 2), be_const_ctype_func(Berry_Checkbox_Class_Deinitialize_5B4B53BD_AE16_47A8_B320_F4520B9D650B) },
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
