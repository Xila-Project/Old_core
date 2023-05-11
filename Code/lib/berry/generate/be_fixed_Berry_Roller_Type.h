#include "be_constobj.h"

static be_define_const_map_slots(Berry_Roller_Type_map) {
    { be_const_key(Get_Selected_String, 3), be_const_ctype_func(Berry_Roller_Class_Get_Selected_String_84E4988E_46CA_4A7C_B3BE_D1EBB410BF9B) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Roller_Class_Get_Options_BFE6073B_0D71_4050_A12D_1C08189A204A) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Roller_Class_Deinitialize_52EE53FA_F772_41ED_835E_94CAB7959C2C) },
    { be_const_key(Get_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Get_Selected_FBBB2F54_23C6_4729_A685_42CD0BA55920) },
    { be_const_key(Create, 5), be_const_ctype_func(Berry_Roller_Class_Create_56A41044_056D_4799_A66F_491ECB2915DB) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Roller_Class_Set_Selected_2ED4E6D9_96BE_4F7C_8AB2_A1F761C93D50) },
    { be_const_key(Set_Visible_Row_Count, -1), be_const_ctype_func(Berry_Roller_Class_Set_Visible_Row_Count_281BBA60_9613_426D_B1BB_6D888DCF7315) },
    { be_const_key(_p, 10), be_const_var(0) },
    { be_const_key(Get_Option_Count, 4), be_const_ctype_func(Berry_Roller_Class_Get_Option_Count_A281E0F1_9D13_4D5B_895C_C7BBF96CCB27) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Roller_Class_Initialize_C78B01F1_E55B_4575_8207_1B36A90460DD) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Roller_Class_Set_Options_EAAD1185_78FD_4DF0_A7B4_934E892FA08D) },
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
