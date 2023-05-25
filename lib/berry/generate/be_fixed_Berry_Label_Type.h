#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_205C9F35_6735_448D_815A_ADD4F143FBF5) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_94E9D264_8C5A_4A6C_8BD9_3AA85931B4D0) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_2A669B1D_BFB9_49FE_8EDD_81AADC8CB9CB) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_1AAD1158_C32E_4A63_BAC3_2F50E499910A) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_BC91D75E_A3FB_461F_8ACE_F3DAB8046EEA) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_144FA011_F802_4269_B086_DF5E09B96616) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_534B7E2B_03E7_4E26_BED8_B1A78F2F7102) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_88576127_CE88_423A_86F8_8A1A2C31868E) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_38A849F9_B973_4F32_B691_A0111B117447) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_F9B7FC64_E6B9_408D_BE13_584FEFAF57C8) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_8750E739_A6DB_4E9C_BAC5_C67469B634D1) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_E18FA4AE_A044_47A9_B0CD_9407E5034DF9) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_43DA5AFE_29B2_44D8_9E0D_80CB5D826B76) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_8EF894C6_AE69_4C35_9A76_05277F10A3FC) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_9FA0BF6C_C0B7_455D_BFB0_590C7324E00A) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_DC436DBB_32C5_4EF3_9F4D_C9F5708E2B0F) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_8DF32E0E_BFE1_49E7_A43F_26A468BBA977) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_E4F8D27D_5309_4376_B6B2_007FBCAF9F8E) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_94F77607_8FC7_44DA_8324_E07E2648FE50) },
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
