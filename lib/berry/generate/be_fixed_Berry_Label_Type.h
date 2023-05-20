#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_EFC078D0_3B26_4835_9331_ECAF0641140E) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_826D3D00_A588_4837_84B4_D304204EF3DC) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_3A20AA32_89DF_4968_A897_D76E882826DC) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_50326AF5_A67E_42BF_8794_EB3D5F9F87EB) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_5322D7FE_B842_4A1C_B08E_AAB210E1D10E) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_33E4BA9C_5A3F_42EA_8721_C55F483972BF) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_02F8E6B5_E8B5_45EA_BE8A_0973CEA10BE4) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_0C9B55BA_9FCD_436C_BF88_014232B54364) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_450C6E7F_1B09_4CD3_8EB2_A505070F181A) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_EE253E3A_CAFD_4C59_BE61_EB4E0581A480) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_5F68551C_EDDB_4B1E_B8BD_548707829575) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_ABB5550A_B139_4484_B4B4_0399030051FA) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_BE3F1A35_A644_4041_9D58_815A5C3C1740) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_7518418B_2CD2_4DDA_B78B_99C04527F7A4) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_A17EA730_373D_45A1_88F8_D0982896B99C) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_8686013D_DD89_4682_8520_634DC0999578) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_F53B105D_73B8_47F1_A67E_6907EB4B4F0B) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_63B98CED_C8AA_4BA1_BC74_D66FE71C7226) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_95DAF71E_ADEA_4DF3_97A9_D177A0259494) },
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
