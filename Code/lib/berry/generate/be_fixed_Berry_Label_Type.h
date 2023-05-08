#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_0CE31454_4DDC_48E4_B60A_85EE1075E0CE) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_64B24DCE_C8DC_4838_A8A6_D8FE424D67B1) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_1470A9A9_411C_4AAA_A5DD_BCA17283CBC9) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_E2F3B416_AC90_47D6_9AC7_5D9E9B5F4D97) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_65A4A137_95EC_4C73_8E76_66A8BCA8C788) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_50C10E40_A823_4BFC_B6E3_1F84B75884CE) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_3F93F706_9A69_47E4_9E2A_5A931349240D) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_3723AF93_043B_49AD_AD30_84668040281C) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_8765576D_305F_4B9D_8CB0_E5F0513EA01A) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_ACF660FE_A653_4205_81F2_061B13FDF22C) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_668C696D_B735_47F8_A339_09279E8ED929) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_835CBED1_A88E_429D_AA8D_5BDE7DE183F7) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_C0019A59_6A0F_44BE_97E2_75F8670DC1A5) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_76B8005E_F68D_47D9_8EF4_3F3A736B1C62) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_312729AE_7810_4339_A963_5C858656F4C9) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_873623C4_61D1_4279_A444_F1F129D477B3) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_01366750_2A12_4DC1_8E3B_BE035A7FAEC9) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_B32040D6_5A23_441C_849F_3B74DAAA87A6) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_7C074D90_3AD2_44F6_BC57_6B91AC4DCACD) },
};

static be_define_const_map(
    Berry_Label_Type_map,
    20
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Label_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Label_Type
);
