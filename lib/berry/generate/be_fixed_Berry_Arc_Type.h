#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_7C3F101C_7A00_48B9_80D4_3E87E22ADE83) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_4961BE10_710A_4857_9003_3729D01E96B1) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_7C0CD68A_8F3D_4B57_991C_712DD33D59E1) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_4B766EDB_B655_48FD_884C_8690DF1AEDEC) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_8E4140A7_4020_41E7_ACD3_1B36E0AC17B8) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_4D713ED9_FA6D_45AA_8447_CFB59CCE880D) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_6233A964_8594_4AFB_9387_973667BC989B) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_549D0E31_B9E0_4781_99FA_1B8F809200FC) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_C5F19164_316A_48E6_860B_D0B2893380FB) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_B1F7FAB3_30D7_49D7_B088_94A9CBF1FB87) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_76A21481_A0AD_4463_B1ED_8047B6CEA1B1) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_8A85BEC7_8D90_446B_953D_CE08B78480F8) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_E3395694_7967_4E81_8262_740DF5206382) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_2581628C_47D4_4CDB_A44B_67C5A7934251) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_43DF7854_FC85_49B8_81BC_8D9F1AF2D21C) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_B36DE00B_6F90_4E68_B531_A3C69D177F67) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_82B6875B_5914_4F3A_B3F9_30F57A2C2A03) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_3606BD8E_DDAA_4155_BED2_75DB79F1B4E5) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_5E9DEE8D_D985_4D75_B5A4_ECEC985D1B9E) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_DCEF9955_A4CD_4DFF_BABC_CBF882140CB9) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_8880B857_2F19_49E7_8EEE_9B185DD5FD3C) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_135E787C_09D7_4B99_A834_6E172570482B) },
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
