#include "be_constobj.h"

static be_define_const_map_slots(Berry_Table_Type_map) {
    { be_const_key(Get_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Get_Cell_Value_E7606765_2CE8_4A8B_AFD4_893D0DC7DB6C) },
    { be_const_key(Has_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Has_Cell_Control_DBB1F72F_80B2_40B2_913C_1D8F641C51D5) },
    { be_const_key(Get_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Get_Column_Count_8B947731_B04D_4DFC_8C01_ED11C19EFF38) },
    { be_const_key(Set_Column_Width, 5), be_const_ctype_func(Berry_Table_Class_Set_Column_Width_317A21B4_6E8F_4F04_9E06_5BB86F78A7B1) },
    { be_const_key(Get_Row_Count, 3), be_const_ctype_func(Berry_Table_Class_Get_Row_Count_AB8530C6_0FBE_4A0F_AC8C_D5FB000D432E) },
    { be_const_key(Set_Row_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Row_Count_4BDFD0E9_40F9_480A_AC26_445E7F8B3938) },
    { be_const_key(Add_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Add_Cell_Control_7752884B_DBB3_40EF_88B4_B70178881734) },
    { be_const_key(Get_Selected_Cell_Column, -1), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Column_C37BE4D2_A7D9_49F6_A5EB_F8FB189B6528) },
    { be_const_key(Get_Selected_Cell_Row, 2), be_const_ctype_func(Berry_Table_Class_Get_Selected_Cell_Row_0F0BF451_6500_4B50_950E_946136F012DF) },
    { be_const_key(Get_Column_Width, 16), be_const_ctype_func(Berry_Table_Class_Get_Column_Width_7B1D016D_3179_41EA_B702_356E8D33001A) },
    { be_const_key(Set_Column_Count, -1), be_const_ctype_func(Berry_Table_Class_Set_Column_Count_05917863_EBE1_4761_AC84_919AE71B1D3D) },
    { be_const_key(deinit, 14), be_const_ctype_func(Berry_Table_Class_Deinitialize_70FE1923_BA5D_4366_918F_1C8F6D3E582C) },
    { be_const_key(Clear_Cell_Control, -1), be_const_ctype_func(Berry_Table_Class_Clear_Cell_Control_74A685E7_A1F3_4882_9763_9139D735051C) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Cell_Value, -1), be_const_ctype_func(Berry_Table_Class_Set_Cell_Value_19CADAFB_B908_4C42_B6D8_B2E5A4309925) },
    { be_const_key(init, 0), be_const_ctype_func(Berry_Table_Class_Initialize_E19B2EE8_9E2A_4DB3_BD87_5A1645AEF19A) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Table_Class_Create_B7B20FA6_C9CA_4165_AAF3_772D401EC0D1) },
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
