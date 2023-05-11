#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_544C9B42_133E_473E_B091_24DBC4B01D5B) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_EF083E7E_3F2B_427C_A810_F0A3145453C2) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_130E00FF_90FB_4574_A6AD_4F69D48EB8A2) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_FB201D1F_954C_4ED5_81B0_A813385F1851) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_D80E5D9F_B9D5_4B40_ABF1_08616B069BAA) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_4EFD4238_6D48_4306_BFA2_4F79FB1732C5) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_65DFBBE3_21BA_43B2_B6A4_5B274DC27631) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_C483927A_A7A5_4B36_8BA5_C34FEC275018) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_2D041AFC_CBFD_483C_9D9F_C3D1A3F1615B) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_9F6DADCC_2880_4F32_B69A_605E88EDB1A2) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_B3C5FE32_5526_4C3B_B474_4AEEBFD25268) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_8C3D91F6_A06D_4BBC_9160_13963E00F216) },
};

static be_define_const_map(
    Berry_Bar_Type_map,
    13
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Bar_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Bar_Type
);
