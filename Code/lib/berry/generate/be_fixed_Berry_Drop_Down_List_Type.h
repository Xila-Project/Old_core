#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_9CC31D1E_EC92_46F1_B68B_76A04E944D74) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_F13484DA_0121_427E_9F37_3DB591E751A8) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_595C9245_4871_4CB6_B22C_56637C434141) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_56406D26_0ED0_4BB9_A31D_2EDC213803F8) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_A698D926_423F_41C5_9023_762D9395C581) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_46CE5D0D_1C25_489A_A8C7_A3F81071F8A0) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_32F7ABA4_20DA_4DAF_BA3C_E133E6448D41) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_DEB39D51_325D_4B32_86CA_8BEF7191F3B4) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_3472CB6F_5F3E_4C05_B0BD_5C74C0C71472) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_DC6C9E7B_D5CA_4778_80F4_6C625CB2C2FC) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_B7760238_21BE_4975_AD03_288509E3C1DC) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_2DACE73E_8DBD_4F0B_B98D_73BBD3553562) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_6EA1EECF_7F03_4982_88DC_D8DAF7F7CBE6) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_BC581284_01F4_44C5_932C_990EDDAD049B) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_4576533D_A0BC_4DF4_8556_1594433C849D) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_7F9DA1AA_E07D_4677_A042_0A02BE44C97D) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_1A62AD57_2F1A_4021_8108_A4DCC6196BE6) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_8703151F_0B90_47B5_8EBE_6DB921FD6729) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_46FD5847_4DD2_44B0_AD75_CD62D392CE8F) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_CCA9C63E_3D6C_4E3B_89B7_A2626178D2DF) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_6E847385_1E62_4B1C_AE4C_0075198DCC6A) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_B5B2458D_7421_4C55_92F8_6771BAA9601C) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_18F7EBE7_F323_4E19_AF22_19E414C2E864) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_C5C8C304_050E_4EDF_A25D_E38F0E413EFC) },
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
