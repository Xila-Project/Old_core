#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_74034574_0173_4B62_9718_647759A3F104) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_2DD23FB7_FAB4_44D7_95F3_A2E8760FC1C4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_1DC73EBC_DC7F_4161_AE86_615A42EEE21A) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_76FBC21F_EA86_472B_A8A2_0E6A78924801) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_ABB590BE_2301_4C06_82E1_E754E0F25AAD) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_461710A6_74C3_44D5_9C35_96F512F48EC4) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_FDF6A7B8_1FA8_4D17_9F79_C7F92BCD8C9A) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_5DF9EE6F_D719_4CAD_81A9_C82244798557) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_48259618_1763_4C70_8B17_CE0AE49FA291) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_57474EC7_87F9_46A0_96B5_39402860C485) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_61D4337A_93E8_456C_AB04_EEC43D36ABBD) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_D8A1E6A9_3122_4C38_BC85_E9E2AEF9DB35) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_ED57DACB_20B5_4F55_BFDA_657BF362C7BA) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_EEB65033_2C82_403B_B193_0DA05D07BBF3) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_883F0495_9A7A_42FE_9F7A_70A5661B7470) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_4642AE4A_D3F2_455A_95A7_BF123867A5DA) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_A4236781_1A31_4D26_BE87_CDB464362F40) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_980CA235_2F88_4356_A9E4_9A5E28FD3CD3) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_A4306AFB_5F3F_4F91_BD5C_6DAF2AF92CB9) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_38E743C2_0E23_4D16_B577_6FEE16C6483D) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_B7C62404_B04A_48CE_AD37_9A40F9424346) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_231C93DE_139F_4D1C_9528_9D38892F2931) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_D4D08141_CF47_41DF_9DE5_95F10E9A7950) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_19F319BE_563E_4B7E_9F1E_7525079D2F5B) },
};

static be_define_const_map(
    Berry_Drop_Down_List_Type_map,
    25
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Drop_Down_List_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Drop_Down_List_Type
);
