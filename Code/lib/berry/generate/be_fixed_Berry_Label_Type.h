#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_309E9D37_9BCF_4196_96CD_5A08064DF303) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_25B2E9BD_E264_4E2E_A3FC_3AB085C13547) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_C51A1020_0741_43D0_8049_BFC349297222) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_267FF9BD_8908_4F3B_82F9_F933C3AC3541) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_04580DE1_58A2_4CE4_B82B_FEA5793C7523) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_BB2FEF66_7ACA_4A64_B521_7F774A8808AE) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_D525ED76_F9BF_4F01_9B0D_C6BD3548E4BD) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_5B7BF82D_E680_468B_A378_F9B5A047B547) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_598C4DF7_B227_4D12_B187_CAAC39E7261B) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_B59BBDD9_113D_474E_812E_747127BEC64E) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_6DD862C6_1CA0_4FC5_8851_805E4127F2A6) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_650A9B7F_3031_4A21_BF62_1D74CF0AC806) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_8D44E492_DFE3_461C_9D49_090A5F1A33D2) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_5A409AB9_AE33_49A1_AB81_D556724F0A37) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_29AFB618_F360_4A11_97CA_28C895735AB4) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_84581759_1E1A_49E5_98FB_F148150829EB) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_A7D68295_3957_493F_B74B_B9F86F1DBA8E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_8F89558B_F01E_4246_9EF7_883B9B36D67B) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_F612AEC8_85E7_412B_AEAD_F7051D79D1D8) },
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
