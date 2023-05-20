#include "be_constobj.h"

static be_define_const_map_slots(Berry_Bar_Type_map) {
    { be_const_key(Set_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Start_Value_0C6BBD35_8C45_4636_9871_D7FF658DCA9D) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Bar_Class_Set_Range_85013A3B_09A7_4A04_8C91_F1C7EF619E5C) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Value_F80410E8_1A9B_45E7_9E46_265152365D2B) },
    { be_const_key(Create, -1), be_const_ctype_func(Berry_Bar_Class_Create_D1F6755A_4E72_46FB_B3D1_6F03B23D4838) },
    { be_const_key(Get_Start_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Start_Value_6361C73C_6622_45EF_90BD_E38426E42DED) },
    { be_const_key(Get_Mode, 4), be_const_ctype_func(Berry_Bar_Class_Get_Mode_AA6938BD_4EED_487B_B1E1_04D38203A269) },
    { be_const_key(init, -1), be_const_ctype_func(Berry_Bar_Class_Initialize_E614D13F_30A3_4DDC_94EA_B882824C62AE) },
    { be_const_key(Get_Minimum_Value, 10), be_const_ctype_func(Berry_Bar_Class_Get_Minimum_Value_C0C3E16B_9BAB_41AB_A303_40C1E66DF783) },
    { be_const_key(Set_Mode, 9), be_const_ctype_func(Berry_Bar_Class_Set_Mode_3EAE275C_5E84_4712_AAD3_F0B8B0D3C78D) },
    { be_const_key(Get_Maximum_Value, -1), be_const_ctype_func(Berry_Bar_Class_Get_Maximum_Value_51C71B02_2F93_4121_AC8C_D03ADCFDDDD4) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Bar_Class_Set_Value_62E4BA94_2C0C_4EAD_8C0D_7162067162EF) },
    { be_const_key(_p, 1), be_const_var(0) },
    { be_const_key(deinit, 7), be_const_ctype_func(Berry_Bar_Class_Deinitialize_96FC3410_73BE_4720_88BE_5B4F065B2624) },
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
