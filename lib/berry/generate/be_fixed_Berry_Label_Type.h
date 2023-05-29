#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_3F699BF8_0747_4DE9_8662_469CAEEAE318) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_46AE7817_7543_4BAF_AFE1_3A5C7F323904) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_C7E5B528_537C_42EF_8A41_C906EE4530DC) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_829C61B2_6428_4B43_9317_18653E72BAD7) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_0C7127B7_502B_45CA_8C6A_85DA63293D0C) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_EC90A1CB_48A9_4A88_B063_66F109135C25) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_8A0AD632_7777_4EFF_AD6E_1E4537B488DC) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_47B5356C_FE41_4A07_A4C8_71E628B2717E) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_8427A738_F6E2_4C84_A8FC_B33B4823CC1E) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_83EEF470_4639_4A08_AF1C_CED8A5170E08) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_75E3E975_A15F_4FDD_B1AA_7509291A4B95) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_443E762D_C3D1_40B5_AB1B_9F67D7A9086B) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_5507BEB2_51B4_4995_8FEA_765CD557EBD4) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_FE060C09_9D74_4A17_A245_8B1AE3C06FB9) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_8F41E4A2_CF95_4678_82B0_0C88A4614681) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_3C53757B_6AB7_43A3_81AE_B55B7E8F6035) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_5FBADE2D_6390_4265_AE17_376C76EF8BFF) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_965009AD_16C4_494F_B156_D9B6028FC3A2) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_1EDB3E3E_98D9_49BD_B155_03225404E14F) },
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
