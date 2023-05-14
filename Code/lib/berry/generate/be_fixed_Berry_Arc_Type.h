#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_43B07954_CDA4_4A1B_A515_FEF0E9227879) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_05072999_D665_4D78_B4C6_34CF7CA98179) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_203DAF1B_852C_4528_B8DB_80C962DA7D7C) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_C1B4BCDA_49A1_4ED2_8558_5FA006342780) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_BA124940_E3BC_4B61_8CB0_654CA659BAA1) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_6D073CF2_3DFF_4CC4_BF7E_F87E478A2B31) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_F19C714D_A49D_400F_B06D_0D66FA36ADDC) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_03A397B9_C295_4A4A_8FA0_C2CAF7B3C248) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_724B0749_4B60_48F3_BA55_A5F348230C22) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_C2E42588_5C34_474A_B455_74582C9C5A66) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_102FA17D_DE15_4F69_8662_40AEA3A84317) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_7CB9E061_A27C_4A16_A958_6C47B2EBAD81) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_19855CB5_59C0_4FDE_A65C_8C9FE07AB4A6) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_2B907191_266C_4148_A1BA_C07E615668A3) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_72BB4A1E_A336_4D27_9A7B_BD6FE2D35810) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_1CBF0774_7D42_4168_A196_983D3941C1DE) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_F3725B94_5525_49D1_ABAB_8EA355621113) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_6E4211FE_1919_4E92_A96C_B837C39226C6) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_8D97C2BF_1DC1_4755_9A66_CB717C6D4492) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_091067AD_2670_40A4_9037_A91E9A70CC2F) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_C7B48867_06D5_422B_9AA8_6C883F07BF5B) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_FDE6FCA5_6CD8_48B6_BE1F_F24B90C2D638) },
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
