#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_C9216881_CB30_4848_9B8A_8CFBA2183734) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_A15FECA1_C9DE_4BE7_9F46_D5E5EAE1B1B2) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_064C00B0_7D07_4DD2_8202_5AC1B6BC5AD7) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_1EA9FD05_6C52_40BE_8B55_FCEDD9FBB429) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_A35269B1_5F8E_403B_AD6A_910BCEAE2925) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_6721689F_67FD_4D05_A781_7A96BD95A32E) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_974D492E_9FA9_4492_AFD8_A76D7521B8F5) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_E1A39209_732D_410D_86F0_7BBD7160F61B) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_F4458B46_D1B5_498D_AF49_47FF95C5AE81) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_28194C7A_BC85_4E0F_8EA4_134A001AB1E6) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_8FDCB520_FEE0_4AEB_AB0D_050A4C502037) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_3BE7D2F9_01F4_40B3_AB18_4D0A86D220DB) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_52530D0A_C0E4_4452_B843_360FFF97CD1F) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_4278A181_8F72_4DB1_B62A_C83797E443D2) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_6156DF61_24E1_4F14_B9F5_CCE9AC348EC9) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_76F5EFE6_E1A1_481E_BD06_96AC1B4D611C) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_8F11C817_A199_4E50_A45A_960BB54BA775) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_1E66FCDF_0447_441E_BA51_595C7831DD23) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_4F57C22E_034A_4D26_B7FB_00A9A441A5DC) },
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
