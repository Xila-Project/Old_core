#include "be_constobj.h"

static be_define_const_map_slots(Berry_Drop_Down_List_Type_map) {
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Text_A3E1F3BA_0944_4C34_B48B_004631035B76) },
    { be_const_key(Set_Selected, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_9C1B51A2_2888_4D43_BD19_E2C15ED707B0) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Is_Open, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Is_Open_EC7B12AF_AE61_410F_9A8D_3C09A78249CD) },
    { be_const_key(Set_Text, 0), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Text_983476D9_4FFD_4F85_B781_EDEB1716FC65) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Initialize_13AD706E_0460_4D54_A3B4_D99395D4D830) },
    { be_const_key(Close, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Close_694C5225_C923_4226_9DA5_AF6672DCC474) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Create_DABB62D5_63D3_476B_B45D_0A1F8910657B) },
    { be_const_key(Add_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Add_Option_FB73943A_C88A_48D6_AD70_A1308DD033AD) },
    { be_const_key(Get_Options, 7), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Options_C97DFB61_EDA4_428A_8AB1_83666856AE4B) },
    { be_const_key(Get_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Direction_7B0D02DE_5100_42D6_8259_F1FBEAB5C6AD) },
    { be_const_key(Open, 12), be_const_ctype_func(Berry_Drop_Down_List_Class_Open_544F7EBC_924E_4411_BE97_62EE34557C5B) },
    { be_const_key(Get_Selected_String, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_String_5644FEF9_A0C1_47AE_86B9_7421393BACB3) },
    { be_const_key(Set_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Selected_Highlight_E14F41B4_971A_4FE8_A82D_0D756EDFD4C5) },
    { be_const_key(Get_Selected_Highlight, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Highlight_E85F7B83_E0EC_42C0_A115_244EFF004518) },
    { be_const_key(Set_Direction, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Direction_2470AE7B_2E1F_4DFF_87BC_2D1477E003F8) },
    { be_const_key(Get_Selected_Option, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Selected_Option_13BACF83_E26A_4B9D_8390_872959FAB58C) },
    { be_const_key(deinit, 10), be_const_ctype_func(Berry_Drop_Down_List_Class_Deinitialize_54B86214_6FE0_48D9_A63B_6A8D79C0EB7C) },
    { be_const_key(Get_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Symbol_F70B2549_B58E_47FC_83FC_086EE2D2EE3E) },
    { be_const_key(Set_Symbol, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Symbol_1B1E51B8_8942_4ACA_8799_2DB53A96C5C9) },
    { be_const_key(Set_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_DB3E3C55_2499_4359_AB24_44C89C62CBB3) },
    { be_const_key(Set_Options_Static, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Set_Options_Static_B954EDC0_462C_48D1_BF53_3DE9CD0382C4) },
    { be_const_key(Clear_Options, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Clear_Options_5397FAE4_5333_41F3_AF19_1EF0FB806D1E) },
    { be_const_key(Get_Option_Count, 3), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_Option_Count_31FB1A10_0C9F_486B_A4A3_393A9F2AB350) },
    { be_const_key(Get_List, -1), be_const_ctype_func(Berry_Drop_Down_List_Class_Get_List_381D3889_980C_4334_AC14_A8D79D5EE5C8) },
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
