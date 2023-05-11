#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_8CDD6F0C_DB08_4C54_836D_BFF5AD703DE0) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_5378961B_63F9_4B35_A8C1_DC4AB5CD8870) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_0E2281AF_6B14_4ADE_9F25_12D8AB1DF60A) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_C7920448_F287_4235_A1CB_3CDE305227AB) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_CB1E1303_2C71_4E81_930C_FEB51DEE41F6) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_FE566AD7_D69F_4C40_B001_DFA40A2B5038) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_0DF788F7_7087_4139_8046_1AAE2A67217A) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_D104E7DD_9919_4F2F_A168_7EC671326ACE) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_D44BCC71_35A5_433E_8CE2_7C06E74F6C05) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_D9433A89_C196_4DCA_8D73_991CCA8E17E5) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_8AB9BEAF_24C5_4D40_BF08_3C73FDC03444) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_4C1970C1_5AE8_4E35_938A_4F1E5CCC213C) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_CC3B39E9_94AB_428D_9E01_C8441F95A681) },
};

static be_define_const_map(
    Berry_Slider_Type_map,
    14
);

BE_EXPORT_VARIABLE be_define_const_class(
    Berry_Slider_Type,
    1,
    (bclass *)&Berry_Object_Type,
    Slider_Type
);
