#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_C6A54D1B_8D6F_4FDD_A595_262D002F53A3) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_95696D41_2A05_4297_9166_BB7F23D5E890) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_4E31E5EB_E1B1_423C_9CCE_EE1CF4D2BCB1) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_C01C5578_8F2C_4621_A81C_9CD051A97350) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_A60F8D8E_ADD1_4084_80CC_DE9269D35CAF) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_CB5815D0_8B1F_4444_94DB_3EE8AE4366CC) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_978192C9_A634_490C_B1D6_DB707042BF16) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_5BFE4BEE_4FFE_47A7_AC28_5F653CBC4EFA) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_B49BD4FB_0494_416A_A994_8D5409EB52F6) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_2CB11613_54BD_4D5D_BEDE_438944CD3D43) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_8DFD8237_0F61_430D_A7DC_5C9FA4D17289) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_20A4C48E_A815_47D7_B5B8_9027C01A892D) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_6521BDF0_6082_4085_BFE1_CBC6610F59BA) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_41B11606_5102_4867_A683_ABE4A8B4EC7B) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_27302A62_73CD_430D_AD47_1D1E239A260F) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_BD49E80C_BE6B_4245_A646_7E71BBBEA40A) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_F367BDF8_F601_4EF2_91B3_0DAFF6CABBAA) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_EE15EBAF_6A99_4530_AEAE_4C2167FE5EA2) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_807FD77C_F902_485F_BD3A_903CDE278B82) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_8BA0B391_989C_49C5_9948_024AD519851C) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_93782630_F717_41B9_801C_D0D1A2D09700) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_F44A0167_91A0_4036_9754_57BB96EE6FF7) },
};

static be_define_const_map(
    Berry_Arc_Type_map,
    23
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Arc_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Arc_Type
);
