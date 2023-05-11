#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_A771483C_5BC8_4E55_9C3D_26C853D9603F) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_B9A407CF_77A1_4E91_9673_2E7118657ABD) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_1CA9BD34_C3B8_462B_B4B2_3C9FD80C4773) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_9F474006_4655_4DAE_BE63_319FF67EAC4A) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_E106EA56_3215_40B2_A1B1_51809B742170) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_584DE37D_48B9_4209_BFDC_A7B75FC93450) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_CB9EC26B_C5CB_4097_A539_A9898904F9C8) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_1DDBF27F_48A4_4F66_B44C_BDF86143F4C2) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_3D915069_F890_4376_A548_2789AFA7D12E) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_939D63B2_2D09_45C1_BD04_3BCE0AF1913E) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_EF53C91F_CC9D_47A5_ABEC_313E4C187D29) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_06764431_1FA1_4E58_9291_199BDF96F9C6) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_FAA84CD7_88D6_4393_AF95_DD09ECD670C2) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_A3B0C0DD_05A1_4266_AFBB_91CB5633FE00) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_A76A9746_CCCF_41A0_9396_8A89F6E1C88C) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_23487C9D_6C66_40B5_86E2_C302A7EB2839) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_34492F5A_C77D_4BF9_A841_E07C7C2BDD20) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_781AC258_2882_44DB_9B56_EE728329F887) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_4917EB38_7D6A_4372_8F29_78FF9CAFD4CB) },
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
