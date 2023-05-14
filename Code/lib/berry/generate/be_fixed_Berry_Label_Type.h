#include "be_constobj.h"

static be_define_const_map_slots(Berry_Label_Type_map) {
    { be_const_key(Set_Recolor, -1), be_const_ctype_func(Berry_Label_Class_Set_Recolor_7ACD600F_03F1_4296_8D6F_72A3783D840A) },
    { be_const_key(Set_Selection_Start, -1), be_const_ctype_func(Berry_Label_Class_Set_Selection_Start_BC2D12A5_0B97_45DB_AD7B_6B578CC52201) },
    { be_const_key(Set_Text_Static, 14), be_const_ctype_func(Berry_Label_Class_Set_Text_Static_03D4E3C2_2DF9_4C31_A319_306B304881CA) },
    { be_const_key(Is_Char_Under_Position, 13), be_const_ctype_func(Berry_Label_Class_Is_Char_Under_Position_8B75E847_BF80_4F24_A76B_BCB49B31A9D4) },
    { be_const_key(Get_Text, -1), be_const_ctype_func(Berry_Label_Class_Get_Text_88FC79E1_E333_45F5_AB59_E1398C50BD7F) },
    { be_const_key(Get_Long_Mode, -1), be_const_ctype_func(Berry_Label_Class_Get_Long_Mode_D18CAEC3_006B_4AEC_B1D8_9930E6A4379A) },
    { be_const_key(Insert_Text, -1), be_const_ctype_func(Berry_Label_Class_Insert_Text_9AA2A9D1_BC48_4A75_8AA1_C300F729CA75) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Label_Class_Create_CFA5D990_25EB_4578_A6AC_57026387790F) },
    { be_const_key(Get_Letter_On, 11), be_const_ctype_func(Berry_Label_Class_Get_Letter_On_FF7A69D2_EED9_4E01_A38F_67309E110B56) },
    { be_const_key(Get_Selection_Start, 7), be_const_ctype_func(Berry_Label_Class_Get_Selection_Start_97F2315E_BD2C_4515_9AD6_A90A32669ED3) },
    { be_const_key(Get_Letter_Position, -1), be_const_ctype_func(Berry_Label_Class_Get_Letter_Position_64705549_56F0_42D8_BC9F_A29B3D89577C) },
    { be_const_key(Set_Long_Mode, 17), be_const_ctype_func(Berry_Label_Class_Set_Long_Mode_628076B8_D257_4D28_B076_8E105A6581C9) },
    { be_const_key(Get_Recolor, 18), be_const_ctype_func(Berry_Label_Class_Get_Recolor_6F99AEA5_F19D_414B_878E_055D43932D50) },
    { be_const_key(Cut_Text, -1), be_const_ctype_func(Berry_Label_Class_Cut_Text_A5DB58CD_799F_47B9_9D05_25BC0C9DFB28) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Label_Class_Initialize_95679028_E9B3_444C_94E2_80C6B455C887) },
    { be_const_key(Set_Selection_End, 5), be_const_ctype_func(Berry_Label_Class_Set_Selection_End_C831C16A_6098_4C14_9418_870D7F9C71D3) },
    { be_const_key(Get_Selection_End, -1), be_const_ctype_func(Berry_Label_Class_Get_Selection_End_2D1AB092_0588_46E8_90E3_3423487F6D3B) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Label_Class_Deinitialize_191E94C2_2352_43D2_9A06_F085BBF96965) },
    { be_const_key(Set_Text, 4), be_const_ctype_func(Berry_Label_Class_Set_Text_9AE1E87C_11D2_4A40_BBA1_8941CD160199) },
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
