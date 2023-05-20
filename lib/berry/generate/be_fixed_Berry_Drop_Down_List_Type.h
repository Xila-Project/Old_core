#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_FFEA4228_F501_4EFB_9D1F_8497845629AE) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_DF438252_0D05_457C_B0EA_461E9CCFF814) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_C7933178_F495_49A4_BEE7_2D71D8D9D8B5) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_2DB60727_8D54_424E_BCAA_00464EA6C9A7) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_67C24FF7_1132_4365_A29D_BF2CD80B9CAD) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_29B5B808_E587_4F76_9C4C_A8F361DDE72D) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_23EECD4F_DDC0_4FD8_A61E_0894DB0F808B) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_D2630B6F_AADD_4422_B1AA_B2E3FAD84283) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_3BA9FCB0_FCB8_4488_8D22_9DB236740889) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_617D3D59_82F3_4675_8D13_0F25E766BA55) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_75E543F4_D5A3_4EAE_AD80_1708C679DDE8) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_FDFBB5F8_BAAD_4B4E_8379_4EFB049D85EC) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_5202C94E_B180_4D4A_8CDB_E5B55145BCE5) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_718E6BAC_C255_4107_9920_DF62B217B411) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_73745137_5C15_4014_A05D_AB615A818E8D) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_144DD239_E3EC_4976_A1AA_56C56CFE2123) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_F5CC2B19_36D0_4932_909C_19E681DCF70D) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_B69F389A_0CEA_4696_B895_216D7D32DC7B) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_B4389BFC_BF2F_4CEA_8250_77B8D586B657) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_0FB89E34_7B76_406D_BB46_BD95E64A10EA) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_A2868A09_DF67_47AE_9831_E64FD7ACA311) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_1DB35C18_A3C3_494E_A108_E327E443A5D3) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_9A2B919D_E811_49E9_BB5F_F3A4E4E14409) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_B351403B_AC36_45A1_A01A_2763D3502BB5) },
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
