#include "be_constobj.h"

static be_define_const_map_slots(Berry_Slider_Type_map) {
    { be_const_key(Set_Left_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Left_Value_F0333DCC_0187_429D_B3E8_4CA5ED238A3B) },
    { be_const_key(Get_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Value_E05F322E_05F8_4F99_8BC5_B57B12D5D8CF) },
    { be_const_key(Get_Mode, 13), be_const_ctype_func(Berry_Slider_Class_Get_Mode_78E5EACB_BC7B_4283_B57F_F9E3D8F81211) },
    { be_const_key(Create, 2), be_const_ctype_func(Berry_Slider_Class_Create_BF8EB668_7758_4C09_B935_D159ACD05344) },
    { be_const_key(Get_Minimum_Value, -1), be_const_ctype_func(Berry_Slider_Class_Get_Minimum_Value_E9879AE9_359C_4DBC_A489_FA78CBCBA10D) },
    { be_const_key(init, 3), be_const_ctype_func(Berry_Slider_Class_Initialize_B8548B43_E4B0_4A3E_8898_EC87F05D59FE) },
    { be_const_key(Get_Maximum_Value, 10), be_const_ctype_func(Berry_Slider_Class_Get_Maximum_Value_C59CD55E_0B15_4655_B943_8CE04F4FC644) },
    { be_const_key(Set_Range, -1), be_const_ctype_func(Berry_Slider_Class_Set_Range_CBAE3F3F_9068_436C_BE03_F268E42C76F5) },
    { be_const_key(Is_Dragged, -1), be_const_ctype_func(Berry_Slider_Class_Is_Dragged_FE611057_F32A_4278_B125_966BE81F16CE) },
    { be_const_key(Get_Left_Value, 0), be_const_ctype_func(Berry_Slider_Class_Get_Left_Value_B88AB508_99D1_421D_A312_59264E0FBF42) },
    { be_const_key(_p, -1), be_const_var(0) },
    { be_const_key(Set_Mode, -1), be_const_ctype_func(Berry_Slider_Class_Set_Mode_DBCBF68C_076D_40A8_9AA6_937F8F78781E) },
    { be_const_key(deinit, -1), be_const_ctype_func(Berry_Slider_Class_Deinitialize_D08C73B2_2C94_48EF_B267_3634C56E67D0) },
    { be_const_key(Set_Value, -1), be_const_ctype_func(Berry_Slider_Class_Set_Value_6F40649F_D160_461C_A545_24164325FE15) },
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
