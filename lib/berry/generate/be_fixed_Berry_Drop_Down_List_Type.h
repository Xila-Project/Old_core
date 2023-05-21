#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_5A412A6B_499C_4C6A_A5F7_3B95A0B0B5F3) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_9DBB1CCF_6733_496F_AC2D_38AD8CB6A7C4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_DABE32E9_59FD_4889_824C_C73624CA352A) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_577D3244_7EAC_43F6_AD64_3B360CB633BA) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_5001779B_B0B6_4B9E_97D3_1C894BB5C4CB) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_AF876D04_A01D_473A_94C9_7CD1CA855E48) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_AF4CF558_7361_43E3_81BC_8A63288A1A35) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_5ADA2A24_BDFD_4B02_AA08_B17134DA58E7) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_9DF93ABA_F133_4CE7_8A95_348FD948D81F) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_E38265F5_43C0_4259_9574_6E3786E33215) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_35736D3D_79CA_492C_84B9_2154AA41E901) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_85B76E09_935A_4933_A01B_D1016667AE45) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_08DB252E_B104_472A_B33B_9EA42F63016D) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_6B94B460_029D_40E0_9C91_DDA2871F72D6) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_EB9B1D62_6F6F_4781_A61C_021986F32FE6) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_D723BCB1_32B2_4379_9878_289E664A0206) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_574292B5_0FF0_4D1E_A715_A3E716287492) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_5C2704F2_A740_4A1B_B0A8_CB0EB2C2C808) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_819FFDF6_EF3E_4C0A_BF7B_33DF64B2CB2A) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_4ED7ECBC_65E3_42AA_8988_C6AE17AC3591) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_A42E30DC_AFFD_443A_AF68_2DF2849CA264) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_3A545FA5_6989_4767_BE42_5CF77D59E5CC) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_32E7F00B_A478_4DCF_931D_802665238FB4) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_0D58D740_D0C3_40A3_A5F1_8EAA769E06D6) },
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
