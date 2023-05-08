#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_F49BDE5B_3FAD_44A5_AE13_5ACDCCCAADD1) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_D61C94A8_D7DD_4B88_BD6C_717D3BCE6901) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_C4C4E0D3_2B60_4F39_B60F_131005DA6CBA) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_2397C92F_FB7B_49DF_9351_12EA32723653) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_6410B8EA_0398_417A_B615_6303E844CF18) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_966A1EF6_136E_41EA_92AC_0E8246598270) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_34284702_98D2_4983_AF16_F863CC95C45F) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_59D14F09_AEA0_4D73_8C62_86198416C6F9) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_0BE7211C_2FBB_48A1_971C_8C72955678DB) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_AB3F019A_A256_473D_8248_34FD6A34E81B) },
};

static be_define_const_map(
    Berry_Roller_Type_map,
    11
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Roller_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Roller_Type
);
