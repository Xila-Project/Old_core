#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_1123834C_3AB3_4486_823E_9542972D61A9) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_F26D3B9D_CFEF_4E4B_93FA_DDC69FF864E7) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_D2423041_5916_4003_807A_B9D93AC51899) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_85FA3BAA_B4CC_414B_B9A7_B40D13A3BCC0) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_AD13E8AF_A017_420D_AF43_10C0AD8AE1EA) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_45DDB2F6_2CCF_49F6_987F_D47AB722066F) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_FA4A62E3_42FC_4493_9E4B_F419C917D1C7) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_7272154E_95E0_4265_B2F2_8E89809ACC8C) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_090829B2_487B_42DC_9938_92DD10F546A5) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_0F5BA5A1_3E18_479E_9EDB_E62AC55BD740) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_CFCD40A7_7758_4C07_B085_AA0F0E2BEB36) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_DFAEB7F6_B31D_4A55_908F_07A577E3C049) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_9BE38639_4C13_4F5F_BD19_BDB90E8AE42F) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_12EE9956_8A78_497C_A898_028D879B420A) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_F527DE2C_CD4A_4418_8F14_D79343658C43) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_F5BD6355_5DAC_49F3_BAD5_1574E4C10EC2) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_0A84F4AE_6B06_4A1B_ACD6_188EC3CB7175) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_2D4314AC_D6D8_4673_8C59_C3CFF23430F7) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_1920F594_1430_42C7_BD5B_3941894188E6) },
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
