#include "be_constobj.h"

static be_define_const_map_slots(Berry_Arc_Type_map) {
    { be_const_key(Get_Background_Angle_End, 7), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_End_E7DE5650_C066_4B6F_97E8_4609CB1665D4) },
    { be_const_key(Get_Angle_Start, 3), be_const_ctype_func(Berry_Arc_Class_Get_Angle_Start_B21EBADE_B604_4E25_A879_61B7300C27C8) },
    { be_const_key(Get_Background_Angle_Start, -1), be_const_ctype_func(Berry_Arc_Class_Get_Background_Angle_Start_5525B6BD_340F_4355_81EF_681FECE93578) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Minimum_Value_1A398AB4_517D_4116_8625_D0380A57920F) },
    { be_const_key(Set_Rotation, 21), be_const_ctype_func(Berry_Arc_Class_Set_Rotation_A3BE47CE_349A_4ABE_BB09_2083D749FEBC) },
    { be_const_key(Get_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Get_Mode_44F48A5C_BDCC_4389_B758_8D751E27153B) },
    { be_const_key(Set_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Start_Angle_1F5319C5_E2DA_4302_AB06_FD81E94D0512) },
    { be_const_key(Set_Range, 22), be_const_ctype_func(Berry_Arc_Class_Set_Range_4A571817_0E51_4855_BE59_9B9B101993CA) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Background_End_Angle, 5), be_const_ctype_func(Berry_Arc_Class_Set_Background_End_Angle_D2455566_B064_4355_915F_EC2894B3DFEF) },
    { be_const_key(Set_End_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_End_Angle_33EE90EC_3A04_4B74_A5F4_DD607E6710A9) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Arc_Class_Get_Maximum_Value_DFA16A78_99E2_4C52_8322_EC927BF48FC0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Arc_Class_Set_Mode_1C81DE17_6A95_4D90_94F8_887035F98C20) },
    { be_const_key(Get_Value, 4), be_const_ctype_func(Berry_Arc_Class_Get_Value_EE9A2B60_BE59_4434_A478_5DC98F29FD33) },
    { be_const_key(init, 6), be_const_ctype_func(Berry_Arc_Class_Initialize_1C10965A_C44F_4E6D_9355_7DDFA3438524) },
    { be_const_key(Set_Background_Angles, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Angles_443F96EF_85AA_4DC3_B25A_16EA98A058D2) },
    { be_const_key(Set_Change_Rate, -1), be_const_ctype_func(Berry_Arc_Class_Set_Change_Rate_84FA81B5_DEB7_4D14_A242_89F214B82B18) },
    { be_const_key(Get_Angle_End, 11), be_const_ctype_func(Berry_Arc_Class_Get_Angle_End_A5FA7035_D713_448A_A390_C02698C0D255) },
    { be_const_key(Set_Angles, 12), be_const_ctype_func(Berry_Arc_Class_Set_Angles_44E688DB_18F7_459A_8CC0_381B15BC1B74) },
    { be_const_key(deinit, 16), be_const_ctype_func(Berry_Arc_Class_Deinitialize_78AF0676_467F_4B77_BFAB_EF6B66B589A8) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Arc_Class_Create_7BEEFE5A_E351_4438_A778_32CC8F6F1D03) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Arc_Class_Set_Value_0FF4B7EB_2DD9_4B5D_B91C_29752BF6E7DE) },
    { be_const_key(Set_Background_Start_Angle, -1), be_const_ctype_func(Berry_Arc_Class_Set_Background_Start_Angle_430A7BEA_4EE4_4AB6_B0BB_5BEB38182CAE) },
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
