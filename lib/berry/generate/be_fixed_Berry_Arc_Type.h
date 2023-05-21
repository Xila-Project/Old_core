#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_161C056F_5798_466C_8207_DBA99D3DF11E) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_C4400A7A_0CC5_4E64_93D4_7144F478ECD9) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_575D9F55_6536_45C7_8AFE_6C2BD959BF69) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_D63987A7_72D9_4053_A49A_37E2352A4061) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_69BCD9C2_0C46_40A5_BADD_4E1A6EF66139) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_8380CC40_4693_4C81_B21D_BA078ADDC44B) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_DFD568D6_8CA4_42CE_A598_3342C9CC5E68) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_8C51AC4D_5965_470E_96FB_9424B71AB69F) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_B2C387BE_EC7F_41C3_8591_CE9E3A91C99C) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_2B19849B_8778_4863_A866_E5F1F1C1E0ED) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_BC0DE449_0743_4CDE_8038_A4532D704028) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_83767524_B56F_4F5A_AC14_1183C7A304C7) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_C6BDE441_EAD2_4E3E_9F38_DB7C703F46EC) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_0E83F512_25A4_473F_A43A_CDA4332BF21A) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_C6F3AC33_D683_4594_9FE0_9D0703094CC1) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_33D77022_6262_4733_8919_FA52FF607999) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_39154CDD_9299_458D_A0EC_CEE0A983D809) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_9BB8B646_A02A_49FD_A017_DAED1B66C90D) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_5F45C489_59D9_4EDA_BBB5_7E836C65A13B) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_654D0BE8_95A2_45C0_B4D4_6882B42F0541) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_9E7802BD_B76B_4E98_82F9_C941B93662D7) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_879DB603_14AA_417C_BCBA_4F8DD4B7A58F) },
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
