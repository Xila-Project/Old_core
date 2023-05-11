#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_DE02A554_17D0_4E3F_ACCF_1C3CE7335A34) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_2BB6A7C1_E454_4930_970C_44927D809E16) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_C8585F4E_1257_489A_8C2E_3B8E26C0EC88) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_CC2ECD65_23D4_46D4_9734_EB0FF3DBA89F) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_8C269640_A42F_4F53_90C6_6F7B53B5C786) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_C5BBBC0D_DB0A_4723_A5BD_5841B161446E) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_616F3946_A254_47B1_A3E4_43E9C6012E79) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_2DC86D24_E1DF_41F2_8C6C_564E8051B213) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_821F8CF7_AE05_4441_A7EF_CEC385AB9271) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_3F781C7C_5415_4FF7_8263_1049E2F8FBCA) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_21692274_8B17_4A50_A6B7_E06FA18B7A70) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_884CD9D9_9C3C_47CF_BCDF_5779B3BD44AC) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_55E0B974_FE50_48E7_B9BB_57C478616D23) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_94531B66_ED2F_4DBF_BD06_A7BD023E9F9C) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_35EF9BF8_0410_464F_96A2_CABC5AA9521D) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_BF0D1B98_2494_4339_801F_EEC23B8C62E6) },
};

static be_define_const_map(
    Berry_Table_Type_map,
    17
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Table_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Table_Type
);
